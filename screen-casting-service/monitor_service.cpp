#include "monitor_service.h"

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#include <png.h>
#include <b64/encode.h>
#include <sstream>

static std::vector<unsigned char> XImageToPNG(XImage *image);

static std::string base64_encode(unsigned char *data, unsigned long size);

std::vector<Monitor> MonitorService::getMonitors() {
    std::vector<Monitor> devices;
    Display *display = XOpenDisplay(nullptr);

    if (display == nullptr) {
        return devices;
    }
    int monitor_count;
    XRRMonitorInfo *xMonitors = XRRGetMonitors(display, DefaultRootWindow(display), false, &monitor_count);

    if (monitor_count == 0) {
        return devices;
    }

    for (int i = 0; i < monitor_count; i++) {
        std::string url = getenv("DISPLAY");
        std::string deviceID = "x11grab";
        std::string name = "Display" + std::to_string(i + 1);
        int x = xMonitors[i].x;
        int y = xMonitors[i].y;
        int width = xMonitors[i].width;
        int height = xMonitors[i].height;
        int primary = xMonitors[i].primary;
        std::string port = XGetAtomName(display, xMonitors[i].name);

        Monitor m(url, deviceID, name, x, y, width, height, primary, port);
        devices.push_back(m);
    }

    XRRFreeMonitors(xMonitors);
    return devices;
}

/// Return Base64 encoded screenshot of the monitor
std::string MonitorService::getMonitorScreenshot(int x, int y, int width, int height) {
    Display *display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        return "";
    }

    Window root = DefaultRootWindow(display);
    XImage *image = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);
    if (image == nullptr) {
        XCloseDisplay(display);
        return "";
    }

    std::vector<unsigned char> png_buffer = XImageToPNG(image);
    std::string base64 = base64_encode(png_buffer.data(), png_buffer.size());

    XDestroyImage(image);
    XCloseDisplay(display);
    return base64;
}

std::vector<unsigned char> XImageToPNG(XImage *image) {
    std::vector<unsigned char> pngBuffer;

    // Initialize write structure
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (png_ptr == nullptr) {
        std::cerr << "Could not allocate write struct\n";
        return pngBuffer;
    }

    // Initialize info structure
    png_infop png_info_ptr = png_create_info_struct(png_ptr);
    if (png_info_ptr == nullptr) {
        std::cerr << "Could not allocate info struct\n";
        png_destroy_write_struct(&png_ptr, (png_infopp) nullptr); // free png_ptr
        return pngBuffer;
    }

    // Setup Exception handling
    if (setjmp (png_jmpbuf(png_ptr))) {
        std::cerr << "Error during png creation\n";
        png_free_data(png_ptr, png_info_ptr, PNG_FREE_ALL, -1); // free png_info_ptr
        png_destroy_write_struct(&png_ptr, (png_infopp) nullptr); // free png_ptr
        return pngBuffer;
    }

    // Initialize PNG write
    png_set_IHDR(png_ptr, png_info_ptr, image->width, image->height, 8, PNG_COLOR_TYPE_RGB,
                 PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    /*// Allocate memory for PNG rows
    std::vector<png_bytep> rowPointers(image->height);
    for (int y = 0; y < image->height; ++y)
        rowPointers[y] = (png_bytep)(image->data + y * image->bytes_per_line);*/

    // Set up PNG write callback to write to memory buffer
    png_set_write_fn(png_ptr, &pngBuffer, [](png_structp pngPtr, png_bytep data, png_size_t length) {
        std::vector<unsigned char> &buffer = *(std::vector<unsigned char> *) png_get_io_ptr(pngPtr);
        buffer.insert(buffer.end(), data, data + length);
    }, nullptr);

    // Write PNG image data
    png_write_info(png_ptr, png_info_ptr);
    //png_write_image(png_ptr, rowPointers.data());
    // Allocate memory for one row (3 bytes per pixel - RGB)
    png_bytep png_row = (png_bytep) malloc(3 * image->width * sizeof(png_byte));

    unsigned long red_mask = image->red_mask;
    unsigned long green_mask = image->green_mask;
    unsigned long blue_mask = image->blue_mask;

    // Write image data
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            unsigned long pixel = XGetPixel(image, x, y);
            png_byte *ptr = &(png_row[x * 3]);
            ptr[0] = (pixel & red_mask) >> 16;
            ptr[1] = (pixel & green_mask) >> 8;
            ptr[2] = pixel & blue_mask;
        }
        png_write_row(png_ptr, png_row);
    }
    png_write_end(png_ptr, png_info_ptr);

    // Clean up
    png_destroy_write_struct(&png_ptr, &png_info_ptr);

    return pngBuffer;
}

std::string base64_encode(unsigned char *data, unsigned long size) {
    std::stringstream input_stream, output_stream;
    base64::encoder b64_encoder;

    input_stream.write(reinterpret_cast<const char *>(data), static_cast<long>(size));
    b64_encoder.encode(input_stream, output_stream);
    return output_stream.str();
}
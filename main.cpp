#include <QApplication>
#include <QWebEngineView>
#include <QtWebChannel/QtWebChannel>
#include "app_proxy.h"


int main(int argc, char **argv) {

    QApplication app(argc, argv);
    QWebEngineView view;

    view.setWindowTitle("Wi-Fi Wonders");
    view.setFixedSize(900, 600);

    AppProxy app_proxy;
    QWebChannel channel;
    channel.registerObject(QStringLiteral("app_proxy"), &app_proxy);
    view.page()->setWebChannel(&channel);

    view.load(QUrl("qrc:/html-ui/index.html"));
    view.show();

    return QApplication::exec();
}
# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wifiwanders/github/wifiwonders-main/app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wifiwanders/github/wifiwonders-main/app

# Include any dependencies generated for this target.
include wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/compiler_depend.make

# Include the progress variables for this target.
include wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/progress.make

# Include the compile flags for this target's objects.
include wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/flags.make

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/flags.make
wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o: wpa-supplicant-manager/WpaSupplicantManager_autogen/mocs_compilation.cpp
wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wifiwanders/github/wifiwonders-main/app/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o -MF CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o -c /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/WpaSupplicantManager_autogen/mocs_compilation.cpp

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.i"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/WpaSupplicantManager_autogen/mocs_compilation.cpp > CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.i

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.s"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/WpaSupplicantManager_autogen/mocs_compilation.cpp -o CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.s

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/flags.make
wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o: wpa-supplicant-manager/wpa_supplicant_manager.cpp
wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wifiwanders/github/wifiwonders-main/app/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o -MF CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o.d -o CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o -c /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/wpa_supplicant_manager.cpp

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.i"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/wpa_supplicant_manager.cpp > CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.i

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.s"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/wpa_supplicant_manager.cpp -o CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.s

# Object files for target WpaSupplicantManager
WpaSupplicantManager_OBJECTS = \
"CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o"

# External object files for target WpaSupplicantManager
WpaSupplicantManager_EXTERNAL_OBJECTS =

wpa-supplicant-manager/libWpaSupplicantManager.a: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/WpaSupplicantManager_autogen/mocs_compilation.cpp.o
wpa-supplicant-manager/libWpaSupplicantManager.a: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/wpa_supplicant_manager.cpp.o
wpa-supplicant-manager/libWpaSupplicantManager.a: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/build.make
wpa-supplicant-manager/libWpaSupplicantManager.a: wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wifiwanders/github/wifiwonders-main/app/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libWpaSupplicantManager.a"
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && $(CMAKE_COMMAND) -P CMakeFiles/WpaSupplicantManager.dir/cmake_clean_target.cmake
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WpaSupplicantManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/build: wpa-supplicant-manager/libWpaSupplicantManager.a
.PHONY : wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/build

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/clean:
	cd /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager && $(CMAKE_COMMAND) -P CMakeFiles/WpaSupplicantManager.dir/cmake_clean.cmake
.PHONY : wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/clean

wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/depend:
	cd /home/wifiwanders/github/wifiwonders-main/app && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wifiwanders/github/wifiwonders-main/app /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager /home/wifiwanders/github/wifiwonders-main/app /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager /home/wifiwanders/github/wifiwonders-main/app/wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wpa-supplicant-manager/CMakeFiles/WpaSupplicantManager.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/addy/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/addy/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/addy/src/misc_scripts/prep_and_learning/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/syslogtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/syslogtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/syslogtest.dir/flags.make

CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.o: CMakeFiles/syslogtest.dir/flags.make
CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.o: ../basic_cpp/syslogtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.o -c /home/addy/src/misc_scripts/prep_and_learning/cpp/basic_cpp/syslogtest.cpp

CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/addy/src/misc_scripts/prep_and_learning/cpp/basic_cpp/syslogtest.cpp > CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.i

CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/addy/src/misc_scripts/prep_and_learning/cpp/basic_cpp/syslogtest.cpp -o CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.s

# Object files for target syslogtest
syslogtest_OBJECTS = \
"CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.o"

# External object files for target syslogtest
syslogtest_EXTERNAL_OBJECTS =

syslogtest: CMakeFiles/syslogtest.dir/basic_cpp/syslogtest.cpp.o
syslogtest: CMakeFiles/syslogtest.dir/build.make
syslogtest: CMakeFiles/syslogtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable syslogtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/syslogtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/syslogtest.dir/build: syslogtest

.PHONY : CMakeFiles/syslogtest.dir/build

CMakeFiles/syslogtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/syslogtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/syslogtest.dir/clean

CMakeFiles/syslogtest.dir/depend:
	cd /home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/addy/src/misc_scripts/prep_and_learning/cpp /home/addy/src/misc_scripts/prep_and_learning/cpp /home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug /home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug /home/addy/src/misc_scripts/prep_and_learning/cpp/cmake-build-debug/CMakeFiles/syslogtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/syslogtest.dir/depend

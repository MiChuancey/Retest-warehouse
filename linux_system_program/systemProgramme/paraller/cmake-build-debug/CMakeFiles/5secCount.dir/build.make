# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.cyOB7AUMHQ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.cyOB7AUMHQ/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/5secCount.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5secCount.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5secCount.dir/flags.make

CMakeFiles/5secCount.dir/5secCount.c.o: CMakeFiles/5secCount.dir/flags.make
CMakeFiles/5secCount.dir/5secCount.c.o: ../5secCount.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.cyOB7AUMHQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/5secCount.dir/5secCount.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/5secCount.dir/5secCount.c.o   -c /tmp/tmp.cyOB7AUMHQ/5secCount.c

CMakeFiles/5secCount.dir/5secCount.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5secCount.dir/5secCount.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.cyOB7AUMHQ/5secCount.c > CMakeFiles/5secCount.dir/5secCount.c.i

CMakeFiles/5secCount.dir/5secCount.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5secCount.dir/5secCount.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.cyOB7AUMHQ/5secCount.c -o CMakeFiles/5secCount.dir/5secCount.c.s

# Object files for target 5secCount
5secCount_OBJECTS = \
"CMakeFiles/5secCount.dir/5secCount.c.o"

# External object files for target 5secCount
5secCount_EXTERNAL_OBJECTS =

5secCount: CMakeFiles/5secCount.dir/5secCount.c.o
5secCount: CMakeFiles/5secCount.dir/build.make
5secCount: CMakeFiles/5secCount.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.cyOB7AUMHQ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 5secCount"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5secCount.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5secCount.dir/build: 5secCount

.PHONY : CMakeFiles/5secCount.dir/build

CMakeFiles/5secCount.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5secCount.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5secCount.dir/clean

CMakeFiles/5secCount.dir/depend:
	cd /tmp/tmp.cyOB7AUMHQ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.cyOB7AUMHQ /tmp/tmp.cyOB7AUMHQ /tmp/tmp.cyOB7AUMHQ/cmake-build-debug /tmp/tmp.cyOB7AUMHQ/cmake-build-debug /tmp/tmp.cyOB7AUMHQ/cmake-build-debug/CMakeFiles/5secCount.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5secCount.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/chuancey/tmp/tmp.uvDJqAdkKi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/myCopy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myCopy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myCopy.dir/flags.make

CMakeFiles/myCopy.dir/myCopy.c.o: CMakeFiles/myCopy.dir/flags.make
CMakeFiles/myCopy.dir/myCopy.c.o: ../myCopy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myCopy.dir/myCopy.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myCopy.dir/myCopy.c.o   -c /home/chuancey/tmp/tmp.uvDJqAdkKi/myCopy.c

CMakeFiles/myCopy.dir/myCopy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myCopy.dir/myCopy.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuancey/tmp/tmp.uvDJqAdkKi/myCopy.c > CMakeFiles/myCopy.dir/myCopy.c.i

CMakeFiles/myCopy.dir/myCopy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myCopy.dir/myCopy.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuancey/tmp/tmp.uvDJqAdkKi/myCopy.c -o CMakeFiles/myCopy.dir/myCopy.c.s

# Object files for target myCopy
myCopy_OBJECTS = \
"CMakeFiles/myCopy.dir/myCopy.c.o"

# External object files for target myCopy
myCopy_EXTERNAL_OBJECTS =

myCopy: CMakeFiles/myCopy.dir/myCopy.c.o
myCopy: CMakeFiles/myCopy.dir/build.make
myCopy: CMakeFiles/myCopy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable myCopy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myCopy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myCopy.dir/build: myCopy

.PHONY : CMakeFiles/myCopy.dir/build

CMakeFiles/myCopy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myCopy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myCopy.dir/clean

CMakeFiles/myCopy.dir/depend:
	cd /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuancey/tmp/tmp.uvDJqAdkKi /home/chuancey/tmp/tmp.uvDJqAdkKi /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles/myCopy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myCopy.dir/depend


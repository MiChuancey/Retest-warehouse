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
include CMakeFiles/IO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IO.dir/flags.make

CMakeFiles/IO.dir/main.c.o: CMakeFiles/IO.dir/flags.make
CMakeFiles/IO.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IO.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IO.dir/main.c.o   -c /home/chuancey/tmp/tmp.uvDJqAdkKi/main.c

CMakeFiles/IO.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IO.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuancey/tmp/tmp.uvDJqAdkKi/main.c > CMakeFiles/IO.dir/main.c.i

CMakeFiles/IO.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IO.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuancey/tmp/tmp.uvDJqAdkKi/main.c -o CMakeFiles/IO.dir/main.c.s

# Object files for target IO
IO_OBJECTS = \
"CMakeFiles/IO.dir/main.c.o"

# External object files for target IO
IO_EXTERNAL_OBJECTS =

IO: CMakeFiles/IO.dir/main.c.o
IO: CMakeFiles/IO.dir/build.make
IO: CMakeFiles/IO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable IO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IO.dir/build: IO

.PHONY : CMakeFiles/IO.dir/build

CMakeFiles/IO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IO.dir/clean

CMakeFiles/IO.dir/depend:
	cd /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuancey/tmp/tmp.uvDJqAdkKi /home/chuancey/tmp/tmp.uvDJqAdkKi /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles/IO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IO.dir/depend


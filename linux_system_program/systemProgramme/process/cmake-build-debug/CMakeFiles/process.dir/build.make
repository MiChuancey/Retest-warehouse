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
CMAKE_SOURCE_DIR = /home/chuancey/tmp/tmp.gTtUxwhsKY

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/process.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/process.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/process.dir/flags.make

CMakeFiles/process.dir/main.c.o: CMakeFiles/process.dir/flags.make
CMakeFiles/process.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/process.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/process.dir/main.c.o   -c /home/chuancey/tmp/tmp.gTtUxwhsKY/main.c

CMakeFiles/process.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/process.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuancey/tmp/tmp.gTtUxwhsKY/main.c > CMakeFiles/process.dir/main.c.i

CMakeFiles/process.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/process.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuancey/tmp/tmp.gTtUxwhsKY/main.c -o CMakeFiles/process.dir/main.c.s

# Object files for target process
process_OBJECTS = \
"CMakeFiles/process.dir/main.c.o"

# External object files for target process
process_EXTERNAL_OBJECTS =

process: CMakeFiles/process.dir/main.c.o
process: CMakeFiles/process.dir/build.make
process: CMakeFiles/process.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable process"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/process.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/process.dir/build: process

.PHONY : CMakeFiles/process.dir/build

CMakeFiles/process.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/process.dir/cmake_clean.cmake
.PHONY : CMakeFiles/process.dir/clean

CMakeFiles/process.dir/depend:
	cd /home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuancey/tmp/tmp.gTtUxwhsKY /home/chuancey/tmp/tmp.gTtUxwhsKY /home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug /home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug /home/chuancey/tmp/tmp.gTtUxwhsKY/cmake-build-debug/CMakeFiles/process.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/process.dir/depend


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
include CMakeFiles/checkPasswd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checkPasswd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checkPasswd.dir/flags.make

CMakeFiles/checkPasswd.dir/checkPasswd.c.o: CMakeFiles/checkPasswd.dir/flags.make
CMakeFiles/checkPasswd.dir/checkPasswd.c.o: ../checkPasswd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/checkPasswd.dir/checkPasswd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checkPasswd.dir/checkPasswd.c.o   -c /home/chuancey/tmp/tmp.uvDJqAdkKi/checkPasswd.c

CMakeFiles/checkPasswd.dir/checkPasswd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkPasswd.dir/checkPasswd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuancey/tmp/tmp.uvDJqAdkKi/checkPasswd.c > CMakeFiles/checkPasswd.dir/checkPasswd.c.i

CMakeFiles/checkPasswd.dir/checkPasswd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkPasswd.dir/checkPasswd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuancey/tmp/tmp.uvDJqAdkKi/checkPasswd.c -o CMakeFiles/checkPasswd.dir/checkPasswd.c.s

# Object files for target checkPasswd
checkPasswd_OBJECTS = \
"CMakeFiles/checkPasswd.dir/checkPasswd.c.o"

# External object files for target checkPasswd
checkPasswd_EXTERNAL_OBJECTS =

checkPasswd: CMakeFiles/checkPasswd.dir/checkPasswd.c.o
checkPasswd: CMakeFiles/checkPasswd.dir/build.make
checkPasswd: CMakeFiles/checkPasswd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable checkPasswd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checkPasswd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checkPasswd.dir/build: checkPasswd

.PHONY : CMakeFiles/checkPasswd.dir/build

CMakeFiles/checkPasswd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checkPasswd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checkPasswd.dir/clean

CMakeFiles/checkPasswd.dir/depend:
	cd /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuancey/tmp/tmp.uvDJqAdkKi /home/chuancey/tmp/tmp.uvDJqAdkKi /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage /home/chuancey/tmp/tmp.uvDJqAdkKi/cmake-build-debug-coverage/CMakeFiles/checkPasswd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checkPasswd.dir/depend

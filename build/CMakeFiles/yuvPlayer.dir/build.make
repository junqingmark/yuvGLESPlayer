# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/henry/src_test/learnOpengl/yuvPlayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/henry/src_test/learnOpengl/yuvPlayer/build

# Include any dependencies generated for this target.
include CMakeFiles/yuvPlayer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yuvPlayer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yuvPlayer.dir/flags.make

CMakeFiles/yuvPlayer.dir/main.cpp.o: CMakeFiles/yuvPlayer.dir/flags.make
CMakeFiles/yuvPlayer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/henry/src_test/learnOpengl/yuvPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yuvPlayer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yuvPlayer.dir/main.cpp.o -c /home/henry/src_test/learnOpengl/yuvPlayer/main.cpp

CMakeFiles/yuvPlayer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yuvPlayer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/henry/src_test/learnOpengl/yuvPlayer/main.cpp > CMakeFiles/yuvPlayer.dir/main.cpp.i

CMakeFiles/yuvPlayer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yuvPlayer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/henry/src_test/learnOpengl/yuvPlayer/main.cpp -o CMakeFiles/yuvPlayer.dir/main.cpp.s

CMakeFiles/yuvPlayer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/yuvPlayer.dir/main.cpp.o.requires

CMakeFiles/yuvPlayer.dir/main.cpp.o.provides: CMakeFiles/yuvPlayer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/yuvPlayer.dir/build.make CMakeFiles/yuvPlayer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/yuvPlayer.dir/main.cpp.o.provides

CMakeFiles/yuvPlayer.dir/main.cpp.o.provides.build: CMakeFiles/yuvPlayer.dir/main.cpp.o


# Object files for target yuvPlayer
yuvPlayer_OBJECTS = \
"CMakeFiles/yuvPlayer.dir/main.cpp.o"

# External object files for target yuvPlayer
yuvPlayer_EXTERNAL_OBJECTS =

yuvPlayer: CMakeFiles/yuvPlayer.dir/main.cpp.o
yuvPlayer: CMakeFiles/yuvPlayer.dir/build.make
yuvPlayer: CMakeFiles/yuvPlayer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/henry/src_test/learnOpengl/yuvPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable yuvPlayer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yuvPlayer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yuvPlayer.dir/build: yuvPlayer

.PHONY : CMakeFiles/yuvPlayer.dir/build

CMakeFiles/yuvPlayer.dir/requires: CMakeFiles/yuvPlayer.dir/main.cpp.o.requires

.PHONY : CMakeFiles/yuvPlayer.dir/requires

CMakeFiles/yuvPlayer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yuvPlayer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yuvPlayer.dir/clean

CMakeFiles/yuvPlayer.dir/depend:
	cd /home/henry/src_test/learnOpengl/yuvPlayer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/henry/src_test/learnOpengl/yuvPlayer /home/henry/src_test/learnOpengl/yuvPlayer /home/henry/src_test/learnOpengl/yuvPlayer/build /home/henry/src_test/learnOpengl/yuvPlayer/build /home/henry/src_test/learnOpengl/yuvPlayer/build/CMakeFiles/yuvPlayer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yuvPlayer.dir/depend


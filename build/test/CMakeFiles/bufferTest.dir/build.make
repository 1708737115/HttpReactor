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
CMAKE_SOURCE_DIR = /home/fengxu/mylib/HttpReactor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fengxu/mylib/HttpReactor/build

# Include any dependencies generated for this target.
include test/CMakeFiles/bufferTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/bufferTest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/bufferTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/bufferTest.dir/flags.make

test/CMakeFiles/bufferTest.dir/BufferTest.cpp.o: test/CMakeFiles/bufferTest.dir/flags.make
test/CMakeFiles/bufferTest.dir/BufferTest.cpp.o: ../test/BufferTest.cpp
test/CMakeFiles/bufferTest.dir/BufferTest.cpp.o: test/CMakeFiles/bufferTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxu/mylib/HttpReactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/bufferTest.dir/BufferTest.cpp.o"
	cd /home/fengxu/mylib/HttpReactor/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/bufferTest.dir/BufferTest.cpp.o -MF CMakeFiles/bufferTest.dir/BufferTest.cpp.o.d -o CMakeFiles/bufferTest.dir/BufferTest.cpp.o -c /home/fengxu/mylib/HttpReactor/test/BufferTest.cpp

test/CMakeFiles/bufferTest.dir/BufferTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bufferTest.dir/BufferTest.cpp.i"
	cd /home/fengxu/mylib/HttpReactor/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxu/mylib/HttpReactor/test/BufferTest.cpp > CMakeFiles/bufferTest.dir/BufferTest.cpp.i

test/CMakeFiles/bufferTest.dir/BufferTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bufferTest.dir/BufferTest.cpp.s"
	cd /home/fengxu/mylib/HttpReactor/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxu/mylib/HttpReactor/test/BufferTest.cpp -o CMakeFiles/bufferTest.dir/BufferTest.cpp.s

# Object files for target bufferTest
bufferTest_OBJECTS = \
"CMakeFiles/bufferTest.dir/BufferTest.cpp.o"

# External object files for target bufferTest
bufferTest_EXTERNAL_OBJECTS =

../bin/bufferTest: test/CMakeFiles/bufferTest.dir/BufferTest.cpp.o
../bin/bufferTest: test/CMakeFiles/bufferTest.dir/build.make
../bin/bufferTest: ../lib/libBuffer.so
../bin/bufferTest: test/CMakeFiles/bufferTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxu/mylib/HttpReactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/bufferTest"
	cd /home/fengxu/mylib/HttpReactor/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bufferTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/bufferTest.dir/build: ../bin/bufferTest
.PHONY : test/CMakeFiles/bufferTest.dir/build

test/CMakeFiles/bufferTest.dir/clean:
	cd /home/fengxu/mylib/HttpReactor/build/test && $(CMAKE_COMMAND) -P CMakeFiles/bufferTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/bufferTest.dir/clean

test/CMakeFiles/bufferTest.dir/depend:
	cd /home/fengxu/mylib/HttpReactor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxu/mylib/HttpReactor /home/fengxu/mylib/HttpReactor/test /home/fengxu/mylib/HttpReactor/build /home/fengxu/mylib/HttpReactor/build/test /home/fengxu/mylib/HttpReactor/build/test/CMakeFiles/bufferTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/bufferTest.dir/depend

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
include src/utils/CMakeFiles/config.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/utils/CMakeFiles/config.dir/compiler_depend.make

# Include the progress variables for this target.
include src/utils/CMakeFiles/config.dir/progress.make

# Include the compile flags for this target's objects.
include src/utils/CMakeFiles/config.dir/flags.make

src/utils/CMakeFiles/config.dir/config.cpp.o: src/utils/CMakeFiles/config.dir/flags.make
src/utils/CMakeFiles/config.dir/config.cpp.o: ../src/utils/config.cpp
src/utils/CMakeFiles/config.dir/config.cpp.o: src/utils/CMakeFiles/config.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxu/mylib/HttpReactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/utils/CMakeFiles/config.dir/config.cpp.o"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/utils/CMakeFiles/config.dir/config.cpp.o -MF CMakeFiles/config.dir/config.cpp.o.d -o CMakeFiles/config.dir/config.cpp.o -c /home/fengxu/mylib/HttpReactor/src/utils/config.cpp

src/utils/CMakeFiles/config.dir/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/config.dir/config.cpp.i"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxu/mylib/HttpReactor/src/utils/config.cpp > CMakeFiles/config.dir/config.cpp.i

src/utils/CMakeFiles/config.dir/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/config.dir/config.cpp.s"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxu/mylib/HttpReactor/src/utils/config.cpp -o CMakeFiles/config.dir/config.cpp.s

src/utils/CMakeFiles/config.dir/ini.cpp.o: src/utils/CMakeFiles/config.dir/flags.make
src/utils/CMakeFiles/config.dir/ini.cpp.o: ../src/utils/ini.cpp
src/utils/CMakeFiles/config.dir/ini.cpp.o: src/utils/CMakeFiles/config.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxu/mylib/HttpReactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/utils/CMakeFiles/config.dir/ini.cpp.o"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/utils/CMakeFiles/config.dir/ini.cpp.o -MF CMakeFiles/config.dir/ini.cpp.o.d -o CMakeFiles/config.dir/ini.cpp.o -c /home/fengxu/mylib/HttpReactor/src/utils/ini.cpp

src/utils/CMakeFiles/config.dir/ini.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/config.dir/ini.cpp.i"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxu/mylib/HttpReactor/src/utils/ini.cpp > CMakeFiles/config.dir/ini.cpp.i

src/utils/CMakeFiles/config.dir/ini.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/config.dir/ini.cpp.s"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxu/mylib/HttpReactor/src/utils/ini.cpp -o CMakeFiles/config.dir/ini.cpp.s

# Object files for target config
config_OBJECTS = \
"CMakeFiles/config.dir/config.cpp.o" \
"CMakeFiles/config.dir/ini.cpp.o"

# External object files for target config
config_EXTERNAL_OBJECTS =

../lib/libconfig.so: src/utils/CMakeFiles/config.dir/config.cpp.o
../lib/libconfig.so: src/utils/CMakeFiles/config.dir/ini.cpp.o
../lib/libconfig.so: src/utils/CMakeFiles/config.dir/build.make
../lib/libconfig.so: src/utils/CMakeFiles/config.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxu/mylib/HttpReactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../../lib/libconfig.so"
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/config.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/utils/CMakeFiles/config.dir/build: ../lib/libconfig.so
.PHONY : src/utils/CMakeFiles/config.dir/build

src/utils/CMakeFiles/config.dir/clean:
	cd /home/fengxu/mylib/HttpReactor/build/src/utils && $(CMAKE_COMMAND) -P CMakeFiles/config.dir/cmake_clean.cmake
.PHONY : src/utils/CMakeFiles/config.dir/clean

src/utils/CMakeFiles/config.dir/depend:
	cd /home/fengxu/mylib/HttpReactor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxu/mylib/HttpReactor /home/fengxu/mylib/HttpReactor/src/utils /home/fengxu/mylib/HttpReactor/build /home/fengxu/mylib/HttpReactor/build/src/utils /home/fengxu/mylib/HttpReactor/build/src/utils/CMakeFiles/config.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/utils/CMakeFiles/config.dir/depend


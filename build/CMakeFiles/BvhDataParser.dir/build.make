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
CMAKE_SOURCE_DIR = /home/wanghuigang/code/cpp/BvhDataParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wanghuigang/code/cpp/BvhDataParser/build

# Include any dependencies generated for this target.
include CMakeFiles/BvhDataParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BvhDataParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BvhDataParser.dir/flags.make

CMakeFiles/BvhDataParser.dir/src/main.cpp.o: CMakeFiles/BvhDataParser.dir/flags.make
CMakeFiles/BvhDataParser.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanghuigang/code/cpp/BvhDataParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BvhDataParser.dir/src/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BvhDataParser.dir/src/main.cpp.o -c /home/wanghuigang/code/cpp/BvhDataParser/src/main.cpp

CMakeFiles/BvhDataParser.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BvhDataParser.dir/src/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanghuigang/code/cpp/BvhDataParser/src/main.cpp > CMakeFiles/BvhDataParser.dir/src/main.cpp.i

CMakeFiles/BvhDataParser.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BvhDataParser.dir/src/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanghuigang/code/cpp/BvhDataParser/src/main.cpp -o CMakeFiles/BvhDataParser.dir/src/main.cpp.s

CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.o: CMakeFiles/BvhDataParser.dir/flags.make
CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.o: ../src/writeNeo4j.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanghuigang/code/cpp/BvhDataParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.o -c /home/wanghuigang/code/cpp/BvhDataParser/src/writeNeo4j.cpp

CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanghuigang/code/cpp/BvhDataParser/src/writeNeo4j.cpp > CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.i

CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanghuigang/code/cpp/BvhDataParser/src/writeNeo4j.cpp -o CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.s

CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.o: CMakeFiles/BvhDataParser.dir/flags.make
CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.o: ../src/readBvh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanghuigang/code/cpp/BvhDataParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.o -c /home/wanghuigang/code/cpp/BvhDataParser/src/readBvh.cpp

CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanghuigang/code/cpp/BvhDataParser/src/readBvh.cpp > CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.i

CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanghuigang/code/cpp/BvhDataParser/src/readBvh.cpp -o CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.s

# Object files for target BvhDataParser
BvhDataParser_OBJECTS = \
"CMakeFiles/BvhDataParser.dir/src/main.cpp.o" \
"CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.o" \
"CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.o"

# External object files for target BvhDataParser
BvhDataParser_EXTERNAL_OBJECTS =

BvhDataParser: CMakeFiles/BvhDataParser.dir/src/main.cpp.o
BvhDataParser: CMakeFiles/BvhDataParser.dir/src/writeNeo4j.cpp.o
BvhDataParser: CMakeFiles/BvhDataParser.dir/src/readBvh.cpp.o
BvhDataParser: CMakeFiles/BvhDataParser.dir/build.make
BvhDataParser: CMakeFiles/BvhDataParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wanghuigang/code/cpp/BvhDataParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable BvhDataParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BvhDataParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BvhDataParser.dir/build: BvhDataParser

.PHONY : CMakeFiles/BvhDataParser.dir/build

CMakeFiles/BvhDataParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BvhDataParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BvhDataParser.dir/clean

CMakeFiles/BvhDataParser.dir/depend:
	cd /home/wanghuigang/code/cpp/BvhDataParser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanghuigang/code/cpp/BvhDataParser /home/wanghuigang/code/cpp/BvhDataParser /home/wanghuigang/code/cpp/BvhDataParser/build /home/wanghuigang/code/cpp/BvhDataParser/build /home/wanghuigang/code/cpp/BvhDataParser/build/CMakeFiles/BvhDataParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BvhDataParser.dir/depend


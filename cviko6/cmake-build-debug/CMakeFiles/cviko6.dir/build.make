# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "/Users/stepankudlacek/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/stepankudlacek/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stepankudlacek/Desktop/AL/cviko6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cviko6.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cviko6.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cviko6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cviko6.dir/flags.make

CMakeFiles/cviko6.dir/main.cpp.o: CMakeFiles/cviko6.dir/flags.make
CMakeFiles/cviko6.dir/main.cpp.o: /Users/stepankudlacek/Desktop/AL/cviko6/main.cpp
CMakeFiles/cviko6.dir/main.cpp.o: CMakeFiles/cviko6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cviko6.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cviko6.dir/main.cpp.o -MF CMakeFiles/cviko6.dir/main.cpp.o.d -o CMakeFiles/cviko6.dir/main.cpp.o -c /Users/stepankudlacek/Desktop/AL/cviko6/main.cpp

CMakeFiles/cviko6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cviko6.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stepankudlacek/Desktop/AL/cviko6/main.cpp > CMakeFiles/cviko6.dir/main.cpp.i

CMakeFiles/cviko6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cviko6.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stepankudlacek/Desktop/AL/cviko6/main.cpp -o CMakeFiles/cviko6.dir/main.cpp.s

CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o: CMakeFiles/cviko6.dir/flags.make
CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o: /Users/stepankudlacek/Desktop/AL/cviko6/GraphInMatrix.cpp
CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o: CMakeFiles/cviko6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o -MF CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o.d -o CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o -c /Users/stepankudlacek/Desktop/AL/cviko6/GraphInMatrix.cpp

CMakeFiles/cviko6.dir/GraphInMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cviko6.dir/GraphInMatrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stepankudlacek/Desktop/AL/cviko6/GraphInMatrix.cpp > CMakeFiles/cviko6.dir/GraphInMatrix.cpp.i

CMakeFiles/cviko6.dir/GraphInMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cviko6.dir/GraphInMatrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stepankudlacek/Desktop/AL/cviko6/GraphInMatrix.cpp -o CMakeFiles/cviko6.dir/GraphInMatrix.cpp.s

# Object files for target cviko6
cviko6_OBJECTS = \
"CMakeFiles/cviko6.dir/main.cpp.o" \
"CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o"

# External object files for target cviko6
cviko6_EXTERNAL_OBJECTS =

cviko6: CMakeFiles/cviko6.dir/main.cpp.o
cviko6: CMakeFiles/cviko6.dir/GraphInMatrix.cpp.o
cviko6: CMakeFiles/cviko6.dir/build.make
cviko6: CMakeFiles/cviko6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cviko6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cviko6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cviko6.dir/build: cviko6
.PHONY : CMakeFiles/cviko6.dir/build

CMakeFiles/cviko6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cviko6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cviko6.dir/clean

CMakeFiles/cviko6.dir/depend:
	cd /Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stepankudlacek/Desktop/AL/cviko6 /Users/stepankudlacek/Desktop/AL/cviko6 /Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug /Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug /Users/stepankudlacek/Desktop/AL/cviko6/cmake-build-debug/CMakeFiles/cviko6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cviko6.dir/depend

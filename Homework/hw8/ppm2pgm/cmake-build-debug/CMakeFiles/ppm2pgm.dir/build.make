# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ppm2pgm.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ppm2pgm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ppm2pgm.dir/flags.make

CMakeFiles/ppm2pgm.dir/main.cpp.o: CMakeFiles/ppm2pgm.dir/flags.make
CMakeFiles/ppm2pgm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ppm2pgm.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ppm2pgm.dir/main.cpp.o -c /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/main.cpp

CMakeFiles/ppm2pgm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppm2pgm.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/main.cpp > CMakeFiles/ppm2pgm.dir/main.cpp.i

CMakeFiles/ppm2pgm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppm2pgm.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/main.cpp -o CMakeFiles/ppm2pgm.dir/main.cpp.s

# Object files for target ppm2pgm
ppm2pgm_OBJECTS = \
"CMakeFiles/ppm2pgm.dir/main.cpp.o"

# External object files for target ppm2pgm
ppm2pgm_EXTERNAL_OBJECTS =

ppm2pgm: CMakeFiles/ppm2pgm.dir/main.cpp.o
ppm2pgm: CMakeFiles/ppm2pgm.dir/build.make
ppm2pgm: CMakeFiles/ppm2pgm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ppm2pgm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ppm2pgm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ppm2pgm.dir/build: ppm2pgm
.PHONY : CMakeFiles/ppm2pgm.dir/build

CMakeFiles/ppm2pgm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ppm2pgm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ppm2pgm.dir/clean

CMakeFiles/ppm2pgm.dir/depend:
	cd /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug /Users/bernardlaughlin/Desktop/Code/C++/cs201/Homework/hw8/ppm2pgm/cmake-build-debug/CMakeFiles/ppm2pgm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ppm2pgm.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tahol\code\processing-cpp\marching_squares

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tahol\code\processing-cpp\marching_squares\build

# Include any dependencies generated for this target.
include CMakeFiles/MarchingSquares.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MarchingSquares.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MarchingSquares.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarchingSquares.dir/flags.make

CMakeFiles/MarchingSquares.dir/main.cpp.obj: CMakeFiles/MarchingSquares.dir/flags.make
CMakeFiles/MarchingSquares.dir/main.cpp.obj: CMakeFiles/MarchingSquares.dir/includes_CXX.rsp
CMakeFiles/MarchingSquares.dir/main.cpp.obj: C:/Users/tahol/code/processing-cpp/marching_squares/main.cpp
CMakeFiles/MarchingSquares.dir/main.cpp.obj: CMakeFiles/MarchingSquares.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tahol\code\processing-cpp\marching_squares\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MarchingSquares.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarchingSquares.dir/main.cpp.obj -MF CMakeFiles\MarchingSquares.dir\main.cpp.obj.d -o CMakeFiles\MarchingSquares.dir\main.cpp.obj -c C:\Users\tahol\code\processing-cpp\marching_squares\main.cpp

CMakeFiles/MarchingSquares.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarchingSquares.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tahol\code\processing-cpp\marching_squares\main.cpp > CMakeFiles\MarchingSquares.dir\main.cpp.i

CMakeFiles/MarchingSquares.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarchingSquares.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tahol\code\processing-cpp\marching_squares\main.cpp -o CMakeFiles\MarchingSquares.dir\main.cpp.s

CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj: CMakeFiles/MarchingSquares.dir/flags.make
CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj: CMakeFiles/MarchingSquares.dir/includes_CXX.rsp
CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj: C:/Users/tahol/code/processing-cpp/marching_squares/src/marching_squares.cpp
CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj: CMakeFiles/MarchingSquares.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tahol\code\processing-cpp\marching_squares\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj -MF CMakeFiles\MarchingSquares.dir\src\marching_squares.cpp.obj.d -o CMakeFiles\MarchingSquares.dir\src\marching_squares.cpp.obj -c C:\Users\tahol\code\processing-cpp\marching_squares\src\marching_squares.cpp

CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tahol\code\processing-cpp\marching_squares\src\marching_squares.cpp > CMakeFiles\MarchingSquares.dir\src\marching_squares.cpp.i

CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tahol\code\processing-cpp\marching_squares\src\marching_squares.cpp -o CMakeFiles\MarchingSquares.dir\src\marching_squares.cpp.s

# Object files for target MarchingSquares
MarchingSquares_OBJECTS = \
"CMakeFiles/MarchingSquares.dir/main.cpp.obj" \
"CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj"

# External object files for target MarchingSquares
MarchingSquares_EXTERNAL_OBJECTS =

MarchingSquares.exe: CMakeFiles/MarchingSquares.dir/main.cpp.obj
MarchingSquares.exe: CMakeFiles/MarchingSquares.dir/src/marching_squares.cpp.obj
MarchingSquares.exe: CMakeFiles/MarchingSquares.dir/build.make
MarchingSquares.exe: CMakeFiles/MarchingSquares.dir/linkLibs.rsp
MarchingSquares.exe: CMakeFiles/MarchingSquares.dir/objects1.rsp
MarchingSquares.exe: CMakeFiles/MarchingSquares.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\tahol\code\processing-cpp\marching_squares\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MarchingSquares.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MarchingSquares.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarchingSquares.dir/build: MarchingSquares.exe
.PHONY : CMakeFiles/MarchingSquares.dir/build

CMakeFiles/MarchingSquares.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MarchingSquares.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MarchingSquares.dir/clean

CMakeFiles/MarchingSquares.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tahol\code\processing-cpp\marching_squares C:\Users\tahol\code\processing-cpp\marching_squares C:\Users\tahol\code\processing-cpp\marching_squares\build C:\Users\tahol\code\processing-cpp\marching_squares\build C:\Users\tahol\code\processing-cpp\marching_squares\build\CMakeFiles\MarchingSquares.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MarchingSquares.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain"

# Include any dependencies generated for this target.
include CMakeFiles/CAD.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CAD.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CAD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CAD.dir/flags.make

CMakeFiles/CAD.dir/src/GradientRain.cpp.obj: CMakeFiles/CAD.dir/flags.make
CMakeFiles/CAD.dir/src/GradientRain.cpp.obj: src/GradientRain.cpp
CMakeFiles/CAD.dir/src/GradientRain.cpp.obj: CMakeFiles/CAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CAD.dir/src/GradientRain.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CAD.dir/src/GradientRain.cpp.obj -MF CMakeFiles\CAD.dir\src\GradientRain.cpp.obj.d -o CMakeFiles\CAD.dir\src\GradientRain.cpp.obj -c "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\GradientRain.cpp"

CMakeFiles/CAD.dir/src/GradientRain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAD.dir/src/GradientRain.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\GradientRain.cpp" > CMakeFiles\CAD.dir\src\GradientRain.cpp.i

CMakeFiles/CAD.dir/src/GradientRain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAD.dir/src/GradientRain.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\GradientRain.cpp" -o CMakeFiles\CAD.dir\src\GradientRain.cpp.s

CMakeFiles/CAD.dir/src/Poly.cpp.obj: CMakeFiles/CAD.dir/flags.make
CMakeFiles/CAD.dir/src/Poly.cpp.obj: src/Poly.cpp
CMakeFiles/CAD.dir/src/Poly.cpp.obj: CMakeFiles/CAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CAD.dir/src/Poly.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CAD.dir/src/Poly.cpp.obj -MF CMakeFiles\CAD.dir\src\Poly.cpp.obj.d -o CMakeFiles\CAD.dir\src\Poly.cpp.obj -c "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\Poly.cpp"

CMakeFiles/CAD.dir/src/Poly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAD.dir/src/Poly.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\Poly.cpp" > CMakeFiles\CAD.dir\src\Poly.cpp.i

CMakeFiles/CAD.dir/src/Poly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAD.dir/src/Poly.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\Poly.cpp" -o CMakeFiles\CAD.dir\src\Poly.cpp.s

CMakeFiles/CAD.dir/src/app.cpp.obj: CMakeFiles/CAD.dir/flags.make
CMakeFiles/CAD.dir/src/app.cpp.obj: src/app.cpp
CMakeFiles/CAD.dir/src/app.cpp.obj: CMakeFiles/CAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CAD.dir/src/app.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CAD.dir/src/app.cpp.obj -MF CMakeFiles\CAD.dir\src\app.cpp.obj.d -o CMakeFiles\CAD.dir\src\app.cpp.obj -c "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\app.cpp"

CMakeFiles/CAD.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAD.dir/src/app.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\app.cpp" > CMakeFiles\CAD.dir\src\app.cpp.i

CMakeFiles/CAD.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAD.dir/src/app.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\app.cpp" -o CMakeFiles\CAD.dir\src\app.cpp.s

CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj: CMakeFiles/CAD.dir/flags.make
CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj: src/pge/olcPixelGameEngine.cpp
CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj: CMakeFiles/CAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj -MF CMakeFiles\CAD.dir\src\pge\olcPixelGameEngine.cpp.obj.d -o CMakeFiles\CAD.dir\src\pge\olcPixelGameEngine.cpp.obj -c "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\pge\olcPixelGameEngine.cpp"

CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\pge\olcPixelGameEngine.cpp" > CMakeFiles\CAD.dir\src\pge\olcPixelGameEngine.cpp.i

CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\pge\olcPixelGameEngine.cpp" -o CMakeFiles\CAD.dir\src\pge\olcPixelGameEngine.cpp.s

CMakeFiles/CAD.dir/src/utils/utils.cpp.obj: CMakeFiles/CAD.dir/flags.make
CMakeFiles/CAD.dir/src/utils/utils.cpp.obj: src/utils/utils.cpp
CMakeFiles/CAD.dir/src/utils/utils.cpp.obj: CMakeFiles/CAD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CAD.dir/src/utils/utils.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CAD.dir/src/utils/utils.cpp.obj -MF CMakeFiles\CAD.dir\src\utils\utils.cpp.obj.d -o CMakeFiles\CAD.dir\src\utils\utils.cpp.obj -c "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\utils\utils.cpp"

CMakeFiles/CAD.dir/src/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAD.dir/src/utils/utils.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\utils\utils.cpp" > CMakeFiles\CAD.dir\src\utils\utils.cpp.i

CMakeFiles/CAD.dir/src/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAD.dir/src/utils/utils.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\src\utils\utils.cpp" -o CMakeFiles\CAD.dir\src\utils\utils.cpp.s

# Object files for target CAD
CAD_OBJECTS = \
"CMakeFiles/CAD.dir/src/GradientRain.cpp.obj" \
"CMakeFiles/CAD.dir/src/Poly.cpp.obj" \
"CMakeFiles/CAD.dir/src/app.cpp.obj" \
"CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj" \
"CMakeFiles/CAD.dir/src/utils/utils.cpp.obj"

# External object files for target CAD
CAD_EXTERNAL_OBJECTS =

CAD.exe: CMakeFiles/CAD.dir/src/GradientRain.cpp.obj
CAD.exe: CMakeFiles/CAD.dir/src/Poly.cpp.obj
CAD.exe: CMakeFiles/CAD.dir/src/app.cpp.obj
CAD.exe: CMakeFiles/CAD.dir/src/pge/olcPixelGameEngine.cpp.obj
CAD.exe: CMakeFiles/CAD.dir/src/utils/utils.cpp.obj
CAD.exe: CMakeFiles/CAD.dir/build.make
CAD.exe: CMakeFiles/CAD.dir/linklibs.rsp
CAD.exe: CMakeFiles/CAD.dir/objects1.rsp
CAD.exe: CMakeFiles/CAD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable CAD.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CAD.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CAD.dir/build: CAD.exe
.PHONY : CMakeFiles/CAD.dir/build

CMakeFiles/CAD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CAD.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CAD.dir/clean

CMakeFiles/CAD.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain" "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain" "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain" "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain" "C:\Users\unfal\Documents\Cool Stuff\Purple-Rain\CMakeFiles\CAD.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CAD.dir/depend


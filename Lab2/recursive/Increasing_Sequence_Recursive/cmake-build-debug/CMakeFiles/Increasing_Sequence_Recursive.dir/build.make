# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Increasing_Sequence_Recursive.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Increasing_Sequence_Recursive.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Increasing_Sequence_Recursive.dir\flags.make

CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.obj: CMakeFiles\Increasing_Sequence_Recursive.dir\flags.make
CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Increasing_Sequence_Recursive.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.obj /FdCMakeFiles\Increasing_Sequence_Recursive.dir\ /FS -c "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\main.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Increasing_Sequence_Recursive.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\main.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Increasing_Sequence_Recursive.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.s /c "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\main.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.obj: CMakeFiles\Increasing_Sequence_Recursive.dir\flags.make
CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.obj: ..\read_input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Increasing_Sequence_Recursive.dir/read_input.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.obj /FdCMakeFiles\Increasing_Sequence_Recursive.dir\ /FS -c "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\read_input.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Increasing_Sequence_Recursive.dir/read_input.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\read_input.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Increasing_Sequence_Recursive.dir/read_input.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.s /c "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\read_input.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.obj: CMakeFiles\Increasing_Sequence_Recursive.dir\flags.make
CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.obj: ..\increasing_sequence_recursive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Increasing_Sequence_Recursive.dir/increasing_sequence_recursive.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.obj /FdCMakeFiles\Increasing_Sequence_Recursive.dir\ /FS -c "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\increasing_sequence_recursive.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Increasing_Sequence_Recursive.dir/increasing_sequence_recursive.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\increasing_sequence_recursive.cpp"
<<

CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Increasing_Sequence_Recursive.dir/increasing_sequence_recursive.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.s /c "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\increasing_sequence_recursive.cpp"
<<

# Object files for target Increasing_Sequence_Recursive
Increasing_Sequence_Recursive_OBJECTS = \
"CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.obj" \
"CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.obj" \
"CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.obj"

# External object files for target Increasing_Sequence_Recursive
Increasing_Sequence_Recursive_EXTERNAL_OBJECTS =

Increasing_Sequence_Recursive.exe: CMakeFiles\Increasing_Sequence_Recursive.dir\main.cpp.obj
Increasing_Sequence_Recursive.exe: CMakeFiles\Increasing_Sequence_Recursive.dir\read_input.cpp.obj
Increasing_Sequence_Recursive.exe: CMakeFiles\Increasing_Sequence_Recursive.dir\increasing_sequence_recursive.cpp.obj
Increasing_Sequence_Recursive.exe: CMakeFiles\Increasing_Sequence_Recursive.dir\build.make
Increasing_Sequence_Recursive.exe: CMakeFiles\Increasing_Sequence_Recursive.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Increasing_Sequence_Recursive.exe"
	"C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Increasing_Sequence_Recursive.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Increasing_Sequence_Recursive.dir\objects1.rsp @<<
 /out:Increasing_Sequence_Recursive.exe /implib:Increasing_Sequence_Recursive.lib /pdb:"G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug\Increasing_Sequence_Recursive.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Increasing_Sequence_Recursive.dir\build: Increasing_Sequence_Recursive.exe

.PHONY : CMakeFiles\Increasing_Sequence_Recursive.dir\build

CMakeFiles\Increasing_Sequence_Recursive.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Increasing_Sequence_Recursive.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Increasing_Sequence_Recursive.dir\clean

CMakeFiles\Increasing_Sequence_Recursive.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive" "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive" "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug" "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug" "G:\SSU Courses\CS-315\Lab2\recursive\Increasing_Sequence_Recursive\cmake-build-debug\CMakeFiles\Increasing_Sequence_Recursive.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Increasing_Sequence_Recursive.dir\depend


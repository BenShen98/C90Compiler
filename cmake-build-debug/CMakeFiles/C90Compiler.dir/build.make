# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alan/Desktop/C90Compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alan/Desktop/C90Compiler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C90Compiler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C90Compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C90Compiler.dir/flags.make

CMakeFiles/C90Compiler.dir/include/testTree.cpp.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/include/testTree.cpp.o: ../include/testTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C90Compiler.dir/include/testTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C90Compiler.dir/include/testTree.cpp.o -c /Users/alan/Desktop/C90Compiler/include/testTree.cpp

CMakeFiles/C90Compiler.dir/include/testTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C90Compiler.dir/include/testTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alan/Desktop/C90Compiler/include/testTree.cpp > CMakeFiles/C90Compiler.dir/include/testTree.cpp.i

CMakeFiles/C90Compiler.dir/include/testTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C90Compiler.dir/include/testTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alan/Desktop/C90Compiler/include/testTree.cpp -o CMakeFiles/C90Compiler.dir/include/testTree.cpp.s

CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.o: ../requirement/debugging_exercise/example-backtrace-3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.o -c /Users/alan/Desktop/C90Compiler/requirement/debugging_exercise/example-backtrace-3.cpp

CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alan/Desktop/C90Compiler/requirement/debugging_exercise/example-backtrace-3.cpp > CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.i

CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alan/Desktop/C90Compiler/requirement/debugging_exercise/example-backtrace-3.cpp -o CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.s

CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.o: ../requirement/debugging_exercise/example-leak.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.o   -c /Users/alan/Desktop/C90Compiler/requirement/debugging_exercise/example-leak.c

CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/requirement/debugging_exercise/example-leak.c > CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.i

CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/requirement/debugging_exercise/example-leak.c -o CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.s

CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.o: ../src/C90_lexer.yy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.o -c /Users/alan/Desktop/C90Compiler/src/C90_lexer.yy.cpp

CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alan/Desktop/C90Compiler/src/C90_lexer.yy.cpp > CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.i

CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alan/Desktop/C90Compiler/src/C90_lexer.yy.cpp -o CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.s

CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.o: ../src/C90_parser.tab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.o -c /Users/alan/Desktop/C90Compiler/src/C90_parser.tab.cpp

CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alan/Desktop/C90Compiler/src/C90_parser.tab.cpp > CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.i

CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alan/Desktop/C90Compiler/src/C90_parser.tab.cpp -o CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.s

CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.o: ../src/c_compiler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.o -c /Users/alan/Desktop/C90Compiler/src/c_compiler.cpp

CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alan/Desktop/C90Compiler/src/c_compiler.cpp > CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.i

CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alan/Desktop/C90Compiler/src/c_compiler.cpp -o CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.o: ../test/c_translator/formative/f0.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f0.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f0.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f0.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.o: ../test/c_translator/formative/f1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f1.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f1.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f1.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.o: ../test/c_translator/formative/f2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f2.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f2.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f2.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.o: ../test/c_translator/formative/f3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f3.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f3.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f3.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.o: ../test/c_translator/formative/f4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f4.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f4.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f4.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.o: ../test/c_translator/formative/f5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f5.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f5.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f5.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.o: ../test/c_translator/formative/f6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f6.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f6.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f6.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.o: ../test/c_translator/formative/f7.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f7.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f7.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f7.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.o: ../test/c_translator/formative/f8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f8.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f8.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f8.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.s

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.o: ../test/c_translator/formative/f9.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.o   -c /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f9.c

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f9.c > CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.i

CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test/c_translator/formative/f9.c -o CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.s

CMakeFiles/C90Compiler.dir/test.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/test.c.o: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/C90Compiler.dir/test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/test.c.o   -c /Users/alan/Desktop/C90Compiler/test.c

CMakeFiles/C90Compiler.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/test.c > CMakeFiles/C90Compiler.dir/test.c.i

CMakeFiles/C90Compiler.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/test.c -o CMakeFiles/C90Compiler.dir/test.c.s

CMakeFiles/C90Compiler.dir/tt.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/tt.c.o: ../tt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/C90Compiler.dir/tt.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/tt.c.o   -c /Users/alan/Desktop/C90Compiler/tt.c

CMakeFiles/C90Compiler.dir/tt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/tt.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/tt.c > CMakeFiles/C90Compiler.dir/tt.c.i

CMakeFiles/C90Compiler.dir/tt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/tt.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/tt.c -o CMakeFiles/C90Compiler.dir/tt.c.s

CMakeFiles/C90Compiler.dir/x.c.o: CMakeFiles/C90Compiler.dir/flags.make
CMakeFiles/C90Compiler.dir/x.c.o: ../x.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/C90Compiler.dir/x.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C90Compiler.dir/x.c.o   -c /Users/alan/Desktop/C90Compiler/x.c

CMakeFiles/C90Compiler.dir/x.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C90Compiler.dir/x.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alan/Desktop/C90Compiler/x.c > CMakeFiles/C90Compiler.dir/x.c.i

CMakeFiles/C90Compiler.dir/x.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C90Compiler.dir/x.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alan/Desktop/C90Compiler/x.c -o CMakeFiles/C90Compiler.dir/x.c.s

# Object files for target C90Compiler
C90Compiler_OBJECTS = \
"CMakeFiles/C90Compiler.dir/include/testTree.cpp.o" \
"CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.o" \
"CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.o" \
"CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.o" \
"CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.o" \
"CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.o" \
"CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.o" \
"CMakeFiles/C90Compiler.dir/test.c.o" \
"CMakeFiles/C90Compiler.dir/tt.c.o" \
"CMakeFiles/C90Compiler.dir/x.c.o"

# External object files for target C90Compiler
C90Compiler_EXTERNAL_OBJECTS =

C90Compiler: CMakeFiles/C90Compiler.dir/include/testTree.cpp.o
C90Compiler: CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-backtrace-3.cpp.o
C90Compiler: CMakeFiles/C90Compiler.dir/requirement/debugging_exercise/example-leak.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/src/C90_lexer.yy.cpp.o
C90Compiler: CMakeFiles/C90Compiler.dir/src/C90_parser.tab.cpp.o
C90Compiler: CMakeFiles/C90Compiler.dir/src/c_compiler.cpp.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f0.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f1.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f2.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f3.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f4.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f5.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f6.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f7.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f8.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test/c_translator/formative/f9.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/test.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/tt.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/x.c.o
C90Compiler: CMakeFiles/C90Compiler.dir/build.make
C90Compiler: CMakeFiles/C90Compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable C90Compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C90Compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C90Compiler.dir/build: C90Compiler

.PHONY : CMakeFiles/C90Compiler.dir/build

CMakeFiles/C90Compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C90Compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C90Compiler.dir/clean

CMakeFiles/C90Compiler.dir/depend:
	cd /Users/alan/Desktop/C90Compiler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alan/Desktop/C90Compiler /Users/alan/Desktop/C90Compiler /Users/alan/Desktop/C90Compiler/cmake-build-debug /Users/alan/Desktop/C90Compiler/cmake-build-debug /Users/alan/Desktop/C90Compiler/cmake-build-debug/CMakeFiles/C90Compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C90Compiler.dir/depend

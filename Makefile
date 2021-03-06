# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_SOURCE_DIR = /home/anantoni/ClionProjects/os-f14-prj1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anantoni/ClionProjects/os-f14-prj1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anantoni/ClionProjects/os-f14-prj1/CMakeFiles /home/anantoni/ClionProjects/os-f14-prj1/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anantoni/ClionProjects/os-f14-prj1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named OS_F14_Prj1

# Build rule for target.
OS_F14_Prj1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 OS_F14_Prj1
.PHONY : OS_F14_Prj1

# fast build rule for target.
OS_F14_Prj1/fast:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/build
.PHONY : OS_F14_Prj1/fast

Bucket.o: Bucket.cpp.o
.PHONY : Bucket.o

# target to build an object file
Bucket.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Bucket.cpp.o
.PHONY : Bucket.cpp.o

Bucket.i: Bucket.cpp.i
.PHONY : Bucket.i

# target to preprocess a source file
Bucket.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Bucket.cpp.i
.PHONY : Bucket.cpp.i

Bucket.s: Bucket.cpp.s
.PHONY : Bucket.s

# target to generate assembly for a file
Bucket.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Bucket.cpp.s
.PHONY : Bucket.cpp.s

Hash.o: Hash.cpp.o
.PHONY : Hash.o

# target to build an object file
Hash.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Hash.cpp.o
.PHONY : Hash.cpp.o

Hash.i: Hash.cpp.i
.PHONY : Hash.i

# target to preprocess a source file
Hash.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Hash.cpp.i
.PHONY : Hash.cpp.i

Hash.s: Hash.cpp.s
.PHONY : Hash.s

# target to generate assembly for a file
Hash.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Hash.cpp.s
.PHONY : Hash.cpp.s

InvertedIndexList.o: InvertedIndexList.cpp.o
.PHONY : InvertedIndexList.o

# target to build an object file
InvertedIndexList.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/InvertedIndexList.cpp.o
.PHONY : InvertedIndexList.cpp.o

InvertedIndexList.i: InvertedIndexList.cpp.i
.PHONY : InvertedIndexList.i

# target to preprocess a source file
InvertedIndexList.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/InvertedIndexList.cpp.i
.PHONY : InvertedIndexList.cpp.i

InvertedIndexList.s: InvertedIndexList.cpp.s
.PHONY : InvertedIndexList.s

# target to generate assembly for a file
InvertedIndexList.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/InvertedIndexList.cpp.s
.PHONY : InvertedIndexList.cpp.s

Record.o: Record.cpp.o
.PHONY : Record.o

# target to build an object file
Record.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Record.cpp.o
.PHONY : Record.cpp.o

Record.i: Record.cpp.i
.PHONY : Record.i

# target to preprocess a source file
Record.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Record.cpp.i
.PHONY : Record.cpp.i

Record.s: Record.cpp.s
.PHONY : Record.s

# target to generate assembly for a file
Record.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Record.cpp.s
.PHONY : Record.cpp.s

RecordPointer.o: RecordPointer.cpp.o
.PHONY : RecordPointer.o

# target to build an object file
RecordPointer.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/RecordPointer.cpp.o
.PHONY : RecordPointer.cpp.o

RecordPointer.i: RecordPointer.cpp.i
.PHONY : RecordPointer.i

# target to preprocess a source file
RecordPointer.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/RecordPointer.cpp.i
.PHONY : RecordPointer.cpp.i

RecordPointer.s: RecordPointer.cpp.s
.PHONY : RecordPointer.s

# target to generate assembly for a file
RecordPointer.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/RecordPointer.cpp.s
.PHONY : RecordPointer.cpp.s

TownNode.o: TownNode.cpp.o
.PHONY : TownNode.o

# target to build an object file
TownNode.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/TownNode.cpp.o
.PHONY : TownNode.cpp.o

TownNode.i: TownNode.cpp.i
.PHONY : TownNode.i

# target to preprocess a source file
TownNode.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/TownNode.cpp.i
.PHONY : TownNode.cpp.i

TownNode.s: TownNode.cpp.s
.PHONY : TownNode.s

# target to generate assembly for a file
TownNode.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/TownNode.cpp.s
.PHONY : TownNode.cpp.s

Triple.o: Triple.cpp.o
.PHONY : Triple.o

# target to build an object file
Triple.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Triple.cpp.o
.PHONY : Triple.cpp.o

Triple.i: Triple.cpp.i
.PHONY : Triple.i

# target to preprocess a source file
Triple.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Triple.cpp.i
.PHONY : Triple.cpp.i

Triple.s: Triple.cpp.s
.PHONY : Triple.s

# target to generate assembly for a file
Triple.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/Triple.cpp.s
.PHONY : Triple.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/OS_F14_Prj1.dir/build.make CMakeFiles/OS_F14_Prj1.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... OS_F14_Prj1"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Bucket.o"
	@echo "... Bucket.i"
	@echo "... Bucket.s"
	@echo "... Hash.o"
	@echo "... Hash.i"
	@echo "... Hash.s"
	@echo "... InvertedIndexList.o"
	@echo "... InvertedIndexList.i"
	@echo "... InvertedIndexList.s"
	@echo "... Record.o"
	@echo "... Record.i"
	@echo "... Record.s"
	@echo "... RecordPointer.o"
	@echo "... RecordPointer.i"
	@echo "... RecordPointer.s"
	@echo "... TownNode.o"
	@echo "... TownNode.i"
	@echo "... TownNode.s"
	@echo "... Triple.o"
	@echo "... Triple.i"
	@echo "... Triple.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


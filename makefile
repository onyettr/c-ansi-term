#*******************************************************************************
# File name        : makefile
# File description : C Stack implementation
# Author           : ronyett
#*******************************************************************************

SRC_DIR			= 	.
OBJECT_DIR		= 	$(SRC_DIR)/object
MAKE_DIR_CMD		= 	mkdir $(OBJECT_DIR)

CC  			= 	gcc
LINK  			= 	gcc
AR				= 	ar
CHK   			= 	checkmk
CHECK_FOR_CHK		:= 	$(shell command -v $(CHK) 2> /dev/null)

#*******************************************************************************
# Build options
#*******************************************************************************

# gcov and gprof build options
COVPFLAGS		= 	-fprofile-arcs -ftest-coverage
PROFLAGS		= 	-pg
#PFLAGS			= 	$(COVFLAGS)

# Main CC and Link build strings
DEBUG			= 	-g
CFLAGS			= 	-c -std=c99 -Wall -pedantic $(PFLAGS)
LFLAGS			= 	$(PFLAGS) -static -L.

# Flags specific for Unity build
UNITY_CFLAGS 		+= -Wall
UNITY_CFLAGS 		+= -Wextra
UNITY_CFLAGS 		+= -Wpointer-arith
UNITY_CFLAGS 		+= -Wcast-align
UNITY_CFLAGS 		+= -Wwrite-strings
UNITY_CFLAGS 		+= -Wswitch-default
UNITY_CFLAGS 		+= -Wunreachable-code
UNITY_CFLAGS 		+= -Winit-self
UNITY_CFLAGS 		+= -Wmissing-field-initializers
UNITY_CFLAGS 		+= -Wno-unknown-pragmas
UNITY_CFLAGS 		+= -Wstrict-prototypes
UNITY_CFLAGS 		+= -Wundef
UNITY_CFLAGS 		+= -Wold-style-definition
UNITY_CFLAGS 		+= -DUNITY_OUTPUT_COLORS

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness

#
# Code checking with splint
#
CODE_CHECK       	= 	splint
CODE_CHECK_ARGS	 	= 	-showfunc -mustfreefresh -nullpass -nullret -noeffect

# Unity support
UNITY_ROOT 		= 	../../unity/auto/
RUBY			= 	ruby

#
# Libs, objs targets
# libstack library is built from trap handling and the stack implementation. 
#
OBJS  		     	=	$(OBJECT_DIR)/main.o 		\
		       		$(OBJECT_DIR)/test_gfx.o	\
				$(OBJECT_DIR)/test_colors.o

LIBS  		     	= libansigfx.a

TEST_STACK 	     	= ansigfx_test.ts

#*******************************************************************************
# Build targets:
# all		Creates object directory, builds executable and runs checker
# lib		Build only the list library, no test harness
# splint-it	run the Syntax checker
# clean		Delete object and library files
#*******************************************************************************

all:	$(OBJECT_DIR) ansigfx.exe libansigfx.a
#test_harness unity_test_harness

lib:	$(LIBS)

ansigfx.exe:	$(OBJS) $(LIBS)
	$(LINK) $(OBJS) $(LFLAGS) -lansigfx -o ansigfx.exe

libansigfx.a:	$(OBJECT_DIR)/ansigfx.o
	$(AR) rcs libansigfx.a $(OBJECT_DIR)/ansigfx.o

$(OBJECT_DIR):
	-$(MAKE_DIR_CMD)

$(OBJECT_DIR)/main.o:		main.c
	$(CC) $(CFLAGS) $(DEBUG) main.c -o $(OBJECT_DIR)/main.o
$(OBJECT_DIR)/ansigfx.o:	ansigfx.c
	$(CC) $(CFLAGS) $(DEBUG) ansigfx.c -o $(OBJECT_DIR)/ansigfx.o
$(OBJECT_DIR)/test_gfx.o:	test_gfx.c
	$(CC) $(CFLAGS) $(DEBUG) test_gfx.c -o $(OBJECT_DIR)/test_gfx.o
$(OBJECT_DIR)/test_colors.o:	test_colors.c
	$(CC) $(CFLAGS) $(DEBUG) test_colors.c -o $(OBJECT_DIR)/test_colors.o

#
# Unity test harness
#
unity_test_harness: 	unitytest.exe unitytest_Runner.exe

unitytest.exe:		libstack.a $(OBJECT_DIR)/unitytest.o $(OBJECT_DIR)/unity.o
	$(CC) -o unitytest.exe $(OBJECT_DIR)/unity.o $(OBJECT_DIR)/unitytest.o -static -L. -lstack 

unitytest_Runner.exe:	libstack.a $(OBJECT_DIR)/unity.o $(OBJECT_DIR)/unitytest_Runner.o
	$(CC) -o unitytest_Runner.exe $(OBJECT_DIR)/unity.o $(OBJECT_DIR)/unitytest_Runner.o -L. -lstack 

$(OBJECT_DIR)/unity.o:	unity/unity.c
	$(CC) $(UNITY_CFLAGS) $(CFLAGS) -I unity/ unity/unity.c -o $(OBJECT_DIR)/unity.o
$(OBJECT_DIR)/unitytest.o:	unitytest.c
	$(CC) $(UNITY_CFLAGS) $(CFLAGS) -I unity/ unitytest.c -o $(OBJECT_DIR)/unitytest.o
$(OBJECT_DIR)/unitytest_Runner.o:	unitytest_Runner.c
	$(CC) $(UNITY_CFLAGS) $(CFLAGS) -I unity/ unitytest_Runner.c -o $(OBJECT_DIR)/unitytest_Runner.o
unitytest_Runner.c:  unitytest.c
	$(RUBY) $(UNITY_ROOT)/generate_test_runner.rb unitytest.c

#
# This is the "check" target: Test harness is in stack_check.ts file and 
# this is converted by "check" into a C file which is linked to give another
# executable. 
# 
# NOTE: This will not build if you have the Profiling enabled as the libstack.a 
# contains gcov 
#
test_harness: libansigfx.a ansigfx_check.ts
ifndef CHECK_FOR_CHK
	@echo "** checkmk command not found"
else
	$(CHK) ansigfx_check.ts > ansigfx_check.c
	$(CC) -o ansigfx_check.exe ansigfx_check.c -static -L. -lcheck -lansigfx
endif

#
# Code checking target
#
splint-it:
	$(CODE_CHECK) $(CODE_CHECK_ARGS) main.c
	$(CODE_CHECK) $(CODE_CHECK_ARGS) ansigfx.c   

clean:
	rm -f ansigfx.exe
	rm -f ansigfx_check.exe
	rm -f unitytest.exe
	rm -f $(OBJECT_DIR)/ansigfx.o
	rm -f libansigfx.a
	rm -f $(OBJECT_DIR)/test_gfx.o
	rm -f $(OBJECT_DIR)/test_colors.o
	rm -f $(OBJECT_DIR)/main.o
	rm -f $(OBJECT_DIR)/unity.o
	rm -f $(OBJECT_DIR)/unitytest.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f gmon.out
	rm -f core

#
# Fin
#


###############################################
# Makefile for compiling the program skeleton
# 'make'           build executable file 'parseFormula'
# 'make doxy'      build project manual in doxygen
# 'make all'       build project + manual
# 'make clean'     removes all .o, executable and doxy log
###############################################

PROJ = parseFormula   # the name of the project
CC   = gcc            # name of compiler
DOXYGEN = doxygen      # name of doxygen binary

# define any compile-time flags
CFLAGS = -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic
LFLAGS = -lm

###############################################
# You don't need to edit anything below this line
###############################################

# list of object files
# Explicitly list all your .c files here
C_FILES = Main.c periodic_table.c sort.c checkFormula_extendFormula.c formulaProton.c stack.c

# Create object files from C files
OBJS := $(patsubst %.c, %.o, $(C_FILES))

# To create the executable file we need the individual object files
$(PROJ): $(OBJS)
	$(CC) -g -o $(PROJ) $(OBJS) $(LFLAGS)

# To create each individual object file we need to
# compile these files using the following general
# purpose macro
.c.o:
	$(CC) $(CFLAGS) -g -c $<

# To make all (program + manual)
all : $(PROJ) doxy

# To make doxy
doxy:
	$(DOXYGEN) project2.conf &> doxygen.log

# To clean .o files: "make clean"
clean:
	rm -rf *.o doxygen.log html $(PROJ)

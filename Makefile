###		
###     Made by Dario Frello and Jacques Monnier
###

### Generate 32 bit executable : 1=yes, 0=no = machine target (16 or 32 or 8 ...)
M32?= 0 
### Including Debugging Symbols : 1=yes, 0=no step by step
DBG?= 1
### Including Compiler Optimizations : 1=yes, 0=no (line per line)
OPT?= 0
### Keep Assembly Files : 1=yes, 0=no (can change the value that is why there is a "?")
ASM?= 0

CC=g++
NAMEEXT=jack
#name of the exe
NAME=test-smart-wc
#Dependancies
DEPEND=dependencies
BINDIR= bin
INCDIR= inc
SRCDIR= src
OBJDIR= obj

#cast : poblem cast
#pointer : almost same as cast
#sign-compare : unsigned == signed (warning)
WARNINGS=-W -Wall -Wundef -Wpointer-arith -Wcast-qual -Wsign-compare 

#optimisation or not (-O3 : code size and vitess)
ifeq ($(OPT),1)
OPTIMIZATIONS=-O3 -fomit-frame-pointer -ffast-math
else
OPTIMIZATIONS=-O0
endif


CXXFLAGS=$(WARNINGS) $(OPTIMIZATIONS) -std=c++11
ifeq ($(M32),1)
CXXFLAGS+=-m32
endif
ifeq ($(DBG),1)
CXXFLAGS+=-g
endif

#If you have a file more than 4G you can open it if you have compiled in 32 bits
#offset is if you want to go through 4GO when seek
FLAGS=$(CXXFLAGS) -I$(INCDIR)

#link to library math
LIBS=-lm
#extention for objects
OBJSUF= .o

#automatization of listing sources
SRC=    $(wildcard $(SRCDIR)/*.cpp) 
#all files included with .O is moved in the obj directory
OBJ=    $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

BIN=    $(BINDIR)/$(NAME).$(NAMEEXT)

#only these command are available
.PHONY: default clean objdir_mk bindir_mk depend tgz

#no make plus parameter than you do this
default: objdir_mk depend bindir_mk bin

clean:
	@rm -rf $(OBJDIR)
	@rm -rf ./asm/
	@rm -rf $(BINDIR)/$(NAME).$(NAMEEXT)
	@rm -rf $(DEPEND)
	@rm -rf $(NAME).tgz 
	@echo
	@echo Cleaning done!
	@echo

bin:    bindir_mk $(OBJ)
	@echo
	@echo 'creating binary "$(BIN)"'
	@$(CC) $(FLAGS) -o $(BIN) $(OBJ) $(LIBS)
	@echo 'Using Flags: $(FLAGS)'
	@echo 'Using Libs: $(LIBS)'
	@echo
	@echo '... done'
	@echo
	
#if you want to to compile with multi core and to avoid problems of linkings
#if there is the sed option there is no check in inc directory
depend:
	@echo
	@echo Compiler is: $(CC)
	@echo 'checking dependencies'
	@$(SHELL) -ec '$(CC) $(FLAGS) -MM $(INCLUDE) $(SRC) | sed '\''s@\(.*\)\.o[ :]@$(OBJDIR)/\1.o:@g'\'' >$(DEPEND)'
	@echo '... done'
	@echo


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo
	@echo 'Compiling file "$<"'
	@echo 'Using Flags: $(FLAGS)'
	@$(CC) -c -o $@ $(FLAGS) $<
ifeq ($(ASM),1)
	@mkdir -p ./asm/
	@$(CC) -c -S $(FLAGS) $<
	@mv *.s ./asm/
endif

bindir_mk:
	@echo 'Creating $(BINDIR) ...'
	@mkdir -p $(BINDIR)

objdir_mk:
	@echo 'Creating $(OBJDIR) ...'
	@mkdir -p $(OBJDIR)

tgz: clean
	@echo Making tgz archive
	@tar cvzf $(NAME).tgz $(SRCDIR) $(INCDIR) Makefile
	@echo 
	@echo $(NAME).tgz archive created...Bye!
	
-include $(DEPEND)


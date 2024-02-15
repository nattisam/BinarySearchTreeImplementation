# Compiler
CC = g++
# Compiler flags
CWFLAGS = -Wall -Wextra -std=c++11
# Command for removing files
RM = rm -f

# Directories
SRCDIR = .
OBJDIR =
BINDIR =

# Source files
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
# Object files
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,%.o,$(SRCFILES))
# Executable name
EXE = BSTApp
# Output file for redirection
OUTPUT_TXT = BSToutput.txt

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJFILES)
	$(CC) $(CWFLAGS) $^ -o $@

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CWFLAGS) -c $< -o $@

clean:
	del $(OBJFILES) $(EXE) $(OUTPUT_TXT)

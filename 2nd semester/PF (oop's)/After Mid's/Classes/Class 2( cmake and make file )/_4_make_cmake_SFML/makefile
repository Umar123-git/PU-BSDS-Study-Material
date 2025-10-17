# Paths - adjust to your SFML installation
SFML_ROOT = C:\SFML-3.0.0
INCLUDE_DIR = $(SFML_ROOT)\include
LIB_DIR = $(SFML_ROOT)\lib

# Output folders
BIN_DIR = bin
OBJ_DIR = obj

# Tools
CXX = g++
LINK = g++
DEL = del /Q

# Source and target
# for the time being manually copy resourse folder in bin
SRC = src\Tennis.cpp
#SRC = src\SoundCapture.cpp
OBJ = $(OBJ_DIR)\main.obj
EXE = $(BIN_DIR)\SFML_App.exe

# Compiler and linker flags
CXXFLAGS = /I"$(INCLUDE_DIR)" /std:c++latest /EHsc
LDFLAGS = /LIBPATH:"$(LIB_DIR)" sfml-graphics.lib sfml-window.lib sfml-system.lib sfml-audio.lib

# Default target
all: $(EXE)

# Link
$(EXE): $(OBJ)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(LINK) /OUT:$(EXE) $(OBJ) $(LDFLAGS)

# Compile
$(OBJ): $(SRC)
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) /Fo$(OBJ) /c $(SRC)

# Clean
clean:
	-$(DEL) $(OBJ_DIR)\*.obj
	-$(DEL) $(BIN_DIR)\*.exe


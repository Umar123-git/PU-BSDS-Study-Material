# Variables
SRC_DIR=src
INCLUDE_DIR=include
LIB_DIR=lib

BUILD_DIR=build

DEBUG_DIR=$(BUILD_DIR)/debug
RELEASE_DIR=$(BUILD_DIR)/release

# Compiler and linker settings
CC=g++
LINKER=g++

DEBUG_CFLAGS=-I$(INCLUDE_DIR) -g -O0 -DDEBUG
DEBUG_LFLAGS=-L$(LIB_DIR)

RELEASE_CFLAGS=-I$(INCLUDE_DIR) -O2 -DNDEBUG
RELEASE_LFLAGS=-L$(LIB_DIR)

# Source files
SOURCES=$(SRC_DIR)/main.cpp $(SRC_DIR)/complex1.cpp $(SRC_DIR)/complex2.cpp $(SRC_DIR)/complex3.cpp

# Targets
DEBUG_TARGET=$(BUILD_DIR)/Project_debug.exe
RELEASE_TARGET=$(BUILD_DIR)/Project_release.exe

# Platform-specific mkdir
MKDIR_CMD = if not exist $(1) mkdir $(1)

# Rules
all: debug release

debug: $(DEBUG_TARGET)

release: $(RELEASE_TARGET)

$(DEBUG_TARGET): $(DEBUG_DIR)/main.o $(DEBUG_DIR)/complex1.o $(DEBUG_DIR)/complex2.o $(DEBUG_DIR)/complex3.o
	$(call MKDIR_CMD, $(BUILD_DIR))
	$(LINKER) $^ $(DEBUG_LFLAGS) -o $@

$(RELEASE_TARGET): $(RELEASE_DIR)/main.o $(RELEASE_DIR)/complex1.o $(RELEASE_DIR)/complex2.o $(RELEASE_DIR)/complex3.o
	$(call MKDIR_CMD, $(BUILD_DIR))
	$(LINKER) $^ $(RELEASE_LFLAGS) -o $@

$(DEBUG_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(call MKDIR_CMD, $(DEBUG_DIR))
	$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(DEBUG_DIR)/complex1.o: $(SRC_DIR)/complex1.cpp
	$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(DEBUG_DIR)/complex2.o: $(SRC_DIR)/complex2.cpp
	$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(DEBUG_DIR)/complex3.o: $(SRC_DIR)/complex3.cpp
	$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(RELEASE_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(call MKDIR_CMD, $(RELEASE_DIR))
	$(CC) $(RELEASE_CFLAGS) -c $< -o $@

$(RELEASE_DIR)/complex1.o: $(SRC_DIR)/complex1.cpp
	$(CC) $(RELEASE_CFLAGS) -c $< -o $@

$(RELEASE_DIR)/complex2.o: $(SRC_DIR)/complex2.cpp
	$(CC) $(RELEASE_CFLAGS) -c $< -o $@

$(RELEASE_DIR)/complex3.o: $(SRC_DIR)/complex3.cpp
	$(CC) $(RELEASE_CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

# Add run targets to execute debug or release
run: debug
	./$(DEBUG_TARGET)

run_debug: $(DEBUG_TARGET)
	./$(DEBUG_TARGET)

run_release: $(RELEASE_TARGET)
	./$(RELEASE_TARGET)

.PHONY: all debug release clean run run_debug run_release

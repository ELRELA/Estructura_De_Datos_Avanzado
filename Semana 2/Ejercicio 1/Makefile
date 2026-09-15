CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -Iinclude

SRC_DIR = src
APP_DIR = apps
OBJ_DIR = obj
BIN_DIR = bin

OBJS   = $(OBJ_DIR)/tabla_hash.o $(OBJ_DIR)/app_main.o
TARGET = $(BIN_DIR)/app_tabla_hash

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/tabla_hash.o: $(SRC_DIR)/tabla_hash.cpp include/tabla_hash.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/app_main.o: $(APP_DIR)/app_main.cpp include/tabla_hash.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
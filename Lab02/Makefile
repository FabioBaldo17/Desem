TARGET = prog
CC = g++
CFLAGS = -g -Wall


OBJ_DIR = obj
SRC_DIR = src
HEAD_DIR = inc


SRC = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS =  $(wildcard $(HEAD_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

VPATH = $(SRC)

.PHONY: default all clean list
default: $(TARGET)

all: default

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$()/%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -I./$(HEAD_DIR) -o $@

list:
	$(info    SRC is $(SRC))
	$(info    HEADERS is $(HEADERS))
	$(info    OBJECTS is $(OBJECTS))


clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)

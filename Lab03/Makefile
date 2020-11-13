####################################################################################################
# list of possible commands:
# all -> compile [need subfolders]
# beauty -> create subfolders if not already present, reorder files into subfolders
# directories -> create subfolders
# list -> list all files in all subfolders
# clean -> remove all compilation files
####################################################################################################

CC = g++
CFLAGS+=-Wall -Wextra -g -O0 -MD -I./$(HEAD_DIR)

#C_CPP = cpp # This must be changed to cpp when used with cpp files

TARGET = prog
MKDIR_P = mkdir -p

OBJ_DIR = obj
SRC_DIR = src
HEAD_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(HEAD_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))
REAL_OBJ = $(wildcard $(OBJ_DIR)/%.o)

VPATH = $(SRC_DIR)

.PHONY: default all clean list directories beauty

all: default

default: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	echo "$< --> $@"
	$(CC) $(CFLAGS) -c $< -o $@

directories: ${OBJ_DIR} ${SRC_DIR} ${HEAD_DIR}

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

${SRC_DIR}:
	${MKDIR_P} ${SRC_DIR}

${HEAD_DIR}:
	${MKDIR_P} ${HEAD_DIR}

beauty: directories
	find . -maxdepth 1 -name \*.o -exec mv {} $(OBJ_DIR) \;
	find . -maxdepth 1 -name \*.d -exec mv {} $(OBJ_DIR) \;
	find . -maxdepth 1 -name \*.cpp -exec mv {} $(SRC_DIR) \;
	find . -maxdepth 1 -name \*.h -exec mv {} $(HEAD_DIR) \;

list: beauty
	$(info    SRC is $(SRC))
	$(info    HEADERS is $(HEADERS))
	$(info    OBJECTS is $(REAL_OBJ))

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.d
	rm -f $(TARGET)


-include $(OBJECTS:.o=.d)

echo:
	echo "$(OBJECTS)"

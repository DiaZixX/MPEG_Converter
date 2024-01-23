TARGET = mpeg
CC = gcc
CFLAGS = -Wall
SRC_DIR = Source
OBJ_DIR = Bin

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Create the directory only if it doesn't exist 
$(shell mkdir -p $(OBJ_DIR))

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "\n\nNe pas oublier d'executer la commande \033[1mmake clean\033[0m avant de push !\n\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

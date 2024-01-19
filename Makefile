TARGET = mpeg
CC = gcc
CFLAGS = -Wall
SRC_DIR = Source

SOURCES = $(SRC_DIR)/main.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) ;
	@echo "\n\nNe pas oublier d'executer la commande \033[1mmake clean\033[0m avant de push !\n\n"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

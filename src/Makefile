CC := g++
CFLAGS := -Wall -g -Iinclude
TARGET := inventory

all: $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

inventory: inventory_items.o inventory.o main.o
	@echo " Linking...";
	$(CC) $^ -o $@

clean:
	@echo " Cleaning...";
	rm -r *o $(TARGET)


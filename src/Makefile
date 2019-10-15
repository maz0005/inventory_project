CC := g++
CFLAGS := -Wall -g -Iinclude
OBJFILES := inventory_items.o inventory.o main.o
TARGET := bin/inventory

all: inventory

inventory: $(OBJFILES)
	@echo " Linking...";
	$(CC) $(OBJFILES) -o $(TARGET)

inventory_items.o: inventory_items.cpp
	$(CC) $(CFLAGS) -c inventory_items.cpp

inventory.o: inventory.cpp
	$(CC) $(CFLAGS) -c inventory.cpp
		
main.o: main.cpp
	$(CC) (CFLAGS) -c main.cpp

clean:
	@echo " Cleaning...";
	rm -r *o $(TARGET)

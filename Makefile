CC = g++
CFLAGS = -g
OBJFILES = inventory_items.o inventory.o main.o
TARGET = bin/inventory

all: inventory

inventory: $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET)

inventory_items.o: inventory_items.cpp
	$(CC) $(CFLAGS) -c inventory_items.cpp

inventory.o: inventory.cpp
	$(CC) $(CFLAGS) -c inventory.cpp
		
main.o: main.cpp
	$(CC) (CFLAGS) -c main.cpp

clean:
	rm -r *o $(TARGET)

CC=g++

all: inventory

inventory: inventory_items.o inventory.o main.o
	    $(CC) inventory_items.o inventory.o main.o -o inventory

inventory_items.o: inventory_items.cpp
		    $(CC) -g -c inventory_items.cpp

inventory.o: inventory.cpp
	      $(CC) -g -c inventory.cpp
		
main.o: main.cpp
	 $(CC) -g -c main.cpp

clean:
	rm -r *o inventory

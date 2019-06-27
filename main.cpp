
#include <fstream>
#include <iostream>
#include "inventory_items.h"
#include "inventory.h"


int main() {
 std::vector<User_Item> user_items;
 std::vector<Electronic> electronic_items;
 std::vector<Furniture> furniture_items;
 std::vector<Clothing> clothing_items;
 std::vector<Book> book_items;
 std::vector<double> positions;
 std::string user_name;
 std::string password;


 Startup_Handler(user_name, password, user_items, electronic_items, furniture_items, clothing_items, book_items, positions);
 
 electronic_items[0].Print_Item();
 std::cout << "\n\n";

 furniture_items[0].Print_Item();
 std::cout << "\n\n";
 furniture_items[1].Print_Item();
 std::cout << "\n\n";
 book_items[0].Print_Item();
 
 return 0;
}
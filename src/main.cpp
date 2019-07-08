
#include <fstream>
#include <iostream>
#include "../include/inventory_items.h"
#include "../include/inventory.h"


int main() {
 std::vector<User_Item> user_items;
 std::vector<Electronic> electronic_items;
 std::vector<Furniture> furniture_items;
 std::vector<Clothing> clothing_items;
 std::vector<Book> book_items;
 std::string user_name;
 std::string password;

 /*Startup the system. This deals with login if needed*/
 Startup_Handler(user_name, password, user_items, electronic_items, furniture_items, clothing_items, book_items);

 if (!user_name.empty()) { Login_Handler(user_name, password); };
 
 electronic_items[0].Print_Item();
 std::cout << "\n\n";

 furniture_items[0].Print_Item();
 std::cout << "\n\n";

 furniture_items[1].Print_Item();
 std::cout << "\n\n";

 book_items[0].Print_Item();
 std::cout << "\n\n";

 clothing_items[0].Print_Item();
 std::cout << "\n\n";

 user_items[0].Print_Item();
 std::cout << "\n\n";
 
 return 0;
}

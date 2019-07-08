
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
 std::string title;
 std::string file_name = "inventory_data.txt";

 /*Handle Login if needed*/
 Login_Handler(file_name);
 
 /*Startup the system. Retreive saved data*/
 Startup_Handler(file_name, user_name, password, title, user_items, electronic_items, furniture_items, clothing_items, book_items);
 
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

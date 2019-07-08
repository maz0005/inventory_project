
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
 std::string input;

 /*Handle Login if needed*/
 Login_Handler(file_name);
 
 /*Startup the system. Retreive saved data*/
 Startup_Handler(file_name, user_name, password, title, user_items, electronic_items, furniture_items, clothing_items, book_items);


 while (1) {
   Display_Menu(MAIN_MENU);
 		std::cout << "Enter one of the available options and press enter: ";
 		getline(std::cin, input);
  
 		if (!input.compare("1\0")) {
 				while(1) {
 						std::cout << "Enter one of the available options and press enter: ";
 						getline(std::cin, input);
       /*Call the appropriate handler*/
 						if (!input.compare("1\0"));
 						else if (!input.compare("2\0"));
 						else if (!input.compare("3\0"));
 						else if (!input.compare("4\0")) break;
 						else std::cout << "Please enter a valid option\n" std::endl;
 				}
 		}

 		else if (!input.compare("2\0")) {
 			
 		}

 		else if (!input.compare("3\0")) {
 			
 		}

 		else if (!input.compare("4\0")) {
 			
 		}

 		else if (!input.compare("5\0")) {
 				exit(1);	
 		}

 		else {
 				std::cout << "Please enter a valid option\n" std::endl;
 		}
 }
 

 return 0;
}

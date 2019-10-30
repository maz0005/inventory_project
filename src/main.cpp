
#include <fstream>
#include <iostream>
#include "../include/inventory_items.h"
#include "../include/inventory.h"


int main() {
 std::string user_name;
 std::string password;
 std::string title;
 std::string input;
 std::vector<bool> inventory_numbers;
 std::string file_name = "inventory_data.txt";
 
 HashMap<unsigned long, Item> database;
 /*Handle Login if needed*/
 Login_Handler(file_name);
 
 /*Startup the system. Retrieve saved data*/
 Startup_Handler(file_name, user_name, password, title, inventory_numbers, database);
 
 while (1) {
   Display_Menu(MAIN_MENU);
 		std::cout << "Enter one of the available options and press enter: ";
 		getline(std::cin, input);
  
 		if (!input.compare("1\0")) { /*View/Edit Inventory*/
 				while(1) {
 						Display_Menu(INVENTORY);
 						std::cout << "Enter one of the available options and press enter: ";

 						/*Call a specific handler*/
 						getline(std::cin, input);
 						if (!input.compare("1\0")); /*Display entire inventory*/
 								//display_handler();
 						else if (!input.compare("2\0")); /*Display by option*/
 								//display_bo_handler();
 						else if (!input.compare("3\0")); /*Manage prices*/
 								//price_handler();
 						else if (!input.compare("4\0")); /*Add/Remove from inventory*/
 								//add_remove_handler();
      					else if (!input.compare("5\0")) break; /*Return to Main Menu*/
 						else std::cout << "Please enter a valid option\n" << std::endl;
 				}
 		}

 		else if (!input.compare("2\0")) { /*Manage Acceptable Items*/
     while(1) {
       /*Call a specific handler*/
 						if (!input.compare("1\0")); /*Display Acceptable Item(s)*/
     					//display_accept_handler();
 						else if (!input.compare("2\0")); /*Add/Remove Acceptable Item(s)*/
     					//add_remove_accept_handler();
 						else if (!input.compare("3\0")) break; /*Return to Main Menu*/
 						else std::cout << "Please enter a valid option\n" << std::endl;
     }
 		}

 		else if (!input.compare("3\0")) { /*Change Username/Password*/
 				//modify_credentials();
 		}

 		else if (!input.compare("4\0")) { /*Change Company Name*/
 			
 		}

 		else if (!input.compare("5\0")) { /*Exit*/
 				//update file here
 				exit(0);	
 		}

 		else {
 				std::cout << "Please enter a valid option\n" << std::endl;
 		}
 }
 

 return 0;
}


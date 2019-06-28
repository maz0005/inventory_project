#include "inventory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


int Startup_Handler(std::string &user_name_In, std::string &password_In, std::vector<User_Item> &user_items_In, std::vector<Electronic> &electronic_items_In, 
	std::vector<Furniture> &furniture_items_In, std::vector<Clothing> &clothing_items_In, std::vector<Book> &book_items_In) {

 std::string data[14];
 std::vector<std::string> misc_names;
 std::vector<std::string> misc_values;
 std::vector<std::string> materials;
 std::vector<std::string> material_percentages;
 std::string temp;
 std::string temp2;

 std::ifstream input_file;
 input_file.open("inventory_data.txt");

 if(input_file.fail()) { 
 	std::cout << "Error with file: inventory_file\n" << std::endl; 
 	exit(1);
 }

 getline(input_file, temp);

 if(!temp.compare("no_saved_data\0")) return 1;

 if(temp.compare("end_username_password\0")) { /*Will return 0 if both equal. Means no username or password at this point in text file so won't enter*/
 		user_name_In = temp;
 		getline(input_file, password_In);
 }

 getline(input_file, temp);

 while(temp.compare("end_all_items\0")) {

  		if (!temp.compare("User Item\0")) { /*Check if user created a specific item*/
 	
 				getline(input_file, temp2);
 				do {
 						misc_names.push_back(temp2);
 						getline(input_file, temp2); /*Get corresponding value*/
 						misc_values.push_back(temp2);
 						getline(input_file, temp2); 

 				} while(temp2.compare("end_user_item\0"));

 				User_Item item = User_Item(temp, misc_names, misc_values);
 				user_items_In.push_back(item);
 				misc_names.clear();
 				misc_values.clear();
 		}

 		else { /*Check if item is one of the hardcoded items*/
 				data[0] = temp;
 				for (int i = 1; i < 7; i++) { getline(input_file, data[i]); } 
        
 				if (!temp.compare("Electronic\0")) {
 						for (int i = 7; i < 10; i++) { getline(input_file, data[i]); }
 						Electronic item = Electronic(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9]);
 						electronic_items_In.push_back(item);
 				}

 				else if (!temp.compare("Book\0")) {
 						for (int i = 7; i < 12; i++) { getline(input_file, data[i]); }
 						Book item = Book(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11]);
 						book_items_In.push_back(item);
 				}

 				else if (!temp.compare("Furniture\0")) {
 						for (int i = 7; i < 14; i++) { getline(input_file, data[i]); }
 						Furniture item = Furniture(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12], data[13]);
 						furniture_items_In.push_back(item);
 				}

  				else if (!temp.compare("Clothing\0")) {
 						for (int i = 7; i < 12; i++) { getline(input_file, data[i]); }
 						
 						getline(input_file, temp);
 						while(temp.compare("end_materials\0")) {
 								materials.push_back(temp);
 								getline(input_file, temp);
 								material_percentages.push_back(temp);
 								getline(input_file, temp);
 						}

 						Clothing item = Clothing(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], materials, material_percentages);
 						clothing_items_In.push_back(item);
 						materials.clear();
 						material_percentages.clear();
 				}
 		}

 		getline(input_file, temp);
 }

 input_file.close();

 return 0;
}


void Display_Menu(DISPLAY_OPTION, DISPLAY_FILTER) {

}

void Display_Inventory(DISPLAY_FILTER) {

}

void Manage_Inventory(void) {

}

void Change_User_Password(void) {

}

void Manage_Acc_Items(void) {

}

void Save_System(void){

}

void Login(std::string user_name_In, std::string password_In) {

}
#include "inventory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


/**
@brief Retrieve previously saved data from 
@param input_file File holding previously saved data
*/
int Startup_Handler(std::string &user_name_In, std::string &password_In, std::vector<User_Item> &user_items_In, std::vector<Electronic> &electronic_items_In, 
	std::vector<Furniture> &furniture_items_In, std::vector<Clothing> &clothing_items_In, std::vector<Book> &book_items_In, std::vector<double> &positions_In) {

 std::string data[14];
 std::vector<std::string> misc_names;
 std::vector<std::string> misc_values;
 std::vector<std::string> materials;
 std::vector<std::string> material_percentages;
 std::string temp;

 std::ifstream input_file;
 input_file.open("inventory_data.txt");

 if(input_file.fail()) { 
 	std::cout << "Error with file: inventory_file\n" << std::endl; 
 	exit(1);
 }

 getline(input_file, temp);

 if(!temp.compare("no_saved_data\0")) return 1;

 if(temp.compare("end_username_password\0")) { /*Will return 0 if both equal. Means no username or password at this point in text file*/
 		user_name_In = temp;
 		getline(input_file, password_In);
 }

 getline(input_file, temp);

 while(temp.compare("end_all_items\0")) {
 		data[0] = temp;
 		for (int i = 1; i < 7; i++) { getline(input_file, data[i]); }


 		if (data[0].compare("Electronic\0") == 0) {
 				for (int i = 7; i < 10; i++) { getline(input_file, data[i]); }
 				Electronic item = Electronic(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9]);
 				electronic_items_In.push_back(item);
 		}

 		else if (data[0].compare("Furniture\0") == 0) {
 				for (int i = 7; i < 14; i++) { getline(input_file, data[i]); }
 				Furniture item = Furniture(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12], data[13]);
 				furniture_items_In.push_back(item);
 		}


 		else if (data[0].compare("Book\0") == 0) {
 				for (int i = 7; i < 12; i++) { getline(input_file, data[i]); }
 				Book item = Book(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11]);
 				book_items_In.push_back(item);
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
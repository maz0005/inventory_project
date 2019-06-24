#include "inventory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


/**
@brief Retrieve previously saved data from 
@param input_file File holding previously saved data
*/
int Startup_Handler(std::string &user_name_In, std::string &password_In, std::vector<User_Item> &user_items_In, 
				std::vector<Electronic> &electronic_items_In, std::vector<Furniture> &furniture_items_In, std::vector<Clothing> &clothing_items_In, std::vector<Book> &book_items_In) {
 std::string temp;
 std::string item_type;
 std::string type;
 std::string inventory_num;
 std::string manufacturer;
 std::string model;
 std::string price;
 std::string color;
 std::string id_num;
 std::string condition;
 std::string used_condition;
 std::string material;
 std::string length;
 std::string width;
 std::string height;
 std::string gender;
 std::string size;
 std::string title;
 std::string author;
 std::string isbn;
 std::vector<std::string> misc_names;
 std::vector<std::string> misc_values;
 std::vector<std::string> materials;
 std::vector<std::string> material_percentages;



 std::ifstream input_file;
 input_file.open("inventory_data.txt");

 if(input_file.fail()) { 
 	std::cout << "Error with file: inventory_file\n" << std::endl; 
 	exit(1);
 }

 getline(input_file, temp);

 if(!temp.compare("no_saved_data\0")) return 1;

 if(temp.compare("end_username_password\0")) {
 		user_name_In = temp;
 		getline(input_file, password_In);
 }

 getline(input_file, temp);

 while(temp.compare("end_user_items\0")) {

 		item_type = temp;
 		getline(input_file, inventory_num);
 		getline(input_file, price);
 		getline(input_file, id_num);
 		getline(input_file, type);
 		getline(input_file, manufacturer);
 		getline(input_file, model);
  		getline(input_file, color);
 		getline(input_file, condition);
 		getline(input_file, used_condition);

 		getline(input_file, temp);
 		
 		while (temp.compare("end_materials\0")) {
 				materials.push_back(temp);
 				getline(input_file, temp);
 				material_percentages.push_back(temp);
 				getline(input_file, temp);

 		}

 		getline(input_file, temp);

 		while (temp.compare("end_user_item\0")) {
 				misc_names.push_back(temp);
 				getline(input_file, temp);
 				misc_values.push_back(temp);
 				getline(input_file, temp);
 		}
 	

 		User_Item item = User_Item(item_type, inventory_num, price, id_num, type, manufacturer, model, color, condition, used_condition, materials, material_percentages, misc_names, misc_values);
 		user_items_In.push_back(item);
 		materials.clear();
 		material_percentages.clear();
 		misc_names.clear();
 		misc_values.clear();

 		getline(input_file, temp);

 }

 getline(input_file, temp);
 while(temp.compare("end_electronic_items\0")) {
 		item_type = temp;
 		getline(input_file, inventory_num);
 		getline(input_file, price);
 		getline(input_file, id_num);
 		getline(input_file, type);
 		getline(input_file, manufacturer);
 		getline(input_file, model);
  		getline(input_file, color);
 		getline(input_file, condition);
 		getline(input_file, used_condition);


 		Electronic item = Electronic(item_type, inventory_num, price, id_num, type, manufacturer, model, color, condition, used_condition);
 		electronic_items_In.push_back(item);

 		getline(input_file, temp);
 }

 getline(input_file, temp);
 while(temp.compare("end_furniture_items\0")) {
 		item_type = temp;
 		getline(input_file, inventory_num);
 		getline(input_file, price);
 		getline(input_file, id_num);
 		getline(input_file, type);
 		getline(input_file, manufacturer);
 		getline(input_file, model);
  		getline(input_file, color);
 		getline(input_file, condition);
 		getline(input_file, used_condition);
 		getline(input_file, material);
  		getline(input_file, length);
 		getline(input_file, width);
 		getline(input_file, height);


 		Furniture item = Furniture(item_type, inventory_num, price, id_num, type, manufacturer, model, color, condition, used_condition, material, length, width, height);
 		furniture_items_In.push_back(item);

 		getline(input_file, temp);
 }

 getline(input_file, temp);

 while(temp.compare("end_clothing_items\0")) {
 		item_type = temp;
 		getline(input_file, inventory_num);
 		getline(input_file, price);
 		getline(input_file, id_num);
 		getline(input_file, type);
 		getline(input_file, manufacturer);
 		getline(input_file, model);
  		getline(input_file, color);
  		getline(input_file, gender);
 		getline(input_file, size);
 		getline(input_file, condition);
 		getline(input_file, used_condition);

 		getline(input_file, temp);
 		while (temp.compare("end_materials\0")) {
 				materials.push_back(temp);
 				getline(input_file, temp);
 				material_percentages.push_back(temp);
 				getline(input_file, temp);
 		}


 		Clothing item = Clothing(item_type, inventory_num, price, id_num, type, manufacturer, model, color, gender, size, condition, used_condition, materials, material_percentages);
 		clothing_items_In.push_back(item);
 		getline(input_file, item_type);
 }
 

 getline(input_file, temp);
 while(temp.compare("end_book_items\0")) {
 		item_type = temp;
 		getline(input_file, inventory_num);
 		getline(input_file, price);
 		getline(input_file, id_num);
 		getline(input_file, type);
 		getline(input_file, title);
 		getline(input_file, author);
 		getline(input_file, isbn);
  		getline(input_file, color);
 		getline(input_file, condition);
 		getline(input_file, used_condition);
 		getline(input_file, material);

 		Book item = Book(item_type, inventory_num, price, id_num, type, title, author, isbn, color, condition, used_condition, material);
 		book_items_In.push_back(item);

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
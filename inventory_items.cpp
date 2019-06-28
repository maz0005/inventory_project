#include "inventory_items.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream> 
#include <iomanip>

Item::Item() {
 category = "N/A";
 inventory_num = "N/A"; 
 price = "N/A";
 id_num = "N/A";
 color = "N/A";
 condition = "N/A";
 used_condition = "N/A";
}

Item::Item(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In) {
 category = category_In;
 inventory_num = inventory_num_In; 
 price = price_In;
 id_num = id_num_In;
 color = color_In;
 condition = condition_In;
 used_condition = used_condition_In;
}

void Item::Print_Type(void) const{

}

void Item::Print_Price(void) const{

}

void Item::Print_Inventory_Num(void) const{

}

void Item::Change_Price(std::string price_In) {

}

volatile void Item::Print_Item(void) const {

}

User_Item::User_Item(std::vector<std::string> misc_names_In, std::vector<std::string> misc_values_In) 
						: Item() {

 misc_names = misc_names_In;
 misc_values = misc_values_In;
}

void User_Item::Print_Item(void) const {


}

Electronic::Electronic(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string electronic_type_In, std::string manufacturer_In, std::string model_In) 
							: Item(category_In, inventory_num_In, price_In, id_num_In, color_In, condition_In, used_condition_In) {
 electronic_type = electronic_type_In; 
 manufacturer = manufacturer_In; 
 model = model_In;
}

void Electronic::Print_Item(void) const {
  std::cout << "Inventory#: " << std::left <<  std::setw(5) << inventory_num  << std::right <<  std::setw(13) << "Category: " << std::left << std::setw(11) << category 
  			<< std::right << std::setw(11) << "Color: " << std::left << std::setw(11) << color << std::right << std::setw(9) << "SKU#: " << std::left << std::setw(8) << id_num  
  			<< "\n" /*End row 1*/
  			<< std::right << std::setw(30) <<  "Type: " << std::left << std::setw(11) << electronic_type << std::right << std::setw(11) << "Condition: " 
  			<< std::left << std::setw(11) << condition << std::right << std::setw(10) << "Price: $" << std::left << std::setw(11) << price
  			<< "\n" /*End row 2*/
  			<< std::right << std::setw(30) << "Manufact: " << std::left << std::setw(11) << manufacturer << std::right << std::setw(11) << "Used Cond: " 
  			<< std::left << std::setw(11) << used_condition  
  			<< "\n"  /*End row 3*/
  			<< std::right << std::setw(30) <<  "Model: " << std::left << std::setw(11) << model << std::endl;


}

Furniture::Furniture(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string furniture_type_In, std::string manufacturer_In, std::string model_In, std::string material_In, std::string length_In, 
				std::string width_In, std::string height_In)
						: Item(category_In, inventory_num_In, price_In, id_num_In, color_In, condition_In, used_condition_In) {
 furniture_type = furniture_type_In; 
 manufacturer = manufacturer_In; 
 model = model_In; 
 material = material_In; 
 length = length_In; 
 width = width_In; 
 height = height_In; 
}

void Furniture::Print_Item(void) const {
  std::cout << "Inventory#: " << std::left <<  std::setw(5) << inventory_num  << std::right <<  std::setw(13) << "Category: " << std::left << std::setw(11) << category 
  			 << std::right << std::setw(11) << "Color: " << std::left << std::setw(11) << color << std::right << std::setw(9) << "Length: " << std::left << std::setw(9)
  			<< length << std::right << std::setw(9) << "SKU#: " << std::left << std::setw(8) << id_num  
  			<< "\n" /*End row 1*/
  			<< std::right << std::setw(30) <<  "Type: " << std::left << std::setw(11) << furniture_type << std::right << std::setw(11) << "Material: " << std::left 
  			<< std::setw(11) << material << std::right << std::setw(9) << "Width: " << std::left << std::setw(10) << width << std::right << std::setw(9) << "Price: $" << std::left << std::setw(11) << price 
  			<< "\n" /*End row 2*/
  			<< std::right << std::setw(30) << "Manufact: " << std::left << std::setw(11) << manufacturer << std::right << std::setw(11) << "Condition: " << std::left << std::setw(11) 
  			<< condition << std::right << std::setw(9) << "Height: " << std::left << std::setw(11) << height 
  			<< "\n"  /*End row 3*/
  			<< std::right << std::setw(30) <<  "Model: " << std::left << std::setw(11) << model << std::right << std::setw(10) <<  std::right << std::setw(11) << "Used Cond: " 
  			<< std::left << std::setw(11) << used_condition << std::endl;

}

Clothing::Clothing(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string clothing_type_In, std::string manufacturer_In, std::string model_In, std::string gender_In, std::string size_In, 
				std::vector<std::string> materials_In, std::vector<std::string> material_percentages_In) 
						: Item(category_In, inventory_num_In, price_In, id_num_In, color_In, condition_In, used_condition_In) {
 clothing_type = clothing_type_In; 
 manufacturer = manufacturer_In; 
 model = model_In; 
 gender = gender_In; 
 size = size_In; 
 materials = materials_In; 
 material_percentages = material_percentages_In; 

}

void Clothing::Print_Item(void) const {

  std::cout << "Inventory#: " << std::left <<  std::setw(5) << inventory_num  << std::right <<  std::setw(13) << "Category: " << std::left << std::setw(11) << category 
         << std::right << std::setw(11) << "Color: " << std::left << std::setw(11) << color << std::right << std::setw(12) << "SKU#: " << std::left << std::setw(11) << id_num  
        << "\n" /*End row 1*/
        << std::right << std::setw(30) <<  "Type: " << std::left << std::setw(11) << clothing_type << std::right << std::setw(11) << "Condition: " << std::left 
        << std::setw(11) << condition << std::right << std::setw(13) << "Price: $" << std::left << std::setw(11) << price 
        << "\n" /*End row 2*/
        << std::right << std::setw(30) << "Manufact: " << std::left << std::setw(11) << manufacturer << std::right << std::setw(11) << "Used Cond: " << std::left << std::setw(11) 
        << used_condition << std::right << std::setw(12) << "Materials: ";
        if (!materials.empty()) {
            std::cout << "{";
            for (int i = 0; i < materials.size(); i++) {
                std::cout << materials[i] << "," << material_percentages[i];
                if ((i + 1) != materials.size()) std::cout << ' ';
            }
            std::cout << "}\n";
        }
        /*End row 3*/
        std::cout << std::right << std::setw(30) <<  "Model: " << std::left << std::setw(11) << model << std::right << std::setw(11) << "Gender: " << std::left << std::setw(11)
        << gender << std::right << std::setw(12) << "Size: " << std::left << std::setw(10) << size 
        << std::endl;
}

Book::Book(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
		std::string book_type_In, std::string title_In, std::string author_In, std::string isbn_In, std::string material_In) 
				: Item(category_In, inventory_num_In, price_In, id_num_In, color_In, condition_In, used_condition_In) {
 book_type = book_type_In; 
 title = title_In; 
 author = author_In;
 isbn = isbn_In; 
 material = material_In; 

}

void Book::Print_Item(void) const {

  std::cout << "Inventory#: " << std::left <<  std::setw(5) << inventory_num  << std::right << std::setw(13) << "Category: " << std::left << std::setw(11) << category 
  			 << std::right << std::setw(11) << "Color: " << std::left << std::setw(11) << color << std::right << std::setw(9) << "SKU#: " << std::left << std::setw(8) << id_num  
  			<< "\n" /*End row 1*/
  			<< std::right << std::setw(30) <<  "Type: " << std::left << std::setw(11) << book_type << std::right << std::setw(11) << "Condition: " 
  			<< std::left << std::setw(11) << condition << std::right << std::setw(10) << "Price: $" << std::left << std::setw(11) << price
  			<< "\n" /*End row 2*/
  			<< std::right << std::setw(30) << "Author: " << std::left << std::setw(11) << author << std::right << std::setw(11) << "Used Cond: " 
  			<< std::left << std::setw(11) << used_condition  
  			<< std::right << std::setw(9) <<  "Title: " << title << std::endl;
        /*End row 3*/

}
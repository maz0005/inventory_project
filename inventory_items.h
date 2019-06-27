
#include <string>
#include <vector>

#ifndef INVENTORY_ITEMS_H
#define INVENTORY_ITEMS_H



class Item {
protected:
	std::string category;
	std::string inventory_num;
	std::string price;
	std::string id_num;
	std::string color;
	std::string condition;
	std::string used_condition;

public:
	Item();
	Item(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In);
	void Print_Type(void) const;
	void Print_Price(void) const;
	void Print_Inventory_Num(void) const;
	void Change_Price(std::string price_In);
	volatile void Print_Item(void) const;	
};

class User_Item : public Item {
private:
	std::string type;
	std::string manufacturer;
	std::string model;
	std::vector<std::string> misc_names;
	std::vector<std::string> misc_values;
	std::vector<std::string> materials;
	std::vector<std::string> material_percentages;
public:
	User_Item(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string type_In, std::string manufacturer_In, std::string model_In, std::vector<std::string> materials_In, std::vector<std::string> material_percentages_In, 
				std::vector<std::string> misc_names_In, std::vector<std::string> misc_values_In);

	void Print_Item(void) const;
};

class Electronic : public Item {
private:
	std::string electronic_type;
	std::string manufacturer;
	std::string model;

public:
	Electronic(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string electronic_type_In, std::string manufacturer_In, std::string model_In);

	void Print_Item(void) const;
};

class Furniture : public Item {
private:
	std::string furniture_type;
	std::string manufacturer;
	std::string model;
	std::string material;
	std::string length;
	std::string width;
	std::string height;

public:
	Furniture(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string furniture_type_In, std::string manufacturer_In, std::string model_In, std::string material_In, std::string length_In, 
				std::string width_In, std::string height_In);

	void Print_Item(void) const;
};

class Clothing : public Item {
private: 
	std::string clothing_type;
	std::string manufacturer;
	std::string model;
	std::string gender;
	std::string size;
	std::vector<std::string> materials;
	std::vector<std::string> material_percentages;

public:
	Clothing(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
				std::string clothing_type_In, std::string manufacturer_In, std::string model_In, std::string gender_In, std::string size_In, 
				std::vector<std::string> materials_In, std::vector<std::string> material_percentages_In);

	void Print_Item(void) const;
};

class Book : public Item {
private:
	std::string book_type;
	std::string title;
	std::string author;
	std::string isbn;
	std::string material;
public:
	Book(std::string category_In, std::string inventory_num_In, std::string price_In, std::string id_num_In, std::string color_In, std::string condition_In, std::string used_condition_In, 
		std::string book_type_In, std::string title_In, std::string author_In, std::string isbn_In, std::string material_In);
	void Print_Item(void) const;
};

#endif
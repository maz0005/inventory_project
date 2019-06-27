#include "inventory_items.h"
#include <string>
#include <fstream>
#include <vector>

#ifndef INVENTORY_H
#define INVENTORY_H


enum DISPLAY_OPTION {MAIN_MENU = 0, INVENTORY = 1, ACCECTABLE = 2};

enum DISPLAY_FILTER {KEYWORD = 0, CATEGORY = 1, BRAND = 2, INV_NUM = 3};

/**
@brief Retrieve previously saved data from 
@param input_file File holding previously saved data
*/
int Startup_Handler(std::string &user_name_In, std::string &password_In, std::vector<User_Item> &user_items_In, std::vector<Electronic> &electronic_items_In, 
	std::vector<Furniture> &furniture_items_In, std::vector<Clothing> &clothing_items_In, std::vector<Book> &book_items_In, std::vector<double> &positions_In);

void Display_Menu(DISPLAY_OPTION, DISPLAY_FILTER);

void Display_Inventory(DISPLAY_FILTER);

void Manage_Inventory(void);

void Change_User_Password(void);

void Manage_Acc_Items(void);

void Save_System(void);

void Login(std::string user_name_In, std::string password_In);

#endif
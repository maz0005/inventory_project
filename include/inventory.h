#include "inventory_items.h"
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <termios.h>

#ifndef INVENTORY_H
#define INVENTORY_H


enum DISPLAY_OPTION {MAIN_MENU = 0, INVENTORY = 1, INV_OPTION = 2, ACCEPTABLE = 3};

enum DISPLAY_FILTER {KEYWORD = 0, CATEGORY = 1, BRAND = 2, INV_NUM = 3};

/**
@brief Dynamic array that will change its size frequently
*/
struct Dynamic_Array {
bool* pointer;
unsigned long int size;
};

/**
@brief Retrieve previously saved data from 
@param input_file File holding previously saved data
@param user_name_In Username used for login
@param password Password used for login
@param &vector<User_Item>, &vector<Electronic>, &vector<Furniture>, &vector<Clothing>, &vector<Book> vectors you want items stored in.
*/
void Startup_Handler(const std::string &file_name_In, std::string &user_name_In, std::string &password_In, std::string &title_In, Dynamic_Array &inventory_numbers_In, std::vector<User_Item> &user_items_In, std::vector<Electronic> &electronic_items_In, std::vector<Furniture> &furniture_items_In, 
		     std::vector<Clothing> &clothing_items_In, std::vector<Book> &book_items_In);

/**
@brief Display one of the menu options option
@param option_In Display one of the menu options
*/
void Display_Menu(DISPLAY_OPTION option_In);

/**
@brief Display inventory with a filter option
@param filter_In Filter option
*/
void Display_Inventory(DISPLAY_FILTER filter_In);

void Manage_Inventory(void);

void Change_User_Password(void);

void Manage_Acc_Items(void);

/**
@brief Generates and returns a new inventory number
*/
double New_Inv_Number(void);

/**
@brief Update the text file: inventory_data.txt
*/
void Save_System(void);

void Login_Handler(const std::string &file_name_In);

#endif

#include "../include/inventory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


void Startup_Handler(const std::string &file_name_In, std::string &user_name_In, std::string &password_In, std::string &title_In, std::vector<User_Item> &user_items_In, std::vector<Electronic> &electronic_items_In, 
	std::vector<Furniture> &furniture_items_In, std::vector<Clothing> &clothing_items_In, std::vector<Book> &book_items_In) {

 std::string data[14]; /*Where data will be stored to instantiate objects*/
 std::vector<std::string> misc_names;
 std::vector<std::string> misc_values;
 std::vector<std::string> materials;
 std::vector<std::string> material_percentages;
 std::string temp;
 std::string temp2;

 std::ifstream input_file;
 input_file.open(file_name_In);

 if(input_file.fail()) { 
 	std::cout << "Error with file: inventory_file\n" << std::endl; 
 	exit(1);
 }

 getline(input_file, temp);
 if(!temp.compare("no_saved_data\0")) return; /*First boot up. No previously saved data.*/

 if(temp.compare("end_username_password\0")) { /*Will return 0 if both equal. Means no username or password at this point in text file so won't enter*/
	 	user_name_In = temp;
 		getline(input_file, password_In);
	 	getline(input_file, temp); /*Remove 'end_username_password' from stream*/
 }
	
 getline(input_file, temp);	
 if(temp.compare("end_title\0")) {  /*Will return 0 if no title at this point.*/
	 	title_In = temp;
	 	getline(input_file, temp); /*Remove 'end_title from stream'*/
 }

 std::cout << "Loading system...\n" << std::endl;
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
 				for (int i = 1; i < 7; i++) { getline(input_file, data[i]); } /*Get common memebers among all objects*/
        
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
 std::cout << "Bootup successful\n" << std::endl;
 for (int i = 0; i < 10000; i++); /*Make sure file closes before returning*/

}


void Display_Menu(DISPLAY_OPTION option_In) {
 switch (option_In) {

    case MAIN_MENU:
        std::cout << "***********************************************************************************************************\n"
                  << "*                                                Main Menu                                                *\n"
                  << "***********************************************************************************************************\n"
                  << "(1) View/Edit Inventory\n"
                  << "(2) Manage Acceptable Items\n"
                  << "(3) Change Username/Password\n"
                  << "(4) Change Company Name\n"
                  << "(5) Exit" << std::endl;
    break;

    case INVENTORY:
        std::cout << "***********************************************************************************************************\n"
                  << "*                                               Inventory Page                                            *\n"
                  << "***********************************************************************************************************\n"
                  << "(1) Display Entire Inventor\n"
                  << "(2) Display by Option\n"
                  << "(3) Manage Prices\n"
                  << "(4) Add to Inventory\n"
                  << "(5) Remove from Inventory\n"
                  << "(6) Return to Main Menu\n" << std::endl;
    break;

    case INV_OPTION:
        std::cout << "***********************************************************************************************************\n"
                  << "*                                               Inventory Page                                            *\n"
                  << "***********************************************************************************************************\n"
                  << "(1) Keyword\n"
                  << "(2) Category\n"
                  << "(3) Brand\n"
                  << "(4) Inventory Number\n"
                  << "(5) Go Back\n" << std::endl;
    break;

    case ACCEPTABLE:
        std::cout << "***********************************************************************************************************\n"
                  << "*                                            Acceptable Items Page                                        *\n"
                  << "***********************************************************************************************************\n"
                  << "(1) Display Acceptable Items" 
                  << "(2) Add Acceptable Items"
                  << "(3) Remove Acceptable Items"
                  << "(4) Return to Main Menu" << std::endl;
    break;

    default;

 }

}

void Display_Inventory(DISPLAY_FILTER filter_In) {

}

void Manage_Inventory(void) {

}

void Change_User_Password(void) {

}

void Manage_Acc_Items(void) {

}

void Save_System(void){

}

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}



std::string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE = 127;
  const char RETURN = 10;

  std::string password;
  unsigned char ch = 0;

  std::cout << prompt;

  while((ch=getch())!=RETURN)
    {
       if(ch == BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 std::cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password += ch;
             if(show_asterisk)
                 std::cout <<'*';
         }
    }
  std::cout << std::endl;
  return password;
}


void Login_Handler(const std::string &file_name_In) {
 std::ifstream input_file;
 input_file.open(file_name_In);

 if(input_file.fail()) { 
 	std::cout << "Error with file: inventory_file\n" << std::endl; 
 	exit(1);
 }
	
 std::string user_name;
 std::string password;
	
 getline(file_name_In, user_name);
 if(!user_name.compare("end_username_password")) return; /*No login required. Else continue*/
 
 getline(file_name_In, password);
 std::string user_name_2;
 std::string password_2;
 while(1) {
 		user_name_2.clear();
 		password_2.clear();

 		std::cout << "Username: ";
 		getline(std::cin, user_name_2);
 		password_2 = getpass("Password: ", true);

 		if ((user_name_2.compare(user_name)) || (password_2.compare(password))) std::cout  << "Invalid user name or password" << std::endl;
 		else break;
 } 

 input_file.close();
 for (int i = 0; i < 10000; i++); /*Make sure file closes before returning*/

}

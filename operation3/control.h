typedef struct menu_char{
    //std::string cmd;
    char* cmd;
    int id;
} menu_char; 

int menu_num = 4;
int button_num(0);

menu_char main_menu_char[] = {
    "draw point", 1,
    "draw line", 2,
    "draw circle", 3,
    "quit", 4,
};

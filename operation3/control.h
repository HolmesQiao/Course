typedef struct menu_char{
    //std::string cmd;
    char* cmd;
    int id;
} menu_char; 

int menu_num(8);
int button_num(0);

menu_char main_menu_char[] = {
    "draw point", 1,
    "draw line/ polygon", 2,
    "draw circle", 3,
    "draw rectangle", 4,
    "draw oval", 5,
    "draw Bezier curve", 6, 
    "fill", 7,
    "quit", 8,
};

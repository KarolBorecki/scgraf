#ifndef _PRINTER_H_
#define _PRINTER_H_

#define WHITE      "\033[0m"
#define GREY       "\033[37m"
#define LIGHT_BLUE "\033[36m"
#define PINK       "\033[35m"
#define BLUE       "\033[34m"
#define RED        "\033[31m"
#define YELLOW     "\033[33m"
#define GREEN      "\033[32m"
#define BOLD       "\033[1m"


void set_font(char* font);

void print_greetings();
void print_help();

#endif /* _MENU_PRINTER_H_ */

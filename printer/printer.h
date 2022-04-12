#ifndef _PRINTER_H_
#define _PRINTER_H_

#define WHITE      "\033[0m"
#define GREY       "\033[0;37m"
#define LIGHT_BLUE "\033[0;36m"
#define PINK       "\033[0;35m"
#define BLUE       "\033[0;34m"
#define RED        "\033[0;31m"
#define YELLOW     "\033[0;33m"
#define GREEN      "\033[0;32m"
#define BOLD       "\033[1m"


void set_font(char* font);

void print_greetings();
void print_help();

#endif /* _MENU_PRINTER_H_ */

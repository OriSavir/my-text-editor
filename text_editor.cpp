#include "text_editor.h"

using namespace std;

void open_curses() {
    initscr();
    noecho();
    refresh();
}

void get_file_name(int argc, char *argv[]) {
    
}
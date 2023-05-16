#include "text_editor.h"

void open_curses() {
    initscr();
    noecho();
    refresh();
    noecho();
}
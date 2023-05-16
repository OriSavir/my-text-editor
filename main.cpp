#include <iostream>
#include "text_editor.h"

using namespace std;

int main(int argc, char* argv[]) {


    open_curses();

    refresh();
    endwin();
    return 0;
}
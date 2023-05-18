#include <iostream>
#include <string>
#include <stdexcept>
#include <ncurses.h>
#include "text_editor.h"
#include "mem_buffer.h"

using namespace std;

void open_curses() {
    initscr();
    noecho();
    refresh();
}

int main(int argc, char* argv[]) {
    open_curses();

    Editor editor;
    if (argc > 1) {
        try {
            editor = Editor(argv[1]);
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    else {
        editor = Editor();
    }

    try {
        while (editor.getMode() != 'x') {
            editor.printBuffer();
            int input = getch();
            editor.readInput(input);
        }
    } catch (const std::exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    refresh();
    endwin();
    return 0;
}
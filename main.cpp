#include <iostream>
#include <string>
#include <stdexcept>
#include "text_editor.h"

using namespace std;

void open_curses() {
    initscr();
    noecho();
    refresh();
}

string get_file_name(int argc, char *argv[]) {
    if (argc <= 1) {
        throw std::invalid_argument("Please enter a filename to be opened in the editor");
    }
    string s = argv[0];
    return s;
}

int main(int argc, char* argv[]) {
    open_curses();

    string name = get_file_name(argc, argv);

    refresh();
    endwin();
    return 0;
}
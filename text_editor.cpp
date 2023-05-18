#include "text_editor.h"
#include <ncurses.h>
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;

Editor::Editor(): x(0), y(0), mode('n'), filename("undefined"), buff(new Buffer()), startLine(0) {}

Editor::Editor(string filename): x(0), y(0), mode('n'), filename(filename), buff(new Buffer()), startLine(0) {
    ifstream file(filename);
    string line;
    if (!file.is_open()) {
        throw std::invalid_argument("File does not exist");
    }
    while (getline(file, line)) {
        buff->appendLine(line);
    }
}


Editor::~Editor() {
    delete buff;
}

Editor::Editor(const Editor &o): x(o.x), y(o.y), mode(o.mode), filename(o.filename) {
    buff = new Buffer();
    for (int i = 0; i < o.buff->lines.size(); i++) {
        buff->appendLine(o.buff->lines[i]);
    }
}

void Editor::moveDown() {
    if (y < buff->lines.size() - 1) {
        y++;
    }
    if (x > buff->lines[y].size() - 1) {
        x = buff->lines[y].size() - 1;
    }
    move(y, x);
}

void Editor::moveUp() {
    if (y > 0) {
        y--;
    }
    if (x > buff->lines[y].size() - 1) {
        x = buff->lines[y].size() - 1;
    }
    move(y, x);
}

void Editor::moveLeft() {
    if (x > 0) {
        x--;
    }
    move (y, x);
}

void Editor::moveRight() {
    if (x < buff->lines[y].size() - 1) {
        x++;
    }
    move(y, x);
}

void Editor::deleteLine(int y) {
    if (y >= buff->lines.size()) {
        throw std::invalid_argument("Line does not exist");
    }
    buff->removeLine(y);
}

void Editor::readInput(char input) {
    switch(input) {
        case KEY_DOWN:
            moveDown();
            return;
        case KEY_UP:
            moveUp();
            return;
        case KEY_LEFT:
            moveLeft();
            return;
        case KEY_RIGHT:
            moveRight();
            return;
    }

    switch (mode) {
        case 'n':
            switch (input) {
                case 'x':
                    mode = 'x';
                    break;
                case 'i':
                    mode = 'i';
                    break;
                case 's':
                    saveFile();
                    break;
                default:
                    throw std::invalid_argument("Invalid command mode input");
            }
        case 'i':
            handle_i_mode(input);
            break;
    }
}

void Editor::handle_i_mode(char input) {
    switch (input) {
        case KEY_BACKSPACE:
            if (x > 0) {
                x--;
                buff->lines[y].erase(x, 1);
            }
            else if (x == 0 && y > 0) {
                x = buff->lines[y-1].length();
                buff->lines[y-1] += buff->lines[y];
                deleteLine(y);
            }
            break;
        case KEY_DC:
            if (x < buff->lines[y].length()) {
                buff->lines[y].erase(x, 1);
            }
            else if (x == buff->lines[y].length() && y != buff->lines.size() - 1) {
                buff->lines[y] += buff->lines[y+1];
                deleteLine(y+1);
            }
            break;
        case KEY_ENTER:
        case 10:
            if (x < buff->lines[y].length()) {
                string new_line = buff->lines[y].substr(x, buff->lines[y].length() - x);
                buff->insertLine(new_line, y+1);
                buff->lines[y].erase(x, buff->lines[y].length() - x);
            }
            else {
                buff->insertLine("", y+1);
            }
            x = 0;
            moveDown();
            break;
        case KEY_BTAB:
        case KEY_CTAB:
        case KEY_STAB:
        case KEY_CATAB:
        case 9:
            buff->lines[y].insert(x, 4, ' ');
            x += 4;
            break;
        default:
            buff->lines[y].insert(x, 1, input);
            x++;
            break;
    }
}

void Editor::saveFile() {
    ofstream file(filename, ofstream::trunc);
    for (int i = 0; i < buff->lines.size(); i++) {
        file << buff->lines[i] << endl;
    }
    file.close();
}

void Editor::printBuffer() {
    int windowHeight, windowWidth;
    getmaxyx(stdscr, windowHeight, windowWidth);

}
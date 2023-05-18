#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <string>

#include "mem_buffer.h"

class Editor {
    public:
        Editor();
        Editor(std::string filename);
        ~Editor();
        Editor(const Editor &o);

        char getMode() { return mode; }

        void readInput(char input);

        void printBuffer();

    private:
        int startLine;
        int x, y;
        char mode;
        Buffer *buff;
        std::string filename;

        void moveDown();
        void moveUp();
        void moveLeft();
        void moveRight();
        
        void deleteLine();
        void deleteLine(int);

        void saveFile();

        void handle_i_mode(char input);
};

#endif
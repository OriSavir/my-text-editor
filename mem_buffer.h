#ifndef MEM_BUFFER_H
#define MEM_BUFFER_H

#include <string>
#include <vector>


class Buffer {
    public:
        Buffer();

        std::vector<std::string> lines;
        std::string filename;

        void insertLine(std::string new_line, int line_num);
        void appendLine(std::string new_line);
        void removeLine(int line_num);

        std::string tabToSpace(std::string line);
    private:
};

#endif
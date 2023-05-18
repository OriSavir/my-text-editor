#include "mem_buffer.h"

using namespace std;

string Buffer::tabToSpace(string line) {
    int t_ind = line.find("\t");
    if (t_ind == line.npos) {
        return line;
    }
    return tabToSpace(line.replace(t_ind, 1, "    "));
}

void Buffer::insertLine(string new_line, int line_num) {
    new_line = tabToSpace(new_line);
    lines.insert(lines.begin() + line_num, new_line);
}

void Buffer::appendLine(string new_line) {
    new_line = tabToSpace(new_line);
    lines.push_back(new_line);
}

void Buffer::removeLine(int line_num) {
    lines.erase(lines.begin() + line_num);
}
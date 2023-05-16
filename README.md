# my-text-editor
Making my own text editor! Using C++, with libraries imported.


ncurses tutorial:

To compile we must link the libncurses while compilation.
$ g++ <program file> -lncurses -o <output file name>

initscr()
initializes screen
sets up memory and clean the screen
refresh()
refreshes the screen to match what's in the memory on the screen
endwin()
deallocates memory and ends ncurses
getch()
waits for user input
returns the ASCII value of that key


#include <ncurses.h>

int main() {
    initscr();
    clear();
    mvprintw(LINES/2, COLS/2 - 5, "welcome to smth idk");
    refresh();
    getch();
    endwin();
    return 0;
}
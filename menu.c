#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int setup() {
    initscr();
    start_color();
    
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    init_color(8, 700, 700, 700);
    init_pair(2, COLOR_BLACK, 8);
    clear();

    int height = LINES * 0.75;
    int width = COLS * 0.75;
    int starty = (LINES - height) / 2;
    int startx = (COLS - width) / 2;
    attron(COLOR_PAIR(2));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mvaddch(starty + y, startx + x, ' ');
        }
    }

    mvprintw(LINES/2, COLS/2 - strlen("welcome to arm64-asm-test")/2, "welcome to arm64-asm-test");
    mvprintw(LINES/2+1, COLS/2 - strlen("<press any key to continue>")/2, "<press any key to continue>");
    refresh();
    getch();

    clear();

    height = LINES * 0.75;
    width = COLS * 0.75;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mvaddch(starty + y, startx + x, ' ');
        }
    }

    const char *options[] = {
        "lightweight version (no built-in stuff)",
        "normal version"
    };
    int option_count = 2;
    int selected = 0;

    keypad(stdscr, TRUE);
    int ch;
    while (1) {
        // redraw menu inside gray box
        for (int i = 0; i < option_count; i++) {
            if (i == selected) {
                attron(A_REVERSE); // highlight
            }
            mvprintw(LINES/2 + 1 + i, COLS/2, "%s", options[i]);
            attroff(A_REVERSE);
        }
        mvprintw(LINES/2, COLS/2 - strlen("what do you want installed?")/2, "what do you want installed?");

        refresh();
        ch = getch();

        if (ch == KEY_UP) {
            selected = (selected - 1 + option_count) % option_count;
        } else if (ch == KEY_DOWN) {
            selected = (selected + 1) % option_count;
        } else if (ch == '\n') {
            break; // user selected something
        }
    }
    refresh();

    clear();

    height = LINES * 0.75;
    width = COLS * 0.75;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mvaddch(starty + y, startx + x, ' ');
        }
    }
    mvprintw(LINES/2, COLS/2 - strlen("please wait...")/2, "please wait...");
    refresh();
    sleep(1);
    endwin();

    chmod("extract.sh", 0755); // basically just chmod +x extract.sh
    int result = system("./extract.sh");


    initscr();
    start_color();
    
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    init_color(8, 700, 700, 700);
    init_pair(2, COLOR_BLACK, 8);
    clear();

    height = LINES * 0.75;
    width = COLS * 0.75;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    attron(COLOR_PAIR(2));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mvaddch(starty + y, startx + x, ' ');
        }
    }

    if (result == -1) {
        mvprintw(LINES/2, COLS/2 - strlen("system() failed to fork/execute.")/2, "system() failed to fork/execute.");
        getch();
        endwin();
        return 1;
    } else {
        mvprintw(LINES/2, COLS/2 - strlen("Success!")/2, "Success!");
    }
    refresh();
    getch();

    clear();
    chmod("compress/compile.sh", 0755);
    endwin();
    int resultt = system("cd compress && ./compile.sh");
    return 0;
}
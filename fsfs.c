

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#else
#include <unistd.h>
#endif

#define W 80
#define H 24
const char *C_RED = "\033[1;31m";
const char *C_GREEN = "\033[1;32m";
const char *C_YELLOW = "\033[1;33m";
const char *C_BLUE = "\033[1;34m";
const char *C_MAG = "\033[1;35m";
const char *C_CYAN = "\033[1;36m";
const char *C_WHITE = "\033[1;37m";
const char *C_RESET = "\033[0m";

void clear_screen()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}
void move_cursor(int r, int c)
{
    printf("\033[%d;%dH", r, c);
    fflush(stdout);
}
void hide_cursor()
{
    printf("\033[?25l");
    fflush(stdout);
}
void show_cursor()
{
    printf("\033[?25h");
    fflush(stdout);
}
void print_center(int r, const char *color, const char *text)
{
    int len = (int)strlen(text);
    int col = (W - len) / 2 + 1;
    move_cursor(r, col);
    if (color)
        printf("%s%s%s", color, text, C_RESET);
    else
        printf("%s", text);
    fflush(stdout);
}

void type_write_center(int row, const char *color, const char *s, int delay_us)
{
    int len = (int)strlen(s);
    int col = (W - len) / 2 + 1;
    move_cursor(row, col);
    if (color)
        printf("%s", color);
    for (int i = 0; i < len; ++i)
    {
        putchar(s[i]);
        fflush(stdout);
        usleep(delay_us);
    }
    if (color)
        printf("%s", C_RESET);
    fflush(stdout);
}

void big_banner()
{
    const char *lines[] = {
        "  ____   __   _  _  ____  ____  _  _  ____ ",
        " (  _ \\ /__\\ ( \\/ )(  _ \\(  _ \\( \\/ )(  _ \\",
        "  )   //(__)\\\\ \\/ / )   / )   / )  /  )   /",
        " (_)\\_)(__)(__)(__) (_)\\_)(_)\\_)(__)  (_)\\_\\"};
    for (int i = 0; i < 4; ++i)
    {
        print_center(1 + i, C_MAG, lines[i]);
        usleep(30000);
    }
    print_center(6, C_CYAN, "    A Special Surprise - Just For Ayushi!");
}

void confetti_and_hearts(int rounds)
{
    for (int r = 0; r < rounds; ++r)
    {
        for (int i = 0; i < 140; ++i)
        {
            int rr = 1 + rand() % (H - 8);
            int cc = 1 + rand() % (W - 2);
            const char *col;
            switch (rand() % 6)
            {
            case 0:
                col = C_RED;
                break;
            case 1:
                col = C_GREEN;
                break;
            case 2:
                col = C_YELLOW;
                break;
            case 3:
                col = C_BLUE;
                break;
            case 4:
                col = C_MAG;
                break;
            default:
                col = C_CYAN;
                break;
            }
            move_cursor(rr, cc);
            if (rand() % 14 == 0)
                printf("%s<3%s", col, C_RESET);
            else
                printf("%s.%s", col, C_RESET);
        }
        fflush(stdout);
        usleep(140000);

        for (int i = 0; i < 40; ++i)
        {
            int rr = (H - 10) + rand() % 6;
            int cc = 1 + rand() % W;
            move_cursor(rr, cc);
            printf(" ");
        }
    }
}

void draw_cake_with_name(int top_row, const char *name)
{
    const char *cake[] = {
        "           ,:;:;:;:;:;,",
        "         ,;:;:;:;:;:;:;:;,",
        "        |:;:;:;:;:;:;:;:;|",
        "        |                 |",
        "        |     ( ) ( )     |",
        "       ---------------------",
        "      |   Happy Birthday   |",
        "      |                   |",
        "      ---------------------"};
    int lines = sizeof(cake) / sizeof(cake[0]);
    int startc = (W - 27) / 2 + 1;
    for (int i = 0; i < lines; ++i)
    {
        move_cursor(top_row + i, startc);
        printf("%s", cake[i]);
    }

    char nameLine[64];
    snprintf(nameLine, sizeof(nameLine), "      |    For: %-11s |", name);
    move_cursor(top_row + 6, startc);
    printf("%s", nameLine);
    fflush(stdout);
}

void candle_flicker(int top_row, int center_col, int repeats)
{
    for (int t = 0; t < repeats; ++t)
    {

        const char *flame = (rand() % 2)
                                ? "\033[1;33m▲\033[0m"
                                : "\033[1;31m▲\033[0m";
        move_cursor(top_row, center_col);
        printf("%s", flame);
        fflush(stdout);
        usleep(140000);
        move_cursor(top_row, center_col);
        printf(" ");
        fflush(stdout);
        usleep(90000);
    }
}

void fireworks(int cycles)
{
    const double PI = 3.141592653589793;
    for (int c = 0; c < cycles; ++c)
    {
        int cr = 3 + rand() % (H / 3);
        int cc = 8 + rand() % (W - 16);
        const char *col;
        switch (rand() % 6)
        {
        case 0:
            col = C_RED;
            break;
        case 1:
            col = C_GREEN;
            break;
        case 2:
            col = C_YELLOW;
            break;
        case 3:
            col = C_BLUE;
            break;
        case 4:
            col = C_MAG;
            break;
        default:
            col = C_CYAN;
            break;
        }
        int pieces = 20;
        int radius = 1 + rand() % 6;
        for (int p = 0; p < pieces; ++p)
        {
            double ang = 2.0 * PI * p / (double)pieces;
            int r = cr + (int)(radius * sin(ang));
            int cpos = cc + (int)(radius * cos(ang));
            if (r >= 1 && r <= H && cpos >= 1 && cpos <= W)
            {
                move_cursor(r, cpos);
                printf("%s*\033[0m", col);
            }
        }
        fflush(stdout);
        usleep(220000);

        for (int p = 0; p < 60; ++p)
        {
            int r = 1 + rand() % (H - 2);
            int cpos = 1 + rand() % (W - 2);
            move_cursor(r, cpos);
            printf(" ");
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    clear_screen();
    hide_cursor();

    const char *name = "Ayushi";

    big_banner();
    usleep(600000);

    print_center(8, C_CYAN, "Get ready... confetti & hearts incoming!");
    usleep(400000);

    confetti_and_hearts(7);

    clear_screen();
    big_banner();
    print_center(8, C_YELLOW, "Balloons & candles for you!");
    fflush(stdout);
    usleep(400000);

    for (int f = 0; f < 7; ++f)
    {
        int col = 6 + (f * 9);
        int row = H - 8 - f;
        for (int r = row; r > 2; r -= 2)
        {
            move_cursor(r, col);
            const char *colc = (rand() % 2) ? C_RED : C_MAG;
            printf("%s<3%s", colc, C_RESET);
            fflush(stdout);
            usleep(70000);
            move_cursor(r, col);
            printf("  ");
        }
    }

    int cake_top = H - 10;
    draw_cake_with_name(cake_top, name);

    int candle_r = cake_top - 1;
    int candle_c = W / 2;
    candle_flicker(candle_r, candle_c, 18);

    clear_screen();
    big_banner();
    type_write_center(8, C_MAG, "Happy Birthday, Ayushi!", 40000);
    usleep(300000);
    type_write_center(10, C_CYAN, "May your days be bright and your smiles endless.", 30000);
    usleep(400000);
    print_center(13, C_YELLOW, "Press Enter to launch fireworks!");
    show_cursor();
    move_cursor(H, 1);
    getchar();

    clear_screen();
    fireworks(6);

    clear_screen();
    print_center(6, C_GREEN, "========================================");
    print_center(7, C_YELLOW, "   H A P P Y   B I R T H D A Y   ");
    print_center(9, C_CYAN, "           Ayushi - you light up the world!           ");
    print_center(12, C_MAG, "     Wishing you love, laughter and amazing adventures!     ");
    print_center(15, C_WHITE, "                 Press Enter to exit.                 ");
    move_cursor(H, 1);
    getchar();

    clear_screen();
    show_cursor();
    printf(C_RESET);
    return 0;
}

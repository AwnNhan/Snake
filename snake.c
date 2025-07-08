// snake.c
#include <stdio.h>
#include <windows.h>   // để dùng hàm gotoxy
#include <conio.h>     // để dùng getch()
#include "snake.h"

// Biến toàn cục lưu vị trí rắn
int x = 10, y = 10;

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void snake_init() {
    gotoxy(x, y);
    printf("O");  // in rắn ban đầu
}

void draw_snake() {
    SetColorAdjustment(2);
    gotoxy(x, y);
    printf("O");  // đầu rắn
}

void snake_move() {
    char c = getch();  // đọc phím bấm

    // Xóa rắn ở vị trí cũ
    gotoxy(x, y);
    printf(" ");

    // Cập nhật vị trí theo phím
    if (c == 'w') y--;       // lên
    else if (c == 's') y++;  // xuống
    else if (c == 'a') x--;  // trái
    else if (c == 'd') x++;  // phải

    // Vẽ rắn ở vị trí mới
    draw_snake();

    if (x <= 0 || x >= 79 || y <= 0 || y >= 24) {
    gotoxy(35, 12);
    printf("GAME OVER!");
    Sleep(2000);
    exit(0); // kết thúc game
}

}

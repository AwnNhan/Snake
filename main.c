// main.c
#include <stdio.h>
#include <conio.h>     // để dùng getch() và kbhit()
#include <windows.h>   // để dùng Sleep()
#include "snake.h"     // khai báo hàm snake đã viết

int main() {
    system("cls");     // xóa màn hình console

    snake_init();      // khởi tạo rắn ban đầu

    while (1) {        // vòng lặp chạy hoài (game loop)
        if (kbhit()) {         // nếu có người chơi nhấn phím
            snake_move();      // di chuyển rắn
        }

        Sleep(100);    // nghỉ 100 mili giây để game mượt hơn
    }

    return 0;
}

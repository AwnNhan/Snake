#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "snake.h"
extern int x, y;        // đầu rắn (cập nhật trong snake_move)
int  score   = 0;
int  length  = 1;       // đầu tiên rắn dài 1 laf dau ran

#define MAX_LEN 500      // độ dài tối cua ran
int bodyX[MAX_LEN], bodyY[MAX_LEN];
int bodyLen = 0;  // số khúc thân đang tồn tại

int foodX, foodY;   // toạ độ thức ăn

// ham lay toa do xy
void gotoxy(int xpos, int ypos)
{
    COORD coord = { xpos, ypos };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void generateFood(void)
{
    foodX = rand() % 60+10;
    foodY = rand() % 15+5;
    gotoxy(foodX, foodY);     putchar('o');
}

static void growSnake(void) { ++length; }

//Kiểm tra va chạm với thức ăn
void checkFoodCollision(int headX, int headY)
{
    if (headX == foodX && headY == foodY) {
        ++score;
        generateFood();
        growSnake();          // tăng chiều dài logic
    }
}

static void displayScore(void)
{
    gotoxy(0, 0);
    printf("Score: %d", score);
}

void food_score(int snakeHeadX, int snakeHeadY)
{
    static int first = 1;
    static int prevHeadX, prevHeadY;   // lưu đầu ở khung hình trước

    // Khởi tạo lần đầu
    if (first) {
        srand((unsigned)time(NULL));
        generateFood();
        prevHeadX = snakeHeadX;
        prevHeadY = snakeHeadY;
        first = 0;
    }

    //Xử lý ăn thức ăn (có thể làm length++)
    checkFoodCollision(snakeHeadX, snakeHeadY);

    //Thêm vị trí đầu CŨ thành một khúc thân mới
    if (bodyLen < MAX_LEN) {
        bodyX[bodyLen] = prevHeadX;
        bodyY[bodyLen] = prevHeadY;
        ++bodyLen;
    }

    // Nếu thân dài hơn (length‑1) thì xoá đuôi để giữ đúng chiều dài
    if (bodyLen > length - 1) {
        int tailIndex = 0;                        // phần tử đầu mảng là đuôi
        gotoxy(bodyX[tailIndex], bodyY[tailIndex]);
        putchar(' ');
        // Dồn mảng sang trái một ô (đơn giản, O(n) nhưng đủ dùng)
        for (int i = 1; i < bodyLen; ++i) {
            bodyX[i-1] = bodyX[i];
            bodyY[i-1] = bodyY[i];
        }
        --bodyLen;
    }

    //Vẽ tất cả khúc thân hiện có
    for (int i = 0; i < bodyLen; ++i) {
        gotoxy(bodyX[i], bodyY[i]);
        putchar('#');
    }

    //Lưu lại đầu hiện tại cho khung hình sau
    prevHeadX = snakeHeadX;
    prevHeadY = snakeHeadY;

    //Hiển thị điểm
    displayScore();
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "snake.h"

extern int x, y;
int score = 0;
int length = 1;

#define MAX_LEN 500
int bodyX[MAX_LEN], bodyY[MAX_LEN];
int bodyLen = 0;
int foodX, foodY;

void generateFood() {
    foodX = rand() % 60 + 10;
    foodY = rand() % 15 + 5;
    gotoxy(foodX, foodY);
    putchar('o');
}

void growSnake() { length++; }

void checkFoodCollision(int headX, int headY) {
    if (headX == foodX && headY == foodY) {
        score++;
        generateFood();
        growSnake();
    }
}

void displayScore() {
    gotoxy(0, 0);
    printf("Score: %d", score);
}

void food_score(int headX, int headY) {
    static int first = 1;
    static int prevX, prevY;

    if (first) {
        srand(time(NULL));
        generateFood();
        prevX = headX;
        prevY = headY;
        first = 0;
    }

    checkFoodCollision(headX, headY);

    // Thêm khúc thân tại vị trí đầu cũ
    if (bodyLen < MAX_LEN) {
        bodyX[bodyLen] = prevX;
        bodyY[bodyLen] = prevY;
        bodyLen++;
    }

    // Xoá đuôi nếu quá dài
    if (bodyLen > length - 1) {
        gotoxy(bodyX[0], bodyY[0]);
        putchar(' ');
        for (int i = 1; i < bodyLen; i++) {
            bodyX[i - 1] = bodyX[i];
            bodyY[i - 1] = bodyY[i];
        }
        bodyLen--;
    }

    // Vẽ thân rắn
    for (int i = 0; i < bodyLen; i++) {
        gotoxy(bodyX[i], bodyY[i]);
        putchar('#');
    }

    prevX = headX;
    prevY = headY;

    displayScore();
}

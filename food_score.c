#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int foodX, foodY;
int score = 0;
int length = 1;

// Sử dụng x, y từ snake.c
extern int x, y;

void gotoxy(int xpos, int ypos) {
    COORD coord;
    coord.X = xpos;
    coord.Y = ypos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void generateFood() {
    foodX = rand() % 50;
    foodY = rand() % 25;
    gotoxy(foodX, foodY);
    printf("o");
}

void growSnake() {
    length++;
    gotoxy(x, y);
    printf("0");// In lại đầu rắn sau khi ăn
}

void checkFoodCollision(int snakeHeadX, int snakeHeadY) {
    if (snakeHeadX == foodX && snakeHeadY == foodY) {
        score++;
        generateFood();
        growSnake();
    }
}

void displayScore() {
    gotoxy(0, 0);
    printf("Score: %d", score);
}

void food_score(int snakeHeadX, int snakeHeadY) {
    // Khởi tạo thức ăn nếu lần đầu
    static int first = 1;
    if (first) {
        srand(time(NULL));
        generateFood();
        first = 0;
    }
    checkFoodCollision(snakeHeadX, snakeHeadY);
    displayScore();
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

    int foodX, foodY;
    int score = 0;
    int length = 1;
    int x = 1, y = 1;
void gotoxy(int xpos, int ypos) {
    COORD coord;
    coord.X = xpos;
    coord.Y = ypos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Tạo thức ăn mới tại vị trí ngẫu nhiên
void generateFood() {
    foodX = rand() % 50;
    foodY = rand() % 25;
    gotoxy(foodX, foodY);
    printf("o");
}

// Khi rắn ăn mồi thì tăng chiều dài
void growSnake() {
    length++;
    gotoxy(x, y);
    printf("#");
}

// Kiểm tra va chạm thức ăn
void checkFoodCollision(int snakeHeadX, int snakeHeadY) {
    if (snakeHeadX == foodX && snakeHeadY == foodY) {
        score++;
        generateFood();
        growSnake();
    }
}

// Hiển thị điểm số
void displayScore() {
    gotoxy(0, 0);
    printf("Score: %d", score);
}


void food_score(int snakeHeadX, int snakeHeadY) {
    checkFoodCollision(snakeHeadX, snakeHeadY);
    displayScore();
}


int main() {
    srand(time(NULL));
    generateFood();
    displayScore();

    food_score(x, y);

    getchar();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
    int foodX, foodY;          // Tọa độ thức ăn
    int score = 0;             // Điểm số ban đầu

    int maxWidth = 50;         // Chiều rộng khung chơi
    int maxHeight = 25;        // Chiều cao khung chơi
    return 0;
    
    void generateFood() {
    foodX = rand() % 79;
    foodY = rand() % 24;
    gotoxy(foodX, foodY);
    printf("o");  // Ký hiệu thức ăn
}
    void growSnake() {
    length++;
    gotoxy(x, y); // vẽ tại đầu mới
    printf("#");
}
    void checkFoodCollision() {
    if (x == foodX && y == foodY) {
        score = score + 1;
        generateFood();  // Tạo mồi mới
        growSnake();     // Rắn dài lên
    }
}
    void displayScore() {
        gotoxy(0, 0);
        printf("Score: %d", score);
    }
    void food_score(int snakeHeadX, int snakeHeadY) {
    checkFoodCollision(snakeHeadX, snakeHeadY);
    displayScore();
}

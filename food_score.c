#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int foodX, foodY;          // Tọa độ thức ăn
    int score = 0;             // Điểm số ban đầu

    int maxWidth = 50;         // Chiều rộng khung chơi
    int maxHeight = 25;        // Chiều cao khung chơi
    return 0;
    void generateFood() {
    foodX = rand() % maxWidth;
    foodY = rand() % maxHeight;

    void growSnake() {
    if (length < MAX_LENGTH) {
        length++;  // Tăng độ dài rắn lên 1
    }
}   void checkFoodCollision(int snakeHeadX, int snakeHeadY) {
    if (snakeHeadX == foodX && snakeHeadY == foodY) {
        score += 10;          // Tăng điểm
        generateFood();       // Tạo thức ăn mới
        growSnake();          // Gọi hàm làm rắn dài thêm
    }
}
    void displayScore() {
        gotoxy(0, 0); 
        printf("Score: %d", score);
    }
}
    void food_score(int snakeHeadX, int snakeHeadY) {
    checkFoodCollision(snakeHeadX, snakeHeadY);
    displayScore();
}
return0;
}
#include <iostream>
#include <conio.h> // For non-blocking input (getch())
#include <windows.h> // For Sleep()

using namespace std;

const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 20;

class SnakeGame {
private:
    int snakeX;
    int snakeY;
    int fruitX;
    int fruitY;
    int score;
    bool gameOver;
    enum Direction { STOP, LEFT, RIGHT, UP, DOWN };
    Direction snakeDir;

public:
    SnakeGame() {
        snakeX = BOARD_WIDTH / 2;
        snakeY = BOARD_HEIGHT / 2;
        fruitX = rand() % BOARD_WIDTH;
        fruitY = rand() % BOARD_HEIGHT;
        score = 0;
        gameOver = false;
        snakeDir = STOP;
    }

    void startGame() {
        hideCursor();
        while (!gameOver) {
            drawBoard();
            processInput();
            moveSnake();
            checkCollision();
            Sleep(100); // Delay for smoother movement
        }
        cout << "Game Over! Score: " << score << endl;
    }

private:
    void drawBoard() {
        system("cls"); // Clear the console
        // Draw the game board with snake and fruit
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                if (x == snakeX && y == snakeY)
                    cout << "O"; // Snake's head
                else if (x == fruitX && y == fruitY)
                    cout << "*"; // Fruit
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
        cout << "Use arrow keys to control the snake." << endl;
    }

    void processInput() {
        // Check for non-blocking input and update snake's direction accordingly
        if (_kbhit()) {
            switch (_getch()) {
                case 'a':
                    snakeDir = LEFT;
                    break;
                case 'd':
                    snakeDir = RIGHT;
                    break;
                case 'w':
                    snakeDir = UP;
                    break;
                case 's':
                    snakeDir = DOWN;
                    break;
                case 'x':
                    gameOver = true;
                    break;
            }
        }
    }

    void moveSnake() {
        // Update snake's position based on the current direction
        switch (snakeDir) {
            case LEFT:
                snakeX--;
                break;
            case RIGHT:
                snakeX++;
                break;
            case UP:
                snakeY--;
                break;
            case DOWN:
                snakeY++;
                break;
        }
    }

    void checkCollision() {
        // Check for collision with the fruit and update the score
        if (snakeX == fruitX && snakeY == fruitY) {
            score++;
            fruitX = rand() % BOARD_WIDTH;
            fruitY = rand() % BOARD_HEIGHT;
        }
    }

    void hideCursor() {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(handle, &cursorInfo);
        cursorInfo.bVisible = false; // Hide the cursor
        SetConsoleCursorInfo(handle, &cursorInfo);
    }
};

int main() {
    SnakeGame game;
game.startGame();

return 0;
}
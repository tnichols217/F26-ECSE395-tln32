#include "constants.hpp"
#include <Arduino.h>

// Direction Enumeration
enum Direction { UP, DOWN, LEFT, RIGHT };

// Segment Coordinate Structure
typedef struct {
  int8_t x;
  int8_t y;
} Point;

typedef struct {
  Point snake[MAX_SNAKE_LENGTH];
  uint8_t snakeLength = 3;
  Direction dir = RIGHT;
  Point food;
  bool gameOver = false;
  uint16_t score = 0;
} GameState;

void spawnFood(GameState *gs);
void resetGame(GameState *gs);
void moveSnake(GameState *gs);
void checkCollision(GameState *gs);

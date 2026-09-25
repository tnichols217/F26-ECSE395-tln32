#include "game.hpp"
#include "constants.hpp"

// Spawn food at a random grid location aligned with SNAKE_SIZE
void spawnFood(GameState *gs) {
  gs->food.x = (random(0, SCREEN_W / SNAKE_SIZE)) * SNAKE_SIZE;
  gs->food.y = (random(0, SCREEN_H / SNAKE_SIZE)) * SNAKE_SIZE;
}

// Reset game state
void resetGame(GameState *gs) {
  gs->snakeLength = 3;
  gs->dir = RIGHT;
  gs->score = 0;
  gs->gameOver = false;

  // Center snake initial position
  int8_t startX = (SCREEN_W / (2 * SNAKE_SIZE)) * SNAKE_SIZE;
  int8_t startY = (SCREEN_H / (2 * SNAKE_SIZE)) * SNAKE_SIZE;

  for (uint8_t i = 0; i < gs->snakeLength; i++) {
    gs->snake[i].x = startX - (i * SNAKE_SIZE);
    gs->snake[i].y = startY;
  }

  spawnFood(gs);
}

void moveSnake(GameState *gs) {
  for (int i = gs->snakeLength - 1; i > 0; i--) {
    gs->snake[i] = gs->snake[i - 1];
  }
  switch (gs->dir) {
  case UP:
    gs->snake[0].y -= SNAKE_SIZE;
    break;
  case DOWN:
    gs->snake[0].y += SNAKE_SIZE;
    break;
  case LEFT:
    gs->snake[0].x -= SNAKE_SIZE;
    break;
  case RIGHT:
    gs->snake[0].x += SNAKE_SIZE;
    break;
  }
}

void checkCollision(GameState *gs) {
  // Walls
  if (gs->snake[0].x < 0 || gs->snake[0].x >= SCREEN_W || gs->snake[0].y < 0 ||
      gs->snake[0].y >= SCREEN_H) {
    gs->gameOver = true;
  }

  // Self
  for (uint8_t i = 1; i < gs->snakeLength; i++) {
    if (gs->snake[0].x == gs->snake[i].x && gs->snake[0].y == gs->snake[i].y) {
      gs->gameOver = true;
      break;
    }
  }

  // Food
  if (gs->snake[0].x == gs->food.x && gs->snake[0].y == gs->food.y) {
    if (gs->snakeLength < MAX_SNAKE_LENGTH) {
      gs->snakeLength++;
    }
    gs->score += 10;
    spawnFood(gs);
  }
}

#include "constants.hpp"
#include "game.hpp"
#include "input.hpp"
#include "screen.hpp"
#include <Arduino.h>

Adafruit_SSD1306 *display = nullptr;
GameState *gs = new GameState{};

void setup() {
  Serial.begin(BAUD);
  display = makeDisplay();
  if (display == nullptr) {
    Serial.println("SSD1306 allocation failed");
    while (true)
      ;
  }

  randomSeed(analogRead(0)); // Seed random generator
  resetGame(gs);
}

void loop() {
  // Process Input
  inputs in = get_input();

  // Prevent reversing directly onto oneself
  if (in.up && gs->dir != DOWN)
    gs->dir = UP;
  if (in.down && gs->dir != UP)
    gs->dir = DOWN;
  if (in.left && gs->dir != RIGHT)
    gs->dir = LEFT;
  if (in.right && gs->dir != LEFT)
    gs->dir = RIGHT;

  // Handle Game Over Reset
  if (gs->gameOver) {
    // Press any input direction to restart
    if (in.up || in.down || in.left || in.right) {
      resetGame(gs);
    }
    delay(DELAY_TIME);
    return;
  }

  moveSnake(gs);
  checkCollision(gs);

  // Render Frame
  display->clearDisplay();

  if (gs->gameOver) {
    display->setTextSize(2);
    display->setTextColor(SSD1306_WHITE);
    display->setCursor(10, 15);
    display->println("GAME OVER");

    display->setTextSize(1);
    display->setCursor(25, 40);
    display->print("Score: ");
    display->println(gs->score);

    display->setCursor(10, 52);
    display->println("Press key to retry");
  } else {
    // Draw Snake
    for (uint8_t i = 0; i < gs->snakeLength; i++) {
      display->fillRect(gs->snake[i].x, gs->snake[i].y, SNAKE_SIZE, SNAKE_SIZE,
                        SSD1306_WHITE);
    }

    // Draw Food
    display->drawRect(gs->food.x, gs->food.y, SNAKE_SIZE, SNAKE_SIZE,
                      SSD1306_WHITE);
  }

  display->display();

  // Frame Speed Control
  delay(DELAY_TIME);
}

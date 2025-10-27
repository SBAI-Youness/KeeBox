#include <iostream>

#include "../include/raylib.h"
#include "../include/config.h"

int main () {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "KeeBox");

  SetTargetFPS(60);

  while (WindowShouldClose() == false) {
    BeginDrawing();

    ClearBackground(RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}

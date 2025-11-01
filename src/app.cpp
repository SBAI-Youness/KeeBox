#include "app.h"

App::App()
    : window_width(DEFAULT_WINDOW_WIDTH), window_height(DEFAULT_WINDOW_HEIGHT), window_title(WINDOW_TITLE) {
  // Enable window resizing + vsync
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

  // Initialize the Raylib window with given width/height/title
  InitWindow(window_width, window_height, window_title.c_str());

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

  // Load a custom font
  font = LoadFont("fonts/Poppins-ExtraBold.ttf");
}

App::~App() {
  // Free memory used
  UnloadFont(font);

  // Destroy the window and cleanup the OpenGL context
  CloseWindow();
}

void App::run() {
  // Main loop - runs until window is closed
  while (WindowShouldClose() == false) {
		update();
		render();
	}
}

void App::update() {
  // Keep window dimensions updated for resize events
  window_width = GetScreenWidth();
  window_height = GetScreenHeight();
}

void App::render() {
	BeginDrawing();

  // Clear screen with a red background
	ClearBackground(RED);

  float fontSize = 50.0f;
  float fontSpacing = 2.0f;

  // Measure text
  Vector2 textSize = MeasureTextEx(font, WINDOW_TITLE, fontSize, fontSpacing);

  // Calculate center position
  Vector2 textPosition = {
      (window_width - textSize.x) / 2.0f,
      (window_height - textSize.y) / 2.0f
  };

  // Draw centered window title text in white
  DrawTextEx(font, WINDOW_TITLE, textPosition, fontSize, fontSpacing, RAYWHITE);

	EndDrawing();
}

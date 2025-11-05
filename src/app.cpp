#include "app.hpp"
#include "config.hpp"
#include "raylib.h"
#include "ui/font_manager.hpp"

App::App()
    : window_width(DEFAULT_WINDOW_WIDTH), window_height(DEFAULT_WINDOW_HEIGHT), window_title(WINDOW_TITLE) {
  // Enable window resizing + vsync
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

  // Initialize the Raylib window with given width/height/title
  InitWindow(window_width, window_height, window_title.c_str());

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("assets");
}

App::~App() {
  // Free memory used
  FontManager::unload();

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
	ClearBackground((Color) { 59, 59, 61, 255});

  // Pick font by key
  Font& title_font = FontManager::get("title");

  // Responsive size
  float font_size = window_width * 0.05f;
  float spacing = font_size * 0.05f;

  Vector2 text_size = MeasureTextEx(title_font, window_title.c_str(), font_size, spacing);

  DrawTextEx(title_font, window_title.c_str(), (Vector2) { (window_width - text_size.x) * .5f, (window_height - text_size.y) *.5f}, font_size, spacing, WHITE);

	EndDrawing();
}

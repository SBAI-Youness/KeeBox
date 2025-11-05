#pragma once

#include "raylib.h"
#include "resource_dir.h"
#include "config.hpp"

#include <string>

class App {
  private:
    int window_width;          // Current window width (updated on resize)
    int window_height;         // Current window height (updated on resize)
    std::string window_title;  // Window title text

    void update();             // Method used to update application state (e.g., window resize, logic)
    void render();             // Method used to handle all the drawing operations

  public:
    App();                     // Constructor — initializes the app (creates window, loads font, etc.)
    ~App();                    // Destructor — cleans up resources (unloads font, closes window)

    void run();                // Main loop — runs until the window is closed
};

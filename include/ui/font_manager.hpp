#pragma once

#include "raylib.h"

#include <map>
#include <string>
#include <stdexcept>

class FontManager {
  private:
    static inline std::map<std::string, Font> fonts;     // Loaded fonts
    static Font load_font_by_key(const std::string& key);  // Helper to load a font

  public:
    static Font& get(const std::string& key);           // Get font by key (lazy load)
    static void unload();                               // Unload all the fonts
};

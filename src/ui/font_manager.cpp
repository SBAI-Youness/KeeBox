#include "ui/font_manager.hpp"

Font FontManager::load_font_by_key(const std::string& key) {
  // Load font based on key
  if (key == "title") {
    Font f = LoadFontEx("fonts/Poppins-ExtraBold.ttf", 512, nullptr, 0);
    SetTextureFilter(f.texture, TEXTURE_FILTER_BILINEAR);
    return f;
  }
  else if (key == "subtitle") {
    Font f = LoadFontEx("fonts/Poppins-SemiBold.ttf", 256, nullptr, 0);
    SetTextureFilter(f.texture, TEXTURE_FILTER_BILINEAR);
    return f;
  }
  else if (key == "body") {
    Font f = LoadFontEx("fonts/Poppins-Regular.ttf", 256, nullptr, 0);
    SetTextureFilter(f.texture, TEXTURE_FILTER_BILINEAR);
    return f;
  }
  else if (key == "small") {
    Font f = LoadFontEx("fonts/Poppins-Regular.ttf", 128, nullptr, 0);
    SetTextureFilter(f.texture, TEXTURE_FILTER_BILINEAR);
    return f;
  }
  else {
    throw std::runtime_error("Font key not recognized: " + key);
  }
}

Font& FontManager::get(const std::string& key) {
  // If font already loaded, return it
  if (fonts.count(key)) {
    return fonts[key];
  }

  // Otherwise, load it, cache it, then return
  fonts[key] = load_font_by_key(key);
  return fonts[key]; // Return reference to the requested font
}

void FontManager::unload() {
  for (auto &f : fonts) {
    UnloadFont(f.second);
  }

  fonts.clear();
}

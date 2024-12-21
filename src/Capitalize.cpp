#include "../Headers/Capitalize.h"

std::string Capitalize::transform(std::string& text) const {
    text[0] = tolower(text[0]);
}
#include "../Headers/Capitalize.h"

std::string Capitalize::transform(const std::string& text) const {
    std::string result = text;
    if (result.length() > 0) {
        result[0] = toupper(result[0]);
    }
    return result;
}
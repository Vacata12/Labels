#include "../Headers/NormalizeSpace.h"

std::string NormalizeSpace::transform(std::string& text) const {
    std::string result;
    bool hasSpace = false;
    for (char c : text) {
        if (c == ' ') {
            if (!hasSpace) {
                result += c;
                hasSpace = true;
            }
        } else {
            result += c;
            hasSpace = false;
        }
    }
    return result;
}
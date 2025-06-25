#include "../../Headers/Transformations/NormalizeSpace.h"
#include <iostream>

std::string NormalizeSpace::transform(const std::string& text) const {
    std::string result;
    bool hasSpace = false;
    LeftTrim l;
    RightTrim r;
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
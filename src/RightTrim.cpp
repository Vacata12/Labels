#include "../Headers/RightTrim.h"

std::string RightTrim::transform(std::string& text) const {
    size_t i = text.length();
    while(text[i] == ' ') {
        --i;
    }
    return i == text.length() ? text : text.substr(0, i);
}
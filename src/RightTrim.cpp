#include "../Headers/RightTrim.h"

std::string RightTrim::transform(const std::string& text) const {
    size_t i = text.length() - 1;
    while(text[i] == ' ') {
        --i;
    }
    return i == text.length() ? text : text.substr(0, i + 1);
}
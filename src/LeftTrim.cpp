#include "../Headers/LeftTrim.h"

std::string LeftTrim::transform(std::string& text) const {
    size_t i = 0;
    while(text[i] == ' ') {
        ++i;
    }
    return i == 0 ? text : text.substr(i);
}
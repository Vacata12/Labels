#include "../Headers/Decorate.h"

std::string Decorate::transform(std::string& text) const {
    std::string start = "-={ ";
    std::string end = " }=-";
    std::string result = start + text + end;
    return result;
}
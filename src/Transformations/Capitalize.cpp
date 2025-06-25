#include "../../Headers/Transformations/Capitalize.h"

std::string Capitalize::transform(const std::string& text) const {
    std::string result = text;
    if (result.length() > 0) {
        size_t index = 0;
        while(true) {
            if(result[index] != ' ') {
                result[index] = toupper(result[index]);
                break;
            }
            index += 1;
        }
    }
    return result;
}
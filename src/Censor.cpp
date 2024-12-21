#include "../Headers/Censor.h"

Censor::Censor(const std::string& W) {
    this->W = W;
}

std::string Censor::transform(const std::string& text) const {
    std::string result;
    for(size_t i = 0, j = W.length(); j <= text.length() || i < text.length(); i++, j++) {
        if(text.substr(i, j - i) == W) {
            for(size_t i = 0; i < W.length(); i++) {
                result += '*';
            }
            i = j - 1;
            j += W.length();
        }
        else {
            result += text[i];
        }
    }
    return result;
}
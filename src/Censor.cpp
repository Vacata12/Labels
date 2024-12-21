#include "../Headers/Censor.h"
#include <iostream>

Censor::Censor(const std::string& W) {
    this->W = W;
}

std::string Censor::transform(const std::string& text) const {
    std::string result;
    for(size_t i = 0, j = W.length(); j <= text.length(); i++, j++) {
        std::cout << text.substr(i, j) << " == " << W << std::endl;
        std::cout << "i = " << i << std::endl << "j = " << j << std::endl;
        if(text.substr(i, j) == W) {
            for(size_t i = 0; i < W.length(); i++) {
                result += '*';
            }
            i = j;
            j += W.length();
        }
        else {
            result += text[i];
        }
    }
    std::cout << result << std::endl;
    return result;
}
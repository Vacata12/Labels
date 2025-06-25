#include "../../Headers/Transformations/Replace.h"

Replace::Replace(const std::string& A, const std::string& B) {
    this->A = A;
    this->B = B;
}

std::string Replace::transform(const std::string& text) const {
    std::string result;
    for(size_t i = 0, j = A.length(); j <= text.length() || i < text.length(); i++, j++) {
        if(text.substr(i, j - i) == A) {
            for(size_t i = 0; i < B.length(); i++) {
                result += B[i];
            }
            i = j - 1;
            j += B.length();
        }
        else {
            result += text[i];
        }
    }
    return result;
}
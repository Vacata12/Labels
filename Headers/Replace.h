#pragma once
#include "../Headers/TextTransformation.h"

class Replace : public TextTransformation {
    std::string A;
    std::string B;
public:
    Replace(const std::string& A, const std::string& B);
    std::string transform(std::string& text) const override;
};
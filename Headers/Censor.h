#pragma once
#include "../Headers/TextTransformation.h"

class Censor : public TextTransformation {
    std::string W;
public:
    Censor(const std::string& W);
    std::string transform(std::string& text) const override;
};
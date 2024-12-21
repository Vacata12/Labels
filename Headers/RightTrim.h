#pragma once
#include "../Headers/TextTransformation.h"

class RightTrim : public TextTransformation {
public:
    RightTrim();
    std::string transform(std::string& text) const override;
};
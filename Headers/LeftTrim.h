#pragma once
#include "../Headers/TextTransformation.h"

class LeftTrim : public TextTransformation {
public:
    LeftTrim();
    std::string transform(std::string& text) const override;
};
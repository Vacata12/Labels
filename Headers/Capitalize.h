#pragma once
#include "../Headers/TextTransformation.h"

class Capitalize : public TextTransformation {
public:
    Capitalize();
    std::string transform(std::string& text) const override;
};
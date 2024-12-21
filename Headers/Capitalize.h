#pragma once
#include "../Headers/TextTransformation.h"

class Capitalize : public TextTransformation {
public:
    Capitalize() = default;
    std::string transform(const std::string& text) const override;
};
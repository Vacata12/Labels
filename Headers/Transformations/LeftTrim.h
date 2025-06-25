#pragma once
#include "TextTransformation.h"

class LeftTrim : public TextTransformation {
public:
    LeftTrim() = default;
    std::string transform(const std::string& text) const override;
};
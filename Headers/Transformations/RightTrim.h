#pragma once
#include "TextTransformation.h"

class RightTrim : public TextTransformation {
public:
    RightTrim() = default;
    std::string transform(const std::string& text) const override;
};
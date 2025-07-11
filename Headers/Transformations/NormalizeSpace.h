#pragma once
#include "TextTransformation.h"
#include "LeftTrim.h"
#include "RightTrim.h"

class NormalizeSpace : public TextTransformation {
public:
    NormalizeSpace() = default;
    std::string transform(const std::string& text) const override;
};
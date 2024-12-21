#pragma once
#include "../Headers/TextTransformation.h"

class NormalizeSpace : public TextTransformation {
public:
    NormalizeSpace() = default;
    std::string transform(const std::string& text) const override;
};
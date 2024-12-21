#pragma once
#include "../Headers/TextTransformation.h"

class NormalizeSpace : public TextTransformation {
public:
    NormalizeSpace();
    std::string transform(std::string& text) const override;
};
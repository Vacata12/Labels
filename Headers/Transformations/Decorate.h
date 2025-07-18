#pragma once
#include "TextTransformation.h"

class Decorate : public TextTransformation {
public:
    Decorate() = default;
    std::string transform(const std::string& text) const override;
};
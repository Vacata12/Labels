#pragma once
#include "../Headers/TextTransformation.h"

class Decorate : public TextTransformation {
    Decorate();
    std::string transform(std::string& text) const override;
};
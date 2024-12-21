#pragma once
#include <string>

class TextTransformation {
public:
    TextTransformation() = default;
    virtual ~TextTransformation() = default;
    virtual std::string transform(const std::string& text) const = 0;
};
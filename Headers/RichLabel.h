#pragma once
#include "../Headers/SimpleLabel.h"
#include "LabelPrinter.h"

class RichLabel : public Label {
    std::string text;
    std::string color;
public:
    RichLabel(const std::string& text, const std::string& color);
    RichLabel(const std::string& text, const std::string& color, const std::string& helpText);
    ~RichLabel() = default;
    std::string getText() const override;
    std::string getColor() const override;
};
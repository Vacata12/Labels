#pragma once
#include "../Headers/SimpleLabel.h"
#include "LabelPrinter.h"

class RichLabel : public Label {
    std::string text;
    std::string color;
public:
    RichLabel(const std::string& text, const std::string& color);
    RichLabel(const std::string& text, const std::string& color, std::shared_ptr<LabelPrinter> LabelPrinter);
    ~RichLabel() = default;
    std::string getText() override;
    std::string getColor() override;
};
#pragma once
#include "../Headers/SimpleLabel.h"

class RichLabel : public SimpleLabel {
    std::string color;
public:
    RichLabel(const std::string& text, const std::string& color);
    ~RichLabel() = default;
    std::string getText() override;
    std::string getColor() const;
};
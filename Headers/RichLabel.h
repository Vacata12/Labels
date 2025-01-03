#pragma once
#include "../Headers/SimpleLabel.h"

class RichLabel : public Label {
    std::string text;
    std::string color;
public:
    RichLabel(const std::string& text, const std::string& color);
    RichLabel(const std::string& text, const std::string& color, std::shared_ptr<LabelImp> labelImp);
    ~RichLabel() = default;
    std::string getText() override;
    std::string getColor() override;
};
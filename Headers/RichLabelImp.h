#pragma once
#include "RichLabel.h"
#include "LabelImp.h"

class RichLabelImp : public LabelImp {
    RichLabel richLabel;
public:
    RichLabelImp(const std::string& text, const std::string& color, const std::string& helpText);
    ~RichLabelImp() = default;
    std::string getHelpText() override;
    std::string getText();
    std::string getColor() const;
};
#pragma once
#include "Labels.h"

class SimpleLabel : public Label {
    std::string text;
    
public:
    explicit SimpleLabel(const std::string& text);
    SimpleLabel(const std::string& text, const std::string& helpText);
    ~SimpleLabel() override = default;
    
    std::string getText() const override;
};
#pragma once
#include "../Headers/Labels.h"

class SimpleLabel : public Label {
    std::string text;
public:
    SimpleLabel(const std::string& text);
    ~SimpleLabel() = default;
    std::string getText() override;
};
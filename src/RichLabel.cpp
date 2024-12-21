#include "../Headers/RichLabel.h"

RichLabel::RichLabel(const std::string& text, const std::string& color) : SimpleLabel(text) {
    this->color = color;
}

std::string RichLabel::getColor() const {
    return this->color;
}

std::string RichLabel::getText() const {
    return SimpleLabel::getText();
}
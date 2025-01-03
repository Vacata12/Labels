#include "../Headers/RichLabel.h"

RichLabel::RichLabel(const std::string& text, const std::string& color) {
    this->text = text;
    this->color = color;
}

std::string RichLabel::getColor() {
    return this->color;
}

std::string RichLabel::getText() {
    return this->text;
}
#include "../Headers/SimpleLabel.h"

SimpleLabel::SimpleLabel(const std::string& text) {
    this->text = text;
}

std::string SimpleLabel::getText() {
    return this->text;
}
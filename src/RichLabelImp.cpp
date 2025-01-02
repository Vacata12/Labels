#include "../Headers/RichLabelImp.h"

RichLabelImp::RichLabelImp(const std::string& text, const std::string& color, const std::string& helpText) : richLabel(text,color) {
    this->helpText = helpText;
}
std::string RichLabelImp::getHelpText() {
    return this->helpText;
}
std::string RichLabelImp::getText() {
    return richLabel.getText();
}
std::string RichLabelImp::getColor() const {
    return richLabel.getColor();
}
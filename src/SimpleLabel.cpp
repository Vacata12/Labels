#include "../Headers/SimpleLabel.h"
#include "../Headers/HelpText.h"

SimpleLabel::SimpleLabel(const std::string& text) 
    : Label(), text(text) {}

SimpleLabel::SimpleLabel(const std::string& text, const std::string& helpText) 
    : Label(createHelpText(helpText)), text(text) {}

std::string SimpleLabel::getText() const {
    return text;
}

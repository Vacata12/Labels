#include "../Headers/SimpleLabel.h"
#include <iostream>

SimpleLabel::SimpleLabel(const std::string& text) : text(text)
{}

SimpleLabel::SimpleLabel(const std::string& text, const std::string& helpText) 
    : text(text)
{
    this->helpText = std::make_unique<HelpText>(helpText);
}

std::string SimpleLabel::getText() const
{
    return this->text;
}

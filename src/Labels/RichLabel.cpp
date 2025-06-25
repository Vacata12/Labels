#include "../../Headers/Labels/RichLabel.h"

RichLabel::RichLabel(const std::string& text, const std::string& color) : text(text), color(color) {}

RichLabel::RichLabel(const std::string& text, const std::string& color, const std::string& helpText) : text(text), color(color)
{
    this->helpTextImpl = std::make_unique<HelpText>(helpText);
}
std::string RichLabel::getColor() const
{
    return this->color;
}

std::string RichLabel::getText() const
{
    return this->text;
}
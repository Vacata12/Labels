#include "../Headers/LabelPrinter.h"

LabelPrinter::LabelPrinter(std::unique_ptr<Label> label) : label(std::move(label))
{

}

LabelPrinter::LabelPrinter(std::unique_ptr<Label> label, const std::string& helpText) : label(std::move(label)), helpText(helpText)
{
}

std::string LabelPrinter::getHelpText() const
{
    return this->helpText;
}
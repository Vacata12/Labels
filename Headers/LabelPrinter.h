// filepath: /Users/ivanstoynev/Documents/GitHub/Labels/Headers/LabelPrinter.h
#pragma once
#include <string>
#include <memory>
#include "Labels.h"

class LabelPrinter {
private:
    std::unique_ptr<Label> label = nullptr;
    std::string helpText = "";
public:
    LabelPrinter() = default;
    LabelPrinter(std::unique_ptr<Label> label);
    LabelPrinter(std::unique_ptr<Label> label, const std::string& helpText);
    virtual ~LabelPrinter() = default;
    virtual std::string getHelpText() const;
};
// filepath: /Users/ivanstoynev/Documents/GitHub/Labels/Headers/LabelPrinter.h
#pragma once
#include <string>
#include <memory>
#include "Labels.h"
#include "HelpText.h"

class LabelPrinter {
public:
    LabelPrinter();
    ~LabelPrinter() = default;
    static void printLabel(const Label* label);
    static void getHelpText(const Label* label, const HelpText& helpText);
};
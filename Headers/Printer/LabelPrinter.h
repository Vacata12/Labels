#pragma once
#include <string>
#include <memory>
#include "../Labels/Labels.h"

class LabelPrinter {
public:
    LabelPrinter() = delete;
    ~LabelPrinter() = delete;
    
    // Print just the label text
    static void print(const Label* label);
    
    // Print the label text followed by its help text (if any)
    static void printWithHelpText(const Label* label);
};
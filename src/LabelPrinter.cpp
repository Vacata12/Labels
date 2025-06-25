#include "../Headers/LabelPrinter.h"
#include <iostream>

void LabelPrinter::print(const Label* label) {
    if (label) {
        std::cout << "Here is a label: " << label->getText() << std::endl;
    }
}

void LabelPrinter::printWithHelpText(const Label* label) {
    if (!label) return;
    
    // Print the regular label text
    print(label);
    
    // Print help text if available
    if (label->hasHelpText()) {
        std::cout << "Some help information about this label: " 
                  << label->getHelpText() << std::endl;
    }
}


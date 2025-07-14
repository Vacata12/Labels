#include "../../Headers/Labels/ProxyLabel.h"

ProxyLabel::ProxyLabel() : label(std::make_unique<SimpleLabel>("")), isLoad(false), timeout(false) {
}

void ProxyLabel::makeTimeout() {
    std::cout << "Choose Option:\n1->Change label\n2->Keep label\n";
    int command;
    std::cin >> command;
    switch (command)
    {
    case 1:
        changeLabel();  
        break;
    case 2:
        std::cout << "Label stays the same\n";
        break;
    default:
        std::cout << "Invalid command\nBy default label stays the same\n";
        break;
    }
}
std::string ProxyLabel::getText() const
{
    return this->label->getText();
}

void ProxyLabel::changeLabel() {
        std::cout << "Enter text for the label: ";
        std::cin.ignore();
        std::string userInput;
        std::getline(std::cin, userInput);
        label = nullptr;
        label = std::make_unique<SimpleLabel>(userInput);
        isLoad = true;
}
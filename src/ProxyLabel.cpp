#include "../Headers/ProxyLabel.h"

ProxyLabel::ProxyLabel() : label(std::make_unique<SimpleLabel>("")), isLoad(false), timeout(false) {
}

void ProxyLabel::makeTimeout() {
    std::cout << "Choose Option:\n1->Change label\n2->Keep label\n";
    int command;
    std::cin >> command;
    std::cout << command << std::endl;
    switch (command)
    {
    case 1:
        changeLabel();  
        std::cout << "Label: " << this->label->getText() << std::endl;
        break;
    case 2:
        std::cout << "Label stays the same\n";
        std::cout << "Label: " << this->label->getText() << std::endl;
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
        std::cout << std::endl;
        std::cout << this->label->getText() << std::endl;
        isLoad = true;
}
#include "../Headers/ProxyLabel.h"

ProxyLabel::ProxyLabel() : label(nullptr), isLoad(false), timeout(false) {

}
void ProxyLabel::makeTimeout() {
    this->timeout = true;
}
std::string ProxyLabel::getText() {
    if(!isLoad) {
        changeLabel();
        isLoad = true;
    }
    if(timeout) {
        std::cout << "The label is in timeout.\nDo you want to change(1) or keep the text(any other number):";
        size_t command;
        std::cin >> command;
        if(command == 1) {
            changeLabel();
        }
        timeout = false;
    }
    return label->getText();
}

void ProxyLabel::changeLabel() {
        std::cout << "Enter text for the label: ";
        std::string userInput;
        std::getline(std::cin, userInput);
        label = std::make_unique<SimpleLabel>(userInput);
        isLoad = true;
}
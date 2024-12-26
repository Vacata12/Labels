#include "../Headers/LabelDecoratorBase.h"
#include <iostream>

LabelDecoratorBase::LabelDecoratorBase(std::shared_ptr<Label> label) : label(label)
{}
std::string LabelDecoratorBase::getText() {
    return this->label->getText();
}

std::shared_ptr<Label> LabelDecoratorBase::removeDecorator(std::shared_ptr<Label> label, std::shared_ptr<LabelDecoratorBase> toRemove) {
    if(!label) {
        return nullptr;
    }
    std::shared_ptr<LabelDecoratorBase> current = std::dynamic_pointer_cast<LabelDecoratorBase>(label);
    std::shared_ptr<LabelDecoratorBase> previous = nullptr;
    while (current) {
        if (current == toRemove) {
            if (previous) {
                previous->label = current->label;
            } else {
                label = current->label;
            }
            break;
        }
        previous = current;
        current = std::dynamic_pointer_cast<LabelDecoratorBase>(current->label);
    }
    std::cout << label->getText() << std::endl;
    return label;
}
#include "../Headers/LabelDecoratorBase.h"

LabelDecoratorBase::LabelDecoratorBase(std::shared_ptr<Label> label) : label(label)
{}
std::string LabelDecoratorBase::getText() const {
    return this->label->getText();
}
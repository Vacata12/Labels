#include "../Headers/RandomTransformationDecorator.h"
#include <memory>
#include <iostream>

// I tried with std;:dynamic_cast but it gave me error: expected unqualified-id :'(
void RandomTransformationDecorator::generateTransformation() {
    size_t sz = transforms.size();
    if(sz == 1) {
        return;
    }
    while(true) {
        size_t tmp = std::rand() % sz;
        if(tmp != currentIndex) {
            currentIndex = tmp;
            break;
        }
    }
}
RandomTransformationDecorator::RandomTransformationDecorator(std::vector<std::shared_ptr<TextTransformation> > transforms, std::shared_ptr<Label> label) : LabelDecoratorBase(label), transforms(transforms) {
}

std::string RandomTransformationDecorator::getText() {
    generateTransformation();
    return this->transforms[currentIndex]->transform(this->label->getText());
}
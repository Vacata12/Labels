#include "../Headers/RandomTransformationDecorator.h"
#include <memory>
#include <iostream>

// I tried with std;:dynamic_cast but it gave me error: expected unqualified-id :'(
void RandomTransformationDecorator::generateTransformation() const {
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
RandomTransformationDecorator::RandomTransformationDecorator(std::vector<std::shared_ptr<TextTransformation> > _transforms, std::shared_ptr<Label> label) : LabelDecoratorBase(label), transforms(_transforms) {
}

std::string RandomTransformationDecorator::getText() const {
    generateTransformation();
    label = std::make_shared<TextTransformationDecorator>(label, transforms[currentIndex]);
    std::string result = label->getText();
    return result;
}
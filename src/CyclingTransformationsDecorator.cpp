#include "../Headers/CyclingTransformationsDecorator.h"

void CyclingTransformationsDecorator::moveOne() {
    if(currentIndex == transforms.size() - 1) {
        currentIndex = 0;
    }
    else {
        currentIndex += 1;
    }
}

CyclingTransformationsDecorator::CyclingTransformationsDecorator(std::vector<std::shared_ptr<TextTransformationDecorator> > transforms, std::shared_ptr<Label> label) : LabelDecoratorBase(label), transforms(transforms) {

}
std::string CyclingTransformationsDecorator:: getText() {
    if(transforms.empty()) {
        return label->getText();
    }
    moveOne();
    return transforms[currentIndex]->getText();
}
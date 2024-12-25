#include "../Headers/CyclingTransformationsDecorator.h"

void CyclingTransformationsDecorator::moveOne() {
    if(currentIndex == transforms.size()) {
        currentIndex = 0;
    }
    else {
        currentIndex += 1;
    }
}

CyclingTransformationsDecorator::CyclingTransformationsDecorator(std::vector<std::shared_ptr<TextTransformation> > transforms, std::shared_ptr<Label> label) : LabelDecoratorBase(label), transforms(transforms) {

}
std::string CyclingTransformationsDecorator:: getText() {
    moveOne();
    return transforms[currentIndex]->transform(label->getText());
}
#include "../Headers/CyclingTransformationsDecorator.h"

void CyclingTransformationsDecorator::moveOne() const {
    if(currentIndex == transforms.size() - 1) {
        currentIndex = 0;
    }
    else {
        currentIndex += 1;
    }
}

CyclingTransformationsDecorator::CyclingTransformationsDecorator(std::vector<std::shared_ptr<TextTransformation> > _transforms, std::shared_ptr<Label> label) : LabelDecoratorBase(label), transforms(_transforms) {
}
std::string CyclingTransformationsDecorator:: getText() const
 {
    if(transforms.empty()) {
        return label->getText();
    }
    moveOne();
    label = std::make_shared<TextTransformationDecorator>(label, transforms[currentIndex]);
    std::string result = label->getText();
    return result;
}
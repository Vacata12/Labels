#include "../Headers/CyclingTransformationsDecorator.h"

void CyclingTransformationsDecorator::moveOne() {
    if(currentIndex == transforms.size() - 1) {
        currentIndex = 0;
    }
    else {
        currentIndex += 1;
    }
}

CyclingTransformationsDecorator::CyclingTransformationsDecorator(std::vector<std::shared_ptr<TextTransformation> > _transforms, std::shared_ptr<Label> label) : LabelDecoratorBase(label) {
    for(size_t i = 0; i < _transforms.size(); i++) {
        transforms.push_back(std::make_shared<TextTransformationDecorator>(label, _transforms[i]));
    }
}
std::string CyclingTransformationsDecorator:: getText() {
    if(transforms.empty()) {
        return label->getText();
    }
    moveOne();
    std::string result = transforms[currentIndex]->getText();
    return result;
}
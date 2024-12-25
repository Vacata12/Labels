#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"
#include <vector>
#include <memory>

class CyclingTransformationsDecorator : public LabelDecoratorBase {
    std::vector<std::shared_ptr<TextTransformation> > transforms;
    size_t currentIndex = 0;
    void moveOne();
public:
    CyclingTransformationsDecorator(std::vector<std::shared_ptr<TextTransformation> > transforms, std::shared_ptr<Label> label);
    ~CyclingTransformationsDecorator() = default;
    std::string getText() override;
};
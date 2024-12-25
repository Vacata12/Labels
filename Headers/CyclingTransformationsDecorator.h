#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformationDecorator.h"
#include <vector>
#include <memory>

class CyclingTransformationsDecorator : public LabelDecoratorBase {
    std::vector<std::shared_ptr<TextTransformationDecorator> > transforms;
    size_t currentIndex = -1;
    void moveOne();
public:
    CyclingTransformationsDecorator(std::vector<std::shared_ptr<TextTransformationDecorator> > transforms, std::shared_ptr<Label> label);
    ~CyclingTransformationsDecorator() = default;
    std::string getText() override;
};
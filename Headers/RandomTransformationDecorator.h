#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformationDecorator.h"
#include "Capitalize.h"
#include "LeftTrim.h"
#include "RightTrim.h"
#include "Censor.h"
#include "NormalizeSpace.h"
#include "Replace.h"
#include <vector>
#include <memory>

class RandomTransformationDecorator : public LabelDecoratorBase {
private:
    std::vector<std::shared_ptr<TextTransformation> > transforms;
    size_t currentIndex = 0;
    void generateTransformation();
public:
    RandomTransformationDecorator(std::vector<std::shared_ptr<TextTransformation> > transforms, std::shared_ptr<Label> label);
    ~RandomTransformationDecorator() = default;

    std::string getText() override;
};
#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformationDecorator.h"
#include "../Transformations/Capitalize.h"
#include "../Transformations/LeftTrim.h"
#include "../Transformations/RightTrim.h"
#include "../Transformations/Censor.h"
#include "../Transformations/NormalizeSpace.h"
#include "../Transformations/Replace.h"
#include <vector>
#include <memory>

class RandomTransformationDecorator : public LabelDecoratorBase {
private:
    std::vector<std::shared_ptr<TextTransformation> > transforms;
    mutable size_t currentIndex = 0;
public:
    RandomTransformationDecorator(std::vector<std::shared_ptr<TextTransformation> > transforms, std::shared_ptr<Label> label);
    ~RandomTransformationDecorator() = default;

    std::string getText() const override;
private:
    void generateTransformation() const;
};
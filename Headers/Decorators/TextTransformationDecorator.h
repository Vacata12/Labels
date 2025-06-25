#pragma once
#include "LabelDecoratorBase.h"
#include "../Transformations/TextTransformation.h"

class TextTransformationDecorator : public LabelDecoratorBase {
protected:
    std::shared_ptr<TextTransformation> labelTransform;
public:
    TextTransformationDecorator(std::shared_ptr<Label> label, std::shared_ptr<TextTransformation> labelTransform);
    ~TextTransformationDecorator() = default;
    std::string getText() const override;
};
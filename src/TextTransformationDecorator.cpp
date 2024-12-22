#include "../Headers/TextTransformationDecorator.h"

TextTransformationDecorator::TextTransformationDecorator(std::shared_ptr<Label> label, std::shared_ptr<TextTransformation> labelTransform) : LabelDecoratorBase(label), labelTransform(labelTransform)
{

}
std::string TextTransformationDecorator::getText() const {
    return this->labelTransform->transform(label->getText());
}
void TextTransformationDecorator::transform() const {
    labelTransform->transform(label->getText());
}
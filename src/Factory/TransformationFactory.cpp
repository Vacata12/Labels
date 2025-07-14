#include "../../Headers/Factory/TransformationFactory.h"

std::shared_ptr<TextTransformation> TransformationFactory::createCapitalize() {
    return std::make_shared<Capitalize>();
}

std::shared_ptr<TextTransformation> TransformationFactory::createLeftTrim() {
    return std::make_shared<LeftTrim>();
}

std::shared_ptr<TextTransformation> TransformationFactory::createRightTrim() {
    return std::make_shared<RightTrim>();
}

std::shared_ptr<TextTransformation> TransformationFactory::createCensor(
    const std::string& wordToCensor) {
    return std::make_shared<Censor>(wordToCensor);
}

std::shared_ptr<TextTransformation> TransformationFactory::createDecorate() {
    return std::make_shared<Decorate>();
}

std::shared_ptr<TextTransformation> TransformationFactory::createNormalizeSpace() {
    return std::make_shared<NormalizeSpace>();
}

std::shared_ptr<TextTransformation> TransformationFactory::createReplace(
    const std::string& target, const std::string& replacement) {
    return std::make_shared<Replace>(target, replacement);
}

std::shared_ptr<TextTransformation> TransformationFactory::createComposite( const std::string& transformations) {
    return std::make_shared<CompositeTransformation>(transformations);
}

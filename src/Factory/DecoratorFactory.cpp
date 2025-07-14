#include "../../Headers/Factory/DecoratorFactory.h"

std::shared_ptr<Label> DecoratorFactory::createTextTransformationDecorator(
    std::shared_ptr<Label> label,
    std::shared_ptr<TextTransformation> transformation) {
    return std::make_shared<TextTransformationDecorator>(label, transformation);
}

std::shared_ptr<Label> DecoratorFactory::createRandomTransformationDecorator(
    std::shared_ptr<Label> label,
    const std::vector<std::shared_ptr<TextTransformation>>& transformations) {
    return std::make_shared<RandomTransformationDecorator>(transformations, label);
}

std::shared_ptr<Label> DecoratorFactory::createCyclingTransformationsDecorator(
    std::shared_ptr<Label> label,
    const std::vector<std::shared_ptr<TextTransformation>>& transformations) {
    return std::make_shared<CyclingTransformationsDecorator>(transformations, label);
}

std::shared_ptr<Label> DecoratorFactory::applyMultipleDecorators(
    std::shared_ptr<Label> baseLabel,
    const std::vector<std::string>& decoratorTypes,
    const std::vector<std::shared_ptr<TextTransformation>>& transformations) {
    
    std::shared_ptr<Label> decoratedLabel = baseLabel;
    size_t transformIndex = 0;
    
    for (const auto& type : decoratorTypes) {
        if (type == "textTransformation" && transformIndex < transformations.size()) {
            decoratedLabel = createTextTransformationDecorator(
                decoratedLabel, transformations[transformIndex++]);
        }
        else if (type == "random" && !transformations.empty()) {
            decoratedLabel = createRandomTransformationDecorator(
                decoratedLabel, transformations);
        }
        else if (type == "cycling" && !transformations.empty()) {
            decoratedLabel = createCyclingTransformationsDecorator(
                decoratedLabel, transformations);
        }
    }
    
    return decoratedLabel;
}

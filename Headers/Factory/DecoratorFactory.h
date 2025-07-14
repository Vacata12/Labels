#pragma once
#include <memory>
#include <string>
#include <vector>
#include "../Labels/Labels.h"
#include "../Decorators/LabelDecoratorBase.h"
#include "../Decorators/TextTransformationDecorator.h"
#include "../Decorators/RandomTransformationDecorator.h"
#include "../Decorators/CyclingTransformationsDecorator.h"
#include "../Transformations/TextTransformation.h"

class DecoratorFactory
{
private:
public:
    DecoratorFactory() = default;
    DecoratorFactory(const DecoratorFactory&) = delete;
    DecoratorFactory& operator=(const DecoratorFactory&) = delete;
    ~DecoratorFactory() = default;

    // Create different types of decorators
    static std::shared_ptr<Label> createTextTransformationDecorator(
        std::shared_ptr<Label> label,
        std::shared_ptr<TextTransformation> transformation);
    
    static std::shared_ptr<Label> createRandomTransformationDecorator(
        std::shared_ptr<Label> label,
        const std::vector<std::shared_ptr<TextTransformation>>& transformations);
    
    static std::shared_ptr<Label> createCyclingTransformationsDecorator(
        std::shared_ptr<Label> label,
        const std::vector<std::shared_ptr<TextTransformation>>& transformations);
    
    // Helper method to apply multiple decorators in sequence
    static std::shared_ptr<Label> applyMultipleDecorators(
        std::shared_ptr<Label> baseLabel,
        const std::vector<std::string>& decoratorTypes,
        const std::vector<std::shared_ptr<TextTransformation>>& transformations);
};

#pragma once
#include <memory>
#include <string>
#include <vector>
#include "../Transformations/TextTransformation.h"
#include "../Transformations/Capitalize.h"
#include "../Transformations/LeftTrim.h"
#include "../Transformations/RightTrim.h"
#include "../Transformations/Censor.h"
#include "../Transformations/Decorate.h"
#include "../Transformations/NormalizeSpace.h"
#include "../Transformations/Replace.h"
#include "../Transformations/CompositeTransformation.h"

class TransformationFactory
{
private:
public:
    TransformationFactory() = default;
    TransformationFactory(const TransformationFactory&) = delete;
    TransformationFactory& operator=(const TransformationFactory&) = delete;
    ~TransformationFactory() = default;

    // Create individual transformations
    static std::shared_ptr<TextTransformation> createCapitalize();
    static std::shared_ptr<TextTransformation> createLeftTrim();
    static std::shared_ptr<TextTransformation> createRightTrim();
    static std::shared_ptr<TextTransformation> createCensor(const std::string& wordToCensor);
    static std::shared_ptr<TextTransformation> createDecorate();
    static std::shared_ptr<TextTransformation> createNormalizeSpace();
    static std::shared_ptr<TextTransformation> createReplace(const std::string& target, const std::string& replacement);
    
    //Create composite transformation
    static std::shared_ptr<TextTransformation> createComposite(const std::string& transformations);
};

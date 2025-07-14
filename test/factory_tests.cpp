// #include "../Headers/Factory/LabelFactory.h"
// #include "../Headers/Factory/TransformationFactory.h"
// #include "../Headers/Factory/DecoratorFactory.h"
// #include "catch2/catch_test_macros.hpp"
// #include <memory>
// #include <string>

// TEST_CASE("Factory integration", "[Factory]") {
//     // Create a simple label using LabelFactory
//     auto simpleLabel = LabelFactory::createSimpleLabel("Hello World", "This is a test label");

//     SECTION("LabelFactory creates labels with correct text") {
//         REQUIRE(simpleLabel->getText() == "Hello World");
//     }

//     SECTION("TransformationFactory creates transformations") {
//         // Create a capitalize transformation
//         auto capitalizeTransform = TransformationFactory::createCapitalize();
        
//         // Apply the transformation directly to the text
//         REQUIRE(capitalizeTransform->transform("hello") == "Hello");
//     }

//     SECTION("DecoratorFactory applies transformations to labels") {
//         // Create a capitalize transformation
//         auto capitalizeTransform = TransformationFactory::createCapitalize();

//         // Apply it to the label via a decorator
//         auto decoratedLabel = DecoratorFactory::createTextTransformationDecorator(simpleLabel, capitalizeTransform);

//         // The text should now be capitalized
//         REQUIRE(decoratedLabel->getText() == "Hello World");
//     }

//     SECTION("Complex decoration using multiple factories") {
//         // Create text transformations
//         std::vector<std::shared_ptr<TextTransformation>> transforms;
//         transforms.push_back(TransformationFactory::createCapitalize());
//         transforms.push_back(TransformationFactory::createDecorate("** ", " **"));

//         // Create a rich label
//         auto richLabel = LabelFactory::createRichLabel("important message", "red", "Notice");

//         // Apply random transformation decorator
//         auto decoratedLabel = DecoratorFactory::createCyclingTransformationsDecorator(richLabel, transforms);

//         // The first call should apply the first transformation (capitalize)
//         std::string firstTransform = decoratedLabel->getText();
//         // The second call should apply the second transformation (decorate)
//         std::string secondTransform = decoratedLabel->getText();

//         REQUIRE(firstTransform == "Important Message");
//         REQUIRE(secondTransform == "** important message **");
//     }
// }

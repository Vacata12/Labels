#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "catch2/catch_test_macros.hpp"
#include "../Headers/Labels/RichLabel.h"
#include "../Headers/Transformations/Capitalize.h"
#include "../Headers/Transformations/LeftTrim.h"
#include "../Headers/Transformations/RightTrim.h"
#include "../Headers/Transformations/Censor.h"
#include "../Headers/Transformations/Decorate.h"
#include "../Headers/Transformations/NormalizeSpace.h"
#include "../Headers/Transformations/Replace.h"
#include "../Headers/Decorators/TextTransformationDecorator.h"
#include "../Headers/Decorators/RandomTransformationDecorator.h"
#include "../Headers/Decorators/CyclingTransformationsDecorator.h"
#include "../Headers/Transformations/CompositeTransformation.h"
#include "../Headers/Labels/ProxyLabel.h"
#include "../Headers/Printer/LabelPrinter.h"
#include "../Headers/Factory/LabelFactory.h"
#include "../Headers/Factory/TransformationFactory.h"
#include "../Headers/Factory/DecoratorFactory.h"

TEST_CASE("SimpleLabel functionality", "[SimpleLabel]") {
    SECTION("Constructor sets text correctly") {
        SimpleLabel label("Test");
        REQUIRE(label.getText() == "Test");
    }

    SECTION("getText returns correct text") {
        SimpleLabel label("Another Test");
        REQUIRE(label.getText() == "Another Test");
    }
}

TEST_CASE("RichLabel functionality", "[RichLabel]") {
    SECTION("Constructor sets color correctly") {
        RichLabel label("Red", "Red");
        REQUIRE(label.getColor() == "Red");
    }

    SECTION("getColor returns correct color") {
        RichLabel label("Blue", "Blue");
        REQUIRE(label.getColor() == "Blue");
    }

    SECTION("Inheritance of getText from SimpleLabel") {
        RichLabel label("Green", "Green");
        REQUIRE(label.getText() == "Green");
    }
}

TEST_CASE("Capitalize functionality", "[Capitalize]") {
    SECTION("Capitalize capitalizes first letter") {
        Capitalize capitalize;
        REQUIRE(capitalize.transform("test") == "Test");
    }

    SECTION("Capitalize does not change already capitalized first letter") {
        Capitalize capitalize;
        REQUIRE(capitalize.transform("Test") == "Test");
    }

    SECTION("Capitalize does not change empty string") {
        Capitalize capitalize;
        REQUIRE(capitalize.transform("") == "");
    }
}

TEST_CASE("LeftTrim functionality", "[LeftTrim]") {
    SECTION("LeftTrim trims spaces from left") {
        LeftTrim leftTrim;
        REQUIRE(leftTrim.transform("   test") == "test");
    }

    SECTION("LeftTrim does not change string without leading spaces") {
        LeftTrim leftTrim;
        REQUIRE(leftTrim.transform("test") == "test");
    }

    SECTION("LeftTrim does not change empty string") {
        LeftTrim leftTrim;
        REQUIRE(leftTrim.transform("") == "");
    }
}

TEST_CASE("RightTrim functionality", "[RightTrim]") {
    SECTION("RightTrim trims spaces from right") {
        RightTrim rightTrim;
        REQUIRE(rightTrim.transform("test   ") == "test");
    }

    SECTION("RightTrim does not change string without trailing spaces") {
        RightTrim rightTrim;
        REQUIRE(rightTrim.transform("test") == "test");
    }

    SECTION("RightTrim does not change empty string") {
        RightTrim rightTrim;
        REQUIRE(rightTrim.transform("") == "");
    }
}

TEST_CASE("Censor functionality", "[Censor]") {
    SECTION("Censor censors word") {
        Censor censor("censor");
        REQUIRE(censor.transform("censor") == "******");
    }

    SECTION("Censor censors word in sentence") {
        Censor censor("censor");
        REQUIRE(censor.transform("This is a censor test") == "This is a ****** test");
    }

    SECTION("Censor does not change string without censored word") {
        Censor censor("censor");
        REQUIRE(censor.transform("This is a test") == "This is a test");
    }

    SECTION("Censor does not change empty string") {
        Censor censor("censor");
        REQUIRE(censor.transform("") == "");
    }
}

TEST_CASE("Decorate functionality", "[Decorate]") {
    SECTION("Decorate decorates text") {
        Decorate decorate;
        REQUIRE(decorate.transform("test") == "-={ test }=-");
    }

    SECTION("Decorate does not change empty string") {
        Decorate decorate;
        REQUIRE(decorate.transform("") == "-={  }=-");
    }
}

TEST_CASE("NormalizeSpace functionality", "[NormalizeSpace]") {
    SECTION("NormalizeSpace removes extra spaces") {
        NormalizeSpace normalizeSpace;
        REQUIRE(normalizeSpace.transform("test   test") == "test test");
    }

    SECTION("NormalizeSpace does not change string without extra spaces") {
        NormalizeSpace normalizeSpace;
        REQUIRE(normalizeSpace.transform("test test") == "test test");
    }

    SECTION("NormalizeSpace does not change empty string") {
        NormalizeSpace normalizeSpace;
        REQUIRE(normalizeSpace.transform("") == "");
    }
}

TEST_CASE("Replace functionality", "[Replace]") {
    SECTION("Replace replaces A with B") {
        Replace replace("A", "B");
        REQUIRE(replace.transform("A") == "B");
    }

    SECTION("Replace replaces A with B in sentence") {
        Replace replace("A", "B");
        REQUIRE(replace.transform("This is A test") == "This is B test");
    }

    SECTION("Replace does not change string without A") {
        Replace replace("A", "B");
        REQUIRE(replace.transform("This is a test") == "This is a test");
    }

    SECTION("Replace does not change empty string") {
        Replace replace("A", "B");
        REQUIRE(replace.transform("") == "");
    }
}   

TEST_CASE("TextTransformationDecorator functionality", "[TextTransformationDecorator]") {
    SECTION("getText applies transformation to label text") {
        auto label = std::make_shared<SimpleLabel>("test");
        auto capitalize = std::make_shared<Capitalize>();
        TextTransformationDecorator decorator(label, capitalize);
        REQUIRE(decorator.getText() == "Test");
    }

    SECTION("transform applies transformation to label text") {
        auto label = std::make_shared<SimpleLabel>("test");
        auto capitalize = std::make_shared<Capitalize>();
        TextTransformationDecorator decorator(label, capitalize);
        REQUIRE(label->getText() == "test");
    }

    SECTION("getText with multiple transformations") {
        auto label = std::make_shared<SimpleLabel>("   test   ");
        auto leftTrim = std::make_shared<LeftTrim>();
        auto rightTrim = std::make_shared<RightTrim>();
        
        auto leftTrimDecorator = std::make_shared<TextTransformationDecorator>(label, leftTrim);
        auto rightTrimDecorator = std::make_shared<TextTransformationDecorator>(leftTrimDecorator, rightTrim);
    
        REQUIRE(rightTrimDecorator->getText() == "test");
    }
}

TEST_CASE("RandomTransformationDecorator functionality", "[RandomTransformationDecorator]") {
    SECTION("RandomTransformationDecorator applies one of the transformations randomly") {
        auto label = std::make_shared<SimpleLabel>("   test   ");
        auto leftTrim = std::make_shared<LeftTrim>();
        auto rightTrim = std::make_shared<RightTrim>();
        auto capitalize = std::make_shared<Capitalize>();

        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            leftTrim,
            rightTrim,
            capitalize
        };

        RandomTransformationDecorator randomDecorator(transformations, label);

        std::string result = randomDecorator.getText();
        REQUIRE((result == "test" || result == "   test" || result == "   Test   "));
    }
}

TEST_CASE("CyclingTransformationsDecorator functionality", "[CyclingTransformationsDecorator]") {
    SECTION("getText returns label text if no transformations are provided") {
        auto label = std::make_shared<SimpleLabel>("test");
        CyclingTransformationsDecorator decorator({}, label);
        REQUIRE(decorator.getText() == "test");
    }

    SECTION("getText cycles through transformations and returns transformed text") {
        auto label = std::make_shared<SimpleLabel>("  test  ");
        auto capitalize = std::make_shared<Capitalize>();
        auto leftTrim = std::make_shared<LeftTrim>();
        auto rightTrim = std::make_shared<RightTrim>();

        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            capitalize,
            leftTrim,
            rightTrim
        };

        CyclingTransformationsDecorator decorator(transformations, label);

        REQUIRE(decorator.getText() == "  Test  "); // First transformation: Capitalize
        REQUIRE(decorator.getText() == "Test  "); // Second transformation: LeftTrim
        REQUIRE(decorator.getText() == "Test"); // Third transformation: RightTrim
        REQUIRE(decorator.getText() == "Test"); // Back to the first transformation: Capitalize
    }
}

TEST_CASE("LabelDecoratorTest", "[RemoveDecorator]") {
    std::shared_ptr<Label> label = std::make_shared<SimpleLabel>("abcd efgh ijkl mnop");
    label = std::make_shared<TextTransformationDecorator>(label, std::make_shared<Censor>("abcd"));
    label = std::make_shared<TextTransformationDecorator>(label, std::make_shared<Censor>("mnop"));
    REQUIRE(label->getText() == "**** efgh ijkl ****");

    std::shared_ptr<LabelDecoratorBase> whatToRemove = std::make_shared<TextTransformationDecorator>(nullptr, std::make_shared<Censor>("abcd"));
    label = LabelDecoratorBase::removeDecorator(label, whatToRemove);
    REQUIRE(label->getText() == "**** efgh ijkl ****"); 
}

TEST_CASE("CompositeTransformation functionality", "[CompositeTransformation]") {
    SECTION("CompositeTransformation apples one transformation") {
        CompositeTransformation composite("Capitalize");
        REQUIRE(composite.transform("test") == "Test");
    }
    SECTION("CompositeTransformation applies transformations in order") {
        CompositeTransformation composite("Capitalize LeftTrim RightTrim NormalizeSpace");
        REQUIRE(composite.transform("   test   ") == "Test");
    }
    SECTION("CompositeTransformation with replace") {
        CompositeTransformation composite("Capitalize Decorate Replace(abc,def)");
        REQUIRE(composite.transform("abc def") == "-={ Abc def }=-");
    }
    //In work
    SECTION("CompositeTransformation swap") {
        CompositeTransformation composite("Capitalize Decorate Replace(abc,def)");
        composite.swithPlacesOfTransforms(0, 2);
        composite.swithPlacesOfTransforms(1, 2);
        REQUIRE(composite.transform("abc def") == "-={ Def def }=-");
    }
}


TEST_CASE("ProxyLabel makeTimeout behavior", "[ProxyLabel]") {
    ProxyLabel proxyLabel;

    SECTION("makeTimeout changes label when option 1 is selected") {
        std::istringstream input("1\nNew Label Text");
        std::cin.rdbuf(input.rdbuf());

        proxyLabel.makeTimeout();
        REQUIRE(proxyLabel.getText() == "New Label Text");


        std::istringstream input2("2\n");
        std::cin.rdbuf(input2.rdbuf());

        std::string currentLabel = proxyLabel.getText();

        proxyLabel.makeTimeout();
        REQUIRE(proxyLabel.getText() == currentLabel);
    }
}

TEST_CASE("HelpTextImpl basic functionality", "[HelpText]") {
    SECTION("Create empty HelpText") {
        HelpText helpText;
        REQUIRE(helpText.getHelpText() == "");
    }
    
    SECTION("Create HelpText with text") {
        HelpText helpText("This is help text");
        REQUIRE(helpText.getHelpText() == "This is help text");
    }
}

TEST_CASE("Label with HelpText functionality", "[Label]") {
    SECTION("Default Label has no HelpText") {
        Label* label = new SimpleLabel("Test");
        REQUIRE_FALSE(label->hasHelpText());
        REQUIRE(label->getHelpText() == "");
        delete label;
    }
    
    SECTION("Setting HelpText on Label") {
        Label* label = new SimpleLabel("Test");
        label->setHelpText(createHelpText("New help text"));
        REQUIRE(label->hasHelpText());
        REQUIRE(label->getHelpText() == "New help text");
        delete label;
    }
    
    SECTION("Creating Label with HelpText") {
        SimpleLabel label("Test", "Help for test label");
        REQUIRE(label.hasHelpText());
        REQUIRE(label.getHelpText() == "Help for test label");
    }
}

TEST_CASE("SimpleLabel with HelpText", "[SimpleLabel]") {
    SECTION("SimpleLabel without help text") {
        SimpleLabel label("Test");
        REQUIRE_FALSE(label.hasHelpText());
    }
    
    SECTION("SimpleLabel with help text via constructor") {
        SimpleLabel label("Test", "This is help text for Test");
        REQUIRE(label.hasHelpText());
        REQUIRE(label.getHelpText() == "This is help text for Test");
    }
    
    SECTION("SimpleLabel with help text via setter") {
        SimpleLabel label("Test");
        label.setHelpText(createHelpText("Added help text"));
        REQUIRE(label.hasHelpText());
        REQUIRE(label.getHelpText() == "Added help text");
    }
}

TEST_CASE("RichLabel with HelpText", "[RichLabel]") {
    SECTION("RichLabel with help text via constructor") {
        RichLabel label("Test", "blue", "This is help for a blue label");
        REQUIRE(label.hasHelpText());
        REQUIRE(label.getHelpText() == "This is help for a blue label");
    }
    
    SECTION("RichLabel help text does not affect text or color") {
        RichLabel label("Test", "red", "Help info");
        REQUIRE(label.getText() == "Test");
        REQUIRE(label.getColor() == "red");
        REQUIRE(label.getHelpText() == "Help info");
    }
}

TEST_CASE("HelpText with decorators", "[Decorators]") {
    SECTION("Decorators preserve help text") {
        auto baseLabel = std::make_shared<SimpleLabel>("test", "This is help text");
        auto capitalize = std::make_shared<Capitalize>();
        
        TextTransformationDecorator decorator(baseLabel, capitalize);
        
        REQUIRE(decorator.getText() == "Test");
        REQUIRE(baseLabel->hasHelpText());
        REQUIRE(baseLabel->getHelpText() == "This is help text");
    }
}

TEST_CASE("LabelPrinter with HelpText", "[LabelPrinter]") {
    SECTION("Print label with help text") {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        
        SimpleLabel label("Test Label", "Help for test label");
        LabelPrinter::printWithHelpText(&label);
        
        std::cout.rdbuf(old);
        std::string output = buffer.str();
        
        REQUIRE(output.find("Here is a label: Test Label") != std::string::npos);
        REQUIRE(output.find("Some help information about this label: Help for test label") != std::string::npos);
    }
    
    SECTION("Print label without help text") {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        
        SimpleLabel label("Test Label");
        LabelPrinter::printWithHelpText(&label);
        
        std::cout.rdbuf(old);
        std::string output = buffer.str();
        
        REQUIRE(output.find("Here is a label: Test Label") != std::string::npos);
        REQUIRE(output.find("Some help information") == std::string::npos);
    }
}

TEST_CASE("Help text modification", "[HelpText]") {
    SECTION("Change help text after creation") {
        SimpleLabel label("Test", "Initial help");
        REQUIRE(label.getHelpText() == "Initial help");
        
        label.setHelpText(createHelpText("Updated help"));
        REQUIRE(label.getHelpText() == "Updated help");
    }
    
    SECTION("Remove help text") {
        SimpleLabel label("Test", "Help text");
        REQUIRE(label.hasHelpText());
        
        label.setHelpText(nullptr);
        REQUIRE_FALSE(label.hasHelpText());
        REQUIRE(label.getHelpText() == "");
    }
}

TEST_CASE("LabelFactory functionality", "[LabelFactory]") {
    SECTION("createSimpleLabel creates proper SimpleLabel") {
        auto label = LabelFactory::createSimpleLabel("Test Label", "Help text");
        REQUIRE(label->getText() == "Test Label");
        REQUIRE(label->hasHelpText());
        REQUIRE(label->getHelpText() == "Help text");
    }
    
    SECTION("createSimpleLabel with empty help text") {
        auto label = LabelFactory::createSimpleLabel("Test Label", "");
        REQUIRE(label->getText() == "Test Label");
        REQUIRE(label->hasHelpText());
        REQUIRE(label->getHelpText() == "");
    }
    
    SECTION("createRichLabel creates proper RichLabel") {
        auto label = LabelFactory::createRichLabel("Rich Label", "blue", "Rich help text");
        REQUIRE(label->getText() == "Rich Label");
        REQUIRE(label->getColor() == "blue");
        REQUIRE(label->hasHelpText());
        REQUIRE(label->getHelpText() == "Rich help text");
    }
    
    SECTION("createRichLabel with default color and help text") {
        auto label = LabelFactory::createRichLabel("Rich Label", "", "");
        REQUIRE(label->getText() == "Rich Label");
        REQUIRE(label->getColor() == "");
        REQUIRE(label->hasHelpText());
        REQUIRE(label->getHelpText() == "");
    }
    
    SECTION("createProxyLabel creates ProxyLabel instance") {
        auto proxyLabel = LabelFactory::createProxyLabel("Initial Text", "Help text");
        
        // Since ProxyLabel constructor doesn't use parameters,
        // we're just checking that it creates a valid instance
        REQUIRE(proxyLabel != nullptr);
        
        // Test label functionality
        std::istringstream input("1\nNew Label Text");
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
        
        // Redirect cout to avoid cluttering test output
        std::stringstream outputBuffer;
        std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf());
        
        // Cast to ProxyLabel to access makeTimeout
        auto* proxy = dynamic_cast<ProxyLabel*>(proxyLabel.get());
        REQUIRE(proxy != nullptr);
        proxy->makeTimeout();
        
        // Restore cin and cout
        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);
        
        REQUIRE(proxy->getText() == "New Label Text");
    }
    
    SECTION("Factory creates distinct instances") {
        auto label1 = LabelFactory::createSimpleLabel("Label 1", "Help 1");
        auto label2 = LabelFactory::createSimpleLabel("Label 2", "Help 2");
        
        REQUIRE(label1->getText() == "Label 1");
        REQUIRE(label2->getText() == "Label 2");
        REQUIRE(label1->getHelpText() == "Help 1");
        REQUIRE(label2->getHelpText() == "Help 2");
    }
}

TEST_CASE("TransformationFactory functionality", "[TransformationFactory]") {
    SECTION("createCapitalize creates proper Capitalize transformation") {
        auto capitalize = TransformationFactory::createCapitalize();
        REQUIRE(capitalize->transform("test") == "Test");
    }
    
    SECTION("createLeftTrim creates proper LeftTrim transformation") {
        auto leftTrim = TransformationFactory::createLeftTrim();
        REQUIRE(leftTrim->transform("   test") == "test");
    }
    
    SECTION("createRightTrim creates proper RightTrim transformation") {
        auto rightTrim = TransformationFactory::createRightTrim();
        REQUIRE(rightTrim->transform("test   ") == "test");
    }
    
    SECTION("createCensor creates proper Censor transformation") {
        auto censor = TransformationFactory::createCensor("badword");
        REQUIRE(censor->transform("This contains badword here") == "This contains ******* here");
    }
    
    SECTION("createDecorate creates proper Decorate transformation") {
        auto decorate = TransformationFactory::createDecorate();
        REQUIRE(decorate->transform("test") == "-={ test }=-");
    }
    
    SECTION("createNormalizeSpace creates proper NormalizeSpace transformation") {
        auto normalize = TransformationFactory::createNormalizeSpace();
        REQUIRE(normalize->transform("test   test") == "test test");
    }
    
    SECTION("createReplace creates proper Replace transformation") {
        auto replace = TransformationFactory::createReplace("old", "new");
        REQUIRE(replace->transform("Replace old with new") == "Replace new with new");
    }
    
    SECTION("createComposite creates proper CompositeTransformation") {
        auto composite = TransformationFactory::createComposite("Capitalize LeftTrim");
        REQUIRE(composite->transform("  test") == "Test");
    }
    
    SECTION("createComposite with complex transformations") {
        auto composite = TransformationFactory::createComposite("Capitalize Decorate Replace(test,example)");
        REQUIRE(composite->transform("this is a test string") == "-={ This is a example string }=-");
    }
}

TEST_CASE("DecoratorFactory functionality", "[DecoratorFactory]") {
    SECTION("createTextTransformationDecorator applies transformation") {
        auto baseLabel = std::make_shared<SimpleLabel>("test");
        auto capitalize = TransformationFactory::createCapitalize();
        
        auto decorated = DecoratorFactory::createTextTransformationDecorator(baseLabel, capitalize);
        REQUIRE(decorated->getText() == "Test");
    }
    
    SECTION("createRandomTransformationDecorator applies one transformation randomly") {
        auto baseLabel = std::make_shared<SimpleLabel>("   test   ");
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            TransformationFactory::createCapitalize(),
            TransformationFactory::createLeftTrim(),
            TransformationFactory::createRightTrim()
        };
        
        auto decorated = DecoratorFactory::createRandomTransformationDecorator(baseLabel, transformations);
        std::string result = decorated->getText();
        std::cout << '|' << result << '|' << std::endl;

        std::vector<std::string> answers = {"test   ", "   test", "   Test   "};
        bool right = std::any_of(answers.begin(), answers.end(), [&result](const std::string& answer) {
            return result == answer;
        });
        
        REQUIRE(right == true);
    }
    
    SECTION("createCyclingTransformationsDecorator cycles through transformations") {
        auto baseLabel = std::make_shared<SimpleLabel>("  test  ");
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            TransformationFactory::createCapitalize(),
            TransformationFactory::createLeftTrim(),
            TransformationFactory::createRightTrim()
        };
        
        auto decorated = DecoratorFactory::createCyclingTransformationsDecorator(baseLabel, transformations);
        
        REQUIRE(decorated->getText() == "  Test  "); // First transformation: Capitalize
        REQUIRE(decorated->getText() == "Test  ");   // Second transformation: LeftTrim
        REQUIRE(decorated->getText() == "Test");     // Third transformation: RightTrim
        REQUIRE(decorated->getText() == "Test");     // Back to first: Capitalize (already capitalized)
    }
    
    SECTION("applyMultipleDecorators with text transformations") {
        auto baseLabel = std::make_shared<SimpleLabel>("  test  ");
        
        std::vector<std::string> decoratorTypes = {
            "textTransformation",
            "textTransformation",
            "textTransformation"
        };
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            TransformationFactory::createLeftTrim(),
            TransformationFactory::createRightTrim(),
            TransformationFactory::createCapitalize()
        };
        
        auto decorated = DecoratorFactory::applyMultipleDecorators(baseLabel, decoratorTypes, transformations);
        REQUIRE(decorated->getText() == "Test");
    }
    
    SECTION("applyMultipleDecorators with mixed decorators") {
        auto baseLabel = std::make_shared<SimpleLabel>("test");
        
        std::vector<std::string> decoratorTypes = {
            "textTransformation",
            "random"
        };
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            TransformationFactory::createDecorate(),
            TransformationFactory::createCapitalize(),
            TransformationFactory::createLeftTrim(),
            TransformationFactory::createRightTrim()
        };
        
        auto decorated = DecoratorFactory::applyMultipleDecorators(baseLabel, decoratorTypes, transformations);
        std::string result = decorated->getText();
        
        // First the text is decorated, then one random transformation is applied
        bool validResult = (
            result == "-={ test }=-" ||         // No change from random (unlikely)
            result == "-={ Test }=-" ||         // Capitalize
            result == "-={ test }=-" ||         // LeftTrim (no effect)
            result == "-={ test }=-"            // RightTrim (no effect)
        );
        REQUIRE(validResult);
    }
    
    SECTION("applyMultipleDecorators with cycling decorator") {
        auto baseLabel = std::make_shared<SimpleLabel>("  test  ");
        
        std::vector<std::string> decoratorTypes = {
            "cycling"
        };
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            TransformationFactory::createCapitalize(),
            TransformationFactory::createLeftTrim(),
            TransformationFactory::createRightTrim()
        };
        
        auto decorated = DecoratorFactory::applyMultipleDecorators(baseLabel, decoratorTypes, transformations);
        
        REQUIRE(decorated->getText() == "  Test  "); // First transformation: Capitalize
        REQUIRE(decorated->getText() == "Test  ");   // Second transformation: LeftTrim
        REQUIRE(decorated->getText() == "Test");     // Third transformation: RightTrim
    }
    
    SECTION("applyMultipleDecorators with invalid decorator type") {
        auto baseLabel = std::make_shared<SimpleLabel>("test");
        
        std::vector<std::string> decoratorTypes = {
            "invalid",
            "textTransformation"
        };
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {
            TransformationFactory::createCapitalize()
        };
        
        auto decorated = DecoratorFactory::applyMultipleDecorators(baseLabel, decoratorTypes, transformations);
        
        // The invalid decorator type should be skipped, but the valid one should still be applied
        REQUIRE(decorated->getText() == "Test");
    }
    
    SECTION("applyMultipleDecorators with empty transformations") {
        auto baseLabel = std::make_shared<SimpleLabel>("test");
        
        std::vector<std::string> decoratorTypes = {
            "textTransformation",
            "random",
            "cycling"
        };
        
        std::vector<std::shared_ptr<TextTransformation>> transformations = {};
        
        auto decorated = DecoratorFactory::applyMultipleDecorators(baseLabel, decoratorTypes, transformations);
        
        // No transformations should be applied since the vector is empty
        REQUIRE(decorated->getText() == "test");
    }
    
    SECTION("createTextTransformationDecorator preserves help text") {
        auto baseLabel = std::make_shared<SimpleLabel>("test", "Help info");
        auto capitalize = TransformationFactory::createCapitalize();
        
        auto decorated = DecoratorFactory::createTextTransformationDecorator(baseLabel, capitalize);
        REQUIRE(decorated->getText() == "Test");
        REQUIRE(baseLabel->hasHelpText());
        REQUIRE(baseLabel->getHelpText() == "Help info");
    }
}
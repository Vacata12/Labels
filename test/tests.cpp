#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "catch2/catch_test_macros.hpp"
#include "../Headers/RichLabel.h"
#include "../Headers/Capitalize.h"
#include "../Headers/LeftTrim.h"
#include "../Headers/RightTrim.h"
#include "../Headers/Censor.h"
#include "../Headers/Decorate.h"
#include "../Headers/NormalizeSpace.h"
#include "../Headers/Replace.h"
#include "../Headers/TextTransformationDecorator.h"
#include "../Headers/RandomTransformationDecorator.h"
#include "../Headers/CyclingTransformationsDecorator.h"
#include "../Headers/CompositeTransformation.h"

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
        TextTransformationDecorator leftTrimDecorator(label, leftTrim);
        TextTransformationDecorator rightTrimDecorator(std::make_shared<TextTransformationDecorator>(leftTrimDecorator), rightTrim);
        REQUIRE(rightTrimDecorator.getText() == "test");
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
}

#pragma once
#include <string>
#include <memory>
class Label {
protected:
public:
    Label() = default;
    virtual ~Label() = default;
    virtual std::string getText() = 0;
    virtual std::string getColor();
    virtual std::string getHelpText();
};
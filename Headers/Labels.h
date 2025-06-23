#pragma once
#include <string>
#include <memory>
#include "HelpText.h"
class Label {
protected:
    std::unique_ptr<HelpText> helpText;
public:
    Label() = default;
    virtual ~Label() = default;
    virtual std::string getText() const = 0;
    virtual std::string getColor() const;
    virtual std::string getHelpText() const;
};
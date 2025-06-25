#pragma once
#include <string>


class HelpTextImpl {
public:
    virtual ~HelpTextImpl() = default;
    virtual std::string getHelpText() const = 0;
};


class HelpText : public HelpTextImpl {
private:
    std::string helpText;
public:
    HelpText() : helpText("") {}
    explicit HelpText(const std::string& text) : helpText(text) {}
    ~HelpText() override = default;
    std::string getHelpText() const override { return helpText; }
};
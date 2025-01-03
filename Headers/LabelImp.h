#pragma once
#include <string>

class LabelImp {
private:
    std::string helpText = "";
public:
    LabelImp() = default;
    LabelImp(const std::string& helpText) : helpText(helpText) {}
    virtual ~LabelImp() = default;
    virtual std::string getHelpText() = 0;
};
#pragma once
#include <string>

class LabelImp {
protected:
    std::string helpText = "";
public:
    LabelImp() = default;
    virtual ~LabelImp() = default;
    virtual std::string getHelpText() = 0;
};
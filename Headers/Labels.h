#pragma once
#include "LabelImp.h"
#include <string>
#include <memory>
class Label {
protected:
    std::shared_ptr<LabelImp> labelImp = nullptr;
public:
    Label() = default;
    Label(std::shared_ptr<LabelImp> labelImp);
    virtual ~Label() = default;
    virtual std::string getText() = 0;
    virtual std::string getColor();
    virtual std::string getHelpText();
};
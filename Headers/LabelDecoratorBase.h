#pragma once
#include "../Headers/Labels.h"
#include <memory>

class  LabelDecoratorBase : public Label {
protected:
    std::shared_ptr<Label> label;
public:
    LabelDecoratorBase(std::shared_ptr<Label> label);
    ~LabelDecoratorBase() = default;
    std::string getText() const override;
};
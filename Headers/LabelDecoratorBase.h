#pragma once
#include "../Headers/Labels.h"
#include <memory>

class  LabelDecoratorBase : public Label {
protected:
    std::shared_ptr<Label> label;
public:
    LabelDecoratorBase(std::shared_ptr<Label> label);
    ~LabelDecoratorBase() = default;
    std::string getText() override;
    static std::shared_ptr<Label> removeDecorator(std::shared_ptr<Label> label, std::shared_ptr<LabelDecoratorBase> toRemove);
};
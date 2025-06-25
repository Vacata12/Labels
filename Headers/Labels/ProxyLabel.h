#pragma once
#include "SimpleLabel.h"
#include<memory>
#include <iostream>

class ProxyLabel : public Label {
    std::unique_ptr<Label> label;
    bool isLoad;
    bool timeout;
public:
    ProxyLabel();
    ~ProxyLabel() = default;
    void makeTimeout();
    std::string getText() const override;
private:
    void changeLabel();
};
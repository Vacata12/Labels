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
    std::string getText() override;
private:
    void changeLabel();
};
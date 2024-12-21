#pragma once
#include <string>
class Label {
public:
    virtual ~Label() = default;
    virtual std::string getText() const = 0;
};
#pragma once
#include <iostream>
#include <memory>
#include "../Labels/Labels.h"


class LabelFactory
{
private:
public:
    LabelFactory() = default;
    LabelFactory(const LabelFactory&) = delete;
    LabelFactory& operator=(const LabelFactory&) = delete;
    ~LabelFactory() = default;

    static std::unique_ptr<Label> createSimpleLabel(const std::string& text, const std::string& helptext);

    static std::unique_ptr<Label> createRichLabel(const std::string& text, const std::string& color, const std::string& helptext);

    static std::unique_ptr<Label> createProxyLabel(const std::string& text, const std::string& helptext);
};


#include "../../Headers/Factory/LabelFactory.h"
#include "../../Headers/Labels/SimpleLabel.h"
#include "../../Headers/Labels/RichLabel.h"
#include "../../Headers/Labels/ProxyLabel.h"

std::unique_ptr<Label> LabelFactory::createSimpleLabel(const std::string& text, const std::string& helptext) 
{
    return std::make_unique<SimpleLabel>(text, helptext);
}

std::unique_ptr<Label> LabelFactory::createRichLabel(const std::string& text, const std::string& color, const std::string& helptext)
{
    return std::make_unique<RichLabel>(text, color, helptext);
}

std::unique_ptr<Label> LabelFactory::createProxyLabel(const std::string& text, const std::string& helptext)
{
    return std::make_unique<ProxyLabel>();
}
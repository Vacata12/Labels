#include "../Headers/Labels.h"
#include "../Headers/HelpText.h"

Label::Label() : helpTextImpl(nullptr) {}

Label::Label(std::unique_ptr<HelpTextImpl> impl) : helpTextImpl(std::move(impl)) {}

std::string Label::getHelpText() const {
    if (!hasHelpText()) {
        return "";
    }
    return helpTextImpl->getHelpText();
}

void Label::setHelpText(std::unique_ptr<HelpTextImpl> impl) {
    helpTextImpl = std::move(impl);
}

// Helper function implementation
std::unique_ptr<HelpTextImpl> createHelpText(const std::string& text) {
    return std::make_unique<HelpText>(text);
}
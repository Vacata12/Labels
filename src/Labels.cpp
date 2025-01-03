#include "../Headers/Labels.h"
Label::Label(std::shared_ptr<LabelImp> labelImp) : labelImp(labelImp) {}
std::string Label::getColor() {
    return "";
}
std::string Label::getHelpText() {
    return "";
}
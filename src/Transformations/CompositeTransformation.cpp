#include "../../Headers/Transformations/CompositeTransformation.h"

CompositeTransformation::CompositeTransformation(const std::string& strTransformations)
{
    std::string newTransform = "";
    for(int i = 0; i < strTransformations.size(); i++) {
        if(strTransformations[i] == ' ') {
            createTransformations(newTransform);
            newTransform = "";
        }
        else {
            newTransform += strTransformations[i];
        }
    }
    createTransformations(newTransform);
}
std::string CompositeTransformation::transform(const std::string& text) const
{
    std::string transformedText = text;
    for(size_t i = 0; i < transforms.size(); i++) {
        transformedText = transforms[i]->transform(transformedText);
    }   
    return transformedText;
}

void CompositeTransformation::swithPlacesOfTransforms(size_t one, size_t two){
    std::shared_ptr<TextTransformation> tmp = transforms[one];
    transforms[one] = transforms[two];
    transforms[two] = tmp;
}

void CompositeTransformation::createTransformations(const std::string newTransform) {
    if(newTransform == "Capitalize") {
        transforms.push_back(std::make_shared<Capitalize>());
    }
    else if(newTransform == "LeftTrim") {
        transforms.push_back(std::make_shared<LeftTrim>());
    }
    else if(newTransform == "RightTrim") {
        transforms.push_back(std::make_shared<RightTrim>());
    }
    else if(newTransform == "NormalizeSpace") {
        transforms.push_back(std::make_shared<NormalizeSpace>());
    }
    else if(newTransform == "Decorate") {
        transforms.push_back(std::make_shared<Decorate>());
    }
    else if(newTransform.substr(0, 6) == "Censor") {
        std::string censorText = newTransform.substr(8, newTransform.size() - 1);
        transforms.push_back(std::make_shared<Censor>(censorText));
    }
    else if(newTransform.substr(0,7) == "Replace") {
        std::string replaceText = newTransform.substr(8, newTransform.size() - 1);
        std::string from = replaceText.substr(0, replaceText.find(","));
        std::string to = replaceText.substr(replaceText.length() - from.length() - 1, replaceText.length() - from.length() - 2);
        transforms.push_back(std::make_shared<Replace>(from, to));
    }
    else {
        throw std::invalid_argument("Invalid transformation");
    }
}
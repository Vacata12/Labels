#pragma once
#include "TextTransformation.h"
#include "Capitalize.h"
#include "LeftTrim.h"
#include "RightTrim.h"
#include "NormalizeSpace.h"
#include "Decorate.h"
#include "Censor.h"
#include "Replace.h"
#include <vector>
#include <memory>

class CompositeTransformation : public TextTransformation {
    std::vector<std::shared_ptr<TextTransformation> > transforms;
public:
    CompositeTransformation(const std::string& strTransformations);
    ~CompositeTransformation() = default;
    void swithPlacesOfTransforms(size_t one, size_t two);
    virtual std::string transform(const std::string& text) const;
private:
    void createTransformations(const std::string newTransform);
};
#include "../Headers/RandomTransformationDecorator.h"
#include <memory>


// I tried with std;:dynamic_cast but it gave me error: expected unqualified-id :'(
void RandomTransformationDecorator::generateTransformation() {
    if (this->transforms.empty()) {
        this->transforms.push_back(std::make_shared<Capitalize>());
    }
    else {
        bool done = false;
        while(!done) {
            uint8_t randT = std::rand() % 6;
            switch (randT)
            {
            case 0:
                if(typeid(transforms.back()) == typeid(Capitalize)) {
                    break;
                }
                else {
                    this->transforms.push_back(std::make_shared<Capitalize>());
                    done = true;
                }
                break;
            case 1:
                if(typeid(transforms.back()) == typeid(LeftTrim)) {
                    break;
                }
                else {
                    this->transforms.push_back(std::make_shared<LeftTrim>());
                    done = true;
                }
                break;
            case 2:
                if(typeid(transforms.back()) == typeid(RightTrim)) {
                    break;
                }
                else {
                    this->transforms.push_back(std::make_shared<RightTrim>());
                    done = true;
                }
                break;
            case 3:
                if(typeid(transforms.back()) == typeid(NormalizeSpace)) {
                    break;
                }
                else {
                    this->transforms.push_back(std::make_shared<NormalizeSpace>());
                    done = true;
                }
                break;
            case 4:
                if(typeid(transforms.back()) == typeid(Censor)) {
                    break;
                }
                else {
                    this->transforms.push_back(std::make_shared<Censor>("abc"));
                    done = true;
                }
                break;
            case 5:
                if(typeid(transforms.back()) == typeid(Replace)) {
                    break;
                }
                else {
                    this->transforms.push_back(std::make_shared<Replace>("a", "b"));
                    done = true;
                }
                break;
            default:
                break;
            }
        }
    }
}
RandomTransformationDecorator::RandomTransformationDecorator(std::shared_ptr<Label> label) : LabelDecoratorBase(label) {
}

std::string RandomTransformationDecorator::getText() {
    generateTransformation();
    return this->transforms.back()->transform(this->label->getText());
}
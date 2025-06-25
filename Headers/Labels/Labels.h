#pragma once
#include <string>
#include <memory>
#include "HelpText.h"

// Forward declaration
class HelpTextImpl;

class Label {
protected:
    std::unique_ptr<HelpTextImpl> helpTextImpl;
    
public:
    Label();
    explicit Label(std::unique_ptr<HelpTextImpl> impl);
    virtual ~Label() = default;
    
    virtual std::string getText() const = 0;
    virtual std::string getColor() const { return "black"; }  // Default color
    
    // Help text related methods
    virtual bool hasHelpText() const { return helpTextImpl != nullptr; }
    virtual std::string getHelpText() const;
    virtual void setHelpText(std::unique_ptr<HelpTextImpl> impl);
};

// Helper function to create a help text implementation
std::unique_ptr<HelpTextImpl> createHelpText(const std::string& text = "");
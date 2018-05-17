#ifndef DYNAMICTEXTBOX_H_INCLUDED
#define DYNAMICTEXTBOX_H_INCLUDED

#include <vector>
#include "base/item.h"
#include "base/conststring.h"
#include "elements/keycodes.h"
#include "text.h"

/**
 class DynamicTextbox - a basic textbox.
*/

namespace gui
{

class DynamicTextbox: Item
{
protected:
    std::string keyBuffer;
    ConstString resetText;
    Text text;

public:
    DynamicTextbox(float x, float y, float width, float height, std::string startText,
                   WindowRef window);

    void update();

    virtual void display() const override;

    void send(sf::Event& tosend);
};

} // namespace gui

#endif // DYNAMICTEXTBOX_H_INCLUDED

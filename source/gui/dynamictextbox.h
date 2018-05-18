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

class DynamicTextbox: public Item
{
protected:
    unsigned int cursorX;
    float textSize;
    ConstString resetText;
    Text text;

    void updateCursor();
    bool textIsInBox(char extraCharacter);
    void type(char character);

public:
    DynamicTextbox(float x, float y, float chars, float lines, float charHeight,
                   std::string startText, WindowRef window);


    virtual sf::Vector2f getBGSize() const;
    virtual void display() const override;

    void send(sf::Event& tosend);

    std::string getText();
};

} // namespace gui

#endif // DYNAMICTEXTBOX_H_INCLUDED

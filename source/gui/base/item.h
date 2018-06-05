#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../elements/typedefs.h"

namespace gui{
namespace base{

/** \brief A basic item class. Contains X/Y/width/height along with basic
 * setters/getters, some helpful typedefs, and a pure-virtual draw method
 */

// Documentation for every method is in the implementation file. I like to keep my
// definitions decently brief and easy to traverse.
class Item
{
protected:
    // All items will be square based
    float x, y, width, height;

    // The main window pointer. Needed for drawing
    WindowPtr window;

    // Just for child classes to set properties easier.
    void setRectInfo(__RECTINFO, WindowRef window);

    // constant (r)eference to sf::(Vector2f)
    typedef const sf::Vector2f& rVector2f;
    // (c)onstant (float)
    typedef const float cFloat;

public:
    // Getter methods for X/Y and width/height. Doing it like SFML does to make
    // rendering easier.
    virtual sf::Vector2f getPos() const;
    virtual sf::Vector2f getSize() const;

    // Changes the X and Y. Overloaded to use a sf::Vector or two floats.
    void setPos(rVector2f to);
    void setPos(cFloat newX, cFloat newY);

    // Changes the X. Takes the X element out of the sf::Vector if given
    void setX(rVector2f to);
    void setX(cFloat newX);

    // Changes the Y. Takes the Y element out of the sf::Vector if given
    void setY(rVector2f to);
    void setY(cFloat newY);

    // Changes the width and height. Overloaded to use a sf::Vector or two floats.
    void setSize(rVector2f to);
    void setSize(cFloat newwidth, cFloat newheight);

    // Changes the width. Takes the X element out of the sf::Vector if given
    void setWidth(rVector2f to);
    void setWidth(cFloat newwidth);

    // Changes the height. Takes the Y element out of the sf::Vector if given
    void setHeight(rVector2f to);
    void setHeight(cFloat newheight);

    // Making it a pure virtual method. Children classes must implement themselves.
    virtual void draw() const = 0;

    // Child classes can redefine if they need to do anything extra on resize/
    // reposition.
    virtual void handleNewSize(rVector2f newSize){};
    virtual void handleNewPosition(rVector2f newPos){};
};

} // namespace base
} // namespace gui

#endif // ITEM_H_INCLUDED

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <SFML/Graphics.hpp>

/**
class Item - abstract class representing a GUI item

Protected Properties:
    -> float x
        X position of some item
    -> float y
        Y position of some item
    -> float width
        width of some item
    -> float height
        height of some item
    -> sf::RectangleShape rect
        actual rectangle representing prev. properties
    -> sf::RenderWindow* window
        Holds a window to render to


Protected Methods:
    -> virtual void display()
        pure virtual method that must be defined by children classes.
    -> void setrect(float x, y, width, height, sf::RenderWindow& window)
        First four arguments are floats. Simply sets the corresponding properties in the
        class.


Public Getter Methods:
    -> sf::Vector2f getPos()
        get's the X and Y properties zipped together in a sf::Vector2f
    -> sf::Vector2f getSize()
        get's the width and height properties zipped together in a sf::Vector2f


Public Setter Methods:
    -> setPos(sf::Vector2f to)
    -> setPos(float newx, float newy)
        Set the X and Y. Can take either two floats or a sf::Vector2f
    -> setX(sf::Vector2f to)
    -> setX(float newx)
        Set the X. Will take the X element out of a sf::Vector
    -> setY(sf::Vector2f to)
    -> setY(float newy)
        Set the Y. Will take the Y element out of a sf::Vector

    -> setSize(sf::Vector2f to)
    -> setSize(float newwidth, float newheight)
        Set the width and height. Can take either two floats or a sf::Vector2f
    -> setWidth(sf::Vector2f to)
    -> setWidth(float newwidth)
        Set the width. Will take the X element out of a sf::Vector
    -> setHeight(sf::Vector2f to)
    -> setHeight(float newheight)
        Set the height. Will take the Y element out of a sf::Vector


Public Methods:
    -> void setRectColor(sf::Color color)
    -> void setRectColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        Set the rect color with an sf::Color or RGBA (alpha defaulting to 255).
        If you don't want a it to be visible, set the alpha to 0 and it will be
        just fine.
*/

namespace gui
{

// The base class of all GUI objects.
class Item
{
protected:
    // All items will be square based
    float x, y, width, height;

    // The default rectangle
    sf::RectangleShape rect;

    // The main window pointer. Needed for displaying
    sf::RenderWindow* window;

    // Just for child classes to set properties easier.
    void setrect(float x, float y, float width, float height,
                 sf::RenderWindow& window);


public:
    // Getter methods for X/Y and width/height. Doing it like SFML does to make
    // rendering easier.
    sf::Vector2f getPos();
    sf::Vector2f getSize();

    // Changes the X and Y. Overloaded to use a sf::Vector or two floats.
    void setPos(sf::Vector2f to);
    void setPos(float newx, float newy);

    // Changes the X. Takes the X element out of the sf::Vector if given
    void setX(sf::Vector2f to);
    void setX(float newx);

    // Changes the Y. Takes the Y element out of the sf::Vector if given
    void setY(sf::Vector2f to);
    void setY(float newy);

    // Changes the width and height. Overloaded to use a sf::Vector or two floats.
    void setSize(sf::Vector2f to);
    void setSize(float newwidth, float newheight);

    // Changes the width. Takes the X element out of the sf::Vector if given
    void setWidth(sf::Vector2f to);
    void setWidth(float newwidth);

    // Changes the height. Takes the Y element out of the sf::Vector if given
    void setHeight(sf::Vector2f to);
    void setHeight(float newyheight);

    // Making it a virtual method. Children classes can implement themselves.
    virtual void display();
};

} // namespace gui

#endif // ITEM_H_INCLUDED

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <SFML/Graphics.hpp>

/**
class Item - abstract class representing a GUI item

Protected Attributes:
    -> float x
        X position of some item
    -> float y
        Y position of some item
    -> float width
        width of some item
    -> float height
        height of some item

Protected Methods:
    -> virtual void display()
        pure virtual method that must be defined by children classes.
    -> void setrect(float x, y, width, height)
        All arguments are floats. Simply sets the corresponding attributes in the class.

Public Getter Methods:
    -> sf::Vector2f getPos()
        get's the X and Y attributes zipped together in a sf::Vector2f
    -> sf::Vector2f getSize()
        get's the width and height attributes zipped together in a sf::Vector2f
*/

// The base class of all GUI objects.
class Item
{
protected:
    // All items will be square based
    float x, y, width, height;

    // Making it a pure virtual method. Children classes will have to implement
    // themselves.
    virtual void display() = 0;

    // Just for child classes to set properties easier.
    void setrect(float x, float y, float width, float height);

public:
    // Getter methods for X/Y and width/height. Doing it like SFML does to make
    // rendering easier.
    sf::Vector2f getPos();
    sf::Vector2f getSize();
};

#endif // ITEM_H_INCLUDED

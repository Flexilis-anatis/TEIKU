#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "base/item.h"
#include <string>

/**
Class Image - semi abstract class representing a GUI item that displays an image

Protected attributes:
    -> sf::Texture* texture
        Holds a loaded image
    -> sf::RectangleShape rect
        Holds a rectangle. Texture's host

Public Methods:
    -> void setup(std::string texturefilename, sf::RenderWindow* window)
        loads the texture, puts the texture into the rectangle, and sets the window
        attribute.
    -> virtual bool update()
        Can be used by children classes for updating more complex GUI items. By default,
        just calls display() and returns false.
    -> void display()
        displays the rectangle on to the window.

Public Setter Methods:
    -> setpos(sf::Vector2f to)
    -> setpos(float newx, float newy)
        Set the X and Y. Can take either two floats or a sf::Vector2f
    -> setx(sf::Vector2f to)
    -> setx(float newx)
        Set the X. Will take the X element out of a sf::Vector
    -> sety(sf::Vector2f to)
    -> sety(float newy)
        Set the Y. Will take the Y element out of a sf::Vector

    -> setsize(sf::Vector2f to)
    -> setsize(float newwidth, float newheight)
        Set the width and height. Can take either two floats or a sf::Vector2f
    -> setwidth(sf::Vector2f to)
    -> setwidth(float newwidth)
        Set the width. Will take the X element out of a sf::Vector
    -> setheight(sf::Vector2f to)
    -> setheight(float newheight)
        Set the height. Will take the Y element out of a sf::Vector
*/

// Possibly the base class of buttons, for instance. But certainly useful for other
// purposes
class Image : pulbic Item
{
protected:
    // This will hold the image. You can easily go texture.loadFromFile to load most
    // images, and then you can set the rectangles texture to it. You have to keep a
    // pointer to it alive though, or it won't work.
    sf::Texture* texture;

    // The host for the texture
    sf::RectangleShape rect;

    // The main window pointer. Needed for displaying
    sf::RenderWindow* window.

public:
    // set everything up. Needs a render window pointer and the filename of an image
    void setup(std::string texturefilename, sf::RenderWindow* window);

    // Since this is the lowest level GUI class that will be used as a standalone, need a
    // placeholder constructor
    Image(){}

    // The base implementation will call Image::display() and return false, but it can be
    // repurposed for things like buttons.
    virtual bool update();

    // Just displays the rectangle and exits.
    void display();

    /// Get ready for a ton of setters! Woo hoo! ///

    /* X/Y setters */
    // Changes the X and Y. Overloaded to use a sf::Vector or two floats.
    void setpos(sf::Vector2f to);
    void setpos(float newx, float newy);

    /* X individual setters */
    // Just changes the X. Takes the X element out of the sf::Vector if given
    void setx(sf::Vector2f to);
    void setx(float newx);

    /* Y individual setters */
    // Just changes the Y. Takes the Y element out of the sf::Vector if given
    void sety(sf::Vector2f to);
    void sety(float newy);

    /// Now we get to do it all again! Yay! ///

    /* width/height setters */
    // Changes the width and height. Overloaded to use a sf::Vector or two floats.
    void setsize(sf::Vector2f to);
    void setsize(float newwidth, float newheight);

    /* width individual setters */
    // Just changes the width. Takes the X element out of the sf::Vector if given
    void setwidth(sf::Vector2f to);
    void setwidth(float newwidth);

    /* height individual setters */
    // Just changes the height. Takes the Y element out of the sf::Vector if given
    void setheight(sf::Vector2f to);
    void setheight(float newyheight;
};


#endif // IMAGE_H_INCLUDED

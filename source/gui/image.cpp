#include "image.h"


/* Basically a constructor, just designed so it can be easily called by child classes.
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename, sf::RenderWindow* window)
 *      loads the texture, puts the texture into the rectangle, and sets the window
 *      attribute. Note this MUST BE CALLED AFTER Item::setrect
*/

void Image::setup(std::string texturefilename, sf::RenderWindow* window)
{
    // Loading texture
    if (!texture->loadFromFile(texturefilename))
    {
        // error opening file. Might just throw an exception
        return;
    }

    // Setting rectangles texture
    rect.setTexture(texture);

    // Setting position/size of rect
    rect.setPosition(getPos());
    rect.setSize(getSize());

    // Saving render window
    this->window = window;
}


/* Can be used by children classes for more complex behavior.
 * From image.h docs:
 *
 *  -> virtual bool update()
 *      Can be used by children classes for updating more complex GUI items. By default,
 *      just calls display() and returns false.
*/

bool Image::update()
{
    display();
    return false;
}

/* Displays the rectangle on the render window.
 * From image.h docs:
 *
 *  -> void display()
 *      displays the rectangle on to the window.
*/

void Image::display()
{
    window->draw(rect);
}


/* Set's the position of the rectangle.
 * From image.h docs:
 *
 * -> setpos(sf::Vector2f to)
 * -> setpos(float newx, float newy)
 *      Set the X and Y. Can take either two floats or a sf::Vector2f
*/

void Image::setpos(sf::Vector2f to)
{
    rect.setPosition(to);
}

void Image::setpos(float newx, float newy)
{
    setpos(sf::Vector2f(newx, newy));
}


/* Set's the X position of the rectangle.
 * from image.h docs:
 *
 * -> setx(sf::Vector2f to)
 * -> setx(float newx)
 *      Set the X. Will take the X element out of a sf::Vector
*/

void Image::setx(sf::Vector2f to)
{
    setpos(to.x, y);
}

void Image::setx(float newx)
{
    setpos(newx, y);
}


/* Set's the Y position of the rectangle.
 * from image.h docs:
 *
 * -> sety(sf::Vector2f to)
 * -> sety(float newy)
 *      Set the Y. Will take the Y element out of a sf::Vector
*/

void Image::sety(sf::Vector2f to)
{
    setpos(x, to.y);
}

void Image::sety(float newy)
{
    setpos(x, newy);
}


/// END POSITION SETTERS, START SIZE SETTERS ///


/* Set's the size of the rectangle.
 * From image.h docs:
 *
 * -> setsize(sf::Vector2f to)
 * -> setsize(float newwidth, float newheight)
 *      Set the width and height. Can take either two floats or a sf::Vector2f
*/

void Image::setsize(sf::Vector2f to)
{
    rect.setSize(to);
}

void Image::setsize(float newx, float newy)
{
    setsize(sf::Vector2f(newx, newy));
}


/* Set's the width of the rectangle.
 * from image.h docs:
 *
 * -> setwidth(sf::Vector2f to)
 * -> setwidth(float newwidth)
 *      Set the width. Will take the X element out of a sf::Vector
*/

void Image::setwidth(sf::Vector2f to)
{
    setsize(to.x, height);
}

void Image::setwidth(float newwidth)
{
    setsize(newwidth, height);
}


/* Set's the height of the rectangle.
 * from image.h docs:
 *
 * -> setheight(sf::Vector2f to)
 * -> setheight(float newheight)
 *      Set the height. Will take the Y element out of a sf::Vector
*/

void Image::setheight(sf::Vector2f to)
{
    setsize(width, to.y);
}

void Image::setheight(float newheight)
{
    setsize(width, newheight);
}


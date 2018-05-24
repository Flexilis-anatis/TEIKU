#include "item.h"

namespace gui
{

/* Protected method setrect.
 * From item.h docs:
 *
 *  -> void setrect(float x, y, width, height)
 *      All arguments are floats. Simply sets the corresponding
 *      properties in the class.
*/

void Item::setrect(RectInfo, WindowRef window)
{
    // References 'this' to avoid naming conflict
    this->x         = RIx;
    this->y         = RIy;
    this->width     = RIwidth;
    this->height    = RIheight;
    this->window    = &window;

    // Setting position/size of rect
    rect.setPosition(this->getPos());
    rect.setSize(this->getSize());

    // Setting alpha to 0 by default to make it invisible, but only if
    // it doesn't have a texture
    if (rect.getTexture() == nullptr)
    {
        rect.setFillColor(sf::Color(0, 0, 0, 0));
    }
}


/* Get the position of the object.
 * From item.h docs:
 *
 *  -> sf::Vector2f getPos()
 *      get's the X and Y properties zipped together in a sf::Vector2f
*/

sf::Vector2f Item::getPos() const
{
    return sf::Vector2f(x, y);
}


/* Get the size of an object.
 * From item.h docs:
 *
 *  -> sf::Vector2f getSize()
 *      get's the width and height properties zipped together in a
 *      sf::Vector2f
*/

sf::Vector2f Item::getSize() const
{
    return sf::Vector2f(width, height);
}

/* Set's the position of the rectangle.
 * From item.h docs:
 *
 * -> setPos(sf::Vector2f to)
 * -> setPos(float newx, float newy)
 *      Set the X and Y. Can take either two floats or a sf::Vector2f
*/

void Item::setPos(sf::Vector2f to)
{
    // All position setters call this method, so I only need to reset
    // X/Y here. Same with the setSize method down below.
    rect.setPosition(to);
    x = to.x;
    y = to.y;
}

void Item::setPos(float newx, float newy)
{
    setPos(sf::Vector2f(newx, newy));
}


/* Set's the X position of the rectangle.
 * From item.h docs:
 *
 * -> setX(sf::Vector2f to)
 * -> setX(float newx)
 *      Set the X. Will take the X element out of a sf::Vector
*/

void Item::setX(sf::Vector2f to)
{
    setPos(to.x, y);
}

void Item::setX(float newx)
{
    setPos(newx, y);
}


/* Set's the Y position of the rectangle.
 * from i.h docs:
 *
 * -> setY(sf::Vector2f to)
 * -> setY(float newy)
 *      Set the Y. Will take the Y element out of a sf::Vector
*/

void Item::setY(sf::Vector2f to)
{
    setPos(x, to.y);
}

void Item::setY(float newy)
{
    setPos(x, newy);
}


/// END POSITION SETTERS, START SIZE SETTERS ///


/* Set's the size of the rectangle.
 * From item.h docs:
 *
 * -> setSize(sf::Vector2f to)
 * -> setSize(float newwidth, float newheight)
 *      Set the width and height. Can take either two floats or a
 *      sf::Vector2f
*/

void Item::setSize(sf::Vector2f to)
{
    rect.setSize(to);
    x = to.x;
    y = to.y;
}

void Item::setSize(float newx, float newy)
{
    setSize(sf::Vector2f(newx, newy));
}


/* Set's the width of the rectangle.
 * from item.h docs:
 *
 * -> setWidth(sf::Vector2f to)
 * -> setWidth(float newwidth)
 *      Set the width. Will take the X element out of a sf::Vector
*/

void Item::setWidth(sf::Vector2f to)
{
    setSize(to.x, height);
}

void Item::setWidth(float newwidth)
{
    setSize(newwidth, height);
}


/* Set's the height of the rectangle.
 * from item.h docs:
 *
 * -> setHeight(sf::Vector2f to)
 * -> setHeight(float newheight)
 *      Set the height. Will take the Y element out of a sf::Vector
*/

void Item::setHeight(sf::Vector2f to)
{
    setSize(width, to.y);
}

void Item::setHeight(float newheight)
{
    setSize(width, newheight);
}


/* Set's the rectangles  color.
 * from item.h docs:
 *
 *  -> setRectColor(sf::Color color)
 *  -> setRectColor(RGBA red, RGBA green, RGBA blue, RGBA alpha = 255)
 *       Sets the rectangles color
 */

 void Item::setRectColor(sf::Color color)
 {
     rect.setFillColor(color);
 }

 void Item::setRectColor(RGBA red, RGBA green, RGBA blue, RGBA alpha)
 {
     setRectColor(sf::Color(red, green, blue, alpha));
 }

/* Displays the rectangle.
 * From item.h docs:
 *  -> void display()
 *      displays the rectangle on to the window.
*/

void Item::display() const
{
    window->draw(rect);
}

} // namespace gui

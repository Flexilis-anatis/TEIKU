#include "item.h"


/* Protected method setrect. Taken from item.h docs:
 *
 *  -> void setrect(float x, y, width, height)
 *      All arguments are floats. Simply sets the corresponding attributes in the class.
*/

void Item::setrect(float x, float y, float width, float height)
{
    // References 'this' to avoid naming conflict
    this->x         = x;
    this->y         = y;
    this->width     = width;
    this->height    = height;
}


/* Get the position of the object. Taken from item.h docs:
 *
 *  -> sf::Vector2f getPos()
 *      get's the X and Y attributes zipped together in a sf::Vector2f
*/

sf::Vector2f Item::getPos()
{
    return sf::Vector2f(x, y);
}


/* Get the size of an object. Taken from item.h docs:
 *
 *  -> sf::Vector2f getSize()
 *      get's the width and height attributes zipped together in a sf::Vector2f
*/

sf::Vector2f Item::getSize()
{
    return sf::Vector2f(width, height);
}

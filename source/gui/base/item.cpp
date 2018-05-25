#include "item.h"

namespace gui{
namespace base{

/** \brief Base rectangle/window setup
 *
 * \param const float RI_x/RI_y/RI_width/RI_height - the position and size of the
 *        rectangle
 * \param const sf::RenderWindow& window - a window to draw to
 *
 * \return Nothing
 */

void Item::setRectInfo(__RECTINFO, WindowRef window)
{
    // References 'this' to avoid naming conflict
    this->x      = RI_x;
    this->y      = RI_y;
    this->width  = RI_width;
    this->height = RI_height;
    this->window = &window;
}

/** \brief Get the position of the rectangle in a sf::Vector2f
 *
 * \return X/Y of object (sf::Vector2f)
 */

sf::Vector2f Item::getPos() const
{
    return sf::Vector2f(x, y);
}


/** \brief Get the size of the rectangle in a sf::Vector2f
 *
 * \return width/height of object (sf::Vector2f)
 */

sf::Vector2f Item::getSize() const
{
    return sf::Vector2f(width, height);
}


/** \brief Set the position of the rectangle
 *
 * \param const float newX - the new x to set the rectangle to
 * \param const float newY - the new y to set the rectangle to
 * \return Nothing
 */

void Item::setPos(cFloat newX, cFloat newY)
{
    setPos(sf::Vector2f(newX, newY));
}


/** \brief Set the position of the rectangle
 *
 * \param const sf::Vector2f& to - the position to move to
 * \return Nothing
 */

void Item::setPos(const sf::Vector2f& to)
{
    // All position setters call this method, so I only need to reset
    // X/Y here. Same with the setSize method down below.

    // This can be defined by children classes if they have anything extra they
    // need to do
    handleNewPosition(to);

    x = to.x;
    y = to.y;
}


/** \brief Set the X position of the rectangle
 *
 * \param const sf::Vector2f& to - the X value of the vector is used
 * \return Nothing
 */

void Item::setX(rVector2f to)
{
    setPos(to.x, y);
}


/** \brief Set the X position of the rectangle
 *
 * \param const float newX - the X position to set the rectangle to
 * \return Nothing
 */

void Item::setX(cFloat newX)
{
    setPos(newX, y);
}


/** \brief Set the Y position of the rectangle
 *
 * \param const sf::Vector2f& to - the Y value of the vector is used
 * \return Nothing
 */

void Item::setY(rVector2f to)
{
    setPos(x, to.y);
}


/** \brief Set the Y position of the rectangle
 *
 * \param const float newY - the Y position to set the rectangle to
 * \return Nothing
 */

void Item::setY(cFloat newY)
{
    setPos(x, newY);
}


/// END POSITION SETTERS, START SIZE SETTERS ///


/** \brief Set the width and height of the item
 *
 * \param const sf::Vector2f to - the width/height to set
 * \return Nothing
 */

void Item::setSize(rVector2f to)
{
    handleNewSize(to);
    x = to.x;
    y = to.y;
}


/** \brief Set the width and height of the item
 *
 * \param const float newWidth - the new width to set to the rectangle
 * \param const float newHeight - the new height to set to the rectangle
 * \return Nothing
 */

void Item::setSize(cFloat newWidth, cFloat newHeight)
{
    setSize(sf::Vector2f(newWidth, newHeight));
}


/** \brief Set the width of the item
 *
 * \param const sf::Vector2f& to - takes the X value out of the vector
 * \return Nothing
 */

void Item::setWidth(rVector2f to)
{
    setSize(to.x, height);
}


/** \brief Set the width of the item
 *
 * \param const float newWidth - the new width to set to the rectangle
 * \return Nothing
 */

void Item::setWidth(cFloat newWidth)
{
    setSize(newWidth, height);
}


/** \brief Set the height of the item
 *
 * \param const sf::Vector2f& to - takes the Y value out of the vector
 * \return Nothing
 */

void Item::setHeight(rVector2f to)
{
    setSize(width, to.y);
}


/** \brief Set the height of the item
 *
 * \param const float newHeight - the new width to set to the rectangle
 * \return Nothing
 */

void Item::setHeight(cFloat newHeight)
{
    setSize(width, newHeight);
}

} // namespace base
} // namespace gui

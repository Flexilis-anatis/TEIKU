#include "rectitem.h"

namespace gui{
namespace base{

/** \brief Quasi-constructor. Sets up rectangle with X/Y/width/height from __RECTINFO
 *
 * \param const float RI_x/RI_y/RI_width/RI_height - the main four parameters of the rect
 * \param sf::RenderWindow& window - the window to draw to
 * \return
 */

void RectItem::setRect(__RECTINFO, WindowRef window)
{
    setRectInfo(RI_x, RI_y, RI_width, RI_height, window);

    rect.setSize(sf::Vector2f(RI_width, RI_height));
    rect.setPosition(sf::Vector2f(RI_x, RI_y));
}


/** \brief Displays the rectangle
 * \return Nothing
 */

void RectItem::draw() const
{
    window->draw(rect);
}


/** \brief Called by gui::base::Item's size setters. Can perform extra actions on resize
 *
 * \param const sf::Vector2f& newSize - the new size to change to
 * \return Nothing
 */

void RectItem::handleNewSize(rVector2f newSize)
{
    rect.setSize(newSize);
}


/** \brief Called by gui::base::Item's position setters. Can perform extra actions on
 * reposition.
 *
 * \param const sf::Vector2f& newPos - the new position to move to
 * \return Nothing
 */

void RectItem::handleNewPosition(rVector2f newPos)
{
    rect.setPosition(newPos);
}

} // namespace base
} // namespace gui

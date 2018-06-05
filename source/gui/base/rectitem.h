#ifndef RECTITEM_H_INCLUDED
#define RECTITEM_H_INCLUDED

#include "item.h"

namespace gui{
namespace base{

// Should only be used for children classes, even though it technically isn't a
// pure-virtual class
class RectItem: protected Item
{
protected:
    // The rectangle shape this whole class is based on
    sf::RectangleShape rect;

    // Calls setRectInfo, then sets up the actual rectangle
    void setRect(__RECTINFO, WindowRef window);

    // Displays the rectangle
    virtual void draw() const override;

    // Updates rectangle along with X/Y positions
    virtual void handleNewSize(rVector2f newSize) override;
    virtual void handleNewPosition(rVector2f newPos) override;
};

} // namespace base
} // namespace gui

#endif // RECTITEM_H_INCLUDED

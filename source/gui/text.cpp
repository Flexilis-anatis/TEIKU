#include "text.h"

namespace gui
{

Text::Text(sf::Vector2f position, std::string text, WindowRef window)
{
    setrect(position.x, position.y, 0, 0, window);
}

void Text::display() const
{
    // pass
}

}

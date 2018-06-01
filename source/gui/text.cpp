#include "text.h"

namespace gui{

Text::Text(const sf::Vector2f& position, const string& text, WindowRef window)
{
    setRectInfo(position.x, position.y, 0, 0, window);
}

void Text::display() const
{
    // pass
}

} // namespace gui

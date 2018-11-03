#include "text.h"

#include <iostream> // testing

namespace gui{

Text::Text(const sf::Vector2f& position, WindowRef window, unsigned int fontSize, const string& text)
: TextGroup("resources\\monospace.ttf", fontSize)
{
    setRectInfo(position.x, position.y, 0, 0, window);

    // Inserting inital text, if it exists.
    if (text.size()) insert(text, 0, 0);
}

void Text::draw() const
{
    for (const sf::Text& text: textLines)
        window->draw(text);
}

void Text::updateText()
{
    unsigned int line=0;
    for (sf::Text& text: textLines)
        text.setPosition(x, y+line++*30);
}

} // namespace gui

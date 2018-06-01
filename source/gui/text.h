#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "base/rectitem.h"
#include "textgroup.h"

namespace gui
{

class Text: public base::RectItem
{
    sf::Font font;
    text::TextGroup text;

public:
    Text(const sf::Vector2f& position, const string& text, WindowRef window);
    void display() const override;
};

}

#endif // TEXT_H_INCLUDED

#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "base/item.h"

namespace gui
{

class Text: public Item
{
    sf::Font font;
    sf::Text text;

public:
    Text(sf::Vector2f position, std::string text, WindowRef window);
    void display() const override;
};

}

#endif // TEXT_H_INCLUDED

#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "base/rectitem.h"
#include "textgroup.h"

namespace gui
{

class Text: public text::TextGroup, public base::RectItem
{
protected:
    virtual void updateText() override;

public:
    Text(const sf::Vector2f& position, WindowRef window, const string& text = "",
         unsigned int fontSize=30, const string font = "resources/monospace.ttf");
    virtual void draw() const override;
};

}

#endif // TEXT_H_INCLUDED

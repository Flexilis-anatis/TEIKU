#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "base/rectitem.h"
#include "textgroup.h"

namespace gui
{

class Text: public base::RectItem, public text::TextGroup
{
protected:
    text::TextGroup text;
    virtual void updateText() override;

public:
    Text(const sf::Vector2f& position, WindowRef window, const string& text = "");
    virtual void draw() const override;
};

}

#endif // TEXT_H_INCLUDED

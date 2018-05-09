#include "text.h"

namespace gui
{

/* A partial constructor, taking care of the font and window. Must come after setrect.
 * From text.h docs:
 *
 *  -> void setup(std::string fontfilename, sf::RenderWindow* window)
 *      Loads the font and sets the window property.
*/

void Text::setup(std::string fontfilename, sf::RenderWindow* window)
{
    // Tries to load font. The if statement will only trigger if it fails
    if (!font.loadFromFile(fontfilename))
    {
        // Again, need some sort of error handling
        return;
    }

    this->window = window;
}


/* Sets the text, defaults text color and calls setrect/setup.
 *
 * From base/item.h docs:
 *
 *  -> void setrect(float x, y, width, height)
 *      All arguments are floats. Simply sets the corresponding properties in the
 *      class.
 *
 * From text.h docs:
 *
 *  -> void setup(std::string fontfilename, sf::RenderWindow* window)
 *      Loads the font and sets the window property.
*/

Text::Text(float x, float y, float width, float height, std::string text,
           std::string fontfilename, sf::RenderWindow* window)
{
    // Calling setup methods
    setrect(x, y, width, height);
    setup(fontfilename, window);

    // Defaulting text color
    textcolor = sf::Color(0,   0,   0);

    // Setting text
    rawText = text;
}


/* Set the text's color.
 * Taken from text.h docs:
 *
 *  -> void setTextColor(sf::Color color)
 *  -> void setTextColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
 *      Set the textcolor property with an sf::Color or RGBA (alpha defaulting to 255)
*/

void Text::setTextColor(sf::Color color)
{
    textcolor = color;
}

void Text::setTextColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    // Unlike the setter methods - which I hopefully shouldn't need to reuse all that
    // often - this doesn't call the other method as to avoid copying the sf::Color object.
    textcolor = sf::Color(red, green, blue, alpha);
}


/* Displays the background/text.
 * Taken from text.h docs:
 *
 *  -> void display()
 *      Display the background and text
*/

void Text::display()
{
    window->draw(rect);

    sf::Text text = sf::Text(rawText, font, height-2);
    text.setPosition(x, y);
    text.setFillColor(textcolor);

    window->draw(text);
}

} // namespace gui

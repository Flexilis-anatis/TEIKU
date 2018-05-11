#include "text.h"

namespace gui
{

/* A partial constructor, taking care of the font and window. Must come after setrect.
 * From text.h docs:
 *
 *  -> void setup(std::string fontfilename)
 *      Loads the font.
*/

void Text::setup(std::string fontfilename)
{
    // Tries to load font. The if statement will only trigger if it fails
    if (!font.loadFromFile(fontfilename))
    {
        // Again, need some sort of error handling
        return;
    }
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
 *  -> void setup(std::string fontfilename)
 *      Loads the font.
*/

Text::Text(float x, float y, float width, float height, std::string text,
           std::string fontfilename, sf::RenderWindow& window)
{
    // Calling setup methods
    setrect(x, y, width, height, window);
    setup(fontfilename);

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


/* Set the rectangle's color.
 * From text.h docs:
 *
 *  -> void setRectColor(sf::Color color)
 *  -> void setRectColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
 *      Set the rect color with an sf::Color or RGBA (alpha defaulting to 255).
 *      If you don't want a it to be visible, set the alpha to 0 and it will be
 *      just fine.
*/

void Text::setRectColor(sf::Color color)
{
    rect.setFillColor(color);
}

void Text::setRectColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    // Unlike the Item classes setter methods - which I hopefully shouldn't need to
    // reuse all that often - this doesn't call the other method as to avoid copying
    // the sf::Color object.
    rect.setFillColor(sf::Color(red, green, blue, alpha));
}


/* Displays the background/text.
 * Taken from text.h docs:
 *
 *  -> void display()
 *      Display the background and text.
 *      Note that text will be centered.
*/

void Text::display()
{
    // Draws background
    window->draw(rect);

    // Creates sf::Text object
    sf::Text text = sf::Text(rawText, font, height);

    // Calculates centered positions
    int centeredYPos = y - ((height - text.getLocalBounds().height) / 2.f);
    int centeredXPos = x + ((width -  text.getLocalBounds().width)  / 2.f);

    // Sets position and size
    text.setPosition(centeredXPos, centeredYPos);
    text.setFillColor(textcolor);

    // Draws text
    window->draw(text);
}

} // namespace gui

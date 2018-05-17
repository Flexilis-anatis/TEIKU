#include "text.h"

namespace gui
{

/* A partial constructor, taking care of the font and window. Must come after setrect.
 * From text.h docs:
 *
 *  -> void setup(std::string fontFilename)
 *      Sets up text/color/font
*/

void Text::setup(std::string fontFilename, std::string startText, int charHeight)
{
    // Tries to load font. The if statement will only trigger if it fails
    if (!font.loadFromFile(fontFilename))
    {
        // Again, need some sort of error handling
        return;
    }

    // Defaulting text color
    textColor = sf::Color(0, 0, 0);

    // Setting text
    rawText = startText;

    // Setting font size
    fontSize = charHeight;
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
 *  -> void setup(std::string fontFilename, std::string startText, int charHeight)
 *      Sets up text/color/font
*/

Text::Text(float x, float y, float charHeight, std::string text,
           std::string fontFilename, WindowRef window)
{
    // Calling setup methods. Arbitrary width/height given on rectangle
    setrect(x, y, 0, 0, window);
    setup(fontFilename, text, charHeight);
}


/* Set the text's color.
 * Taken from text.h docs:
 *
 *  -> void setTextColor(sf::Color color)
 *  -> void setTextColor(byte red, byte green, byte blue, byte alpha)
 *      Set the textColor property with an sf::Color or RGBA (alpha defaulting to 255)
*/

void Text::setTextColor(sf::Color color)
{
    textColor = color;
}

void Text::setTextColor(byte red, byte green, byte blue, byte alpha)
{
    // Unlike the setter methods - which I hopefully shouldn't need to reuse all that
    // often - this doesn't call the other method as to avoid copying the sf::Color object.
    textColor = sf::Color(red, green, blue, alpha);
}


/* Displays the background/text.
 * Taken from text.h docs:
 *
 *  -> void display()
 *      Display the background and text.
 *      Note that text will be centered.
*/

void Text::display() const
{
    // Creates sf::Text object
    sf::Text text = sf::Text(rawText, font, fontSize);

    // Sets position and size
    text.setPosition(x, y);
    text.setFillColor(textColor);

    // Draws text
    window->draw(text);
}

} // namespace gui

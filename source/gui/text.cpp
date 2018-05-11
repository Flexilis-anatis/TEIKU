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


/* Sets the text, defaults text color, calls setrect/setup and sets the initial string.
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
 *
 * From text.h docs:
 *
 *  -> void setString(std::string text)
 *      Reset's the string/rect to match the given text
  */

Text::Text(float x, float y, float charHeight, std::string text, std::string fontfilename,
           sf::RenderWindow& window, float widthMult, float heightMult)
{
    // Tweaking Y pos. to exactly match up
    y -= 2;

    // Stores font size
    fontsize = charHeight;

    // Sets up font
    setup(fontfilename);

    // Creates sf::Text object
    sf::Text testText = sf::Text(text, font, fontsize+1);

    // Calculates width/height based off of the dimensions
    int width  = testText.getLocalBounds().width  * widthMult;
    int height = testText.getLocalBounds().height * heightMult;

    // Making rectangle
    setrect(x, y, width, height, window);

    // Defaulting text color
    textcolor = sf::Color(0, 0, 0);

    // Parses the text
    setString(text);
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


/* Resets the string displayed by the object.
 * From text.h docs:
 *
 *  -> void setString(std::string text)
 *      Reset's the string/rect to match the given text
 */

void Text::setString(std::string text)
{
    // Clears out vector. We're going to completely replace it
    rawText.clear();

    std::string line = "";
    char character;

    // Loop through every character in the text
    for (unsigned int i = 0; i < text.size(); i++)
    {
        character = text[i];

        switch (character)
        {
        // If the character is a newline, add the text up to this point to the vector
        // and clear out the variable storing the text up to this point
        case '\n':
            rawText.push_back(line);
            line = "";
            break;

        // Otherwise, add the character to the list of text
        default:
            line += character;
            break;
        }
    }

    // Centers rectangle around text
    rect.setPosition(x, y + (fontsize / 10.f));

    // Adds last line
    if (line != "")
        rawText.push_back(line);
}


/* Displays the background/text.
 * Taken from text.h docs:
 *
 *  -> void display()
 *      Display the background and text.
 */

// (HALFOF(n)) = (.5f*(n)) = (0.5f * (n)) = ((n) / 2.0f)
#define HALFOF .5f*

void Text::display()
{
    // Draws background
    window->draw(rect);

    // Makes text variable
    sf::Text text = sf::Text("", font, fontsize);

    // Make Y position variable
    float yPos;

    // Loops through text vector and draws each one lower down
    for (unsigned int i = 0; i < rawText.size(); i++)
    {
        // Resets text object string
        text.setString(rawText[i]);

        // Calculates Y position
        yPos = y + (i * fontsize * 0.7f);

        // Sets position and color
        text.setPosition(x, yPos);
        text.setFillColor(textcolor);

        // Draws text
        window->draw(text);
    }
}

#undef HALFOF

} // namespace gui

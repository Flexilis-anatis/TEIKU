#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "base/item.h"

/**
Class Text - semi abstract class representing a GUI item that displays text

Protected Properties:
    -> sf::Font font
        Holds a font to render text with. (I decided to recreate the sf::Text object every
        time)
    -> sf::Color textcolor
        Holds the color to render the text with
    -> sf::Color bgcolor
        Holds the color to render the background with
    -> sf::RenderWindow* window
        Holds a window to render to
    -> std::string rawText
        Holds the actual given text to render


Protected Methods:
    -> void setup(std::string fontfilename, sf::RenderWindow* window)
        Loads the font and sets the window property.


Public Methods:
    -> void setTextColor(sf::Color color)
    -> void setTextColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        Set the textcolor property with an sf::Color or RGBA (alpha defaulting to 255)
    -> void display()
        Display the background and text.
        Note that text will be centered.
*/

namespace gui
{

// The image classes sister class, the Text class is - obviously - for rendering text.
class Text : public Item
{

protected:
    // The text's font
    sf::Font font;

    // The color of the text / background
    sf::Color textcolor;

    // The main window
    sf::RenderWindow* window;

    // The background
    sf::RectangleShape background;

    // The actual text
    std::string rawText;

    // Load font and set window
    void setup(std::string fontfilename, sf::RenderWindow* window);


public:
    // Calls setrect and setup
    Text(float x, float y, float width, float height, std::string text,
         std::string fontfilename, sf::RenderWindow* window);

    // Since this is in the lowest level of GUI classes that will be used as a
    // standalone, it needs a placeholder constructor
    Text(){}

    // Set's the text color. Uses RGBA format, with alpha defaulting to 255
    void setTextColor(sf::Color color);
    void setTextColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

    // Displays the background and text
    void display();

    // Set's the rectangle color. Uses RGBA format, with alpha defaulting to 255
    void setRectColor(sf::Color color);
    void setRectColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
};

} // namespace gui

#endif // TEXT_H_INCLUDED

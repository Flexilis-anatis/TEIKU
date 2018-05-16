#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "base/item.h"

/**
Class Text - semi abstract class representing a GUI item that displays text

Protected Properties:
    -> sf::Font font
        Holds a font to render text with. (I decided to recreate the sf::Text object
        every time)
    -> sf::Color textColor
        Holds the color to render the text with
    -> sf::Color bgcolor
        Holds the color to render the background with
    -> std::string rawText
        Holds the actual given text to render


Protected Methods:
    -> void setup(std::string fontFilename, std::string startText, int charHeight)
        Sets up text/color/font


Public Methods:
    -> void setTextColor(sf::Color color)
    -> void setTextColor(byte red, byte green, byte blue, byte alpha)
        Set the textColor property with an sf::Color or RGBA (alpha defaulting to 255)
    -> void display()
        Display the background and text.
        Note that text will be centered.
*/

namespace gui
{

// The image classes sister class, the Text class is - obviously - for rendering text.
class Text: public Item
{

protected:
    // The text's font
    sf::Font font;

    // The color of the text / background
    sf::Color textColor;

    // The actual text
    std::string rawText;

    // The height of the text
    float fontSize;

    // Sets up text/color/font
    void setup(std::string fontFilename, std::string startText, int charHeight);


public:
    // Calls setrect and setup
    Text(float x, float y, float charHeight, std::string text,
         std::string fontFilename, WindowRef window);

    // Since this is in the lowest level of GUI classes that will be used as a
    // standalone, it needs a placeholder constructor
    Text(){}

    // Set's the text color. Uses RGBA format, with alpha defaulting to 255
    void setTextColor(sf::Color color);
    void setTextColor(byte red, byte green, byte blue, byte alpha = 255);

    // Displays the background and text
    void display() const override;


    // Adds to the string
    void operator+=(std::string toadd);
};

} // namespace gui

#endif // TEXT_H_INCLUDED

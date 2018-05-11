#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "base/item.h"
#include <vector>

/**
Class Text - semi abstract class representing a GUI item that displays text

Protected Properties:
    -> sf::Font font
        Holds a font to render text with. (I decided to recreate the sf::Text object
        every time)
    -> sf::Color textcolor
        Holds the color to render the text with
    -> std::vector<std::string> rawText
        Holds the actual given text to render, separated by newlines
    -> float fontsize
        The height, in pixels, of the text


Protected Methods:
    -> void setup(std::string fontfilename)
        Loads the font.


Public Methods:
    -> void setTextColor(sf::Color color)
    -> void setTextColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        Set the textcolor property with an sf::Color or RGBA (alpha defaulting to 255)
    -> void setString(std::string text)
        Reset's the string/rect to match the given text
    -> void display()
        Display the background and text.
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
    sf::Color textcolor;

    // The actual text. Every newline needs a new instance so I can control the newlines
    // better
    std::vector<std::string> rawText;

    // Size of the text
    float fontsize;

    // Loads font
    void setup(std::string fontfilename);


public:
    // Calls setrect and setup
    Text(float x, float y, float charHeight, std::string text, std::string fontfilename,
         sf::RenderWindow& window, float widthMult=1, float heightMult=1);

    // Since this is in the lowest level of GUI classes that will be used as a
    // standalone, it needs a placeholder constructor
    Text(){}

    // Set's the text color. Uses RGBA format, with alpha defaulting to 255
    void setTextColor(sf::Color color);
    void setTextColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

    // Set's the rectangle color. Uses RGBA format, with alpha defaulting to 255
    void setRectColor(sf::Color color);
    void setRectColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

    // Set's the string to display
    void setString(std::string text);

    // Displays the background and text
    void display();
};

} // namespace gui

#endif // TEXT_H_INCLUDED

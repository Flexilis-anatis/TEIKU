#ifndef TEXTGROUP_H_INCLUDED
#define TEXTGROUP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace gui{
namespace text{

enum CursorDir
{
    LEFT, RIGHT, UP, DOWN
};

class TextGroup
{
    struct Cursor
    {
        typedef unsigned int uint;

        uint x, y, idealX;

        set(uint x_, uint y_, uint idealX_)
        {
            x = x_;
            y = y_;
            idealX = idealX_;
        }

        set(uint x_, uint y_)
        {
            x = x_;
            y = y_;
            idealX = x;
        }
    };

    struct PagePos
    {
        typedef unsigned int uint;
        uint x, y;
    };

    /// START OF ELEMENTS
    std::vector<sf::Text> text;
    sf::Font font;

    PagePos scrollPosition;
    Cursor cursor;

public:
    TextGroup(const sf::Font& fontToCopy);
    TextGroup(const std::string& fontFilename);
    TextGroup(){}

    void newline();
    void type(const char character);

    void moveCursor(const CursorDir direction);
};

} // namespace text
} // namespace gui

#endif // TEXTGROUP_H_INCLUDED

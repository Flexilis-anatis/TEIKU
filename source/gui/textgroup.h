#ifndef TEXTGROUP_H_INCLUDED
#define TEXTGROUP_H_INCLUDED

#include "elements/typedefs.h"
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
    typedef int Index;

// TESTING ONLY
public:
    std::vector<sf::Text> textLines;
    sf::Font font;

    sf::Vector2i indexToXY(const Index index);

public:
    TextGroup(const sf::Font& fontToCopy);
    TextGroup(const string fontFilename);
    TextGroup(){}

    // yay for void!

    void newline(Index line, Index column);
    void newline();
    void insert(char character, Index line, Index column);
    void insert(char character, Index index);
    void insert(string characters, Index line, Index column);
    void insert(string characters, Index index);

    void moveCursor(const CursorDir direction);
};

} // namespace text
} // namespace gui

#endif // TEXTGROUP_H_INCLUDED
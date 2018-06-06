#ifndef TEXTGROUP_H_INCLUDED
#define TEXTGROUP_H_INCLUDED

#include "elements/typedefs.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace gui{
namespace text{

class TextGroup
{
    typedef unsigned int Index;

protected:
    // The actual text
    std::vector<sf::Text> textLines;

    // The font the text will load
    sf::Font font;

    // Changes a 1d index to a 2d index
    sf::Vector2i indexToXY(const Index index);

    // Called every time a character is inserted
    virtual void updateText(){}

    // The font size
    const unsigned int fontSize;

public:
    TextGroup(const sf::Font& fontToCopy, unsigned int fontSize = 30);
    TextGroup(const string fontFilename, unsigned int fontSize = 30);
    TextGroup():fontSize(0){};

    // Add a new line into the text
    void newline(Index line, Index column);
    void newline(Index);

    // Insert a character into the text
    void insert(char character, Index line, Index column);
    void insert(char character, Index index);

    // Insert a string into the text
    void insert(string characters, Index line, Index column);
    void insert(string characters, Index index);
};

} // namespace text
} // namespace gui

#endif // TEXTGROUP_H_INCLUDED

#ifndef TEXTGROUP_H_INCLUDED
#define TEXTGROUP_H_INCLUDED

#include "elements/typedefs.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Index To X/Y Function Wrapper
// makes f(x,y) = f(i)
#define ITXYFuncWrapper(func) void func(Index index){auto xy=indexToXY(index);func(xy.x,xy.y);}
// optional extra args for above macro
#define AITXYFuncWrapper(func,args) void func(args,Index index){auto xy=indexToXY(index);func(xy.x,xy.y);}

namespace gui{
namespace text{

/**
    A handler for a block of text.  It's designed to be easy to handle with for displaying.
*/

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
    ITXYFuncWrapper(newline)

    // Insert a character into the text
    void insert(char character, Index line, Index column);
    AITXYFuncWrapper(insert, char character)

    // Insert a string into the text
    void insert(string characters, Index line, Index column);
    AITXYFuncWrapper(insert, string characters)
};

} // namespace text
} // namespace gui

#undef ITXYFuncWrapper
#undef AITXYFuncWrapper

#endif // TEXTGROUP_H_INCLUDED

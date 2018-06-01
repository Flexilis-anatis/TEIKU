#include "textgroup.h"

#ifdef DEBUG_TEXTGROUP
#include <iostream>
#endif

#define INSERT_ONCE 1

namespace gui{
namespace text{

sf::Vector2i TextGroup::indexToXY(const Index index)
{
    // If index is falsey, it must be 0. This is an edge case unfortunately,
    // and just defining it is a much briefer solution than making the algo
    // deal with it.
    if (!index) return sf::Vector2i(0,0);

    // Initialization of main unsigned ints
    Index line=0, column=0, total=0, lastSize;

    // While its still less than the index, add the length of the next string
    // to total and increase the line number
    while (total < index)
        total += textLines[line++].getString().getSize();

    // Ok, I'll admit this is a little hacky. This:
    //   Decreases the line number
    //   Gets the size of the last string
    //   Saves the size of the last string in lastSize
    //   ...And gets rid of the size of the last string from the total size
    total -= lastSize = textLines[--line].getString().getSize();

    // This increases the column until the total distance traversed so far
    // plus the column is the same as the desired index. (The actual logic
    // works by subtracting from the index and doesn't check for equality,
    // but that made more sense and actually means the same thing)
    while (total < index-(++column)){}

    // There's an edge case for the last character, so if it's the last
    // character (which will be one over the maximum index) reset the
    // column and increase the line
    column == lastSize && ++line && (column = 0);

    #ifdef DEBUG_TEXTGROUP
    std::cout << "Converted " << index << " to (" << line << ", " << column << ')' << std::endl;
    #endif

    // Returns the line and column
    return sf::Vector2i(line, column);
}


TextGroup::TextGroup(const sf::Font& fontToCopy)
{
    font = fontToCopy;
    textLines.push_back(sf::Text("", font, 30));
}

TextGroup::TextGroup(const string fontFilename)
{
    font.loadFromFile(fontFilename);
    textLines.push_back(sf::Text("", font, 30));
}


void TextGroup::newline(Index line, Index column)
{
    string str = textLines[line].getString().toAnsiString();
    string newStr = str.substr(column, str.size());
    string cutStr = str.substr(0, column);

    #ifdef DEBUG_TEXTGROUP
    std::cout << "NewStr: <" << newStr << ">\nCutStr: <" << cutStr << '>' << std::endl;
    #endif

    textLines[line].setString(cutStr);
    textLines.insert(textLines.begin()+line+1, sf::Text(newStr, font, 30));
}

void TextGroup::newline()
{
    newline(textLines.size()-1, textLines[textLines.size()-1].getString().getSize());
}


void TextGroup::insert(char character, Index line, Index column)
{
    if (character == '\n')
    {
        newline(line, column);
    }

    else
    {
        #define text textLines[line]
        string newString = text.getString();
        newString.insert(column, INSERT_ONCE, character);
        text.setString(newString);
        #undef text
    }
}


void TextGroup::insert(char character, Index index)
{
    sf::Vector2i location = indexToXY(index);
    insert(character, location.x, location.y);
}


void TextGroup::insert(string characters, Index line, Index column)
{
    for (Index i = 0; i < characters.size(); i++)
    {
        insert(characters[i], line, column++);

        if (characters[i] == '\n')
        {
            line++;
            column = 0;
        }
    }
}

void TextGroup::insert(string characters, Index index)
{
    sf::Vector2i location = indexToXY(index);
    insert(characters, location.x, location.y);
}

} // namespace text
} // namespace gui

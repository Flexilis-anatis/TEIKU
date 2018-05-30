#include "textgroup.h"

namespace gui{
namespace text{

sf::Vector2f TextGroup::indexToXY(const Index index)
{
    Index line=0, total=0, column=0;
    sf::Text* text = &textLines[line];

    // Finds the correct line
    do
    {
        total += text->getString().getSize();
        text = &textLines[++line];
    }
    while (index > total);

    // Gets rid of last column from total size
    total -= text->getString().getSize();

    // Finds the correct column
    while (total < index)
    {
        total++;
        column++;
    }

    // Returns the line and column
    return sf::Vector2f(line, column);
}


TextGroup::TextGroup(const sf::Font& fontToCopy)
{
    font = fontToCopy;
}

TextGroup::TextGroup(const std::string fontFilename)
{
    font.loadFromFile(fontFilename);
}

void TextGroup::insert(const char character, Index line, Index column)
{
    //
}


void TextGroup::insert(const char character, Index index)
{
    sf::Vector2f location = indexToXY(index);
    insert(character, location.x, location.y);
}


} // namespace text
} // namespace gui

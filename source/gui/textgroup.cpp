#include "textgroup.h"

#include <iostream>

// Char insert
#define cInsert(pos,char) insert(pos,1,char)


namespace gui{
namespace text{


/** \brief Turns a one-dimensional index into a two-dimensional index
 *
 * \param index - the one-dimensional index to transform
 * \return the two-dimensional index
 */

// I actually had this down to 5 extremely hacky lines
sf::Vector2i TextGroup::indexToXY(const Index index)
{
    // If index is falsey, it must be 0. This is an edge case unfortunately,
    // and just defining it is a much briefer solution than making the algo
    // deal with it.
    if (!index) return sf::Vector2i(0,0);

    // Initialization of main unsigned ints
    Index line=0, total=0, column, lastSize;

    // While its still less than the index, add the length of the next string
    // to total and increase the line number
    while(total < index)
        total += textLines[line++].getString().getSize();

    // Gets the size of the last line and stores it
    lastSize = textLines[--line].getString().getSize();

    // Gets rid of last lines length from total
    total -= lastSize;

    // Increases the column until it's reached the index requested
    column = index - total;

    // There's an edge case for the last character, so if it's the last
    // character (which will be one over the maximum index) reset the
    // column and increase the line
    if (column == lastSize)
    {
        column = 0;
        line++;
    }

    // Returns the line and column
    return sf::Vector2i(line, column);
}

TextGroup::TextGroup(const sf::Font& fontToCopy, unsigned int fontSize)
: fontSize(fontSize)
{
    font = fontToCopy;
    textLines.push_back(sf::Text("", font, fontSize));
}

TextGroup::TextGroup(const string fontFilename, unsigned int fontSize)
: fontSize(fontSize)
{
    font.loadFromFile(fontFilename);
    textLines.push_back(sf::Text("", font, fontSize));
}


/** \brief Inserts a newline into the text with an X/Y position
 *
 * \param line - the line to insert the newline into
 * \param column - the column to insert the newline into
 * \return Nothing
 */

void TextGroup::newline(Index line, Index column)
{
    string str = textLines[line].getString().toAnsiString();
    string newStr = str.substr(column, str.size());
    string cutStr = str.substr(0, column);

    textLines[line].setString(cutStr);
    textLines.insert(textLines.begin()+line+1, sf::Text(newStr, font, fontSize));
}

/** \brief Inserts a newline into the text with an index
 *
 * \param index - the position to insert the newline into
 * \return Nothing
 */

void TextGroup::newline(Index index)
{
    sf::Vector2i location = indexToXY(index);
    newline(location.x, location.y);
}


/** \brief Inserts a character into the text with an X/Y position
 *
 * \param character - the character to insert
 * \param line - the line to insert it in
 * \param column - the column to insert it in
 * \return Nothing
 */

void TextGroup::insert(char character, Index line, Index column)
{
    if (character == '\n')
    {
        newline(line, column);
    }

    else
    {
        string newStr = textLines[line].getString();
        newStr.cInsert(column, character);
        textLines[line].setString(newStr);
    }

    // I can get away with only doing this here because all other insert
    // methods boil down to this method.
    updateText();
}


/** \brief Inserts a character into the text with an index
 *
 * \param character - the character to insert
 * \param index - the index to insert it into
 * \return Nothing
 */

void TextGroup::insert(char character, Index index)
{
    sf::Vector2i location = indexToXY(index);
    insert(character, location.x, location.y);
}


/** \brief Inserts a string into the text with an X/Y position
 *
 * \param characters - string to insert
 * \param line - the line to insert it in
 * \param column - the column to insert it in
 * \return Nothing
 */

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

/** \brief Inserts a string into the text with an index
 *
 * \param characters - the string to insert
 * \param index - the index to insert the string into
 * \return Nothing
 */

void TextGroup::insert(string characters, Index index)
{
    sf::Vector2i location = indexToXY(index);
    insert(characters, location.x, location.y);
}

} // namespace text
} // namespace gui

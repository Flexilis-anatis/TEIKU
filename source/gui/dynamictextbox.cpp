#include "dynamictextbox.h"

namespace gui
{

void DynamicTextbox::updateCursor()
{
    std::string rawText = text.rawText;

    unsigned int line = 0;
    std::string relevantText = "";

    for (unsigned int index = 0; index < cursorX; index++)
    {
        if (rawText[index] == '\n')
        {
            relevantText = "";
            line++;
        }

        else
        {
            relevantText += rawText[index];
        }
    }

    sf::Text dummyWidthText  = sf::Text(relevantText, text.font, text.fontSize);

    sf::Text dummyHeightText1 = sf::Text(rawText.substr(0,cursorX)+'D', text.font, text.fontSize);
    sf::Text dummyHeightText2  = sf::Text(relevantText+'D', text.font, text.fontSize);


    float xOffset = dummyWidthText.getLocalBounds().width;
    float yOffset = dummyHeightText1.getLocalBounds().height - dummyHeightText2.getLocalBounds().height;

    rect.setPosition(x + xOffset, y + yOffset);
}


bool DynamicTextbox::textIsInBox(char extraCharacter)
{
    sf::Text throwawayTextObject = sf::Text(text.rawText + extraCharacter, text.font, text.fontSize);

    return (throwawayTextObject.getLocalBounds().width <= text.width &&
            throwawayTextObject.getLocalBounds().height <= text.height);
}


void DynamicTextbox::type(char character)
{
    if (textIsInBox(character))
    {
        text.rawText.insert(text.rawText.begin()+cursorX, character);
        cursorX++;
        updateCursor();
    }
}


DynamicTextbox::DynamicTextbox(float x, float y, float chars, float lines,
                               float charHeight, std::string startText, WindowRef window)
{
    float height = lines*charHeight;

    resetText.create(startText);
    setrect(x, y+(charHeight/5.f), 2, charHeight*.9f, window);

    // Sets up text object
    text.setup("resources\\monospace.ttf", startText, charHeight);

    // Calculates required width
    sf::Text dummyText;

    std::string testText = "";

    while (testText.size() < chars)
    {
        testText += ' ';
        dummyText = sf::Text(testText, text.font, text.fontSize);
    }

    text.setrect(this->x, y, dummyText.getLocalBounds().width, height*1.2, window);

    // Sets text and bg color
    text.setTextColor(0, 0, 0);
    text.setRectColor(255, 255, 255);

    // Initiates cursor
    cursorX = text.rawText.size();
    updateCursor();

    // Sets cursor color
    setRectColor(0, 0, 0);
}

void DynamicTextbox::display() const
{
    window->draw(text.rect);
    text.display();
    window->draw(rect);
}


sf::Vector2f DynamicTextbox::getBGSize() const
{
    return text.rect.getSize();
}


void DynamicTextbox::send(sf::Event& tosend)
{
    switch (tosend.type)
    {
    case sf::Event::TextEntered:
        switch (tosend.text.unicode)
        {
        case Keycode::BACKSPACE:
            if (cursorX > 0)
            {
                cursorX--;
                text.rawText.erase(text.rawText.begin()+cursorX);
                updateCursor();
            }

            break;

        case Keycode::ENTER:
            type('\n');
            break;

        default:
            type(tosend.text.unicode);
            break;
        }

    default:
        break;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && cursorX > 0)
    {
        cursorX--;
        updateCursor();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && cursorX < text.rawText.size())
    {
        cursorX++;
        updateCursor();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        unsigned int length = 1;
        bool foundNewline = false;

        for (unsigned int index = cursorX; index < text.rawText.size(); index++)
        {
            if (!foundNewline && text.rawText[index] == '\n')
                foundNewline = true;
            else if (foundNewline && text.rawText[index] == '\n')
                break;
            else if (foundNewline)
                length++;
        }

        if (cursorX + length <= text.rawText.size())
        {
            cursorX += length;
            updateCursor();
        }
    }
}


std::string DynamicTextbox::getText()
{
    return text.rawText;
}

} // namespace gui

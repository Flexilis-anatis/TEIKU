#include "dynamictextbox.h"

namespace gui
{

DynamicTextbox::DynamicTextbox(float x, float y, float width, float height,
                               std::string startText, WindowRef window)
{
    resetText.create(startText);
    setrect(x, y, width, height, window);

    text.setrect(x, y-(height/5.f), 0, 0, window);
    text.setup("resources\\monospace.ttf", startText, height);

    text.setTextColor(0, 0, 0);
    setRectColor(255, 255, 255);
}


void DynamicTextbox::update()
{
    display();
    char character;

    // Test update
    while (keyBuffer.size() > 0)
    {
        character += keyBuffer[0];

        if (character == gui::BACKSPACE)
            text.rawText.erase(text.rawText.end()-1);
        else
            text += character;

        keyBuffer.erase(keyBuffer.begin());
    }
}


void DynamicTextbox::display() const
{
    window->draw(rect);

    text.display();
}


void DynamicTextbox::send(sf::Event& tosend)
{
    switch (tosend.type)
    {
    case sf::Event::TextEntered:
        text += tosend.text.unicode;
        break;
    default:
        break;
    }
}

} // namespace gui

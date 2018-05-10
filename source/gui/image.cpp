#include "image.h"

namespace gui
{

/* Basically a constructor, just designed so it can be easily called by child classes.
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename, sf::RenderWindow& window)
 *      loads the texture, puts the texture into the rectangle, and sets the window
 *      attribute.
*/

void Image::setup(std::string texturefilename, sf::RenderWindow& window)
{
    // Loading texture
    if (!(texture->loadFromFile(texturefilename)))
    {
        // error opening file. Might just throw an exception. Not sure what to do
        // here yet
        return;
    }

    // Setting rectangles texture
    rect.setTexture(texture);

    // Saving render window
    this->window = &window;
}


/* Calls setup AND setrect.
 *
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename, sf::RenderWindow& window)
 *      loads the texture, puts the texture into the rectangle, positions and resizes
 *      the rectangle, and sets the window attribute.
 *
 * From base/item.h docs:
 *
 *  -> void setrect(float x, y, width, height)
 *      All arguments are floats. Simply sets the corresponding properties in the
 *      class.
*/

Image::Image(float x, float y, float width, float height,
             std::string texturefilename, sf::RenderWindow& window)
{
    // Setup is called first as to set the rect's texture and avoid making it invisible
    setup(texturefilename, window);
    setrect(x, y, width, height); // gui::Item::setRect(float,float,float,float): defined in source/gui/base
}


/* Displays the rectangle on the render window.
 * From image.h docs:
 *
 *  -> void display()
 *      displays the rectangle on to the window.
*/

void Image::display()
{
    window->draw(rect);
}

} // namespace gui


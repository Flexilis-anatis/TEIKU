#include "image.h"

namespace gui
{

/* Basically a constructor, just designed so it can be easily called by child classes.
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename, sf::RenderWindow* window)
 *      loads the texture, puts the texture into the rectangle, and sets the window
 *      attribute. Note this MUST BE CALLED AFTER Item::setrect
*/

void Image::setup(std::string texturefilename, sf::RenderWindow* window)
{
    // Loading texture
    if (!(texture->loadFromFile(texturefilename)))
    {
        // error opening file. Might just throw an exception
        return;
    }

    // Setting rectangles texture
    rect.setTexture(texture);

    // Saving render window
    this->window = window;
}


/* Calls setup AND setrect.
 *
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename, sf::RenderWindow* window)
 *      loads the texture, puts the texture into the rectangle, positions and resizes
 *      the rectangle, and sets the window attribute
 *
 * From base/item.h docs:
 *
 *  -> void setrect(float x, y, width, height)
 *      All arguments are floats. Simply sets the corresponding properties in the
 *      class.
*/

Image::Image(float x, float y, float width, float height,
             std::string texturefilename, sf::RenderWindow* window)
{
    setup(texturefilename, window);
    setrect(x, y, width, height);
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


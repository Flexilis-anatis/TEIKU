#include "image.h"

namespace gui
{

/* Basically a constructor, just designed so it can be easily called by child classes.
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename)
 *      loads the texture and puts the texture into the rectangle
*/

void Image::setup(std::string texturefilename)
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
}


/* Calls setup AND setrect.
 *
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename,)
 *      loads the texture and puts the texture into the rectangle
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
    setup(texturefilename);
    setrect(x, y, width, height, window); // gui::Item::setRect(float,float,float,float): defined in source/gui/base
}

} // namespace gui


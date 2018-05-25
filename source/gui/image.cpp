#include "image.h"

namespace gui{

/* Basically a constructor, just designed so it can be easily called by child classes.
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename)
 *      loads the texture and puts the texture into the rectangle
*/

void Image::setup(cString texturefilename)
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


/* Calls setup AND setRectInfo.
 *
 * From image.h docs:
 *
 *  -> void setup(std::string texturefilename,)
 *      loads the texture and puts the texture into the rectangle
 *
 * From base/item.h docs:
 *
 *  -> void setRectInfo(float x, y, width, height, )
 *      First four arguments are floats. Simply sets the corresponding properties in the
 *      class.
*/

Image::Image(__RECTINFO, cString texturefilename, WindowRef window)
{
    // Setup is called first as to set the rect's texture and avoid making it invisible
    setup(texturefilename);

    // gui::Item::setRect(float,float,float,float,sf::RenderWindow&): defined in source/gui/base
    setRectInfo(RI_x, RI_y, RI_width, RI_height, window);
}

} // namespace gui


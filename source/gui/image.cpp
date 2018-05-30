#include "image.h"

namespace gui{

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


Image::Image(__RECTINFO, cString texturefilename, WindowRef window)
{
    // Setup is called first as to set the rect's texture and avoid making it invisible
    setup(texturefilename);

    // gui::Item::setRect(float,float,float,float,sf::RenderWindow&): defined in source/gui/base
    setRectInfo(RI_x, RI_y, RI_width, RI_height, window);
}

} // namespace gui


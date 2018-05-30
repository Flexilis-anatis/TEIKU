#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "base/rectitem.h"
#include <string>

namespace gui{

///\brief A class for rendering images
class Image: public base::RectItem
{
protected:
    // This will hold the image. You can easily go texture.loadFromFile to load most
    // images, and then you can set the rectangles texture to it. You have to keep a
    // pointer to it alive though, or it won't work.
    sf::Texture* texture;


    // (c)onstant std::(string)
    typedef const std::string& cString;

    // Set everything up. Needs the filename of an image
    void setup(cString texturefilename);

public:
    // Calls setRectInfo and setup
    Image(__RECTINFO, cString texturefilename, WindowRef window);

    // Since this will be in the lowest level of GUI classes that will be used as a
    // standalone, we need a placeholder constructor
    Image(){}
};

} // namespace gui

#endif // IMAGE_H_INCLUDED

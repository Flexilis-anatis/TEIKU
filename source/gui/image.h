#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "base/item.h"
#include <string>

/**
Class Image - semi abstract class representing a GUI item that displays an image

Protected Properties:
    -> sf::Texture* texture
        Holds a loaded image

Protected Methods:
    -> void setup(std::string texturefilename)
        loads the texture and puts the texture into the rectangle
*/

namespace gui
{

// Possibly the base class of buttons, for instance. But certainly useful for other
// purposes
class Image: public Item
{
protected:
    // This will hold the image. You can easily go texture.loadFromFile to load most
    // images, and then you can set the rectangles texture to it. You have to keep a
    // pointer to it alive though, or it won't work.
    sf::Texture* texture;

    // Set everything up. Needs the filename of an image
    void setup(std::string texturefilename);

public:
    // Calls setrect and setup
    Image(float x, float y, float width, float height,
          std::string texturefilename, sf::RenderWindow& window);

    // Since this will be in the lowest level of GUI classes that will be used as a
    // standalone, we need a placeholder constructor
    Image(){}
};

} // namespace gui

#endif // IMAGE_H_INCLUDED

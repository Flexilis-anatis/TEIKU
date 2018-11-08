#include "dynamictextbox.h"

namespace gui{

DynamicTextbox::DynamicTextbox(__RECTINFO, uint charSize, WindowRef window, std::string defaultString)
: Text({RI_x, RI_y}, window, defaultString, charSize), defaultString(defaultString)
{
    setRectInfo(RI_x, RI_y, RI_width, RI_height, window);
}

} // namespace gui

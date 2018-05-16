#include "dynamictextbox.h"

namespace gui
{

DynamicTextbox::DynamicTextbox(float x, float y, float width, float height,
                               std::string startText, WindowRef window)
{
    resetText.create(startText);
    setrect(x, y, width, height, window);
    setup("resources\\monospace.ttf", startText, height);
}

} // namespace gui

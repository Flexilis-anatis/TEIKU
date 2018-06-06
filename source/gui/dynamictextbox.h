#include "base/rectitem.h"
#include "text.h"

namespace gui{

class DynamicTextbox: public Text
{
    typedef unsigned int uint;

    struct Point
    {
        uint x=0, y=0;
        void set(const uint x_, const uint y_){x=x_;y=y_;}
    };

    struct Cursor: Point
    {
        uint idealX=0;

        void set(const uint x, const uint y, const uint ix)
        {
            Point::set(x, y);
            idealX = ix;
        }
    };


    Point scrollPosition = Point();
    Cursor cursor = Cursor();
    const std::string defaultString;

public:
    DynamicTextbox(__RECTINFO, uint charSize, WindowRef window, std::string defaultString="");
};

} // namespace gui

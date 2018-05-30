#include "base/rectitem.h"
#include "text.h"

namespace gui{

class DynamicTextbox: public Text
{
    struct Point
    {
        typedef unsigned int uint; uint x, y;
        void set(const uint x_, const uint y_){x=x_;y=y_;}
    };

    struct Cursor: Point
    {
        uint idealX;

        void set(const uint x, const uint y, const uint ix)
        {
            Point::set(x, y);
            idealX = ix;
        }
    };


    Point scrollPosition;
    Cursor cursor;

public:
    // pass
};

} // namespace gui

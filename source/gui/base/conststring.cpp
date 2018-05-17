#include "conststring.h"

#include <stdexcept>

void ConstString::create(std::string s)
{
    if (isSet)
    {
        throw std::runtime_error("ConstString created twice");
    }

    else
    {
        isSet = true;
        contents = s;
    }
}


std::string ConstString::str()
{
    return contents;
}

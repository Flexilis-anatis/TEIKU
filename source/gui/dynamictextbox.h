#ifndef DYNAMICTEXTBOX_H_INCLUDED
#define DYNAMICTEXTBOX_H_INCLUDED

#include <functional>
#include "base/item.h"
#include "text.h"

/**
 class DynamicTextbox - a basic textbox.
*/
s
namespace gui
{

class DynamicTextbox: public Text
{
private:
    // Stores two values of any type. A key and a value.
    template<typename T1, typename T2>
    struct Mapping
    {
        T1 key;
        T2 code;

        Mapping(T1 k, T2 c)
        {
            key = k;
            code = c;
        }
    };

    // A constant string that allows itself to be set once
    struct ConstString: public sf::NonCopyable
    {
    private:
        bool isSet = false;
        std::string contents;

    public:
        ConstString(){}

        void create(std::string s)
        {
            if (isSet)
            {
                throw std::bad_function_call();
            }

            else
            {
                isSet = true;
                contents = s;
            }
        }

        std::string str()
        {
            return contents;
        }
    };

protected:
    std::string keyBuffer;
    ConstString resetText;

public:
    DynamicTextbox(float x, float y, float width, float height, std::string startText,
                   WindowRef window);
};

} // namespace gui

#endif // DYNAMICTEXTBOX_H_INCLUDED

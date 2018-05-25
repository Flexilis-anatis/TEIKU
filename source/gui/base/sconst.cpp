#include <SFML/System/NonCopyable.hpp>
#include <stdexcept>

using sf::NonCopyable;

namespace base{
namespace utils{

// A constant string allows itself to be set once
template<class Type>
class SConst: NonCopyable // (S)ettable (Const)ant
{
    bool isSet = false;
    Type data;

public:
    // If you give it a value to start with, it will
    SConst(Type d){create(d);}
    SConst(){}

    void create(Type d)
    {
        if (isSet)
        {
            // Throw error if isSet has already been set to true
            throw std::runtime_error("ConstString created twice");
        }

        else
        {
            // If not, it's the first time to create it, so set the data and register it
            // as set
            isSet = true;
            data = d;
        }
    }

    // Returns the stored data
    Type value()
    {
        return data;
    }
};

} // namespace utils
} // namespace base

#ifndef CONSTSTRING_H_INCLUDED
#define CONSTSTRING_H_INCLUDED

// A constant string allows itself to be set once
template<class Type>
struct GConst
{
private:
    bool isSet = false;
    Type contents;

public:
    GGonst(Type d){create(d)}
    GConst(){}

    void create(Type d)
    {
        if (isSet)
        {
            throw std::runtime_error("ConstString created twice");
        }

        else
        {
            isSet = true;
            data = d;
        }
    }

    Type value()
    {
        return data;
    }
};

#endif // CONSTSTRING_H_INCLUDED

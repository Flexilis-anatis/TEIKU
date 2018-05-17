#ifndef CONSTSTRING_H_INCLUDED
#define CONSTSTRING_H_INCLUDED

#include <string>

// A constant string that allows itself to be set once
struct ConstString
{
private:
    bool isSet = false;
    std::string contents;

public:
    ConstString(){}

    void create(std::string s);
    std::string str();
};

#endif // CONSTSTRING_H_INCLUDED

#ifndef TYPEDEFS_H_INCLUDED
#define TYPEDEFS_H_INCLUDED

/// typedefs for GUI

#include <SFML/Graphics/RenderWindow.hpp>

typedef uint8_t byte;
typedef const byte RGBA;

// Window typedefs
typedef typename sf::RenderWindow Window;

typedef Window& WindowRef;
typedef Window* WindowPtr;

// Constant window typedefs
typedef const Window cWindow;

typedef cWindow& cWindowRef;
typedef cWindow* cWindowPtr;

/// global macros for GUI

#define __RECTINFO const float RI_x,const float RI_y,const float RI_width,const float RI_height
#define __COLORINFO RGBA CI_red,RGBA CI_green,RGBA CI_blue,RGBA CI_alpha=255

/// global using statements
#include <string>
using std::string;

#endif // TYPEDEFS_H_INCLUDED

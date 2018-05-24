#ifndef TYPEDEFS_H_INCLUDED
#define TYPEDEFS_H_INCLUDED

/// Contains typedefs for GUI

#include <SFML/Graphics/RenderWindow.hpp>

typedef uint8_t byte;
typedef byte RGBA;

#define RectInfo float RIx,float RIy,float RIwidth,float RIheight

typedef typename sf::RenderWindow  Window;
typedef typename sf::RenderWindow& WindowRef;
typedef typename sf::RenderWindow* WindowPtr;


#endif // TYPEDEFS_H_INCLUDED

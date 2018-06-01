#include "source/gui.h"
#include <iostream>

/**
Author:     RubberDuckyMaster
Start date: 5/8/2018, 11:03 AM
Name:       TextEditor (I know, Uninventive) (TEIKU for short ;)
Purpose:    Basic text editor.

Just a little program I'm writing to get more practice with GUI's
and text rendering. Hoping to - in the end - at least get it up
to the level of notepad, as simple a goal as that may sound.

I'm going to try and design my own file selector for
saving/opening, because I hate the Win32 API.
*/

using gui::text::TextGroup;

int main()
{
    TextGroup e = gui::text::TextGroup("resources\\monospace.ttf");

    e.insert('5', 0, 0);
    e.insert('\n', 0, 0);
    e.insert('h', 1, 0);

    for (unsigned int i = 0; i < e.textLines.size(); i++)
        std::cout << e.textLines[i].getString().toAnsiString() << std::endl;

    return 0;
}


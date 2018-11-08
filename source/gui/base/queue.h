#include "item.h"

namespace gui
{

class Queue
{
    // Quality of life typedef. ¯\_(ツ)_/¯
    typedef base::Item Item;

    struct SelectedItem
    {
        bool itemIsSelected = false;
        Item* item;
    };

    std::vector<Item*> items;
    SelectedItem selectedItem;

public:
    Queue();

    void addItem(Item& item);
};

} // namespace gui

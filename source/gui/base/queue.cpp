#include "queue.h"

namespace gui
{

Queue::Queue()
{
    // idk what to put here yet
}

void Queue::addItem(Item& item)
{
    items.push_back(&item);
}

} // namespace gui

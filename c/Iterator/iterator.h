#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "menuItem.h"
#include "stdbool.h"

typedef struct MenuItem MenuItem;

typedef struct Iterator_MenuItem
{
    MenuItem *items;
    int length;
    int pos;
    MenuItem (*next)(struct Iterator_MenuItem *);
    bool (*hasNext)(struct Iterator_MenuItem *);
} Iterator_MenuItem;

void Iterator_MenuItem_New(Iterator_MenuItem *self, MenuItem *items, int length);

#endif /*__ITERATOR_H__*/

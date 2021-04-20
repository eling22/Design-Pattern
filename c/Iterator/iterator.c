#include "iterator.h"

static MenuItem _next(Iterator_MenuItem *self);
static bool _hasNext(Iterator_MenuItem *self);

void Iterator_MenuItem_New(Iterator_MenuItem *self, MenuItem *items, int length)
{
    self->items = items;
    self->length = length;
    self->pos = 0;
    self->next = _next;
    self->hasNext = _hasNext;
}

static MenuItem _next(Iterator_MenuItem *self)
{
    MenuItem item = self->items[self->pos];
    self->pos++;
    return item;
}
static bool _hasNext(Iterator_MenuItem *self)
{
    return self->pos < self->length;
}
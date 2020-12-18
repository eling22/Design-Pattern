#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <stdbool.h>

typedef struct _IObserver
{
    void (*update)(struct _IObserver *, void *);
    bool (*isSameObserver)(struct _IObserver *, struct _IObserver *);
} IObserver;

#define IObserver(TYPE)             \
    void (*update)(TYPE *, void *); \
    bool (*isSameObserver)(TYPE *, IObserver *);

#endif /* __OBSERVER_H__ */
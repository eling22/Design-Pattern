#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "Observer.h"
typedef struct _ISubject
{
    void (*registerObserver)(struct _ISubject *, IObserver *);
    void (*removeObserver)(struct _ISubject *, IObserver *);
    void (*notifyObserver)(struct _ISubject *);
} ISubject;

#define ISubject(TYPE)                             \
    ISubject super_ISubject;                       \
    void (*registerObserver)(TYPE *, IObserver *); \
    void (*removeObserver)(TYPE *, IObserver *);   \
    void (*notifyObserver)(TYPE *);

#endif /* __SUBJECT_H__ */
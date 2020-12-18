#ifndef __DISPLAYELEMENT_H__
#define __DISPLAYELEMENT_H__

typedef struct _IDisplayElement
{
    void (*display)(struct _IDisplayElement *);
} IDisplayElement;

#define IDisplayElement(TYPE) \
    void (*display)(TYPE *);

#endif /* __DISPLAYELEMENT_H__ */
#ifndef __IBEVERAGE_H__
#define __IBEVERAGE_H__

typedef struct _IBeverage
{
    char description[256];
    float price;
    char *(*getDescription)(struct _IBeverage *);
    float (*cost)(struct _IBeverage *);
} IBeverage;

#define IBeverage(TYPE)              \
    char description[256];           \
    float price;                     \
    char *(*getDescription)(TYPE *); \
    float (*cost)(TYPE *);

#endif /* __IBEVERAGE_H__ */
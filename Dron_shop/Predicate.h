#ifndef Predicate_H
#define Predicate_H

#include "Dron.h"

struct makeLessThanOther
{
    inline bool operator() (Dron& Dron1, Dron& Dron2)
    {
        return (Dron1.Getmake() < Dron2.Getmake());
    }
};

struct ModelLessThanOther
{
    inline bool operator() (Dron& Dron1, Dron& Dron2)
    {
        return (Dron1.GetModel() < Dron2.GetModel());
    }
};

struct PriceLessThanOther
{
    inline bool operator() (Dron& Dron1, Dron& Dron2)
    {
        return (Dron1.GetPrice() < Dron2.GetPrice());
    }
};

#endif // !Predicate_H


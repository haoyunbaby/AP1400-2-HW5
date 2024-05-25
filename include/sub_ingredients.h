#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include <string>

#include "ingredient.h"

#define DEFCLASS(_name, _price_unit)                                        \
  class _name : public Ingredient {                                         \
   public:                                                                  \
    _name(size_t units) : Ingredient(_price_unit, units) { name = #_name; } \
    virtual std::string get_name() const override { return name; }          \
    virtual Ingredient *clone() const override {                            \
      return new _name(this->units);                                        \
    }                                                                       \
  }

DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);
#endif  // SUB_INGREDIENTS_H

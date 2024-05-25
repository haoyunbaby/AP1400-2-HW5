#ifndef MOCHA_H
#define MOCHA_H
#include <string>
#include <vector>

#include "espresso_based.h"
#include "sub_ingredients.h"
class Mocha : public EspressoBased {
 public:
  Mocha();
  Mocha(const Mocha &moc);
  virtual ~Mocha() override;
  void operator=(const Mocha &moc);

  virtual std::string get_name() const override;
  virtual double price() const override;

  void add_side_item(Ingredient *side);
  std::vector<Ingredient *> &get_side_items();

 private:
  std::vector<Ingredient *> side_items;
};
#endif  // MOCHA_H

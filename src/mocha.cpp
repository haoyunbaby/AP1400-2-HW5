#include "mocha.h"
using namespace std;

Mocha::Mocha() {
  ingredients.push_back(new Espresso(2));
  ingredients.push_back(new Milk(2));
  ingredients.push_back(new MilkFoam(1));
  ingredients.push_back(new Chocolate(1));
  name = "Mocha";
}
Mocha::Mocha(const Mocha& moc) : EspressoBased(moc) {
  for (const auto& side : moc.side_items) {
    side_items.push_back(side->clone());
  }
}
Mocha::~Mocha() {
  for (const auto& i : side_items) delete i;
  side_items.clear();
}
void Mocha::operator=(const Mocha& moc) {
  if (this == &moc) {
    return;
  }
  EspressoBased::operator=(moc);
  for (const auto& i : side_items) delete i;
  side_items.clear();

  for (const auto& side : moc.side_items) {
    side_items.push_back(side->clone());
  }
}
string Mocha::get_name() const { return name; }
double Mocha::price() const {
  double rv = 0;
  for (const auto& ind : ingredients) {
    rv += ind->price();
  }
  for (const auto& ind : side_items) {
    rv += ind->price();
  }
  return rv;
}
void Mocha::add_side_item(Ingredient* side) { side_items.push_back(side); }
vector<Ingredient*>& Mocha::get_side_items() { return side_items; }

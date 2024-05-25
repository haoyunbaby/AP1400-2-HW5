#include "cappuccino.h"
using namespace std;

Cappuccino::Cappuccino() {
  ingredients.push_back(new Espresso(2));
  ingredients.push_back(new Milk(2));
  ingredients.push_back(new MilkFoam(1));
  name = "Cappuccino";
}
Cappuccino::Cappuccino(const Cappuccino& cap) : EspressoBased(cap) {
  for (const auto& side : cap.side_items) {
    side_items.push_back(side->clone());
  }
}
Cappuccino::~Cappuccino() {
  for (const auto& i : side_items) delete i;
  side_items.clear();
}
void Cappuccino::operator=(const Cappuccino& cap) {
  if (this == &cap) {
    return;
  }
  EspressoBased::operator=(cap);
  for (const auto& i : side_items) {
    delete i;
  }
  side_items.clear();
  for (const auto& side : cap.side_items) {
    side_items.push_back(side->clone());
  }
}
string Cappuccino::get_name() const { return name; }
double Cappuccino::price() const {
  double rv = 0;
  for (const auto& ind : ingredients) {
    rv += ind->price();
  }
  for (const auto& ind : side_items) {
    rv += ind->price();
  }
  return rv;
}

void Cappuccino::add_side_item(Ingredient* side) { side_items.push_back(side); }
vector<Ingredient*>& Cappuccino::get_side_items() { return side_items; }

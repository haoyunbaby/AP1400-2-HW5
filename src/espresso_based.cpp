#include "espresso_based.h"
using namespace std;

vector<Ingredient*>& EspressoBased::get_ingredients() { return ingredients; }
EspressoBased::~EspressoBased() {
  for (const auto& i : ingredients) delete i;
  ingredients.clear();
}
EspressoBased::EspressoBased() {}
EspressoBased::EspressoBased(const EspressoBased& esp) : name(esp.name) {
  ingredients.reserve(esp.ingredients.size());
  for (const auto& ing : esp.ingredients) {
    ingredients.push_back(ing->clone());
  }
}

void EspressoBased::operator=(const EspressoBased& esp) {
  if (this == &esp) {
    return;
  }
  for (const auto& i : ingredients) delete i;
  ingredients.clear();
  name = esp.name;
  for (const auto& ing : esp.ingredients) {
    ingredients.push_back(ing->clone());
  }
}

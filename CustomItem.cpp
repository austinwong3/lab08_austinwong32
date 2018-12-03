#include <string>
#include <iostream>
#include <map>

#include "CustomItem.h"

CustomItem::CustomItem(std::string size) : IceCreamItem(size)
{
    if(size == "small")
        price=3;
    else if(size == "medium")
        price=5;
    else if(size == "large")
        price = 6.5;
    else
        price = 0;
}
CustomItem::~CustomItem()
{

}
void CustomItem::addTopping(std::string topping)
{
    if(toppings.count(topping) == 0)
        toppings.insert(std::pair<std::string,int>(topping,1));
    else{
        toppings[topping]++;
    }
    price += .40;
}
std::string CustomItem::composeItem()
{
    std::string comp = "";
  comp += "Custom Size: " + size + "\n" + "Toppings:\n";
  for( std::map<std::string, int>::iterator it = toppings.begin(); it != toppings.end(); it++ ) {
    comp += it->first + ": " + std::to_string(it->second) + " oz\n";
  }

  comp+= "Price: $";

  std::string p = std::to_string( getPrice() );
  int index = 0;
  for(  int i = 0; i < static_cast<int>(p.length()); i++ ) {
    if( p[i] == '.' )
      index = i;
  }
  p = p.substr( 0, index+3 );


  comp+= (p+"\n");

  return comp;
}
double CustomItem::getPrice()
{
    return price;
}


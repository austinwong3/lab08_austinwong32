#include <string>
#include <iostream>
#include "PreMadeItem.h"

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem( size )
{
    if(size == "small")
    price = 4;
    else if(size == "medium")
        price = 6;
    else if(size == "large")
        price = 7.5;
    else
        price = 0;

    this->name = name;
}
PreMadeItem::~PreMadeItem()
{

}
std::string PreMadeItem::composeItem()
{
    std::string comp = "";
    comp += "Pre-made Size: " + size + "\nPre-made Item: " + name + "\nPrice: $";

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
double PreMadeItem::getPrice()
{
    return price;
}
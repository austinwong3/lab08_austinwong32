// CustomItem.h


#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H


#include <map>
#include <string>
#include "IceCreamItem.h"

class CustomItem: public IceCreamItem{
    public:
        CustomItem(std::string size);
        virtual ~CustomItem();
        void addTopping(std::string topping);
        virtual std::string composeItem();
        virtual double getPrice();
    private:
        std::map<std::string, int> toppings;

};

#endif
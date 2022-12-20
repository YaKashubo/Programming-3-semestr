#include<iostream>

using namespace std;

class Burger
{
protected:
    int size = 0;
    bool cheese = false;
    bool pepperoni = false;
    bool lettuce = false;
    bool tomato = false;
    
    Burger(int size = 0) : size(size) {};

    Burger(BurgerBuilder builder)
    {
        this->size = builder.size;
        this->cheese = builder.cheese;
        this->pepperoni = builder.pepperoni;
        this->lettuce = builder.lettuce;
        this->tomato = builder.tomato;
    }
};

class BurgerBuilder: public Burger
{
public:
    int size;
    bool cheese = false;
    bool pepperoni = false;
    bool lettuce = false;
    bool tomato = false;

    BurgerBuilder(int size=0)
    {
        this->size = size;
    }

    BurgerBuilder addPepperoni()
    {
        this->pepperoni = true;
        return *this;
    }

    BurgerBuilder addLettuce()
    {
        this->lettuce = true;
        return *this;
    }

    BurgerBuilder addCheese()
    {
        this->cheese = true;
        return *this;
    }

    BurgerBuilder addTomato()
    {
        this->tomato = true;
        return *this;
    }

   Burger* build()
    {
        return new Burger(*this);
    }
};

int main()
{
    BurgerBuilder builder(14);
    builder.addCheese();
    builder.addPepperoni();
    builder.addTomato();
    Burger pizzaBurger(builder);

    return EXIT_SUCCESS;
}
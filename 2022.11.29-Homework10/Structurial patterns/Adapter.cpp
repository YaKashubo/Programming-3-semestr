#include<iostream>

using namespace std;

struct Lion
{
    void roar();
};

class AfricanLion : public Lion
{
    void roar();
};

class AsianLion : public Lion
{
    void roar();
};

class Hunter
{
public:
    void hunt(Lion lion);

};

class WildDog
{
public:
    void bark();
};


class WildDogAdapter : public Lion
{
protected:
    WildDog dog;
public:
    WildDogAdapter(WildDog dog)
    {
        this->dog = dog;
    }

    void roar()
    {
        this->dog.bark();
    }
};

int main()
{
    WildDog wildDog;
    WildDogAdapter adapt(wildDog);

    Hunter hunter;
    hunter.hunt(adapt);
    return EXIT_SUCCESS;
}
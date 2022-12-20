#include<iostream>

using namespace std;

struct Builder
{
    void build()
    {
        this->test();
        this->lint();
        this->assemble();
        this->deploy();
    }

    void test();
    void lint();
    void assemble();
    void deploy();
};

class AndroidBuilder :public Builder
{
    void test()
    {
        cout << "Старт Android тестов" << endl;
    }

    void lint()
    {
        cout << "Анализ Android кода" << endl;
    }

    void assemble()
    {
        cout << "Сборка Android" << endl;
    }

    void deploy()
    {
        cout << "Развертывание Android" << endl;
    }
};

class IosBuilder :public Builder
{
    void test()
    {
        cout << "Старт iOS тестов" << endl;;
    }

    void lint()
    {
        cout << "Анализ iOS кода" << endl;
    }

    void assemble()
    {
        cout << "Сборка iOS" << endl;
    }

    void deploy()
    {
        cout << "Развертывание iOS" << endl;
    }
};

int main()
{
    AndroidBuilder androidBuilder;
    androidBuilder.build();

    IosBuilder iosBuilder;
    iosBuilder.build();

    return EXIT_SUCCESS;
}

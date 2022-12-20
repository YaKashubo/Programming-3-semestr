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
        cout << "����� Android ������" << endl;
    }

    void lint()
    {
        cout << "������ Android ����" << endl;
    }

    void assemble()
    {
        cout << "������ Android" << endl;
    }

    void deploy()
    {
        cout << "������������� Android" << endl;
    }
};

class IosBuilder :public Builder
{
    void test()
    {
        cout << "����� iOS ������" << endl;;
    }

    void lint()
    {
        cout << "������ iOS ����" << endl;
    }

    void assemble()
    {
        cout << "������ iOS" << endl;
    }

    void deploy()
    {
        cout << "������������� iOS" << endl;
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

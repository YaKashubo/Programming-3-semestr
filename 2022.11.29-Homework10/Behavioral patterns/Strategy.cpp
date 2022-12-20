#include<iostream>

using namespace std;

struct SortStrategy
{
    void sort(int* dataset);
};

class BubbleSortStrategy : public SortStrategy
{
public:
    int* sort(int* dataset)
    {
        cout << "���������� ���������" << endl;

        // ���������
        return dataset;
    }
};

class QuickSortStrategy : public SortStrategy
{
public:
    int* sort(int* dataset)
    {
        cout << "���������� ���������" << endl;

        // ���������
        return dataset;
    }
};

class Sorter
{
protected:
    SortStrategy sorter;
public:
    Sorter(SortStrategy sorter)
    {
        this->sorter = sorter;
    }

    void sort(int* dataset)
    {
        return this->sorter.sort(dataset);
    }
};

int main()
{
    int dataset[6] = {1, 5, 4, 3, 2, 8};
    
    BubbleSortStrategy sort1;
    Sorter sorter(sort1);
    sorter.sort(dataset); // ����� : ���������� ���������

    QuickSortStrategy sort1;
    Sorter sorter(sort1);
    sorter.sort(dataset); // ����� : ������� ����������
    return EXIT_SUCCESS;
}
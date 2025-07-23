#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Array
{
public:
Array()
{
ArraySize = 0;
};
~Array()
{
this->Clear();
};
void FillArr()
{
ArraySize = 1 + rand() % (10 - 1);
pArr = new T[ArraySize];
for (int i = 0; i < ArraySize; i++)
{
pArr[i] = frand(0.0, 1000.0);
}
};
void Clear()
{
if (ArraySize != 0)
{
delete[] pArr;
this->ArraySize = 0;
}
};
double GetAverage()
{
double average = 0;
for (int i = 0; i < ArraySize; i++)
{
average += pArr[i];
}
average = average / ArraySize;
return average;
};
void Print()
{
cout << "Ваш массив: ";
for (int i = 0; i < ArraySize; i++)
{
cout << pArr[i] << " ";
}
cout << endl;
};
bool IsEmpty()
{
return (this->ArraySize == 0) ? true : false;
};
private:
T ArraySize;
T* pArr = nullptr;
double frand(const double down, const double up)
{
return down + 1.0 * rand() / RAND_MAX * (up - down);
}
};
template<>
class Array<char>
{
public:
Array()
{}
};

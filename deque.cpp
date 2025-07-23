#include <iostream>
#include <fstream>
using namespace std;
template<typename T>
class Deque
{
struct element
{
element* next, * prev;
T val;
element(const T& v)
{
next = nullptr;
prev = nullptr;
val = v;
};
};
private:
element* left, * right;
int size; //случайное число до 30
T& operator[] (const int index)
{
int cntr = 0;
element* currentEl = left;
while (currentEl != nullptr)
{
if (cntr == index)
return currentEl->val;
currentEl = currentEl->next;
cntr++;
}
};
public:
Deque()
{
left = nullptr;
right = nullptr;
size = 0;
}
~Deque()
{
clear();
}
Deque(const Deque& other)
{
this.clear();
for (int i = 0; i < other.size; i++)
{
this->add_right(other[i]);
}
}
void fill()
{
int tmp = 1 + rand() % (30 - 1);
for (int i = 0; i < tmp; i++)
this->add_left(rand() % 10);
}
void add_left(const T& v)
{
element* p = new element(v);
if (left == nullptr)
left = right = p;
else
{
p->next = left;
left->prev = p;
left = p;
}
++size;
}
void add_right(const T& v)
{
element* p = new element(v);
if (left == nullptr)
left = right = p;
else
{
p->prev = right;
right->next = p;
right = p;
}
++size;
}
void pop_left()
{
element* t;
if (left != nullptr)
{
t = left;
left = left->next;
delete t;
if (left == nullptr)
right = nullptr;
else
left->prev = nullptr;
--size;
}
}
void pop_right()
{
element* t;
if (right != nullptr)
{
t = right;
right = right->prev;
delete t;
if (right == nullptr)
left = nullptr;
else
right->next = nullptr;
--size;
}
}
void clear()
{
element* t;
while (left != nullptr)
{
t = left;
left = left->next;
delete t;
}
right = nullptr;
size = 0;
}
Deque& operator= (Deque& d2);
template <typename T> friend ostream& operator<< (ostream& out, Deque<T>& deque);
template <typename T> friend istream& operator>> (istream& in, Deque<T>& deque);
template <typename T> friend Deque<T>& operator-(Deque<T>& dq, const int value);
template <typename T> friend Deque<T>& operator+(Deque<T>& d1, Deque<T>& d2);
template <typename T> friend bool operator<(Deque<T>& d1, Deque<T>& d2);
};
template<typename T>
ostream& operator<<(ostream& out, Deque<T>& deque)
{
for (int i = 0; i < deque.size; i++)
{
out << deque[i] << " ";
}
return out;
}
template<typename T>
istream& operator>>(istream& in, Deque<T>& deque)
{
T tmp;
in >> tmp;
deque.add_right(tmp);
return in;
}
template<typename T>
Deque<T>& operator-(Deque<T>& dq, const int value)
{
if (dq.size < value)
{
dq.clear();
return dq;
}
for (int i = 0; i < value; i++)
dq.pop_right();
return dq;
}
template<typename T>
Deque<T>& operator+(Deque<T>& d1, Deque<T>& d2)
{
for (int i = 0; i < d2.size; i++)
d1.add_right(d2[i]);
return d1;
}
template<typename T>
bool operator<(Deque<T>& d1, Deque<T>& d2)
{
T sum = 0;
for (int i = 0; i < d1.size; i++)
sum += d1[i];
for (int i = 0; i < d2.size; i++)
sum -= d2[i];
return (sum < 0)? true : false;
}
template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T>& other)
{
T tmp;
if (this == &other)
return *this;
this->clear();
for (int i = 0; i < other.size; i++)
{
tmp = other.operator[](i);
this->add_right(tmp);
}
return *this;
}

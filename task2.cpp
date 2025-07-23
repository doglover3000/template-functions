#include <iostream>
#include <ctime>
#include <typeinfo>
#include "deque.cpp"
using namespace std;
int main()
{
setlocale(LC_ALL, "rus");
srand(time(0));
Deque<int> d1;
Deque<int> d2;
d1.fill();
d2.fill();
string line = "-----------------------------------------------------------------\n";
cout << "Программа работает действия над деком, который генерируется программой" << endl;
int entered = 0, tmp, tmp2;
while (true)
{
cout << "Выберите команду которую хотите выполнить:\n"
"1 - Сгенерировать новый дек\n"
"2 - Удалить с левого конца\n"
"3 - Удалить с правого конца\n"
"4 - Вывести оба дека\n"
"5 - Удалить n-ое количество элементов из одного из деков\n"
"6 - Сравнить суммы деков\n"
"7 - Отчистить один из деков\n"
"0 - Звершить работу программы\n"
"> ";
try
{
cin >> entered;
switch (entered)
{
default:
return 0;
case 1:
cout << line;
cout << "Выберите дек. Введите 1 для первого, 2 - для второго > ";
cin >> tmp;
if (tmp == 1)
{
cout << "Старый дек: " << d1 << endl;
d1.clear();
d1.fill();
cout << "Новый дек: " << d1 << endl;
}
if (tmp == 2)
{
cout << "Старый дек: " << d2 << endl;
d2.clear();
d2.fill();
cout << "Новый дек: " << d2 << endl;
}
if (tmp != 1 && tmp != 2)
throw exception("Введено неверное значение!");
cout << line;
break;
case 2:
cout << line;
cout << "d1: " << d1 << "\nd2: " << d2 << endl;
cout << "Выберите дек. Введите 1 для первого, 2 - для второго > ";
cin >> tmp;
if (tmp != 1 && tmp != 2)
throw exception("Введено неверное значение!");
if (tmp == 1)
{
d1.pop_left();
cout << "Ваш дек: " << d1 << endl;
}
if (tmp == 2)
{
d2.pop_left();
cout << "Ваш дек: " << d2 << endl;
}
if (tmp != 1 && tmp != 2)
throw exception("Введено неверное значение!");
cout << line;
break;
case 3:
cout << line;
cout << "d1: " << d1 << "\nd2: " << d2 << endl;
cout << "Выберите дек. Введите 1 для первого, 2 - для второго > ";
cin >> tmp;
if (tmp != 1 && tmp != 2)
throw exception("Введено неверное значение!");
if (tmp == 1)
{
d1.pop_right();
cout << "Ваш дек: " << d1 << endl;
}
else
{
d2.pop_right();
cout << "Ваш дек: " << d2 << endl;
}
cout << line;
break;
case 4:
cout << line;
cout << "d1: " << d1 << "\nd2: " << d2 << endl;
cout << line;
break;
case 5:
cout << line;
cout << "d1: " << d1 << "\nd2: " << d2 << endl;
cout << "Выберите дек. Введите 1 для первого, 2 - для второго > ";
cin >> tmp;
if (tmp != 1 && tmp != 2)
throw exception("Введено неверное значение!");
cout << "Введите число, на которое хотите сократить дек > ";
cin >> tmp2;
if (tmp2 > 30 && tmp < 0)
throw exception("Введено неподходящее значение!");
if (tmp == 1)
{
d1 - tmp2;
cout << "Ваш дек: " << d1 << endl;
}
else
{
d2 - tmp2;
cout << "Ваш дек: " << d2 << endl;
}
cout << line;
break;
case 6:
cout << line;
cout << "d1: " << d1 << "\nd2: " << d2 << endl;
(d1 < d2) ? (cout << "Cумма первого меньше\n") : (cout << "Сумма первого больше или равна сумме второго\n");
cout << line;
break;
case 7:
cout << line;
cout << "d1: " << d1 << "\nd2: " << d2 << endl;
if (tmp != 1 && tmp != 2)
throw exception("Введено неверное значение!");
cout << "Выберите дек. Введите 1 для первого, 2 - для второго > ";
cin >> tmp;
if (tmp == 1)
d1.clear();
else
d2.clear();
cout << "Дек успешно отчищен!" << endl;
cout << line;
break;
}
}
catch (const std::exception& ex)
{
cout << "\n**** Ошибка! " << ex.what() << " ****\n\n";
}
}
}

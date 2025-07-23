#include <iostream>
#include <ctime>
#include <locale>
#include "Array.cpp"
int main()
{
setlocale(LC_ALL, "rus");
int entered = 0;
srand(time(0));
string line = "-------------------------------------------\n";
Array<double> a;
cout << "Программа генерирует массив случайной длины и заполняет его случайными числами\nВведите команду, которую хотите совершить\n";
while (true)
{
cout << "1 - Сгенерировать массив\n"
"2 - Вывести массив\n"
"3 - Найти среднее арифметическое массива\n"
"4 - Отчистить массив\n"
"0 - Завершить работу программы\n"
">> ";
try
{
cin >> entered;
if ((entered != 1) && (entered != 2) && (entered != 3) && (entered != 4) && (entered != 5) && (entered != 6) && (entered != 7) && (entered != 0))
throw exception("Такой команды нет!");
switch (entered)
{
case 1:
cout << line;
if (!a.IsEmpty())
a.Clear();
a.FillArr();
a.Print();
cout << line;
break;
case 2:
cout << line;
a.Print();
cout << line;
break;
case 3:
cout << line;
if (a.IsEmpty())
throw exception("Массив пуст!");
cout << "Среднее арифметическое массива - " << a.GetAverage() << endl;
cout << line;
break;
case 4:
cout << line;
if (a.IsEmpty())
throw exception("Массив уже пуст!");
a.~Array();
cout << "Массив успешно очищен!" << endl;
cout << line;
break;
default:
return 0;
}
}
catch (const std::exception& ex)
{
cout << endl << "**** Ошибка! " << ex.what() << " ****\n\n";
}
}
}

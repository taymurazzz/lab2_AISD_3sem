#pragma once
#include <iostream>
using namespace std;

// функци€ с алгоритмом двоичного поиска 
int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       // если искомое меньше значени€ в €чейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > arr[midd])  // если искомое больше значени€ в €чейке
			left = midd + 1;       // смещаем левую границу поиска
		else                       // иначе (значени€ равны)
			return midd;           // функци€ возвращает индекс €чейки

		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}

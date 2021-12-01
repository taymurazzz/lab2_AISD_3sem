#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//направление сортировки
enum SortOrder
{
    ASC,    //по возрастанию
    DESC    //по убыванию
};

//метод для обмена элементов массива
void swapElements(int& element1, int& element2)
{
    int tempVar = element1;
    element1 = element2;
    element2 = tempVar;
}

//проверка правильности расположения элементов массива
bool isElementsSorted(int a, int b, SortOrder sortOrder)
{
    if (sortOrder == ASC)
    {
        return a <= b;
    }
    else
    {
        return a >= b;
    }
}

//проверка отсортирован массив или нет
bool isArraySorted(int* arr, int n, SortOrder sortOrder)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (!isElementsSorted(arr[i], arr[i + 1], sortOrder))
        {
            return false;
        }
    }

    return true;
}

//перемешивание элементов массива в случайном порядке
int* shuffleElements(int* arr, int n)
{
    while (n > 1)
    {
        int r = rand() % n;
        n -= 1;
        swapElements(arr[r], arr[n]);
    }

    return arr;
}

//случайная сортировка
int* bogoSort(int* arr, int n, SortOrder sortOrder)
{
    while (!isArraySorted(arr, n, sortOrder))
    {
        arr = shuffleElements(arr, n);
    }

    return arr;
}

//вывод массива на экран
void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

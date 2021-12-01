#include <iostream>;
#include "bogoSort.h"
#include "binarySearch.h"
#include "quickSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "countingSort.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Список алгоритмов:" << endl;
    cout << "1) Двоичный поиск(BinarySearch)" << endl;
    cout << "2) Быстрая сортировка(QuickSort)" << endl;
    cout << "3) Сортировка вставками(InsertionSort)" << endl;
    cout << "4) Сортировка пузырьком(BubbleSort)" << endl;
    cout << "5) Глупая сортировка(BogoSort)" << endl;                       // готово
    cout << "6) Сортировка подсчётом(CountingSort) для типа char" << endl;
    cout << "Выберите алгоритм:";
    int alg;
    cin >> alg;

    if (alg==1) {
        int SIZE;
        cout << "Введите размер: ";
        cin >> SIZE;
        int* array = new int[SIZE];
        int key = 0;
        int index = 0; // индекс ячейки с искомым значением

        cout << "Заполните массив: " << endl;
        for (int i = 0; i < SIZE; i++) // заполняем массив
        {
            cin>>array[i];
            if (i != 0 && array[i] < array[i - 1]) {
                cout << "Ошибка! Для binary search массив должен быть отсортирован";
                return 0;
            }
        }
        for (int i = 0; i < SIZE; i++) // показываем массив
        {
            cout << array[i] << " | ";
        }

        cout << "\n\nВведите любое число: ";
        cin >> key;

        index = Search_Binary(array, 0, SIZE, key);

        if (index >= 0)
            cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
        else
            cout << "В массиве нет такого числа!\n\n";
    }


    if (alg == 2) {
        int size;
        cout << "Введите размер массива: ";
        cin >> size;
        int* arr2 = new int[size];
        cout << "Введите значения массива: ";
        for (int i = 0; i < size; i++) {
            cin >> arr2[i];
        }
        cout << "Отсортированный массив: ";
        qsortRecursive(arr2, size);
        for (int i = 0; i < size; i++) {
            cout << arr2[i] << " ";
        }
    }


    if (alg == 3) {
        int N;
        cout << "Введите размер массива: ";
        cin >> N;
        int* a = new int[N];
        cout << "Введите значения массива:";
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        insSort(a, N);
        cout << "Отсортированый массив: ";
        for (int i = 0; i < N; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }


    if (alg == 4) {
        int SIZE;
        cout << "Введите размер массива: ";
        cin >> SIZE;
        int* arr = new int[SIZE];

        cout << "Введите значения массива: ";
        for (int i = 0; i < SIZE; i++)
        {
            cin >> arr[i];
        }
        cout << endl;

        bubSort(arr, SIZE);  // передаем в функцию для сортировки

        cout << "Массив после сортировки: ";
        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    if (alg == 5) {
        srand(time(NULL));
        int* arr;
        int size;
        cout << "n = ";
        cin >> size;
        arr = new int[size];
        cout << "Введите значения массива: ";
        for (int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
        arr = bogoSort(arr, size, ASC);
        printArray(arr, size);
        delete arr;
        cout << endl;
        system("pause");
        return 0;
    }

    if (alg == 6) {
        int size;
        cout << "Введите размер массива: ";
        cin >> size;
        char* arr = new char[size];
        cout << "Введите значения массива: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        countSort(arr, size);

        cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }

    if (alg > 6 || alg < 1) {
        cout << "Неверный выбор";
    }


    return 0;
}

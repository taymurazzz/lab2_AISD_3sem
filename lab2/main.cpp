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
    cout << "������ ����������:" << endl;
    cout << "1) �������� �����(BinarySearch)" << endl;
    cout << "2) ������� ����������(QuickSort)" << endl;
    cout << "3) ���������� ���������(InsertionSort)" << endl;
    cout << "4) ���������� ���������(BubbleSort)" << endl;
    cout << "5) ������ ����������(BogoSort)" << endl;                       // ������
    cout << "6) ���������� ���������(CountingSort) ��� ���� char" << endl;
    cout << "�������� ��������:";
    int alg;
    cin >> alg;

    if (alg==1) {
        int SIZE;
        cout << "������� ������: ";
        cin >> SIZE;
        int* array = new int[SIZE];
        int key = 0;
        int index = 0; // ������ ������ � ������� ���������

        cout << "��������� ������: " << endl;
        for (int i = 0; i < SIZE; i++) // ��������� ������
        {
            cin>>array[i];
            if (i != 0 && array[i] < array[i - 1]) {
                cout << "������! ��� binary search ������ ������ ���� ������������";
                return 0;
            }
        }
        for (int i = 0; i < SIZE; i++) // ���������� ������
        {
            cout << array[i] << " | ";
        }

        cout << "\n\n������� ����� �����: ";
        cin >> key;

        index = Search_Binary(array, 0, SIZE, key);

        if (index >= 0)
            cout << "��������� ����� ��������� � ������ � ��������: " << index << "\n\n";
        else
            cout << "� ������� ��� ������ �����!\n\n";
    }


    if (alg == 2) {
        int size;
        cout << "������� ������ �������: ";
        cin >> size;
        int* arr2 = new int[size];
        cout << "������� �������� �������: ";
        for (int i = 0; i < size; i++) {
            cin >> arr2[i];
        }
        cout << "��������������� ������: ";
        qsortRecursive(arr2, size);
        for (int i = 0; i < size; i++) {
            cout << arr2[i] << " ";
        }
    }


    if (alg == 3) {
        int N;
        cout << "������� ������ �������: ";
        cin >> N;
        int* a = new int[N];
        cout << "������� �������� �������:";
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        insSort(a, N);
        cout << "�������������� ������: ";
        for (int i = 0; i < N; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }


    if (alg == 4) {
        int SIZE;
        cout << "������� ������ �������: ";
        cin >> SIZE;
        int* arr = new int[SIZE];

        cout << "������� �������� �������: ";
        for (int i = 0; i < SIZE; i++)
        {
            cin >> arr[i];
        }
        cout << endl;

        bubSort(arr, SIZE);  // �������� � ������� ��� ����������

        cout << "������ ����� ����������: ";
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
        cout << "������� �������� �������: ";
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
        cout << "������� ������ �������: ";
        cin >> size;
        char* arr = new char[size];
        cout << "������� �������� �������: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        countSort(arr, size);

        cout << "��������������� ������: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }

    if (alg > 6 || alg < 1) {
        cout << "�������� �����";
    }


    return 0;
}

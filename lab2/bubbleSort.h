#pragma once
#include <iostream>

using namespace std;

void bubSort(int* arrForSort, int SIZE)
{
	int buff = 0; // ��� ���������� �������� ��������, ��� ����������

	for (int i = 0; i < SIZE - 1; i++) // 
	{
		// ��������� ���� �������� �� ���������� �������� 
		// �� �������, ������� � ������� if ����� "������" ��������,
		// ��������� �������� ���� ���������,
		// � ��������� ��� � ������� ������ �������
		for (int j = SIZE - 1; j > i; j--)
		{
			if (arrForSort[j] < arrForSort[j - 1])
			{
				buff = arrForSort[j - 1];
				arrForSort[j - 1] = arrForSort[j];
				arrForSort[j] = buff;
			}
		}
		// ����� �������� i ������������� �� 1
		// � ���������� ���� ����� ���������� �������� 
		// �� ���������� �� �������. ����� ������� �������� �����
		// "������" �������� �� ����������  � ������ ������ � �.�.
	}
}
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>

using namespace std;

void Simple(int *x);

void linearSearch(int *key, int *arr);

void binarySearch(int *key, int *a, int arr);

int BullsAndCows(int*arr, int *mas);



int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int nz;

	do
	{
		cout << "������� ����� �������: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "�������� �������, ������� ���������, �������� �� ���������� ��" << endl
				<< "����� �������? ����� ���������� �������, ���� ��� ������� ��� " << endl
				<< "������� ������ �� ���� � �� �������.\n\n";
			int a;
			cout << "������� �����, ����� ��������� �������� �� ��� �������: ";
			cin >> a;
			Simple(&a);

		}break;

		case 2:
		{
			cout << "�������� �������, ����������� �������� ��������� ������ ���������" << endl
				<< "����� � ���������� �������.\n\n";
			int mas[10] = { 0 };
			int a;
			cout << "������� ����� ��� ����, ����� ����� ���: "; cin >> a;
			cout << "\n�������� ������ ��������:\n";
			for (int i = 0; i < 10; i++)
			{
				mas[i] = rand() % 25;
				cout << mas[i] << "\t";
			}

			linearSearch(&a, mas);

		}break;

		case 3:
		{
			cout << "�������� �������, ����������� �������� ��������� ������ ��������� " << endl
				<< "����� � ���������� �������.\n\n";
			int mas[10] = { 0 };
			int a;
			cout << "������� ����� ��� ����, ����� ����� ���: "; cin >> a;
			cout << "\n�������� ������ ��������:\n";
			for (int i = 0; i < 10; i++)
			{
				mas[i] = rand() % 25;
				cout << mas[i] << "\t";
			}
			binarySearch(&a, mas, 10);
		}break;

		case 4:
		{
			cout << "�������� ���� ����� � �������.��������� ���������� ������������� �����" << endl
				<< "� �������� ������ ������� ���.����� ����� ������������� ����� ���������" << endl
				<< "��������, ������� ���� ����� �������(����) � ������� ���� ������� � �����" << endl
				<< "�� ������ �����(������).����� ����������� ����� �� ����� ���������� " << endl
				<< "������� ���������� ��������� ������������� �������.� ��������� ����������" << endl
				<< "������������ ��������.\n\n";
			//���� ��������, ��� �������� �������, �� ������ �������� ������ ������

			int comp[4], user[5], a, b = 0, count = 0;
			for (int i = 0; i < 4; i++)
			{
				comp[i] = 1 + rand() % 9;
				cout << comp[i];
			}

			
			cout << endl;
			while (b != 4)
			{
				do
				{
					cout << "\n������� �������������� �����: \n";
					cin >> a;
				} while (a < 999 || a > 10000);

				int i = 0;
				int q = 1000;
				do
				{
					user[i] = a / q;
					a = a - (user[i])*q;
					q = q / 10;
					i++;
				} while (i < 4);

				b = BullsAndCows(comp, user);
				count++;

			}

			cout << "\n�� ��������!\n���� ������� "<<count<<" �������(-��, -��)\n\n";
		}break;

		}


		cout << "������ ���������� 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "������" << endl;
		}
		}
	} while (nz > 0);


}


void Simple(int *x)
{
	int i, count = 0;
	for (i = 2; i < *x; i++)
	{
		if (*x%i == 0)
			count++;
	}

	if (count > 0)
		cout << "��� �� ������� �����\n\n";

	if (count == 0)
		cout << "��� ������� �����\n\n";
}

void linearSearch(int *key, int *arr)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == *key)
		{
			cout << "��� ����� ��������� �� ���� �����: " << i + 1 << endl;
			count++;
		}
	}

	if (count == 0)
		cout << "\n������ ����� ��� � �������\n\n";
}

void binarySearch(int *key, int *a, int rr)
{
	int j;
	cout << "����������:\n";
	for (int i = 0; i <= rr - 1; i++)
	{
		for (j = (rr - 1); j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}

		}
		cout << "a[" << i << "] = " << a[j] << endl;
	}


	int left = 0;
	int right = 19;
	int count = 0;
	int issearch = -1;

	while (left <= right)
	{
		count++;
		int mid = (left + right) / 2;

		if (*key == a[mid])
		{
			issearch = mid;
			break;
		}

		if (*key < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (issearch == -1)
		cout << "������� �� ������!" << endl;
	else
	{
		cout << "a[" << issearch << "]=" << a[issearch] << " (�� " << count << " ������(-�, -��)" << endl;
	}
}

int BullsAndCows(int*arr, int *mas)
{
	int cows = 0, bulls = 0;

	//���������� �����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i] == mas[j])
				cows++;
		}
	}

	//���������� �����, ������� �� ���������� ������
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] == mas[i])
			bulls++;
	}

	cout << bulls << " - ���., " << cows << " - �����.\n";


	return bulls;
}
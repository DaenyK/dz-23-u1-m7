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
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "Написать функцию, которая проверяет, является ли переданное ей" << endl
				<< "число простым? Число называется простым, если оно делится без " << endl
				<< "остатка только на себя и на единицу.\n\n";
			int a;
			cout << "введите число, чтобы проверить является ли оно простым: ";
			cin >> a;
			Simple(&a);

		}break;

		case 2:
		{
			cout << "Написать функцию, реализующую алгоритм линейного поиска заданного" << endl
				<< "ключа в одномерном массиве.\n\n";
			int mas[10] = { 0 };
			int a;
			cout << "введите число для того, чтобы найти его: "; cin >> a;
			cout << "\nзаполним массив рандомно:\n";
			for (int i = 0; i < 10; i++)
			{
				mas[i] = rand() % 25;
				cout << mas[i] << "\t";
			}

			linearSearch(&a, mas);

		}break;

		case 3:
		{
			cout << "Написать функцию, реализующую алгоритм бинарного поиска заданного " << endl
				<< "ключа в одномерном массиве.\n\n";
			int mas[10] = { 0 };
			int a;
			cout << "введите число для того, чтобы найти его: "; cin >> a;
			cout << "\nзаполним массив рандомно:\n";
			for (int i = 0; i < 10; i++)
			{
				mas[i] = rand() % 25;
				cout << mas[i] << "\t";
			}
			binarySearch(&a, mas, 10);
		}break;

		case 4:
		{
			cout << "Написать игру «Быки и коровы».Программа загадывает четырёхзначное число" << endl
				<< "и играющий должен угадать его.После ввода пользователем числа программа" << endl
				<< "сообщает, сколько цифр числа угадано(быки) и сколько цифр угадано и стоит" << endl
				<< "на нужном месте(коровы).После отгадывания числа на экран необходимо " << endl
				<< "вывести количество сделанных пользователем попыток.В программе необходимо" << endl
				<< "использовать рекурсию.\n\n";
			//игра сыровата, все недочеты доделаю, по поводу рекурсии возник вопрос

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
					cout << "\nвведите четырехзначное число: \n";
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

			cout << "\nвы выиграли!\nбыло сделано "<<count<<" попыток(-ки, -ка)\n\n";
		}break;

		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "ошибка" << endl;
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
		cout << "это не простое число\n\n";

	if (count == 0)
		cout << "это простое число\n\n";
}

void linearSearch(int *key, int *arr)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == *key)
		{
			cout << "это число находится на этом месте: " << i + 1 << endl;
			count++;
		}
	}

	if (count == 0)
		cout << "\nтакого числа нет в массиве\n\n";
}

void binarySearch(int *key, int *a, int rr)
{
	int j;
	cout << "сортировка:\n";
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
		cout << "элемент не найден!" << endl;
	else
	{
		cout << "a[" << issearch << "]=" << a[issearch] << " (за " << count << " проход(-а, -ов)" << endl;
	}
}

int BullsAndCows(int*arr, int *mas)
{
	int cows = 0, bulls = 0;

	//одинаковые числа
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i] == mas[j])
				cows++;
		}
	}

	//одинаковые числа, стоящие на правильных местах
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] == mas[i])
			bulls++;
	}

	cout << bulls << " - бык., " << cows << " - коров.\n";


	return bulls;
}
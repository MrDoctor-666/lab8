#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale (LC_ALL, "RUS");
	int z=0, k, i = 0;
	float s;
	float *a;
	fstream fi, fo;
	cout << "Новокрещенов Демьян, 9302 группа, 21.10.2019\n";
	cout << "Программа переставляет числа в массиве.\n";
	fi.open("v1.txt", ios::in);
	fo.open("tmp.txt", ios::app);
	if (!fi.good())
	{
		cout << "\nПрограмма сломалась, приходите позже.\n";
		fo << "\nПрограмма сломалась, приходите позже.\n";
	}
	else
	{
		fo << "\n-----------------------------------------------\n";
		while (!fi.eof())
		{
			fi >> s;
			z++;
			if (fi.eof()) {
				z = z-1; break;
			}
		}
		fi.close();
		a = new float [z];
		fi.open("v1.txt", ios::in);
		for (i = 0; i < z; ++i)
		{
			fi >> *(a+i);
			if (fi.eof()) break;
		}
		fi.close();
		fo << "\nЧисло элементов массива: " << z;
		fo << "\nИсходный массив: ";
		for (i = 0; i < z; ++i)
			fo << *(a+i) << " ";
		for (k = 0; k < (z/2); k++)
		{
			for (i = 0; i < z; ++i)
			{
				while (*(a + i) < 0)
				{
					if (*(a + i + 1) < 0) break;
					s = *(a + i + 1);
					*(a + i + 1) = *(a + i);
					*(a + i) = s;
				}
				if (*(a + i) == 0 && *(a + i + 1) >= 0)
				{
					s = *(a + i);
					*(a + i) = *(a  +i + 1);
					*(a + i + 1) = s;
				}
			}
		}
		fo << "\nПолученный массив: ";
		for (i = 0; i < z; i++)
		{
			cout << *(a + i) << " ";
			fo << *(a + i) << " ";
		}	
		delete[]a;
	}
	cin >> i;
}


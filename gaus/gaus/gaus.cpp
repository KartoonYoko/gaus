// gaus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;



void outm(vector<vector<double>> matrix, int n) {
	cout.setf(ios::fixed);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 4)
				cout << "   " << matrix[i][j] << endl;
			else
				if(matrix[i][j] < 0)
					cout << "  " << setprecision(1) << matrix[i][j];
				else
					cout << "   " << setprecision(1) << matrix[i][j];
		}
	}
	cout << "-------------" << endl;
	cout.unsetf(ios::fixed);
}




int main()
{
	const int n = 5;
	vector <vector<double>> matrix(n, vector<double>(n, 1));
	vector<double> answer(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = i + j + 2;
		}
	}
	outm(matrix, n);
	///*
	double buf;
	for (int i = 0; i < n - 1; i++) {
		buf = matrix[i][i];
		for (int j = 0; j < n; j++) {
			if (buf != 0) {
				matrix[i][j] /= matrix[i][i];
			}
			else
				cout << "A[" << i << "][" << i << "] == 0";
			if (j == i) {
				for (int k = i + 1; k < n; k++) {
					matrix[k][j] = 0;
				}
			}
			for (int i1 = i + 1; i1 < n; i1++) {
				for (int j1 = 0; j1 < n; j1++) {
					matrix[i1][j1] = (matrix[i1][j1] * buf - matrix[i1][i] * matrix[i][j1]) / buf;
				}

			}
		}
	}
	outm(matrix, n);
	///*
	for (int i = n - 2; i > -1; i--) {
		for (int j = n - 2; j > -1; j--) {
			matrix[i][j] -= matrix[i + 1][j + 1] * matrix[i][i];
		}
	}//*/

	outm(matrix, n);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

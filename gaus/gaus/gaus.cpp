// gaus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;


// выводит массив размером N x N+1 в консоль
void outm(vector<vector<double>> matrix, int n) {
	cout.setf(ios::fixed);
	const unsigned accuracy = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (j == n)
				cout << " |  " << setprecision(accuracy) << matrix[i][j] << endl;
			else
				if(matrix[i][j] < 0)
					cout << "  " << setprecision(accuracy) << matrix[i][j];
				else
					cout << "   " << setprecision(accuracy) << matrix[i][j];
		}
	}
	cout << "-------------------------------------" << endl;
	cout.unsetf(ios::fixed);
}


int main()
{
	const int n = 5;
	vector <vector<double>> matrix(n, vector<double>(n + 1, 1));
	vector <vector<double>> nevyaz(n, vector<double>(n + 1, 1));
	vector<double> answer(n);
	double buf, buf2;
	double eps = 1 * pow(10, -2);

	matrix[0][1] = -0.66;
	matrix[1][1] = -0.59;
	matrix[2][1] = -0.8;
	matrix[3][1] = -0.97;
	matrix[4][1] = 0.33;
	matrix[0][2] = 0.46;
	matrix[1][2] = -0.46;
	matrix[2][2] = -0.24;
	matrix[3][2] = -0.46;
	matrix[4][2] = -0.28;
	matrix[0][3] = 0.62;
	matrix[1][3] = 0.63;
	matrix[2][3] = -0.51;
	matrix[3][3] = 0.27;
	matrix[4][3] = -0.94;
	matrix[0][4] = 0.83;
	matrix[1][4] = -0.68;
	matrix[2][4] = 0.98;
	matrix[3][4] = -0.45;
	matrix[4][4] = -0.92;
	matrix[0][0] = -0.02;
	matrix[1][0] = 0.52;
	matrix[2][0] = 0.28;
	matrix[3][0] = 0.38;
	matrix[4][0] = 0.17;

	matrix[0][5] = 0.24;
	matrix[1][5] = -0.98;
	matrix[2][5] = -0.94;
	matrix[3][5] = -0.84;
	matrix[4][5] = -0.79;

	nevyaz = matrix;

	outm(matrix, n);

	//метод халецкого
	{
	/*

	vector <vector<double>> b(n, vector<double>(n + 1, 0));
	vector <vector<double>> t(n, vector<double>(n + 1, 0));

	for (int i = 0; i < n; i++) {
		b[i][0] = matrix[i][0];
	}
	for (int j = 1; j < n; j++) {
		t[0][j] = matrix[0][j] / b[0][0];
	}
	for (int i = 0; i < n; i++) {
		t[i][i] = 1;
	}



	for (int k = 1; k < n; k++) {
		for (int i = k; i < n; i++) {
			double sum = 0;
			for (int m = 0; m <= k - 1; m++) {
				sum += b[i][m] * t[m][k];
			}
			b[i][k] = matrix[i][k] - sum;
		}
		for (int j = k + 1; j < n; j++) {
			double sum = 0;
			for (int m = 0; m <= k - 1; m++) {
				sum += b[k][m] * t[m][j];
			}
			t[k][j] = 1 / b[k][k] * (matrix[k][j] - sum);
		}
	}

	outm(t, n);
	outm(b, n);


	vector<double> y(n, 0);
	y[0] = matrix[0][n] / b[0][0];

	for (int i = 1; i < n; i++) {
		double sum = 0;
		for (int m = 0; m <= i - 1; m++) {
			sum += b[i][m] * y[m];
		}
		y[i] = (1 / b[i][i]) * (matrix[i][n] - sum);
	}

	cout << y[0] << " " << y[1] << " " << y[2] << " " << y[3] << " " << y[4] << endl;

	answer[n - 1] = y[n - 1];

	for (int i = n - 2; i > -1; i--) {
		double sum = 0;
		for (int m = i + 1; m < n; m++) {
			sum += t[i][m] * answer[m];
		}
		answer[i] = y[i] - sum;
	}

	cout << answer[0] << " " << answer[1] << " " << answer[2] << " " << answer[3] << " " << answer[4] << endl;

	*/
	///*

}


	// метод жордана-гаусса
	{
		for (int i = 0; i < n; i++) {
			buf = matrix[i][i];
			for (int j = i; j < n + 1; j++)
			{
				matrix[i][j] /= buf;
			}
			for (int k = i + 1; k < n; k++) {
				buf2 = matrix[k][i];
				for (int j = i; j < n + 1; j++)
				{
					matrix[k][j] -= buf2 * matrix[i][j];
				}
			}
		}
		for (int i = n - 1; i > -1; i--) {
			for (int k = i - 1; k > -1; k--) {
				buf = matrix[k][i];
				for (int j = n; j > -1; j--)
				{
					matrix[k][j] -= buf * matrix[i][j];
				}
			}
		}
		outm(matrix, n);
		for (int i = 0; i < n; i++) {
			answer[i] = matrix[i][n];
		}
		//*/

	}


	for (int i = 0; i < n; i++) {
		buf = 0;
		for (int j = 0; j < n; j++) {
			buf += nevyaz[i][j] * answer[j];
		}
		if (abs(nevyaz[i][n] - buf) > eps) cout << "Not required accuracy in line " << i << endl;
		else cout << "There is required accuracy in line " << i << endl;
	}
	
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

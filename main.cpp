#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>
#include <clocale>
#include <cstdlib> 
using namespace std;
int main()
{
    system("chcp 65001 > nul");
    int n;
    while (true)
    {
        cout << "Введите размер квадратной матрицы: ";
        if (!(cin >> n))
        {
            cout << "Ошибка! Введите целое число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (n <= 0)
        {
            cout << "Ошибка! Размер матрицы должен быть больше 0.\n";
            continue;
        }
        break;
    }
    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "\nВведите элементы матрицы:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            while (true)
            {
                cout << "A[" << i + 1 << "][" << j + 1 << "] = ";

                if (!(cin >> matrix[i][j]))
                {
                    cout << "Ошибка! Введите число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                break;
            }
        }
    }
    double determinant = 1.0;
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(matrix[j][i]) > fabs(matrix[pivot][i]))
            {
                pivot = j;
            }
        }
        if (fabs(matrix[pivot][i]) < 1e-10)
        {
            determinant = 0;
            break;
        }
        if (pivot != i)
        {
            swap(matrix[i], matrix[pivot]);
            swaps++;
        }

        for (int j = i + 1; j < n; j++)
        {
            double factor = matrix[j][i] / matrix[i][i];

            for (int k = i; k < n; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    if (determinant != 0)
    {
        for (int i = 0; i < n; i++)
        {
            determinant *= matrix[i][i];
        }
        if (swaps % 2 != 0)
        {
            determinant *= -1;
        }
    }
    cout << fixed << setprecision(4);
    cout << "\nОпределитель матрицы = " << determinant << endl;
    return 0;
}

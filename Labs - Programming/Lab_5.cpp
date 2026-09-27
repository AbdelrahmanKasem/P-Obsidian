#include <iostream>
#include <iomanip>
#include <cfloat>

using namespace std;

// ============================================================
// Exercise 1
// Find maximum above the main diagonal
// and minimum below the main diagonal
// ============================================================

void findValues(double* matrix, int n, int m,
                double& maximum, double& minimum)
{
    maximum = -DBL_MAX;
    minimum = DBL_MAX;

    bool foundAbove = false;
    bool foundBelow = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Position of matrix[i][j]
            int index = i * m + j;

            // Above main diagonal
            if (i < j)
            {
                if (matrix[index] > maximum)
                    maximum = matrix[index];

                foundAbove = true;
            }

            // Below main diagonal
            if (i > j)
            {
                if (matrix[index] < minimum)
                    minimum = matrix[index];

                foundBelow = true;
            }
        }
    }

    if (!foundAbove)
        maximum = 0;

    if (!foundBelow)
        minimum = 0;
}

// ============================================================
// Main
// ============================================================

int main()
{
    int n, m;

    cout << "Enter N and M: ";
    cin >> n >> m;

    // One continuous block of memory
    double* matrix = new double[n * m];

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i * m + j];
        }
    }

    cout << "\nMatrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(8)
                 << matrix[i * m + j];
        }

        cout << endl;
    }

    double maximum, minimum;

    findValues(matrix, n, m, maximum, minimum);

    cout << "\nMaximum above main diagonal: "
         << maximum << endl;

    cout << "Minimum below main diagonal: "
         << minimum << endl;

    // Free memory
    delete[] matrix;

    return 0;
}

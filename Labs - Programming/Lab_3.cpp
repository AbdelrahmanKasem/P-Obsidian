#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// ============================================================
// Exercise 1
// Find the first positive element in an integer array
// ============================================================

int* findFirstPositive(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            return &arr[i];
    }

    return nullptr;
}

// Count elements before and after the pointer
void countParts(int* arr, int n, int* positive,
                int& firstPart, int& secondPart)
{
    if (positive == nullptr)
    {
        firstPart = 0;
        secondPart = 0;
        return;
    }

    firstPart = positive - arr;
    secondPart = n - firstPart - 1;
}

// ============================================================
// Exercise 2
// Maximum above the main diagonal
// Minimum below the main diagonal
// ============================================================

void findMatrixValues(int** matrix, int n, int m,
                      int& maximum, int& minimum)
{
    maximum = INT_MIN;
    minimum = INT_MAX;

    bool foundAbove = false;
    bool foundBelow = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Above the main diagonal
            if (i < j)
            {
                if (matrix[i][j] > maximum)
                    maximum = matrix[i][j];

                foundAbove = true;
            }

            // Below the main diagonal
            if (i > j)
            {
                if (matrix[i][j] < minimum)
                    minimum = matrix[i][j];

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
// Main program
// ============================================================

int main()
{
    // --------------------------------------------------------
    // Exercise 1
    // --------------------------------------------------------

    int n;

    cout << "Enter size of arrays: ";
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];

    cout << "Enter array A:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter array B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    int* posA = findFirstPositive(A, n);
    int* posB = findFirstPositive(B, n);

    int firstA, secondA;
    int firstB, secondB;

    countParts(A, n, posA, firstA, secondA);
    countParts(B, n, posB, firstB, secondB);

    cout << "\n--- Array A ---\n";

    if (posA != nullptr)
    {
        cout << "First positive element: " << *posA << endl;
        cout << "Elements before it: " << firstA << endl;
        cout << "Elements after it: " << secondA << endl;
    }
    else
    {
        cout << "No positive element found.\n";
    }

    cout << "\n--- Array B ---\n";

    if (posB != nullptr)
    {
        cout << "First positive element: " << *posB << endl;
        cout << "Elements before it: " << firstB << endl;
        cout << "Elements after it: " << secondB << endl;
    }
    else
    {
        cout << "No positive element found.\n";
    }

    // --------------------------------------------------------
    // Exercise 2
    // --------------------------------------------------------

    int rows, cols;

    cout << "\nEnter matrix rows and columns: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    cout << "Enter matrix:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    }

    int maximum, minimum;

    findMatrixValues(matrix, rows, cols, maximum, minimum);

    cout << "\nMaximum above main diagonal: "
         << maximum << endl;

    cout << "Minimum below main diagonal: "
         << minimum << endl;

    // Free memory
    delete[] A;
    delete[] B;

    for (int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}

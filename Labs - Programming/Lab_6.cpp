#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// ============================================================
// Product structure
// ============================================================

struct Product
{
    char* name;      // Product name
    double price;    // Price
    int quant;       // Quantity
};

// ============================================================
// Create a Product
// ============================================================

Product createProduct(const char* name, double price, int quant)
{
    Product p;

    p.name = new char[strlen(name) + 1];
    strcpy(p.name, name);

    p.price = price;
    p.quant = quant;

    return p;
}

// ============================================================
// Free memory of one Product
// ============================================================

void deleteProduct(Product& p)
{
    delete[] p.name;
    p.name = nullptr;
}

// ============================================================
// Exercise 1
// Search product by name
// ============================================================

int findProductByName(Product* products,
                      int n,
                      const char* name)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(products[i].name, name) == 0)
            return i;
    }

    return -1;
}

// ============================================================
// Exercise 2
// Find all products with quantity less than given value
// ============================================================

void findProductsWithLowQuantity(Product* products,
                                  int n,
                                  int limit)
{
    bool found = false;

    cout << "\nProducts with quantity < "
         << limit << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (products[i].quant < limit)
        {
            cout << products[i].name
                 << " | price = " << products[i].price
                 << " | quantity = " << products[i].quant
                 << endl;

            found = true;
        }
    }

    if (!found)
        cout << "No products found.\n";
}

// ============================================================
// Exercise 3
// Sort database by decreasing price
// ============================================================

void sortByPrice(Product* products, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (products[j].price < products[j + 1].price)
            {
                swap(products[j], products[j + 1]);
            }
        }
    }
}

// ============================================================
// Print database
// ============================================================

void printProducts(Product* products, int n)
{
    cout << "\nWarehouse:\n";

    for (int i = 0; i < n; i++)
    {
        cout << products[i].name
             << " | price = " << products[i].price
             << " | quantity = " << products[i].quant
             << endl;
    }
}

// ============================================================
// Main
// ============================================================

int main()
{
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    Product* products = new Product[n];

    // --------------------------------------------------------
    // Input database
    // --------------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        char name[100];
        double price;
        int quant;

        cout << "\nProduct " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Price: ";
        cin >> price;

        cout << "Quantity: ";
        cin >> quant;

        products[i] = createProduct(name, price, quant);
    }

    printProducts(products, n);

    // --------------------------------------------------------
    // Exercise 1: Search by name
    // --------------------------------------------------------

    char searchName[100];

    cout << "\nEnter product name to search: ";
    cin >> searchName;

    int index = findProductByName(
        products,
        n,
        searchName
    );

    if (index != -1)
    {
        cout << "Product found:\n";
        cout << "Name: " << products[index].name << endl;
        cout << "Price: " << products[index].price << endl;
        cout << "Quantity: " << products[index].quant << endl;
    }
    else
    {
        cout << "Product not found.\n";
    }

    // --------------------------------------------------------
    // Exercise 2
    // --------------------------------------------------------

    int limit;

    cout << "\nEnter quantity limit: ";
    cin >> limit;

    findProductsWithLowQuantity(
        products,
        n,
        limit
    );

    // --------------------------------------------------------
    // Exercise 3
    // --------------------------------------------------------

    sortByPrice(products, n);

    cout << "\nAfter sorting by decreasing price:\n";

    printProducts(products, n);

    // --------------------------------------------------------
    // Free memory
    // --------------------------------------------------------

    for (int i = 0; i < n; i++)
        deleteProduct(products[i]);

    delete[] products;

    return 0;
}

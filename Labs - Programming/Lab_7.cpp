#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// ============================================================
// New structure: Date
// ============================================================

struct Date
{
    int day;
    int month;
    int year;
};

// ============================================================
// Product structure
// ============================================================

struct Product
{
    char* name;
    double price;
    int quant;
    Date date;       // Expiration date
};

// ============================================================
// Create Product
// ============================================================

Product createProduct(const char* name,
                      double price,
                      int quant,
                      Date date)
{
    Product p;

    p.name = new char[strlen(name) + 1];
    strcpy(p.name, name);

    p.price = price;
    p.quant = quant;
    p.date = date;

    return p;
}

// ============================================================
// Free product memory
// ============================================================

void deleteProduct(Product& p)
{
    delete[] p.name;
    p.name = nullptr;
}

// ============================================================
// Print date
// ============================================================

void printDate(Date date)
{
    cout << date.day << "."
         << date.month << "."
         << date.year;
}

// ============================================================
// Compare dates
//
// Returns:
// true if date1 is earlier than date2
// ============================================================

bool isEarlier(Date date1, Date date2)
{
    if (date1.year != date2.year)
        return date1.year < date2.year;

    if (date1.month != date2.month)
        return date1.month < date2.month;

    return date1.day < date2.day;
}

// ============================================================
// Exercise 1
// Find product by name
// ============================================================

int findProduct(Product* products,
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
// Add product to warehouse
//
// If product already exists:
// increase quantity.
//
// Otherwise:
// create a new position.
// ============================================================

void addProduct(Product*& products,
                int& n,
                const char* name,
                double price,
                int quantity,
                Date expiration)
{
    int index = findProduct(products, n, name);

    // Product already exists
    if (index != -1)
    {
        products[index].quant += quantity;

        cout << "Product already exists.\n";
        cout << "Quantity increased.\n";

        return;
    }

    // Create larger array
    Product* newProducts = new Product[n + 1];

    for (int i = 0; i < n; i++)
        newProducts[i] = products[i];

    newProducts[n] = createProduct(
        name,
        price,
        quantity,
        expiration
    );

    delete[] products;

    products = newProducts;
    n++;

    cout << "New product added.\n";
}

// ============================================================
// Exercise 3
// Write off product from warehouse
// ============================================================

void writeOffProduct(Product* products,
                     int n,
                     const char* name,
                     int quantity)
{
    int index = findProduct(products, n, name);

    if (index == -1)
    {
        cout << "Product not found.\n";
        return;
    }

    if (quantity > products[index].quant)
    {
        cout << "Not enough quantity in warehouse.\n";
        return;
    }

    products[index].quant -= quantity;

    cout << "Product written off successfully.\n";
}

// ============================================================
// Exercise 4
// Find expired products
// ============================================================

void findExpiredProducts(Product* products,
                         int n,
                         Date currentDate)
{
    bool found = false;

    cout << "\nExpired products:\n";

    for (int i = 0; i < n; i++)
    {
        if (isEarlier(products[i].date, currentDate))
        {
            cout << products[i].name
                 << " | quantity = "
                 << products[i].quant
                 << " | expiration = ";

            printDate(products[i].date);

            cout << endl;

            found = true;
        }
    }

    if (!found)
        cout << "No expired products.\n";
}

// ============================================================
// Save database to disk
// ============================================================

void saveDatabase(Product* products,
                  int n)
{
    ofstream file("warehouse.txt");

    if (!file)
    {
        cout << "Error opening file for writing.\n";
        return;
    }

    file << n << endl;

    for (int i = 0; i < n; i++)
    {
        file << products[i].name << endl;
        file << products[i].price << endl;
        file << products[i].quant << endl;

        file << products[i].date.day << " "
             << products[i].date.month << " "
             << products[i].date.year << endl;
    }

    file.close();

    cout << "Database saved to warehouse.txt\n";
}

// ============================================================
// Load database from disk
// ============================================================

bool loadDatabase(Product*& products,
                  int& n)
{
    ifstream file("warehouse.txt");

    if (!file)
        return false;

    file >> n;

    products = new Product[n];

    for (int i = 0; i < n; i++)
    {
        char name[200];

        file >> name;
        file >> products[i].price;
        file >> products[i].quant;

        file >> products[i].date.day
             >> products[i].date.month
             >> products[i].date.year;

        products[i].name =
            new char[strlen(name) + 1];

        strcpy(products[i].name, name);
    }

    file.close();

    return true;
}

// ============================================================
// Print database
// ============================================================

void printDatabase(Product* products, int n)
{
    cout << "\n========== WAREHOUSE ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". "
             << products[i].name
             << " | price = "
             << products[i].price
             << " | quantity = "
             << products[i].quant
             << " | expiration = ";

        printDate(products[i].date);

        cout << endl;
    }

    cout << "================================\n";
}

// ============================================================
// Main
// ============================================================

int main()
{
    // --------------------------------------------------------
    // Current date
    // --------------------------------------------------------

    Date currentDate;

    cout << "Enter current date (day month year): ";
    cin >> currentDate.day
        >> currentDate.month
        >> currentDate.year;

    // --------------------------------------------------------
    // Try to load existing database
    // --------------------------------------------------------

    Product* products = nullptr;
    int n = 0;

    if (loadDatabase(products, n))
    {
        cout << "Database loaded from file.\n";
    }
    else
    {
        cout << "No database found.\n";
        cout << "Creating new database.\n";

        cout << "Enter number of products: ";
        cin >> n;

        products = new Product[n];

        for (int i = 0; i < n; i++)
        {
            char name[200];
            double price;
            int quantity;

            Date expiration;

            cout << "\nProduct " << i + 1 << endl;

            cout << "Name: ";
            cin >> name;

            cout << "Price: ";
            cin >> price;

            cout << "Quantity: ";
            cin >> quantity;

            cout << "Expiration date "
                    "(day month year): ";

            cin >> expiration.day
                >> expiration.month
                >> expiration.year;

            products[i] = createProduct(
                name,
                price,
                quantity,
                expiration
            );
        }
    }

    // --------------------------------------------------------
    // Main menu
    // --------------------------------------------------------

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Show warehouse\n";
        cout << "2. Add product\n";
        cout << "3. Write off product\n";
        cout << "4. Find expired products\n";
        cout << "5. Save database\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        switch (choice)
        {
            // ------------------------------------------------
            // Show database
            // ------------------------------------------------
            case 1:
            {
                printDatabase(products, n);
                break;
            }

            // ------------------------------------------------
            // Add product
            // ------------------------------------------------
            case 2:
            {
                char name[200];
                double price;
                int quantity;
                Date expiration;

                cout << "Product name: ";
                cin >> name;

                cout << "Price: ";
                cin >> price;

                cout << "Quantity: ";
                cin >> quantity;

                cout << "Expiration date "
                        "(day month year): ";

                cin >> expiration.day
                    >> expiration.month
                    >> expiration.year;

                addProduct(
                    products,
                    n,
                    name,
                    price,
                    quantity,
                    expiration
                );

                break;
            }

            // ------------------------------------------------
            // Write off
            // ------------------------------------------------
            case 3:
            {
                char name[200];
                int quantity;

                cout << "Product name: ";
                cin >> name;

                cout << "Quantity to write off: ";
                cin >> quantity;

                writeOffProduct(
                    products,
                    n,
                    name,
                    quantity
                );

                break;
            }

            // ------------------------------------------------
            // Find expired products
            // ------------------------------------------------
            case 4:
            {
                findExpiredProducts(
                    products,
                    n,
                    currentDate
                );

                break;
            }

            // ------------------------------------------------
            // Save
            // ------------------------------------------------
            case 5:
            {
                saveDatabase(products, n);
                break;
            }

            // ------------------------------------------------
            // Exit
            // ------------------------------------------------
            case 0:
            {
                // Save automatically before exit
                saveDatabase(products, n);

                cout << "Program finished.\n";
                break;
            }

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    // --------------------------------------------------------
    // Free memory
    // --------------------------------------------------------

    for (int i = 0; i < n; i++)
        deleteProduct(products[i]);

    delete[] products;

    return 0;
}

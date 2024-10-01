//The project-Code

#include <iostream>
#include <iomanip> // for formatting output
using namespace std;

// Prices for each item
const double pantPrice = 25.0;
const double shirtPrice = 15.0;
const double sweetShirtPrice = 30.0;
const double discount = 0.05; // 5% discount

// Inventory for each item
int stockOfPants = 25;
int stockOfShirt = 40;
int stockOfSweatshirt = 10;

// Function declarations
void Inventory();
double UserOrder(int &pantsQuantity, int &shirtQuantity, int &sweatshirtQuantity);
double TotalPrice(double costOfPants, double costOfShirt, double costOfSweetShirt);
void Receipt(int pantsQuantity, int shirtQuantity, int sweatshirtQuantity, double total);

int main() {
    int pantsQuantity = 0, shirtQuantity = 0, sweatshirtQuantity = 0;
    double total;

    Inventory();
    total = processOrder(pantsQuantity, shirtQuantity, sweatshirtQuantity);
    Receipt(pantsQuantity, shirtQuantity, sweatshirtQuantity, total);

    return 0;
}

// Function to display available inventory
void Inventory() {
    cout << "Welcome to the Clothing Store!" << endl;
    cout << "We have the following items in stock:" << endl;
    cout << "1. Pants: $" << pantPrice << " (" << stockOfPants << " in stock)" << endl;
    cout << "2. Shirt: $" << shirtPrice << " (" << stockOfShirt << " in stock)" << endl;
    cout << "3. Sweatshirt: $" << sweetShirtPrice << " (" << stockOfSweatshirt << " in stock)" << endl;
}

// Function to process the order
double UserOrder(int &pantsQuantity, int &shirtQuantity, int &sweatshirtQuantity) {
    int choice, quantity;
    double costOfPants = 0, costOfShirt = 0, costOfSweetshirt = 0;
    
    while (true) {
        cout << "Please choose an item to buy (1-Pants, 2-Shirt, 3-Sweatshirt, 0 to finish): ";
        cin >> choice;
        
        if (choice == 0) break;

        cout << "Enter quantity: ";
        cin >> quantity;

        switch (choice) {
            case 1: // Pants
                if (quantity > stockOfPants) {
                    cout << "Sorry, not enough stock for pants." << endl;
                } else {
                    pantsQuantity = quantity;
                    costOfPants = pantPrice * quantity;
                    stockOfPants = quantity;
                }
                break;
            case 2: // Shirt
                if (quantity > stockOfShirt) {
                    cout << "Sorry, not enough stock for shirts." << endl;
                } else {
                    shirtQuantity = quantity;
                    costOfShirt = shirtPrice * quantity;
                    stockOfShirt = quantity;
                }
                break;
            case 3: // Sweatshirt
                if (quantity > stockOfSweatshirt) {
                    cout << "Sorry, not enough stock for sweatshirts." << endl;
                } else {
                    sweatshirtQuantity = quantity;
                    costOfSweetshirt = sweetShirtPrice * quantity;
                    stockOfSweatshirt = quantity;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}

// Function to calculate total cost and apply discount if applicable
double TotalPrice(double costOfPants, double costOfShirt, double costOfSweetshirt) {
    double total = costOfPants + costOfShirt + costOfSweetshirt;
    int total_items = (costOfPants > 0 ? 1 : 0) + (costOfShirt > 0 ? 1 : 0) + (costOfSweetshirt > 0 ? 1 : 0);

    if (total_items > 1) {
        total -= total * discount;
        cout << "You are qualified to get a 5% discoount! " << endl;
    }

    return total;
}

// Function to print the receipt
void Receipt(int pantsQuantity, int shirtQuantity, int sweatshirtQuantity, double total) {
    cout << fixed << setprecision(2);
    cout << "--- Receipt ---" << endl;
    if (pantsQuantity > 0) cout << "Pants: " << pantsQuantity << " x $" << pantPrice << " = $" << pantsQuantity * pantPrice << endl;
    if (shirtQuantity > 0) cout << "Shirts: " << shirtQuantity << " x $" << shirtPrice << " = $" << shirtQuantity * shirtPrice << endl;
    if (sweatshirtQuantity > 0) cout << "Sweatshirts: " << sweatshirtQuantity << " x $" << sweetShirtPrice << " = $" << sweatshirtQuantity * sweetShirtPrice << endl;
    cout << "Total Price: $" << total << endl;
    cout << "Thank you for shopping with us!" << endl;
}









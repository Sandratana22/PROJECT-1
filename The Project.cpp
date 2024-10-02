//The project-Code

#include <iostream>
#include <iomanip>

using namespace std;

// Prices for each item
const double pantPrice = 25.0;
const double shirtPrice = 15.0;
const double sweetShirtPrice = 30.0;
const double discount = 0.05; 

//Stock available for each item
int stockOfPants = 25;
int stockOfShirt = 40;
int stockOfSweatshirt = 10;

// Function prototype
void Inventory();
double UserOrder(int &pantsQuantity, int &shirtQuantity, int &sweatshirtQuantity, double &costOfPants, double &costOfShirt, double &costOfSweetShirt);
double TotalPrice(double costOfPants, double costOfShirt, double costOfSweetShirt);
void Receipt(int pantsQuantity, int shirtQuantity, int sweatshirtQuantity, double total);

//The main function to prints everything
int main() {
    int pantsQuantity = 0, shirtQuantity = 0, sweatshirtQuantity = 0; 
    double costOfPants = 0, costOfShirt = 0, costOfSweetShirt = 0; 
    double total = 0;

    Inventory();
    UserOrder(pantsQuantity, shirtQuantity, sweatshirtQuantity, costOfPants, costOfShirt, costOfSweetShirt); 
    total = TotalPrice(costOfPants, costOfShirt, costOfSweetShirt); 
    Receipt(pantsQuantity, shirtQuantity, sweatshirtQuantity, total);

    return 0;
}

// Function to prints available Items
void Inventory() {
    cout << fixed << setprecision(2); 
    cout << "-----Welcome to SA Clothing Store!-----" << endl;
    cout << "We have the following items in stock:" << endl;
    cout << "1. Pants: $" << pantPrice << " (" << stockOfPants << " in stock)" << endl;
    cout << "2. Shirt: $" << shirtPrice << " (" << stockOfShirt << " in stock)" << endl;
    cout << "3. Sweatshirt: $" << sweetShirtPrice << " (" << stockOfSweatshirt << " in stock)" << endl;
}

// Function to process the order
double UserOrder(int &pantsQuantity, int &shirtQuantity, int &sweatshirtQuantity, double &costOfPants, double &costOfShirt, double &costOfSweetShirt) {
    int choice, quantity;
     costOfPants = 0;
     costOfShirt = 0; 
     costOfSweetShirt = 0;

    //loop to allow the user to chose multiple item 
    while (true) {
        cout << "Please choose an item to buy (1-Pants, 2-Shirt, 3-Sweatshirt, 0 to stop): ";
        cin >> choice;
        
        if (choice == 0) break;

        cout << "Enter quantity: ";
        cin >> quantity;

        //This statement is used to handle the user's choice
        switch (choice) {
            case 1: //for Pants
                if (quantity > stockOfPants) {
                    cout << "Sorry, out of stock for pants." << endl;
                } else {
                    pantsQuantity = quantity;
                    costOfPants = pantPrice * quantity;
                    stockOfPants = quantity;
                }
                break;
            case 2: //for  Shirt
                if (quantity > stockOfShirt) {
                    cout << "Sorry, out of stock for shirts." << endl;
                } else {
                    shirtQuantity = quantity;
                    costOfShirt = shirtPrice * quantity;
                    stockOfShirt = quantity;
                }
                break;
            case 3: //for Sweatshirt
                if (quantity > stockOfSweatshirt) {
                    cout << "Sorry, out of stock for sweatshirts." << endl;
                } else {
                    sweatshirtQuantity = quantity;
                    costOfSweetShirt = sweetShirtPrice * quantity;
                    stockOfSweatshirt = quantity;
                }
                break;
            default:
                cout << "Wrong choice!" << endl;
                break;
        }
    }

    return 0;
}

// Function to calculate total price and see if user get a discount or not
double TotalPrice(double costOfPants, double costOfShirt, double costOfSweetShirt) {
    double total = costOfPants + costOfShirt + costOfSweetShirt;
    int total_items = (costOfPants > 0 ? 1 : 0) + (costOfShirt > 0 ? 1 : 0) + (costOfSweetShirt > 0 ? 1 : 0); //This is to track for every item purchaced

    //statement for the discount
    if (total_items > 1) {
        total -= total * discount;
        cout << "You got a 5% discoount! " << endl;
   }
     return total;
}

// Function to print the receipt
void Receipt(int pantsQuantity, int shirtQuantity, int sweatshirtQuantity, double total) {
    cout << fixed << setprecision(2); //This is to prints the price with two decimal places
    cout << endl; 

    cout << "--- Receipt ---" << endl;
    if (pantsQuantity > 0) cout << "Pants: " << pantsQuantity << " * $" << pantPrice << " = $" << pantsQuantity * pantPrice << endl;
    if (shirtQuantity > 0) cout << "Shirts: " << shirtQuantity << " * $" << shirtPrice << " = $" << shirtQuantity * shirtPrice << endl;
    if (sweatshirtQuantity > 0) cout << "Sweatshirts: " << sweatshirtQuantity << " * $" << sweetShirtPrice << " = $" << sweatshirtQuantity * sweetShirtPrice << endl;
    cout << "Total Price: $" << total << endl;
    cout << endl; 
    cout << "---Thank you for shopping with us!---" << endl;
}









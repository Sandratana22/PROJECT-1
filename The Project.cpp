//The project-Code

#include <iostream>

using namespace std; 

const double pantPrice = 40.0; 
const double shirtPrice = 15.0; 
const double sweetShirtPrice = 75.0; 
const double discount = 0.05; 

void ItemToChose();
int User_Choice();
int QuantityOfItem();

int main(){
  ItemToChose(); 
  int choice = User_Choice(); 
  int quantity = QuantityOfItem(); 

  return 0;
}

void ItemToChose() {
    cout << "Select any Items: " << endl; 
    cout << "1- Pants " << endl; 
    cout << "2- Shirts " << endl; 
    cout << "3- SweetShirts " << endl; 
}

int User_Choice(){
  int choice; 
  cout << "Enter your choice: "; 
  cin >> choice; 

if(choice < 1 || choice > 3) {
  cout << "Not exist in the store. " << endl; 
  return 0; 
} else {
  return choice; 
  }
}

int QuantityOfItem(){
  int quantity = 100; 
  cout << "How many Items do you want: "; 
  cin >> quantity; 

if(quantity < 1 || quantity > 100) {
  cout >> "Too much! 100 is the max you can buy. " << endl; 
  return 0; 
} else {
  return quantity; 
  }
}







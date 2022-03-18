//Aaron Winters 202102 CIS 164 13708
// ajwinters@dmacc.edu
//Week 3 Rebel Food Truck Model
// 09/11/2021

#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
    //On this submission all constants are in program unlike the working model.  I added a step when ordering a hot dog to
    //add chili, and thought the senior and military discount was a good idea so I added that as well - Aaron Winters

    //Constants - AW
    const int BURGERS_MAX = 200;
    const int HOT_DOGS_MAX = 200;
    const int BURGER_BUNS_MAX = 75;
    const int DOG_BUNS_MAX = 75;
    const int CHILI_OUNCE_MAX = 500;
    const int FRIES_MAX = 75;
    const int SODA_MAX = 200;
    const int FULL_CHILI_ORDER = 12;
    const int ADD_CHILI_ORDER = 4;

    //Menu prices - AW
    const double BURGER_PRICE = 5.0;
    const double HOT_DOG_PRICE = 5.0;
    const double CHILI_PRICE = 4.0;
    const double FRIES_PRICE = 5.0;
    const double ADD_CHILI_PRICE = 2.0;
    const double SODA_PRICE = 2.0;
    const double TAX = 1.05;
    const double MILITARY_SENIOR_DISCOUNT = .1;

    //Inventory - AW
    int currentBurgerInventory;
    int currentHotDogInventory;
    int currentChiliOuncesInventory;
    int currentBurgerBunInventory;
    int currentHotDogBunInventory;
    int currentFriesInventory;
    int currentSodaInventory;
    int burgersSold = 0;
    int hotDogsSold = 0;
    int chiliSold = 0;
    int sodaSold = 0;
    int friesSold = 0;
    int currentOrderAmount;
    double subtotal = 0.0;
    double totalSales = 0;
    bool orderYorN = false;
    
    string selection;

    // Just Burgers Chili and Hot Dogs for working model - AW
    //Updated to all variables 09-17-21 - AW

    //initial Inventory - AW
    cout << "Please enter number of Hamburger patties in inventory: " << endl;
    cin >> currentBurgerInventory;
    cout << "Please enter number of Hot Dogs in inventory: " << endl;
    cin >> currentHotDogInventory;
    cout << "Please enter number of ounces of Chili in inventory: " << endl;
    cin >> currentChiliOuncesInventory;
    cout << "Please enter number of hamburger buns in inventory: " << endl;
    cin >> currentBurgerBunInventory;
    cout << "Please enter number of Hot Dog Buns in inventory: " << endl;
    cin >> currentHotDogBunInventory;
    cout << "Please enter number of Fries in inventory: " << endl;
    cin >> currentFriesInventory;
    cout << "Please enter number of Sodas in inventory: " << endl;
    cin >> currentSodaInventory;

    cout << "Would you like to start today's business?  (Y for yes)" << endl;
    cin >> selection;

    //Gatekeeper - AW
    if (selection == "Y" || selection =="y") {
        orderYorN = true;
    }

    //real POS logic - AW
    while (orderYorN) {

        //Burger order - AW
        cout << "How many Hamburgers in this order?: " << endl;
        cin >> currentOrderAmount;
        
        currentBurgerInventory = currentBurgerInventory - currentOrderAmount;
        currentBurgerBunInventory = currentBurgerBunInventory - currentOrderAmount;
        if (currentBurgerInventory <= 0 || currentBurgerBunInventory <= 0) {
            cout << "Please discontinue Hamburger Sales and inform customer we are out of stock." << endl;
        }
        else if (currentBurgerInventory < 5 || currentBurgerBunInventory < 5) {
            cout << "Please discontinue Hamburger Sales" << endl;
        }
        else {
            burgersSold = burgersSold + currentOrderAmount;
            subtotal = currentOrderAmount * BURGER_PRICE;
        }

        //Hot Dogs -AW
        cout << "How many Hot Dogs in this order?: " << endl;
        cin >> currentOrderAmount;

        currentHotDogInventory = currentHotDogInventory - currentOrderAmount;
        currentHotDogBunInventory = currentHotDogBunInventory - currentOrderAmount;
        if (currentHotDogInventory <= 0 || currentHotDogBunInventory <= 0) {
            cout << "Please discontinue Hot Dog Sales and inform customer we are out of stock." << endl;
        }
        else if (currentHotDogInventory < 5 || currentHotDogBunInventory < 5) {
            cout << "Please discontinue Hot Dog Sales" << endl;
        }
        else if (currentHotDogInventory > 0 && currentBurgerBunInventory > 0 && currentOrderAmount > 0){

            cout << "Add chili to Hot Dog? (Y for yes)";
            cin >> selection;
            if (currentChiliOuncesInventory <= 0) {
                cout << "Please discontinue Chili Sales and inform customer we are out of stock." << endl;
            }
            else if (currentChiliOuncesInventory < 50) {
                cout << "Please discontinue Chili Sales" << endl;
            }
            else if (selection == "Y" || selection == "y") {
                hotDogsSold = hotDogsSold + currentOrderAmount;
                subtotal = subtotal + (currentOrderAmount * HOT_DOG_PRICE);
            }
            else {
                hotDogsSold = hotDogsSold + currentOrderAmount;
                subtotal = subtotal + ((currentOrderAmount * HOT_DOG_PRICE) + (currentOrderAmount * ADD_CHILI_PRICE));
                currentChiliOuncesInventory = currentChiliOuncesInventory - ADD_CHILI_ORDER;
            }
        }

        //Chili - AW
        cout << "How many orders of Chili in this order?: " << endl;
        cin >> currentOrderAmount;

        currentChiliOuncesInventory = currentChiliOuncesInventory - (currentOrderAmount * FULL_CHILI_ORDER);
        if (currentChiliOuncesInventory <= 0) {
            cout << "Please discontinue Chili Sales and inform customer we are out of stock." << endl;
        }
        else if (currentChiliOuncesInventory < 50) {
            cout << "Please discontinue Chili Sales" << endl;
        }
        else {
            chiliSold = chiliSold + currentOrderAmount;
            subtotal = subtotal + (currentOrderAmount * FULL_CHILI_ORDER);
            
        }

        //Fries - AW
        cout << "How many orders of Fries in this order?: " << endl;
        cin >> currentOrderAmount;

        currentFriesInventory = currentFriesInventory - currentOrderAmount;
        if (currentFriesInventory <= 0) {
            cout << "Please discontinue Fries Sales and inform customer we are out of stock." << endl;
        }
        else if (currentFriesInventory < 5) {
            cout << "Please discontinue Fries Sales" << endl;
        }
        else {
            friesSold = friesSold + currentOrderAmount;
            subtotal = subtotal + currentOrderAmount * FRIES_PRICE;
        }

        //Sodas - AW

        cout << "How many Sodas in this order?: " << endl;
        cin >> currentOrderAmount;

        currentSodaInventory = currentSodaInventory - currentOrderAmount;
        
        if (currentSodaInventory <= 0) {
            cout << "Please discontinue Hamburger Sales and inform customer we are out of stock." << endl;
        }
        else if (currentBurgerInventory < 5) {
            cout << "Please discontinue Soda Sales" << endl;
        }
        else {
            sodaSold = sodaSold + currentOrderAmount;
            subtotal = subtotal + currentOrderAmount * SODA_PRICE;
        }

        //Complete Order
        cout << "Does this complete the order? (Y for yes)" << endl;
        cin >> selection;
        if (selection == "Y" || selection == "y") {
            cout << "Military or Senior Discount? (Y for yes)" << endl;
            cin >> selection;
            if (selection == "Y" || selection == "y") {
                subtotal = (subtotal -(subtotal * MILITARY_SENIOR_DISCOUNT)) *  TAX;
                totalSales = totalSales + subtotal;
                cout << "Total Due: $" << subtotal << endl;
                subtotal = 0;
            }
            else {
                subtotal = subtotal * TAX;
                totalSales = totalSales + subtotal;
                cout << "Total Due: $";
                cout << fixed << setprecision(2) << subtotal << endl;
                subtotal = 0;
            }

            //End of Day

            cout << "Would you like to run end of day? (Y for yes)" << endl;
            cin >> selection;
            if (selection == "Y" || selection == "y") {
                cout << "Burgers Sold: " << burgersSold << endl;
                cout << "Hot Dogs Sold: " << hotDogsSold << endl;
                cout << "Ounces of Chili Sold: " << (chiliSold * FULL_CHILI_ORDER) << endl;
                cout << "Total Sales : $";
                cout << fixed << setprecision(2) << totalSales << endl;
                orderYorN = false;
            }

        }

    }

    

    //ending inventory - AW
    
   
    cout << "Burgers on hand: " << currentBurgerInventory << endl;
    cout << "Hot Dogs on hand: " << currentHotDogInventory << endl;
    cout << "Ounces of Chili on hand: " << currentChiliOuncesInventory << endl;
    cout << "Burgers Buns on hand: " << currentBurgerBunInventory << endl;
    cout << "Hot Dog Buns on hand: " << currentHotDogBunInventory << endl;
    cout << "Fries on hand: " << currentFriesInventory << endl;
    cout << "Sodas on hand: " << currentSodaInventory << endl;
    return 0;
}


//Lots of testing for this as I discovered for awhile you were offered chili on your hot dogs whether you ordered one or not.
//Also the addition of the Senior/Military discount played havok with my totals, which reminded me to set precision - AW
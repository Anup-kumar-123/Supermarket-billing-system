#include<iostream>         // BASIC HEADER FILE FOR INPUT & OUTPUT.
#include<vector>           // VECTOR LIBRARY.
#include<iomanip>          // HEADER FILE FOR BETTER ORDER LIST APPEARANCE.
#include<windows.h>        // WINDOWS.H FOR SLEEP COMMAND.
using namespace std;

struct Super_market{        // SUPER MARKET STRUCTURE.
    string Name;            // DATA MEMBERS
    int quatity;
    int price;
    int total;
}sm;                       // STRUCTURE NAME DECLARATION.

vector<Super_market> v;       // VECTOR ARRAY WHICH STORES DATA USING DYNAMIC MEMORY ALLOCATION.

int main(){                   // MAIN FUNCTION.

    int value;

    do{                        // MAIN MENU.........................
        cout << "\t\t ||............. SELECT OPTION .............||" << endl;      
        cout << "\t\t ||.........................................||" << endl;
        cout << "\t\t ||            1. ADD ITEM                  ||" << endl;
        cout << "\t\t ||            2. PRINT BILL                ||" << endl;
        cout << "\t\t ||            3. EDIT ORDER                ||" << endl;
        cout << "\t\t ||            4. RESET LIST                ||" << endl;
        cout << "\t\t ||            5. DELETE PRODUCT            ||" << endl;
        cout << "\t\t ||            0. Exit                      ||" << endl;
        cout << "\t\t ||.........................................||" << endl;

        cout << "Enter your choice :";          // USER CHOICE INPUT.
        cin >> value;

        if(value == 1){                        // CODE BLOCK FOR ADDING ITEMS TO THE LIST.

            system("cls");

            cout << "Items :"; cin >> sm.Name;
            cout << "Quantity :"; cin >> sm.quatity;
            cout << "Price :"; cin >> sm.price; 

            v.push_back(sm);

            cout << sm.Name << " (" <<sm.quatity << ")" << "added" << endl << endl;

            Sleep(1000);
            system("cls");                   // SLEEP & CLEAR SCREEN COMMAND. (FOR BETTER VISIBILITY).
        }

        else if (value == 2) {               // CODE BLOCK FOR SEEING THE TOTAL BILL OF THE ITEMS.
            system("cls");

            float grand_total = 0;
            float discount = 0.0;            // DISCOUNT AND TOTAL OF ALL ITEMS VARIABLE.
            string d;                        // ------------>    FOR DECISION OF USER.

            cout << "Enter the discont :";
            cin >> discount;

            cout << left << setw(16) << "Item"         // PRINTS THE ITEMS DETAILS LIST AND THE GRAND TOTAL AMOUNT OF ALL ITEMS.
                 << setw(10) << "Quantity"
                 << setw(10) << "Price"
                 << setw(10) << "Total" << endl;
            cout << "------------------------------------------------------------" << endl;

            for (int i = 0; i < v.size(); ++i) {
                v[i].total = v[i].price * v[i].quatity;
                grand_total += v[i].total;

                cout << left << setw(16) << v[i].Name
                     << setw(10) << v[i].quatity
                     << setw(10) << v[i].price
                     << setw(10) << v[i].total << endl;
            }
            if(discount != 0.0){                       // ALSO CONTAINS DISCOUNT FUNCTION IF THERE IS.
                grand_total = grand_total - (grand_total*discount/100);
            }
            cout << "------------------------------------------------------------" << endl;
            cout << "--------  GRAND TOTAL AMOUNT :      " << grand_total << endl;
            cout << endl<< endl;

            cout << "Enter ok / OK for exit the page :- ";       // UNTIL U TYPE OK OR ok IT WILL STAY THERE.
            cin >> d;
            if(d == "ok" || d == "OK"){
                system("cls");                       // CLEAR SCREEN.
            }
        }

        else if(value == 3){            // CODE BLOCK FOR EDITING ANY ITEM IF THERE IS SOME MISTAKE.
            
            system("cls");

            bool found = false;

            string order_name;
            cout << "Enter name of the product : ";         // ENTER NAME OF THE PRODUCT FOR SEARCHING IN THE LIST.
            cin >> order_name;

            for(int i=0; i<v.size(); ++i){
                if(v[i].Name == order_name){            // IF BLOCK EXECUTE OT ITEM FOUND IN THE LIST.

                    found = true;

                    cout << "Item :" ; cin >> v[i].Name;
                    cout << "Quantity :"; cin >> v[i].quatity;
                    cout << "Price :"; cin >> v[i].price;
                    cout << endl << "Updated Succesfully !"<<endl;
                    
                    break;
                }
            }

            if(!found){                   // IF BLOCK EXECUTED IF THE ITEM NOT FOUND.
                cout << "Item not found in the list. "<< endl;
            }

            Sleep(2000);
            system("cls");                // SLLEP TIMER AND SCREEN CLEAR COMMAND.

        }

        else if(value == 4){             // CODE BLOCK IF YOU WANT TO DELETE ALL THE PREVOIS BUYER DEATILS 
                                         // AND MAKE A NEW LIST FOR NEW CUSTOMER AND ITEMS.

            system("cls");

            string des;
            cout << "Enter ok / OK for proceed :";       // DECISION OF THE USER FOR PROCEEDING.
            cin >> des;

            if(des == "ok" || des == "OK"){     // LIST CLEAR USING VECTOR clear() COMMAND AT A SINGLE TIME.
                v.clear();
            }

            system("cls");

            cout << "List deleted succesfully !" << endl;
            Sleep(1500);
            system("cls");
        }

        else if(value == 5){             // CODE BLOCK FOR DELETING A PARTICULAR ITEMS IF USER DON'T WANT TO BUY IT.
            system("cls");

            bool found = false;

            string item_name;
            cout << "Enter item name :";
            cin >> item_name;

            for(int i=0; i<v.size(); ++i){
                if(item_name == v[i].Name){

                    found = true;

                    v[i].Name = v[i+1].Name;            // REPALACE ONE BY ONE TO EACH OTHER AFTER THE ENTERED ITEM NAME.
                    v[i].quatity = v[i+1].quatity;
                    v[i].price = v[i+1].price;
                    v[i].total = v[i+1].total;
                }
            }

            cout << "Item deleted Succesfully !" << endl;
            Sleep(2000);

            v.pop_back();          // DELETE THE LAST ONES MEMORY.

            if(!found){                // IF BLOCK IF THE ITEM NOT FOUND.
                cout << "Item not found in the list. "<< endl;
            }

            system("cls");
            Sleep(2000);

        }

        else if(value == 0){             // THE LAST CODE BLOCK FOR TERMINATING THE WHOLE PROGRAM.
            system("cls");
            cout << "Thank for your work , see you tommorow !" << endl;
            Sleep(2000);
            system("cls");
            cout << "          Byy Byyy ....... "<< endl;
            Sleep(3000);
            exit(0);
    
        }
    }
    while(value != 0);              // CONDITION FOR THE CONTINOUS LOOP.(WORK UNTIL USER PRESS 0).

    
    return 0;
}

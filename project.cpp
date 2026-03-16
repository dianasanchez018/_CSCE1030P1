#include <iostream>
#include <string> // gives name
#include <cctype> 
#include <cstdlib>
#include <ctime> 
#include <cmath>

using namespace std;

int main()
{
 cout << "+-----------------------------------------------------------------------+" << endl;
    cout << "|                     Computer Science and Engineering                  |" << endl;
    cout << "|                      CSCE 1030 - Computer Science I                   |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "| Group Members:                                                        |" << endl;
    cout << "| 1. Gabriella Vazquez (gv0244) gabriellavazquez@my.unt.edu             |" << endl;
    cout << "| 2. Perla Diana Sanchez Rincon (pds0137) perlasanchezrincon@my.unt.edu |" << endl;
    cout << "| 3. Michell Mata Martinez (mam1460) MichellMataMartinez@my.unt.edu     |" << endl;
    cout << "| 4. Casiel Montoya Muro (cm1645) casielmontoyamuro@my.unt.edu          |" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl;

    int points = 50;
    string userName;
    enum MenuChoice { MULTIPLY = 1, DIVIDE, AVERAGE, REVEAL, GIVEUP, EXIT };
    bool isInvalid;
    int randnum1; //Assigning "random numbers" to ints
    int randnum2; 
    char play_again = 'y';//char to ask user if they want to play again after each round.
    int Choice;

        do {
            cout << "Enter your name: ";
            getline(cin, userName);
            isInvalid = false;
    
            for (int i = 0; i < userName.length(); i++) {
                if (!isalnum(userName[i]) && !isspace(userName[i])) {
                    cout << "Your name must contain alphanumeric characters and spaces only." << endl;
                    cout << "Please re-enter your name." << endl;
                    isInvalid = true;
                    break;
                }
            }
        } while (isInvalid || userName.empty());
        cout << "Welcome " << userName << "!" << endl;

    
    srand(time(NULL)); //random number generator seeded

        while (play_again == 'y' || play_again == 'Y'){ //if user wants to play again, regenerate random numbers and display menu again.

            do {
                randnum1 = rand() % 51 + 50; //range of random number between 50 - 100 / inlcusive
                randnum2 = rand() % 51 + 50;
            } while (randnum1>=randnum2); //RULE : randnum1 must be LESS than randnum2. If not, keep generating. 
                cout<<"Your two random numbers have been generated!\n"<<endl;
                bool solved = false; // boolean if the user guess corrected
    // cout<<"Random number 1: "<<randnum1<<endl<<"Random number 2: "<<randnum2; (double checking it meets requirement)
          while(!solved) { // keep showing menu 
            while(true){
                cout<<"Please select from the menu: "<<endl; //Asking user to select from menu to begin guessing.
                cout<<"1. MULTIPLY"<<endl<<"2. DIVIDE"<<endl<<"3. AVERAGE"<<endl<<"4. REVEAL"<<endl<<"5. GIVE-UP"<<endl<<"6. EXIT"<<endl;
                cout<<"Please enter choice(1-6):  ";
                cin>>Choice;
                    if(Choice >= 1 && Choice <= 6){ //user iput from 1-6 are only valid.
                        break;
                    }
                cout<<"Error: Please enter valid options only! \n"<<endl; 
            } 

            switch(Choice){
                case MULTIPLY:

                    int exact_product;
                    int guess_product;
                    cout<<"Enter your guess for the PRODUCT of the two random numbers: ";
                    cin>>guess_product;

                    /*The absolute value of the difference between the guess_product and the exact_product
                    between both nums have to be LESS than 50 
                    inorder for the user to increment ++5 points. If incorrect -- decrement by 1 point.

                    If correct ask if user wants to play again(display menu). 
                    */
                    cout<<"Do you wish to play again? (y/n): ";
                    cin>>play_again;
                    solved = true; //if user guesses correctly, solved becomes true and menu will be displayed again if they want to play again.
                    break;
                
                case DIVIDE:
                    cout<<"Enter your guess for the QUOTIENT of the two random numbers: ";
                    break;
                case AVERAGE:
                    cout<<"Enter your guess for the AVERAGE of the two random numbers: ";
                    break;
                case REVEAL:
                    cout<<"The two random numbers are: "<<randnum1<<" and "<<randnum2<<endl;
                    break;
                case GIVEUP:
                    cout<<"Better luck next time! The numbers were: "<<randnum1<<" and "<<randnum2<<endl;
                    break;
                case EXIT:
                    cout<<"Exiting game. Goodbye!"<<endl;
                    break;
                default:
                    cout<<"Error: Please enter options (1-6)only! \n"<<endl;
                    break;
            }
            }
        }
    return 0;
}

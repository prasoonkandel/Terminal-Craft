#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "utils.h"

using namespace std;

void playHeadOrTails() {
    bool playAgain = true;
    char choice;
    int userChoice;
    int computerChoice;
    while (playAgain) {
        cout << "Do you want to choose Head or Tails? (H/T): ";
 
        cin >> choice;
        choice = toupper(choice);

        if (choice != 'H' && choice != 'T') {
            cout << "Invalid choice. Please choose H or T." << endl;
            continue;
        }
        else {
            if (choice == 'H') {
                userChoice = 1;
            } else {
                userChoice = 2;
            }
        }

        computerChoice = randInt(1, 2);
        if (userChoice == computerChoice) {
            if (userChoice == 1) {
                cout << "It's Head! You win!" << endl;
            } else {
                cout << "It's Tails! You win!" << endl;
            }
        } else {
            if (computerChoice == 1) {
                cout << "It's Head! You lose!" << endl;
            } else {
                cout << "It's Tails! You lose!" << endl;
            }
        }
        cout << "Do you want to play again? (Y/N): ";
        char again;
        cin >> again;
        if (toupper(again) != 'Y') {
            playAgain = false;
        }
    }
}


void playRockPaperScissors() {
    
}

int main(){
   srand(time(nullptr)); 

    bool endProgram = false;
    while (!endProgram) {
cout << "#====================================================#" << endl;
cout << "         Welcome to the game collection!          " << endl;
cout << "#====================================================#" << endl << endl;


    cout << "1. Head or Tails \t 2. Rock Paper Scissors \t 3. Coming Soon" << endl;
    
    cout << "4. Coming Soon   \t 5. Coming Soon         \t 6. End Game" << endl << endl;
    cout << "#====================================================#" << endl << endl;
    cout << "Select a game to play:";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            cout << "You selected Head or Tails!" << endl << endl;
            playHeadOrTails();
            break;
        case 2:
            cout << "You selected Rock Paper Scissors!" << endl;
           
            break;
        case 3:
            cout << "This game is coming soon!" << endl;
            break;
        case 4:
            cout << "This game is coming soon!" << endl;
            break;
            
        case 5:
            cout << "This game is coming soon!" << endl;
            break;
            
        case 6:
            cout << "Thank you for playing! Goodbye!" << endl;
            endProgram = true;
            break;    
        default:
            cout << "Invalid choice. Please select a valid game." << endl;
    }}
return 0;    
}
 
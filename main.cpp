#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "utils.h"

using namespace std;

bool checkWin_game3(const vector<char>& board, char player) {
    if (board[0] == player && board[1] == player && board[2] == player) return true;
    else if (board[3] == player && board[4] == player && board[5] == player) return true;
    else if (board[6] == player && board[7] == player && board[8] == player) return true;
    else if (board[0] == player && board[3] == player && board[6] == player) return true;
    else if (board[1] == player && board[4] == player && board[7] == player) return true;
    else if (board[2] == player && board[5] == player && board[8] == player) return true;
    else if (board[0] == player && board[4] == player && board[8] == player) return true;
    else if (board[2] == player && board[4] == player && board[6] == player) return true;
    else return false;
}

bool checkDraw_game3(const vector<char>& board) {
    if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
        board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
        board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
        
        {
        return true; }
    else{
    return false; }
}
void printBoard_game3(const vector<char>& board) {
    cout << "\033[34m"; 

    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |     \n";

    cout << "\033[0m";

    

}

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
     bool playAgain = true;
    char choice;
    int userChoice;
    int computerChoice;

    while (playAgain)
    {
        cout << "Choose Rock, Paper or Scissors (R/P/S): ";
        cin >> choice;
        choice = toupper(choice);
        if (choice != 'R'&& choice != 'P' && choice != 'S') {
            cout << "Invalid choice. Please choose R, P or S." << endl;
            continue;
        }
        else {
            if (choice == 'R') {
                userChoice = 1;
            } else if (choice == 'P') {
                userChoice = 2;
            } else {
                userChoice = 3;
            }
        }
        computerChoice = randInt(1, 3);

        if (userChoice == computerChoice){
            cout << "It's a tie!" << endl;
        } else if (userChoice == 1 && computerChoice==3)
        {
            cout << "Rock crushes Scissors! You win!" << endl;

        }else if (userChoice == 2 && computerChoice==1)
        {
            cout << "Paper covers Rock! You win!" << endl;

        }else if (userChoice == 3 && computerChoice==2)
        {
       
            cout << "Scissors cuts Paper! You win!" << endl;
               } else if (computerChoice == 1 && userChoice==3)
        {
            cout << "Rock crushes Scissors! You lose!" << endl;

        }else if (computerChoice == 2 && userChoice==1)
        {
            cout << "Rock gets covered by Paper! You lose!" << endl;

        }else if (computerChoice == 3 && userChoice==2)
        {
             cout << "Paper gets cut by Scissors! You lose!" << endl;
       }
    
        cout << "Do you want to play again? (Y/N): ";
        char again;
        cin >> again;
        if (toupper(again) != 'Y') {
            playAgain = false;
        }
    }
}

void playTicTacToe() {
    vector<char> board(9, ' '); 
    int userPos;
    int computerPos;


    bool playing = true;
    while (playing) {
 
        printBoard_game3(board);
      

        cout << "Choose a position (1-9) to place your mark: ";
    
        cin >> userPos;
        userPos--;
        if (userPos < 0 || userPos >= 9 || board[userPos] != ' ') {
            cout << "Invalid move. Try again." << endl;
            playing = true; 
            continue;
    }else {

            board[userPos] = 'X'; 

    }
    
    bool userWin = checkWin_game3(board, 'X');
  
        if (userWin) {
            printBoard_game3(board);
            cout << "Congratulations! You win!" << endl;
            playing = false;
            continue;
        }
        
        computerPos = randInt(0, 8);
        while (board[computerPos] != ' ') {
            computerPos = randInt(0, 8);
        }
        board[computerPos] = 'O';}

    bool computerWin = checkWin_game3(board, 'O');
  
        if (computerWin) {
            printBoard_game3(board);
            cout << "A dumb bot wins! You lose!" << endl;
            playing = false;
        }    


    if (playing) {
   bool draw = checkDraw_game3(board);
   
        if (draw) {
            printBoard_game3(board);
            cout << "It's a draw!" << endl;
            playing = false;
        }
    }else {
        //just nothing here womp womp
    }
    }
int main(){
cout << "\033[33m" 
              << "  ______                    _             __   ______           ______ \n"
              << " /_  __/__  _________ ___  (_)___  ____ _/ /  / ____/________ _/ __/ /_\n"
              << "  / / / _ \\/ ___/ __ `__ \\/ / __ \\/ __ `/ /  / /   / ___/ __ `/ /_/ __/\n"
              << " / / /  __/ /  / / / / / / / / / / /_/ / /  / /___/ /  / /_/ / __/ /_  \n"
              << "/_/  \\___/_/  /_/ /_/ /_/_/_/ /_/\\__,_/_/   \\____/_/   \\__,_/_/  \\__/  \n"
              << "\033[0m" << endl; 
   srand(time(nullptr)); 
   

    bool endProgram = false;
    while (!endProgram) {
cout << "#====================================================#" << endl;
cout << "         Welcome to the game collection!          " << endl;
cout << "#====================================================#" << endl << endl;


    cout << "1. Head or Tails \t 2. Rock Paper Scissors \t 3. Tic Tac Toe" << endl; 
    cout << "4. Coming Soon   \t 5. Coming Soon         \t 6. End Game" << endl << endl;

    cout << "#====================================================#" << endl << endl;
    cout << "Select a game to play:";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            cout << "You selected Head or Tails!"  << endl << endl<<  endl;
            playHeadOrTails();
            break;
        case 2:
            cout << "You selected Rock Paper Scissors!" << endl << endl << endl;
            playRockPaperScissors();
            break;
        case 3:
            cout << "You selected Tic Tac Toe!" << endl << endl<< endl;
            playTicTacToe();
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
 
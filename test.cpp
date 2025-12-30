// The files containg my all testting sessions

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "utils.h"

void printBoard(const vector<char>& board) {
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

void sessionOne() {
    vector<char> board(9, ' '); 
    int userPos;
    int computerPos;


    bool playing = true;
    while (playing) {
 
        printBoard(board);
      

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
  

        
        computerPos = randInt(0, 8);
        while (board[computerPos] != ' ') {
            computerPos = randInt(0, 8);
        }
        board[computerPos] = 'O';}
    
    playing = true;


    }


int main() {
    cout << "Which Testing session do you want to run?" << endl;
    cout << "1. Session One" << endl;  
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
           
            cout << "Running Testing Session One..." << endl << endl << endl;

            sessionOne();
        
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            break;
    }
    return 0;
}
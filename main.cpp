#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "utils.h"

using namespace std;

void hangmanDisplay(int attemptsLeft) {
   cout << "\33[32m";
   cout << "  _______\n";
   cout << " |/      |\n";
   cout << " |      " << (attemptsLeft <= 5 ? "(_)" : "") << "\n";
   cout << " |      " << (attemptsLeft <= 4 ? "|" : "") << (attemptsLeft <= 3 ? "\\" : "") << (attemptsLeft <= 2 ? "/" : "") << "\n";
   cout << " |      " << (attemptsLeft <= 1 ? "/" : "") << (attemptsLeft == 0 ? " \\" : "") << "\n";
   cout << " |\n";                             
   cout << "_|___\n";
    cout << "\33[0m";
}


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
        cin.clear();
        cin.ignore(10000, '\n');
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
                cout << "\033[32m";
                cout << "It's Head! You win!" << endl;
                cout << "\033[0m";
            } else {
                cout << "\033[32m";
                cout << "It's Tails! You win!" << endl;
                cout << "\033[0m";
            }
        } else {
            if (computerChoice == 1) {
                cout << "\033[31m";
                cout << "It's Head! You lose!" << endl;
                cout << "\033[0m";
            } else {
                cout << "\033[31m";
                cout << "It's Tails! You lose!" << endl;
                cout << "\033[0m";
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
            cout << "\033[32m";
            cout << "Rock crushes Scissors! You win!" << endl;
            cout << "\033[0m";

        }else if (userChoice == 2 && computerChoice==1)
        {
            cout << "\033[32m";
            cout << "Paper covers Rock! You win!" << endl;
            cout << "\033[0m";

        }else if (userChoice == 3 && computerChoice==2)
        {

            cout << "\033[32m";
       
            cout << "Scissors cuts Paper! You win!" << endl;
            cout << "\033[0m";
               } else if (computerChoice == 1 && userChoice==3)
        {
            cout << "\033[31m";
            cout << "Rock crushes Scissors! You lose!" << endl;
            cout << "\033[0m";

        }else if (computerChoice == 2 && userChoice==1)
        {
            cout << "\033[31m";
            cout << "Rock gets covered by Paper! You lose!" << endl;
            cout << "\033[0m";

        }else if (computerChoice == 3 && userChoice==2)
        {
             cout << "\033[31m";
             cout << "Paper gets cut by Scissors! You lose!" << endl;
             cout << "\033[0m";
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
            cout << "\033[31m";
            cout << "Invalid move. Try again." << endl;
            cout << "\033[0m";
            playing = true; 
            continue;
    }else {

            board[userPos] = 'X'; 

    }
    
    bool userWin = checkWin_game3(board, 'X');
  
        if (userWin) {
            printBoard_game3(board);
            cout << "\033[32m";
            cout << "Congratulations! You win!" << endl;
            cout << "\033[0m";
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
            cout << "\033[31m";
            cout << "A dumb bot wins! You lose!" << endl;
            cout << "\033[0m";
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


void playHangman() {
   const vector<string> words = {
    "computer",
    "science",
    "planet",
    "history",
    "library",
    "mountain",
    "network",
    "teacher",
    "student",
    "language"
};

  bool playing = true;
  string randomWord;
  int randomInt;
  

  while (playing){

    randomInt = randInt(0,9);
    randomWord = words[randomInt];
    
    string guessedWord(randomWord.length(), '_');
    int attempts = 6;
    int maxAttempts = 6;
    vector<char> guessedLetters;
    bool wordGuessed = false;

    cout << "Try to guess the word!" << endl;
    while (attempts > 0 && !wordGuessed)
    {
        cout << "Word: " << guessedWord << endl;
        hangmanDisplay(attempts);
        cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            cout << letter << " ";
        }
        cout << endl;   
        cout << "Attempts left: " << attempts << "/" << maxAttempts << endl;
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        guess = tolower(guess);
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You already guessed that letter. Try again." << endl;
            continue;
        }else {
            guessedLetters.push_back(guess);
        }
        bool correctGuess = false;
        for (size_t i = 0; i < randomWord.length(); ++i) {
            if (randomWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }
        if (!correctGuess) {
            attempts--;
        }
        wordGuessed = (guessedWord == randomWord);
    }

    if (wordGuessed) {
        
        cout << "Word: " << guessedWord << endl;
        hangmanDisplay(attempts);
        cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            cout << letter << " ";
        }
        cout << endl;   
        cout << "Attempts left: " << attempts << "/" << maxAttempts << endl;
        cout << "\33[32m";
        cout << "Congratulations! You guessed the word: " << randomWord << endl;
        cout << "\33[0m";
    } else {
        
        cout << "Word: " << guessedWord << endl;
        hangmanDisplay(attempts);
        cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            cout << letter << " ";
        }
        cout << endl;   
        cout << "Attempts left: " << attempts << "/" << maxAttempts << endl;
        cout << "\33[31m";
        cout << "Game Over! The word was: " << randomWord << endl;
        cout << "\33[0m";
    }

    cout << "Do you want to play again? (Y/N): ";
    char again;
    cin >> again;
    if (toupper(again) != 'Y') {
        playing = false;
    }
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
    cout << "4. Hangman       \t 5. Coming Soon         \t 6. End Game" << endl << endl;

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
            cout << "You selected Hangman!" << endl << endl << endl;
            playHangman();
            break;
            
        case 5:
            cout << "This game is coming soon!" << endl;
            break;
            
        case 6:
            cout << "Thank you for playing! Goodbye!" << endl;
            endProgram = true;
            break;    
        default:
            cout << "\033[31m";
            cout << "Invalid choice. Please select a valid game." << endl;
            cout << "\033[0m";
    }}
return 0;    
}
 
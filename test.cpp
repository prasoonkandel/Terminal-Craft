// The files containg my all testting sessions

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "utils.h"


void sessionOne() {
    vector<int> board(9, ' ');

    cout << R"(
    ⠀⠀  ⢰⡆⠀⠀⠀⠀⠀⠀⠀⠀⢰⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⢀⣀⣀⣀⣀⣀⣸⣇⣀⣀⣀⣀⣀⣀⣀⣸⣇⣀⣀⣀⣀⣀⡀
⠈⠉⠉⠉⠉⠉⢹⡏⠉⠉⠉⠉⠉⠉⠉⢹⡏⠉⠉⠉⠉⠉⠁
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⢀⣀⣀⣀⣀⣀⣸⣇⣀⣀⣀⣀⣀⣀⣀⣸⣇⣀⣀⣀⣀⣀⡀
⠈⠉⠉⠉⠉⠉⢹⡏⠉⠉⠉⠉⠉⠉⠉⢹⡏⠉⠉⠉⠉⠉⠁
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠸⠇⠀⠀⠀⠀)" <<endl;

}


int main() {
    cout << "Which Testing session do you want to run?" << endl;
    cout << "1. Session One" << endl;  

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
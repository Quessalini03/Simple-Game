#include <iostream>
#include <vector>

using std::cout;
using std::cin;

void inputAndCheck(bool &validity, std::vector<int> &game, int &index);
void Human_Player(std::vector<int> &game);
void COM_Player(std::vector<int> &game);

int index = 0;
bool playerWin = false;

int main() {
    std::vector<int> game;
    int index = 0;
    while (game.size() < 20) {
        Human_Player(game);
        if (playerWin == true) {
            break;
        }
        COM_Player(game);
    }
    for (int i = 0; i < game.size(); i++) {
        cout << game[i] << '\n';
    }
    if (playerWin == true) {
        cout << "You WIN !!!";
    } else {
        cout << "You LOSE, HAHAHA !!!";
    }
    return 0;
}

void Human_Player(std::vector<int> &game) {
    int tempIndex = index;
    do {
        bool validity = true;
        index = tempIndex;
        if (game.size() > 0) {
            for (int i = 0; i < index; i++) {
                cout << game[i] << '\n';    // Print the previous elements in the game vector
            }
            inputAndCheck(validity, game, index);
            if (validity == true) {         // If the inputs are valid, exit the do-while
                break;
            } else continue;
        } else {      
            inputAndCheck(validity, game, index);  
            if (validity == true) {         // If the inputs are valid, exit the do-while
                break;
            } else continue; 
        }
    } while (1);
}

void inputAndCheck(bool &validity, std::vector<int> &game, int &index) {   
    int num;
    std::vector<int> tempGame = game;
    while (1) {
        cout << "How many number: ";
        cin >> num;    
        if (num > 3 || num < 1) {      // Check if the number of inputs exceeds 3
            cout << "Cheater, haha, pathetic !!! \n";
            validity = false;
            return;
        }
        else break;
    }
    int targetIndex = index + num;
    int i = index;
    for (; i < targetIndex; i++) {  // Input 
        int inputTemp;
        cin >> inputTemp;
        if (inputTemp == i+1) {     // Check whether the input is valid
            validity *= true;       // If so, validity AND true
            game.push_back(inputTemp);
            index++;
            if (inputTemp == 20) {  // Win if player reaches 20
                playerWin = true;
                return;
            }
        } else {                    // The inputs are invalid
            cout << "Illegal input, please try again" << '\n';
            validity *= false;      // validity becomes false and makes the do-while loop restart
            game = tempGame;        // Reset the game vector to its original state
            return;       
        }
    }    
}

void COM_Player(std::vector<int> &game) {
    int tempIndex = index;
    int remaining = 4 - (game[index-1]%4);
    for (int i = index; i < tempIndex + remaining; i++) {
        game.push_back(i+1);
        index++;
        if (i+1 == 20) {
            playerWin = false;
            return;
        }
    }
    cout << "End \n"; 
}
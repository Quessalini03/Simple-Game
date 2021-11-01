/* 	Name of the game: The game that you can't win :)

	Rules:
		- Who reaches 20 first wins the game
		- The game starts from 1
		- You start the game
		- Each player has a choice to enter from 1 to 3 numbers in their turns
		- The numbers input have to be in sequential order
		
	How to play:
		Play this game by entering the number of numbers you want to enter
			in your turn (from 1 to 3)
		Then type in those number in sequential order follow the flow of the game
			How many number: 3 (The start of the game)
			1
			2
			3
			*Or*
			How many number: 2 (The middle of the game)
			15
			16	   
		Then the computer will try to do the same, decide to enter from 1 to 3 numbers
			and add them to the flow of the game
		
		A real game example:
			Hom many numbers: 1
			1
			Thinking...
			1
			2
			3
			How many numbers: 3
			4
			5
			6
			Thinking... 
			
			1
			2
			3
			4
			5
			6
			7
			8
			9
			How many numbers: 1
			10
			Thinking...
			
			1
			2
			3
			4
			5
			6
			7
			8
			9
			10
			11
			12
			13
			How many numbers: 2
			.
			.
			.
			How many numbers: 2
			19
			20
			
			1
			2
			3
			4
			5
			6
			7
			8
			9
			10
			11
			12
			13
			14
			15
			16
			17
			18
			19
			20
			You WIN !!!
	*/
		



#include <iostream>
#include <vector>
#include<windows.h>

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
        	cout << '\n';
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
        if (num > 3 || num < 1) {      // Check if the number of inputs exceeds 3 or smaller than 1
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
    int remaining = 4 - (game[index-1]%4);	// Calculate the remaining numbers to add
    for (int i = index; i < tempIndex + remaining; i++) {
        game.push_back(i+1);
        index++;
        if (i+1 == 20) {
            playerWin = false;
            return;
        }
    }
    cout << "Thinking... \n"; 
    Sleep(1500);
}

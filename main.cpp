
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

void displayScore(int sticks);
int gatherPlayerInput();
bool isGameOver(int score);
bool playAgain();

int main() {
    bool playing;
    do {
        // Greet players and initiate game.
        std::cout << "Welcome to Nim!" << std::endl;
        std::cout << "Players will take turns removing 1, 2, or 3 sticks from the initial 11." << std::endl;
        std::cout <<  "The player removing the last stick wins!" << std::endl;
        bool gameOn;
        int player = 1;
        int score = 11;
        do {
            int turnInput;
            // Display game board to user
            std::cout << "The game currently looks like this:" << std::endl;
            displayScore(score);
            //Prompt for user input
            std:: cout << "Player " << player << ", it\'s your turn!" << std:: endl;
            std::cout << "How many sticks would you like to remove?" << std:: endl;
            turnInput = gatherPlayerInput();
            //Give player feedback on play
            std::cout << "Player " << player << " takes " << turnInput << "sticks!" << std::endl;
            //Acc score
            score = score - turnInput;
            //Check for endgame condition
            if (isGameOver(score)) {
                gameOn = false;
            }
            else {
                gameOn = true;
                //Switch players
                if(player == 1 ) {
                    player = 2;
                }
                else {
                    player = 1;
                }
            }
        } while (gameOn);
        //End game and notify players
        std:: cout << "Player " << player << " is the winner!" << std::endl;
        std:: cout << "Congratulations" << std::endl;
        // Ask players to play again
        playing = playAgain();
    } while (playing);

    //Thank players and exit program
    std::cout << "Thank you for playing Nim!" << std::endl;
    return 0;
}

bool isGameOver(int score) {
    return score <= 0;
}

void displayScore(int sticks) {
    for( int i = 0; i < sticks; i++ ) {
        std::cout << "|";
    }
    std::cout << endl;
}

int gatherPlayerInput() {
    const int LARGE = numeric_limits<streamsize>::max();
    const char END_LINE = '\n';
    int input;
    do {
        std::cin >> input;
        if ( input < 1 || input > 3 ) {
            std::cout << "Only values 1-3 are accepted" << endl;
            cin.clear();
            cin.ignore(LARGE,END_LINE);
        }
    } while( input < 1 || input > 3 );
    return input;
}

bool playAgain(){
    const int LARGE = numeric_limits<streamsize>::max();
    const char END_LINE = '\n';
    char input;
    bool playAgain;

    std::cout << "Would you like to play again? (y/n)" << std::endl;
    do {
        // Gather input
        std::cin >> input;
        input = tolower(input);
        if( input != 'y' && input != 'n') {
            std::cout << "Enter y or n, or else." << std::endl;
            // Clear input and errors
            cin.clear();
            // Flush the buffer
            cin.ignore(LARGE,END_LINE);
        }
    } while ( input != 'y' && input != 'n' );

    // Set return value
    if ( input == 'y' ) {
        playAgain = true;
    }
    else if ( input == 'n') {
        playAgain = false;
    }
    return playAgain;
}


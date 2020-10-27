
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;
void displayScore(int sticks);
int gatherPlayerInput(int score);
bool isGameOver(int score);
bool playAgain();

int main() {
    bool playing;
    do {
        // Greet players and initiate game.
        std::cout << "Welcome to Nim!" << std::endl;
        std::cout << "Players will take turns removing 1, 2, or 3 sticks from the initial 11.\nThe player removing the"
                     "last stick wins!" << std::endl;
        bool gameOn;
        int player;
        do {
            int player = 1;
            int score = 11;
            int turnInput;
            std::cout << "The game currently looks like this:" << std::endl;
            displayScore(score);
            std:: cout << "Player " << player << ", it\'s your turn!" << std:: endl;
            std::cout << "How many sticks would you like to remove?" << std:: endl;
            turnInput = gatherPlayerInput(score);
            score = score - turnInput;
            bool gameOn = isGameOver(score);
        }
        while (gameOn);
        std:: cout << "Player " << player << "is the winner!" std::endl;
        std:: cout << "Congratulations" << std::endl;
        playing = playAgain();
    }
    while (playing);

    std::cout << "Thank you for playing Nim!" << std:: endl;
    return 0;
}

void displayScore(int sticks) {
    for( int i = 0; i < sticks; i++ ) {
        std::cout << "|";
    }
}

int gatherPlayerInput(int score) {
    const int LARGE = numeric_limits<streamsize>::max();
    const char END_LINE = '\n';
    int input;
    do {
        std::cin >> input;
        if ( input < 1 || input > 3 ) {
            std::cout << "Only values 1-3 are accepted" <<
        }
    }
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


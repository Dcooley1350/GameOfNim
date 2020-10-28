
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

void displayScore(int sticks);
int gatherPlayerInput(int score);
bool isGameOver(int score);
bool playAgain();
void resetStream();

int main() {
    bool toEnd = true;
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
            std:: cout << "Player " << player << ", it\'s your turn!" << std::endl;
            turnInput = gatherPlayerInput(score);
            //Exit game if -1 inputted
            if ( turnInput == -1 ) {
                gameOn = false;
                toEnd = false;
                playing = false;
                std::cout << "-1 inputted, exiting game. :(" << std::endl;
            }
            else {
                //Give player feedback on play
                std::cout << "Player " << player << " takes " << turnInput << (turnInput == 1 ? " stick!" : " sticks!") << std::endl;
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
            }
        } while (gameOn);
        if (toEnd) {
            //End game and notify players
            std:: cout << "Player " << player << " is the winner!" << std::endl;
            std:: cout << "Congratulations" << std::endl;
            // Ask players to play again
            playing = playAgain();
        }
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

int gatherPlayerInput(int score) {
    int input;
    bool inputValid;
    do {
        std::cout << "How many sticks would you like to remove?" << std:: endl;
        std::cin >> input;
        if ( cin.fail() || input < -1 || input > 3 || input == 0 ) {
            std::cout << "Only values 1-3 are acceptable plays! Enter -1 to exit." << endl;
            resetStream();
            inputValid = false;
        }
        else if ( input > score ) {
            std::cout << "You can\'t take sticks that are not there!" << endl;
            resetStream();
            inputValid = false;
        }
        else {
            inputValid = true;
        }
    } while( !inputValid );
    return input;
}

bool playAgain(){
    unsigned char input;
    bool playAgain;

    std::cout << "Would you like to play again? (y/n)" << std::endl;
    do {
        // Gather input
        std::cin >> input;
        input = tolower(input);
        if( input != 'y' && input != 'n') {
            std::cout << "Enter y or n, or else." << std::endl;
            resetStream();
        }
    } while ( input != 'y' && input != 'n' );

    // Set return value
    if ( input == 'y' ) {
        playAgain = true;
    }
    else {
        playAgain = false;
    }
    return playAgain;
}

void resetStream() {
    const long LARGE = numeric_limits<streamsize>::max();
    const char END_LINE = '\n';
    // Clear input and errors
    cin.clear();
    // Flush the buffer
    cin.ignore(LARGE,END_LINE);
}


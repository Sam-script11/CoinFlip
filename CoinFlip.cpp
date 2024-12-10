#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype> // For std::toupper

using namespace std;

// Function to simulate a coin flip
char flipCoin() {
    return (rand() % 2 == 0) ? 'H' : 'T';
}

// Function to play the coin flip game
int play(int rounds) {
    int points = 0; // Points counter
    int streak = 0; // Streak counter
    int maxStreak = 0; // Track maximum streak

    for (int i = 0; i < rounds; i++) {
        char playerGuess;

        // Input validation and conversion to uppercase
        do {
            cout << "Guess the next coin flip outcome (h for head, t for tail): ";
            cin >> playerGuess;
            playerGuess = toupper(playerGuess); // Convert to uppercase
            if (playerGuess != 'H' && playerGuess != 'T') {
                cout << "Invalid input. Please guess 'h' for head or 't' for tail." << endl;
            }
        } while (playerGuess != 'H' && playerGuess != 'T');

        char result = flipCoin();
        cout << "The coin landed on: " << result << endl;

        // Compare guesses (both in uppercase now)
        if (playerGuess == result) {
            points++;
            streak++;
            maxStreak = max(maxStreak, streak);
            cout << "Correct! Current streak: " << streak << endl;
        } else {
            streak = 0;
            cout << "Wrong guess. Streak reset to 0." << endl;
        }
    }
    cout << "Your highest streak was: " << maxStreak << endl;
    return points;
}

int main() {
    srand(time(nullptr)); // Seed the random number generator

    while (true) {
        int rounds;
        cout << "Enter the number of times to play: ";
        cin >> rounds;

        // Play the game and display points
        int points = play(rounds);
        cout << "You earned " << points << " points." << endl;

        // Ask if the player wants to play again
        char again;
        cout << "Do you want to play again? (y/n): ";
        cin >> again;

        if (toupper(again) != 'Y') { // Convert to uppercase for comparison
            cout << "Have a good day!!" << endl;
            break;
        }
    }

    return 0;
}

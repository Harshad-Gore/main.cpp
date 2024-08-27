#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class playGame
{
public:
    int guess, attempt = 1, upperLim, lowerLim, randomNum;

    void read()
    {
        cout << "Let's play Guess The Number.\nEnter the upper and lower limits to continue." << endl;
        cout << "Enter the upper limit: ";
        cin >> upperLim;
        cout << "Enter the lower limit: ";
        cin >> lowerLim;
        cout << "Enter your guess: ";
        cin >> guess;
    }

    void performOp()
    {
        srand(time(0));
        randomNum = rand() % (upperLim - lowerLim + 1) + lowerLim;

        while (guess != randomNum)
        {
            if (guess < randomNum)
                cout << "Too low! Try again: ";
            else
                cout << "Too high! Try again: ";

            cin >> guess;
            attempt++;
        }

        cout << "Congratulations! You guessed the number " << randomNum << " in " << attempt << " attempts." << endl;
    }
};

int main()
{
    playGame game;
    game.read();
    game.performOp();

    return 0;
}

/******************************************************************************

Problem 11 - CH 3 Savitch - Game of Pig

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

int HumanTurn(int humanTotalScore);
int ComputerTurn(int computerTotalScore);
int main()
{
    int humanScore = 0, computerScore = 0;
    int turnNumber = 1;
    
    srand(time(0));
    
    while (humanScore < 100 && computerScore < 100) {
        std::cout << "Turn " << turnNumber << std::endl;
        humanScore = humanScore + HumanTurn(humanScore);
        std::cout << "Human score = " << humanScore << std::endl;
        if (humanScore < 100) {
            computerScore = computerScore + ComputerTurn(computerScore);
            std::cout << "Computer score = " << computerScore << std::endl;
        }
        turnNumber++;
        std::cout << std::endl;
    }
    std::cout << "Human score = " << humanScore << std::endl;
    std::cout << "Computer score = " << computerScore << std::endl;
    if (humanScore >= 100) {
        std::cout << "Human won\n";
    }
    else {
        std::cout << "Computer won\n";
    }

    return 0;
}
int HumanTurn(int humanTotalScore) {
    int diceRoll;
    int score = 0;
    while(1) {
        diceRoll = 1 + rand()%6;
        std::cout << "You rolled a " << diceRoll << std::endl;
        if (diceRoll == 1) {
            return 0;
        }
        else {
            char ch;
            std::cout << "Your total score prior to this roll is " << humanTotalScore+score << std::endl;
            std::cout << "Do you want to roll (r) or hold (h)?: ";
            std::cin >> ch;
            if (ch == 'r') {
                score = score + diceRoll;
            }
            else if (ch == 'h') {
                score = score + diceRoll;
                return score;
            }
        }
    }
}
int ComputerTurn(int computerTotalScore) {
    int diceRoll;
    int score = 0;
    while(1) {
        diceRoll = 1 + rand()%6;
        std::cout << "Computer rolled a " << diceRoll << std::endl;
        if (diceRoll == 1) {
            std::cout << "Computer current score ---> " << score << std::endl;
            return 0;
        }
        else {
            if (score < 20) {
                score = score + diceRoll;
                std::cout << "Computer current score ---> " << score << std::endl;
                if (score >= 20) {
                    return score;
                }
            }
        }
    }
}
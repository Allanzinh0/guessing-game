#include <iostream>
#include <cstdlib>

enum class DifficultyAttempts
{
    Easy = 15,
    Normal = 10,
    Hard = 5
};

float GuessingGame(const DifficultyAttempts maxAttempts)
{
    // Create any number between 0 and 100
    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;

    // Create main variables used in game
    float score = 1000.0f;
    int guess = -1;

    for (int attempts = 1; attempts <= (int)maxAttempts; attempts++)
    {
        // Print current attempt
        std::cout << "Attempt number " << attempts << std::endl;

        // Get a attempt from console
        std::cout << "What is your attempt: ";
        std::cin >> guess;

        // Subtract from score some point if the guess is wrong
        float penalityScore = abs(guess - SECRET_NUMBER) / 2.0f;
        score -= penalityScore;
        
        // Test the attempt with the secretNumber
        if (guess == SECRET_NUMBER)
        {
            std::cout << "Congratulations, you find the number." << std::endl;
            std::cout << "********   End Game!!!   ********" << std::endl;
            std::cout << "You find the number in " << attempts << " attempts." << std::endl;
            return score;
        }
        else if (guess > SECRET_NUMBER)
            std::cout << "Your attempt was higher than the secret number." << std::endl;
        else
            std::cout << "Your attempt was lower than the secret number." << std::endl;
    }

    std::cout << "********   End Game!!!   ********" << std::endl;
    std::cout << "You didn't find the number." << std::endl;
    score -= 250.0f;
    return score;
}

int main()
{
    // Display a splash screen in console
    std::cout << "*******************************************" << std::endl;
    std::cout << "*      Welcome to the Guessing Game!      *" << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << "Try to guess any number between 0 and 100." << std::endl;

    // Select difficulty level
    std::cout << "Which difficulty do you want to play ([E]asy, [N]ormal, [H]ard): ";
    char difficulty;
    std::cin >> difficulty;

    DifficultyAttempts attempts;
    switch (difficulty)
    {
        case 'E': attempts = DifficultyAttempts::Easy; break;
        case 'N': attempts = DifficultyAttempts::Normal; break;
        case 'H':
        default: attempts = DifficultyAttempts::Hard; break;
        
    }

    float score = GuessingGame(attempts);
    score = (score < 0.0f) ? 0.0f : score;

    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "Your score is: " << score << std::endl;

    return 0;
}
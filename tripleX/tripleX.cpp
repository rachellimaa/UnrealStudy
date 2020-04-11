#include <iostream> 
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << "\n\nYou are a hacker and to save the world, you have to break the code, you are at level " << Difficulty << endl;
    cout << "You need to enter the correct codes to continue..." << endl << endl; 
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty    );

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "There are 3 numbers in the code" << endl;
    cout << "The codes add-up to: " << CodeSum << endl;
    cout << "The codes multiply to give: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cout << "\nThe entered is: "<< endl;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum, GuessProduct;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    /*cout << "The GuesSum: " << GuessSum << endl;
    cout << "The GuesProduct: " << GuessProduct << endl;*/

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
       cout << "Well done hacker! Keep going! " << endl;
       return true;
    }else
    {
        cout << "You entered the wrong code! Try again!" << endl;
        return false;
    }
}

int main ()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxDifficult = 5;
    while (LevelDifficulty <= MaxDifficult)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();       

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    cout << "\nGreat work hacker! You saved the world!" << endl;
    
    return 0;
}
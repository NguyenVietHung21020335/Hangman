#include <bits/stdc++.h>
using namespace std;

string update(string secretWord, string guessedWord, char guess)
{
    for(int i= secretWord.length()-1; i>= 0; i--){
        if ( secretWord[i]== guess){
            guessedWord[i]= guess;
        }
    }
    return guessedWord;
}

bool contains(string secretWord, char guess)
{
    if ( secretWord.find_first_of( guess)== string::npos){
        return false;
    }
    return true;
}

int main()
{
    int badGuessCount =0;
    string secretWord= "book";
    string guessedWord= string( secretWord.length(), '-');
    char guess;
    const int MAX_BAD_GUESSES = 7;
    do{
        cout<< "Your guess: "<< ' ';
        cin >>guess ;
        if( contains( secretWord, guess)== true)
        {
            guessedWord= update( secretWord, guessedWord, guess);
            cout<< "guessWord"<< ':'<< guessedWord<< ' '<< '\n';
        }
        else
        {
            badGuessCount++;
            cout<< "guessWord"<< ':'<< guessedWord<< ' '<< '\n';
        }
        cout<< "Number of wrong guesses:" << ' '<< badGuessCount<< '\n';
        cout<<"***********************************************"<<'\n';
    }while ( badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord);
    if ( badGuessCount < MAX_BAD_GUESSES)
    {
        cout<< "Congratulations! You win!";
    } else cout<< "You lost. The correct word is "<< secretWord;
}

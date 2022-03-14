#include <bits/stdc++.h>
using namespace std;
//Chọn từ
const string wordList[]= { "dog", "cat", "human"};
const int wordCount= sizeof(wordList) / sizeof(string);

string chooseWord()
{
    int randomIndex= rand()% 3;
    return wordList[randomIndex];
}
//Kiểm tra có đoán đúng chữ số hay không
bool contains(string secretWord, char guess)
{
    if ( secretWord.find_first_of( guess)== string::npos){
        return false;
    }
    return true;
}
//Thay đổi từ sau khi đoán
string update(string secretWord, string guessedWord, char guess)
{
    for(int i= secretWord.length()-1; i>= 0; i--){
        if ( secretWord[i]== guess){
            guessedWord[i]= guess;
        }
    }
    return guessedWord;
}

int main()
{
    int badGuessCount =0;
    string secretWord= chooseWord();
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

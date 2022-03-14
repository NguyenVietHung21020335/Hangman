#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

//Chọn từ
const string wordList[]= { "dog", "cat", "human"};
const int wordCount= sizeof( wordList) / sizeof( string);
string chooseWord()
{
    int randomIndex= rand()% 3;
    return wordList[ randomIndex];
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
//Vẽ hình
const string FIGURE[]={
 " ------------- \n"
 " |             \n"
 " |             \n"
 " |             \n"
 " |             \n"
 " |             \n"
 " -----         \n"
 ,
 " ------------- \n"
 " |           | \n"
 " |             \n"
 " |             \n"
 " |             \n"
 " |             \n"
 " -----         \n"
 ,
 " ------------- \n"
 " |           | \n"
 " |           O \n"
 " |             \n"
 " |             \n"
 " |             \n"
 " -----         \n"
 ,
 " ------------- \n"
 " |           | \n"
 " |           O \n"
 " |           | \n"
 " |             \n"
 " |             \n"
 " -----         \n"
 ,
 " -------------  \n"
 " |           |  \n"
 " |           O  \n"
 " |          /|  \n"
 " |              \n"
 " |              \n"
 " -----          \n"
 ,
 " -------------   \n"
 " |           |   \n"
 " |           O   \n"
 " |          /|\\ \n"
 " |               \n"
 " |               \n"
 " -----           \n"
 ,
 " -------------   \n"
 " |           |   \n"
 " |           O   \n"
 " |          /|\\ \n"
 " |          /    \n"
 " |               \n"
 " -----           \n"
 ,
 " -------------   \n"
 " |           |   \n"
 " |           O   \n"
 " |          /|\\ \n"
 " |          / \\ \n"
 " |               \n"
 " -----           \n"
};
void renderGame(string guessedWord, int badGuessCount)
{
cout << FIGURE[ badGuessCount] << endl;
cout << guessedWord << endl;
cout << "Number of wrong guesses: " << badGuessCount << endl;

}
int main()
{
    string secretWord= chooseWord();
    string guessedWord= string( secretWord.length(), '-');
    char guess;
    int badGuessCount =0;
    const int MAX_BAD_GUESSES = 7;
    do{
        cout<< "Your guess: "<< ' ';
        cin >>guess ;
        if( contains( secretWord, guess)== true)
        {
            guessedWord= update( secretWord, guessedWord, guess);

        }
        else    badGuessCount++;
        renderGame( guessedWord, badGuessCount);
        cout<< "***********************************************"<< '\n';
        //2 dòng dưới +thư viện <unistd.h> là để xóa màn hình.
        //sleep(2);
        //system("cls");

    }while ( badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord);

    if ( badGuessCount < MAX_BAD_GUESSES)
    {
        cout<< "Congratulations! You win!";
    } else cout<< "You lost. The correct word is "<< '"'<< ' '<< secretWord<< ' '<< '"';
}

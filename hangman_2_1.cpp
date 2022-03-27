//Chuẩn hóa dữ liệu- Chuẩn hóa từ nhập từ file+ từ người chơi đoán luôn chuyển sang chữ thường
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const int MAX_BAD_GUESSES = 7;
const char DATA_FILE[] = "fileChooseWord.txt";

string chooseWord(const char* fileName);
void renderGame(string guessedWord, int badGuessCount, string guessChars, string badGuesses);
char readAGuess();
bool contains(const string& secretWord, char guess);
string update(const string& secretWord, string& guessedWord, char guess);
string toLowerCase(const string& s);

//guessChars này là để hiện ra những từ ng chơi đã đoán
string guessChars="";
string badGuesses = "";

int main()
{
    srand(time(0));
    string secretWord= chooseWord(DATA_FILE);
    string guessedWord= string( secretWord.length(), '-');
    int badGuessCount =0;

    do{
        //Vòng lặp for để đẩy màn hình xuống chỉ thấy lần tiếp theo
        for (int i= 0; i< 50; i++){
            cout<< endl;
        }
        renderGame(guessedWord, badGuessCount, guessChars, badGuesses);
        char guess= readAGuess();
        guessChars+= guess;
        if( contains( secretWord, guess) == true)
        {
             update( secretWord, guessedWord, guess);

        }
        else{
            badGuesses += guess;
            badGuesses += " ";
            badGuessCount++;
        }
        cout<< "**************************************************************************************************"<< '\n';
        //2 dòng dưới +thư viện <unistd.h> là để xóa màn hình.
        //sleep(2);
        //system("cls");

    }while ( badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord);
    //Vòng lặp for để đẩy màn hình xuống chỉ thấy lần tiếp theo
    for (int i= 0; i< 50; i++){
            cout<< endl;
    }
    renderGame(guessedWord, badGuessCount, guessChars, badGuesses);
    cout<< endl; //tách hàng cho dễ nhìn lúc endgame thôi.
    if ( badGuessCount < MAX_BAD_GUESSES)
    {
        cout<< "Congratulations! You win!";
    } else cout<< "You lost. The correct word is "<< '"'<< ' '<< secretWord<< ' '<< '"';
    cout<< endl; //tách hàng cho dễ nhìn lúc endgame thôi.
    return 0;
}

string toLowerCase(const string& s)
{
    string res = s;
    for (int i = 0; i < s.size(); i++)
        res[i] = tolower(s[i]);
    return res;
}
/* Cách khác:
string toLowerCase(const string& s)
{
 string res = s;
 transform(s.begin(), s.end(), res.begin(), ::tolower);
 return res;
}
*/
//Chọn từ
string chooseWord(const char* fileName)
{
    vector<string> wordList;
    ifstream file(fileName);
    if ( file.is_open()){
    string word;
    while ( file >> word){
        wordList.push_back(word);
        }
    }
    file.close();
    if(wordList.size()!=0){
        int randomIndex= rand() % wordList.size();
    return  toLowerCase(wordList[randomIndex]);
    }
    else return "";
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
void renderGame(string guessedWord, int badGuessCount, string guessChars, string badGuess)
{
    cout << FIGURE[ badGuessCount] << endl;
    cout << guessedWord << endl;
    cout << "You've made " << badGuessCount << " wrong guess, they are: " << badGuess << endl;
}
//Nhập từ người chơi đoán
char readAGuess()
{
	char guess;
	cout << "Your guess: ";
	cin >> guess;
	return tolower(guess);
}
//Kiểm tra có đoán đúng chữ số hay không
bool contains(const string& secretWord, char guess)
{
    if ( secretWord.find_first_of( guess)== string::npos){
        return false;
    }
    return true;
}
//Thay đổi từ sau khi đoán
string update(const string& secretWord, string& guessedWord, char guess)
{
    for(int i= secretWord.length()-1; i>= 0; i--){
        if ( secretWord[i]== guess){
            guessedWord[i]= guess;
        }
    }
    return guessedWord;
}

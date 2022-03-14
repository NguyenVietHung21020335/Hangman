//Thêm tham biến và hằng
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const int MAX_BAD_GUESSES = 7;

string chooseWord();
void renderGame(string guessedWord, int badGuessCount);
char readAGuess();
bool contains(const string& secretWord, char guess);
string update(const string& secretWord, string& guessedWord, char guess);

int main()
{
    srand(time(0));
    string secretWord= chooseWord();
    string guessedWord= string( secretWord.length(), '-');
    int badGuessCount =0;

    do{

        renderGame(guessedWord, badGuessCount);
        char guess= readAGuess();
        if( contains( secretWord, guess) == true)
        {
             update( secretWord, guessedWord, guess);

        }
        else    badGuessCount++;
        cout<< "**************************************************************************************************"<< '\n';
        //2 dòng dưới +thư viện <unistd.h> là để xóa màn hình.
        //sleep(2);
        //system("cls");

    }while ( badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord);
    renderGame(guessedWord, badGuessCount);
    if ( badGuessCount < MAX_BAD_GUESSES)
    {
        cout<< "Congratulations! You win!";
    } else cout<< "You lost. The correct word is "<< '"'<< ' '<< secretWord<< ' '<< '"';
    return 0;
}

//Chọn từ
const string wordList[]= { "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm" };
const int wordCount= sizeof( wordList) / sizeof( string);
string chooseWord()
{
    int randomIndex= rand()% wordCount;
    return wordList[ randomIndex];
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
//Nhập từ người chơi đoán
char readAGuess()
{
	char guess;
	cout << "Your guess: ";
	cin >> guess;
	return guess;
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


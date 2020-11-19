#include <iostream>

using namespace std;
class Player{
    public:
        virtual int getGuess(){
            return 0;
        }
};
class HumanPlayer:public Player{
    public:
        int getGuess(){
            int num;
            cin>>num;
            return num;
        }
};
class ComputerPlayer:public Player{
    public:
        int getGuess(){
            int num=rand()%101;
            cout<<"The computer Guess "<<num<<" \n";
            return num;
        }
};
bool checkForWin(int guess, int answer){
    if (answer ==guess){
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess){
        cout << "Your guess is too high." << endl;
    }
    else{ 
        cout << "Your guess is too low." << endl;
    }
    return false;
}
void play(Player &player1, Player &player2){
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    while (!win){
        cout << "Player 1's turn to guess." <<endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win) return;
        cout <<"Player 2's turn to guess." <<endl;
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
    }
}

int main(){
    HumanPlayer A;
    HumanPlayer B;
    ComputerPlayer C;
    ComputerPlayer D;
    play(A,B);
    play(A,C);
    play(C,D);

    return 0;
}
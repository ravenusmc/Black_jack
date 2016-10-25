/*
 program: Black Jack
 Programmer: Mike Cuddy
 Date: 24 October 2016
 Other: N/A
 */

/*
 
 Explanation: This program is an electronic version of the casino game Black Jack
 
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//*******************************
//Structures
//*******************************


//*******************************
//Global Variables/constants
//*******************************


//*******************************
//Prototype Functions
//*******************************

void welcome();
int numberOfPlayers();
bool validPlayers(int);
void game(int);


//******************************
//Main Function
//******************************

int main(){
    
    int players;
    
    
    welcome();
    //mainMenu():
    players = numberOfPlayers();
    game(players);
    
    
    
    
    //system("pause"); //This line is for Microsoft Visual users.
    
    return 0;
    
}// End of main function

//******************************
//Functions
//******************************

//This function is the title menu and greets the user(s)
void welcome(){
    
    cout << "----------------------" << endl;
    cout << "Welcome to Black Jack" << endl;
    cout << "----------------------" << endl;


}//End of welcome function

//This function is what will determine the number of players in the game.
int numberOfPlayers(){
    
    int players;
    
    cout << "Please enter the number of players, between 1 or 2: " << endl;
    cin >> players;
    while (!validPlayers(players)) {
        cout << "The amount of players may only be between 1 or 2" << endl;
        cin >> players;
    }
    
    return players;
}// End of numberOfPlayers function

//This function will run the main aspect of the game.
void game(int players){
    
    //This is a dynamically created array for the number of players and the bets that they make.
    int *arrayForBets;
    
    arrayForBets = new int[players];
    
    //This loop will ask the players to make their bets.
    for (int i = 0; i < players; i ++){
        cout << "Player " << i + 1 << " please place your bet: " << endl;
        cout << "The bet must be between 10 and 500" << endl;
        cin >> *(arrayForBets + i);
    }
    
    
    

}//End of Game Function



//***************************
//Validation functions below this point
//***************************

//This function checks to ensure that the game only has one or two players.
bool validPlayers(int value){
    if (value == 1 || value == 2){
        return true;
    }else{
        return false;
    }

}// End of validPlayers function.












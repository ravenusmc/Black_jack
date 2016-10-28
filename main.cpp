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
#include <cstdlib>
#include <ctime>

using namespace std;

//*******************************
//Structures
//*******************************

struct Card
{
    int valueOne;
    int valueTwo;
    string suite;
    string face;
};


//*******************************
//Global Variables/constants
//*******************************

const int DECKSIZE = 52;
const int MAXDECK = 11;

//*******************************
//Prototype Functions
//*******************************

void welcome();
void createDeck(Card [], int);
void shuffle(Card [], int);
int numberOfPlayers();
bool validPlayers(int);
bool validAgain(int);
bool validBets(int);
void game(int, Card [], int);
int playAgain();
void stand();

void dealTwoCars(Card [], int, Card [], int, int &, int &);



//******************************
//Main Function
//******************************

int main(){
    
    //Declaring variables
    int players, again, action;
    int cardLocation, playerOneTotal;
    
    
    //Creating the deck of cards
    Card deck[DECKSIZE];
    
    //These structures will be used to hold the cards that dealer, playerOne and playerTwo have
    //The constanst is set to 11 because that is the maximun number of cards that someone can have
    //before Black Jack or 21 may arise.
    Card playerOne[MAXDECK];
    Card playerTwo[MAXDECK];
    Card dealer[MAXDECK];
    
    //welcome();
    //mainMenu():
    players = numberOfPlayers();
    //This will actually create the deck of cards
    createDeck(deck, DECKSIZE);
    //This function will be the actual game function
    //game(players, deck, DECKSIZE);
    
    do {
        
        //Need to allocated bets-add function for that.
        
        //These variables must be returned to zero at the end of every round.
        cardLocation = 0;
        playerOneTotal = 0;
        
        //This will shuffle the deck of cards
        shuffle(deck, DECKSIZE);
    
        dealTwoCars(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
        
        //Show dealers hand here????
        
        cout << "Your total is: " << playerOneTotal << endl;
        cout << "1. Hit" << endl;
        cout << "2. Stand" << endl;
        cout << "3. Double Down" << endl;
        cout << "4. Surrender" << endl;
        cout << "What is your action?" << endl;
        cin >> action;
        if (action == 1){
            //hitMe();
        }else if (action == 2){
            stand();
        }else if (action == 3){
            //Doubledown();
        }else if (action == 4){
            //Surrender();
        }
        
        
        
        cardLocation++;
        
        //Asking the player(S) if they want to play again.
        again = playAgain();
        
    } while (again != 2);

    
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
    
    //Declaring variables
    int players;
    
    cout << "Please enter the number of players, between 1 or 2: " << endl;
    cin >> players;
    while (!validPlayers(players)) {
        cout << "The amount of players may only be between 1 or 2" << endl;
        cin >> players;
    }
    
    return players;
}// End of numberOfPlayers function


//This function will deal the first two cards to the player(s)
void dealTwoCars(Card deck[], int DECKSIZE, Card playerOne[], int MAXDECK, int &cardLocation, int &playerOneTotal){
    
    int aceValue;
    
    for (int i = 0; i < 2; i++)
    {
        cout << "your " << cardLocation + 1 << " card is the " << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite  << endl;
        if (deck[cardLocation].valueTwo == 11){
            cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
            cin >> aceValue;
            deck[cardLocation].valueOne = aceValue;
        }
        playerOneTotal = playerOneTotal + deck[cardLocation].valueOne;
        playerOne[cardLocation] = deck[cardLocation]; //assigns card to players hand
        //I have to increment the cardLocation after each hand to ensure that the cards are not
        //repeated.
        cardLocation++;
    }
    
}//End of dealTwoCars


//This function will run the main aspect of the game.
void game(int players, Card deck[], int DECKSIZE){

    
//    arrayForBets = new int[players];
//    
//    //This loop will ask the players to make their bets.
//    for (int i = 0; i < players; i ++){
//        cout << "Player " << i + 1 << " please place your bet: " << endl;
//        cout << "The bet must be between 10 and 500" << endl;
//        cin >> arrayForBets[i];
//        while ((arrayForBets[i] < 10) || (arrayForBets[i] > 500) ){
//            cout << "The bets must be between 10 and 500" << endl;
//            cin >> arrayForBets[i];
//        }
//    }
    

}//End of Game Function

//This function will simply alert the user that they have decided to stand
//meaning that they will no longer take any cards.
void stand(){
    cout << "You choose to stand" << endl;
    cout << "This means you are not asking for any more cards!" << endl;
}


//This function will ask the player if they want to play again
int playAgain(){
    
    int again;
    cout << "Do you want to play again? " << endl;
    cout << "1. Play Again" << endl;
    cout << "2. Stop Playing" << endl;
    cout << "Do you want to play again? " << endl;
    cin >> again;
    while (!validAgain(again)) {
        cout << "You may only select 1 or 2" << endl;
        cin >> again;
    }
    return again;
}// End of PlayAgain function

//This function will initialize the deck of cards.
void createDeck(Card deck[], int DECKSIZE) //creates deck
        {
            deck[0].valueOne = 1;
            deck[0].valueTwo = 11;
            deck[0].suite = "Spade";
            deck[0].face = "ACE ";
            deck[1].valueOne = 2;
            deck[1].valueTwo = 2;
            deck[1].suite = "Spade";
            deck[1].face = "";
            deck[2].valueOne = 3;
            deck[2].valueTwo = 3;
            deck[2].suite = "Spade";
            deck[2].face = "";
            deck[3].valueOne = 4;
            deck[3].valueTwo = 4;
            deck[3].suite = "Spade";
            deck[3].face = "";
            deck[4].valueOne = 5;
            deck[4].valueTwo = 5;
            deck[4].suite = "Spade";
            deck[4].face = "";
            deck[5].valueOne = 6;
            deck[5].valueTwo = 6;
            deck[5].suite = "Spade";
            deck[5].face = "";
            deck[6].valueOne = 7;
            deck[6].valueTwo = 7;
            deck[6].suite = "Spade";
            deck[6].face = "";
            deck[7].valueOne = 8;
            deck[7].valueTwo = 8;
            deck[7].suite = "Spade";
            deck[7].face = "";
            deck[8].valueOne = 9;
            deck[8].valueTwo = 9;
            deck[8].suite = "Spade";
            deck[8].face = "";
            deck[9].valueOne = 10;
            deck[9].valueTwo = 10;
            deck[9].suite = "Spade";
            deck[9].face = "";
            deck[10].valueOne = 10;
            deck[10].valueTwo = 10;
            deck[10].suite = "Spade";
            deck[10].face = "Jack";
            deck[11].valueOne = 10;
            deck[11].valueTwo = 10;
            deck[11].suite = "Spade";
            deck[11].face = "Queen";
            deck[12].valueOne = 10;
            deck[12].valueTwo = 10;
            deck[12].suite = "Spade";
            deck[12].face = "King";
            
            deck[13].valueOne = 1;
            deck[13].valueTwo = 11;
            deck[13].suite = "Clubs";
            deck[13].face = "ACE ";
            deck[14].valueOne = 2;
            deck[14].valueTwo = 2;
            deck[14].suite = "Clubs";
            deck[14].face = "";
            deck[15].valueOne = 3;
            deck[15].valueTwo = 3;
            deck[15].suite = "Clubs";
            deck[15].face = "";
            deck[16].valueOne = 4;
            deck[16].valueTwo = 4;
            deck[16].suite = "Clubs";
            deck[16].face = "";
            deck[17].valueOne = 5;
            deck[17].valueTwo = 5;
            deck[17].suite = "Clubs";
            deck[17].face = "";
            deck[18].valueOne = 6;
            deck[18].valueTwo = 6;
            deck[18].suite = "Clubs";
            deck[18].face = "";
            deck[19].valueOne = 7;
            deck[19].valueTwo = 7;
            deck[19].suite = "Clubs";
            deck[19].face = "";
            deck[20].valueOne = 8;
            deck[20].valueTwo = 8;
            deck[20].suite = "Clubs";
            deck[20].face = "";
            deck[21].valueOne = 9;
            deck[21].valueTwo = 9;
            deck[21].suite = "Clubs";
            deck[21].face = "";
            deck[22].valueOne = 10;
            deck[22].valueTwo = 10;
            deck[22].suite = "Clubs";
            deck[22].face = "";
            deck[23].valueOne = 10;
            deck[23].valueTwo = 10;
            deck[23].suite = "Clubs";
            deck[23].face = "Jack";
            deck[24].valueOne = 10;
            deck[24].valueTwo = 10;
            deck[24].suite = "Clubs";
            deck[24].face = "Queen";
            deck[25].valueOne = 10;
            deck[25].valueTwo = 10;
            deck[25].suite = "Clubs";
            deck[25].face = "King";
            
            deck[26].valueOne = 1;
            deck[26].valueTwo = 11;
            deck[26].suite = "Diamonds";
            deck[26].face = "ACE ";
            deck[27].valueOne = 2;
            deck[27].valueTwo = 2;
            deck[27].suite = "Diamonds";
            deck[27].face = "";
            deck[28].valueOne = 3;
            deck[28].valueTwo = 3;
            deck[28].suite = "Diamonds";
            deck[28].face = "";
            deck[29].valueOne = 4;
            deck[29].valueTwo = 4;
            deck[29].suite = "Diamonds";
            deck[29].face = "";
            deck[30].valueOne = 5;
            deck[30].valueTwo = 5;
            deck[30].suite = "Diamonds";
            deck[30].face = "";
            deck[31].valueOne = 6;
            deck[31].valueTwo = 6;
            deck[31].suite = "Diamonds";
            deck[31].face = "";
            deck[32].valueOne = 7;
            deck[32].valueTwo = 7;
            deck[32].suite = "Diamonds";
            deck[32].face = "";
            deck[33].valueOne = 8;
            deck[33].valueTwo = 8;
            deck[33].suite = "Diamonds";
            deck[33].face = "";
            deck[34].valueOne = 9;
            deck[34].valueTwo = 9;
            deck[34].suite = "Diamonds";
            deck[34].face = "";
            deck[35].valueOne = 10;
            deck[35].valueTwo = 10;
            deck[35].suite = "Diamonds";
            deck[35].face = "";
            deck[36].valueOne = 10;
            deck[36].valueTwo = 10;
            deck[36].suite = "Diamonds";
            deck[36].face = "Jack";
            deck[37].valueOne = 10;
            deck[37].valueTwo = 10;
            deck[37].suite = "Diamonds";
            deck[37].face = "Queen";
            deck[38].valueOne = 10;
            deck[38].valueTwo = 10;
            deck[38].suite = "Diamonds";
            
            deck[38].face = "King";
            deck[39].valueOne = 1;
            deck[39].valueTwo = 11;
            deck[39].suite = "Hearts";
            deck[39].face = "ACE ";
            deck[40].valueOne = 2;
            deck[40].valueTwo = 2;
            deck[40].suite = "Hearts";
            deck[40].face = "";
            deck[41].valueOne = 3;
            deck[41].valueTwo = 3;
            deck[41].suite = "Hearts";
            deck[41].face = "";
            deck[42].valueOne = 4;
            deck[42].valueTwo = 4;
            deck[42].suite = "Hearts";
            deck[42].face = "";
            deck[43].valueOne = 5;
            deck[43].valueTwo = 5;
            deck[43].suite = "Hearts";
            deck[43].face = "";
            deck[44].valueOne = 6;
            deck[44].valueTwo = 6;
            deck[44].suite = "Hearts";
            deck[44].face = "";
            deck[45].valueOne = 7;
            deck[45].valueTwo = 7;
            deck[45].suite = "Hearts";
            deck[45].face = "";
            deck[46].valueOne = 8;
            deck[46].valueTwo = 8;
            deck[46].suite = "Hearts";
            deck[46].face = "";
            deck[47].valueOne = 9;
            deck[47].valueTwo = 9;
            deck[47].suite = "Hearts";
            deck[47].face = "";
            deck[48].valueOne = 10;
            deck[48].valueTwo = 10;
            deck[48].suite = "Hearts";
            deck[48].face = "";
            deck[49].valueOne = 10;
            deck[49].valueTwo = 10;
            deck[49].suite = "Hearts";
            deck[49].face = "Jack";
            deck[50].valueOne = 10;
            deck[50].valueTwo = 10;
            deck[50].suite = "Hearts";
            deck[50].face = "Queen";
            deck[51].valueOne = 10;
            deck[51].valueTwo = 10;
            deck[51].suite = "Hearts";
            deck[51].face = "King";
            
}// End of createDeck Function

//This function will shuffle the deck
void shuffle(Card deck[], int DECKSIZE){
    
    long seed;
    int k;
    const int TEMPSIZE = 52;
    Card temp[TEMPSIZE];
    time_t * value;
    value = 0;
    
    seed = time(value);  // use the system clock to produce an initial time
    
    srand(seed);            // to seed the random number generator
    
    int random[52];
    
    k = 0;
    while(k < 52) //creates an array of 52 intergers (0-51) in random order
    {
        random[k] = rand() % 52;
        k++;
    }
    
    for (int i = 0; i < 52; i++) //uses random array to shuffle cards
    {
        temp[i] = deck[i]; //temp holds the card
        deck[i] = deck[random[i]]; //a new card is assigned to place i
        deck[random[i]] = temp[i]; //old card is reassigned to place random
    }
}
        
        

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

//This function checks to make sure that the players only enter valid numbers to play again
bool validAgain(int value){
    if (value == 1 || value == 2){
        return true;
    }else{
        return false;
    }
}// Enof of validAgain function.



























//int getNum(){
//
//    int value;
//
//    value = rand()%MAX_VALUE;
//
//    return value;
//}


//int getNum(){
//
//    int value;
//
//    //Getting the system time for random number generator
//    unsigned seed = time(0);
//    //Seeding the random number generator
//    srand(seed);
//
//    value = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
//    
//    return value;
//}

//int random;

//Declaring variables for use in this function
//int cardPosition, cardPosition2;

//This is a dynamically created array for the number of players and the bets that they make.
//int *arrayForBets;
//
//srand(time(0));
//random = rand()%MAX_VALUE;
//random = getNum();
//cout << random  << endl;

//int x = 0;
//
//while (x < 4){
//    
//    random = rand()%MAX_VALUE;
//    cout << random  << endl;
//    x++;
//    }

    
    
    //Getting the system time for random number generator
    //    unsigned seed = time(0);
    //Seeding the random number generator
    //    srand(seed);





//This function will initialize the deck of cards.
//void createDeck(Card deck[], int DECKSIZE) //creates deck
//{
//    
//    for (int i=0; i < 9; i++)
//    {
//        deck[i].number = i + 2;
//        deck[i].suite = "Hearts";
//    }
//    
//    for (int i=9; i < 12; i++)
//    {
//        deck[i].number = 10;
//        deck[i].suite = "Hearts";
//    }
//    
//    deck[12].number = 11;
//    deck[12].suite = "Hearts";
//    
//    for (int i=13; i < 22; i++)
//    {
//        deck[i].number = i - 11;
//        deck[i].suite = "Jacks";
//    }
//    
//    for (int i=22; i < 25; i++)
//    {
//        deck[i].number = 10;
//        deck[i].suite = "Jacks";
//    }
//    
//    deck[25].number = 11;
//    deck[25].suite = "Jacks";
//    
//    
//    for (int i=26; i < 35; i++)
//    {
//        deck[i].number = i - 24;
//        deck[i].suite = "Spades";
//    }
//    
//    for (int i=35; i < 38; i++)
//    {
//        deck[i].number = 10;
//        deck[i].suite = "Spades";
//    }
//    
//    deck[38].number = 11;
//    deck[38].suite = "Spades";
//    
//    for (int i=39; i < 48; i++)
//    {
//        deck[i].number = i - 37;
//        deck[i].suite = "Clubs";
//    }
//    
//    for (int i = 48; i < 51; i++)
//    {
//        deck[i].number = 10;
//        deck[i].suite = "Clubs";
//    }
//    
//    deck[51].number = 11;
//    deck[51].suite = "Clubs";
//    
//}











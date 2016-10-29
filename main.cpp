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
const int BLACKJACK = 21;

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
int cardCheck(int, int, int);

void dealTwoCards(Card [], int, Card [], int, int &, int &);
void dealTwoCardsTwo(Card [], int, Card [], int, int &, int &);

void dealOneCard(Card [], int, Card [], int, int &, int &);
void makeBets(int *, int);
void surrender(int *, int);
void Doubledown(Card [], int, Card [], int, int &, int &, int *, int);

void getDealersCards(Card [], int, Card [], int, int &, int &);

bool Winner(bool, int playerOneTotal, int *, int);
bool WinnerTwo(bool, int playerOneTotal, int *, int);


//******************************
//Main Function
//******************************

int main(){
    
    //Declaring variables
    int players, again, action, cardLocation, playerOneTotal, playerTwoTotal, dealerTotal;
    int *arrayForBets;
    int dealerWinnings = 0;
    int playerOneEarnings = 0;
    bool BlackJack = false;
    bool foldem = false;
    bool hold = false;
    bool Break = false;
    bool Surrender = false;
    
    
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
    //game(players, deck, DECKSIZE); NOT USING AS OF NOW
    
    do {
        
        //These variables must be returned to zero at the end of every round.
        cardLocation = 0;
        playerOneTotal = 0;
        playerTwoTotal = 0;
        dealerTotal = 0;
        Break = false;
        Surrender = false;
        
        //This will shuffle the deck of cards
        shuffle(deck, DECKSIZE);
        
        //This line sets up the array for the players bets
        arrayForBets = new int[players];
        //Calling the function allow the player to see their bets
        makeBets(arrayForBets, players);
    
        //This conditional statement will deal the initial first two cards based on how many players
        //There are playing the game.
        if (players == 1){
            
            dealTwoCards(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
            
        }else if (players == 2){
            dealTwoCards(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
            cout << endl;
            dealTwoCardsTwo(deck, DECKSIZE, playerTwo, MAXDECK, cardLocation, playerTwoTotal);
        }
        
        //These functions check to see if player one or two has BLACKJACK on the initial round.
        Break = Winner(BlackJack, playerOneTotal, arrayForBets, players);
        Break = WinnerTwo(BlackJack, playerTwoTotal, arrayForBets, players);
        
        //This is a line break to help with output
        cout << endl;
        //This function will get the dealers hand.
        getDealersCards(deck, DECKSIZE, dealer, MAXDECK, cardLocation, dealerTotal);
        cout << endl;
        
        //if (players == 1 && (foldem == false && BlackJack == false && hold == false) ){
        if (players == 1 && Break == false){
            while (Break == false){
                cout << "1. Hit" << endl;
                cout << "2. Stand" << endl;
                cout << "3. Double Down" << endl;
                cout << "4. Surrender" << endl;
                cout << "Player one, what is your action: " << endl;
                cin >> action;
                if (action == 1){
                    dealOneCard(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
                    if (playerOneTotal > BLACKJACK){
                        Break = true;
                    }else if (playerOneTotal == BLACKJACK){
                        Break = true;
                    }
                }else if (action == 2){
                    stand();
                    Break = true;
                }else if (action == 3){
                    Doubledown(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal, arrayForBets, players);
                    Break = true;
                //May need a function to end game-since the player doubledown  or use a boolean flag?
                }else if (action == 4){
                    surrender(arrayForBets, players);
                    Break = true;
                    Surrender = true;
                }
            }
        }
        
        cout << endl;
        //Writing the function for the below if then statement.
//        void determineWinnerOne(bool Surrender, int playerOneTotal, int dealerTotal,int *arrayForBets, int players, int dealerWinnings);
        
        if (players == 1 && Surrender == false){
            if ((playerOneTotal > dealerTotal) && (playerOneTotal <= 21)){
                cout << "The players total was: " << playerOneTotal << endl;
                cout << "The Dealers total was: " << dealerTotal << endl;
                cout << "Player one Wins!" << endl;
                arrayForBets[0] = arrayForBets[0] * 2;
                cout << "You won $" << arrayForBets[0] << endl;
                playerOneEarnings += arrayForBets[0];
                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
            }else if (playerOneTotal < dealerTotal){
                cout << "The players total was: " << playerOneTotal << endl;
                cout << "The Dealers total was: " << dealerTotal << endl;
                cout << "The dealer wins!" << endl;
                cout << "The dealer won $" << arrayForBets[0] << endl;
                playerOneEarnings -= arrayForBets[0];
                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
                dealerWinnings += arrayForBets[0];
            }else if (playerOneTotal == dealerTotal){
                cout << "The dealer and player have the same values" << endl;
                cout << "The game is a tie and no one wins anything" << endl;
            }else if (playerOneTotal > 21 && dealerTotal <= 21){
                cout << "The players total was: " << playerOneTotal << endl;
                cout << "The Dealers total was: " << dealerTotal << endl;
                cout << "The dealer won!" << endl;
                cout << "The dealer won $" << arrayForBets[0] << endl;
                playerOneEarnings -= arrayForBets[0];
                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
                dealerWinnings += arrayForBets[0];
            }else{
                cout << "The players total was: " << playerOneTotal << endl;
                cout << "The Dealers total was: " << dealerTotal << endl;
                cout << "The dealer won!" << endl;
                cout << "The dealer won $" << arrayForBets[0] << endl;
                dealerWinnings += arrayForBets[0];
                playerOneEarnings -= arrayForBets[0];
                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
            }
        }else if (players == 1 && Surrender == true){
            cout << "You choose to surrender!" << endl;
            cout << "You now have " << arrayForBets[0] << endl;
            playerOneEarnings -= arrayForBets[0];
            cout << "Player one your total earnings are $" << playerOneEarnings << endl;
            
        }
        
//        if (players == 1){
//            playerOneEarnings += arrayForBets[0];
//            cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//        }

        //Asking the player(s) if they want to play again.
        again = playAgain();
        cardLocation++;
        
        //This will automatically end the program if the last card is reached. THIS FUNCTION MAY
        //NOT BEEN NEEDED BECAUSE THE PROGRAM ALWAYS RESHUFFLES THE CARD DECK AND CARD LOCATION TO
        //ZERO THROUGH EVERY ROUND.
        //again = cardCheck(cardLocation, DECKSIZE, again);


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

//This function will allow the players to make their bets
void makeBets(int *arrayForBets, int players){
    
    //This loop will ask the players to make their bets.
    for (int i = 0; i < players; i ++){
        cout << "Player " << i + 1 << " please place your bet: " << endl;
        cout << "The bet must be between 10 and 500" << endl;
        cin >> arrayForBets[i];
        while ((arrayForBets[i] < 10) || (arrayForBets[i] > 500) ){
            cout << "The bets must be between 10 and 500" << endl;
            cin >> arrayForBets[i];
        }
    }
}//End of makeBets function

//This function will deal two cards to the dealer.
void getDealersCards(Card deck[], int DECKSIZE, Card dealer[], int MAXDECK, int &cardLocation, int &dealerTotal){
    
    for (int i = 0; i < 2; i++){
        
        dealer[i].valueOne = deck[cardLocation].valueOne;
        dealer[i].valueTwo = deck[cardLocation].valueTwo;
        dealer[i].suite = deck[cardLocation].suite;
        dealer[i].face = deck[cardLocation].face;
        dealerTotal = dealerTotal + deck[cardLocation].valueOne;
        cardLocation++;
    }
    
    cout << "The dealers top card is a " << dealer[1].valueOne << " " << "of " << dealer[1].suite << endl;

}//End of getDealersCards function


//This function will deal the first two cards to the player(s)
void dealTwoCards(Card deck[], int DECKSIZE, Card playerOne[], int MAXDECK, int &cardLocation, int &playerOneTotal){
    
    int aceValue;
    
    cout << "Player One here are your first two cards: " << endl;
    
    for (int i = 0; i < 2; i++)
    {
        cout << "your " << i + 1 << " card is the " << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite  << endl;
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
    cout << endl;
    cout << "Player One your total is: " << playerOneTotal << endl;
    
}//End of dealTwoCars


//This function deals the cards for the second player.
void dealTwoCardsTwo(Card deck[], int DECKSIZE, Card playerTwo[], int MAXDECK, int &cardLocation, int &playerTwoTotal){
    
    int aceValue;
    
    cout << "Player Two here are your first two cards: " << endl;
    
    for (int i = 0; i < 2; i++)
    {
        cout << "your " << i + 1 << " card is the " << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite  << endl;
        if (deck[cardLocation].valueTwo == 11){
            cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
            cin >> aceValue;
            deck[cardLocation].valueOne = aceValue;
        }
        playerTwoTotal = playerTwoTotal + deck[cardLocation].valueOne;
        playerTwo[cardLocation] = deck[cardLocation]; //assigns card to players hand
        //I have to increment the cardLocation after each hand to ensure that the cards are not
        //repeated.
        cardLocation++;
    }
    
    cout << endl;
    cout << "Player Two your total is: " << playerTwoTotal << endl;

}//End of dealTwoCardsTwo

//This function will detect if there is a winner in the game
bool Winner(bool BlackJack, int playerOneTotal, int *arrayForBets, int players){
    if (playerOneTotal == BLACKJACK){
        cout << "Player one Won" << endl;
        arrayForBets[0] = arrayForBets[0] * 2;
        cout << "Player One won " << arrayForBets[0] << endl;
        return BlackJack = true;
    }else {
        return BlackJack = false;
    }
}//End of Winner Function

//This function will detect if there is a winner in the game
bool WinnerTwo(bool BlackJack, int playerTwoTotal, int *arrayForBets, int players){
    if (playerTwoTotal == BLACKJACK){
        cout << "Player Two Won" << endl;
        arrayForBets[1] = arrayForBets[1] * 2;
        cout << "Player Two won " << arrayForBets[1] << endl;
        return BlackJack = true;
    }else {
        return BlackJack = false;
    }
}//End of Winner Function


//This function will deal one card to the player(s) when they do the hit action
void dealOneCard(Card deck[], int DECKSIZE, Card playerOne[], int MAXDECK, int &cardLocation, int &playerOneTotal){
    
    int aceValue;
    
    cout << "You just recieved a" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite << endl;
    if (deck[cardLocation].valueTwo == 11){
        cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
        cin >> aceValue;
        deck[cardLocation].valueOne = aceValue;
    }
    playerOneTotal = playerOneTotal + deck[cardLocation].valueOne;
    playerOne[cardLocation] = deck[cardLocation]; //assigns card to players hand
    cout << "Player one your total is " << playerOneTotal << endl;
    //I have to increment the cardLocation after each hand to ensure that the cards are not
    //repeated.
    cardLocation++;
    
}//End of dealOneCard function

//This function is where the player will doubledown.
void Doubledown(Card deck[], int DECKSIZE, Card playerOne[], int MAXDECK, int &cardLocation, int &playerOneTotal, int *arrayForBets, int players){
    
    float betIncrease;
    //Again may need to do something with a second player-see notes in surrender function
    
    cout << "Please enter in a percentage of how much you would like to increase the bet by: " << endl;
    cin >> betIncrease;
    int aceValue;
    
    cout << "You just recieved a" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite << endl;
    if (deck[cardLocation].valueTwo == 11){
        cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
        cin >> aceValue;
        deck[cardLocation].valueOne = aceValue;
    }
    playerOneTotal = playerOneTotal + deck[cardLocation].valueOne;
    playerOne[cardLocation] = deck[cardLocation];
    
    
    //I have to increment the cardLocation after each hand to ensure that the cards are not
    //repeated.
    cardLocation++;
    
}//End of Doubledown function

//This function will take care of the player surrendering.
void surrender(int *arrayForBets, int players){
    
    int loss;
    
    //May need a marker in here to id which player it is 1 or 2 I will also probably need an if then
    //statement to go into a certain field depending on the player. Best bet may be to use a Boolean
    //flag.
    //cout << "You choose to surrender!" << endl;
    //cout << "You will lose half your earnings" << endl;
    loss = arrayForBets[0] * .50;
    arrayForBets[0] = loss;

}//End of surrender function

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

//This function checks to see if the card deck is almost used up. If it is, it will force the
//players to end the game and reshuffle the deck.
int cardCheck(int cardLocation, int DECKSIZE, int again){
    if (cardLocation == DECKSIZE){
        again = 2;
        return again;
    }else {
        return again;
    }
}//End of cardCheck Function

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
        
        

//**************************************
//Validation functions below this point
//*************************************

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

//This function will run the main aspect of the game.
//void game(int players, Card deck[], int DECKSIZE){
//    
//    
//    
//}//End of Game Function








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

struct PlayerInfo
{
    string name;
    string emailAddress;
    string username;
    int winnings;

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
int playerChoices();
void playerOneInfo(int);
void playerTwoInfo(int);
//int cardCheck(int, int, int); old function that is not really needed.
void dealTwoCards(Card [], int, Card [], int, int &, int &);
void dealTwoCardsTwo(Card [], int, Card [], int, int &, int &);
void dealOneCard(Card [], int, Card [], int, int &, int &);
void dealOneCardTwo(Card [], int, Card [], int, int &, int &);
void makeBets(int *, int, PlayerInfo, PlayerInfo);
void surrender(int *, int);
void surrenderTwo(int *, int);
void Doubledown(Card [], int, Card [], int, int &, int &, int *, int);
void DoubleDownTwo(Card [], int, Card [],int, int &, int &, int *, int);
void getDealersCards(Card [], int, Card [], int, int &, int &);
int dealerAddCard(Card [], int, Card [], int, int &, int &);
void dealerShowCards(int, Card [], int);
bool Winner(bool, int playerOneTotal, int *, int);
bool WinnerTwo(bool, int playerOneTotal, int *, int);
void determineWinnerOne(int, int, int *, int, int &, int &);
void determineWinnerTwo(int, int, int *, int, int &, int &);
void playerOneSurrendered(int *, int , int &, int &);
void playerTwoSurredndered(int *, int, int &,int &);
void pauseProgram();
void createId(int, PlayerInfo &, PlayerInfo &);
void displayStats(int, int, int, PlayerInfo &, PlayerInfo &, int);
bool bootedOut(PlayerInfo, PlayerInfo);
void clearScreen();
void mainMenu();
void instructions();



//******************************
//Main Function
//******************************

int main(){
    
    //Declaring variables
    int players, again, action, cardLocation, playerOneTotal, playerTwoTotal, dealerTotal;
    int dealerDeckSize;
    int *arrayForBets;
    int dealerWinnings = 0;
    int playerOneEarnings = 0;
    int playerTwoEarnings = 0;
    bool BlackJack = false;
    bool Break = false;
    //bool Surrender = false; I may not need this variable since SurrenderOne Replaces it
    bool SurrenderOne = false;
    bool SurrenderTwo = false;
    bool breakOne = false;
    bool breakTwo = false;
    bool booted = false;
    //Declaring the structures which will contain info on the players.
    PlayerInfo pOne;
    PlayerInfo pTwo;
    
    
    //Creating the deck of cards
    Card deck[DECKSIZE];
    
    //These structures will be used to hold the cards that dealer, playerOne and playerTwo have
    //The constanst is set to 11 because that is the maximun number of cards that someone can have
    //before Black Jack or 21 may arise. However, the main reason why these structures were created
    //was to allow me to have a place to hold cards, if I needed them. Which became quite useful in dealing
    //with aces.
    Card playerOne[MAXDECK];
    Card playerTwo[MAXDECK];
    Card dealer[MAXDECK];
    
    //The call to this function will great the users.
    welcome();
    pauseProgram();
    clearScreen();
    
    mainMenu();
    pauseProgram();
    clearScreen();
    
    //This function will allow the user(s) to enter the number of players
    players = numberOfPlayers();
    pauseProgram();
    clearScreen();
    //Here the players create an ID for themselves.
    createId(players, pOne, pTwo);
    
    //Line break
    cout << endl;
    
    //This function call will create the deck of cards.
    createDeck(deck, DECKSIZE);
    
    do {
        
        //These variables must be returned to zero, initial condition at the end of every round.
        cardLocation = 0;
        playerOneTotal = 0;
        playerTwoTotal = 0;
        playerOneEarnings = 0;
        playerTwoEarnings = 0;
        dealerTotal = 0;
        Break = false;
        //Surrender = false; I may not need this variable since SurrenderOne Replaces it
        SurrenderOne = false;
        SurrenderTwo = false;
        breakOne = false;
        breakTwo = false;
        booted = false;
        //This line sets up the array for the players bets
        arrayForBets = new int[players];
        
        clearScreen();
        
        //This function call will shuffle the deck of cards
        shuffle(deck, DECKSIZE);
        
        //This code will forbid the players from playing the game if they have negative money.
        booted = bootedOut(pOne, pTwo);
        //If a player does have a negative balance they will be booted from the game-the while loop will break.
        if (booted){
            break;
        }
        
        //Calling the function allow the player to see their bets
        makeBets(arrayForBets, players, pOne, pTwo);
        
        clearScreen();
        
        //Line breaks-to help with output.
        cout << endl;

        //This conditional statement will deal the initial first two cards based on how many players
        //That are playing the game.
        if (players == 1){
            dealTwoCards(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
        }else if (players == 2){
            dealTwoCards(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
            cout << endl;
            dealTwoCardsTwo(deck, DECKSIZE, playerTwo, MAXDECK, cardLocation, playerTwoTotal);
        }
        
        //These functions check to see if player one or two has BLACKJACK on the initial round.
        //If they do, they will win twice the amount that they bet and they will not be allowed to
        //take any more cards.
        Break = Winner(BlackJack, playerOneTotal, arrayForBets, players);
        Break = WinnerTwo(BlackJack, playerTwoTotal, arrayForBets, players);
        
        //This is a line break to help with output
        cout << endl;
        
        //This function will get the dealers hand.
        getDealersCards(deck, DECKSIZE, dealer, MAXDECK, cardLocation, dealerTotal);
        cout << endl;
        
        //This massive conditional statement is what will allow the players to decide what actions they want to take in regards
        //to taking another card, stand, double down or surrendering.
        if (players == 1 && Break == false){
            while (breakOne == false){
                playerOneInfo(playerOneTotal);
                action = playerChoices();
                if (action == 1){
                    dealOneCard(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
                    if (playerOneTotal > BLACKJACK){
                        breakOne = true;
                    }else if (playerOneTotal == BLACKJACK){
                        breakOne = true;
                    }
                }else if (action == 2){
                    stand();
                    breakOne = true;
                }else if (action == 3){
                    Doubledown(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal, arrayForBets, players);
                    breakOne = true;
                }else if (action == 4){
                    surrender(arrayForBets, players);
                    breakOne = true;
                    SurrenderOne = true;
                }
            }
        } else if ( (players == 2) && (Break == false) ){
            while ((breakOne == false) || (breakTwo == false)){
                if (breakOne == false){
                    playerOneInfo(playerOneTotal);
                    action = playerChoices();
                    if (action == 1){
                        dealOneCard(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal);
                        if (playerOneTotal > BLACKJACK){
                            breakOne = true;
                        }else if (playerOneTotal == BLACKJACK){
                            breakOne = true;
                        }
                    }else if (action == 2){
                        stand();
                        breakOne = true;
                    }else if (action == 3){
                        Doubledown(deck, DECKSIZE, playerOne, MAXDECK, cardLocation, playerOneTotal, arrayForBets, players);
                        breakOne = true;
                    }else if (action == 4){
                        surrender(arrayForBets, players);
                        breakOne = true;
                        SurrenderOne = true;
                    }
                }
                if (breakTwo == false){
                    playerTwoInfo(playerTwoTotal);
                    action = playerChoices();
                    if (action == 1){
                        dealOneCardTwo(deck, DECKSIZE, playerTwo, MAXDECK, cardLocation, playerTwoTotal);
                        if (playerTwoTotal > BLACKJACK){
                            breakTwo = true;
                        }else if (playerTwoTotal == BLACKJACK){
                            breakTwo = true;
                        }
                    }else if (action == 2){
                        stand();
                        breakTwo = true;
                    }else if (action == 3){
                        DoubleDownTwo(deck, DECKSIZE, playerTwo, MAXDECK, cardLocation, playerTwoTotal, arrayForBets, players);
                        breakTwo = true;
                    }else if (action == 4){
                        surrenderTwo(arrayForBets, players);
                        breakTwo = true;
                        SurrenderTwo = true;
                    }
                
                }

            }
        }
        
        //This function call will add more cards to the computer if their total is 16 or below.
        dealerDeckSize = dealerAddCard(deck, DECKSIZE, dealer, MAXDECK, cardLocation, dealerTotal);
        //This function call will show the dealers hands right before the winners are announced.
        dealerShowCards(dealerDeckSize, dealer, MAXDECK);
        
        //This is another line which will help with output.
        cout << endl;
        
        //This conditional statement will determine what the first player won or lost.
        if (SurrenderOne == false){
            determineWinnerOne(playerOneTotal, dealerTotal, arrayForBets, players, dealerWinnings, playerOneEarnings);
          }else if (SurrenderOne == true){
              playerOneSurrendered(arrayForBets, players, playerOneEarnings, dealerWinnings);
        }
        
        //This conditional statement will determine what the second player won or lost.
        if(SurrenderTwo == false && players == 2){
            determineWinnerTwo(playerTwoTotal, dealerTotal, arrayForBets, players, dealerWinnings, playerTwoEarnings);
        }
        else if (SurrenderTwo == true){
            playerTwoSurredndered(arrayForBets, players, playerTwoEarnings, dealerWinnings);
        }
        
        //line break-to help with output.
        cout << endl;
        
        //This function will display the stats for the players.
        displayStats(players, playerOneEarnings, playerTwoEarnings, pOne, pTwo, dealerTotal);
        
        //line break to help with output.
        cout << endl;
        
        //Asking the player(s) if they want to play again.
        again = playAgain();
        
        //Increasing the card location.
        cardLocation++;


    } while (again != 2);
    
    //Destroying the dynamically allocated memory
    delete [] arrayForBets;
    arrayForBets = nullptr;

    
    //system("pause"); //This line is for Microsoft Visual users.
    
    return 0;
    
}// End of main function

//******************************
//Functions
//******************************

//This function is the title menu and greets the user(s)
void welcome(){
    
    //All of these cout statements introduce the user to the game.
    cout << "***********************" << endl;
    cout << "*---------------------*" << endl;
    cout << "*---------------------*" << endl;
    cout << "*----Cuddy Casino-----*" << endl;
    cout << "*---------------------*" << endl;
    cout << "*Welcome to Black Jack*" << endl;
    cout << "*---------------------*" << endl;
    cout << "*-------Where---------*" << endl;
    cout << "*------You Lose-------*" << endl;
    cout << "*-------We Win--------*" << endl;
    cout << "*---------------------*" << endl;
    cout << "***********************" << endl;
    cout << endl;


}//End of welcome function

//This function is what will determine the number of players in the game.
int numberOfPlayers(){
    
    //Declaring variables
    int players;
    
    //The user(s) enter the number of players
    cout << "Please enter the number of players (1 or 2): " << endl;
    cin >> players;
    //If the user(s) enters a value that is not acceptable they go into a validation loop.
    while (!validPlayers(players)) {
        cout << "The amount of players may only be between 1 or 2" << endl;
        cin >> players;
    }
    
    return players;
}// End of numberOfPlayers function

//This function will allow the players to make their bets
void makeBets(int *arrayForBets, int players, PlayerInfo pOne, PlayerInfo pTwo){
    
    //This loop will ask the players to make their bets.
    for (int i = 0; i < players; i++){
        //This coditional statement will excute depending on what the value of i is. It will ensure that the
        //users are only able to enter in the amount of money that they have.
        if (i == 0){
            cout << "Player " << i + 1 << " please place your bet: " << endl;
            cout << "The bet must be between 10 and " << pOne.winnings << endl;
            cin >> arrayForBets[i];
            while ( (arrayForBets[i] < 10) || (arrayForBets[i] > pOne.winnings) ){
                cout << "The bets must be between 10 and " << pOne.winnings << endl;
                cin >> arrayForBets[i];
            }
        }else if (i == 1){
            cout << "Player " << i + 1 << " please place your bet: " << endl;
            cout << "The bet must be between 10 and " << pTwo.winnings << endl;
            cin >> arrayForBets[i];
            while ((arrayForBets[i] < 10) || (arrayForBets[i] > pTwo.winnings) ){
                cout << "The bets must be between 10 and " << pTwo.winnings << endl;
                cin >> arrayForBets[i];
            }
        }
    }
}//End of makeBets function


//This function allows for the players to set up the information about who they are.
void createId(int players, PlayerInfo &pOne, PlayerInfo &pTwo){
    
    //Declaring variables which will be used to set up the user information structures.
    string name;
    string email;
    string username;
    
    //This conditional loop will allow the players to set up their user information.
    if (players == 1){
        cout << "Player One please enter your name: " << endl;
        cin >> name;
        pOne.name = name;
        cout << "Player One please enter your email: " << endl;
        cin >> email;
        pOne.emailAddress = email;
        cout << "Player One please enter a username: " << endl;
        cin >> username;
        pOne.username = username;
        pOne.winnings = 500;
        //I add this line because I had a slight bug where the program thought, in one player mode, that the second
        //player had no money and thus would enter into an endless loop.
        pTwo.winnings = 500;
    }else if (players == 2){
        cout << "Player One please enter your name: " << endl;
        cin >> name;
        pOne.name = name;
        cout << "Player One please enter your email: " << endl;
        cin >> email;
        pOne.emailAddress = email;
        cout << "Player One please enter a username: " << endl;
        cin >> username;
        pOne.username = username;
        pOne.winnings = 500;
        cout << endl;
        cout << "Player Two please enter your name: " << endl;
        cin >> name;
        pTwo.name = name;
        cout << "Player Two please enter your email: " << endl;
        cin >> email;
        pTwo.emailAddress = email;
        cout << "Player TWo please enter a username: " << endl;
        cin >> username;
        pTwo.username = username;
        pTwo.winnings = 500;
    
    }
    
    
}//End of createId function

//This function will determine if the player has enough money to play a round.
bool bootedOut(PlayerInfo pOne, PlayerInfo pTwo){
    
    bool booted = false;
    
    //If player one has no winnings they get booted out of the virtual casino
    if (pOne.winnings <= 0){
        cout << "Player one, you attempted to make bets with money you did not have" << endl;
        cout << "You are now booted out of the game!" << endl;
        booted = true;
        return booted;
    //If player two has no money then they get booted out of the casino.
    }else if (pTwo.winnings <= 0){
        cout << "Player Two, you attempted to make bets with money you did not have" << endl;
        cout << "You are now booted out of the game!" << endl;
        cout << "Player one is booted as well!" << endl;
        booted = true;
        return booted;
    }
    
    //returning the boolean variable to determine if the player(s) will be booted by the game.
    return booted;
    
}//End of bootedOut function

//This function will display the earnings of the players.
void displayStats(int players, int playerOneEarnings, int playerTwoEarnings, PlayerInfo &pOne, PlayerInfo &pTwo, int dealerTotal){
    
    //Showing the game stats for the first player
    if (players == 1){
        cout << "Here are the stats for the amount of money and wins each player has: " << endl;
        pOne.winnings = pOne.winnings + playerOneEarnings;
        cout << pOne.username << " has a total of: $" << pOne.winnings << endl;
    //Showing the game stats for the first and second player.
    }else if (players == 2){
        cout << "Here are the stats for the amount of money and wins each player has: " << endl;
        cout << endl;
        pOne.winnings = pOne.winnings + playerOneEarnings;
        pTwo.winnings = pTwo.winnings + playerTwoEarnings;
        cout << pOne.username << " has a total of: $" << pOne.winnings << endl;
        cout << pTwo.username << " has a total of: $" << pTwo.winnings << endl;
    }

    
}//end of displayStats function

//This function will deal two cards to the dealer.
void getDealersCards(Card deck[], int DECKSIZE, Card dealer[], int MAXDECK, int &cardLocation, int &dealerTotal){
    
    //This for loop will deal the initial two cards to the dealer.
    for (int i = 0; i < 2; i++){
        
        dealer[i].valueOne = deck[cardLocation].valueOne;
        dealer[i].valueTwo = deck[cardLocation].valueTwo;
        dealer[i].suite = deck[cardLocation].suite;
        dealer[i].face = deck[cardLocation].face;
        //This conditional statement will determine what the value of an ace is if the dealer gets one. In this case,
        //if the dealer total is less than or equal to 10, the ace will be worth 11 points. Greater than 10, the ace
        //will be worth 1 point.
        if (deck[cardLocation].valueTwo == 11 && dealerTotal <= 10){
            dealerTotal = dealerTotal + deck[cardLocation].valueTwo;
        }else if (deck[cardLocation].valueTwo == 11 && dealerTotal > 10){
            dealerTotal = dealerTotal + deck[cardLocation].valueOne;
        }else{
            dealerTotal = dealerTotal + deck[cardLocation].valueOne;
        }
        //card location is incremented so a card is not used twice.
        cardLocation++;
    }
    //This line here will get the dealers top card.
    cout << "The dealers top card is a " << dealer[1].valueOne << " " << "of " << dealer[1].suite << endl;

}//End of getDealersCards function

//This function simply displays information for player one.
void playerOneInfo(int playerOneTotal){
    
    cout << endl;
    //Player ones total is outputed.
    cout << "Player One your total is: " << playerOneTotal << endl;
    cout << "Player One, what is your action: " << endl;
    
}//End of playerOneInfo function

//This function simply displays information for player two.
void playerTwoInfo(int playerTwoTotal){
    
    cout << endl;
    //Player two's total is outputted.
    cout << "Player Two your total is: " << playerTwoTotal << endl;
    cout << "Player Two, what is your action: " << endl;
    
}//End of playerOneInfo function

//This function provides the menu for the options on what the player can do.
int playerChoices(){
    
    int action;
    //Choices are presented for the players actions
    cout << "1. Hit" << endl;
    cout << "2. Stand" << endl;
    cout << "3. Double Down" << endl;
    cout << "4. Surrender" << endl;
    cout << "What is your action: " << endl;
    cin >> action;
    //If a correct selection is not made, then the user will enter a while loop that will force the user to make a
    //valid choice before moving on.
    while ((action < 1) || (action > 4)){
        cout << "That is not a valid selection" << endl;
        cout << "Please enter in 1 - 4 for your choice" << endl;
        cin >> action;
    }
    
    return action;
    
}//End of playerOneAction function

//This function will continue to deal cards to the dealer until they get over 17.
int dealerAddCard(Card deck [], int DECKSIZE, Card dealer[], int MAXDECK, int &cardLocation, int &dealerTotal){
    
    //I have this variable equal two because the computer received two cards which are in the dealer structure. This means that
    //spots 0 and 1 are taken. Thus, the next card that the dealer gets will take up the subscript 2 location. Each time
    //the below loop is incremented, i will increase by one to place more cards into the dealer structure.
    int i = 2;
    
    //If the dealers total is below 16 they get more and more cards added to their total until it is greater than 16.
    while (dealerTotal <= 16){
        dealer[i].valueOne = deck[cardLocation].valueOne;
        dealer[i].valueTwo = deck[cardLocation].valueTwo;
        dealer[i].suite = deck[cardLocation].suite;
        dealer[i].face = deck[cardLocation].face;
        //This conditional statement will check to see if the dealer recieved an ace. If the dealer did then the program will
        //assign a value of the ace based on the dealers total currently stands at.
        if (deck[cardLocation].valueTwo == 11 && dealerTotal <= 10){
            dealerTotal = dealerTotal + deck[cardLocation].valueTwo;
        }else if (deck[cardLocation].valueTwo == 11 && dealerTotal > 10){
            dealerTotal = dealerTotal + deck[cardLocation].valueOne;
        }else{
            dealerTotal = dealerTotal + deck[cardLocation].valueOne;
        }
        //Incrementing card location
        cardLocation++;
        //I keep track of the number of times that the loop increments.
        i++;
    }
    
    //I then return the number of times that the deck incremented to use in the dealerShowCards function.
    return i;
    
}//End of dealerAddCard Function

//This function will reveal the dealers cards.
void dealerShowCards(int dealerDeckSize, Card dealer[], int MAXDECK){
    
    cout << endl;
    cout << "The dealer has the following cards: " << endl;
    //The value of i, which is now dealerDeckSize, which was calculated in the dealerAddCard function, will be used
    //to determine the amount of times to loop through to show all of the dealers cards.
    for (int i = 0; i < dealerDeckSize; i++){
        cout << "card " << i + 1 << " is a " << dealer[i].valueOne << " of " << dealer[i].suite << endl;
    }
    
}//End of dealerShowCards function


//This function will deal the first two cards to the player(s). All of the comments below also
//apply to dealTwoCardsTwo.
void dealTwoCards(Card deck[], int DECKSIZE, Card playerOne[], int MAXDECK, int &cardLocation, int &playerOneTotal){
    
    //Displaying the information to the player as to what their first two cards are.
    cout << "Player One here are your first two cards: " << endl;
    
    //This for loop will give the first two cards to the first player.
    for (int i = 0; i < 2; i++)
    {
        cout << "Card " << i + 1 << " is the " << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite  << endl;
        
        //I am getting the total for the player by adding togather is current total to the value
        //of the card.
        playerOneTotal = playerOneTotal + deck[cardLocation].valueOne;
        
        //These lines are where the players deck structure is loaded with what they were given. This will be useful
        //further down in this function when an ace is given to the player.
        playerOne[i].valueOne = deck[cardLocation].valueOne;
        playerOne[i].valueTwo = deck[cardLocation].valueTwo;
        playerOne[i].suite = deck[cardLocation].suite;
        playerOne[i].face = deck[cardLocation].face;
   
        //playerOne[cardLocation] = deck[cardLocation]; //assigns card to players hand
        
        //I have to increment the cardLocation after each hand to ensure that the cards are not
        //repeated.
        cardLocation++;
    }
    
    //This variable is what will be used to hold the value of what an ace will be worth.
    int points;
    
    //This conditional block will check to see if the player has an ace value. I originally had this code in the above loop to
    //determine what an ace value was. The problem was that if an ace was the first card received the user had to decide if
    //they wanted its value to be an 1 or an 11. Thus, I had to write this much longer line of code to allow the player to
    //determine the value of an ace after they recieved their two cards.
    if (playerOne[0].valueTwo == 11){
        cout << endl;
        cout << "Player one, one of your cards is an 'ACE'" << endl;
        cout << "This card may be worth either 1 or 11 points " << endl;
        cout << "You currenty have a total of " << playerOneTotal << endl;
        cout << "1. 1 point" << endl;
        cout << "2. 11 points" << endl;
        cout << "Would you like the card to be worth 1 or 11 points: (1/2) " << endl;
        cin >> points;
        //validation loop to ensure that the correct value was entered.
        while ((points < 1) || (points > 2)){
            cout << "That value is not allowed. Please enter 1 or 2" << endl;
            cin >> points;
        }
        //Conditional statement to determine assign the value of the ace-either a 1 or a 11.
        if (points == 1){
            playerOne[0].valueOne = 1;
        }else if (points == 2){
            playerOne[0].valueOne = 11;
        }
        //Assigning the value for what was selected to the new total.
        playerOneTotal = playerOne[0].valueOne + playerOne[1].valueOne;
        //Displaying the new total to the screen.
        cout << "Your new total is " << playerOneTotal << endl;
    //This conditional statement will kick in if the second card is an ace.
    }else if (playerOne[1].valueTwo == 11){
        cout << endl;
        cout << "Player one, one of your cards is an 'ACE'" << endl;
        cout << "This card may be worth either 1 or 11 points " << endl;
        cout << "You currenty have a total of " << playerOneTotal << endl;
        cout << "1. 1 point" << endl;
        cout << "2. 11 points" << endl;
        cout << "Would you like the card to be worth 1 or 11 points: " << endl;
        cin >> points;
        //Validation statement to ensure that the correct value was entered.
        while ((points < 1 ) || (points > 2)){
            cout << "That value is not allowed. Please enter 1 or 2" << endl;
            cin >> points;
        }
        if (points == 1){
            playerOne[1].valueOne = 1;
        }else if (points == 2){
            playerOne[1].valueOne = 11;
        }
        //assigning the new total
        playerOneTotal = playerOne[0].valueOne + playerOne[1].valueOne;
        //Displaying the new total.
        cout << "Your new total is " << playerOneTotal << endl;
    }else {
        cout << endl;
        cout << "Player One your total is: " << playerOneTotal << endl;
    }
    
    //This line pauses the program and waits for user input to continue.
    pauseProgram();

}//End of dealTwoCars

//This function will pause the program to allow the players to review information. In many ways, the only purpose of this
//function is to pause the program so that the user may review information. Before adding this function, I felt that the
//program was moving to 'fast'.
void pauseProgram(){
    
    char temp;
    cout << endl;
    cout << "Press any letter to continue" << endl;
    cin >> temp;
    
}//End of PuaseProgram function


//This function deals the cards for the second player.
void dealTwoCardsTwo(Card deck[], int DECKSIZE, Card playerTwo[], int MAXDECK, int &cardLocation, int &playerTwoTotal){
    
    //Displaying the information to the player as to what their first two cards are.
    cout << "Player Two here are your first two cards: " << endl;
    
    //This for loop will give the first two cards to the second player.
    for (int i = 0; i < 2; i++)
    {
        cout << "Card " << i + 1 << " is the" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite  << endl;
        playerTwoTotal = playerTwoTotal + deck[cardLocation].valueOne;
        
        //playerTwo[cardLocation] = deck[cardLocation]; //assigns card to players hand
        
        //These lines are where the players deck structure is loaded with what they were given. This will be useful
        //further down in this function when an ace is given to the player.
        playerTwo[i].valueOne = deck[cardLocation].valueOne;
        playerTwo[i].valueTwo = deck[cardLocation].valueTwo;
        playerTwo[i].suite = deck[cardLocation].suite;
        playerTwo[i].face = deck[cardLocation].face;
        
        //I have to increment the cardLocation after each hand to ensure that the cards are not
        //repeated.
        cardLocation++;
    }
    
    //This variable is what will be used to hold the value of what an ace will be worth.
    int points;

    //This conditional block will check to see if the player has an ace value. I originally had this code in the above loop to
    //determine what an ace value was. The problem was that if an ace was the first card received the user had to decide if
    //they wanted its value to be an 1 or an 11. Thus, I had to write this much longer line of code to allow the player to
    //determine the value of an ace after they recieved their two cards.
    if (playerTwo[0].valueTwo == 11){
        cout << endl;
        cout << "Player Two, one of your cards is an 'ACE'" << endl;
        cout << "This card may be worth either 1 or 11 points " << endl;
        cout << "You currenty have a total of " << playerTwoTotal << endl;
        cout << "1. 1 point" << endl;
        cout << "2. 11 points" << endl;
        cout << "Would you like the card to be worth 1 or 11 points: (1/2) " << endl;
        cin >> points;
        //Validation loop to ensure that the correct value was entered.
        while ((points < 1) || (points > 2)){
            cout << "That value is not allowed. Please enter 1 or 2" << endl;
            cin >> points;
        }
        if (points == 1){
            playerTwo[0].valueOne = 1;
        }else if (points == 2){
            playerTwo[0].valueOne = 11;
        }
        playerTwoTotal = playerTwo[0].valueOne + playerTwo[1].valueOne;
        cout << "Your new total is " << playerTwoTotal << endl;
    }else if (playerTwo[1].valueTwo == 11){
        cout << endl;
        cout << "Player Two, one of your cards is an 'ACE'" << endl;
        cout << "This card may be worth either 1 or 11 points " << endl;
        cout << "You currenty have a total of " << playerTwoTotal << endl;
        cout << "1. 1 point" << endl;
        cout << "2. 11 points" << endl;
        cout << "Would you like the card to be worth 1 or 11 points: " << endl;
        cin >> points;
        //Validation loop to ensure that the correct value was entered.
        while ((points < 1) || (points > 2)){
            cout << "That value is not allowed. Please enter 1 or 2" << endl;
            cin >> points;
        }
        if (points == 1){
            playerTwo[1].valueOne = 1;
        }else if (points == 2){
            playerTwo[1].valueOne = 11;
        }
        playerTwoTotal = playerTwo[0].valueOne + playerTwo[1].valueOne;
        cout << "Your new total is " << playerTwoTotal << endl;
    }else {
        cout << endl;
        cout << "Player Two your total is: " << playerTwoTotal << endl;
    }
    
    //This line pauses the program and waits for user input to continue.
    pauseProgram();

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
    
    //This line is dealing out the card to the player.
    cout << "You just recieved a" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite << endl;
    
    //This conditional statement will check to see if the card, that the player recieves is an ace.
    //If the card is an ace, the player will be allowed to choose its value.
    if (deck[cardLocation].valueTwo == 11){
        cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
        cin >> aceValue;
        //If the wrong value is entered, the player goes into a validation loop. The program will not move on until
        //the correct value is entered.
        while ((aceValue != 1) && (aceValue != 11)){
            cout << "Please enter in the correct value, 1 or 11" << endl;
            cin >> aceValue;
        }
        deck[cardLocation].valueOne = aceValue;
    }
    //The players new total is calculated by adding together the playerOneTotal plus the value of the new card.
    playerOneTotal = playerOneTotal + deck[cardLocation].valueOne;
    
    //playerOne[cardLocation] = deck[cardLocation]; //assigns card to players hand This line probably not needed.
    //This line displays the new total to the screen.
    cout << "Player one your total is " << playerOneTotal << endl;
    //I have to increment the cardLocation after each hand to ensure that the cards are not
    //repeated.
    cardLocation++;
    
    //This line pauses the program and waits for user input to continue.
    pauseProgram();
    
}//End of dealOneCard function

//This function will deal one card to the second player when they do the hit action
void dealOneCardTwo(Card deck[], int DECKSIZE, Card playerTwo[], int MAXDECK, int &cardLocation, int &playerTwoTotal){
    
    int aceValue;
    
    //This line is dealing out the card to the player.
    cout << "You just recieved a" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite << endl;
    
    //This conditional statement will check to see if the card, that the player recieves is an ace.
    //If the card is an ace, the player will be allowed to choose its value.
    if (deck[cardLocation].valueTwo == 11){
        cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
        cin >> aceValue;
        //A validation loop to ensure that the player enters the correct value.
        while ((aceValue != 1) && (aceValue != 11)){
            cout << "Please enter in the correct value, 1 or 11" << endl;
            cin >> aceValue;
        }
        deck[cardLocation].valueOne = aceValue;
    }
    //The players new total is calculated by adding together the playerOneTotal plus the value of the new card.
    playerTwoTotal = playerTwoTotal + deck[cardLocation].valueOne;
    //playerTwo[cardLocation] = deck[cardLocation]; //assigns card to players hand Line probably not needed
    
    //This line displays the new total to the screen.
    cout << "Player Two your total is " << playerTwoTotal << endl;
    
    //I have to increment the cardLocation after each hand to ensure that the cards are not
    //repeated.
    cardLocation++;
    
    //This line pauses the program and waits for user input to continue.
    void pauseProgram();

}// End of dealOneCardTwo Function

//This function is where the player will doubledown.
void Doubledown(Card deck[], int DECKSIZE, Card playerOne[], int MAXDECK, int &cardLocation, int &playerOneTotal, int *arrayForBets, int players){
    
    float betIncrease;
    int aceValue;
    
    //The player is asked what percentage they want to increase their wager by.
    cout << "Player One, please enter in a percentage (0-1) of how much you would like to increase the bet by: " << endl;
    cin >> betIncrease;
    //If the bet increase is outside of the acceptable range, the player is asked to enter the correct amount.
    while ((betIncrease < 0) || (betIncrease > 1)){
        cout << "Please enter a value between 0 and 1" << endl;
        cin >> betIncrease;
    }
    
    //The player is given a card.
    cout << "Player One you just recieved a" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite << endl;
    //The card is checked to see whether it is an ace.
    if (deck[cardLocation].valueTwo == 11){
        cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
        cin >> aceValue;
        deck[cardLocation].valueOne = aceValue;
    }
    //Calculating the bet increase and changing the initial bet to it.
    arrayForBets[0] = (arrayForBets[0] * betIncrease) + arrayForBets[0];
    //Calculating the total of the cards.
    playerOneTotal = playerOneTotal + deck[cardLocation].valueOne;
    //playerOne[cardLocation] = deck[cardLocation]; //May need to get rid of this line.
    
    //Telling the user what their new bet is at.
    cout << "Your bet is now at " << arrayForBets[0] << endl;
    cout << endl;
    
    
    //I have to increment the cardLocation after each hand to ensure that the cards are not
    //repeated.
    cardLocation++;
    
    //This line pauses the program and waits for user input to continue.
    void pauseProgram();
    
}//End of Doubledown function

//This function is where the second player will doubledown.
void DoubleDownTwo(Card deck[], int DECKSIZE, Card playerTwo[],int  MAXDECK, int &cardLocation, int &playerTwoTotal, int *arrayForBets, int players){
    
    float betIncrease;
    int aceValue;
    
    //The player is asked what percentage they want to increase their wager by.
    cout << "Player Two, Please enter in a percentage (0-1) of how much you would like to increase the bet by: " << endl;
    cin >> betIncrease;
    //If the bet increase is outside of the acceptable range, the player is asked to enter the correct amount.
    while ((betIncrease < 0) || (betIncrease > 1)){
        cout << "Please enter a value between 0 and 1" << endl;
        cin >> betIncrease;
    }

    //The player is given a card.
    cout << "You just recieved a" << deck[cardLocation].face << " " << deck[cardLocation].valueOne << " of " << deck[cardLocation].suite << endl;
    //The card is checked to see whether it is an ace.
    if (deck[cardLocation].valueTwo == 11){
        cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
        cin >> aceValue;
        deck[cardLocation].valueOne = aceValue;
    }
    //Calculating the bet increase and changing the initial bet to it.
    arrayForBets[1] = (arrayForBets[1] * betIncrease) + arrayForBets[1];
    //Calculating the total of the cards.
    playerTwoTotal = playerTwoTotal + deck[cardLocation].valueOne;
    
    //playerTwo[cardLocation] = deck[cardLocation]; Line may not be needed since I never used this.
    
    //Telling the user what their new bet is at.
    cout << "Your bet is now at " << arrayForBets[1] << endl;
    //This line is here to help with output
    cout << endl;
    
    //I have to increment the cardLocation after each hand to ensure that the cards are not
    //repeated.
    cardLocation++;
    
    //This line pauses the program and waits for user input to continue.
    void pauseProgram();

}//End of DoubleDown Function


//This function will take care of the player surrendering.
void surrender(int *arrayForBets, int players){
    
    //Creating a loss variable to hold the amount that the player will lose.
    int loss;
    
    //This line will take half the players bet if they choose to surrender.
    loss = arrayForBets[0] * .50;
    //Making the value in the array equal the new loss variable.
    arrayForBets[0] = loss;

}//End of surrender function

//This function will take care of the second player surrendering.
void surrenderTwo(int *arrayForBets, int players){
    
    //Creating a loss variable to hold the amount that the player will lose.
    int loss;
    
    //This line will take half the players bet if they choose to surrender.
    loss = arrayForBets[1] * .50;
    //Making the value in the array equal the new loss variable.
    arrayForBets[1] = loss;
    

}//End of Surrender function

//This function will simply alert the user that they have decided to stand
//meaning that they will no longer take any cards.
void stand(){
    
    //Advising the player that they choose stand and what it means.
    cout << "You choose to stand" << endl;
    cout << "This means you are not asking for any more cards!" << endl;
    
    //This line pauses the program and waits for user input to continue.
    void pauseProgram();
    
}//End of stand function


//This function will ask the player if they want to play again
int playAgain(){
    
    int again;
    //Giving the player the option if they want to play again.
    cout << "1. Play Again" << endl;
    cout << "2. Stop Playing" << endl;
    cout << "Do you want to play again? " << endl;
    cin >> again;
    //Input validation is occuring to ensure that the player chooses the correct option.
    while (!validAgain(again)) {
        cout << "You may only select 1 or 2" << endl;
        cin >> again;
    }
    
    return again;
    
}// End of PlayAgain function

//I may not need this function-I once did but then took it out.
//This function checks to see if the card deck is almost used up. If it is, it will force the
//players to end the game and reshuffle the deck.
//int cardCheck(int cardLocation, int DECKSIZE, int again){
//    
//    if (cardLocation == DECKSIZE){
//        again = 2;
//        return again;
//    }else {
//        return again;
//    }
//    
//}//End of cardCheck Function

//This function will initialize the deck of cards.
void createDeck(Card deck[], int DECKSIZE) //creates deck
{
            //One thing that may not make a lot of sense is that is structure has a a valueTwo. This is really not needed except
            //for the situation involving an ACE. The value two is how I identify an ace as well as let the user or computer
            //select if they want the value of the card to be a 1 or an 11. Everything else about the structure should make sense.
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
    int a;
    const int TEMPSIZE = 52;
    Card temp[TEMPSIZE];
    time_t * value;
    value = 0;
    
    //Using the system clock to produce an initial time
    seed = time(value);
    //Seeding the random number generator
    srand(seed);
    
    //Creating an array which will hold all the random values.
    int random[52];
    
    a = 0;
    
    //Here, I am filling the random array. Each number in it will be in a random order.
    while(a < 52)
    {
        //This line assigns a random number to the current location of what a is.
        random[a] = rand() % 52;
        //Incrementing a to fill the next flot.
        a++;
    }
    
    //A loop to shuffle cards
    for (int i = 0; i < 52; i++)
    {
        //Temp will hold the card.
        temp[i] = deck[i];
        //A new card is assigned to place i.
        deck[i] = deck[random[i]];
        //Old card is assigned to place random.
        deck[random[i]] = temp[i];
    }
}

//This function will use a massive conditional statement to determine if player one beat the dealer.
void determineWinnerOne(int playerOneTotal, int dealerTotal, int *arrayForBets, int players, int &dealerWinnings, int &playerOneEarnings){
    if (playerOneTotal == 21){
        cout << "Player One your total was: " << playerOneTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "Player one Wins!" << endl;
        arrayForBets[0] = arrayForBets[0] * 2;
        cout << "You won $" << arrayForBets[0] << endl;
        playerOneEarnings += arrayForBets[0];
        //cout << "Player one your earnings are $" << playerOneEarnings << endl;
    }else if (playerOneTotal > 21 && dealerTotal > 21){
        cout << "Player One went BUST" << endl;
        cout << "Dealer wins!" << endl;
        cout << "The dealer won $" << arrayForBets[0] << endl;
        playerOneEarnings -= arrayForBets[0];
        cout << "Player one you lost $" << playerOneEarnings << endl;
        dealerWinnings += arrayForBets[0];
    }else if ((playerOneTotal > dealerTotal) && (playerOneTotal <= 21)){
        cout << "Player One your total was: " << playerOneTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "Player one Wins!" << endl;
        arrayForBets[0] = arrayForBets[0] * 2;
        cout << "You won $" << arrayForBets[0] << endl;
        playerOneEarnings += arrayForBets[0];
        //cout << "Player one your earnings are $" << playerOneEarnings << endl;
    }else if (playerOneTotal < dealerTotal && (dealerTotal > 21)){
        cout << "Player One your total was: " << playerOneTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "Player one Wins!" << endl;
        arrayForBets[0] = arrayForBets[0] * 2;
        cout << "You won $" << arrayForBets[0] << endl;
        playerOneEarnings += arrayForBets[0];
        //cout << "Player one your earnings are $" << playerOneEarnings << endl;
    }else if (playerOneTotal < dealerTotal && (dealerTotal <= 21)){
        cout << "Player One your total was: " << playerOneTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "The dealer wins!" << endl;
        cout << "The dealer won $" << arrayForBets[0] << endl;
        playerOneEarnings -= arrayForBets[0];
        cout << "Player one you lost: " << playerOneEarnings << endl;
        dealerWinnings += arrayForBets[0];
    }else if (playerOneTotal == dealerTotal){
        cout << "The dealer and player have the same values" << endl;
        cout << "The game is a tie and no one wins anything" << endl;
    }else if (playerOneTotal > 21 && dealerTotal <= 21){
        cout << "Player One your total was: " << playerOneTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "The dealer won!" << endl;
        cout << "The dealer won $" << arrayForBets[0] << endl;
        playerOneEarnings -= arrayForBets[0];
        cout << "Player one, you lost $" << playerOneEarnings << endl;
        dealerWinnings += arrayForBets[0];
    }else{
        cout << "Player One your total was: " << playerOneTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "The dealer won!" << endl;
        cout << "The dealer won $" << arrayForBets[0] << endl;
        dealerWinnings += arrayForBets[0];
        playerOneEarnings -= arrayForBets[0];
        cout << "Player one you lost $" << playerOneEarnings << endl;
    }
}//End of determineWinnerOne Function

//This function will use a massive conditional statement to determine if player Two beat the dealer.
void determineWinnerTwo(int playerTwoTotal, int dealerTotal, int *arrayForBets, int players, int &dealerWinnings, int &playerTwoEarnings){
    cout << endl;
    if (playerTwoTotal == 21){
        cout << "Player Two your total was: " << playerTwoTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "Player Two Wins!" << endl;
        arrayForBets[1] = arrayForBets[1] * 2;
        cout << "You won $" << arrayForBets[1] << endl;
        playerTwoEarnings += arrayForBets[1];
        //cout << "Player two your earnings are $" << playerTwoEarnings << endl;
    }else if (playerTwoTotal > 21 && dealerTotal > 21){
        cout << "Player Two went BUST!!!" << endl;
        cout << "Dealer wins!" << endl;
        cout << "The dealer won $" << arrayForBets[1] << endl;
        playerTwoEarnings -= arrayForBets[1];
        //cout << "Player Two your earnings are $" << playerTwoEarnings << endl;
        dealerWinnings += arrayForBets[1];
    }else if((playerTwoTotal > dealerTotal) && (playerTwoTotal <= 21)){
        cout << "Player Two your total was: " << playerTwoTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "Player Two Wins!" << endl;
        arrayForBets[1] = arrayForBets[1] * 2;
        cout << "You won $" << arrayForBets[1] << endl;
        playerTwoEarnings += arrayForBets[1];
        //cout << "Player two your earnings are $" << playerTwoEarnings << endl;
    }else if (playerTwoTotal < dealerTotal && (dealerTotal > 21)){
        cout << "Player Two your total was: " << playerTwoTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "Player Two Wins!" << endl;
        arrayForBets[0] = arrayForBets[0] * 2;
        cout << "You won $" << arrayForBets[0] << endl;
        playerTwoEarnings += arrayForBets[0];
        //cout << "Player Two your earnings are $" << playerTwoEarnings << endl;
    }else if (playerTwoTotal < dealerTotal && (dealerTotal <= 21)){
        cout << "Player Two your total was: " << playerTwoTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "The dealer wins!" << endl;
        cout << "The dealer won $" << arrayForBets[1] << endl;
        playerTwoEarnings -= arrayForBets[1];
        cout << "Player Two you lost $" << playerTwoEarnings << endl;
        dealerWinnings += arrayForBets[1];
    }else if (playerTwoTotal == dealerTotal){
        cout << "The dealer and player Two have the same values" << endl;
        cout << "Neither Player Two or the dealer wins anything" << endl;
    }else if (playerTwoTotal > 21 && dealerTotal <= 21){
        cout << "Player Two your total was: " << playerTwoTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "The dealer won!" << endl;
        cout << "The dealer won $" << arrayForBets[1] << endl;
        playerTwoEarnings -= arrayForBets[1];
        cout << "Player Two you lost $" << playerTwoEarnings << endl;
        dealerWinnings += arrayForBets[1];
    }else{
        cout << "Player Two's total was: " << playerTwoTotal << endl;
        cout << "The Dealers total was: " << dealerTotal << endl;
        cout << "The dealer won!" << endl;
        cout << "The dealer won $" << arrayForBets[1] << endl;
        dealerWinnings += arrayForBets[1];
        playerTwoEarnings -= arrayForBets[1];
        cout << "Player Two you lost $" << playerTwoEarnings << endl;
    }
    
}//End of determineWinnerTwo Function


//This function will play only if the player surroundered in the round.
void playerOneSurrendered(int *arrayForBets, int players, int &playerOneEarnings, int &dealerWinnings){
    
    cout << "Player One you choose to surrender!" << endl;
    cout << "You now have " << arrayForBets[0] << endl;
    playerOneEarnings -= arrayForBets[0];
    cout << "Player one your total earnings are $" << playerOneEarnings << endl;
    dealerWinnings += playerOneEarnings;
    cout << "The dealer won " << dealerWinnings << endl;
    
}//End of playerOneSurrendered function

//This function will play only if the player surroundered in the round.
void playerTwoSurredndered(int *arrayForBets, int players, int &playerTwoEarnings,int &dealerWinnings){
    
        cout << "Player Two you choose to surrender!" << endl;
        cout << "You now have " << arrayForBets[1] << endl;
        playerTwoEarnings -= arrayForBets[1];
        cout << "Player Two your total earnings are $" << playerTwoEarnings << endl;
        dealerWinnings += playerTwoEarnings;
        cout << "The dealer won " << dealerWinnings << endl;

}//End of playerTwoSurrendered function

void clearScreen(){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

//Clears the screen
//void clrscrn()
//
//{
//    cout << "\033[2J\033[1;1H";
//}

//This is the main menu function.
void mainMenu(){
    
    int choice;
    
    cout << "Welcome to the Main Menu" << endl;
    cout << "1. Instructions" << endl;
    cout << "2. Play Game (You will Lose)" << endl;
    cout << "What is you choice?" << endl;
    cin >> choice;
    while ((choice < 1) || (choice > 2)){
        cout << "That value is not allowed. Please enter 1 or 2" << endl;
        cin >> choice;
    }
    if (choice == 1){
        clearScreen();
        instructions();
    }
    else if  (choice == 2){
        cout << "Game Starting!" << endl;
    }


}//End of mainMenu function

//Instructions function
void instructions(){
    
    clearScreen();
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "*****             Instructions on how to play        *****" << endl;
    cout << "##########################################################" << endl;
    cout << "*****          Aces may be worth 1 or 11 points      *****" << endl;
    cout << "*****           Face cards are worth 10 point        *****" << endl;
    cout << "**** All other cards are worth the number on the card ****" << endl;
    cout << "##########################################################" << endl;
    cout << "*****     The basic goal of the game is to get to 21 *****" << endl;
    cout << "*****    If the player gets to 21, the player wins   *****" << endl;
    cout << "*****     If the dealer gets 21, the dealer wins *****" << endl;
    cout << "*****    If the player and the dealer are both over 21, the dealer wins *****" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    

}//End of instructions function




//**************************************
//Validation functions below this point-In this program, I user both validation functions and a validation loop
//to ensure that the data that is coming in is accurate.
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










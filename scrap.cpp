//The code in here is all code that I was using at one point in my program but then realized that I may not need it.
//I place it in here in case I do need it again.


//CHECKING FOR AN ACE 

//        if (deck[cardLocation].valueTwo == 11){
//            cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
//            cin >> aceValue;
//            deck[cardLocation].valueOne = aceValue;
//        }

//        if (deck[cardLocation].valueTwo == 11){
//            cout << "You have an ace, what do you want it to equal 1 or 11?" << endl;
//            cin >> aceValue;
//            deck[cardLocation].valueOne = aceValue;
//        }

//END OF CHECKING FOR AN ACE



if (players == 1){
   playerOneEarnings += arrayForBets[0];
   cout << "Player one your total earnings are $" << playerOneEarnings << endl;
}


//This will automatically end the program if the last card is reached. THIS FUNCTION MAY
//NOT BEEN NEEDED BECAUSE THE PROGRAM ALWAYS RESHUFFLES THE CARD DECK AND CARD LOCATION TO
//ZERO THROUGH EVERY ROUND.
again = cardCheck(cardLocation, DECKSIZE, again);


if (players == 2 && SurrenderOne == false && SurrenderTwo == false){
  if ((playerOneTotal > dealerTotal) && (playerOneTotal <= 21)){
      cout << "Player One's total was: " << playerOneTotal << endl;
      cout << "Player Two's total was: " << playerTwoTotal << endl;
      cout << "The Dealers total was: " << dealerTotal << endl;
      cout << "Player one Wins!" << endl;
      arrayForBets[0] = arrayForBets[0] * 2;
      cout << "You won $" << arrayForBets[0] << endl;
      playerOneEarnings += arrayForBets[0];
      cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//                arrayForBets[1] -= arrayForBets[1];
//                cout << "Player two you lost $" << arrayForBets[1] << endl;
  }else if ((dealerTotal > playerOneTotal)   ){
  
  }

}

cout << "1. Hit" << endl;
cout << "2. Stand" << endl;
cout << "3. Double Down" << endl;
cout << "4. Surrender" << endl;
cout << "Player one, what is your action: " << endl;
cin >> action;

cout << endl;
cout << "Player One your total is: " << playerOneTotal << endl;
cout << "Player one, what is your action: " << endl;

void determineWinnerOne(int, int, int *, int, int &, int &);

determineWinnerOne(playerOneTotal, dealerTotal, arrayForBets, players, dealerWinnings, playerOneEarnings);

void determineWinnerOne(int playerOneTotal, int dealerTotal, int *arrayForBets, int players, int &dealerWinnings, int &playerOneEarnings){

void determineWinnerTwo(int, int, int *, int, int &, int &);

void determineWinnerTwo(int playerTwoTotal, int dealerTotal, int *arrayForBets, int players, int &dealerWinnings, int &playerTwoEarnings){
  cout << endl;
  if (playerTwoTotal == 21){
      cout << "Player Two your total was: " << playerTwoTotal << endl;
      cout << "The Dealers total was: " << dealerTotal << endl;
      cout << "Player Two Wins!" << endl;
      arrayForBets[1] = arrayForBets[1] * 2;
      cout << "You won $" << arrayForBets[1] << endl;
      playerTwoEarnings += arrayForBets[1];
      cout << "Player two your total earnings are $" << playerTwoEarnings << endl;
  }else if (playerTwoTotal > 21 && dealerTotal > 21){
      cout << "BUST" << endl;
      cout << "Dealer wins!" << endl;
      cout << "The dealer won $" << arrayForBets[1] << endl;
      playerTwoEarnings -= arrayForBets[1];
      cout << "Player one your total earnings are $" << playerTwoEarnings << endl;
      dealerWinnings += arrayForBets[1];
  }else if((playerTwoTotal > dealerTotal) && (playerTwoTotal <= 21)){
      cout << "Player Two your total was: " << playerTwoTotal << endl;
      cout << "The Dealers total was: " << dealerTotal << endl;
      cout << "Player Two Wins!" << endl;
      arrayForBets[1] = arrayForBets[1] * 2;
      cout << "You won $" << arrayForBets[1] << endl;
      playerTwoEarnings += arrayForBets[1];
      cout << "Player two your total earnings are $" << playerTwoEarnings << endl;
  }else if (playerTwoTotal < dealerTotal && (dealerTotal > 21)){
      cout << "Player Two your total was: " << playerTwoTotal << endl;
      cout << "The Dealers total was: " << dealerTotal << endl;
      cout << "Player Two Wins!" << endl;
      arrayForBets[0] = arrayForBets[0] * 2;
      cout << "You won $" << arrayForBets[0] << endl;
      playerTwoEarnings += arrayForBets[0];
      cout << "Player one your total earnings are $" << playerTwoEarnings << endl;
  }else if (playerTwoTotal < dealerTotal && (dealerTotal <= 21)){
      cout << "Player Two your total was: " << playerOneTotal << endl;
      cout << "The Dealers total was: " << dealerTotal << endl;
      cout << "The dealer wins!" << endl;
      cout << "The dealer won $" << arrayForBets[1] << endl;
      playerTwoEarnings -= arrayForBets[1];
      cout << "Player two your total earnings are $" << playerTwoEarnings << endl;
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
      cout << "Player Two your total earnings are $" << playerTwoEarnings << endl;
      dealerWinnings += arrayForBets[1];
  }else{
      cout << "Player Two's total was: " << playerTwoTotal << endl;
      cout << "The Dealers total was: " << dealerTotal << endl;
      cout << "The dealer won!" << endl;
      cout << "The dealer won $" << arrayForBets[1] << endl;
      dealerWinnings += arrayForBets[1];
      playerTwoEarnings -= arrayForBets[1];
      cout << "Player Two your total earnings are $" << playerTwoEarnings << endl;
      }
}



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


    //This function will be the actual game function
    //game(players, deck, DECKSIZE); NOT USING AS OF NOW




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

///// ACE CARDS FOR TESTING  ///////

            deck[0].valueOne = 1;
            deck[0].valueTwo = 11;
            deck[0].suite = "Spade";
            deck[0].face = "ACE ";

            deck[1].valueOne = 1;
            deck[1].valueTwo = 11;
            deck[1].suite = "Spade";
            deck[1].face = "ACE ";

            deck[2].valueOne = 1;
            deck[2].valueTwo = 11;
            deck[2].suite = "Spade";
            deck[2].face = "ACE ";

            deck[3].valueOne = 1;
            deck[3].valueTwo = 11;
            deck[3].suite = "Spade";
            deck[3].face = "ACE ";

            deck[4].valueOne = 1;
            deck[4].valueTwo = 11;
            deck[4].suite = "Spade";
            deck[4].face = "ACE ";

            deck[5].valueOne = 1;
            deck[5].valueTwo = 11;
            deck[5].suite = "Spade";
            deck[5].face = "ACE ";

            deck[6].valueOne = 1;
            deck[6].valueTwo = 11;
            deck[6].suite = "Spade";
            deck[6].face = "ACE ";

            deck[7].valueOne = 1;
            deck[7].valueTwo = 11;
            deck[7].suite = "Spade";
            deck[7].face = "ACE ";

            deck[8].valueOne = 1;
            deck[8].valueTwo = 11;
            deck[8].suite = "Spade";
            deck[8].face = "ACE ";

            deck[9].valueOne = 1;
            deck[9].valueTwo = 11;
            deck[9].suite = "Spade";
            deck[9].face = "ACE ";

            deck[10].valueOne = 1;
            deck[10].valueTwo = 11;
            deck[10].suite = "Spade";
            deck[10].face = "ACE ";

            deck[11].valueOne = 1;
            deck[11].valueTwo = 11;
            deck[11].suite = "Spade";
            deck[11].face = "ACE ";

            deck[12].valueOne = 1;
            deck[12].valueTwo = 11;
            deck[12].suite = "Spade";
            deck[12].face = "ACE ";


//Test for 21 

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
            deck[1].valueOne = 1;
            deck[1].valueTwo = 11;
            deck[1].suite = "Spade";
            deck[1].face = "ACE ";
            deck[2].valueOne = 1;
            deck[2].valueTwo = 11;
            deck[2].suite = "Spade";
            deck[2].face = "ACE ";
            deck[3].valueOne = 1;
            deck[3].valueTwo = 11;
            deck[3].suite = "Spade";
            deck[3].face = "ACE ";
            deck[4].valueOne = 1;
            deck[4].valueTwo = 11;
            deck[4].suite = "Spade";
            deck[4].face = "ACE ";
            deck[5].valueOne = 1;
            deck[5].valueTwo = 11;
            deck[5].suite = "Spade";
            deck[5].face = "ACE ";
            deck[6].valueOne = 1;
            deck[6].valueTwo = 11;
            deck[6].suite = "Spade";
            deck[6].face = "ACE ";
            deck[7].valueOne = 1;
            deck[7].valueTwo = 11;
            deck[7].suite = "Spade";
            deck[7].face = "ACE ";
            deck[8].valueOne = 1;
            deck[8].valueTwo = 11;
            deck[8].suite = "Spade";
            deck[8].face = "ACE ";
            deck[9].valueOne = 1;
            deck[9].valueTwo = 11;
            deck[9].suite = "Spade";
            deck[9].face = "ACE ";
            deck[10].valueOne = 1;
            deck[10].valueTwo = 11;
            deck[10].suite = "Spade";
            deck[10].face = "ACE ";
            deck[11].valueOne = 1;
            deck[11].valueTwo = 11;
            deck[11].suite = "Spade";
            deck[11].face = "ACE ";
            deck[12].valueOne = 1;
            deck[12].valueTwo = 11;
            deck[12].suite = "Spade";
            deck[12].face = "ACE ";
            
            deck[13].valueOne = 1;
            deck[13].valueTwo = 11;
            deck[13].suite = "Clubs";
            deck[13].face = "ACE ";
            deck[14].valueOne = 10;
            deck[14].valueTwo = 10;
            deck[14].suite = "Clubs";
            deck[14].face = "";
            deck[15].valueOne = 10;
            deck[15].valueTwo = 3;
            deck[15].suite = "Clubs";
            deck[15].face = "";
            deck[16].valueOne = 10;
            deck[16].valueTwo = 10;
            deck[16].suite = "Clubs";
            deck[16].face = "";
            deck[17].valueOne = 10;
            deck[17].valueTwo = 10;
            deck[17].suite = "Clubs";
            deck[17].face = "";
            deck[18].valueOne = 10;
            deck[18].valueTwo = 10;
            deck[18].suite = "Clubs";
            deck[18].face = "";
            deck[19].valueOne = 10;
            deck[19].valueTwo = 10;
            deck[19].suite = "Clubs";
            deck[19].face = "";
            deck[20].valueOne = 10;
            deck[20].valueTwo = 8;
            deck[20].suite = "Clubs";
            deck[20].face = "";
            deck[21].valueOne = 10;
            deck[21].valueTwo = 10;
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
            deck[27].valueOne = 10;
            deck[27].valueTwo = 10;
            deck[27].suite = "Diamonds";
            deck[27].face = "";
            deck[28].valueOne = 10;
            deck[28].valueTwo = 10;
            deck[28].suite = "Diamonds";
            deck[28].face = "";
            deck[29].valueOne = 10;
            deck[29].valueTwo = 10;
            deck[29].suite = "Diamonds";
            deck[29].face = "";
            deck[30].valueOne = 10;
            deck[30].valueTwo = 10;
            deck[30].suite = "Diamonds";
            deck[30].face = "";
            deck[31].valueOne = 10;
            deck[31].valueTwo = 10;
            deck[31].suite = "Diamonds";
            deck[31].face = "";
            deck[32].valueOne = 10;
            deck[32].valueTwo = 10;
            deck[32].suite = "Diamonds";
            deck[32].face = "";
            deck[33].valueOne = 10;
            deck[33].valueTwo = 10;
            deck[33].suite = "Diamonds";
            deck[33].face = "";
            deck[34].valueOne = 10;
            deck[34].valueTwo = 10;
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
            
            deck[39].valueOne = 1;
            deck[39].valueTwo = 11;
            deck[39].suite = "Hearts";
            deck[39].face = "ACE ";
            deck[40].valueOne = 10;
            deck[40].valueTwo = 10;
            deck[40].suite = "Hearts";
            deck[40].face = "";
            deck[41].valueOne = 10;
            deck[41].valueTwo = 10;
            deck[41].suite = "Hearts";
            deck[41].face = "";
            deck[42].valueOne = 10;
            deck[42].valueTwo = 10;
            deck[42].suite = "Hearts";
            deck[42].face = "";
            deck[43].valueOne = 10;
            deck[43].valueTwo = 10;
            deck[43].suite = "Hearts";
            deck[43].face = "";
            deck[44].valueOne = 10;
            deck[44].valueTwo = 10;
            deck[44].suite = "Hearts";
            deck[44].face = "";
            deck[45].valueOne = 10;
            deck[45].valueTwo = 10;
            deck[45].suite = "Hearts";
            deck[45].face = "";
            deck[46].valueOne = 10;
            deck[46].valueTwo = 10;
            deck[46].suite = "Hearts";
            deck[46].face = "";
            deck[47].valueOne = 10;
            deck[47].valueTwo = 10;
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






































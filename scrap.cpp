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









































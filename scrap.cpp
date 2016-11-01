//The code in here is all code that I was using at one point in my program but then realized that I may not need it.
//I place it in here in case I do need it again.

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









































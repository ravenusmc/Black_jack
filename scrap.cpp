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
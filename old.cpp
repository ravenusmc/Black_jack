//This is the old version of my blackjack determine winner code before I changed it:

        //Writing the function for the below if then statement.
        if (SurrenderOne == false){
            determineWinnerOne(playerOneTotal, dealerTotal, arrayForBets, players, dealerWinnings, playerOneEarnings);
//            if (playerOneTotal == 21){
//                cout << "Player One your total was: " << playerOneTotal << endl;
//                cout << "The Dealers total was: " << dealerTotal << endl;
//                cout << "Player one Wins!" << endl;
//                arrayForBets[0] = arrayForBets[0] * 2;
//                cout << "You won $" << arrayForBets[0] << endl;
//                playerOneEarnings += arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//            }else if (playerOneTotal > 21 && dealerTotal > 21){
//                cout << "BUST" << endl;
//                cout << "Dealer wins!" << endl;
//                cout << "The dealer won $" << arrayForBets[0] << endl;
//                playerOneEarnings -= arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//                dealerWinnings += arrayForBets[0];
//            }else if ((playerOneTotal > dealerTotal) && (playerOneTotal <= 21)){
//                cout << "Player One your total was: " << playerOneTotal << endl;
//                cout << "The Dealers total was: " << dealerTotal << endl;
//                cout << "Player one Wins!" << endl;
//                arrayForBets[0] = arrayForBets[0] * 2;
//                cout << "You won $" << arrayForBets[0] << endl;
//                playerOneEarnings += arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//            }else if (playerOneTotal < dealerTotal && (dealerTotal > 21)){
//                cout << "Player One your total was: " << playerOneTotal << endl;
//                cout << "The Dealers total was: " << dealerTotal << endl;
//                cout << "Player one Wins!" << endl;
//                arrayForBets[0] = arrayForBets[0] * 2;
//                cout << "You won $" << arrayForBets[0] << endl;
//                playerOneEarnings += arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//            }else if (playerOneTotal < dealerTotal && (dealerTotal <= 21)){
//                cout << "Player One your total was: " << playerOneTotal << endl;
//                cout << "The Dealers total was: " << dealerTotal << endl;
//                cout << "The dealer wins!" << endl;
//                cout << "The dealer won $" << arrayForBets[0] << endl;
//                playerOneEarnings -= arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//                dealerWinnings += arrayForBets[0];
//            }else if (playerOneTotal == dealerTotal){
//                cout << "The dealer and player have the same values" << endl;
//                cout << "The game is a tie and no one wins anything" << endl;
//            }else if (playerOneTotal > 21 && dealerTotal <= 21){
//                cout << "Player One your total was: " << playerOneTotal << endl;
//                cout << "The Dealers total was: " << dealerTotal << endl;
//                cout << "The dealer won!" << endl;
//                cout << "The dealer won $" << arrayForBets[0] << endl;
//                playerOneEarnings -= arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//                dealerWinnings += arrayForBets[0];
//            }else{
//                cout << "Player One your total was: " << playerOneTotal << endl;
//                cout << "The Dealers total was: " << dealerTotal << endl;
//                cout << "The dealer won!" << endl;
//                cout << "The dealer won $" << arrayForBets[0] << endl;
//                dealerWinnings += arrayForBets[0];
//                playerOneEarnings -= arrayForBets[0];
//                cout << "Player one your total earnings are $" << playerOneEarnings << endl;
//            }
          }else if (SurrenderOne == true){
            cout << "Player One you choose to surrender!" << endl;
            cout << "You now have " << arrayForBets[0] << endl;
            playerOneEarnings -= arrayForBets[0];
            cout << "Player one your total earnings are $" << playerOneEarnings << endl;
            
        }
        
        if(SurrenderTwo == false && players == 2){
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
        else if (SurrenderTwo == true){
                cout << "Player Two you choose to surrender!" << endl;
                cout << "You now have " << arrayForBets[1] << endl;
                playerTwoEarnings -= arrayForBets[1];
                cout << "Player Two your total earnings are $" << playerTwoEarnings << endl;
            
        }
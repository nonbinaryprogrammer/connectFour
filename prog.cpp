#include"./game.h"

int main(int argc, char **argv) {
   int n, m, p, col;
   game b;

   //gets the inputs from argv
   	//if they're wrong than it gets good ones form the user
   getn(argc, argv, n, m, p);
   getm(argc, argv, m, n, p);
   getp(argc, argv, p, n, m);

   //makes the board
   b.p1_board = new char*[n];
   for(int i = 0; i < n; i++)
      b.p1_board[i] = new char[m];

   //initializes the board
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
	 b.p1_board[i][j] = '0';
   }

   //gets the p1 colour
   cout << "Player 1, what colour do you want to play with? (red-r, or yellow-y): ";
   cin >> b.p1;

   //assigns p1 and p2 their colours
   if(b.p1 == 'r')
      b.p2 = 'y';
   else if (b.p1 == 'y')
      b.p2 = 'r';

   do {

      //asks the uer if they want to cont
      if(!cturn())
	 return 0;

      //start p1's turn
      cout << "Player 1's turn!" << endl;
      //prints out the board
      printboard(b.p1_board, n, m);
      //does the turn
      turn(b, 1, col, n, m);
      //checks to see if anyone won
      if(win(b, n, m, p))
	 break;

      //asks the user if they want to continue
      if(!cturn())
	 return 0;

      //start p2's turn
      cout << "Player 2's turn!" << endl;
      //prints board
      printboard(b.p1_board, n, m);
      //does the turn
      turn(b, 2, col, n, m);

   }while(!win(b, n, m, p));

   return 0;
}

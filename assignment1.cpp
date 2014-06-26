#include"./game.h"

void getvalidn(int &n) {

   do {
      cout << "Please enter a valid number of rows: ";
      cin >> n;
   }while(n <= 0);

}

void getvalidm(int &m) {

   do {
      cout << "Please enter a valid number of columns: ";
      cin >> m;
   }while(m <= 0);

}

void getvalidp(int &p) {

   do {
      cout << "Please enter a valid number of pieces to connect: ";
      cin >> p;
   }while(p <= 1);

}

void printboard(char **board, int n, int m) {

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
	 cout << board[i][j] << "  ";
      cout << endl;
   }

}

int checkcol(game b, int col, int n) {

   //checks for the lowest rows that contains 0 and returns it
   for(int i = (n-1); i >= 0; i--) {
      if(b.p1_board[i][col] == '0') {
	 return i;
      }
   }

}

void placepiece(game b, int player, int col, int n, int m) {
   int row;

   //gets the lowest empty row to put a piece in
   row = checkcol(b, col, n);
   //puts the p1 character in the lowest row
   if(player == 1) {
      b.p1_board[row][col] = b.p1;
   }
   //puts the p2 character in the lowest row if it's p2's turn
   else if(player == 2) {
      b.p1_board[row][col] = b.p2;
   }

}

void getn(int argc, char *argv[], int &n, int m, int p) {
   bool b = 0;

   //gets the number of rows out of argv
   for(int i = 1; i < argc; i++) {
      //looks for where -rows occurs
      if((argv[i][0] == '-') && (argv[i][1] == 'r') && (argv[i][2] == 'o') && (argv[i][3] == 'w') && (argv[i][4] == 's')) {
	 if(!((argv[i+1][0] >= 49) && (argv[i+1][0] <= 57))) {
	    getvalidn(n);
	    b = 0;
	 }
	 else {
	    n = atoi(argv[i+1]);
	    b = 0;
	 }
	 return;
      }
      else
	 b = 1;
   }
   //if there wasn't a valid value entered then gets a good one
   if(b) {
      getvalidn(n);
      return;
   }

}

void getm(int argc, char *argv[], int &m, int n, int p) {
   bool b = 0;

   for(int i = 1; i < argc; i++) {
      if((argv[i][0] == '-') && (argv[i][1] == 'c') && (argv[i][2] == 'o') && (argv[i][3] == 'l') && (argv[i][4] == 's')) {
	 if(!((argv[i+1][0] >= 49) && (argv[i+1][0] <= 57))) {
	    getvalidm(m);
	    b = 0;
	 }
	 else {
	    m = atoi(argv[i+1]);
	    b = 0;
	 }
	 return;
      }
      else
	 b = 1;
   }
   if(b) {
      getvalidm(m);
      return;
   }

}

void getp(int argc, char *argv[], int &p, int m, int n) {
   bool b = 0;

   for(int i = 1; i < argc; i++) {
      if((argv[i][0] == '-') && (argv[i][1] == 'p')) {
	 if(!((argv[i+1][0] >= 49) && (argv[i+1][0] <= 57))) {
	    getvalidp(p);
	    b = 0;
	 }
	 else {
	    p = atoi(argv[i+1]);
	    b = 0;
	 }
	 return;
      }
      else
	 b = 1;
   }
   if(b) {
      getvalidp(p);
      return;
   }

}

bool horizontal(game b, int n, int m, int p) {
   int win = 0;

   //horizontal check
   //checks for places in range where there are pieces placed
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < (m-(p-1)); j++) {
	 if(b.p1_board[i][j] != '0') {
	    //when it finds one that's not 0, checks for p consecutive pieces
	    //in the direction of the check
	    for(int t = 0; t < p; t++) {
	       if(b.p1_board[i][j+t] == b.p1_board[i][j]) {
		  win += 1;
	       }
	       else {
		  win = 0;
		  break;
	       }
	    }
	    if(win == p) {
	       //checks who won
		  printboard(b.p1_board, n, m);
	       if(b.p1_board[i][j] == b.p1) {
		  cout << "Player 1 has won the game!" << endl;
	       }
	       else if(b.p1_board[i][j] == b.p2) {
		  cout << "Player 2 has won the game!" << endl;
	       }
	       return 1;
	    }
	    else {
	       win = 0;
	    }
	 }
      }
   }

   return 0;
}

bool vertical(game b, int n, int m, int p) {
   int win = 0;

   //vertical check
   for(int i = 0; i < (n-(p-1)); i++) {
      for(int j = 0; j < m; j++) {
	 if(b.p1_board[i][j] != '0') {
	    for(int t = 0; t < p; t++) {
	       if(b.p1_board[i+t][j] == b.p1_board[i][j]) {
		  win += 1;
		  cout << win << endl;
	       }
	       else {
		  win = 0;
		  break;
	       }
	    }
	    if(win == p) {
		  printboard(b.p1_board, n, m);
	       if(b.p1_board[i][j] == b.p1) {
		  cout << "Player 1 has won the game!" << endl;
	       }
	       else if(b.p1_board[i][j] == b.p2) {
		  cout << "Player 2 has won the game!" << endl;
	       }
	       return 1;
	    }
	    else {
	       win = 0;
	    }
	 }
      }
   }

   return 0;
}

bool downright(game b, int n, int m, int p) {
   int win = 0;

   //diagonal down check
   for(int i = 0; i < (n-(p-1)); i++) {
      for(int j = 0; j < (m-(p-1)); j++) {
	 if(b.p1_board[i][j] != '0') {
	    for(int t = 0; t < p; t++) {
	       if(b.p1_board[i+t][j+t] == b.p1_board[i][j]) {
		  win += 1;
	       }
	       else {
		  win = 0;
		  break;
	       }
	    }
	    if(win == p) {
	       printboard(b.p1_board, n, m);
	       if(b.p1_board[i][j] == b.p1) {
		  cout << "Player 1 has won the game!" << endl;
	       }
	       else if(b.p1_board[i][j] == b.p2) {
		  cout << "Player 2 has won the game!" << endl;
	       }
	       return 1;
	    }
	    else {
	       win = 0;
	    }
	 }
      }
   }

   return 0;
}

bool upright(game b, int n, int m, int p) {
   int win = 0;

   //diagonal up check
   for(int i = (n-1); i > 0; i--) {
     for(int j = ((m-1)-(p-1)); j > 0; j--) {
       if(b.p1_board[i][j] != '0') {
	  for(int t = 0; t < p; t++) {
	     if(b.p1_board[i-t][j+t] == b.p1_board[i][j]) {
		win += 1;
	     }
	     else {
		win = 0;
		break;
	     }
	  }
	  if(win == p) {
	     printboard(b.p1_board, n, m);
	     if(b.p1_board[i][j] == b.p1) {
		cout << "Player 1 has won the game!" << endl;
		return 1;
	     }
	     else if(b.p1_board[i][j] == b.p2) {
		cout << "Player 2 has won the game!" << endl;
		return 1;
	     }
	  }
       }
     }
   }

   return 0;
}

bool win(game b, int n, int m, int p) {

   //runs all of the directional checks
   //if any of them won, then a 1 is returned to end the game
   if(horizontal(b, n, m, p) || vertical(b, n, m, p) || downright(b, n, m, p) || upright(b, n, m, p))
      return 1;

   else
      return 0;

}

void turn(game b, int player, int &col, int n, int m) {

   //keeps getting a col until one in range is entered
   do {
      cout << "Which column do you want to place a piece in?: ";
      cin >> col;
   }while((col < 0) && (col >= m));

   //places the piece in the row
   placepiece(b, player,col, n, m);

}

bool cturn() {
   bool cont;

   cout << "Do you want to continue playing? (enter a 0 to quit) : ";
   cin >> cont;

   return cont;

}


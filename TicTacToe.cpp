#include<iostream>
using namespace std;

class tictactoe
{
  //This works for only 3 x 3 tictactoe board
  //Array Size to store values for 3 x 3 tictactoe board
  static const int size = 9;
  
  //Symbols used for players
  static const char p1Symbol = 'X';
  static const char p2Symbol = 'O';
  
  //Internal to the class to check for the winner
  static const char noWinners = 'N';

  char cSquare[size];
  int movesMade;
  bool bGameOver;
  
  //Function to check the winner  
  char checkWinner();

  //Function to print the board
  void printBoard();
  
  //Reset the Board
  void clearBoard();
  
  //Check if players want to continue the game
  bool isContinuePlay(); 

  public:
  //Constructor
  tictactoe()
  {
    clearBoard();
  }
  
  //Play TicTacToe Game
  void playGame();

};


char tictactoe::checkWinner()
{
  if(cSquare[0] != '1')
  {
    if(cSquare[0] == cSquare[1] && cSquare[1] == cSquare[2])
      return cSquare[0];

    if(cSquare[0] == cSquare[3] && cSquare[3] == cSquare[6])
      return cSquare[0];

    if(cSquare[0] == cSquare[4] && cSquare[4] == cSquare[8])
      return cSquare[0];
     
  }
    
  if(cSquare[4] != '5')
  {
    if(cSquare[3] == cSquare[4] && cSquare[4] == cSquare[5])
      return cSquare[4];

    if(cSquare[1] == cSquare[4] && cSquare[4] == cSquare[7])
      return cSquare[4];

    if(cSquare[2] == cSquare[4] && cSquare[4] == cSquare[6])
      return cSquare[4];
  }

  if(cSquare[8] != '9')
  {
    if(cSquare[6] == cSquare[7] && cSquare[7] == cSquare[8])
      return cSquare[8];

    if(cSquare[2] == cSquare[5] && cSquare[5] == cSquare[8])
      return cSquare[8];
  }

  return noWinners;
}


void tictactoe::printBoard()
{
  cout << "||" << cSquare[0] << "||" << cSquare[1] << "||" << cSquare[2] << "||" << endl;
  cout << "||" << cSquare[3] << "||" << cSquare[4] << "||" << cSquare[5] << "||" << endl;
  cout << "||" << cSquare[6] << "||" << cSquare[7] << "||" << cSquare[8] << "||" << endl;
}


void tictactoe::clearBoard()
{
  movesMade = 0;
  bGameOver = false;

  cSquare[0] = '1';
  cSquare[1] = '2';
  cSquare[2] = '3';
  cSquare[3] = '4';
  cSquare[4] = '5';
  cSquare[5] = '6';
  cSquare[6] = '7';
  cSquare[7] = '8';
  cSquare[8] = '9';
}


bool tictactoe::isContinuePlay()
{
  std::cout << endl << "Play again (y/n)?" << std::endl;
  char cPlayAgain;
  std::cin >> cPlayAgain;
  if (cPlayAgain == 'y' || cPlayAgain == 'Y')
  {
    clearBoard();
    printBoard();
    return true;
  }
  return false;
}

void tictactoe::playGame()
{
  int currMove,playerTurn = 1;
  bool bValidMove;
  printBoard();
  cout << "Player1 -> " << p1Symbol << endl << "Player2 -> " << p2Symbol << endl;
  cout << "Players select the box numbered between 1 and 9" << endl;

  //Begin the game
  do
  {
    cout << endl << "Player "<< playerTurn << " makes the selection --> ";
    cin >> currMove;
    bValidMove = false;
   
    //Get the Current Player Input
    //Check the validity of the input and set the board
    do
    {
      if(cin.fail())
      {
        cout << "INVALID SELECTION" << endl;
        cout << "Select the number between 1 and 9" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        break;
      }
      if((currMove < 0 || currMove > 9) &&
         (cSquare[currMove-1] == p1Symbol || cSquare[currMove-1] == p2Symbol))
      {
        cout << "INVALID SELECTION" << endl;
        cout << "Select the unused box numbered between 1 and 9" << endl;
        break;
      }
      
      //Set the valid move flag 
      bValidMove = true;

      //Set the Value in the board and Alternate the Players
      if(playerTurn == 1) 
      {
        cSquare[currMove-1] = p1Symbol;
        playerTurn = 2;
      }
      else
      {
        cSquare[currMove-1] = p2Symbol;
        playerTurn = 1;
      }
      //Increment the total moves made
      ++movesMade;
    }while(!bValidMove);
    
   
    //Print the Board
    printBoard();   
 
    //Check for the Winner
    char winner = checkWinner();
    if(winner != noWinners)
    {
      if(winner == p1Symbol)
        cout << "**** Player 1 Wins ****" << endl;
      else
        cout << "**** Player 2 Wins ****" << endl;

      if(!isContinuePlay())
        bGameOver = true;
    }
    else
    {
      //Check if the board is full
      if(movesMade == size)
      {
        cout << "**** Game Over -> No Winners ****" << endl;

        if(!isContinuePlay())
          bGameOver = true;
      }        
    }
    
  }while(!bGameOver);
    
}  


int main()
{
  tictactoe myBoard;
  myBoard.playGame();
  return 0;
}

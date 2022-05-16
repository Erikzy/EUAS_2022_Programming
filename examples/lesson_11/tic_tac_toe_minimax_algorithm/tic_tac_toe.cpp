// C++ tic-tac-toe using the Minimax algorithm
// Algorithm from> https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/


#include <iostream>
#include <stdlib.h>


using namespace std;
 
struct Move
{
    int row, col;
};
 
char ai_player = 'x', opponent = 'o';
 
// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}
 
// This is the evaluation function as discussed
// It examines the state of the board, and checks
// Whether either the player or the opponent have
int evaluate(char b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==ai_player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==ai_player)
                return +10;
 
            else if (b[0][col]==opponent)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==ai_player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==ai_player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}
 
void printBoard(char board[3][3], bool playerTurn){
    system ("clear");
    cout << " Tic-Tac-Toe - (Skynet simulator)  " << endl;
    cout << "  " << endl;
    cout << "  " << endl;


    if(playerTurn){
        cout << "      Player's Turn (o)  " << endl;
    }else{
        cout << "      Computer's Turn (x)                 " << endl; 
    }
    
    
    cout << "        0   1   2  " << endl; 
    cout << "      0 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "      1 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "      2 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "            " << endl;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);
 
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;
 
    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = ai_player;
 
                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMax) );
 
                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
 
    // If this minimizer's move
    else
    {
        int best = 1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = opponent;
 
                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax(board, depth+1, !isMax));
 
                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}
 
// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (board[i][j]=='_')
            {
                // Make the move
                board[i][j] = ai_player;
 
                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);
 
                // Undo the move
                board[i][j] = '_';
 
                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
 
    cout << "The value of the best Move is : " << bestVal;
    cout << "The Optimal Move is :" << endl;
    cout << "ROW:" << bestMove.row << " COL:" <<  bestMove.col << endl;
    return bestMove;
}

Move getPlayerMove()
{
    Move playerMove;
    int playerMoveRow, playerMoveCol;
    cout << "Please enter your move (row): " << endl;
    cin >> playerMove.row;
    cout << "Please enter your move (column): " << endl;
    cin >> playerMove.col;
    return playerMove;
}

void printGameOver(int state){
    cout << " GAME OVER " << endl;
    cout << "    " << endl;
    cout << "    " << endl; 
    if(state == -10){
        cout << "Player won!" << endl;
    } else {
        cout << "Computer won" << endl;
    }
}

bool gameOver(char board[3][3]){

    bool _gameOver;
    bool _isMovesLeft = isMovesLeft(board);
    int state = evaluate(board);

    _gameOver = !(_isMovesLeft && state == 0);
       
    if(_gameOver){
       printGameOver(state);
    }
    return _gameOver;
}


// Driver code
int main()
{
    char board[3][3] =
    {
        { '_', '_', '_' },
        { '_', '_', '_' },
        { '_', '_', '_' }
    };
    bool playerTurn = true;
    int state = 0;
    bool validPlayerMove = false; 
    bool _isMovesLeft;
    
    _isMovesLeft = true;

    while(!gameOver(board)){
        printBoard(board, playerTurn);       
        
        if(playerTurn){     
            validPlayerMove = false;

            do {
                Move playerMove = getPlayerMove(); 
                if(board[playerMove.row][playerMove.col] == '_'){
                    validPlayerMove = true;
                    board[playerMove.row][playerMove.col]  = 'o';
                } else {
                    cout << "Invalid Move" << endl;
                }
            } while (!validPlayerMove);
        
        } else {
            cout << "The computer is thinking.... Press any key to continue .." << endl;
            cin.ignore();
            cin.get();

            Move bestAiMove = findBestMove(board);                  
            board[bestAiMove.row][bestAiMove.col] = 'x';

            cout << "Press any key to continue .." << endl;
            cin.get();

        }
        playerTurn  = !playerTurn;
    }
    return 0;
}
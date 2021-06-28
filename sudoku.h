#define N 9

class Sudoku{

   private : 
      // vector< vector<int>> board(N, vector<int> (N,0));
      int board[N][N];
      int solved[N][N];
      bool isSolved;
   public :
      
      Sudoku(){
            memset(board, 0, sizeof(board));
            memset(solved, 0, sizeof(board));
            isSolved = false;
            isGenerated = false;
      }
      void printGraffiti();
      void generate();
      bool solve(int, int);
      bool check(int ,int ,int );
      void printB(int );
      void play();
      bool isEmpty();
      bool isGenerated;
};

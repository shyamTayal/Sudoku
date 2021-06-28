#include<bits/stdc++.h>
#include "sudoku.h"
using namespace std;

void Sudoku::generate(){      
      
      

      // Higher the K value , higher the difficulty
      // here [Difficulty : Easy]
      srand(time(0));


      int K = 45,x=1;
      cout<<"Enter Board Difficulty Level : \n";
      cout<<"1) Easy \t 2) Medium \t 3) Hard \t --> ";
      cin>>x;
      switch(x){
            case 1: K = 45; break;
            case 2: K = 55; break;
            case 3: K = 64; break;
      }
      isGenerated = solve(0,0);

      while(K--){
            int at = rand()%(N*N);
            int row = at/N, col = at%N;
            // cout<<row<<' '<<col<<'\n';
            if(board[row][col] == 0)
                  K++;
            else
                  board[row][col] = 0;
      }

      printB(0);

      
}

bool Sudoku::check(int row, int col, int c){

      // Check in the row
      for(int i=0;i<N;i++)
            if(board[row][i] == c) return false;

      // Check in the column
      for(int i=0;i<N;i++)
            if(board[i][col] == c) return false;

      // Check in the 3 X 3 Box 
      for(int i=0;i<N/3;i++)
            for(int j=0;j<N/3;j++)
                  if(board[row/3*3 + i][col/3*3 + j] == c)
                        return false;

      return true;
}

void Sudoku::printB(int t=0){

      cout<<"\nSudoku Board\n\n";
      for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                  if(board[i][j] != 0)
                        cout<<"  "<<board[i][j] << "  ";
                  else
                        cout<<"     ";

                  if((j+1)%3 == 0 && j!=8){
                        cout<<"||";
                  }
            }
            cout<<'\n';
            if((i+1)%3 == 0 && i!=8){
                  string p(48,'=');
                  cout<<p<<'\n';
            }
      }
      cout<<'\n';

      if(t == 1){
            cout<<"Board After Solving ...\n\n";
            string p(48,'=');
            for(int i=0;i<N;++i){
                  for(int j=0;j<N;++j){
                        if(solved[i][j] != 0)
                              cout<<"  "<<solved[i][j] << "  ";
                        else
                              cout<<"     ";

                        if((j+1)%3 == 0 && j!=8){
                              cout<<"||";
                        }
                  }
                  cout<<'\n';
                  if((i+1)%3 == 0 && i!=8){
                        cout<<p<<'\n';
                  }
            }
      }
      cout<<"\nPress ENTER to continue .....";
      
      cin.ignore();
      cin.get();
           
}


void Sudoku::printGraffiti(){
      
      cout<<"\t  _________ ____ ___ ________   ________    ____  __. ____ ___ \n";      
      cout<<"\t /   _____/|    |   \\\\______ \\  \\_____  \\  |    |/ _||    |   \\\n";     
      cout<<"\t \\_____  \\ |    |   / |    |  \\  /   |   \\ |      <  |    |   /\n";    
      cout<<"\t /        \\|    |  /  |    `   \\/    |    \\|    |  \\ |    |  / \n";   
      cout<<"\t/_______  /|______/  /_______  /\\_______  /|____|__ \\|______/  \n";
      cout<<"\t        \\/                   \\/         \\/         \\/           \n\n";
}

bool Sudoku::solve(int row, int col){

	if (row == N - 1 && col == N-1){
		isSolved=true;
		return true;
	}
		

	if (col == N-1) {
		row++;
		col = 0;
	}

	if (solved[row][col] > 0)
		return solve(row, col + 1);

	for (int num = 1; num <= N; num++)
	{
		if (check(row, col, num))
		{
			solved[row][col] = num;
                  board[row][col] = num;
			if (solve(row, col + 1))
				return true;
		}
		solved[row][col] = 0;
            board[row][col] = 0;
	}
	return false;
}


void Sudoku::play(){
      if(!isGenerated){
            generate();
      }
      solve(0,0);
      while(isEmpty()){

            system("CLS");
            printGraffiti();
            printB(0);

            int row=0,col=0,number=1;
            cout<<"Enter you Move or To exit input \'-1\' in all \n(row, column, number): ";
            cin>>row>>col>>number;
            if(row == -1 || col == -1 || number == -1)
                  break;
            if(row >= N || row < 0 || col >= N || col < 0 || number >N || number < 1){
                  cout<<"Invalid Move !!!!\n";
                  continue;
            } 
            if(solved[row][col] != number){
                  cout<<"Invalid Move !!!!\n";
                  continue;
            }
            board[row][col] = number;
      }
      if(isSolved){
            printB(1);
      }
}
bool Sudoku::isEmpty(){
      for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                  if(board[i][j] == 0)
                        return true;
            }
      }
      isSolved = true;
      return false;
}
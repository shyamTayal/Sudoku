#include<bits/stdc++.h>
#include "sudoku.h"
using namespace std;

void printOp(){                                                  
      cout<<"\nChoose an option :\n";
      cout<<"1) Generate a Board\n";
      cout<<"2) Auto Solve the Board\n";
      cout<<"3) Play Sudoku\n";
      cout<<"0) Exit\n";
      cout<<" --> ";
}

int main(){
      bool run = true;
      Sudoku sk;
      while(run){
            
            system("CLS");
            int ch=0;
            bool f = true;
            sk.printGraffiti();
            printOp();
            cin>>ch;
            switch(ch){
                  case 0: run = false; break;
                  case 1: sk.generate(); break;
                  case 2: 
                        if(!sk.isGenerated)
                              cout<<"Error 404 !!! Board not Found\n";
                              system("pause");
                        break;

                  case 3: sk.play(); 
                          break;
                  default: run = false;
            }
      }
      fflush(stdout);

      cout<<"\nGame Ended";
}
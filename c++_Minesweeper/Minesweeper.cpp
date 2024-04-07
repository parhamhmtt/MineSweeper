#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

const int row=10, column=10, bombcounts=10;
int matrix[10][10];
bool endGame=false;

struct coord
{ int row;
    int column;
    
};


void aroundCoordSearch(coord source){
    int aroundBombCounter=0;
    coord nextCoord;

    for(nextCoord.row=source.row-1; nextCoord.row<=source.row +1; nextCoord.row++){
        for(nextCoord.column=source.column -1; nextCoord.column<=source.column +1; nextCoord.column++){
            if(nextCoord.row<row && nextCoord.row>=0   &&  nextCoord.column<column && nextCoord.column>=0){
                if(matrix[nextCoord.row][nextCoord.column]== -1){
                    aroundBombCounter++;
                }
            }
        }
    }

    if(aroundBombCounter>0){
        matrix[source.row][source.column]=aroundBombCounter;
    }

    else{
        matrix[source.row][source.column]=0;
            
     for(nextCoord.row=source.row-1; nextCoord.row<=source.row +1; nextCoord.row++){
        for(nextCoord.column=source.column -1; nextCoord.column<=source.column +1; nextCoord.column++){
            if(nextCoord.row<row && nextCoord.row>=0   &&  nextCoord.column<column && nextCoord.column>=0){
                if(matrix[nextCoord.row][nextCoord.column]== -2){
                    aroundCoordSearch(nextCoord);
               }
            }
        }
    }
 }

}

void boardDisplay(){

    int askiCode=97;
    cout<< "     ";
    for (int i=0; i<10; i++){
        cout<<(char)askiCode<<"   ";
         askiCode++;
     }
    cout<<endl;

    
    
    for(int i=0; i<row; i++){

        cout<< "   +";
        for(int k=0; k<row; k++)
            cout<<"---+";

        cout<<endl;

        
            if(i+1==10)
            cout<<i+1<<" | ";
            else{
                cout<<" "<<i+1<<" | ";
            }
            for(int j=0; j<column; j++)
            switch (matrix[i][j]){
            
            case -1:
                if(endGame==true)
                    cout<<"#"<<" | ";
                     else
                    cout<<"."<<" | ";
                break;

            case 9:

              cout<<"#"<<" | ";
                break;
               
            
            case -2:
                cout<<"."<<" | ";
                break;
            
            case 0:
                cout<<" "<<" | ";
                break;
            
            default:

            cout<<matrix[i][j]<<" | ";
                break;
            }

            cout<<endl;

        }
        cout<< "   +";
        for(int k=0; k<row; k++)
            cout<<"---+";
    }
       




void randomBombFixer(){
    for(int i=0; i<=bombcounts; i++){
        int newRow=rand()%row;
        int newCol=rand()%column;
        matrix[newRow][newCol]=-1;
    }

}

void firstMatrixFixer(){
    for(int i=0; i<row; i++){
        for(int j=0; j< column; j++){
            matrix[i][j]=-2;
        }
    }
}

void checkTheGameEnd(){
    endGame=true;
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            if(matrix[i][j]==-2){
                endGame=false;
                break;
            }
          if(endGame==true){
          	system("cls");
          	cout<<endl<<"*******************YOU WON THE GAME*****************"<<endl;
          	boardDisplay();
          	cout<<endl;
          	
          	}

}
void reset(){
     firstMatrixFixer();
    randomBombFixer();
    boardDisplay();
}
int searchTheBombCounts(){
    int counter=0;
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            if(matrix[i][j]==-1)
                counter++;

                return counter;

}

int score(){
    int score=0;
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            if(matrix[i][j]>=0)
                score++;

 return score;
}

int main(){
    firstMatrixFixer();
    randomBombFixer();
    


    here:
    cout<<" Enter 1 to start , and 0 to exit : ";
     int start;
    cin>>start;

    switch (start){
    
    case 1:
        break;
    case 0:
        endGame=true;
        break;

    default:
        system("cls");
        goto here;

        break;
    }
    system("cls");
    boardDisplay();

    

 while (!endGame){
   
    
     cout<<endl<<"info Bombs: "<< searchTheBombCounts()<<endl;
     cout<<" Enetr 1 to Find Bomb and 2 to find blank : ";
     int a;
     cin>>a;
     cout<< "enter the coord row and column :";
         coord entry;
    cin>>entry.row>>entry.column;

    entry.row--;
    entry.column--;
    if(a==2){
    if(matrix[entry.row][ entry.column]!=-1){
        aroundCoordSearch(entry);
        checkTheGameEnd();
        system("cls");
        boardDisplay();
    }

    else{ system("cls");
        cout<<"*******************GAME OVER*****************"<<endl<<endl;
        endGame=true;
        boardDisplay();
        cout<<endl;
        

    
            
    }
        

    } 
    if(a==1){
        if(matrix[entry.row][ entry.column]==-1){
        //aroundCoordSearch(entry);
        matrix[entry.row][ entry.column]=9;
        checkTheGameEnd();
        system("cls");
        boardDisplay();
    }
    else{ system("cls");
        cout<<"*******************GAME OVER*****************"<<endl<<endl;
        endGame=true;
        boardDisplay();
        cout<<endl;
        

    
            
    }

    }  
    }
cout<<"Your score is : "<<score();
    
}
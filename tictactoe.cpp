#include<iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char Board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void Drawboard(){
    cout<<" "<<Board[0][0]<<" | "<<Board[0][1]<<" | "<<Board[0][2]<<"\n";
    cout<<"---|---|---\n";
    cout<<" "<<Board[1][0]<<" | "<<Board[1][1]<<" | "<<Board[1][2]<<"\n";
    cout<<"---|---|---\n";
    cout<<" "<<Board[2][0]<<" | "<<Board[2][1]<<" | "<<Board[2][2]<<"\n";
    


}
//For placing the marker
bool placeMarker(int slot){
    int row=(slot-1) / 3;
    int col=(slot-1) % 3;

    if (Board[row][col]!='X'&& Board[row][col]!='O'){
        Board[row][col]=currentMarker;
        return true;
    }
    
    return false;
    
}
//Determining the winner
int winner(){
    //checking for row
    for(int i=0;i<3;i++){
        if(Board[i][0]==Board[i][1]&& Board[i][1] == Board[i][2]){
        return currentPlayer;
    }
    }
    //checking for column
    for(int i=0;i<3;i++){
        if(Board[0][i]==Board[1][i]&&Board[1][i]==Board[2][i]){
        return currentPlayer;
    }
    }
    //checking for diagonals
    if(Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2]){
        return currentPlayer;
    }
    if(Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0]){
        return currentPlayer;
    }
    return 0;
}
//swapping the current player and current marker
void SwapPlayerandMarker(){
    if(currentMarker=='X'){
        currentMarker='O';
    }
    else{
        currentMarker='X';
    }
    if(currentPlayer==1){
        currentPlayer=2;
    }
    else{
        currentPlayer=1;
    }
}

void game(){
    char markerP1;
    cout<<"Player 1, choose your marker: (X or O):";
    cin>>markerP1;
    while(markerP1 !='X' && markerP1 !='O'){
      cout<<"Invalid marker.Please choose either 'X' or 'O':\n";       //if marker is not X or O
      cin>> markerP1;
    } 


currentPlayer=1;
currentMarker=markerP1;
Drawboard();

int playerwon;
int slot;
for(int i=0;i<9;i++){
    cout<<"It's Player "<<currentPlayer<<"'s turn Enter your slot:";
    
    cin>>slot;


if(slot<1||slot>9){
    cout<<"Invalid slot,Please try again:\n";
    i--;
    continue;
}

if(!placeMarker(slot)){                                    //checking if place is vacant or occupied
    cout<<"Sorry slot is occupied,Try again\n";
    i--;
    continue;
}

Drawboard();                              // Displaying board after every move
playerwon=winner();                       // checking who won after each move


if(playerwon == 1){
    cout<<"Congratulations,Player 1 wins!\n";
    return ;
}
if(playerwon==2){
    cout<<"Congratulations,Player 2 wins!\n";
    return;
}
SwapPlayerandMarker();                    //swapping player and marker after each move

}

if(playerwon==0){                        //if no one wins
    cout<<"Its a Tie";
}

}

int main(){
    cout<<"Welcome to tic-tac-toe game\n";
    game();
    return 0;
}





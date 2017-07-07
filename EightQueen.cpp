#include<iostream>
using namespace std;
bool check(int row,int col,int board[8][8]){
    for(int i=0;i<row;i++){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=0;i<col;i++){
        if(board[row][i]==1){
            return false;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==1 && j-i==col-row){
                return false;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=col+1;j<8;j++){
            if(board[i][j]==1 && j+i == col+row){
                return false;
            }
        }
    }
    return true;

}
bool place(int row,int board[8][8]){
    if(row>=8){
        return true;
    }
    for(int col=0;col<8;col++){
        if(check(row,col,board)){
            board[row][col]=1;
            if(place(row+1,board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}
int main(){
    int board[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=0;
        }
    }
    if(place(0,board)){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No Solution Exist!";
    }
    return 0;
}

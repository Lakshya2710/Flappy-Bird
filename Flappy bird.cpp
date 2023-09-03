#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
int pos=10;
bool k=1;
long int st=0;
char mat[20][80];
char c;
int score=0;
int highscore=0;
bool q=0;
//int t=1;
bool np=1;
int arr[6]={8,10,9,7,8,7};
void dec(){
    if(kbhit()){
        c=getchar();
        --pos;
    }
    else ++pos;
    for(int i=0;i<80;++i){
        mat[0][i]='-';
        mat[19][i]='-';
    }
    for(int i=1;i<19;++i){
        mat[i][0]='|';
        mat[i][79]='|';
    }
    int f=7+rand()%5;
    if(np==1){
        for(int i=2;i<20;++i){
            for(int j=2;j<80;++j){
                if((st+j)%15==0&&(i<arr[(st+j)/15-1]||i>arr[(st+j)/15-1]+4)){
                    mat[i-1][j-1]='*';
                }
                else if(j==5&&i==pos){
                    if(mat[i-1][j-1]=='*'||pos==19||pos==2){
                        k=0;
                        pos=10;
                        return;
                    }
                    if(mat[1][4]=='*') ++score;//1 pos
                    mat[i-1][j-1]='&';
                }
                else mat[i-1][j-1]=' ';
            }
        }
        ++st;
        q=0;
        if(mat[1][1]=='*'){
            q=1;
            st=0;
            np=0;
        }
    }
    else{
    for(int i=2;i<20;++i){
        for(int j=2;j<80;++j){
            if(q==1&&j==79&&(i<f||i>f+4)){//i 79
                mat[i-1][j-1]='*';
            }
            else if(j==5&&i==pos){
                if(mat[i-1][j-1]=='*'||pos==19||pos==2){
                    k=0;
                    pos=10;
                    return;
                }
                if(mat[1][4]=='*') ++score;//1 pos
                mat[i-1][j-1]='&';
            }
            else if(mat[i-1][j]=='*') mat[i-1][j-1]='*';
            else mat[i-1][j-1]=' ';
        }
    }
    q=0;
    if(mat[1][1]=='*') q=1;
    }
}
void printw(){
    for(int i=0;i<20;++i){
        for(int j=0;j<80;++j){
            cout<<mat[i][j];
        }
        cout<<"\n";
    }
}

void game(){   
    while(k){
        system("cls");
        dec();
        if(k==0){
            if(highscore<score) highscore=score;
            cout<<"Score : "<<score<<"\n";
            cout<<"Highest Score : "<<highscore<<"\n";
            score=0;
            cout<<"Game over\n";
            return;
        }
        printw();
    }
}
int main(){
    cout<<"Press enter to move the bird up\nPress y to start the game";
    char d;
    cin>>d;
    game();
    char s;
    cout<<"Do you want to play again?(Y/N)\n";
    cin>>s;
    while(s=='y'||s=='Y'){
        //++t;
        k=1;
        np=1;
        game();
        cout<<"Do you want to play again?(Y/N)\n";
        cin>>s;
    }
    cout<<"Highest Score : "<<highscore<<"\n";
    cout<<"Thanks for playing!";
}
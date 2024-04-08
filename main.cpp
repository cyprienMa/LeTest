#include <iostream>
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <cstdlib>
using namespace std;

const int N=10; // dimension du tableau
const int width=500; // dimension de la fenêtre
const int c=width/N;
// facteur correctif pour passer des indices de la case dans la grille aux coordonnées dans la fenêtre

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1}; // tableau des directions possibles
bool explored[N][N]; // matrice qui recensera si une case a été explorée ou pas encore



bool is_valid(int x, int y){ // la case considérée existe-t-elle dans notre tableau ?
    if (x>=width || x<0 ||y<0 || y>=width || y<0) return false;
    else return true;
}


void initialize_window(){  // dessine les cases
    openWindow(width,width);
    for (int i=1;i<N+1;i++){
        drawLine(i*width/N,0,i*width/N,width,BLACK);
        drawLine(0,i*width/N,width,i*width/N,BLACK);
    }
}

void draw(int x,int y, Color col){ // dessine les carrés de la case
    fillRect(x,y,c,c,col);
}


void go(int ox, int oy, int x, int y){ // fonction récursive

    if (!is_valid(x,y) || explored[x][y]) return;

    else{
        explored[x][y]=true;
        if (ox!=-1 && oy!=-1){ // on pourra pas colorier le point grâce auquel on initialise (-1, -1)
            draw(ox,oy,RED);
            milliSleep(100);
            draw(x,y,GREEN);
            milliSleep(100);
        }

        // tentative de bonus
        initRandom();
        for (int i=0;i<4;i++){
            int kx=dx[i],ky=dy[i]; //
            int j=intRandom(0,3);
            dx[i]=dx[j];
            dy[i]=dy[j];
            dx[j]=kx;
            dy[j]=ky;
        }


        for (int i=0;i<4;i++){
            milliSleep(100);
            draw(x,y,RED);
            go(x,y,x+dx[i]*c,y+dy[i]*c);
        }
    }
}


int main() {

    initialize_window();
    for (int i=0;i<N;i++){ // initialise le tableau des cases explorées telle qu'aucune n'est encore explorée
        for (int j=0;j<N;j++){
            explored[i][j]=false;
        }
    }


    go(-1,-1,width/2,width/2); // permet de lancer la fonction récursive

    return 0;
}























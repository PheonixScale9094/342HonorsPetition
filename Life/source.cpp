#include <stdio.h>

const int SCALE = 10;

int mod(int k, int n) {
    return ((k %= n) < 0) ? k+n : k;
}

void calcFuture(bool** current, bool** future, int posx, int posy){
    int sum = 0;
    for(int y = -1; y <= 1; y++){
        for(int x = -1; x <= 1; x++){
            if(x != 0 || y != 0){
                sum += (int)current[mod(posx+x,SCALE)][mod(posy+y,SCALE)];
            }
        }
    }

    if(sum == 3 || sum + current[posx][posy] == 3){
        future[posx][posy] = true;
    }
    else{
        future[posx][posy] = false;
    }
}

void iterateGrid(bool** current, bool** future, int n = 1){
    for(int i = 0; i < n; i++){
        for(int y = 0; y < SCALE; y++){
            for(int x = 0; x < SCALE; x++){
                calcFuture(current, future, x, y);
            }
        }

        for(int y = 0; y < SCALE; y++){
            for(int x = 0; x < SCALE; x++){
                current[x][y] = future[x][y];
            }
        }
    }
}

void printGrid(bool** grid){
    for(int y = 0; y < SCALE; y++){
        for(int x = 0; x < SCALE; x++){
            printf(" %d", grid[x][y]);
        }
        printf("\n");
    }
}

int main(){
    //Initialize Grids
    bool** currentGrid = new bool*[SCALE];
    bool** futureGrid = new bool*[SCALE];
    for(int i = 0; i < SCALE; i++){
        currentGrid[i] = new bool[SCALE];
        futureGrid[i] = new bool[SCALE];
    }

    currentGrid[5][5] = true;
    currentGrid[6][5] = true;
    currentGrid[7][5] = true;
    currentGrid[6][4] = true;
    currentGrid[5][4] = true;
    currentGrid[2][5] = true;
    currentGrid[3][5] = true;
    currentGrid[0][0] = true;
    currentGrid[1][1] = true;
    currentGrid[0][2] = true;
    currentGrid[1][2] = true;
    currentGrid[2][1] = true;



    printGrid(currentGrid);

    iterateGrid(currentGrid, futureGrid, 8);

    printf("\n");

    printGrid(currentGrid);

    return 0;
}
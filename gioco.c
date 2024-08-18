#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector {
    int x;
    int y;
} vector;

vector init(int matrix[][4]);
int check(int matrix[][4]);
void print(int matrix[][4]);
void play(int matrix[][4], vector* r);

////////////////////////////////////////////////////

int main() {
    srand48(time(NULL));

    int matrix[4][4] = {0};
    int moves = 0;
    vector r;

    r = init(matrix);

    while(check(matrix) == 0) {
        ++moves;
        play(matrix, &r);
    }

    fprintf(stdout, "You won in %d moves!!!\n", moves);

    return 0;
}

////////////////////////////////////////////////////

vector init(int matrix[][4]) {
    int extracted[15] = {0};
    int k, l;
    vector temp;

    l = lrand48() % 16;

    for(int i = 0; i < 16; i++) {
        
        if(i != l) {
            do {
                k = lrand48() % 15;
            } while(extracted[k] == 1);

            extracted[k] = 1;
            matrix[i / 4][i % 4] = k + 1;
        }
    }

    temp.x = l / 4;
    temp.y = l % 4;

    return temp;
}

int check(int matrix[][4]) {
    
    int w = 1;

    for(int i = 0; i < 15; i++){
        
        if(matrix[i / 4][i % 4] != i + 1) {
            w = 0;
        }
    }

    return w;
}

void print(int matrix[][4]) {

    fprintf(stdout, "***************\n");

    for(int i = 0; i < 4; i++) {

        for(int j = 0; j < 4; j++) {
            if(matrix[i][j]) {
                fprintf(stdout,"%2d  ", matrix[i][j]);
            }
            else {
                fprintf(stdout, "__  ");
            }
        }

        fprintf(stdout, "\n");
    }

    fprintf(stdout, "***************\n");
}

void play(int matrix[][4], vector* r) {
    
    print(matrix);

    int res = 0;
    int input = 0;

    while(res == 0 || (input != matrix[r->x][(r->y) + 1] && input != matrix[(r->x) - 1][r->y] && input != matrix[r->x][(r->y) - 1] && input != matrix[(r->x) + 1][r->y])) {
        fprintf(stdout, "Insert a valid input:\n");
        res = fscanf(stdin, "%d", &input);

        while(getchar() != '\n');

        if(res == 0 || (input != matrix[r->x][(r->y) + 1] && input != matrix[(r->x) - 1][r->y] && input != matrix[r->x][(r->y) - 1] && input != matrix[(r->x) + 1][r->y])) {
            fprintf(stderr, "...INVALID INPUT...\n...try again :( ...\n");
        }
    }

    if(input == matrix[r->x][(r->y) + 1]) {
        matrix[r->x][r->y] = matrix[r->x][(r->y) + 1];
        matrix[r->x][(r->y) + 1] = 0;
        ++(r->y); 
    }

    else if(input == matrix[(r->x) - 1][r->y]) {
        matrix[r->x][r->y] = matrix[(r->x) - 1][r->y];
        matrix[(r->x) - 1][r->y] = 0;
        --(r->x); 
    }

    else if(input == matrix[r->x][(r->y) - 1]) {
        matrix[r->x][r->y] = matrix[r->x][(r->y) - 1];
        matrix[r->x][(r->y) - 1] = 0;
        --(r->y); 
    }

    else if(input == matrix[(r->x) + 1][r->y]) {
        matrix[r->x][r->y] = matrix[(r->x) + 1][r->y];
        matrix[(r->x) + 1][r->y] = 0;
        ++(r->x); 
    }
}

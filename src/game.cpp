#include "raylib.h"
using namespace std;

int main(){
    InitWindow(800,450,"game")
    double x,y;
    while(!WindowShouldClose()){
        if(IsKEYDOWN(w)){//up
            y-=5;
        }if(IsKeyDown(s)){//down
            y+=5;
        }if(IsKeyDown(a)){//left
            x-=5;
        }if(IsKeyDown(d)){//right
            x+=5;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(x,y,50,50,RED);
        EndDrawing();
    }
    return 0;
}

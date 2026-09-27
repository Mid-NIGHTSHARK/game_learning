#include "raylib.h"

int main(){
    InitWindow(800,450,"game");
    double x,y;
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_W)){//up
            //IsKeyDown(KEY_W)
            y-=5;
        }if(IsKeyDown(KEY_S)){//dowin
            y+=5;
        }if(IsKeyDown(KEY_A)){//lefit
            x-=5;
        }if(IsKeyDown(KEY_D)){//right
            x+=5;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(x,y,50,50,RED);
        EndDrawing();
    }
    return 0;
}

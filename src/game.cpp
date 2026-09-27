#include "raylib.h"

int main(){
    double player_x,player_y;
    InitWindow(800,450,"--Game--");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_W)){//up
            player_y-=5;
        }if(IsKeyDown(KEY_S)){//down
            player_y+=5;
        }if(IsKeyDown(KEY_A)){//left
            player_x-=5;
        }if(IsKeyDown(KEY_D)){//right
            player_x+=5;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(player_x,player_y,100,100,RED);
        EndDrawing();
    };
}

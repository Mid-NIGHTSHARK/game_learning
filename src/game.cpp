#include "raylib.h"

int main(){
    
    double player_x = 200 ,player_y = 300;
    int window_x = 800,window_y = 450;
    int player_size_x=50,player_size_y=50;
    InitWindow(window_x,window_y,"--GAME--OVER--");
    Texture2D player = LoadTexture("./texture/player.png");
    SetTargetFPS(120);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(player,player_x,player_y,WHITE);
        EndDrawing();
    };
    UnloadTexture(player);
    CloseWindow();
}

#include "raylib.h"
#define BG_COUNT 4


Texture2D backgrounds[BG_COUNT];
float Backgrounds_y[BG_COUNT];

Texture2D player_idel,player_W,bullet;
void LoadIMAGES(){
    backgrounds[0] = LoadTexture("./texture/background.png"); 
    backgrounds[1] = LoadTexture("./texture/background2.png"); 
    backgrounds[2] = LoadTexture("./texture/background3.png"); 
    backgrounds[3] = LoadTexture("./texture/background4.png");
    player_idel = LoadTexture("./texture/PLAYER_IDEL.png");
    player_W = LoadTexture("./texture/PLAYER_W.png");
    bullet = LoadTexture("./texture/bullet_one.png");
    for(int i = 0; i < BG_COUNT; i++){
        Backgrounds_y[i] = -840.0f * i;
    };
    //load images.
}void UnloadIMAGES(){
    for(int i = 0; i < BG_COUNT; i++){
        UnloadTexture(backgrounds[i]);
    };
    UnloadTexture(player_W);
    UnloadTexture(player_idel);
    UnloadTexture(bullet);
    
};

//player
struct PLAYER{
    float x;
    float y;
    int width;
    int height;
    int speed;
    bool IsPlayerAlive;
    bool IsPlayerIdel;
};


//bullet
struct BULLET{
    float x;
    float y;
    int width;
    int height;
    int speed;
    bool IsFired;
    bool IsHit;
};

int main(){
    int screen_width = 1080;
    int screen_height = 840;
    InitWindow(1080,840,"--GAME--");
    SetTargetFPS(120);
    //background
    float BackgroundSpeed = 120.0;
    int ground = 840;
    
    int background_width = screen_width;
    int background_height = screen_height;
    //player
    PLAYER player;
    player.x = 540;
    player.y = 760;
    player.width = 120;
    player.height = 120;
    player.speed = 120;
    player.IsPlayerAlive = true;
    player.IsPlayerIdel = true;
    //bullet
    BULLET PlayerBullet;
    PlayerBullet.width = 50;
    PlayerBullet.height = 70;
    PlayerBullet.speed = 400;
    PlayerBullet.IsFired = false;
    PlayerBullet.IsHit = false;
    //loaing texture for player
    LoadIMAGES();

    while(!WindowShouldClose()){
        float dt = GetFrameTime();
        if(IsKeyDown(KEY_W)){ 
            player.y -= player.speed * dt;
            player.IsPlayerIdel = false;
        }else player.IsPlayerIdel = true;
        if(IsKeyDown(KEY_S)) player.y += player.speed * dt;
        if(IsKeyDown(KEY_A)) player.x -= player.speed * dt;
        if(IsKeyDown(KEY_D)) player.x += player.speed * dt;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        //background
        for(int i = 0; i < BG_COUNT; i++){
            DrawTexturePro(backgrounds[i],
                           {0,0,(float)backgrounds[i].width,(float)backgrounds[i].height},
                           {0,Backgrounds_y[i],(float)background_width,(float)background_height},
                           {0,0},
                           0.0f,
                           WHITE
            );
            Backgrounds_y[i] += BackgroundSpeed * dt; 
            if(Backgrounds_y[i] >= ground){
                Backgrounds_y[i] -= background_height * BG_COUNT;
            };
        };
        //bullet
        // Fire bullet
        if (IsKeyPressed(KEY_SPACE) && !PlayerBullet.IsFired)
        {
            PlayerBullet.x = player.x + player.width / 2.0f
                        - PlayerBullet.width / 2.0f;

            PlayerBullet.y = player.y;

            PlayerBullet.IsFired = true;
        }

        // Move bullet
        if (PlayerBullet.IsFired)
        {
            PlayerBullet.y -= PlayerBullet.speed * dt;

            // Remove bullet when it leaves the screen
            if (PlayerBullet.y + PlayerBullet.height < 0)
            {
                PlayerBullet.IsFired = false;
            }
        }
        DrawTexturePro(bullet,
                       {0,0,(float)bullet.width,(float)bullet.height},
                       {PlayerBullet.x,PlayerBullet.y,(float)PlayerBullet.width,(float)PlayerBullet.height},
                       {0,0},
                       0.0f,
                       WHITE
        );
        //player
        if(player.IsPlayerIdel){
            DrawTexturePro(player_idel,
                           {0,0,(float)player_idel.width,(float)player_idel.height},
                           {player.x,player.y,(float)player.width,(float)player.height},
                           {0,0},
                           0.0f,
                           WHITE
            );
        }else{
            DrawTexturePro(player_W,
                           {0,0,(float)player_W.width,(float)player_W.height},
                           {player.x,player.y,(float)player.width-70,(float)player.height+40},
                           {0,0},
                           0.0f,
                           WHITE
            );
        };

        EndDrawing();
    }
    UnloadIMAGES();
    CloseWindow();
}

/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    int speed = 2;
    const int screenWidth = 1366;
    const int screenHeight = 695;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    
    InitWindow(screenWidth, screenHeight,  "Ramen's Testing Script");

    Texture2D boi = LoadTexture("C:/Users/Ramen/Pictures/placeholder_50x50.png");

    bool goLeft = false;
    bool goRight = false;
    bool goUp = false;
    bool goDown = false;

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        speed = (speed + .1);
        
        if (((ballPosition.x + 50) >= GetScreenWidth())) {
            ballPosition.x = (ballPosition.x - speed);
        };

        if ((ballPosition.x - 0) <= 0) {
            ballPosition.x = (ballPosition.x + speed);
        };

        if ((ballPosition.y + 50) >= GetScreenHeight()) {
            ballPosition.y = (ballPosition.y - speed);
        };

        if (ballPosition.y <= 0) {
            ballPosition.y = (ballPosition.y + speed);
        };

        if (IsKeyDown(KEY_RIGHT)) {
            goLeft = true;
            goRight = false;
            goUp = false;
            goDown = false;
        };
        if (IsKeyDown(KEY_LEFT)) {
            goRight = true;
            goLeft = false;
            goUp = false;
            goDown = false;
        };
        if (IsKeyDown(KEY_UP)) {
            goUp = true;
            goDown = false;
            goRight = false;
            goLeft = false;
        };
        if (IsKeyDown(KEY_DOWN)) {
            goDown = true;
            goUp = false;
            goLeft = false;
            goRight = false;
        };
        
        if (goLeft == true) {
            ballPosition.x += speed;
        };

        if (goRight == true) {
            ballPosition.x -= speed;
        };
        
        if (goUp == true) {
            ballPosition.y -= speed;
        };

        if (goDown == true) {
            ballPosition.y += speed;
        };

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Ramen's Test Script", 10, 0, 20, GREEN);

        DrawText("(Move the ball with arrow keys)", 10, 20, 20, DARKGREEN);

        DrawTexture(boi, ballPosition.x, ballPosition.y, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
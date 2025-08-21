#include <raylib.h>

#include "includes/visualization.h"

void main_loop() {
        int win_width = 1200, win_height = 800;
        InitWindow(win_width, win_height, "3d Mapper");
        Camera3D camera   = { 0 };
        camera.position   = (Vector3){ 5,  5,  5};
        camera.target     = (Vector3){ 0,  0,  0};
        camera.up         = (Vector3){ 0,  1,  0};
        camera.fovy       = 45.0f;
        camera.projection = CAMERA_PERSPECTIVE;
        while (!WindowShouldClose()) {
                // use P to enable/disable cursor

                UpdateCamera(&camera, CAMERA_FREE);
                ClearBackground(LIGHTGRAY);
                BeginDrawing();
                        BeginMode3D(camera);
                        DrawGrid(100, 1.0f);
                        EndMode3D();
                EndDrawing();
        }
        CloseWindow();
}

#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <math.h>
#include <stdio.h>

#include "includes/database.h"
#include "includes/visualization.h"

/*
 * heavy inspiration from
 * https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c
*/

void print_world_pos(Vector2 mouse_world_pos) {
        DrawCircleV(GetMousePosition(), 4, DARKGRAY);
        char mouse_pos_buffer[32];
        sprintf(mouse_pos_buffer, "[%d, %d]", (int16_t)mouse_world_pos.x, (int16_t)mouse_world_pos.y);
        DrawCircleV(GetMousePosition(), 4, DARKGRAY);
        DrawTextEx(GetFontDefault(), mouse_pos_buffer, Vector2Add(GetMousePosition(), (Vector2){ -44, -24 }), 20, 2, BLACK);
}

void main_loop(struct db_settings *alpha) {
        InitWindow(1000, 800, "Generic Mapper");
        Camera2D camera = {0};
        camera.zoom = 10.0f;
        SetTargetFPS(60);
        uint8_t curr_floor = 0; // not used right now

        while (!WindowShouldClose()) {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                        Vector2 delta = Vector2Scale(GetMouseDelta(), -1.0f/camera.zoom);
                        camera.target = Vector2Add(camera.target, delta);
                }
                float wheel = GetMouseWheelMove();
                Vector2 mouse_world_pos = GetScreenToWorld2D(GetMousePosition(), camera);
                if (wheel != 0) {
                        camera.offset = GetMousePosition();
                        camera.target = mouse_world_pos;
                        // Uses log scaling to provide consistent zoom speed
                        // Clamp just ensures value is in range
                        float scale = 0.2f*wheel;
                        camera.zoom = Clamp(expf(logf(camera.zoom)+scale), 0.125f, 64.0f);
                }

                BeginDrawing();
                        ClearBackground(RAYWHITE);
                        BeginMode2D(camera);
                        // so, how does the interal matrix stack affect DrawGrid???
                        // does the current matrix transform the world???
                        rlPushMatrix();
                                rlTranslatef(0, 25*50, 0);
                                rlRotatef(90, 1, 0, 0);
                                DrawGrid(5000, 10);
                        rlPopMatrix();
                        DrawCircle(0, 0, 1.0, RED);
                        EndMode2D();

                        print_world_pos(mouse_world_pos);
                EndDrawing();
        }

        CloseWindow();
}

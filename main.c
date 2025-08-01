#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "/home/mrid/Documents/C&C++/ATM-GUI/raygui.h"

int main(void)
{
    InitWindow(800, 450, "raygui Slider Example");

    float value = 50.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        GuiSliderBar((Rectangle){ 300, 200, 200, 20 },
                     "Min", "Max", &value, 0, 100);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

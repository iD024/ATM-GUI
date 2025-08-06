#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "/home/mrid/Documents/C&C++/ATM-GUI/raygui.h"
#include <stdlib.h>
#define MAX_ACCOUNTS 100

int main(void)
{
    InitWindow(1020, 1860, "ATM - GUI");
    int screenwidth = 1020;
    SetExitKey(KEY_Q);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 60);
    
    char accountNumber[20] = "";
    char pin[20] = "";
    bool accEdit = true;
    bool pinEdit = false;
    bool submitted = false;

    
    typedef struct {
        char name[100];
        int account_number;
        int pin;
        float balance;
    } Account;


    Account accounts[MAX_ACCOUNTS];
    int account_count = 0;

    FILE *fp = fopen("user.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return 1;
    }   
    while (fscanf(fp, "%s %d %d %f", accounts[account_count].name, &accounts[account_count].account_number, &accounts[account_count].pin, &accounts[account_count].balance) == 4) {
        account_count++;
        if (account_count >= MAX_ACCOUNTS) 
        break;
    }
    fclose(fp);



    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        int found = 0;

        GuiLabel((Rectangle){ 300, 10, MeasureText("Press Q to Quit", 60), 100 }, "Press Q to Quit" );
        DrawText("ATM", 400, 150, 100, BLUE);
        


        //acount
        if (GuiTextBox((Rectangle){ 300, 250, 200, 30 }, accountNumber, 20, accEdit)) {
        accEdit = true;
        pinEdit = false;
        submitted = false;
        }

        // Pin
        if (GuiTextBox((Rectangle){ 300, 300, 200, 30 }, pin, 20, pinEdit)) {
        accEdit = false;
        pinEdit = true;
        submitted = false;
        }

        // Toggle with TAB
        if (IsKeyPressed(KEY_TAB)) {
        accEdit = !accEdit;
        pinEdit = !pinEdit;
        }

     // To check its even taking in values
        
        if (GuiButton((Rectangle){ 350, 400, 300, 80 }, "Submit")) {
            submitted = true;
        }
        if (submitted) {
        int found = 0;
        for (int i = 0; i < account_count; i++) {
            if (accounts[i].account_number == atoi(accountNumber) && accounts[i].pin == atoi(pin)) {
                DrawText(TextFormat("Welcome %s, Balance: ₹%.2f", accounts[i].name, accounts[i].balance), 300, 500, 20, DARKGRAY);
                found = 1;
                break;
        }
        }
        if (!found) {
        DrawText("FAILED", 300, 600, 20, RED);
        }
    }
    EndDrawing();

    }
    

    CloseWindow();
    return 0;
}

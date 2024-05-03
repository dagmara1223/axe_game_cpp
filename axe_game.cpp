#include <iostream>
#include "raylib.h"
using namespace std;
 
int main()
{
    // wymiary okienka
    int width{800};
    int height{450};
    InitWindow(width, height, "Dagmara's window") ; //okienko

    //wymiary koleczka
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //wymiary box kolo
    int l_circle_x {circle_x - circle_radius};
    int r_circle_x{circle_x+circle_radius};
    int upper_circle_y{circle_y - circle_radius};
    int bottom_circle_y{circle_y+circle_radius};


    //wymiary kwadrat
    int axe_x{400};
    int axe_y{0}; 
    int axe_length{50};
    //wymiary box kwadrat
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int upper_axe_y{axe_y};
    int bottom_axe_y{axe_y+axe_length};
    

    int direction{15};

    bool collision_with_axe = (bottom_axe_y >= upper_circle_y) &&(upper_axe_y <= bottom_circle_y)
    && (r_axe_x>=l_circle_x)&& (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while(WindowShouldClose() == false) //dopoki nie klikniemy x
    {
        BeginDrawing();
        ClearBackground(WHITE); // kolor okienka 
        if(collision_with_axe)
        {
            DrawText("Game Over", 400, 200, 20, RED);
        }
        else
        {
            // logika gry

            //updatuje wartosci
            l_circle_x= circle_x - circle_radius;
            r_circle_x = circle_x+circle_radius;
            upper_circle_y = circle_y - circle_radius;
            bottom_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            upper_axe_y = axe_y;
            bottom_axe_y = axe_y + axe_length;

            collision_with_axe = (bottom_axe_y >= upper_circle_y) &&(upper_axe_y <= bottom_circle_y)
                && (r_axe_x>=l_circle_x)&& (l_axe_x <= r_circle_x);


            DrawCircle(circle_x, circle_y, circle_radius, PINK);
            DrawRectangle(axe_x, axe_y, axe_length , axe_length, BLACK);

            axe_y +=direction;
            if(axe_y> height or axe_y < 0)
            {
                direction = -direction;
            }

            if(IsKeyDown(KEY_D)&& circle_x < width) //czy klikamy cos na klawiaturze 
            {
                circle_x += 10;
            }
            if(IsKeyDown(KEY_A) && circle_x > 0 )
            {
                circle_x-=10;
            }
            if(IsKeyDown(KEY_W) && circle_y > 0 )
            {
                circle_y-=10;
            }
            if(IsKeyDown(KEY_S) &&  circle_y <450 )
            {
                circle_y+=10;
            }

            
            //koniec gry
        }

        EndDrawing();
    }
}
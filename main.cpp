#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include<ctime>
#include "Collision.h"

int main() {

    srand(time(0));
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* win=SDL_CreateWindow(

        "Change shot",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        800,
        SDL_WINDOW_SHOWN

    );



    bool run=true;
    SDL_Event ev;
    SDL_Rect pl={350,350,50,50};
    SDL_Rect gun={pl.x - 10 ,pl.y + 20 ,20,10};
    SDL_Rect bullet = {0, 0, 20, 10};
    SDL_Rect enemy={rand() %800,rand() % 800,55,55};
    bool shoot=false;
    const int  minDistance=150;
    SDL_Renderer* ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);



    do {


        enemy.x = rand() % (800 - enemy.w);
        enemy.y = rand() % (800 - enemy.h);


        enemy.w = 55;
        enemy.h = 55;

    } while (

        enemy.x < pl.x + pl.w + minDistance &&
        enemy.x + enemy.w > pl.x - minDistance &&
        enemy.y < pl.y + pl.h + minDistance &&
        enemy.y + enemy.h > pl.y - minDistance

    );



    while(run) {

        while (SDL_PollEvent(&ev)) {
        
            if(ev.type == SDL_QUIT) {

                run=false;


            }

            if(ev.type == SDL_KEYDOWN) {

                if(ev.key.keysym.sym == SDLK_SPACE) {
                    
                    if(!shoot) {

                        bullet.x=gun.x + 20;
                        bullet.y=gun.y - 5;
                        shoot=true;

                    }

                }

            }

        }

        gun.y = pl.y;
        const Uint8* kay=SDL_GetKeyboardState(NULL);

        //gun move
        if(kay[SDL_SCANCODE_D]) {

            gun.x=pl.x + 45;

        }else if (kay[SDL_SCANCODE_A]) {

            gun.x=pl.x - 10;

        }






        //pl move
        if(kay[SDL_SCANCODE_W]) {

            pl.y -= 2;

        }else if(kay[SDL_SCANCODE_S]) {

            pl.y += 2;

        }







        //screen wrapping
        if(pl.y < 0) {

            pl.y = 750;


        }else if(pl.y > 750) {

            pl.y = 0;

        }
        
        

        
        
        //move bullet
        if(shoot) {

            if(gun.x == pl.x - 10) {
    
                bullet.x -= 25;


            if(bullet.x < 0) {


                bullet.x=gun.x + 35;
                bullet.y=gun.y - 5;
                shoot=false;



            }





            }else{

                bullet.x += 35;


                if(bullet.x > 799) {


                    bullet.x=gun.x + 25;
                    bullet.y=gun.y - 9;
                    shoot=false;



                }

            }



        }



        if(checkCollision(bullet,enemy)) {




            enemy.x = rand() % (800 - enemy.w);
            enemy.y = rand() % (800 - enemy.h);
        

        }
        




        SDL_SetRenderDrawColor(ren,0,0,0,255);
        SDL_RenderClear(ren);



        
        SDL_SetRenderDrawColor(ren,0,255,0,255);
        SDL_RenderFillRect(ren,&pl);
        



        SDL_SetRenderDrawColor(ren,192,192,192,255);
        SDL_RenderFillRect(ren,&gun);
        





        //show bullet
        if(shoot) {

            SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);  
            SDL_RenderFillRect(ren, &bullet);

        }
        
        SDL_SetRenderDrawColor(ren,255,0,0,255);
        SDL_RenderFillRect(ren,&enemy);







        SDL_RenderPresent(ren);
        SDL_Delay(13);

        

    }



    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
    return 0;

}

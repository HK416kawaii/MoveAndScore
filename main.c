#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct bouns{int x;
             int y;
                   };
struct role {int x;
             int y;
             int score;
             int HP;
                    };
struct bouns Apple;
struct role Player;
void RamApple(struct bouns *p);
void RamPlayer(struct role *p);

int main()
{
    int status=1;
    srand(time(NULL));
    char move;
    Player.HP=10;      //use it later
    Player.score=0;
    do{
        do{     //Randomize the location of Player and Apple
        RamPlayer(&Player);
        RamApple(&Apple);
        }while(Player.x==Apple.x&&Player.y==Apple.y);     //Make sure they won't appear in the same place

        puts("GAME RULES : TYPE w/a/s/d + <ENTER> TO MOVE, TRY TO GET APPLE IN THE FIELD!");        //prompt
        do
        {
            PrintScen();
            puts("Time to move!");
            scanf(" %c",&move);
            switch(move)        //get the location after moving
            {
                case 'w':
                        --Player.x;
                        puts("YOU MOVE UPWARD");
                        break;
                case 'a':
                        --Player.y;
                        puts("YOU MOVE UPWARD");
                        break;
                case 's':
                        ++Player.x;
                        puts("YOU MOVE UPWARD");
                        break;
                case 'd':
                        ++Player.y;
                        puts("YOU MOVE UPWARD");
                        break;
                default: 
                        puts("Wrong char");
                        break;
            }
            if(Player.x==Apple.x&&Player.y==Apple.y)        //verify whether the player win
            {
                ++Player.score;
                puts("YOU GET THE APPLE!");
                printf("Current score: %d\n",Player.score);
                status=0;
            }
        }while(status==1);
        puts("ANOTHER ROUND?(PRESS 1 TO CONTINUE, 0 TO QUIT)");
        scanf("%d",&status);
    }while(status==1);
   
}

void RamPlayer(struct role *p)
{
    p->x=rand()%5;
    p->y=rand()%5;
}

void RamApple(struct bouns *p)
{
    p->x=rand()%5;
    p->y=rand()%5;
}

void PrintScen()
{
    for(int x=0;x<5;++x)
    {
        for(int y=0;y<5;++y)
        {
            if(x==Player.x&&y==Player.y)
            {
                printf("%c",'P');
                for(int i=0;i<3;++i)
                {
                    printf("%c",' ');
                }
            }
            else if(x==Apple.x&&y==Apple.y)
            {
                printf("%c",'A');
                for(int i=0;i<3;++i)
                {
                    printf("%c",' ');
                }
            }
            else
            {
                printf("%c",'O');
                for(int i=0;i<3;++i)
                {
                    printf("%c",' ');
                }
            }
            if(y==4)
            {
                puts("");
            }
        }
    }
    
}
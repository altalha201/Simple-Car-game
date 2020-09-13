/** A simple Car Game for fun ( code written in C) **/

/**
 * This is a simple car game
 * It can be play by writing command
 * It is written for self improvement
 * It is written for fun purpose
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SCORE 2147483640

int main()
{
    char command[30];
    char start[] = "start", stop[] = "stop";
    char help[] = "help", quit[] = "quit";
    char right[] = "right", left[] = "left";
    char run[] = "run", slow[] = "break";
    int score = 0, suffex_counter = 1;
    int running = 0;
    int started = 0;
    int lane = 1;

    printf("Please write all the command in lower case....\n");
    printf("<< start - To start the car    >>\n");
    printf("<< run   - To speed up the car >>\n");
    printf("<< break - To slow the car     >>\n");
    printf("<< stop  - To stop the car     >>\n");
    printf("<< right - To go right         >>\n");
    printf("<< left  - To go left          >>\n");
    printf("<< quit  - To end the game     >>\n");

    while (1)
    {
        if(score == MAX_SCORE)
        {
            printf("\n\t<< YOU RICHED MAX SCORE!!! >>\n");
            break;
        }
        printf("\nCommand -> ");
        gets(command);

        if(strcmp(command,start) == 0)  /** Command to Start The Car **/
        {
            if(started == 1)
            {
                printf("<< Car is already started!!! >>\n");
                score-= suffex_counter;
            }
            else
            {
                started = 1;
                printf("<< Car started... Ready to run! >>\n");
                score+= (3*suffex_counter);
            }
        }

        else if(strcmp(command,run) == 0)   /** Command to Run or speed up The Car **/
        {
            if(started == 1)
            {
                if(running == 1)
                {
                    printf("<< Speed up... >>\n");
                    suffex_counter++;
                }
                else
                {
                    running = 1;
                    printf("<< Car start running... >>\n");
                    score+= (2*suffex_counter);
                }
            }
            else
            {
                printf("<< Car is not started... >>\n");
            }
        }

        else if(strcmp(command,slow) == 0)  /** Command to slow or break The Car **/
        {
            if(started == 1)
            {
                if(running == 1)
                {
                    running = 0;
                    printf("<< Car stop running... >>\n");
                    suffex_counter--;
                }
                else
                {
                    printf("<< Car is not running... >>\n");
                    suffex_counter = 1;
                }

            }
        }

        else if(strcmp(command,right) == 0) /** Command to Change lane in right **/
        {
            if(started == 1)
            {
                if(running == 1)
                {
                    if(lane == 1)
                    {
                        lane = 0;
                        printf("<< Car in shifted to right lane... >>\n");
                        score += (1*suffex_counter);
                    }
                    else if(lane == 2)
                    {
                        lane = 1;
                        printf("<< Car is sifted to center lane... >>\n");
                        score += (1*suffex_counter);
                    }
                    else
                    {
                        printf("<< Car crashed!!! >>\n");
                        printf("\n\t<<\tGAME OVER\t>>\n");
                        break;
                    }
                }
                else
                {
                    printf("<< Car is not running... >>\n");
                }
            }
            else
            {
                printf("<< Car is not started... >>\n");
            }
        }

        else if(strcmp(command,left) == 0)  /** Command to Change lane in left **/
        {
            if(started == 1)
            {
                if(running == 1)
                {
                    if(lane == 1)
                    {
                        lane = 2;
                        printf("<< Car shifted to left lane... >>\n");
                        score += (1*suffex_counter);
                    }
                    else if(lane == 0)
                    {
                        lane = 1;
                        printf("<< Car shifted to center lane... >>\n");
                        score += (1*suffex_counter);
                    }
                    else
                    {
                        printf("<< Car crashed!!! >>\n");
                        printf("\n\t<<\tGAME OVER\t>>\n");
                        break;
                    }
                }
                else
                {
                    printf("<< Car is not running... >>\n");
                }
            }
            else
            {
                printf("<< Car is not started... >>\n");
            }
        }

        else if(strcmp(command,stop) == 0)  /** Command to Stop The Car **/
        {
            if(started == 0)
            {
                printf("<< Car is already stopped!!! >>\n");
                score--;

            }
            else
            {
                started = 0;
                printf("<< Car stopped... >>\n");
                running = 0;
                suffex_counter = 1;
            }
        }

        else if(strcmp(command,help) == 0)  /** Command for Help or hint **/
        {
            printf("<< start - To start the car    >>\n");
            printf("<< run   - To speed up the car >>\n");
            printf("<< break - To slow the car     >>\n");
            printf("<< stop  - To stop the car     >>\n");
            printf("<< right - To go right         >>\n");
            printf("<< left  - To go left          >>\n");
            printf("<< quit  - To end the game     >>\n");
        }

        else if(strcmp(command,quit) == 0)  /** Command to Quit from Game **/
        {
            printf("\n\t<<\tYOU STOP PLAYING\t>>\n");
            score+=5;
            break;
        }

        else
            printf("<< I can't understand the command... >>\n");
    }

    printf("\t<<\tSCORE: %d\t>>\n", score);

    return 0;
}

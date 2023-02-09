#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAMS_LENGTH 5
#define STR_LENGTH 100

int main(void)
{
    char *programs[] = {
                        "isPrime-broken1",
                        "isPrime-broken2",
                        "isPrime-broken3",
                        "isPrime-broken4",
                        "isPrime-correct"
    };

    int start_test = -1;
    int end_test = 1;
    int increment = 1;
    FILE *file;

    int status;
    char command[STR_LENGTH];
    char number[STR_LENGTH];
    char commands[PROGRAMS_LENGTH][STR_LENGTH];
    
    for (int i = 0; i < PROGRAMS_LENGTH; i += 1)
    {
        char *current = commands[i];
        strcpy(current, "./");
        strcat(current, programs[i]);
    }

    for (int i = 0; i < PROGRAMS_LENGTH; i += 1)
    {
        strcpy(command, "output_");
        strcat(command, programs[i]);
        strcat(command, ".txt");
        printf("Clear %s\n", command);
        file = fopen(command, "w");
        fclose(file);
        printf("%s cleared\n", command);
    }

    for (int i = start_test; i <= end_test; i += increment)
    {
        for (int j = 0; j < PROGRAMS_LENGTH; ++j)
        {
            strcpy(command, commands[j]);
            strcat(command, " ");
            sprintf(number, "%d", i);
            strcat(command, number);
            strcat(command, " >> output_");
            strcat(command, programs[j]);
            strcat(command, ".txt");
            status = system(command);
            printf("command: %s\nstatus: %d\n", command, status);
            // printf("%s\n", command);
        }
    }

    int last = PROGRAMS_LENGTH - 1;
    for (int i = 0;i < last; ++i)
    {
        strcpy(command, "diff ");
        strcat(command, "output_");
        strcat(command, programs[i]);
        strcat(command, ".txt");
        strcat(command, " output_");
        strcat(command, programs[last]);
        strcat(command, ".txt");
        strcat(command, " > diff_");
        sprintf(number, "%d", i + 1);
        strcat(command, number);
        strcat(command, ".txt\n");
        status = system(command);
        printf("command: %s\nstatus: %d\n", command, status);
        // printf("%s\n", command);
    }
    
    // status = system("./isPrime-broken1 1 > test.txt");
    // printf("command: %s\nstatus: %d\n", command, status);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Teams {
    char name[64];
    int win;
    int lose;
    int red;
    int yellow;
} Team;
void printTeam(Team team) {
    if (strcmp(team.name,"UNKNOWN") == 0) {
        printf("No teams found!\n");
        return;
    }
    printf("Team result:\n");
    printf("Name: %s\n",team.name);
    printf("Win goals: %d\n",team.win);
    printf("Lose goals: %d\n",team.lose);
    printf("Red cards: %d\n",team.red);
    printf("Yellow cards: %d\n",team.yellow);
    printf("Total score: %d\n",team.win*10 - team.lose*5 - team.yellow*2 - team.red*5);
    return;
}
Team findTeamByName(char name[], Team teamArray[]) {
    Team unknown = {.name="UNKNOWN"};
    for (int i = 0; i<32; i++) {
        if (strcmp(name,teamArray[i].name) == 0) {
            return teamArray[i];
        }
    }
    return unknown;
}
int main() {
    Team teamArray[32];
    printf("Fill in 32 teams scores:\n");
    for (int i = 0; i<32; i++) {
            printf("Team %d:\n",i+1);
            printf("Name:");
            scanf("%s",teamArray[i].name);
            printf("Win goals:");
            scanf("%d",&teamArray[i].win);
            printf("Lose goals:");
            scanf("%d",&teamArray[i].lose);
            printf("Red cards:");
            scanf("%d",&teamArray[i].red);
            printf("Yellow cards:");
            scanf("%d",&teamArray[i].yellow);
            printf("=========================\n");
    }
    printf("Pick one teams to show their results!\n");
    bool isCancelled = false;
    while (!isCancelled) {
        char name[32];
        char res[10];
        printf("Team name: ");
        scanf("%s",name);
        printf("=========================\n");
        printTeam(findTeamByName(name,teamArray));
        printf("Do you want to continue[yes/no]:");
        scanf("%s",res);
        if (strcmp(res,"yes") != 0) {
            isCancelled = true;
        }
    }
    
    return 0;
}
#include <stdio.h>

int main() {
    int score;
    printf("Enter 0 or 1 to STOP otherwise Enter the NFL score: ");
    scanf("%d", &score);
    int combos = 0; //amount of total possiblities
    int score_outputs[100000][5]; //5, one for each category of score, and a max of 100000 combinations
    //100000 is just a place holder value that it will rarely ever reach
    for(int td = 0; td * 6 <= score; td++){
        for(int fg = 0; fg*3 <= score; fg++){
            for(int safety = 0; safety * 2 <= score; safety++){
                for(int td_2 = 0; td_2 * 8 <= score; td_2++){
                    for(int td_xp = 0; td_xp * 7 <= score; td_xp++){
                        int sum = td*6 + fg*3 + safety * 2 + td_2 * 8 + td_xp * 7;
                        if(score == sum){
                        score_outputs[combos][0] = td;
                        score_outputs[combos][1] = fg;
                        score_outputs[combos][2] = safety;
                        score_outputs[combos][3] = td_2;
                        score_outputs[combos][4] = td_xp;
                        combos++;
                        }
                    }
                }
            }
        }
    }
    printf("all possible score combinations\n");
    for (int i = 0; i < combos; i++){
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", score_outputs[i][3], score_outputs[i][4], score_outputs[i][0], score_outputs[i][1], score_outputs[i][2]);
    }

    return 0;
}
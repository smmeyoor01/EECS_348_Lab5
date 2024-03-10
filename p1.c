#include <stdio.h>

int main() {
    char inputFile[35];
    printf("Enter Filename: ");
    scanf("%s", inputFile);
    const char* months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    FILE *input = fopen(inputFile, "r");

    float vals[12];
    float val;
    int count = 0;  
    while (fscanf(input, "%f", &val) > 0) {
        vals[count] = val;
        count++;
    }

    printf("\nMonthly sales report for 2022: \nMonth Sales\n");
    for(int x = 0; x < 12; x++){
        printf("\n%s      $%.2f\n", months[x], vals[x]);
    }

    float min = vals[0];
    int min_month = 0;
    for(int x = 0; x < count; x++){
        if(vals[x] < min){
            min = vals[x];
            min_month = x;
        }
    }

    float max = vals[0];
    int max_month = 0;
    float average = 0;
    for(int x = 0; x < count; x++){
        average += vals[x];
        if(vals[x] > max){
            max = vals[x];
            max_month = x;
        }
    }
    average = average / count;
    fclose(input);
    printf("\nSales summary:\nMinimum sales: $%.2f (%s)\nMaximum sales: $%.2f (%s)\nAverage sales: $%.2f\n", min, months[min_month], max, months[max_month], average);

    printf("\nSix-Month Moving Average Report:\n");
    for(int x = 0; x < 6; x++){
        float six_month_average = 0;
        for(int i = 0; i < 6; i++) {
            six_month_average += vals[x + i];
        }
        six_month_average /= 6;
        printf("\n%s - %s:   %.2f\n", months[x], months[x+5], six_month_average);
    }

    float temp;
	for (int x = 0; x < 12; x++){
		for(int y = x+1; y < 12; y++){
			if(vals[x] < vals[y]){
				temp = vals[x];
				vals[x] = vals[y];
				vals[y] = temp;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n Month Sales\n");
    for(int x = 0; x < 12; x++){
        printf("\n%s      $%.2f\n", months[x], vals[x]);
    }
    return 0;
}
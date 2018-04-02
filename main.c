#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define HUMAN_READABLE

int main()
{
    time_t timer = time(NULL);
    char ds[5], ms[5], ys[5];
    strftime(ds, 5, "%d", localtime(&timer));
    strftime(ms, 5, "%m", localtime(&timer));
    strftime(ys, 5, "%Y", localtime(&timer));
    
    int  dayselapsed = atoi(ds), 
         month = atoi(ms), 
         year = atoi(ys), 
         totaldays = 365,
         months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leapyear = false;
    
    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        leapyear = 1;
        totaldays = 366;
    }
    
    for(int i = 0; i < month - 1; i++)
    {
        dayselapsed += months[i];
        if(i == 1 && leapyear == 1)
            dayselapsed++;
    }

    float result = (float)(dayselapsed) / (float)(totaldays) * 100.0;
#ifdef HUMAN_READABLE
    printf("%i is %.2f%% complete\n", year, result);
#else
    printf("%.2f", result);
#endif //HUMAN_READABLE
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

/*  Demonstration of dynamically allocated array
*/
int main()
{
    int ARRAY_SIZE = 10;
    int *surveyData = calloc(ARRAY_SIZE, sizeof(int));
    printf("Number of survey responses: ");
    scanf("%d", &ARRAY_SIZE);
    realloc(surveyData, ARRAY_SIZE * sizeof(int));
    int i = 0;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Survey response %d: ", i + 1);
        scanf("%d", &surveyData[i]);
        printf("\n");
    }
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", surveyData[i]);
    }
    free(surveyData);
    return 0;
}

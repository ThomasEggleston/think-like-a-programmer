#include <stdio.h>


int main()
{
    int BUFFER_SIZE = 100;
    int UPPER_RANGE = 10;
    int LOWER_RANGE = 1;

    char buffer[BUFFER_SIZE];
    int i = 0;
    for (i = 0; i < BUFFER_SIZE - 1; i++)
        {
            buffer[i] = 0;
        }

    int frequencies[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    printf("Enter some numbers between 1 and 10. Limit of 100 characters\n");
    scanf("%s", &buffer);

    int p = 0;  // Current index buffer is being read from

    int n = 0;  // Integer to store number read by atoi()

    n = atoi(buffer);

    if (n >= LOWER_RANGE && n <= UPPER_RANGE)
    {
        frequencies[n-1] += 1;
    }

    for (p = 0; p < BUFFER_SIZE; p++)
    {
        if (buffer[p] == ',')
        {
            n = atoi(&buffer[p+1]);

            if (n >= LOWER_RANGE && n <= UPPER_RANGE)
            {
                frequencies[n-1] += 1;
            }
        }
    }

    int mode_freq = 0;

    for (i = 0; i < (UPPER_RANGE - LOWER_RANGE + 1); i++)
    {
        if (frequencies[i] > mode_freq)
        {
            mode_freq = frequencies[i];
        }
    }

    for (i = 0; i < (UPPER_RANGE - LOWER_RANGE + 1); i++)
    {
        if (frequencies[i] == mode_freq)
        {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}

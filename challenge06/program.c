#include <stdio.h>

int readInteger(char prompt[])
{
    int value, ch, invalid;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input. Enter an integer.\n");

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            if (ch == EOF)
                return 0;

            continue;
        }

        invalid = 0;

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            if (ch != ' ' && ch != '\t' && ch != '\r' &&
                ch != '\v' && ch != '\f')
            {
                invalid = 1;
            }
        }

        if (invalid)
        {
            printf("Enter only one integer per line.\n");
            continue;
        }

        return value;
    }
}

void reverse(int arr[], int left, int right)
{
    int temp;

    while (left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    int arr[12];
    int n, i, min, max;
    int second, foundSecond = 0;
    int peaks = 0;
    int currentRun = 1, longestRun = 1;
    int k, shift, r, d;
    int divisibleCount = 0;
    long sum = 0;
    double average;

    do
    {
        n = readInteger("Enter N (5 to 12): ");

        if (n < 5 || n > 12)
            printf("Invalid N. Try again.\n");

    } while (n < 5 || n > 12);

    for (i = 0; i < n; i++)
    {
        do
        {
            arr[i] = readInteger("Enter reading (0 to 1000): ");

            if (arr[i] < 0 || arr[i] > 1000)
                printf("Invalid reading. Try again.\n");

        } while (arr[i] < 0 || arr[i] > 1000);
    }

    printf("\nOriginal readings: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    min = max = arr[0];

    for (i = 0; i < n; i++)
    {
        sum += arr[i];

        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    average = (double)sum / n;

    printf("\nSum = %ld", sum);
    printf("\nAverage = %.2f", average);
    printf("\nMinimum = %d", min);
    printf("\nMaximum = %d\n", max);

    for (i = 0; i < n; i++)
    {
        if (arr[i] < max)
        {
            if (!foundSecond || arr[i] > second)
            {
                second = arr[i];
                foundSecond = 1;
            }
        }
    }

    if (foundSecond)
        printf("Second-largest distinct value = %d\n", second);
    else
        printf("No second-largest distinct value exists.\n");

    for (i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            peaks++;
    }

    printf("Number of local peaks = %d\n", peaks);

    for (i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            currentRun++;
        else
            currentRun = 1;

        if (currentRun > longestRun)
            longestRun = currentRun;
    }

    printf("Longest increasing run = %d\n", longestRun);

    k = readInteger("\nEnter K for rotation: ");

    shift = k % n;

    if (shift < 0)
        shift += n;

    reverse(arr, 0, n - 1);
    reverse(arr, 0, shift - 1);
    reverse(arr, shift, n - 1);

    printf("Array after rotation: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    do
    {
        r = readInteger(
            "Enter last two registration digits (0 to 99): ");

        if (r < 0 || r > 99)
            printf("Invalid value. Try again.\n");

    } while (r < 0 || r > 99);

    d = (r % 9) + 1;

    for (i = 0; i < n; i++)
    {
        if (arr[i] % d == 0)
            divisibleCount++;
    }

    printf("D = %d\n", d);
    printf("Count divisible by D = %d\n", divisibleCount);

    return 0;
}

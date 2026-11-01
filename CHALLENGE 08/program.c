#include <stdio.h>

int readValidNumber(int min, int max)
{
    int value, ch;

    while (1)
    {
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input! Enter an integer: ");

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
        }
        else if (value < min || value > max)
        {
            printf("Out of range! Enter a value between %d and %d: ", min, max);
        }
        else
        {
            return value;
        }
    }
}

int main()
{
    int grid[6][6];
    int N, T;
    int i, j;

    int rowSum, colSum;
    int maxRowTotal = -1;
    int maxColTotal = -1;

    int maxRisk;
    int thresholdCount = 0;

    int mainDiagonal = 0;
    int secondaryDiagonal = 0;

    int boundarySum = 0;

    int hotspotCount = 0;

    printf("Enter grid size N (3 to 6): ");
    N = readValidNumber(3, 6);

    printf("\nEnter risk scores (0 to 100):\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Enter value for row %d, column %d: ", i + 1, j + 1);
            grid[i][j] = readValidNumber(0, 100);
        }
    }

    printf("\nEnter warning threshold T (1 to 100): ");
    T = readValidNumber(1, 100);

    printf("\n--- ROW TOTALS ---\n");

    for (i = 0; i < N; i++)
    {
        rowSum = 0;

        for (j = 0; j < N; j++)
        {
            rowSum = rowSum + grid[i][j];
        }

        printf("Row %d total = %d\n", i + 1, rowSum);

        if (rowSum > maxRowTotal)
        {
            maxRowTotal = rowSum;
        }
    }

    printf("Highest row total = %d\n", maxRowTotal);
    printf("Rows with highest total: ");

    for (i = 0; i < N; i++)
    {
        rowSum = 0;

        for (j = 0; j < N; j++)
        {
            rowSum = rowSum + grid[i][j];
        }

        if (rowSum == maxRowTotal)
        {
            printf("%d ", i + 1);
        }
    }

    printf("\n");

    printf("\n--- COLUMN TOTALS ---\n");

    for (j = 0; j < N; j++)
    {
        colSum = 0;

        for (i = 0; i < N; i++)
        {
            colSum = colSum + grid[i][j];
        }

        printf("Column %d total = %d\n", j + 1, colSum);

        if (colSum > maxColTotal)
        {
            maxColTotal = colSum;
        }
    }

    printf("Highest column total = %d\n", maxColTotal);
    printf("Columns with highest total: ");

    for (j = 0; j < N; j++)
    {
        colSum = 0;

        for (i = 0; i < N; i++)
        {
            colSum = colSum + grid[i][j];
        }

        if (colSum == maxColTotal)
        {
            printf("%d ", j + 1);
        }
    }

    printf("\n");

    printf("\n--- FULL GRID ANALYSIS ---\n");

    maxRisk = grid[0][0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] > maxRisk)
            {
                maxRisk = grid[i][j];
            }

            if (grid[i][j] >= T)
            {
                thresholdCount++;
            }
        }
    }

    printf("Highest risk score = %d\n", maxRisk);

    printf("Positions of highest risk score:\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == maxRisk)
            {
                printf("Row %d, Column %d\n", i + 1, j + 1);
            }
        }
    }

    printf("Cells meeting or exceeding threshold = %d\n", thresholdCount);

    printf("\n--- DIAGONAL ANALYSIS ---\n");

    for (i = 0; i < N; i++)
    {
        mainDiagonal = mainDiagonal + grid[i][i];

        secondaryDiagonal = secondaryDiagonal + grid[i][N - 1 - i];
    }

    printf("Main diagonal sum = %d\n", mainDiagonal);
    printf("Secondary diagonal sum = %d\n", secondaryDiagonal);

    if (mainDiagonal == secondaryDiagonal)
    {
        printf("Diagonal totals are BALANCED.\n");
    }
    else
    {
        printf("Diagonal totals are NOT BALANCED.\n");
    }

    printf("\n--- BOUNDARY ANALYSIS ---\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
            {
                boundarySum = boundarySum + grid[i][j];
            }
        }
    }

    printf("Boundary cell total = %d\n", boundarySum);

    printf("\n--- LOCAL HOTSPOTS ---\n");

    for (i = 1; i < N - 1; i++)
    {
        for (j = 1; j < N - 1; j++)
        {
            if (grid[i][j] > grid[i - 1][j] &&
                grid[i][j] > grid[i + 1][j] &&
                grid[i][j] > grid[i][j - 1] &&
                grid[i][j] > grid[i][j + 1] &&
                grid[i][j] >= T)
            {
                printf("Hotspot at Row %d, Column %d, Value = %d\n",
                       i + 1, j + 1, grid[i][j]);

                hotspotCount++;
            }
        }
    }

    if (hotspotCount == 0)
    {
        printf("No local hotspots found.\n");
    }
    else
    {
        printf("Total local hotspots = %d\n", hotspotCount);
    }
    
    printf("\n--- GRIDWATCH FINAL DECISION ---\n");

    if (hotspotCount > 0)
    {
        printf("CRITICAL\n");
    }
    else if (thresholdCount >= N)
    {
        printf("WARNING\n");
    }
    else
    {
        printf("NORMAL\n");
    }

    return 0;
}

#include <stdio.h>
int main() {

    float expense,total=0;
    float smalltotal=0,mediumtotal=0,largertotal=0;
    float average;
    int validcount=0,smallcount=0,mediumcount=0,largercount=0;

    while (expense != 0)
    {
        printf("enter your expenses: ");
        scanf("%f",&expense);

        if (expense < 0)
        {
            printf("invalid value\n");
        }

        else{
            validcount++;
            total = total + expense;}
if (expense < 100){

    smallcount++;
    smalltotal = smalltotal + expense;  
}

else if (expense < 500){

    mediumcount++;
    mediumtotal = mediumtotal + expense;  
}

else{
    largercount++;
    largertotal = largertotal + expense;  
}

printf("total expenses: %f\n",total);}
printf("small count: %d\n",smallcount);
printf("small total: %f\n",smalltotal);
printf("medium count: %d\n",mediumcount);
printf("medium total: %f\n",mediumtotal);
printf("larger count: %d\n",largercount);
printf("larger total: %f\n",largertotal);

if (validcount > 0)
{
    average = total / validcount;
    printf("average expenses: %f\n",average);
}
else
{
    printf("no valid expenses entered\n");
}
    return 0;
}

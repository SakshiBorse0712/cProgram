# include <stdio.h>
# include <stdlib.h>

void towerOfHanoi(int n ,char source,char helper, char destination)
{
    if(n==1)
    {
        printf("Move disc 1 from %c to %c\n",source,destination);
    }
    else
    {
        towerOfHanoi(n-1,source,destination,helper);
        printf("Move disc %d from %c to %c\n",n,source,destination);
        towerOfHanoi(n-1,helper,source,destination);
    }
}

int main()
{
    int n;
    printf("Enter number of disk:");
    scanf("%d",&n);

    towerOfHanoi(n,'A','B','C');

    return 0;
}
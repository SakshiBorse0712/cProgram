# include <stdio.h>
# include <math.h>
# include <ctype.h>

char a[100];
int top = -1;

void push(char x)
{
    a[++top] = x;
}

char pop()
{
    if(top == -1)
    {
        return 0;
    }
    else
    {
        return a[top--]; 
    }
}

int main()
{
    char exp[100];
    char *e;
    int n1,n2,n3,num;
    
    printf("Enter Expression :");
    scanf("%s",exp);
    e = exp;

    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch(*e)
            {
                case '+' : n3 = n1 + n2;
                    break;
                case '-' : n3 = n1 - n2;
                    break;
                case '*' : n3 = n1 * n2;
                    break;
                case '/' : n3 = n1 / n2;
                    break;
                case '^' : n3 = n1 ^ n2;
                    break;
                default :
                    printf("Invalid Input");
                    break;
            }
            push(n3);
        }
        e++;
    }
    printf("Answer = %d\n",pop());

    return 0;
}
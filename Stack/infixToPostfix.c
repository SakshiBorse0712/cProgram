# include <stdio.h>
# include <ctype.h>

char a[50];
int top = -1;

void push(char x)    //push function
{
    a[++top] = x;
}

char pop()   // pop function
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return a[top--];
    }
}

int priority(char x)
{
    if(x == '^')
    {
        return 3;
    }
    else if(x == '*' || x == '/')
    {
        return 2;
    }
    else if(x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[50];
    char *e,x;
    printf("Enter expression:");
    scanf("%s",exp);

    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            printf("%c",*e);
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while( (x == pop()) != '(' )
            {
                printf("%c",x);
            }
        }
        else
        {
            while(priority(a[top]) >= priority(*e))
            {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c",pop());
    }

    return 0;
}
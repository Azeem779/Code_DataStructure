#include<stdio.h>
#define MAX 100
void push(char);
char pop();
int match(char a,char b);
int stack[MAX];
int top=-1;
int main()
{
    char exp[MAX];
    int valid;
    printf("Enter the Algebric Expression : ");
    gets(exp);
    valid=check(exp);
    if(valid==1)
    {
        printf("Valid Expression.\n");
    }
    else
    {
        printf("Invalid Expression.\n");
    }
}
int check(char exp[])
{
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
            {
                push(exp[i]);
            }
        if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
        {
            if(top==-1)
            {
                printf("Right parentheses are more then left.\n");
                return 0;
            }
            else
            {
                temp=pop();
                if(!match(temp,exp[i]))
                {
                    printf("Mismatched Parentheses : ");
                    printf("%c and %c",temp ,exp[i]);
                    return 0;
                }
            }
        }
    }
    if(top==-1)
    {
        printf("Balanced Parentheses : \n");
        return 1;
    }
    else
    {
        printf("Left parentheses is more than right.\n");
        return 0;
    }
}
int match(char a,char b)
{
    if(a=='[' && b==']')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
        return 1;
    return 0;
}
void push (char item)
{
    if(top==(MAX-1))
    {
        printf("Overflow.\n");
        return ;
    }
    top=top+1;
    stack[top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("Underflow.\n");
        exit(1);
    }
    return (stack[top--]);
}

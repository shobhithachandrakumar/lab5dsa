#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main() {
    char arr[][2] = {"-", "+", "2", "*", "3", "1", "9"};
    int n=sizeof(arr)/sizeof(arr[0]);
    int stack[n];
    int top=-1;
    //prefix Evaluation
    for(int i=n-1;i>=0;i--)
    {
        if(isdigit(arr[i][0]))
        {
            stack[++top]=atoi(arr[i]);
            
        }
        else
        {
            int a=stack[top--];
            int b=stack[top--];
            int result;
            switch(arr[i][0])
            {
                case '+':
                result=a+b;
                break;
                
                case '-':
                result=a-b;
                break;
                
                case '*':
                result=a*b;
                break;
                
                case '/':
                result=a/b;
                break;
            }
            stack[++top]=result;
        }
        
    }
    printf("Result is %d",stack[top]);
    return 0;
}

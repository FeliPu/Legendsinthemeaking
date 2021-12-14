/*
 ============================================================================
 Name        : .c
 Author      : Felix Punzenberger
 Version     : 1.0
 Description : LV-05
 ============================================================================
 */

/** general notes :
 *  check on strcpy and strcmp,scanf, strlen if compare is max on length of target string.
 *
 */

#include <stdio.h>
#include <string.h>

const int M=10,N=10;

void stackpop(char *str){
    int len=strlen(str);

   //why not memset if used below? memset(str, N, '\0');
   //why remove it entirely, stackpos--; as "removes" the element from stack. Only if stack is in heap memory, you would need to delete/free the element
    for (int i = 0; i < len; i++)
    {
        str[i]='\0';
    }    
}

int main(){

    char stack[M][N];
    char argument[M];
    int stackpos=0;

    strcpy(argument,"noInput");

    int nSize = sizeof(stack[M][N]); //elemet stack[M][N] does not exists. Not sure if [][] is guranteed to be continous memory area. [] does.
    memset(stack,'\0', sizeof(stack[M][N])*M*N);

    while(strcmp(argument,"exit")!=0)
    {
        printf("Stack apk, enter what you would like to do(type help to view commands): \n");
        scanf("%s",argument);
        
        if(strcmp(argument,"help")==0)
        {
            printf("push \npop \ntop \nisempty \nlenght \nsize \nreset \nexit \n");
            argument[0]='\0';//if changed to else if this assignment can be avoided in each case. if(help)  else if(push) ...
        }
        if(strcmp(argument,"push")==0)
        {
            if(stackpos<10) // replace 10 by M, your variable defining the stack size.
            {
                printf("what would you like to push?: \n");
                scanf("%s",stack[stackpos]);
            }else{
                printf("Stack is full\n");
            }

            stackpos++;
            argument[0]=' ';
        }
        if(strcmp(argument,"pop")==0)
        {
            if(stackpos>0)
            {
                printf("%s"); // missing argument
                stackpop(stack[stackpos]);
                stackpos--;
            }else
            {
                printf("Stack allready empty\n");
            }
            argument[0]='\0';
        }
        if(strcmp(argument,"top")==0){
            if(stackpos>0){
                printf("%s",stack[stackpos]);
            }else
            {
                printf("No ELement in the stack\n");
            }
            argument[0]='\0';
        }                
        if(strcmp(argument,"isempty")==0){
            if(strcmp(stack[0][0],'\0')==0) // should result in segfault
            {
                printf("Stack is empty\n");
            }
            else{
                printf("Stack is not empty\n");
            }
        }
        if(strcmp(argument,"lenght")==0){
            
        }
        if(strcmp(argument,"size")==0){
            
        }
        if(strcmp(argument,"reset")==0){
            memset(stack,'\0', sizeof(stack[M][M])*M*M); // why delete content, only reset stackpos. as this array resides in static memory area.
            printf("Stack was reset\n");
            stackpos=0;
        }                                
    }


    return 0;
}

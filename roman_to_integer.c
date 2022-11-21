#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//rules:
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

typedef struct number{
    int data;
    int digit;
}number;

int checkdigits(int num)
{
    int counter=0;
    while(num!=0)
    {
        num/=10;
        counter++;
    }
    return counter;
}

int cheking_letter(char *str)
{
    if(*str=='I')return 1;
    if(*str=='V')return 5;
    if(*str=='X')return 10;
    if(*str=='L')return 50;
    if(*str=='C')return 100;
    if(*str=='D')return 500;
    if(*str=='M')return 1000;
    else {
        printf("\nthere is no such of this roman number!\n");
        exit(1);
    }
}



int create_counter_array(char* str)
{
    int sum=0;
    int size =strlen(str);
    number *count =(number*)malloc(sizeof(number)*size);
    for(int i=0;i<size;i++)
    {
        count[i].data=cheking_letter(str);
        count[i].digit=checkdigits(count[i].data);
        str++;
    }

    for(int i =0;i<size;i++)
    {
        if((count[i].data==1||count[i].data==10||count[i].data==100)&&count[i].data!=1000)
            {
                if(i+1==size){
                    sum+= count[i].data;
                    break;
                }
                if(count[i].digit>=count[i+1].digit-1 && count[i].data<count[i+1].data)
                {
                    sum+=count[i+1].data-count[i].data;
                    i++;
                }
                else 
                    sum+=count[i].data;

            }
        else 
            sum+=count[i].data;
    }
    free(count);
    return sum;

}




int main()
{
    char*str ="MCMXCIV";
    printf("\nnumber from roman to integer:%d\n",create_counter_array(str));

    return 0;
}


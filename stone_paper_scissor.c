#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int generateRandomNumber(int n){
srand(time(NULL));
return rand()%n;
}
int main(int argc, char const *argv[])
{int a;
char name[100];
  printf("YOU HAVE 3 CHANCES.WHOSOEVER WINS MAXIMUM ,IS THE FINAL WINNER\n\n");
    printf("ENTER YOUR NAME:\t");

        printf("\n\n");
    gets(name);





   int x=0,y=0;
    for(int i=0;i<=2;i++){

        printf("\n\n");
    printf("ENTER 0 FOR ROCK , 1  FOR PAPER AND 2 FOR SCISSORS(NOTE:COMPUTER IS COMPLETELY UNAWARE ABOUT YOUR CHOICE:\n\n");
scanf("%d",&a);
int b=generateRandomNumber(2);
printf("CHOICE ENTERED BY COMPUTER: %d\n",b);
if(a==0 && b==0)
printf("THERE IS A TIE.NO POINT TO BOTH OF YOU\n");
else if(a==0 && b==1)
{printf("COMPUTER HAS WON.1 POINT IS ALLOTTED TO COMPUTER\n");
y+=1;}
else if(a==0 && b==2)
{printf("%s HAS WON.1 POINT IS ALLOTTED TO %s\n",name,name);
x+=1;}
else if(a==1 && b==0)
{printf("%s HAS WON.1 POINT IS ALLOTTED TO %s\n",name,name);
x+=1;}

else if(a==1 && b==1)
printf("THERE IS A TIE.NO POINT TO BOTH OF YOU\n");
else if(a==1 && b==2)
{printf("COMPUTER HAS WON.1 POINT IS ALLOTTED TO COMPUTER\n");
y+=1;}


else if(a==2 && b==0)
{printf("COMPUTER HAS WON.1 POINT IS ALLOTTED TO COMPUTER\n");
y+=1;}
else if(a==2 && b==1)
{printf("%s HAS WON.1 POINT IS ALLOTTED TO %s\n",name,name);
x+=1;}
else if(a==2 && b==2)
printf("THERE IS A TIE.NO POINT TO BOTH OF YOU\n");
printf("\n\n");

}
if(x>y)
printf("%s is the winner",name);
else if(x==y)
printf("SINCE THERE IS TIE.NO ONE IS THE WINNER");
else printf("computer is the wineer");
    return 0;
}

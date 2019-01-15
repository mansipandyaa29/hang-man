#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node *next;
    char data;
} *start;
char movie[100];
int lives=5;
struct node *start=NULL;
struct node *insert(struct node *start,char val);
void display(struct node*);
int traverse(struct node*,char checkvar);
int computer_main();
void friend1(struct node *start);
void showHangman(int);
void computer(char [],struct node *start);

int main()
{
    int option;
    printf("\n\n\n          * * * * * * * * * * * * * * * * * * *\n");
    printf("          *                                   *\n");
    printf("          *           HANG-MAN GAME           *\n");
    printf("          *      1.Play with the computer     *\n");
    printf("          *      2.Play with a friend         *\n");
    printf("          *                                   *\n");
    printf("          * * * * * * * * * * * * * * * * * * *");
    printf("\n\n\nEnter Your choice:");
    scanf("%d",&option);
    switch(option){
    case 1: computer_main();
    break;
    case 2: friend1(start);
    break;
    default:printf("Invalid option");
    }
return 0;
}
int computer_main()
{
   system("cls");
    int c1;
char m1[20] = "thor";
char m2[20] = "avengers infinity";
char m3[20] = "spiderman";
char m4[20] = "taken 2";
    printf("      * * * * * * * * * * * * * * * * *\n");
    printf("      *    << COMPUTER VS PLAYER >>   *\n");
    printf("      * * * * * * * * * * * * * * * * *\n\n");
    printf(" There are 4 movie options.\n Enter your choice ");
    scanf ("%d",&c1);
    switch(c1){
    case 1: computer(m1,start);
    break;
    case 2: computer(m2,start);
    break;
    case 3: computer(m3,start);
    break;
    case 4: computer(m4,start);
    break;
    default:printf("Invalid option");
    }
    return 0;
}
void computer(char m[],struct node *start)
{
    int k,length1,p,winner;
    char checkvar,travsucc;
    length1=strlen(m);
    for(k=0;k<=length1;k++)
    {
      start = insert(start,m[k]);
    }
   char g[length1];
   g[length1]='\0';
   system
   ("cls");
   printf("    << PLAYER >> \n\n Guess the movie name\n");
   for(k=0;k<length1;k++)
    {
     g[k]='_';
    }
    for(p=0;p<length1;p++)
    {
    printf(" ");
    if (m[p]==32)
    {
        g[p]=m[p];
        printf("  %c",g[p]);
    }
    else{
        printf("%c",g[p]);
    }
    }
while(length1!='\0' && lives!=0){
printf("\nEnter your guess (any alphabet) :\n");
scanf("\n %c",&checkvar);
if(checkvar<'a' || checkvar>'z'){
    printf("Your input is invalid\n");
}
travsucc=traverse(start,checkvar);
for(k=0;k<=length1;k++)
{
 if(m[k]==travsucc)
  {
      g[k]=m[k];
  }
printf(" %c", g[k]);
       }
winner = strcmp(g,m);
if(winner == 0)
{
printf("\n\n \t  You are the WINNER !!!!!\n");
printf("       \t    << GAME OVER >>   \n\t  The entered movie was %s ",m);
break;
}
       if(lives==0){
    system("cls");
       printf("    YOU LOSE!!!! \n   << GAME OVER >>\n   The movie name was %s \n\n",m);
       printf("   The man is Dead!!\n\t||===== ");
  printf("\n\t||    | ");
 printf("\n\t||   %cO/",'\\');
 printf("\n\t||    | ");
 printf("\n\t||   / %c",'\\');
 printf("\n\t||      ");
       }
       }
}

void friend1(struct node *start){
    int i,length,j,winner;
    char checkvar,travsucc;
    system("cls");
    printf("      * * * * * * * * * * * * * * * * * *\n");
    printf("      *  << PLAYER 1 VS PLAYER 2 >>     *\n");
    printf("      * * * * * * * * * * * * * * * * * *\n\n");
    printf("PLAYER 1 : \n\nEnter the name of the movie:");
     scanf("%[^\t\n]s",&movie);
    length=strlen(movie);
    for(i=0;i<=length;i++)
    {
      start = insert(start,movie[i]);
    }
   char guess[length];
   guess[length]='\0';
   system("cls");
    printf("      * * * * * * * * * * * * * * * * * *\n");
    printf("      *  << PLAYER 1 VS PLAYER 2 >>     *\n");
    printf("      * * * * * * * * * * * * * * * * * *\n\n");
   printf("PLAYER 2 : \n\nGuess the movie name\n");
   printf("You have %d lives \n", lives);
   for(i=0;i<length;i++)
    {
     guess[i]='_';
    }
    for(j=0;j<length;j++)
    {
    printf(" ");
    if (movie[j]==32)
    {
        guess[j]=movie[j];
        printf("  %c",guess[j]);
    }
    else{
        printf("%c",guess[j]);
    }
    }
while(length!='\0' && lives!=0){
printf("\nEnter your guess (any alphabet) :\n");
scanf("\n %c",&checkvar);
if(checkvar<'a' || checkvar>'z'){
    printf("Your input is invalid\n");
}
travsucc=traverse(start,checkvar);
for(i=0;i<=length;i++)
{
 if(movie[i]==travsucc)
  {
      guess[i]=movie[i];
  }
printf(" %c", guess[i]);
       }
winner = strcmp(guess,movie);
if(winner == 0)
{
printf("\n\n \t  You are the WINNER !!!!!\n");
printf("       \t    << GAME OVER >>   \n\t  The entered movie was %s",movie);
break;
}
       if(lives==0){
    system("cls");
       printf("    YOU LOSE!!!! \n   << GAME OVER >>\n   The entered movie was %s\n\n",movie);
       printf("   The man is Dead!!\n\t||===== ");
  printf("\n\t||    | ");
 printf("\n\t||   %cO/",'\\');
 printf("\n\t||    | ");
 printf("\n\t||   / %c",'\\');
 printf("\n\t||      ");
       }
       }
       }
struct node *insert(struct node *start, char val){
        struct node *new_node,*ptr;
        length = strlen(movie);
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=val;
        if(start==NULL){
            new_node->next=NULL;
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
                ptr->next=new_node;
                new_node->next=NULL;
}
return start;
}
int traverse(struct node *start,char checkvar){
    struct node *ptr2;
    int f=0;
    ptr2=start;
    while(ptr2->next!=NULL && lives>=0){
        if(ptr2->data==checkvar){
            f=1;
            printf("That's Correct !! \n\n ");
            return checkvar;
        }
        ptr2=ptr2->next;
        } if(f==0)
            {
          --lives;
          showHangman(lives);
          return 0;
    }
}
void showHangman(int lives)
 {
     switch(lives)
     {
     case 0:
         system("cls");
 printf("\n\t||===== ");
 printf("\n\t||    | ");
 printf("\n\t||   %cO/",'\\');
 printf("\n\t||    | ");
 printf("\n\t||   / %c",'\\');
 printf("\n\t||      ");
    printf("\n\nYou guessed it wrong!\n");
 printf("You have %d lives left :( \n\n",lives);
 break;
     case 1:
         system("cls");
 printf("\n\t||===== ");
 printf("\n\t||    | ");
 printf("\n\t||   %cO/",'\\');
 printf("\n\t||    | ");
 printf("\n\t||     %c",'\\');
 printf("\n\t||      ");
  printf("\n\nYou guessed it wrong!\n");
 printf("You have %d lives left :( \n\n",lives);
 break;
     case 2:
         system("cls");
 printf("\n\t||===== ");
 printf("\n\t||    | ");
 printf("\n\t||   %cO/",'\\');
 printf("\n\t||    | ");
 printf("\n\t||      ");
 printf("\n\t||      ");
  printf("\n\nYou guessed it wrong!");
 printf("\nYou have %d lives left :( \n\n",lives);
 break;
     case 3:
         system("cls");
 printf("\n\t||===== ");
 printf("\n\t||    | ");
 printf("\n\t||   %cO/",'\\');
 printf("\n\t||      ");
 printf("\n\t||      ");
 printf("\n\t||      ");
  printf("\n\nYou guessed it wrong!");
 printf("\nYou have %d lives left :( \n\n",lives);
 break;
     case 4:
         system("cls");
 printf("\n\t||===== ");
 printf("\n\t||    | ");
 printf("\n\t||   %cO ",'\\');
 printf("\n\t||      ");
 printf("\n\t||      ");
 printf("\n\t||      ");
  printf("\n\nYou guessed it wrong!\n");
 printf("You have %d lives left :( \n\n",lives);
 break;
     case 5:
         system("cls");
 printf("\n\t||===== ");
 printf("\n\t||    | ");
 printf("\n\t||    O ");
 printf("\n\t||      ");
 printf("\n\t||      ");
 printf("\n\t||      ");
   // printf("\n\n \n !!!!! GAME OVER !!!!! \n");
 //printf("\nYou have %d lives left :( \n\n",lives);
 break;
      }
 }

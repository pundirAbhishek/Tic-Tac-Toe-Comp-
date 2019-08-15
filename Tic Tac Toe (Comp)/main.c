#include <stdio.h>
#include <stdlib.h>


void Computer_turn(int *count,int *row,int *column,char arr[][3])
{
    int comp_turn=0;

     select:
     if(*count==0)
     {

        srand(time(NULL));
        *row=rand()%3+1;
        srand(time(NULL));
        int temp=rand()%2;

       if(temp==0)
       {
          *column=*row;
       }

       else
       {
           if(*row==1)
           {
               *column=3;
           }
           else if(*row==3)
           {

               *column=1;
           }
           else
           {
              *row=3;
              *column=1;
           }
       }
        arr[*row-1][*column-1]='O';

}

     else if(*count>=1)
     {
        if(*count>=3){
        comp_turn=check(&count,&row,&column,arr);
        }
        if(comp_turn==0)
        {


            if(arr[1][1]=='-')
            {
                arr[1][1]='O';
                return;
            }

            else if(arr[0][0]=='-'||arr[0][2]=='-'||arr[2][0]=='-'||arr[2][2]=='-')
            {
                    select1:
                    srand(time(NULL));
                    *row=rand()%3+1;
                    srand(time(NULL));

                if(*row==2){
                 goto select1;
                 }
                   if(arr[*row-1][0]=='-'&&(arr[*row-1][2]=='-')){

                    if(rand()%2)
                    {
                        *column=*row;

                    }
                    else {

                        if(*row==1)
                        {
                            *column=3;

                        }
                        else if(*row==3)
                        {

                            *column=1;
                        }
                        else
                        {
                            *row=3;
                            *column=1;
                        }
                }
                arr[*row-1][*column-1]='O';
                *count++;

                   }

                else if((arr[*row-1][0]!='-'&&arr[*row-1][2]=='-')||(arr[*row-1][0]=='-'&&arr[*row-1][2]!='-')) {
                    if(arr[*row-1][0]=='-'){
                        arr[*row-1][0]='O';
                    }
                    else
                        arr[*row-1][2]='O';

                }
                else
                    goto select1;
                }

                else
                {
                    select2:
                    srand(time(NULL));
                    *row=rand()%3+1;
                    srand(time(NULL));

                    if(*row==1)
                    {
                        if(arr[*row-1][1]=='-'){
                            arr[*row-1][1]='O';
                            printf("\n\nError(1)");
                            return;
                        }
                        else
                            goto select2;
                    }
                    else if(*row==3)
                    {
                        if(arr[*row-1][1]=='-')
                        {
                            arr[*row-1][1]='O';
                            printf("\n\nError(2)");
                            return;
                        }
                        else
                            goto select2;
                    }
                    else
                    {

                            if(arr[*row-1][0]=='-')
                            {
                                arr[*row-1][0]='O';
                                return;
                            }
                            else if(arr[*row-1][2]='-')
                            {
                                arr[*row-1][2]='O';
                                return;
                            }
                            else
                                goto select2;
                    }

            }


        }

}
}



int check(int *count,int *row,int *column,char arr[][3])
{
    int end=0;
    static int condition=0;


    if((arr[0][0]=='X')&&(arr[1][1]=='O')&&(arr[2][2]=='X')&&(condition==0))
    {

         end=1;
         condition=1;
         {
                     select3:
                    srand(time(NULL));
                    *row=rand()%3+1;
                    printf("\n\nrow:%d",*row);

                    if(*row==1)
                    {
                        if(arr[*row-1][1]=='-'){
                            arr[*row-1][1]='O';
                        }
                         else
                            goto select3;
                    }


                    else if(*row==3)
                    {
                        if(arr[*row-1][1]=='-'){
                            arr[*row-1][1]='O';
                        }
                         else
                            goto select3;

                    }
                    else
                    {

                            if(rand()%2)
                            {
                                if(arr[*row-1][0]=='-'){
                                arr[*row-1][0]='O';
                                }
                                else goto select3;

                            }
                            else
                            {
                                if(arr[*row-1][2]=='-'){
                                arr[*row-1][2]='O';
                                }
                                else
                                    goto select3;

                            }

                    }

            }


    }

   else if((arr[2][0]=='X')&&(arr[1][1]=='O')&&(arr[0][2]=='X')&&(condition==0))
    {

         end=1;
         condition=1;
         {

                    srand(time(NULL));
                    *row=rand()%3+1;
                    srand(time(NULL));

                    if(*row==1)
                    {

                        if(arr[*row-1][1]=='-'){
                            arr[*row-1][1]='O';
                        }
                         else
                            goto select3;

                    }


                    else if(*row==3)
                    {
                        if(arr[*row-1][1]=='-'){
                            arr[*row-1][1]='O';
                        }
                         else
                            goto select3;

                    }
                    else
                    {

                            if(rand()%2)
                            {

                                if(arr[*row-1][0]=='-'){
                                arr[*row-1][0]='O';
                                }
                                else goto select3;


                            }
                            else
                            {
                                if(arr[*row-1][2]=='-'){
                                arr[*row-1][2]='O';
                                }
                                else
                                    goto select3;


                            }

                    }

            }


    }


if(end==1)
{
     *count++;
     return end;
}


        switch(1){

    case 1:
        if((arr[0][0]=='O')&&(arr[0][1]=='O')&&(arr[0][2]=='-')){
            *row=1;
            *column=3;
            end=1;
            break;
            }
    case 2:
        if((arr[0][0]=='O')&&(arr[0][1]=='-')&&(arr[0][2]=='O')){
            *row=1;
            *column=2;
            end=1;
             break;
            }
    case 3:
        if((arr[0][0]=='-')&&(arr[0][1]=='O')&&(arr[0][2]=='O')){
            *row=1;
            *column=1;
            end=1;
             break;
            }
    case 4:
        if((arr[1][0]=='O')&&(arr[1][1]=='O')&&(arr[1][2]=='-')){
            *row=2;
            *column=3;
            end=1;
          break;
        }

    case 5:
        if((arr[1][0]=='O')&&(arr[1][1]=='-')&&(arr[1][2]=='O')){
            *row=2;
            *column=2;
            end=1;
             break;
        }
    case 6:
        if((arr[1][0]=='-')&&(arr[1][1]=='O')&&(arr[1][2]=='O')){
            *row=2;
            *column=1;
            end=1;

             break;
        }

    case 7:
        if((arr[2][0]=='O')&&(arr[2][1]=='O')&&(arr[2][2]=='-'))  {
            *row=3;
            *column=3;
            end=1;
            break;
        }

    case 8:
        if((arr[2][0]=='O')&&(arr[2][1]=='-')&&(arr[2][2]=='O'))  {
            *row=3;
            *column=2;
            end=1;
            break;
        }

    case 9:
        if((arr[2][0]=='-')&&(arr[2][1]=='O')&&(arr[2][2]=='O'))  {
            *row=3;
            *column=1;
            end=1;
            break;
        }



    case 10:
        if((arr[0][0]=='O')&&(arr[1][0]=='O')&&(arr[2][0]=='-')){
            *row=3;
            *column=1;
            end=1;
            break;
        }

    case 11:
        if((arr[0][0]=='O')&&(arr[1][0]=='-')&&(arr[2][0]=='O')){
            *row=2;
            *column=1;
            end=1;
            break;
        }


    case 12:
        if((arr[0][0]=='-')&&(arr[1][0]=='O')&&(arr[2][0]=='O')){
            *row=1;
            *column=1;
            end=1;
            break;
        }


    case 13:
        if((arr[0][1]=='O')&&(arr[1][1]=='O')&&(arr[2][1]=='-')){
            *row=3;
            *column=2;
            end=1;
             break;
        }

    case 14:
        if((arr[0][1]=='O')&&(arr[1][1]=='-')&&(arr[2][1]=='O')){
            *row=2;
            *column=2;
            end=1;
             break;
        }

    case 15:
        if((arr[0][1]=='-')&&(arr[1][1]=='O')&&(arr[2][1]=='O')){
            *row=1;
            *column=2;
            end=1;
             break;
        }


    case 16:
        if((arr[0][2]=='O')&&(arr[1][2]=='O')&&(arr[2][2]=='-')){
            *row=3;
            *column=3;
            end=1;
            break;
        }

    case 17:
        if((arr[0][2]=='O')&&(arr[1][2]=='-')&&(arr[2][2]=='O')){
            *row=2;
            *column=3;
            end=1;
            break;
        }

    case 18:
        if((arr[0][2]=='-')&&(arr[1][2]=='O')&&(arr[2][2]=='O')){
            *row=1;
            *column=3;
            end=1;
            break;
        }


    case 19:
        if((arr[0][0]=='O')&&(arr[1][1]=='O')&&(arr[2][2]=='-')){
            *row=3;
            *column=3;
            end=1;
             break;
        }
    case 20:
        if((arr[0][0]=='O')&&(arr[1][1]=='-')&&(arr[2][2]=='O')){
            *row=2;
            *column=2;
            end=1;
             break;
        }
    case 21:
        if((arr[0][0]=='-')&&(arr[1][1]=='O')&&(arr[2][2]=='O')){
            *row=1;
            *column=1;
            end=1;
             break;
        }

    case 22:
        if((arr[0][2]=='O')&&(arr[1][1]=='O')&&(arr[2][0]=='-')){
            *row=3;
            *column=1;
            end=1;
            break;
        }

     case 23:
        if((arr[0][2]=='O')&&(arr[1][1]=='-')&&(arr[2][0]=='O')){
            *row=2;
            *column=2;
             end=1;
            break;
        }


     case 24:
        if((arr[0][2]=='-')&&(arr[1][1]=='O')&&(arr[2][0]=='O')){
            *row=1;
            *column=3;
            end=1;
            break;
        }
}

if(end==1)
{
     arr[*row-1][*column-1]='O';
     *count++;
     return end;
}

    switch(1){

    case 1:
        if((arr[0][0]=='X')&&(arr[0][1]=='X')&&(arr[0][2]=='-')){
            *row=1;
            *column=3;
            end=1;
            break;
            }
    case 2:
        if((arr[0][0]=='X')&&(arr[0][1]=='-')&&(arr[0][2]=='X')){
            *row=1;
            *column=2;
            end=1;
            break;
            }
    case 3:
        if((arr[0][0]=='-')&&(arr[0][1]=='X')&&(arr[0][2]=='X')){
            *row=1;
            *column=1;
            end=1;
            break;
            }
    case 4:
        if((arr[1][0]=='X')&&(arr[1][1]=='X')&&(arr[1][2]=='-')){
            *row=2;
            *column=3;
            end=1;
             break;
        }

    case 5:
        if((arr[1][0]=='X')&&(arr[1][1]=='-')&&(arr[1][2]=='X')){
            *row=2;
            *column=2;
            end=1;
             break;
        }
    case 6:
        if((arr[1][0]=='-')&&(arr[1][1]=='X')&&(arr[1][2]=='X')){
            *row=2;
            *column=1;
            end=1;
             break;
        }

    case 7:
        if((arr[2][0]=='X')&&(arr[2][1]=='X')&&(arr[2][2]=='-'))  {
            *row=3;
            *column=3;
            end=1;
            break;
        }

    case 8:
        if((arr[2][0]=='X')&&(arr[2][1]=='-')&&(arr[2][2]=='X'))  {
            *row=3;
            *column=2;
            end=1;
            break;
        }

    case 9:
        if((arr[2][0]=='-')&&(arr[2][1]=='X')&&(arr[2][2]=='X'))  {
            *row=3;
            *column=1;
            end=1;
            break;
        }



    case 10:
        if((arr[0][0]=='X')&&(arr[1][0]=='X')&&(arr[2][0]=='-')){
            *row=3;
            *column=1;
            end=1;
            break;
        }

    case 11:
        if((arr[0][0]=='X')&&(arr[1][0]=='-')&&(arr[2][0]=='X')){
            *row=2;
            *column=1;
            end=1;
            break;
        }


    case 12:
        if((arr[0][0]=='-')&&(arr[1][0]=='X')&&(arr[2][0]=='X')){
            *row=1;
            *column=1;
            end=1;
            break;
        }


    case 13:
        if((arr[0][1]=='X')&&(arr[1][1]=='X')&&(arr[2][1]=='-')){
            *row=3;
            *column=2;
            end=1;
             break;
        }

    case 14:
        if((arr[0][1]=='X')&&(arr[1][1]=='-')&&(arr[2][1]=='X')){
            *row=2;
            *column=2;
            end=1;
             break;
        }

    case 15:
        if((arr[0][1]=='-')&&(arr[1][1]=='X')&&(arr[2][1]=='X')){
            *row=1;
            *column=2;
            end=1;
             break;
        }


    case 16:
        if((arr[0][2]=='X')&&(arr[1][2]=='X')&&(arr[2][2]=='-')){
            *row=3;
            *column=3;
            end=1;
            break;
        }

    case 17:
        if((arr[0][2]=='X')&&(arr[1][2]=='-')&&(arr[2][2]=='X')){
            *row=2;
            *column=3;
            end=1;
            break;
        }

    case 18:
        if((arr[0][2]=='-')&&(arr[1][2]=='X')&&(arr[2][2]=='X')){
            *row=1;
            *column=3;
            end=1;
            break;
        }


    case 19:
        if((arr[0][0]=='X')&&(arr[1][1]=='X')&&(arr[2][2]=='-')){
            *row=3;
            *column=3;
            end=1;
             break;
        }
    case 20:
        if((arr[0][0]=='X')&&(arr[1][1]=='-')&&(arr[2][2]=='X')){
            *row=2;
            *column=2;
            end=1;
             break;
        }
    case 21:
        if((arr[0][0]=='-')&&(arr[1][1]=='X')&&(arr[2][2]=='X')){
            *row=1;
            *column=1;
            end=1;
             break;
        }

    case 22:
        if((arr[0][2]=='X')&&(arr[1][1]=='X')&&(arr[2][0]=='-')){
            *row=3;
            *column=1;
            end=1;
            break;
        }

     case 23:
        if((arr[0][2]=='X')&&(arr[1][1]=='-')&&(arr[2][0]=='X')){
            *row=2;
            *column=2;
            end=1;
            break;
        }


     case 24:
        if((arr[0][2]=='-')&&(arr[1][1]=='X')&&(arr[2][0]=='X')){
            *row=1;
            *column=3;
            end=1;
            break;
        }


}
if(end==1)
{
     arr[*row-1][*column-1]='O';
     *count++;
}
return end;

}



int winner (int*count, char arr[][3]){
    int end=0;

if ((*count)>=5)
    {

    switch(1){

    case 1:
        if((arr[0][0]==arr[0][1])&&(arr[0][1]==arr[0][2])&&(arr[0][0]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
            }
    case 2:
        if((arr[1][0]==arr[1][1])&&(arr[1][1]==arr[1][2])&&(arr[1][1]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }
    case 3:
        if((arr[2][0]==arr[2][1])&&(arr[2][1]==arr[2][2])&&(arr[2][1]=='X'))  {
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }

    case 4:
        if((arr[0][0]==arr[1][0])&&(arr[1][0]==arr[2][0])&&(arr[0][0]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }

    case 5:
        if((arr[0][1]==arr[1][1])&&(arr[1][1]==arr[2][1])&&(arr[1][1]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }

    case 6:
        if((arr[0][2]==arr[1][2])&&(arr[1][2]==arr[2][2])&&(arr[2][2]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }

    case 7:
        if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2])&&(arr[1][1]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }

    case 8:
        if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0])&&(arr[1][1]=='X')){
            printf("\nPlayer 1 won.");
            end=1;
            break;
        }




    switch(1){

    case 1:
         if((arr[0][0]==arr[0][1])&&(arr[0][1]==arr[0][2])&&(arr[0][0]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
            }
    case 2:
        if((arr[1][0]==arr[1][1])&&(arr[1][1]==arr[1][2])&&(arr[1][1]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }
    case 3:
         if((arr[2][0]==arr[2][1])&&(arr[2][1]==arr[2][2])&&(arr[2][1]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }

    case 4:
         if((arr[0][0]==arr[1][0])&&(arr[1][0]==arr[2][0])&&(arr[0][0]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }

    case 5:
       if((arr[0][1]==arr[1][1])&&(arr[1][1]==arr[2][1])&&(arr[1][1]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }

    case 6:
        if((arr[0][2]==arr[1][2])&&(arr[1][2]==arr[2][2])&&(arr[2][2]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }

    case 7:
       if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2])&&(arr[1][1]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }

    case 8:
         if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0])&&(arr[1][1]=='O')){
            printf("\nComputer won.");
            end=1;
            break;
        }

    }

}

}
return end;
}



int main()
{

    int i,j,row,column ,toss,count=0,end;
    char ch1='X',ch2='O',arr[3][3];
    char player1[30];

        printf("\nEnter your name: ");
        gets(player1);

        printf("\n\n");
        for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++){

                    arr[i][j]='-';
                     printf("\t");
                    printf("%c",arr[i][j]);
                }
                printf("\n\n");
            }



        printf("\nPlayer 1 (%s) : X",player1);
        printf("\nComputer :O");


      srand(time(NULL));
      toss=rand()%2;

        if(toss==1){
            printf("\n\n%s got the first turn..",player1);


        }
        else{
            printf("\n\nComputer got the first turn...");
            goto up1;
        }

         while(1){
         up:
         fflush(stdin);
         printf("\n\n\nPlayer 1");
         printf("\n\nEnter the row no where you want to insert .");
         scanf("%d",&row);
         printf("Enter the column no where you want to insert .");
         scanf("%d",&column);

            if((row>=1&&row<=3)&&(column>=1&&column<=3)){

                if (arr[row-1][column-1]=='-'){
                arr[row-1][column-1]='X';                count++;
                printf("\n");

                for(i=0;i<3;i++)
                {
                for(j=0;j<3;j++){
                    printf("\t");
                    printf("%c",arr[i][j]);
                }
                 printf("\n\n");
            }
            }
                else{
                printf("\nLocation already filled");
                goto up;

            }


         }
         else{
            printf("\n\nInvalid Value..");
            goto up;

         }
        end = winner(&count,arr);
         if(end==1){
            printf("\n\nGame Over..\n\n\n");
            break;

        }

        if(count==9&&end==0){
            printf("\n\nMatch Drawn...");
            printf("\n\nGame Over..\n\n\n");
            break;
         }


         up1:
         fflush(stdin);
         printf("\n\n\nComputer\n");
         Computer_turn(&count,&row,&column,arr);

     printf("\n");

            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++){
                    printf("\t");
                    printf("%c",arr[i][j]);
                }
                 printf("\n\n");
            }
            count++;
        end = winner(&count,arr);
        if(end==1){
            printf("\n\nGame Over..\n\n\n");
            break;

        }
        if(count==9&&end==0){
            printf("\n\nMatch Drawn....");
            printf("\n\nGame Over..\n\n\n");
            break;

        }
}
  return 0;
}



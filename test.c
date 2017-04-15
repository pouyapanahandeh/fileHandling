#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

// int main(int argc,char* argv[]){
//     getTime();
// }

/* programm check list 
   
   1  - number one is ok.
   2  - number two is ok.
   3  - number three is ok.
   4  - number four is ok.
   5  - number five is ok.




*/

int main(){

    //user data
    char userName[50];
    char password[50];
    char option;
    char ans;


    /* Time for adding to file creaton and file deleting */
    time_t current_time;
    char* c_time_string;
    
   
    /* create file and  open file */
    FILE *fp;   
    char fName[20];

    /* user input */
    int selection;


    /* opening and reading file variable */
    FILE * pFile;
    char mystring [1000];
    char filename[20];

    /* the number of lines */
    //FILE *fp;
    char ch;
    int linesCount=0;
    char FILENAME[20];

    /* the lines deletation */
    FILE *fileptr1, *fileptr2;
    //char filenames[40];
    //char ch;
    int delete_line, temp = 1;

    //add question and answer in file 
    char question[1000];
    char questions[1000];
    char answerOne[1000];
    char answerTwo[1000];
    char answerThree[1000];
    char answerFour[1000];

    FILE *f;

    //delete file 

    int status;
    char file_name[25];

   
   // printf("\nPlease Enter Username (up to 50 characters): \n");
   // fgets (userName, 50, stdin);
   // printf("\nWelcome Dear %sPlease Choose  Password (up to 50 characters).\n", userName);
   // fgets (password, 50, stdin);
   // printf("\nYour password Set Up Successfully.\n");


    printf("\nWelcome to Hungarian National Club file Handling System.\n");
    printf("please select from menue.");
    
    menue:
    
    printf("\n1 - create file.\n2 - open file.\n3 - the number of line.\n4 - Delete line of Data.\n5 - Add time to your file.\n6 - write in file.\n7 - Delete File.\n8 - EXIT.\nyou choose : \t");
    scanf("%i",&selection);
    printf("\n%i is choosen\n", selection);
    

    /* Create File */
    
    if (selection == 1){

    printf("\nEnter file name to create : \t");
    scanf(" %s",fName);
 
    fp=fopen(fName,"w");
    

    
    if(fp==NULL)
    {
        printf("File does not created!\n");
        goto menue;
    }
 
    printf("File created successfully.\n");
    goto menue;

    }

    /* open file */

    else if (selection == 2){

        printf("please enter file name to open.\nfile name : \t");
        scanf(" %s",filename);

        // pFile = fopen (fileName , "r");
        // if (pFile == NULL) perror ("\nError opening file.\n");
        // else {
        //   if (fgets (mystring , 1000 , pFile) != NULL )
            
        //         puts (mystring);
        //         fclose (pFile);
        // }

        FILE *file = fopen ( filename, "r" );
        if ( file != NULL )
        {
           char line [ 850 ]; 
           while ( fgets ( line, sizeof line, file ) != NULL )
           {
              fputs ( line, stdout ); 
           }
           fclose ( file );
           goto menue;
        }
        else
        {
           perror ( filename ); 
           goto menue;
        }
    }

    /* the number of line */
    else if (selection == 3) {

        printf("\nplease enter the name of file.\nfile name : \t");
        scanf(" %s",FILENAME);

        fp=fopen(FILENAME,"r");
        if(fp==NULL)
        {
            printf("File \"%s\" does not exist!!!\n",FILENAME);
            return -1;
            goto menue;
        }
    
        //read character by character and check for new line    
        while((ch=fgetc(fp))!=EOF)
        {
            if(ch=='\n')
                linesCount++;
        }
        
        //close the file
        fclose(fp);
        
        //print number of lines
        printf("Total number of lines are: %d\n",linesCount); 
        goto menue;  

    }

    /* delete line from file */

    else if (selection == 4){

        printf("Enter file name: ");
        scanf("%s", filename);
        //open file in read mode
        fileptr1 = fopen(filename, "r");
        ch = getc(fileptr1);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fileptr1);
        }
        //rewind
        rewind(fileptr1);
        printf(" \nEnter line number of the line to be deleted:");
        scanf("%d", &delete_line);
        //open new file in write mode
        fileptr2 = fopen("replica.c", "w");
        ch = getc(fileptr1);
        while (ch != EOF)
        {
            ch = getc(fileptr1);
            if (ch == '\n')
                temp++;

                if (temp != delete_line)
                {
                    putc(ch, fileptr2);
                }
        }
        fclose(fileptr1);
        fclose(fileptr2);
        remove(filename);
        
        rename("replica.c", filename);
        printf("\nThe contents of file after being modified are as follows:\n\n");
        fileptr1 = fopen(filename, "r");
        ch = getc(fileptr1);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fileptr1);
        }
        fclose(fileptr1);
        goto menue;
        }

        else if (selection == 5){

            printf("\nplease enter the name of file.\nfile name : \t");
            scanf(" %s",FILENAME);

            FILE* fp = fopen(FILENAME,"a+");
            struct timeval usec_time;
            time_t now = time(0);
            gettimeofday(&usec_time,NULL);
            // format time
            struct tm *current = localtime(&now);
            printf("%d:%d:%d\n",current->tm_hour, current->tm_min, current->tm_sec);
            fprintf(fp,"%d:%d:%d\n",current->tm_hour, current->tm_min, current->tm_sec);
            goto menue;
        }

        else if (selection == 6){
   
           
            

            printf("\nplease enter the name of file.\nfile name : \t");
            scanf(" %s",FILENAME);

           
            f = fopen(FILENAME, "a+");

            printf("\nType first question: ");
            //scanf(" %s", question);
            //printf("\n");
            fgets (question, 1000, stdin);
            fprintf(f, "%s",question);

            printf("\nQuestion : ");
            //scanf(" %s", answerOne);
            fgets (questions,1000,stdin);
            fprintf(f, "%s",questions);

            
            printf("\nType first answer: ");
            //scanf(" %s", answerTwo);
            fgets (answerOne,1000,stdin);
            fprintf(f, "%s",answerOne);


            printf("\nType second answer: ");
            //scanf(" %s", answerThree);
            fgets (answerTwo,1000,stdin);
            fprintf(f, "%s",answerTwo);


            printf("\nType third answer: ");
            //scanf(" %s", answerFour);
            fgets (answerThree,1000,stdin);
            fprintf(f, "%s",answerThree);

            printf("\nType fourth answer: ");
            //scanf(" %s", answerFour);
            fgets (answerFour,1000,stdin);
            fprintf(f, "%s",answerFour);

            //fprintf(f, " %s %s %s %s %s ", question,answerOne,answerTwo,answerThree,answerFour);

            fclose(f);
            goto menue;


        }

        else if (selection == 7){

            printf("are you SURE (y/n) ?  : \t");
            scanf(" %c", &ans);

            if ( ans == 'y' || ans == 'Y'){



            printf("Enter the name of file you wanna delete\n");
            scanf(" %s",file_name);
    
            status = remove(file_name);
    
            if( status == 0 ){    
                printf("%s file deleted successfully.\n",file_name);
                goto menue;
                }    
            else
            {    
                printf("Unable to delete the file\n");
                perror("Error");    
                goto menue;
            }

            }

            else {

                goto menue;
            }



        }


        else if (selection == 8){

            exit(0);
        }


 

    return 0;
}
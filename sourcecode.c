#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int roll;
    char symbol[20];
    char subject[20];  //course name 
    long long int contact;
}info;

void write_to_csv(FILE* file,info a[],int n)        //function to write in csv file
{
    for(int i=0;i<n;i++)
    {
        fprintf(file, "%s,%d,%s,%s,%lld\n",a[i].symbol,a[i].roll,a[i].name,a[i].subject,a[i].contact);
    }
    printf("\033[0;32m");
    printf("\n********************** New Information are Sucessfully stored ************************\n\n");
    printf("\033[0m");
    
}

int search(char x[],int a)              //search function
{
    FILE * stream_file = fopen("data.csv", "r");
    if(!stream_file) {
        printf("There was an error reading the file.\n");
        return 0;
    }
    char line[100];
    char * save_store;
    int row_count=0;
    while(fgets(line,100,stream_file))              //checks the first data stored in csv file
    {
        char *tline = strdup(line);
        save_store = strtok(tline,",");
        if(strcmp(save_store,x)!=0)            //if symbol number does not match
        {
            row_count++;
            continue;
        }

        else if(strcmp(save_store,x)==0)                 //if symbol number matches
        {
            fclose(stream_file);
            return row_count;
        }
    }
    
    fclose(stream_file);
    return 0;
}

int main()
{   
    start:
    printf("\e[1;1H\e[2J");       //clear screen
    
    int command,nos;             //nos = number of students
    char x[12];
    printf("\033[0;32m");
    printf("************************* HOME PAGE *************************\n\n");
    printf("\033[0m");
    
    printf("\033[0;33m");
    printf("Please input the command of your wish : ");
    printf("\033[0;m");
    printf("\033[0;36m");
    printf("\n1) Store Information \n2) Search Information \n3) Delete Information \n4) Exit\n");
    printf("\033[0;m");
    scanf("%d",&command);



    if(command == 1)        //command for storing information
    {
        repeat_storing:
        printf("\e[1;1H\e[2J"); 
        printf("\033[0;32m"); 
        printf("******************** STORING TERMINAL ********************");
        printf("\033[0m");
        printf("\033[0;36m");
        printf("\n\nEnter the number of students : ");
        printf("\033[0m");
        scanf("%d",&nos);

    info a[nos];
    int reply_storing;
    
    for(int i=0;i<nos;i++)            //storing information
    {
        getchar();
        printf("\033[0;36m");
        printf("\nfor student %d : ",i+1);
        printf("\033[0m");

        printf("\033[0;36m");
        printf("\nName : ");
        printf("\033[0m");
        gets(a[i].name);

        printf("\033[0;36m");
        printf("Roll No : ");
        printf("\033[0m");
        scanf("%d",&a[i].roll);

        printf("\033[0;36m");
        printf("Symbol No : ");
        printf("\033[0m");
        scanf("%s",a[i].symbol);
        getchar();

        printf("\033[0;36m");
        printf("Major Subject : ");
        printf("\033[0m");
        gets(a[i].subject); 

        printf("\033[0;36m");
        printf("Contact Number : ");
        printf("\033[0m");
        scanf("%lld",&a[i].contact);
    }
    printf("\033[0;33m");
    printf("\n\nDo you want the information to be stored : ");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("\n1)YES \n2)NO \n3)EXIST WITHOUT SAVING INFORMATION \n");
    printf("\033[0m");
    scanf("%d",&reply_storing);

    switch(reply_storing)
    {
        case 1:
                    printf("\e[1;1H\e[2J");
                    FILE * csv_file = fopen("data.csv", "a");
                    if(!csv_file) {
                        printf("There was an error reading the file.");
                        break;
                    }
                    write_to_csv(csv_file,a,nos);
                    fclose(csv_file);
            goto start;

        case 2:
            goto repeat_storing;
        
        case 3:
            goto start;
    }
    }
  


    if(command == 2)        //command for searching information
    {   
        printf("\e[1;1H\e[2J"); 
        printf("\033[0;32m");
        printf("******************** SEARCH TERMINAL ********************\n\n");
        printf("\033[0m"); 

        int check=0;
        printf("\033[0;36m");
        printf("\nEnter Symbol No to see details : ");
        printf("\033[0m");
        scanf("%s",x);                                      //x=Symbol number  
            
        FILE * print_file = fopen("data.csv", "r");
        if(!print_file)
        {
            printf("There was an error reading the file.\n");
            return 0;
        }

        char line[100];
        int row_count = 0,field_count=0;
        while(fgets(line, 100, print_file)) 
        {
            char *tline = strdup(line);
            char *templine =strdup(line);
            char *token,*temp;
            temp = strtok(templine, ",");
            if(strcmp(temp,x)==0)
            {
                check++;
                for((token = strtok(tline, ",")); token && *token; token = strtok(NULL, ",")) 
                {
                    switch(field_count)
                    {
                        case 0:
                            printf("\033[0;32m");
                            printf("\nSYMBOL NUMBER  : %s",token);
                            printf("\033[0m");
                            break;

                        case 1: 
                            printf("\033[0;32m");
                            printf("\nROLL NUMBER    : %d",atoi(token));
                            printf("\033[0m");
                            break;

                        case 2:
                            printf("\033[0;32m");
                            printf("\nNAME           : %s",token);
                            printf("\033[0m");
                            break;

                        case 3:
                            printf("\033[0;32m");
                            printf("\nCOURSE         : %s",token);
                            printf("\033[0m");
                            break;
                        
                        case 4:
                            printf("\033[0;32m");
                            printf("\nCONTACT NUMBER : %s",token);
                            printf("\033[0m");
                            printf("\n\n");
                            break;
                    }
                    field_count++;   
                }
            }   
            free(tline);
        }   
        fclose(print_file);
        if(check==0)
        {
           printf("\033[0;31m");               
            printf("\nThe given symbol number does not match with any symbol number stored in the database.");
            printf("\n---------------------------------PLEASE TRY AGAIN---------------------------------\n\n");
            printf("\033[0m");
        }
    }



    if(command == 3)        //command for deleting information
    {
        printf("\e[1;1H\e[2J");
        printf("\033[0;32m");
        printf("----------------------------------- Deleting Terminal -----------------------------------");
        printf("\033[0m");
        int ctr=0;
        char lno[13];
        FILE *fptr1, *fptr2;    //fptr1 for data.csv & fptr2 for temp.csv
        char fname[10];         //store "data.csv"
        char temp[10];          //store "temp.csv"

        printf("\033[0;36m");
        printf("\n\nEnter the symbol number you want to remove record of : ");
        printf("\033[0m");
        scanf("%s", lno);

        int result=0;
        printf("\033[0;33m");
        printf("\n\nDo you want to delete the information stored for symbol number %s : ",lno);
        printf("\033[0m");
        printf("\033[0;36m");
        printf("\n1) YES\n2) NO\n");
        printf("\033[0m");
        scanf("%d",&result);

        if(result == 2)
        {
            printf("\033[0;31m"); 
            printf("\n------------------ The process to delete the information was terminated ------------------\n\n");
            printf("\033[0m"); 
            return 0;
        }

        else if(result <=0 || result>2)
        {
            printf("\033[0;31m"); 
            printf("\n\n------------------ INVALID COMMAND ------------------");
            printf("\033[0m"); 
        }
        else
        {
            int check=search(lno,13);
            if(check==0)
            {
                printf("\033[0;31m");               //Set the text to the color red
                printf("\nThe given symbol number does not match with any symbol number stored in the database.");
                printf("\n---------------------------------PLEASE TRY AGAIN---------------------------------\n\n");
                printf("\033[0m");                 //Resets the text to default color
                fclose(fptr1);
                fclose(fptr2);
            }   

            else 
            {

                fptr1 = fopen("data.csv", "r");
                if(!fptr1)
                {
                printf("There was an error reading the file!");
                }

                fptr2 = fopen("temp.csv", "w");
                if(!fptr2)
                {
                printf("Unable To Open A Temporary File");
                fclose(fptr1);
                }
            
                char str[100];
                while(!feof(fptr1)) 
                {
                    fgets(str, 100, fptr1);
                    if(!feof(fptr1))
                    {
                    if(ctr != check)
                    {
                    fprintf(fptr2, "%s", str);
                    }
                    ctr++;
                }
            }

            fclose(fptr1);
            fclose(fptr2);
            remove("data.csv");
            rename("temp.csv", "data.csv");

            printf("\e[1;1H\e[2J");
            printf("\033[0;32m");
            printf("Deleted symbol number : %s.\n\n\n", lno);
            printf("\033[0m");
            }
        }
    }



    if(command == 4)            //command for exit
    {
        printf("\e[1;1H\e[2J");
        return 0;
    }
          
}
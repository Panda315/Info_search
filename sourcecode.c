#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int roll;
    char symbol[20];
    char subject[20];              //course name 
    long long int contact;
}info;

void write_to_csv(FILE* file,info a[],int n)        //function to write in csv file
{
    for(int i=0;i<n;i++)
    {
        fprintf(file, "%s,%d,%s,%s,%lld\n",a[i].symbol,a[i].roll,a[i].name,a[i].subject,a[i].contact);
    }
    printf("\nNew Information are Sucessfully stored.\n\n");
    
}

int search(char x[],int a)              //search function
{
    FILE * stream_file = fopen("data.csv", "r");
    if(!stream_file) {
        printf("There was an error reading the file.\n");
        return 0;
    }
    char save_store[13];
    int row_count=0;
    while(fgets(save_store,13,stream_file))              //checks the first data stored in csv file
    {
        if(row_count==0)
        {
            row_count++;
            continue;
        }

        else if(strcmp(save_store,x)!=0)            //if symbol number does not match
        {
            row_count++;
            continue;
        }

        else if(!strcmp(save_store,x))                 //if symbol number matches
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
    
    printf("Please input the command of your wish : ");
    printf("\n1) Store Information \n2) Search Information \n3) Delete Information \n4) Exit\n");
    scanf("%d",&command);

    if(command == 1)        //command for storing information
    {
        repeat_storing:
        printf("\e[1;1H\e[2J");  
        printf("******************** STORING TERMINAL ********************");
        printf("\n\nEnter the number of students : ");
        scanf("%d",&nos);

    info a[nos];
    int reply_storing;
    
    for(int i=0;i<nos;i++)            //storing information
    {
        getchar();
        printf("\nfor student %d : ",i+1);
        printf("\nName : ");
        gets(a[i].name);
        printf("Roll No : ");
        scanf("%d",&a[i].roll);
        printf("Symbol No : ");
        scanf("%s",a[i].symbol);
        getchar();
        printf("Major Subject : ");
        gets(a[i].subject); 
        printf("Contact Number : ");
        scanf("%lld",&a[i].contact);
    }
    printf("\n\nDo you want the information to be stored : \n1)YES \n2)NO \n3)EXIST WITHOUT SAVING INFORMATION \n");
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
        int check=0;
        printf("\nEnter Symbol No to see details : ");
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
                            printf("\nSYMBOL NUMBER  : %s",token);
                            break;

                        case 1: 
                            printf("\nROLL NUMBER    : %d",atoi(token));
                            break;

                        case 2:
                            printf("\nNAME           : %s",token);
                            break;

                        case 3:
                            printf("\nCOURSE         : %s",token);
                            break;
                        
                        case 4:
                            printf("\nCONTACT NUMBER : %s",token);
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
            printf("\nThe given symbol number does not match with any symbol number stored in the database.");
            printf("\n---------------------------------PLEASE TRY AGAIN---------------------------------\n\n");
        }
    }

    if(command == 3)        //command for deleting information
    {
    }

    if(command == 4)            //command for exit
    {
        printf("\e[1;1H\e[2J");
        return 0;
    }
    
    
        
}
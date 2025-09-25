// This version of the app has limited space for 100 contact data, and each data has fixed
// space for firsname and lasname characters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char firstName[50];
    char lastName[50];
    char number[15];
} User;

User users[100];

void firstMenue(int *c);
void addNewContact(int *count);
void searchContact(int *count);
void allContacts(int *count);

int main(){
    int c;
    int count = 0;
    int running = 1;
    while(running)
    {
        firstMenue(&c);
        if(c == 1) addNewContact(&count);
        else if(c == 2) searchContact(&count);
        else if(c == 3) allContacts(&count);
        else running = 0;
    }
    printf("Goodby\n");
    return 0;
}
void firstMenue(int *c){ 
    printf("Please enter the number of your desire action: \n");
    printf("    Enter new contact: 1\n");
    printf("    Search for a contact: 2\n");
    printf("    See all contacts: 3\n");
    printf("    Exit the app: 4\n");
    printf("What do you want? ");
    scanf("%d", c);
    printf("------------------------------\n");
}
void addNewContact(int *count){
    if(*count == 99 ){
        printf("You have reached the maximum of the memory");
        return;
    }else{
        printf("Please enter the requied information : \n");
        printf("First name : ");
        scanf("%49s",users[*count].firstName);
        printf("\n");
        printf("Last name : ");
        scanf("%49s",users[*count].lastName);
        printf("\n");
        printf("Number : ");
        scanf("%14s",users[*count].number);
        printf("\n");
        printf("New user is created successfully.\n");
        (*count)++;
    }
    
};
char *toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char) str[i]);
    }
    return str;
}
void searchContact(int *count){
    char lastName_search[50];
    int index = 0;
    int found = 0;
    char temp_lastName_search[50];
    char temp_lastName[50];
   
    printf("Please enter the last name : \n");
    scanf("%s",lastName_search);
    strcpy(temp_lastName_search,lastName_search);
    toUpperCase(temp_lastName_search);
    for(index = 0; index < (*count); index++)
    {
        strcpy(temp_lastName,users[index].lastName);
        toUpperCase(temp_lastName);
        if(strcmp(temp_lastName,temp_lastName_search) == 0){
            printf("Result for %s:\n", lastName_search);
            printf("the firstname is : %s \n", users[index].firstName);
            printf("the lastname is : %s \n", users[index].lastName);
            printf("the number is : %s \n", users[index].number);
            printf("---------------------------------------------\n");
            found = 1;
        }
    }
    if(found == 0) {
        printf("There is no contact info for %s .\n" , toUpperCase(lastName_search));
        printf("---------------------------------------------\n");
    }
};
void allContacts(int *count){
    int index = 0;
    if(*count == 0) {
        printf("The phonebook is empty.\n");
    }
    for(index = 0; index < (*count); index++)
    {
        printf("the firstname is : %s \n", users[index].firstName);
        printf("the lastname is : %s \n", users[index].lastName);
        printf("the number is : %s \n", users[index].number);
        if(index != (*count -1)) printf("---------------------------------------------\n");
    }
    printf("---------------------------------------------\n");
};

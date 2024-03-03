#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define MAX_PASSWORD_LENGTH 20

struct user
{
    char phone[10];
    char ac[16];
    char password[16];
    float balance;
};

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int i = 0;
    char ch;
    struct user user, usr;
    char filename[50], phone[50], phone2[50];
    FILE *fp, *fptr;
    int opt, choice;
    int amount;
    int lamount;
    char cont = 'y';
    int valid = 0;
    printf("\nWhat do you want to do?");
    printf("\n\n1.Register your account");
    printf("\n2.Login to your account");

    printf("\n\nPlease enter your choice:\t");
    scanf("%d", &opt);
    if (opt == 1)
    {
        system("cls");
        printf("\nEnter your account number:\t");
        scanf("%s", user.ac);
        printf("Enter your phone number:\t");
        scanf("%s", user.phone);

        while (!valid)
        {

            printf("Enter password: ");
            while (1)
            {
                ch = getch();
                if (ch == '\r')
                { // Enter key pressed
                    password[i] = '\0';
                    break;
                }
                else if (ch == 127)
                { // Backspace key pressed
                    if (i > 0)
                    {
                        i--;
                        printf("\b \b");
                    }
                }
                else if (i < MAX_PASSWORD_LENGTH - 1)
                {
                    password[i] = ch;
                    i++;
                    printf("*");
                }
            }

            int length = strlen(password);
            int has_alpha = 0;
            int has_digit = 0;
            int has_special = 0;
            int has_space = 0;

            for (int i = 0; i < length; i++)
            {
                char c = password[i];
                if (isalpha(c))
                {
                    has_alpha = 1;
                }
                else if (isdigit(c))
                {
                    has_digit = 1;
                }
                else if (isspace(c))
                {
                    has_space = 1;
                }
                else
                {
                    has_special = 1;
                }
            }

            if (length < 8 || length > 20)
            {
                printf("Password must be between 8 and 20 characters long.\n");
            }
            else if (!has_alpha)
            {
                printf("Password must contain at least one alphabet.\n");
            }
            else if (!has_digit)
            {
                printf("Password must contain at least one digit.\n");
            }
            else if (!has_special)
            {
                printf("Password must contain at least one special character.\n");
            }
            else if (has_space)
            {
                printf("Password cannot contain spaces.\n");
            }
            else
            {
                valid = 1;
                strcpy(user.password, password);
                printf("Strong Password\n");
            }
        }
        user.balance = 0;
        stpcpy(filename, user.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&user, sizeof(user), 1, fp);
        if (fwrite != 0)
        {
            printf("Succesfully registered");
        }
    }
    else if (opt == 2)
    {
        system("cls");
        printf("\nPhone No.:\t");
        scanf("%s", phone);
        printf("Password:\t");
        while (1)
        {
            ch = getch();
            if (ch == '\r')
            { // Enter key pressed
                password[i] = '\0';
                break;
            }
            else if (ch == 127)
            { // Backspace key pressed
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (i < MAX_PASSWORD_LENGTH - 1)
            {
                password[i] = ch;
                i++;
                printf("*");
            }
        }
        fp = fopen(strcat(phone, ".dat"), "r");
        if (fp == NULL)
            printf("Account number not registered");
        else
        {
            fread(&user, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(password, user.password))
            {
                while (cont == 'y')
                {
                    system("cls");
                    printf("\n\tWelcome %s", user.phone);
                    printf("\nPress 1 for balance inquiry");
                    printf("\nPress 2 for adding fund");
                    printf("\nPress 3 for cash withdraw");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for changing password");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("Your current balance is Rs. %.2f", user.balance);
                        break;

                    case 2:
                        system("cls");
                        printf("Enter amount to be added:\t");
                        scanf("%d", &amount);
                        user.balance += amount;
                        fp = fopen(phone, "w");
                        fwrite(&user, sizeof(struct user), 1, fp);
                        if (fwrite != 0)
                            printf("\n\nYou have depostied Rs.%d", amount);
                        fclose(fp);
                        break;

                    case 3:
                        system("cls");
                        printf("Enter withdrawl amount:\t");
                        scanf("%d", &amount);
                        if (amount > user.balance)
                            printf("\nSorry insufficeint balance");
                        else
                        {
                            user.balance -= amount;
                            fp = fopen(phone, "w");
                            fwrite(&user, sizeof(struct user), 1, fp);
                            if (fwrite != 0)
                                printf("\n\nYou have withdrawn Rs.%d", amount);
                            fclose(fp);
                        }
                        break;
                        // online money transfer
                    case 4:
                        printf("Please enter the phone number to trasnfer balance:\t");
                        scanf("%s", phone);
                        printf("Enter the amount to transfer:\t");
                        scanf("%d", &amount);
                        if (amount > user.balance)
                            printf("\nSorry insufficent balance");
                        else
                        {
                            fptr = fopen(strcat(phone, ".dat"), "r");
                            if (fptr == NULL)
                                printf("Sorry number is not registered");
                            else
                            {
                                fread(&usr, sizeof(struct user), 1, fptr);
                                fclose(fptr);

                                usr.balance += amount;

                                fptr = fopen(phone, "w");
                                fwrite(&usr, sizeof(struct user), 1, fptr);
                                if (fwrite != 0)
                                {

                                    printf("Your trasfer is completed. You have trasnfered Rs.%d to %s", amount, usr.phone);
                                    fclose(fptr);
                                    user.balance -= amount;
                                    strcpy(filename, user.phone);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    fwrite(&user, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                        }
                        break;
                    case 5:
                        printf("\n\nPlease enter your old password:\t");
                        scanf("%s", password);
                        if (!strcmp(password, user.password))
                        {
                            printf("\n\nPlease enter your new password:\t");
                            while (!valid)
                            {

                                printf("Enter password: ");
                                while (1)
                                {
                                    ch = getch();
                                    if (ch == '\r')
                                    { // Enter key pressed
                                        password[i] = '\0';
                                        break;
                                    }
                                    else if (ch == 127)
                                    { // Backspace key pressed
                                        if (i > 0)
                                        {
                                            i--;
                                            printf("\b \b");
                                        }
                                    }
                                    else if (i < MAX_PASSWORD_LENGTH - 1)
                                    {
                                        password[i] = ch;
                                        i++;
                                        printf("*");
                                    }
                                }

                                int length = strlen(password);
                                int has_alpha = 0;
                                int has_digit = 0;
                                int has_special = 0;
                                int has_space = 0;

                                for (int i = 0; i < length; i++)
                                {
                                    char c = password[i];
                                    if (isalpha(c))
                                    {
                                        has_alpha = 1;
                                    }
                                    else if (isdigit(c))
                                    {
                                        has_digit = 1;
                                    }
                                    else if (isspace(c))
                                    {
                                        has_space = 1;
                                    }
                                    else
                                    {
                                        has_special = 1;
                                    }
                                }

                                if (length < 8 || length > 20)
                                {
                                    printf("Password must be between 8 and 20 characters long.\n");
                                }
                                else if (!has_alpha)
                                {
                                    printf("Password must contain at least one alphabet.\n");
                                }
                                else if (!has_digit)
                                {
                                    printf("Password must contain at least one digit.\n");
                                }
                                else if (!has_special)
                                {
                                    printf("Password must contain at least one special character.\n");
                                }
                                else if (has_space)
                                {
                                    printf("Password cannot contain spaces.\n");
                                }
                                else
                                {
                                    valid = 1;
                                    strcpy(user.password, password);
                                }
                            }

                            strcpy(filename, user.phone);
                            fp = fopen(strcat(filename, ".dat"), "w");
                            fwrite(&user, sizeof(struct user), 1, fp);
                            fclose(fp);
                            printf("\nPassword succesfullly changed");
                        }
                        else
                            printf("\nSorry your password is wrong");
                        break;

                    default:
                        break;
                    } // switch ends here
                    printf("\n\nDo you want to continue?[y/n]:\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("Invalid password");
            }
        }
    }

    return 0;
}
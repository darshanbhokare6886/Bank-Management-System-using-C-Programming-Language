# Bank-Management-System-using-C-Programming-Language
This project is a simple yet functional bank management system implemented in the C programming language. It offers basic banking functionalities such as account registration, login, balance inquiry, fund deposition, cash withdrawal, online money transfer, and password change.

## Features
Registration: Users can register their account by providing their account number, phone number, and a strong password.
Login: Registered users can log in using their phone number and password.
Balance Inquiry: Users can check their account balance.
Deposit Funds: Users can add funds to their account.
Cash Withdrawal: Users can withdraw cash from their account.
Online Transfer: Users can transfer money online to another registered user's account.
Password Change: Users can change their account password for security reasons.

## How to Use:
Compile the source code using any C compiler.
Run the compiled executable and choose from the menu options.
Perform banking operations as per your requirement.

## Key concepts used in this project:

Structures: 
The project uses structures to define the user data type, which stores information such as phone number, account number, password, and balance.

File Handling: 
File handling functions like fopen, fwrite, and fread are used to store and retrieve user information from files. Each user's data is stored in a separate file named after their phone number.

User Input and Output: 
The program takes user input using scanf for menu choices, account details, and transaction amounts. It also provides feedback and prompts to the user using printf statements.

Password Security: 
The program implements password security checks, ensuring that passwords meet certain criteria such as length, containing alphabets, digits, and special characters, and not having spaces.

Control Structures: 
Control structures like if-else statements and switch-case statements are used to implement different functionalities based on user choices.

Looping: 
while loops are used for password input validation and for allowing users to continue performing transactions until they choose to exit.

String Manipulation: 
String manipulation functions like strcpy, strcat, and strcmp are used for handling strings, such as concatenating filenames and comparing passwords.

Dynamic Memory Allocation: 
While not explicitly used in this project, dynamic memory allocation functions like malloc and free could be employed for more advanced features, such as storing user data in dynamic arrays or linked lists.

Header Files: 
Standard C header files like stdio.h, string.h, stdlib.h, ctype.h, and conio.h are included for input/output operations, string manipulation, standard library functions, character handling, and console input/output, respectively.

Preprocessor Directives: 
The #define directive is used to define a macro MAX_PASSWORD_LENGTH, which sets the maximum length for user passwords throughout the program.

# Info_search

Just like the name, the program searches the information and prints the information of the given symbol number. The program was written solely for the student information management system. It can take the information given by user for any given 'n' number of students as input, can store them in a '.csv' file, search the information based on the symbol number provided by the user and can even delete the infomation. The symbol number can be 12 characters long and can contain any characters. 

The program is written in C language. C is a powerful general-purpose programming language. It can be used to develop software like operating systems, databases, compilers, and so on. I have written it in C as this program being the program I was trying out after completing my C classes.

It being the First version till date, it is simple and lacks better features. Currently, it has simple features like store, search and delete. Symbol number being the vital part of information in all of those features.

## Working Process

After getting the command from the user on what the user desires to do, it opens the appropriate terminal. Again, after getting the command in the new terminal as requested by the user previously, it does the work requested by the user. 

If the command is to store the information, it stores the information in a csv file named "data.csv". All the information are stored in this file. The first line of the file shows on which format the information are stored. If any problem arises during opening of the file, an error message is displayed in the screen. Commands are taken in the form of number, with each command being given a specific number, as all the required command are presented on the screen before taking command from the user. 

If the command is to search information, it takes the symbol number from the user and matches with all the symbol number already stored in the csv file. If the symbol number matches then it displays all the information stored for the given symbol number. If it does not find any symbol number in the csv file which matches with the symbol number given by the user then it informs the user about it.

If the command is to delete information, all the process involved during searching information are repeated and then after finding the desired information , it asks again for the confirmation to delete informationa and then deletes it upon the approval from the user.

And the last command is to exit the home page terminal. It closes the program.

Thank you !!!
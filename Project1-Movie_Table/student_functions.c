/* Agastya Asthana
 * 9082088338
*/

#include <stdio.h>
#include <stdlib.h>
#include "student_functions.h"

/*
 * This function returns the length of a given string
 */
int lengthOfString(char str[]){
    int i = 0;
    int length = 0;
    while(str[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

/**
 * Method takes a 2D array and finds the length of
 * biggest entry from all the lines and returns that
 */
int greatestEntryLength(char str[10][1024]){
    int globalMax = 0;
    for (int i = 0; i < 10; i++)
    {
        if(str[i][0] == '\0') break;
        int localMax = 0;
        for (int j = 0; j < 1024; j++)
        {
            if (str[i][j] == '\0')
            {
                break;
            }
            else localMax++;
            
        }
        globalMax = (localMax > globalMax) ? localMax : globalMax;
    }

    return globalMax;
    
}

/* This function takes a string as input and removes 
 * leading and trailing whitespace including spaces
 * tabs and newlines. It also removes multiple internal
 * spaces in a row. Arrays are passed by reference.
 */
void Clean_Whitespace(char str[]) {
    int strLen = lengthOfString(str);    //does not count the string termination character
    //begining whitespace clean
    for (int i = 0; i < strLen; i++)
    {
        //If the character is a letter then we have taken care of begining whitespaces
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            break;
        }
        else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            for (int j = i; j < strLen; j++)
            {
                str[j] = str[j + 1];
            }
            strLen--;
            i--;
        }
    }
    
    //rear whitespace clean
    for (int i = strLen - 1; i >= 0; i--)
    {
        //stop if we have reached the first letter from the back
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            break;
        }
        else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            str[i] = '\0';
            strLen--;
        }
    }
    
    return;
}

/* This function takes a string and makes the first
 * letter of every word upper case and the rest of the
 * letters lower case
 */ 
void Fix_Case(char str[]) {
    short cap = 1;
    int strLen = lengthOfString(str); //not counting the terminating character at the end
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == ' ')
        {
            cap = 1;
        }
        
        if(cap == 1){
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'z')){
                str[i] = str[i] - ('z' - 'Z');
                cap = 0;
            }
        }
        
    }
    
    return;
}

/* this function takes a string and returns the 
 * integer equivalent
 */
int String_To_Year(char str[]) {
    int year = 0;
    // do your work here
    for (int i = 0; i < lengthOfString(str)+1; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        
        year = (year*10) + (str[i]+48);
    }
    
    return year;
}


/* this function takes the name of a 
 * director as a string and removes all but
 * the last name.  Example:
 * "Bucky Badger" -> "Badger"
 */
void Director_Last_Name(char str[]) {
    // do your work here
    char buffer[lengthOfString(str)]; //create a buffer with the same length as str
    int j = 0;  //buffer index pointer
    int wordRead = 0; //boolean to tell if we are ready to read last name
    for (int i = 0; i < lengthOfString(str); i++)
    {
        printf("current char: %c\t j: %d\n", str[i], j);
        if (str[i] == ' ')
        {
            wordRead = 1;
        }
        else if(wordRead){
            buffer[j++] = str[i];   //store current letter from str to buffer at index j and increment it

        }
    }
    buffer[j] = '\0';
    j = 0;
    while(buffer[j] != '\0'){
        str[j] = buffer[j];
        j++;
    }
    str[j] = '\0';
    
    return;
}


/* this function takes the a string and returns
 * the floating point equivalent
 */
float String_To_Rating(char str[]) {
    // do your work here
    float finalNumber = 0.0;
    int decimalPointFlag = 0;   //this flag tells us whether the numbers are after decimal point or not
    int numsAfterDecimal = 0;
    int length = lengthOfString(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '.')
        {
            decimalPointFlag = 1;
        }
        else if (!decimalPointFlag)
        {
            finalNumber = (finalNumber * 10.0) + (str[i]-48.0);
        }
        else if (decimalPointFlag)  //there is an else if instead of an else so potential whitespaces are ignored
        {
            finalNumber = (finalNumber * 10) + (str[i]-48);
            numsAfterDecimal++;
        }
    }
    for (int i = 0; i < numsAfterDecimal; i++)
    {
        finalNumber /= 10.0f;
    }
    
    
    return finalNumber;
}


/* this function takes a string representing
 * the revenue of a movie and returns the decimal
 * equivlaent. The suffix M or m represents millions,
 * K or k represents thousands.
* example: "123M" -> 123000000 
*/
long long String_To_Dollars(char str[])  {
    // do your work here
    long long finalNumber = 0;
    int length = lengthOfString(str);
    for (int i = 0; i < length; i++)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            finalNumber = (finalNumber * 10) + (str[i]-48);
        }
        else if (str[i] == 'M' || str[i] == 'm')
        {
            finalNumber = finalNumber * 1000000;
        }
        else if (str[i] == 'K' || str[i] == 'k'){
            finalNumber *= 1000;
        }
        
        
    }
    
    return finalNumber;
}


/* This function takes the array of strings representing 
 * the csv movie data and divides it into the individual
 * components for each movie.
 * Use the above helper functions.
 */
void Split(char csv[10][1024], int num_movies, char titles[10][1024], int years[10], char directors[10][1024], float ratings[10], long long dollars[10]) {
    int titleIndex = 0, yearIndex = 0, directorIndex = 0, ratingIndex = 0, dollarIndex = 0;
    num_movies = csv[0][0];
    for (int i = 0; i < 10; i++)
    {
        if(csv[i][0] == '\0') break;
        printf("%s\n", csv[i]);
    }
    
    // do your work here
    for (int i = 1; i < 10; i++)    //10 because that how many potential lines we are to encounter
    {
        if (csv[i][0] == '\0') break;
        int numOfComma = 0;
        char tempBuffer[50];
        int bufferIndex = 0;
        int lineIndex = 0;
        for (int j = 0; j < lengthOfString(csv[i]); j++)
        {
            if (csv[i][j] == ','){
                switch (numOfComma++) //switch on the current number of commas and increment after it has been used
                {
                case 0: //titles
                    tempBuffer[bufferIndex++] = '\0';
                    Clean_Whitespace(tempBuffer);
                    for (int k = 0; k < bufferIndex; k++)
                    {
                        titles[titleIndex][lineIndex++] = tempBuffer[k];    //title index for each line in csv and line index is for each char in line
                    }
                    titleIndex++;
                    lineIndex = 0; 
                    bufferIndex = 0;
                    break;
                case 1: //years
                    tempBuffer[bufferIndex++] = '\0';
                    Clean_Whitespace(tempBuffer);
                    years[yearIndex++] = String_To_Year(tempBuffer);
                    bufferIndex = 0;
                    break;
                case 3: //directors
                    tempBuffer[bufferIndex++] = '\0';
                    Clean_Whitespace(tempBuffer);
                    for (int k = 0; k < bufferIndex; k++)
                    {
                        directors[directorIndex][lineIndex++] = tempBuffer[k];    //director index for each line in csv and line index is for each char in line
                    }
                    directorIndex++;
                    lineIndex = 0; 
                    bufferIndex = 0;
                    break;
                case 4: //ratings
                    tempBuffer[bufferIndex++] = '\0';
                    Clean_Whitespace(tempBuffer);
                    ratings[ratingIndex++] = String_To_Rating(tempBuffer);
                    bufferIndex = 0;
                case 5: //dollars
                    tempBuffer[bufferIndex++] = '\0';
                    Clean_Whitespace(tempBuffer);
                    dollars[dollarIndex++] = String_To_Dollars(tempBuffer);
                    bufferIndex = 0;
                    break;
                default:
                    tempBuffer[bufferIndex++] = '\0';
                    bufferIndex = 0;
                    break;
                }
                
            }
            else
            {
                tempBuffer[bufferIndex] = csv[i][j];
                bufferIndex++;
            }
            
            
        }
        numOfComma = 0; 
    }
    
    return;
}



/* This function prints a well formatted table of
 * the movie data 
 * Row 1: Header - use name and field width as below
 * Column 1: Id, field width = 3, left justified
 * Column 2: Title, field width = lenth of longest movie + 2 or 7 which ever is larger, left justified, first letter of each word upper case, remaining letters lower case, one space between words
 * Column 3: Year, field with = 6, left justified
 * Column 4: Director, field width = length of longest director last name + 2 or 10 (which ever is longer), left justified, only last name, first letter upper case, remaining letters lower case
 * column 5: Rating, field width = 6, precision 1 decimal place (e.g. 8.9, or 10.0), right justified
 * column 6: Revenue, field width = 11, right justified
 */
void Print_Table(int num_movies, char titles[10][1024], int years[10], char directors[10][1024], float ratings[10], long long dollars[10]) {
    int titleLength = greatestEntryLength(titles);
    titleLength = ((titleLength+2) > 7) ? titleLength+2 : 7;
    int directorsLength = greatestEntryLength(directors);
    directorsLength = ((directorsLength+2) > 7) ? directorsLength+2 : 7;
    printf("%-3s%-*s%-6s%-*s%6s%11s\n", "Id", titleLength, "Title", "Year", directorsLength, "Director", "Rating", "Revenue");
    for (int i = 0; i < num_movies; i++)
    {
        Fix_Case(titles[i]);
        Director_Last_Name(directors[i]);
        printf("%-3d%-*s%-6d%-*s%6.1f%11lld\n", (i+1), titleLength, titles[i], years[i], directorsLength, directors[i], ratings[i], dollars[i]);
    }
    return;
}





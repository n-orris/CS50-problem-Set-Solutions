#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//function declarations


int main(void) 
{
    
    string text = get_string("input text:\n");
    int length = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;
    
    // counts the letters in a text
    for (int i = 0; i < length; i++)
    {
        if (text[i] != 32 && text[i] != 44 && text[i] != 46 && text[i] != 58 && text[i] != 34 && text[i] != 39 && text[i] != 63
        && text[i] != 3 && text[i] != 45 && text[i] != 59)
        {
            
            letters += 1;
            
        }
        // counts the words by identifying spaces
        else if (text[i] == 32)
        {
            words += 1;
        }
        //counts sentences by identifying ! ? .
        else if (text[i] == 33 || text[i] == 63 || text[i] == 46) 
        {
            sentences += 1;
        }
    
    }
    double L = ((double)letters / (double)words) * 100;
    double S = ((double)sentences / (double) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index >= 16.00) 
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.00) 
    {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n", index);
    }
}

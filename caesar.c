#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    
    
    // exits in error +message if 2 arguments arent input
    if ( argc == 1 || argc > 2 ){
        printf("provide encryption key\n");
        return 1 ;
    }
    char *a = argv[1];
    int key = atoi(a) % 26;
   
    
    string plaintext = get_string("plaintext:");
    
    
}

string rotate (int k, string text) {
    for (int i = 0; i < strlen(text); i++) {
        if ( ( (int) text[i] == 32 || (int) text[i] == 39 || (int) text[i] == 44 || (int) text[i] == 46)) {
            printf("%c",text[i]);
        }
        else if (isupper(text[i])) {
            char rotation = (int) text[i] + k) % 91 +65;
        }
        }
    }
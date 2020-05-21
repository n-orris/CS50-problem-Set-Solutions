#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // exits with error if less or more than 1 argument is entered
    if (argc != 2) {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // opens to file to be read
    FILE *fp = fopen(argv[1],"r");
    // if fopen is unable to read the file it returns with error
    if (!fp) 
    {
        printf("Unable to read file\n");
        return 1;
    }
    typedef uint8_t BYTE;
    BYTE buffer[512];
    char name[8];
    int counter = 0;
    FILE *img = NULL;
    
    while (fread(buffer,512,7314,fp) == 1) {
        
    
        if (buffer[0]== 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 ) {
            if (img == NULL) {
                sprintf(name, "%03i.jpg", counter);
                img = fopen(name,"w");
                counter += 1;
                
            }
            else if (img != NULL) {
                fclose(img);
                sprintf(name, "%03i.jpg", counter);
                img = fopen(name,"w");
                counter += 1;
                
                
            }
        if (img != NULL) {
            fwrite(buffer,512,1,img);
            
        }
        
        }
    }
    fclose(fp);
    fclose(img);
    return 0;
   
}
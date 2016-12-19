#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        char buf[1024];
        char *string = "allah";
        int len;
        FILE *dictionary;
        dictionary = fopen("dictionary.txt" , "r");
        char *found;
        int foundflag;
        foundflag = 0;
        len = strlen(string);
        while(fgets(buf,1024,dictionary)) {
                found = strtok(buf, "\n");
                if(strcmp(string, found) == 0) {
                        printf("Found: %s\n", buf);
                        foundflag = 1;
                        break;
                }

        }
        if(foundflag == 0){
                printf("That was not found in the dictionary\n");
        }
        fclose(dictionary);
        return 0;
}

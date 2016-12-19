
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesarian_encrypt(int n, char *str, int len);
char *caesarian_decrypt(int n, char *str, int len);
int compare(char *temp,int len);


int main()
{
        char *string = "tlffu";
        int len;
        int i;
        i = 0;
        char *temp;
        int foundflag;
        foundflag = 0;
        len = strlen(string);

        //caesarian_encrypt(1, string, len);
        for(;i < 26; i++) {
                temp = caesarian_decrypt(i, string, len);
                compare(temp,len);

        }


        return 0;
}

void caesarian_encrypt(int n, char *str, int len)
{
        //caesarian cipher, n represents the key
        char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char modalphabet[26];
        char newstr[len];
        int i;
        int x;
        x = 0;
        i = 0;
        //while loop
        //move each letter n characters to the right
        //i want to mod the i value to roll over 25/26

        for(;i<26;i++) {
                x = i+n;
                x = x%26;
                modalphabet[i] = alphabet[x];
        }
        i = 0;

        for(;i<len;i++){
                x=0;
                for(;x<26;x++) {
                        if(str[i] == alphabet[x]) {
                                newstr[i] = modalphabet[x];

                        }
                }
        }
        printf("Encrypted:%s\n", newstr);
}

char *caesarian_decrypt(int n, char *str, int len)
{
        //caesarian cipher, n represents the key
        char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char modalphabet[26];
        char *newstr;
        int i;
        int x;
        x = 0;
        i = 0;
        //while loop
        //move each letter n characters to the right
        //i want to mod the i value to roll over 25/26

        for(;i<26;i++) {
                x = i+n;
                x = x%26;
                modalphabet[i] = alphabet[x];

        }
        i = 0;
        newstr = malloc(len);
        for(;i<len;i++){
                x=0;
                for(;x<26;x++) {
                        if(str[i] == modalphabet[x]) {
                                newstr[i] = alphabet[x];

                        }
                }
        }
        return newstr;
}

int compare(char *temp,int len)
{
        int foundflag;
        foundflag = 0;
        FILE *dictionary;
        dictionary = fopen("dictionary.txt" , "r");

        char *found;
        char buf[1024];
        while(fgets(buf,1024, dictionary)) {
                found = strtok(buf, "\n");
                if(strncmp(temp, found,len) == 0) {
                        printf("Found: %s\n", buf);
                        foundflag = 1;
                        }

        }
        fclose(dictionary);
        return foundflag;
}

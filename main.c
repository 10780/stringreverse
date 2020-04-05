#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input1[400];

int main(void){
puts("Enter text: ");
gets(input1);

char *in1 = (char*) malloc(strlen(input1) + 1); //initialize- allocate memory and copy literal to string (otherwise we get warnings)
strcpy(in1, input1); //pointer for input1 ready to go
printf("========================================"); //stylistic, but it separates the input area from the outputs for easier reading & for distinction
printf("\nYour text input: %s\n", in1);

char in1Copy[400], sort;
strcpy(in1Copy, in1); //everything's now copied over
char *cpy1 = (char*) malloc(strlen(in1Copy) + 1);
strcpy(cpy1, in1Copy);

int len, start, end, i, j, index;
len = strlen(in1); //set to whatever length of input string is (this is for rearranging the letters more than anything)
index = 0; //for reversing words

//check words from end of string
start = len - 1;
end = len - 1;

//lines 30-47 deal with reversing
while(start > 0){ //find a word
    if(in1[start] == ' '){ //add word
        i = start + 1;
        while(i <= end){ //start here
            cpy1[index] = in1[i]; //copy vs orig. input
            i++; //go until we hit end of the word
            index++; //go until we hit the end of the word
        }
        cpy1[index++] = ' '; //next word
        end = start - 1;
    }
    start--;
}
for(i = 0; i <= end; i++){ //last one
    cpy1[index] = in1[i]; //just like in the while() above, find the word
    index++;
}
printf("\nReversed: %s", cpy1);
free(cpy1); //pointer has done its job
cpy1 = NULL; //double check- no possible memory leaks or other issues now

//alphabetizing portion of program
for(i = 1; i < len; i++){
    for(j = 0; j < len - i; j++){
        if(in1[j] > in1[j + 1]){
            //swap em
            sort = in1[j];
            in1[j] = in1[j + 1];
            in1[j + 1] = sort;
        }
    }
}
printf("\nAlphabetized: %s", in1); //NOTE (12.12.2018 rev)- it reads spaces... sort of; spaces get put in front of output string, this took me a little while to notice
free(in1);
in1 = NULL; //same as above; no risk of memory leak or something else we don't want
printf("\n\nPress any key to continue"); //only works if you press the "any" key

getchar();
return 0;
}

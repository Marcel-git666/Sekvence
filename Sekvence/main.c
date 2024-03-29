//
//  main.c
//  Sekvence
//
//  Created by Marcel Mravec on 26.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'a');
}
 
// Utility function to reverse a string
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
 
// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;  // Initialize index of result
 
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
 
    // Reverse the result
    strev(res);
 
    return res;
}

int main(void) {
    int position, base, result, i, numberDigits, numberSpaces;
    char res[100];
    result=1;
    while (result!=EOF){
        numberDigits=0;
        printf("Pozice a soustava:\n");
        result=scanf("%d %d", &position, &base);
        if ((result!=2) || (base <2) || (base>36) || (position<0)) {
            printf("Nespravny vstup.\n");
        return 1;
        }
        int count=0;
        i=0;
    //printf("Zadal jsi:%d %d\n", pozice, soustava);
        while (count<position){
            i++;
            fromDeci(res, base, i);
            //printf("Převedené číslo %s\n", res);
            //pocet_cislic=(i==0)?1:log10(i)+1;
            numberDigits=strlen(res);
            //if (res=="0") {pocet_cislic=1;}
            count=numberDigits+count;
            //printf("Count %d, pozice %d\n", count, pozice);
        }
        printf("%s\n", res);
        numberSpaces=numberDigits-(count-position)-1; //count-position 0...znamená poslední číslice
        //printf("Count %d, pozice %d, pocet mezer %d, pocet cislic %d\n", count, pozice, pocet_mezer, pocet_cislic);
        i=0;
        while (i<numberSpaces){
            printf(" ");
            i++;
        }
    //printf("%*c", pocet_mezer, ' ');
        printf("^\n");
   }
    return 0;
}


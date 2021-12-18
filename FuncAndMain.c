#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXTL 1024
#define CHECKEDWORDLEN 30

char word[CHECKEDWORDLEN];
char txt[TXTL];

void checkedWord(){
    char c = 0;
    scanf("%c", &c);
    int i = 0;
    while(c != ' ' && c != '\t' && c != '\n' && i < CHECKEDWORDLEN){
        word[i] = c;
        scanf("%c", &c);
        i++;
    }
    word[i] = '\0';
}

void checkedTxt(){
    char c = 0;
    scanf("%c", &c);
    int i = 0;
    while(c != '~' && i < TXTL){
         txt[i] = c;
         scanf("%c", &c);
         i++;
    }
    txt[i] = '\0';
}

int gematria(){
    int sum = 0;
    int i = 0;
    while (word[i] != '\0'){
        if (word[i] >= 'a' && word[i] <= 'z'){
            sum += word[i] - 'a' + 1;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z'){
            sum += word[i] - 'A' + 1;
        }
        ++i;
    }
    return sum;
}

char *atbash(){
    int i = 0;
    char *newWord = (char*)malloc(sizeof(char) * CHECKEDWORDLEN);
    while (word[i] != '\0' || i <= CHECKEDWORDLEN){
        if (word[i] >= 'a' && word[i] <= 'm'){
            newWord[i] = 'z' - word[i] + 'a';
        }
        else if (word[i] >= 'A' && word[i] <= 'M'){
            newWord[i] = 'Z' - word[i] + 'A';
        }
        else if (word[i] >= 'n' && word[i] <= 'z'){
            newWord[i] = 'a' - word[i] + 'z';
        }
        else if (word[i] >= 'N' && word[i] <= 'Z'){
            newWord[i] = 'A' - word[i] + 'Z';
        }
        else{
            newWord[i] = word[i];
        }
        ++i;
    }
    newWord[i] = '\0';
    return newWord;
}

char *revers(char *currWord){
    char *newWord = (char*)malloc(sizeof(char) * CHECKEDWORDLEN);
    int end = 0;
    while (currWord[end] != '\0'){
        ++end;
    }
    for (int i = 0; i < end; i++){
        newWord[i] = currWord[end - i - 1];
    }
    newWord[end] = '\0';
    return newWord;
}

void gematriaSequences(){
int GematriaSum = gematria();
    printf("Gematria Sequences: ");
    int tiltdaPrint = 0;
    int i = 0;
    while (txt[i] != '\0') {
        int sum = 0; 
        int j = i;
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')) {
            while (txt[j] != '\0' && sum < GematriaSum) {
                if (txt[j] >= 'a' && txt[j] <= 'z') {
                    sum += txt[j] - 'a' + 1;
                }
                else if (txt[j] >= 'A' && txt[j] <= 'Z') {
                    sum += txt[j] - 'A' + 1;
                }
                ++j;
            }
            --j;
            if (sum == GematriaSum) {
                if (tiltdaPrint) {
                    printf("~");
                }
                for (int b = i; b <= j; b++){
                    printf("%c", txt[b]);
                }
                ++tiltdaPrint;
             
            }
        }
        ++i;
    }
}

void atbashSequences(){
    char *atbashWord = atbash();
    char *reversAtbash = revers(atbashWord);
    printf("Atbash Sequences: ");
    int tiltdaPrint = 0;
    int i = 0;
    while (txt[i] != '\0'){
        if (txt[i] == atbashWord[0]){
            int flag = 0;
            int j = i;
            int b = 0;
            while (txt[j] != '\0' && atbashWord[b] != '\0' && b >= 0) {
                if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' && txt[j] <= 'Z')){
                    if (txt[j] == atbashWord[b]){
                        ++b;
                        if (atbashWord[b] == '\0') {
                            flag = 1;
                            b = -1;
                        }
                    }
                    else{
                        b = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag) {
                if (tiltdaPrint){
                    printf("~");
                }
                for (int b = i; b <= j; b++){
                    printf("%c", txt[b]);
                }
                ++tiltdaPrint;
            }
        }
        else if (txt[i] == reversAtbash[0]){
            int flag = 0;
            int j = i;
            int b = 0;
            while (txt[j] != '\0' && reversAtbash[b] != '\0' && b >= 0) {
                if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' && txt[j] <= 'Z')) {
                    if (txt[j] == reversAtbash[b]){
                        ++b;
                        if (reversAtbash[b] == '\0'){
                            flag = 1;
                            b = -1;
                        }
                    }
                    else{
                        b = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag){
                if (tiltdaPrint){
                    printf("~");
                }
                for (int b = i; b <= j; b++){
                    printf("%c", txt[b]);
                }
                ++tiltdaPrint;
            }
        }
        ++i;
    }
    free(atbashWord);
    free(reversAtbash);
}

void anagramSequences(){
    printf("Anagram Sequences: ");
    int tiltdaPrint = 0;
    int i = 0;
    while (txt[i] != '\0'){
        if (txt[i] != ' ' && txt[i] != '\t' && txt[i] != '\n'){
            char copy[CHECKEDWORDLEN];
            strcpy(copy, word);
            int flag = 0;
            int j = i;
            while (txt[j] != '\0' && flag == 0) {
                if (txt[j] != ' ' && txt[j] != '\t' && txt[j] != '\n'){
                    flag = -1;
                    for (int b = 0; copy[b] != '\0' && flag <= -1; b++){
                        if (txt[j] == copy[b]) {
                            copy[b] *= -1;
                            flag = 0;
                        }
                    }
                    if (flag == 0){
                        flag = 1;
                        for (int b = 0; copy[b] != '\0' && flag == 1; b++) {
                            if (copy[b] > 0) {
                                flag = 0;
                            }
                        }
                    }
                }
                ++j;
            }
            --j;
            if (flag == 1){
                if (tiltdaPrint){
                    printf("~");
                }
                for (int b = i; b <= j; b++){
                    printf("%c", txt[b]);
                }
                ++tiltdaPrint;
            }
        }
        ++i;
    }
}
int main()
{
    checkedWord();
    checkedTxt();
    gematriaSequences();
    printf("\n");
    atbashSequences();
    printf("\n");
    anagramSequences();
}

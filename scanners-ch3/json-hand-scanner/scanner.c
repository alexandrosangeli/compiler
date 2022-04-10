#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {

    FILE *fptr;

    fptr = fopen("example.json","r");

    if (!fptr) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i, c;
    int line = 1, column = 0;

    while (1) {
        c = fgetc(fptr);
        column++;
        if (c == EOF) {return 0;}
        if (c == '\n') {
            line++;
            column = 0;
        }
        
        switch (c) {
            case '{' :  
                printf("LBRACKET, %d, %d\n", line, column);
                break;
            case '}' :
                printf("RBRACKET, %d, %d\n", line, column);
                break;
            case ':' :
                printf("COLON, %d, %d\n", line, column);
                break;
            case ',' :
                printf("COMMA, %d, %d\n", line, column);
                break;
        }

        // name
        if (c == '"') {
            int temp_col = column;
            do {
                c = fgetc(fptr);
                column++;
            } while (c != '"');
            
            printf("NAME, %d, %d-%d\n", line, temp_col, column);
        }

        if (isdigit(c)) {
            int temp_col = column;
            do { 
                c = fgetc(fptr);
                column++;
            } while (isdigit(c));
            ungetc(c, fptr);
            column--;
            printf("VALUE, %d, %d-%d\n", line, temp_col, column);
        }

    }

    return 0;
}
#include <stdio.h> 
#include <stdarg.h>
#include "holberton.h"

/***The _printf is thesame as printf which incuds in <stdio.h>***/
int output_convert(unsigned int num, const int base){
    const char *digit = "0123456789ABCDEF";
    unsigned int buf[32];
    int i = 0;
    char ch;
    if(base == 10){
        do
        {
            buf[i]=num%10;
            num=num/16;
            i++;
        } while (num>0);
        
    }
    if (base == 16){
        do { 
            buf[i] = num % 16; num = num / 16; i++; 
            }
        while ( num > 0 ); 
    }
    if (base == 4){
        do { 
            buf[i] = num % 4; num = num / 4; i++; 
            }
        while ( num > 0 ); 
        }


    while ( --i >= 0 ) { 
        ch = digit[buf[i]]; putchar( ch ); 
        } 
}


int _printf(const char *format, ...){
    va_list unnamed_p;
    char *p, *sval;
    unsigned int val_i;
    va_start(unnamed_p, format);
    for ( p=(char *)format; *p; p++ ){
        if(*p!='%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
            case 'd':
                val_i = va_arg(unnamed_p, unsigned int);
                output_convert(val_i, 10);
                break;
            case 's':
                for (sval = va_arg(unnamed_p, char*); *sval; sval++){
                    putchar(*sval);

                }
                break;
            case 'x':
                val_i = va_arg( unnamed_p, unsigned int );
                output_convert( val_i, 10 );
                break;
            default: putchar( *p ); 
                break; } } 
        va_end( unnamed_p ); 
    return 0; 

}

int myprinftest(void){
    char buf[16] = "abcd";
    int counter = 0;
    _printf("hello, test printf\n");
    _printf("test str: %s\n",buf);
    for (; counter<5; counter++){
        _printf("test int: %d\n",counter);
    }
}
int main(){
    int a = 1;
    int b = a*19;
    _printf("%d\n", b);

    myprinftest();
}

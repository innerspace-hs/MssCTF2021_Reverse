#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    char a[100] = {0};
    char b[100] = {0};
    unsigned char buf[100] = "mssctf{please_set_a_flag}";
    printf("[Signin] Welcome to mssctf2021.\n");
    printf("Please input your password and I will check it!\n");
    printf("input: ");
    scanf("%s", a);
    for (int i=0;i<32;i++){
        b[i] = a[i];
    }
    for (int i=0;i<32;i++){
        a[i] ^= (i + 4)*2;
    }
    for (int j=0;j<32;j++){
        if(a[j] != buf[j]){
            printf("WRONG!");
            Sleep(0xdeadbeef);
        }
    }
    printf("Congratulations!You're right!\n");
    printf("Here is your flag : mssctf{%s}",b);
    Sleep(0xdeadbeef);
    return 0;
}
#include <stdio.h>
#include "./lib/file.h"

int main()
{
    char fileName[255];
    printf("Okunacak dosyanin uzantisi ile birlikte adini giriniz (Ornek kullanim: OkunacakDosya.txt): ");
    scanf("%s", fileName);
    read(fileName);
    return 0;
}

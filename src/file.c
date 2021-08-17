#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/file.h"
#include "./lib/luhn.h"

void removeSpace(char *data)
{
    int count = 0;
    for (int i = 0; data[i]; i++)
        if (data[i] != ' ')
            data[count++] = data[i];
    data[count] = '\0';
}

void read(char *fileName)
{
    //Text dosyasında işlem yapmak için FILE dosya değişkeni
    FILE *dataFile;
    //Okunacak olan veri boyutu
    int size = 21;
    //Bellekten okunacak olan veri için yer ayrılıyor
    char *line = (char *)malloc(size * (sizeof(char)));

    //fopen ile dosya okuma modunda aılıyor. Aynı zamanda dosyanın bulunamaması durumu için kontrol ediliyor
    if (!(dataFile = fopen(fileName, "r")))
    {
        //Eğer dosya yok ise hata mesajı döndürüyor
        perror("Dosya açılırken bir sorun oldu.");
        return;
    }

    //Dosyanın sonuna kadar okuması için feof kullanılarak döngü oluşturuluyor
    while (!feof(dataFile))
    {
        //Belirtilen boyut kadar dosyadan okuma yapılıyor
        fgets(line, size, dataFile);
        //Satır sonu işareti yerine NULL byte atanıyor
        line[19] = '\0';
        printf("%s", line);
        removeSpace(line);
        //Luhn algoritması kontrolü gerçekleştiriliyor
        if (control(line) == 0)
            printf(" gecerli\n");
        else
            printf(" gecersiz\n");
    }

    //Bellekten ayrılan yer serbest bırakılıyor
    free(line);
    //Açılan dosya kapatılıyor
    fclose(dataFile);
}
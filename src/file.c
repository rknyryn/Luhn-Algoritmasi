#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/file.h"
#include "./lib/luhn.h"

char *removeSpace(char *data)
{
    //Bellekten yer ayırılıyor
    char *temp = (char *)malloc((16) * sizeof(char));
    int j = 0;
    //Verinin tüm rakamlarını kontrol etmek için döngü
    for (int i = 0; i < 20; i++)
    {
        //Eğer boşluk veya satır sonu değilse; geçici değişkene ekleniyor
        if (data[i] != ' ' && data[i] != '\n')
        {
            temp[j] = data[i];
            j++;
        }
    }
    //Geçici değişken; boşluklardan ve satır sonu işaretlerinden arındırılmış olarak geri döndürülüyor
    return temp;
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
        //Luhn algoritması kontrolü gerçekleştiriliyor
        if(control(removeSpace(line)) == 0)
            printf("%s gecerli\n", line);
        else
            printf("%s gecersiz\n", line);
    }

    //Bellekten ayrılan yer serbest bırakılıyor
    free(line);
    //Açılan dosya kapatılıyor
    fclose(dataFile);
}
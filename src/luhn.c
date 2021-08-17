#include <stdio.h>
#include "./lib/luhn.h"

int sumOfDigits(int number)
{
    int n, sum = 0;
    n = number;
    //Sayı 0 dan büyük olduğu sürece dönüyor
    while (n > 0)
    {
        //Sayının mod10'unu alarak sonucu topluyor
        sum = sum + (n % 10);
        //Sayıyı 10'a bölerek bir basamak ilerliyor
        n = n / 10;
    }
    //Gelen sayının rakamları toplamını döndürüyor
    return sum;
}

int twoTimes(int number)
{
    int result = number * 2;
    //Eğer parametreden gelen rakamın iki katı > 9 ise; iki katının rakamlarını topluyor
    if (result > 9)
        result = sumOfDigits(result);
    return result;
}

int control(char *number)
{
    //Tüm rakamların toplamı için değişken
    int sum = 0;

    //Numaranın sağından başlayıp soluna doğru hareket etmesi için;
    //Dizinin son indisinden başlayarak 0. indisine kadar dönen bir döngü oluşturuluyor
    for (int i = 15; i >= 0; i--)
    {
        //Her ikinci basamağın iki katını almak için;
        //indis numarasının mod2'ye göre kontrolü yapılıyor
        if (i % 2 == 0)
            sum += twoTimes((int)number[i] - 48);
        else
            sum += ((int)number[i] - 48);
    }
    //Tüm rakamların toplamının mod10'a göre sonucu geri döndürülüyor
    return (sum % 10);
}
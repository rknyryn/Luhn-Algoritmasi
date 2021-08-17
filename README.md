# Luhn Algoritması
Adını yaratıcısı IBM bilim adamı Hans Peter Luhn'dan alan ve "modül 10" veya "mod 10" algoritması
olarak da bilinen Luhn algoritması, Kart numaraları, IMEI numaraları gibi çeşitli kimlik numaralarını
doğrulamak için kullanılan basit bir sağlama toplamı algoritmasıdır.
Algoritma günümüzde yaygın olarak kullanılmaktadır. Kötü niyetli saldırılara karşı kriptografik bir işlevi
yoktur, tesadüfi hatalara karşı koruma sağlamak için tasarlanmıştır. Çoğu kredi kartı ve birçok devlet
kimlik numarası, algoritmayı, geçerli sayıları yanlış yazılmış veya yanlış numaralardan ayırt etmenin
basit bir yöntemi olarak kullanır.

### Luhn algoritması aşağıdaki şekilde çalışır:
    1. Girilen sayı alınır ve en sağdaki basamaktan başlayarak sola doğru hareket edilir, her ikinci basamağın değeri iki katına çıkarılır.

    2. Eğer elde edilen sayı 9 dan büyükse rakamları toplanır. Diğer basamaklar aynen kalır.

    3. Elde edilen sayıların (basamakların) hepsi toplanır.
    
    4. Toplamın mod 10'u alınır. Eğer sonuç “0” ise girilen kart numarası doğrudur. Değilse yanlış bir numaradır.

### Örnek
    Kart numarası : 7729 3956 1874 1013
    Adım 1 – Değerleri 2 ile çarp
    14 7 4 9
    6 9 10 6
    2 8 14 4
    2 0 2 3
    Adım 2 – Değerleri Topla
    5 7 4 9 6 9 1 6
    2 8 5 4
    2 0 2 3
    Adım 3 – Tüm Değerleri Topla
    5 + 7 + 4 + 9 + 6 + 9 + 1 + 6 + 2 + 8 + 5 + 4 + 2 + 0 + 2 + 3= 73
    Adım 4 – Mod 10’a göre (73/10=7.3 tam bölünmez.)
    73 % 10 = 3 -> kart numarası geçersizdir.
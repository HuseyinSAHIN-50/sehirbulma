#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *sehirIsmi, *plakaKod;
    int sehir_sayisi = 7;  // Şehir sayisini değişken olarak tanimladim
    int max_uzunluk = 50;  // Maksimum karakter uzunluğu
    char sehirler[7][50];  // 7 şehir için dizi
    int trafikKodlari[7];  // 7 trafik kodu için dizi
    int i, girilenKod, bulundu = 0;

    // Dosyalari açmak için
    sehirIsmi = fopen("sehirler.txt", "r");
    plakaKod = fopen("plakakodlari.txt", "r");

    if (sehirIsmi == NULL || plakaKod == NULL) {
        printf("Dosya acma hatasi");
        return 1;
    }
    if (sehirIsmi == NULL || plakaKod == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    // Dosyalardan verileri oku
    for (i = 0; i < sehir_sayisi; i++) {
        fscanf(sehirIsmi, "%s", sehirler[i]);
        fscanf(plakaKod, "%d", &trafikKodlari[i]);
    }

    fclose(sehirIsmi);
    fclose(plakaKod);

    // Kullanicidan trafik kodu aliyoruz
    printf("Trafik kodunu girin: ");
    scanf("%d", &girilenKod);

    // Girilen kodu listede aratma
    for (i = 0; i < sehir_sayisi; i++) {
        if (trafikKodlari[i] == girilenKod) {
            printf("Sehir: %s", sehirler[i]);
            bulundu = 1;
            printf(" Dogu Karadeniz bolgesinde yer alir");
            break;
        }
    }

    // Eğer kod bulunamazsa
    if (!bulundu) {
        printf("Gecersiz trafik kodu!\n");
    }

    return 0;
}
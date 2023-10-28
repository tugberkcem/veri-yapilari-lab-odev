#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ogrenci yapisi
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// ogrenci listesine yeni ogrenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = head;
    return yeniOgrenci;
}

// ogrenci adina gore arama yapma fonksiyonu
struct Ogrenci* ogrenciAraAd(struct Ogrenci* head, const char* hedefAd) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            return gecici; 
        }
        gecici = gecici->next;
    }
    return NULL; // Eslesme bulunamadi  NULL dondur
}

int main() {
    struct Ogrenci* liste = NULL;

    // ogrenci kayitlari
    liste = ogrenciEkle(liste, 1, "zeynep");
    liste = ogrenciEkle(liste, 2, "efe");
    liste = ogrenciEkle(liste, 3, "ali");
    liste = ogrenciEkle(liste, 4, "berk");

    // Kullanicidan aranacak ogrencinin adi ?
    char arananAd[50];
    printf("Aranacak ogrencinin adini girin: ");
    scanf("%s", arananAd);

    // ogrenci adina gore arama yap
    struct Ogrenci* sonuc = ogrenciAraAd(liste, arananAd);

    if (sonuc != NULL) {
        printf("Ogrenci Bulundu: Ogrenci No %d, Adi: %s\n", sonuc->ogrenciNo, sonuc->ad);
    } else {
        printf("Ogrenci Bulunamadi: %s\n", arananAd);
    }

    // Bellegi temizle
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}


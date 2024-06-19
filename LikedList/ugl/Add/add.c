#include <stdio.h>
#include <stdlib.h>

// تعريف الهيكل
struct cbagliListe {
    int veri1;
    int veri2;
    struct cbagliListe* onceki;
    struct cbagliListe* sonraki;
};

// تعريف المتغيرات العالمية
struct cbagliListe* ilkDugum = NULL;
struct cbagliListe* sonDugum = NULL;

// تعريف الدوال
struct cbagliListe* dolustur(int veril, int veri2) {
    struct cbagliListe* yeniDugum = (struct cbagliListe*)malloc(sizeof(struct cbagliListe));
    yeniDugum->veri1 = veril;
    yeniDugum->veri2 = veri2;
    yeniDugum->onceki = NULL;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

void basaEkle(int veril, int veri2) {
    struct cbagliListe* yeniDugum = dolustur(veril, veri2);
    if (ilkDugum == NULL) {
        ilkDugum = yeniDugum;
        sonDugum = yeniDugum;
    } else {
        yeniDugum->sonraki = ilkDugum;
        ilkDugum->onceki = yeniDugum;
        ilkDugum = yeniDugum;
    }
}

void sonaEkle(int veril, int veri2) {
    struct cbagliListe* yeniDugum = dolustur(veril, veri2);
    if (ilkDugum == NULL) {
        ilkDugum = yeniDugum;
        sonDugum = yeniDugum;
    } else {
        sonDugum->sonraki = yeniDugum;
        yeniDugum->onceki = sonDugum;
        sonDugum = yeniDugum;
    }
}

void arayaEkle(int veril, int veri2, int sira) {
    struct cbagliListe* ArayaEklenecek = dolustur(veril, veri2);
    if (sira == 0) {
        basaEkle(veril, veri2);
        return;
    }
    if (ilkDugum == NULL && sira > 0) {
        printf("\n Ekleme işlemi yapılamaz ");
        return;
    }
    int sayac = 0, kontrol = 0;
    struct cbagliListe* temp = ilkDugum;
    while (temp != NULL) {
        if (sayac == sira) {
            kontrol = 1;
            break;
        }
        temp = temp->sonraki;
        sayac++;
    }
    if (kontrol == 0) {
        printf("\n Eklenecek Pozisyon Yok\n");
        return;
    }
    if (temp->sonraki == NULL) {
        sonaEkle(veril, veri2);
        return;
    }
    struct cbagliListe* OncekiDugum = temp->onceki;
    OncekiDugum->sonraki = ArayaEklenecek;
    ArayaEklenecek->onceki = OncekiDugum;
    ArayaEklenecek->sonraki = temp;
    temp->onceki = ArayaEklenecek;
}

int main() {
    basaEkle(1, 10); // إضافة (1, 10) في بداية القائمة
    sonaEkle(3, 30); // إضافة (3, 30) في نهاية القائمة
    arayaEkle(2, 20, 1); // إضافة (2, 20) بعد عنصر رقم 1

    // طباعة عناصر القائمة
    struct cbagliListe* temp = ilkDugum;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->veri1, temp->veri2);
        temp = temp->sonraki;
    }
    printf("\n");

    return 0;
}


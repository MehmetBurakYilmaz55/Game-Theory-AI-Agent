#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int basla;
int B = 1;
int A = 0;
int *hamleler;
int *analizler;
int hamleSayisi;

void yazdir(const char *a){

    for (int i = 0; !(a[i] == '\0'); i++)
    {
        Sleep(25);
        printf("%c",a[i]);
    }
}



int hamleAl(int* hamleler,int oyun,int hamleSayisi){

    Sleep(100);
    // printf("Hamleler:  ");
    yazdir("Hamleler:  ");
    for (int i = 0; i < hamleSayisi; i++)
    {
        Sleep(100);
        printf(" (-%d) / %d\t",hamleler[i],oyun-hamleler[i]);
    }
    baslangc:
    Sleep(100);
    // printf("\nLütfen Hamle Seçiniz:   ");
    yazdir("\nLütfen Hamle Seçiniz:   ");
    int deger;
    int sayac;
    scanf("%d%*c",&deger);
    for (int i = 0; i < hamleSayisi; i++)
    {
       if ((-1*deger)==hamleler[i])
        {
            return (-1)*deger;
            
        }
    }
    Sleep(100);
    yazdir("Lütfen Gecerli Hamle Seciniz!");
    goto baslangc;

}

void oyunaBasla(int* analizler,int* hamleler,int baslangicSayisi,int hamleSayisi){


    yazdir("\t\t***Oyun Basliyor***\n");
    int oyun = baslangicSayisi;
    int hamle;
    if (analizler[oyun] == 1)
    {
        //rakip başlamalı
        Sleep(500);
        yazdir("Oyuna siz basliyorsunuz...\n");
        printf("Baslangic Oyunu: %d\n",oyun);
        hamle = hamleAl(hamleler,oyun,hamleSayisi);
        oyun -= hamle;
        Sleep(500);
        printf("Hamlenizin Sonucu: %d\n",oyun);
        printf("\n");
        

    }else{

        Sleep(500);
        yazdir("Oyuna bilgisayar basliyor...\n");
        printf("Baslangic Oyunu: %d\n",oyun);
    }

    while (oyun>0)
    {

        for (int i = 0; i < hamleSayisi; i++)
        {
            int deger = oyun-hamleler[i];
            if (analizler[deger] == 1)
            {
                hamle = hamleler[i];
                oyun -=hamle;
                if (oyun <= 0)
                {
                    yazdir("\t\t*** Oyunu Kazandiniz :)  *** \n");
                    break;
                }
                break;
            }
               
        }
        Sleep(500);
        printf("Bilgisayarin Oynadigi Hamle: %d\nMevcut Oyun: %d\n",hamle*(-1),oyun);
        printf("\n");
        Sleep(500);
        hamle = hamleAl(hamleler,oyun,hamleSayisi);
        oyun -= hamle;
        Sleep(100);
        printf("Hamlenizin Sonucu: %d\n",oyun);
        if (oyun <= 0)
        {
            yazdir("\t\t*** Oyunu Kaybettiniz :(  *** \n");
            break;
        }
        
        printf("\n");
    }
}
int main(){

    yazdir("Baslangic sayisini girin:  "); scanf("%d%*c",&basla);
    yazdir("Kac adet hamle girilecek?  "); scanf("%d%*c",&hamleSayisi);
    hamleler = (int*)calloc(hamleSayisi,sizeof(int));
    analizler = (int*)calloc(basla+1,sizeof(int));
    if (analizler == NULL) {
        yazdir("Bellek tahsisi başaririz!\n");
        return 1; // Çıkış kodu ile programı sonlandır
    }

    if (hamleler == NULL) {
        yazdir("Bellek tahsisi başaririz!\n");
        return 1; // Çıkış kodu ile programı sonlandır
    }
    
    for (int c = 0; c < hamleSayisi; c++)
    {
        etiket:
        printf("%d. Hamleyi giriniz: ",c+1); scanf("%d%*c",&hamleler[c]);
        if (hamleler[c] <= 0)
        {
            yazdir("Hamleler 0 dan kücük olamaz!\a\n");
            goto etiket;
        }
        
        printf("\n");
    }
    
    yazdir("\t\t***Oyun analiz ediliyor***\n");
    for (int i = 0; i < basla+1; i++)
    {
        int sayac = hamleSayisi; //hamle sayısı
        int *HamleSonuclariDizi = (int*)calloc(hamleSayisi,sizeof(int));
        int deger =0;

        for (int  j = 0; j < hamleSayisi; j++)
        {
            int hamleSonuc = i-hamleler[j];
            if (hamleSonuc <0)
            {
                sayac--;
            }else if (hamleSonuc >= 0)
            {
                HamleSonuclariDizi[j] = analizler[hamleSonuc];
            }
            
        }
        if (sayac == 0 &&  i==0){

            analizler[i] = A;

        }else if(sayac == 0 && i!=0){

            analizler[i] = B;

        }else{

            
            for (int k = 0; k < hamleSayisi; k++)
            {
                deger = (deger | HamleSonuclariDizi[k]);
            }
        
            analizler[i] = !deger;
        }
           
    }

    for (int a = 0; a < basla+1; a++)
    {
        printf("%d Oyunu:  %d\n",a,analizler[a]);
    }
    printf("\n");
    oyunaBasla(analizler,hamleler,basla,hamleSayisi);    
    // printf("%d",analizler[basla]);



    free(hamleler);
    free(analizler);
}

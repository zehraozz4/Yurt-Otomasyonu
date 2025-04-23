#include <stdio.h>
#include <stdlib.h>

// AD:ZEHRA  SOYAD:OZ NUMARA:22100011049

struct ogrenci_bilgisi
{
    char ad[20];
    char soyad[20];
    long long int tc;
    int yas;
    long long int tel_no;
    char okudugu_bolum[50];
    char okudugu_uni[50];
    int sinif;
}*ogrenci;

struct ucret_bilgisi
{
    struct ogrenci_bilgisi *ogrenci;
    int kac_kisilik_oda;
    char kahvalti[5];
    char ogle_yemegi[5];
    char aksam_yemegi[5];
    int kac_yil_kaldi;
}*ucret;

struct ogrenci_ortalamalari
{
    float vize_notu;
    float final_notu;
}*ort;

void ogrenci_ekle(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi);
void ogrenci_listele(struct ogrenci_bilgisi *ogrenci,int ogrenci_sayisi);
void ogrenci_sil(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi);
void bilgi_guncelle(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi);
void ucret_hesapla(struct ucret_bilgisi *ucret, int ogrenci_sayisi);
void ogrenci_ortalamalari(struct ogrenci_ortalamalari *ort, int ogrenci_sayisi);

int main()
{
    printf("<<<<<<<<<< OZEL YURT OTOMASYONU >>>>>>>>>>\n\n");

    int secim;
    int ogrenci_sayisi=0;

    ogrenci=(struct ogrenci_bilgisi*) malloc(100*sizeof(struct ogrenci_bilgisi));

    if(ogrenci==NULL)
    {
        printf("HATA!!! BELLEK TAHSIS HATASI.");
        exit(0);
    }

    ucret=(struct ucret_bilgisi*) malloc(100*sizeof(struct ucret_bilgisi));

    if(ucret==NULL)
    {
        printf("HATA!!! BELLEK TAHSIS HATASI.");
        exit(0);
    }

    ort=(struct ogrenci_ortalamalari*) malloc(100*sizeof(struct ogrenci_ortalamalari));

    if(ort==NULL)
    {
        printf("HATA!!! BELLEK TAHSIS HATASI.");
        exit(0);
    }

    do
    {
        printf("\n\n<<<<< ANA MENU >>>>>\n\n");
        printf("0:CIKIS\n");
        printf("1:OGRENCI EKLE\n");
        printf("2:OGRENCI LISTELE\n");
        printf("3:OGRENCI SIL\n");
        printf("4:BILGI GUNCELLE\n");
        printf("5:UCRET HESAPLA\n");
        printf("6:YURTTA BULUNAN OGRENCILERIN ORTALAMALARINI HESAPLA\n\n");

        printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMI SECINIZ:");
        scanf("%d",&secim);

        switch(secim)
        {
        case 0:
            printf("\nOTOMASYONDAN CIKILIYOR...");
            return 0;
        case 1:
            ogrenci_ekle(ogrenci,ogrenci_sayisi);
            ogrenci_sayisi++;
            break;
        case 2:
            ogrenci_listele(ogrenci,ogrenci_sayisi);
            break;
        case 3:
            ogrenci_sil(ogrenci,ogrenci_sayisi);
            ogrenci_sayisi--;
            break;
        case 4:
            bilgi_guncelle(ogrenci,ogrenci_sayisi);
            break;
        case 5:
            ogrenci_ekle(ogrenci,ogrenci_sayisi);
            ucret_hesapla(ucret,ogrenci_sayisi);
            break;
        case 6:
            ogrenci_ortalamalari(ort,ogrenci_sayisi);
            break;
        default:
            printf("HATALI DEGER GIRDINIZ!!!");
            break;
        }
    }

    while(secim!=0);

    free(ogrenci);
    free(ucret);
    free(ort);

    return 0;

}

void ogrenci_ekle(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi)
{
    printf("\nLUTFEN OGRENCININ ADINI GIRINIZ:");
    scanf("%s",(ogrenci+ogrenci_sayisi)->ad);
    printf("LUTFEN OGRENCININ SOYADINI GIRINIZ:");
    scanf("%s",(ogrenci+ogrenci_sayisi)->soyad);
    printf("LUTFEN OGRENCININ TC KIMLIK NUMARASINI GIRINIZ:");
    scanf("%lld",&(ogrenci+ogrenci_sayisi)->tc);
    printf("LUTFEN OGRENCININ YASINI GIRINIZ:");
    scanf("%d",&(ogrenci+ogrenci_sayisi)->yas);
    printf("LUTFEN OGRENCININ TELEFON NUMARASINI GIRINIZ:");
    scanf("%lld",&(ogrenci+ogrenci_sayisi)->tel_no);
    printf("LUTFEN OGRENCININ OKUDUGU BOLUMU GIRINIZ:");
    scanf("%s",(ogrenci+ogrenci_sayisi)->okudugu_bolum);
    printf("LUTFEN OGRENCININ OKUDUGU UNIVERSITEYI GIRINIZ:");
    scanf("%s",(ogrenci+ogrenci_sayisi)->okudugu_uni);
    printf("LUTFEN OGRENCININ KACINCI SINIF OLUGUNU GIRINIZ:");
    scanf("%d",&(ogrenci+ogrenci_sayisi)->sinif);
    printf("YENI OGRENCI BASARIYLA EKLENDI");
}

void ogrenci_listele(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi)
{
    int i;

    for(i=0; i<ogrenci_sayisi; i++)
    {
        printf("\n<<<<< %d.OGRENCININ BILGILERI >>>>>\n",i+1);
        printf("%d. OGRENCININ ADI:%s\n",i+1,(ogrenci+i)->ad);
        printf("%d. OGRENCININ SOYADI:%s\n",i+1,(ogrenci+i)->soyad);
        printf("%d. OGRENCININ TC KIMLIK NUMARASI:%lld\n",i+1,(ogrenci+i)->tc);
        printf("%d. OGRENCININ YASI:%d\n",i+1,(ogrenci+i)->yas);
        printf("%d. OGRENCININ TELEFON NUMARASI:%lld\n",i+1,(ogrenci+i)->tel_no);
        printf("%d. OGRENCININ OKUDUGU BOLUM:%s\n",i+1,(ogrenci+i)->okudugu_bolum);
        printf("%d. OGRENCININ OKUDUGU UNIVERSITE:%s\n",i+1,(ogrenci+i)->okudugu_uni);
        printf("%d. OGRENCININ SINIFI:%d\n",i+1,(ogrenci+i)->sinif);

    }
}

void ogrenci_sil(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi)
{
    int silinecek_ogrenci,i;

    printf("\nLUTFEN KACINCI OGRENCIYI SILMEK ISTEDIGINIZI GIRINIZ:");
    scanf("%d",&silinecek_ogrenci);

    if(silinecek_ogrenci>ogrenci_sayisi)
    {
        printf("HATALI DEGER GIRDINIZ!");
        exit(0);
    }

    for(i=silinecek_ogrenci-1; i<ogrenci_sayisi; i++)
    {
        if(i!=silinecek_ogrenci)
        {
            strcpy((ogrenci + i)->ad, (ogrenci + i + 1)->ad);
            strcpy((ogrenci + i)->soyad, (ogrenci + i + 1)->soyad);
            (ogrenci + i)->tc = (ogrenci + i + 1)->tc;
            (ogrenci + i)->yas = (ogrenci + i + 1)->yas;
            (ogrenci + i)->tel_no = (ogrenci + i + 1)->tel_no;
            strcpy((ogrenci + i)->okudugu_bolum, (ogrenci + i + 1)->okudugu_bolum);
            strcpy((ogrenci + i)->okudugu_uni, (ogrenci + i + 1)->okudugu_uni);
            (ogrenci + i)->sinif = (ogrenci + i + 1)->sinif;
        }
    }

    printf("%d. OGRENCI BASARIYLA SILINDI.\n",silinecek_ogrenci);

}

void bilgi_guncelle(struct ogrenci_bilgisi *ogrenci, int ogrenci_sayisi)
{
    int ogrenci_no,guncellenecek_bilgi;

    printf("\nLUTFEN GUNCELLEMEK ISTEDIGINIZ OGRENCININ SIRASINI GIRINIZ:");
    scanf("%d",&ogrenci_no);

    if (ogrenci_no < 1 || ogrenci_no > ogrenci_sayisi)
    {
        printf("HATALI DEGER GIRDINIZ.\n");
        return;
    }

    printf("\n%d.OGRENCININ MEVCUT BILGILERI\n",ogrenci_no);

    printf("%d. OGRENCININ ADI:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->ad);
    printf("%d. OGRENCININ SOYADI:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->soyad);
    printf("%d. OGRENCININ TC KIMLIK NUMARASI:%lld\n",ogrenci_no,(ogrenci+ogrenci_no-1)->tc);
    printf("%d. OGRENCININ YASI:%d\n",ogrenci_no,(ogrenci+ogrenci_no-1)->yas);
    printf("%d. OGRENCININ TELEFON NUMARASI:%lld\n",ogrenci_no,(ogrenci+ogrenci_no-1)->tel_no);
    printf("%d. OGRENCININ OKUDUGU BOLUM:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->okudugu_bolum);
    printf("%d. OGRENCININ OKUDUGU UNIVERSITE:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->okudugu_uni);
    printf("%d. OGRENCININ SINIFI:%d\n\n",ogrenci_no,(ogrenci+ogrenci_no-1)->sinif);

    do
    {
        printf("0:BILGI GUNCELLEME ISLEMINDE CIK\n");
        printf("1:%d. OGRENCININ ADINI GUNCELLE\n",ogrenci_no);
        printf("2:%d. OGRENCININ SOYADINI GUNCELLE\n",ogrenci_no);
        printf("3:%d. OGRENCININ TC KIMLIK NUMARASINI GUNCELLE\n",ogrenci_no);
        printf("4:%d. OGRENCININ YASINI GUNCELLE\n",ogrenci_no);
        printf("5:%d. OGRENCININ TELEFON NUMARASINI GUNCELLE\n",ogrenci_no);
        printf("6:%d. OGRENCININ OKUDUGU BOLUMU GUNCELLE\n",ogrenci_no);
        printf("7:%d. OGRENCININ OKUDUGU UNIVERSITEYI GUNCELLE\n",ogrenci_no);
        printf("8:%d. OGRENCININ SINIFINI GUNCELLE\n\n",ogrenci_no);

        printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMIN NUMARASINI GIRINIZ:");
        scanf("%d",&guncellenecek_bilgi);

        switch(guncellenecek_bilgi)
        {
        case 0:
            printf("\n%d. OGRENCININ BILGILERI BASARIYLA GUNCELLENDI.\n\n",ogrenci_no);


            printf("\n%d.OGRENCININ GUNCEL BILGILERI\n",ogrenci_no);

            printf("%d. OGRENCININ ADI:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->ad);
            printf("%d. OGRENCININ SOYADI:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->soyad);
            printf("%d. OGRENCININ TC KIMLIK NUMARASI:%lld\n",ogrenci_no,(ogrenci+ogrenci_no-1)->tc);
            printf("%d. OGRENCININ YASI:%d\n",ogrenci_no,(ogrenci+ogrenci_no-1)->yas);
            printf("%d. OGRENCININ TELEFON NUMARASI:%lld\n",ogrenci_no,(ogrenci+ogrenci_no-1)->tel_no);
            printf("%d. OGRENCININ OKUDUGU BOLUM:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->okudugu_bolum);
            printf("%d. OGRENCININ OKUDUGU UNIVERSITE:%s\n",ogrenci_no,(ogrenci+ogrenci_no-1)->okudugu_uni);
            printf("%d. OGRENCININ SINIFI:%d\n\n",ogrenci_no,(ogrenci+ogrenci_no-1)->sinif);
            printf("BILGI GUNCELLEME ISLEMINDEN CIKILIYOR...");
            return 0;
        case 1:
            printf("\nLUTFEN OGRENCININ ADINI GIRINIZ:");
            scanf("%s",(ogrenci+ogrenci_no-1)->ad);
            break;
        case 2:
            printf("\nLUTFEN OGRENCININ SOYADINI GIRINIZ:");
            scanf("%s",(ogrenci+ogrenci_no-1)->soyad);
            break;
        case 3:
            printf("\nLUTFEN OGRENCININ TC KIMLIK NUMARASINI GIRINIZ:");
            scanf("%lld",&(ogrenci+ogrenci_no-1)->tc);
            break;
        case 4:
            printf("\nLUTFEN OGRENCININ YASINI GIRINIZ:");
            scanf("%d",&(ogrenci+ogrenci_no-1)->yas);
            break;
        case 5:
            printf("\nLUTFEN OGRENCININ TELEFON NUMARASINI GIRINIZ:");
            scanf("%lld",&(ogrenci+ogrenci_no-1)->tel_no);
            break;
        case 6:
            printf("\nLUTFEN OGRENCININ OKUDUGU BOLUMU GIRINIZ:");
            scanf("%s",(ogrenci+ogrenci_no-1)->okudugu_bolum);
            break;
        case 7:
            printf("\nLUTFEN OGRENCININ OKUDUGU UNIVERSITEYI GIRINIZ:");
            scanf("%s",(ogrenci+ogrenci_no-1)->okudugu_uni);
            break;
        case 8:
            printf("\nLUTFEN OGRENCININ KACINCI SINIF OLUGUNU GIRINIZ:");
            scanf("%d",&(ogrenci+ogrenci_no-1)->sinif);
            break;
        default:
            printf("HATALI DEGER GIRDINIZ!");
            break;
        }
    }
    while(guncellenecek_bilgi!=0);
}

void ucret_hesapla(struct ucret_bilgisi *ucret, int ogrenci_sayisi)
{
    int ogrenci_sira,toplam_ucret=0;

    printf("\nLUTFEN UCRETI HESAPLANACAK OGRENCININ SIRASINI GIRINIZ:");
    scanf("%d",&ogrenci_sira);

    if(ogrenci_sira>ogrenci_sayisi)
    {
        printf("HATALI DEGER GIRDINIZ!");
        return;
    }

    printf("LUTFEN KAC KISILIK ODA DA KALMAK ISTEDIGINIZI GIRINIZ(1,2 VE 4 KISILIK ODALAR MEVCUTTUR):");
    scanf("%d",&(ucret+ogrenci_sira-1)->kac_kisilik_oda);

    if((ucret+ogrenci_sira-1)->kac_kisilik_oda==1)
    {
        toplam_ucret=toplam_ucret+8000;
    }
    else if((ucret+ogrenci_sira-1)->kac_kisilik_oda==2)
    {
        toplam_ucret=toplam_ucret+7000;
    }
    else if((ucret+ogrenci_sira-1)->kac_kisilik_oda==4)
    {
        toplam_ucret=toplam_ucret+6000;
    }
    else
    {
        printf("HATALI DEGER GIRDINIZ!");
        exit(0);
    }

    printf("LUTFEN KAHVALTI ISTEYIP ISTEMEDIGINIZI SECINIZ(EWET(E),HAYIR(H)):");
    scanf("%s",(ucret+ogrenci_sira-1)->kahvalti);

    if(strcmp((ucret+ogrenci_sira-1)->kahvalti,"E")==0 || strcmp((ucret+ogrenci_sira-1)->kahvalti,"e")==0)
    {
        toplam_ucret=toplam_ucret+500;
    }
    else if(strcmp((ucret+ogrenci_sira-1)->kahvalti,"H")==0 || strcmp((ucret+ogrenci_sira-1)->kahvalti,"h")==0)
    {
    }
    else
    {
        printf("HATALI DEGER GIRDINIZ!");
        exit(0);
    }

    printf("LUTFEN OGLE YEMEGI ISTEYIP ISTEMEDIGINIZI SECINIZ(EWET(E),HAYIR(H)):");
    scanf("%s",(ucret+ogrenci_sira-1)->ogle_yemegi);

    if(strcmp((ucret+ogrenci_sira-1)->ogle_yemegi,"E")==0 || strcmp((ucret+ogrenci_sira-1)->ogle_yemegi,"e")==0)
    {
        toplam_ucret=toplam_ucret+600;
    }
    else if(strcmp((ucret+ogrenci_sira-1)->ogle_yemegi,"H")==0 || strcmp((ucret+ogrenci_sira-1)->ogle_yemegi,"h")==0)
    {
    }
    else
    {
        printf("HATALI DEGER GIRDINIZ!");
        exit(0);
    }

    printf("LUTFEN AKSAM YEMEGI ISTEYIP ISTEMEDIGINIZI SECINIZ(EWET(E),HAYIR(H)):");
    scanf("%s",(ucret+ogrenci_sira-1)->aksam_yemegi);

    if(strcmp((ucret+ogrenci_sira-1)->aksam_yemegi,"E")==0 || strcmp((ucret+ogrenci_sira-1)->aksam_yemegi,"e")==0)
    {
        toplam_ucret=toplam_ucret+700;
    }
    else if(strcmp((ucret+ogrenci_sira-1)->aksam_yemegi,"H")==0 || strcmp((ucret+ogrenci_sira-1)->aksam_yemegi,"h")==0)
    {
    }
    else
    {
        printf("HATALI DEGER GIRDINIZ!");
        exit(0);
    }

    printf("LUTFEN DAHA ONCE YURTTA KAC YIL KALDIGINIZI GIRINIZ:");
    scanf("%d",&(ucret+ogrenci_sira-1)->kac_yil_kaldi);

    if((ucret+ogrenci_sira-1)->kac_yil_kaldi==0)
    {
    }
    else if((ucret+ogrenci_sira-1)->kac_yil_kaldi==1)
    {
        toplam_ucret=toplam_ucret-toplam_ucret*0.10;
    }
    else if((ucret+ogrenci_sira-1)->kac_yil_kaldi==2)
    {
        toplam_ucret=toplam_ucret-toplam_ucret*0.15;
    }
    else if((ucret+ogrenci_sira-1)->kac_yil_kaldi>=3)
    {
        toplam_ucret=toplam_ucret-toplam_ucret*0.2;
    }
    else
    {
        printf("HATALI DEGER GIRDINIZ!");
        exit(0);
    }

    printf("%d. OGRENCININ AYLIK ODEYECEGI UCRET:%d",ogrenci_sira,toplam_ucret);
}

void ogrenci_ortalamalari(struct ogrenci_ortalamalari *ort, int ogrenci_sayisi)
{
    int i;
    float ortalama;

    printf("\n<<<<<YURTTA BULUNAN OGRENCILERIN ORTALAMALARI>>>>>\n");

    for (i=0; i<ogrenci_sayisi; i++)
    {
        printf("LUTFEN %d. OGRENCI ICIN VIZE NOTU GIRINIZ:",i+1);
        scanf("%f",&(ort+i)->vize_notu);

        printf("LUTFEN %d. OGRENCI ICIN FINAL NOTU GIRINIZ:",i+1);
        scanf("%f",&(ort+i)->final_notu);

        ortalama=((ort+i)->vize_notu*0.4)+((ort+i)->final_notu*0.6);

        printf("%d. OGRENCININ ORTALAMASI:%.2f\n",i+1,ortalama);
    }
}

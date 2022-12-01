/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:  1
**				ÖÐRENCÝ ADI...............: Ýbrahim Talha Durna
**				ÖÐRENCÝ NUMARASI.: B221210006
**				DERS GRUBU…………: A
****************************************************************************/


#include <iostream>
#include <locale.h>
#include <time.h>
#include <math.h>

using namespace std;


struct Oðrenci
{
	string Adi , Soyadi;
	float No=0, KisaSinav1=0, KisaSinav2=0, Odev1=0, Odev2=0, Proje=0, Vize=0, FinalNotu=0;
};

struct Tarih
{
	int gun, ay, yil;
};


//notlarý harf notuna çeviren fonksiyon
string harfnotu(int sayinotu)
{
	string harf;
	if (sayinotu >= 87 and sayinotu <= 100)
	{
		harf = "AA";
	}

	else if (sayinotu >= 81 and sayinotu <= 86)
	{
		harf = "BA";
	}

	else if (sayinotu >= 74 and sayinotu <= 80)
	{
		harf = "BB";
	}

	else if (sayinotu >= 67 and sayinotu <= 73)
	{
		harf = "CB";
	}

	else if (sayinotu >= 60 and sayinotu <= 66)
	{
		harf = "CC";
	}

	else if (sayinotu >= 53 and sayinotu <= 59)
	{
		harf = "DC";
	}

	else if (sayinotu >= 46 and sayinotu <= 52)
	{
		harf = "DD";
	}

	else if (sayinotu >= 39 and sayinotu <= 45)
	{
		harf = "FD";
	}

	else if (sayinotu >= 0 and sayinotu <= 38)
	{
		harf = "FF";
	}
	return harf;
}

//en büyük notu bulan fonksiyon
int enbüyüknot(int x)
{
	static int eb = 0;
	if (x >= eb)
	{
		eb = x;
	}
	
	return eb;
}

//en küçük notu bulan fonksiyon
int enküçüknot(int x)
{
	static int ek = 100;
	if (x <= ek)
	{
		ek = x;
	}
	return ek;
}

//ortalama hesaplayan fonksiyon
int ortalama(int x[100]) 
{
	int ortalama;
	int toplam = 0;
	for(int i = 0; i < 100; i++)
	{
		toplam = toplam + x[i];
	}
	
	ortalama = toplam / 100;
	return ortalama;
}

//girilen notun doðru olup olmadýðýný kontrol eden fonksiyon
int kontrol(float min, float maks)
{
	float notu;
	cin >> notu;

	do
	{
		if (!(notu >= min and notu <= maks))
		{
			cout << "Geçersiz Not Girdiniz!" << endl;
			cout << "Lütfen Tekrar Not Giriniz: ";
			cin >> notu;
		}
	} while (!(notu >= min and notu <= maks));

	return notu;
}

//girilen 2 deðer arasýndaki notlarý gösteren fonksiyon
void aralýk(int alt, int üst, int notdizi, string addizi, string soyaddizi, string harf)
{
	static int i = 0;

	if (notdizi >= alt and notdizi <= üst)
	{
		cout << i + 1 << ". Öðrenci: " << endl;
		cout << "ADI SOYADI: " << addizi << " " << soyaddizi << endl;
		cout << "NOTU: " << notdizi << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//girilen deðerin altýnda kalan notlarý gösteren fonksiyon
void altinigöster(int notu, int inceleme, string adi, string soyadi, string harf)
{
	static int i = 0;
	if (notu < inceleme)
	{
		cout << i + 1 << ". Öðrenci: " << endl;
		cout << "ADI SOYADI: " << adi << " " << soyadi << endl;
		cout << "NOTU: " << notu << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//girilen deðerin üstünde kalan notlarý gösteren fonksiyon
void üstünügöster(int notu, int inceleme, string adi, string soyadi, string harf)
{
	static int i = 0;
	if (notu > inceleme)
	{
		cout << i + 1 << ". Öðrenci: " << endl;
		cout << "ADI SOYADI: " << adi << " " << soyadi << endl;
		cout << "NOTU: " << notu << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//menü fonksiyonu
void menü()
{
	cout << "1- SINIF LÝSTESÝNÝ GÖRÜNTÜLE" << endl;
	cout << "2- SINIFIN EN YÜKSEK NOTUNU GÖRÜNTÜLE" << endl;
	cout << "3- SINIFIN EN DÜÞÜK NOTUNU GÖRÜNTÜLE" << endl;
	cout << "4- SINIFIN ORTALAMASINI GÖRÜNTÜLE" << endl;
	cout << "5- SINIFIN STANDART SAPMASINI GÖRÜNTÜLE" << endl;
	cout << "6- SEÇÝLEN ARALIKTAKÝ NOTLARI GÖRÜNTÜLE" << endl;
	cout << "7- SEÇÝLEN DEÐERÝN ALTINDAKÝ NOTLARI GÖRÜNTÜLE" << endl;
	cout << "8- SEÇÝLEN DEÐERÝN ÜSTÜNDEKÝ NOTLARI GÖRÜNTÜLE" << endl;
	cout << "9- ÇIKIÞ" << endl;
}

//20'þer 20'þer öðrenci listeleyen fonksiyon
void listele(int notu, string adi, string soyadi, string harf, int gun, int ay, int yil)
{
	static int sira = 0;
		
	bool döngü = 1;
	static int a = 0;
			
	cout << (sira + 1) << ". Öðrenci: " << endl;
	cout << "ADI-SOYADI: " << adi << " " << soyadi << endl;	
	cout << "NOTU: " << notu << endl;
	cout << "HARF NOTU: " << harf << endl;
	cout << "DOÐUM TARÝHÝ: " << gun << "/" << ay << "/" << yil << endl << endl;
	sira++;
	a++;
	
	if (a == 20)
	{
		a = 0;
		system("pause");
		system("CLS");
	}
}

int standartSapma(int notu[100])
{
	int ortalama;
	int toplam = 0;
	int toplam2 = 0;
	int standart = 0;

	for (int i = 0; i < 100; i++)
	{
		toplam = toplam + notu[i];
	}

	ortalama = toplam / 100;

	int a[100];

	for (int i = 0; i < 100; i++)
	{
		a[i] = pow((notu[i] - ortalama) , 2);
		toplam2 = toplam2 + a[i];
	}

	standart = sqrt((toplam2 / 99));
	return standart;
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	string ad[30] = { "Ali","Ahmet","Aslý","Ayþe","Ýbrahim","Melih","Süleyman","Deniz","Mehmet","Merve","Rümeysa","Fatih","Sýla",
		"Çaðrý", "Seda", "Uður", "Selim", "Buse", "Aybüke", "Yusuf", "Kaan", "Gizem", "Hilal", "Ýrem","Halil","Hüseyin","Recep",
		"Beyza","Berk","Ece"
	};
	string soyad[30] = { "Kaya","Yýlmaz","Çelik","Ünal","Kaplan","Çalýþkan","Uysal","Terim","Keser","Akgül","Aksu","Kutbay","Önal",
	"Yalçýn","Ay","Gültekin","Özdemir","Altýnkaynak","Koç","Apaydýn","Kadýoðlu","Yöntem","Arslan","Kayalý","Karagöz","Saðlam",
	"Atýlgan","Iþýk","Çavuþ","Semerci"
	};

	Oðrenci ögrenciListe[100];
	Tarih ögrenci[100];
	int ögrenciNotu[100];
	string HarfNotu[100];
	string OkulNo[100];
	int DönemiciNot[100];
	int EnBüyük;
	int EnKüçük;
	int secim;
	string tekrarGörüntüleme;
	string tekrarGörüntüleme2;
	int ort = 0;
	int StandartSapma;

	

	cout << "Notlarýn Rastgele Girilmesini Ýstiyorsanýz 1'e Basýn" << endl;
	cout << "Notlarý Elle Girmek Ýstiyorsanýz 2'ye Basýn" << endl;
	
	
	do
	{
		cin >> secim; cout << endl;

		switch (secim)
		{
		case 1:
			srand(time(NULL));
			//100 öðrenciye rastgele isim ve soyisim ve doðum tarihi
			int Rastgeleisim, Rastgelesoyisim;

			for (int i = 0; i < 100; i++)
			{
				ögrenci[i].gun = 1 + rand() % 31;
				ögrenci[i].ay = 1 + rand() % 12;
				ögrenci[i].yil = 2000 + rand() % 5;
				Rastgeleisim = rand() % 30;
				Rastgelesoyisim = rand() % 30;
				ögrenciListe[i].Adi = ad[Rastgeleisim];
				ögrenciListe[i].Soyadi = soyad[Rastgelesoyisim];
			}
			// 100 öðrenciye istenen kriterlere göre rastgele not atadým
			for (int i = 0; i < 10; i++)
			{
				ögrenciNotu[i] = rand() % 40;
			}
			for (int i = 10; i < 60; i++)
			{
				ögrenciNotu[i] = 40 + rand() % 30;
			}
			for (int i = 60; i < 75; i++)
			{
				ögrenciNotu[i] = 70 + rand() % 10;
			}
			for (int i = 75; i < 100; i++)
			{
				ögrenciNotu[i] = 80 + rand() % 21;
			}
			//fonksiyon yardýmýyla öðrencilerin harf notlarýný atadým
			for (int i = 0; i < 100; i++)
			{
				HarfNotu[i] = harfnotu(ögrenciNotu[i]);
			}

			int menüSecim;
			
			do
			{
				do
				{
					menü();
					cout << endl;
					cout << "Görüntülemek Ýstediðiniz Seçeneði Seçiniz" << endl;
					cin >> menüSecim; cout << endl;

					switch (menüSecim)
					{
					case 1:
						//öðrenciler fonksiyon ile 20'þer 20'þer listeleniyor
						for (int i = 0; i < 100; i++)
						{
							listele(ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i], ögrenci[i].gun, ögrenci[i].ay, ögrenci[i].yil);
						}
						break;

					case 2:
						//en büyük not fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						for (int i = 0; i < 100; i++)
						{
							EnBüyük = enbüyüknot(ögrenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (ögrenciNotu[i] == EnBüyük)
							{
								cout << "ADI-SOYADI: " << ögrenciListe[i].Adi << " " << ögrenciListe[i].Soyadi << endl;
								cout << "NOTU: " << ögrenciNotu[i] << endl << endl;
							}
						}
						
						break;

					case 3:
						//en düþük not fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						for (int i = 0; i < 100; i++)
						{
							EnKüçük = enküçüknot(ögrenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (ögrenciNotu[i] == EnKüçük)
							{
								cout << "ADI-SOYADI: " << ögrenciListe[i].Adi << " " << ögrenciListe[i].Soyadi << endl;
								cout << "NOTU: " << ögrenciNotu[i] << endl << endl;
							}
						}

						break;

					case 4:
						//ortalama fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						ort = ortalama(ögrenciNotu);
						
						cout << ort << endl;
						break;

					case 5:
						//standart sapma fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						StandartSapma = standartSapma(ögrenciNotu);
						cout << StandartSapma << endl;
						break;

					case 6:
						// girilen aralýktaki notlarý gösterme
						int alt, üst;

						cout << "Bakmak Ýstediðiniz Not Aralýðýný Girin: (önce küçük notu giriniz.) ";
						cin >> alt >> üst; cout << endl;

						//deðerler kontrol ediliyor
						while (alt > üst)
						{
							cout << "Önce Küçük Deðer Giriniz!" << endl;
							cin >> alt >> üst; cout << endl;
						}

						//fonksiyon ile iki deðer arasýndaki notu alan öðrenciler listeleniyor
						for (int i = 0; i < 100; i++)
						{
							aralýk(alt, üst, ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 7:
						// girilen deðerin altýndaki notlar fonksiyon yardýmý ile gösteriliyor
						int inceleme;

						cout << "Girdiðiniz Deðerin Altýnda Kalan Notlara Bakmak Ýçin Bir Deðer Girin: ";
						cin >> inceleme; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							altinigöster(ögrenciNotu[i], inceleme, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}
						break;

					case 8:
						//fonksiyon ile girilen deðerin üstündeki notlarý gösterme
						int inceleme2;

						cout << "Girdiðiniz Deðerin Üstünde Kalan Notlara Bakmak Ýçin Bir Deðer Girin: ";
						cin >> inceleme2; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							üstünügöster(ögrenciNotu[i], inceleme2, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 9:

						return 0;
						break;

					default:
						cout << "Lütfen Geçerli Bir Deðer Giriniz!!!" << endl << endl;
						break;

					}
				} while (menüSecim > 9 or menüSecim < 1);

				system("pause");
				system("CLS");

			} while (true);

			break;
		case 2:
			//kullanýcýdan girdileri isteyen ve gerekli hesaplamalarý yapan döngü
			for (int i = 0; i < 100; i++)
			{
				cout << i+1 << ". Öðrencinin Adýný Giriniz: ";
				cin >> ögrenciListe[i].Adi;

				cout << i+1 << ". Öðrencinin Soyadýný Giriniz: ";
				cin >> ögrenciListe[i].Soyadi;

				cout << i + 1 << ". Öðrencinin Doðum Tarihini GG/AA/YYYY Cinsinden Giriniz: ";
				cin >> ögrenci[i].gun >> ögrenci[i].ay >> ögrenci[i].yil;

				cout << i + 1 << ". Öðrencinin Okul Numarasýný Giriniz: ";
				cin >> ögrenciListe[i].No;

				cout << i + 1 << ". Öðrencinin 1. Kýsa Sýnav Notunu Giriniz: ";
				ögrenciListe[i].KisaSinav1 = kontrol(0,100);

				cout << i + 1 << ". Öðrencinin 2. Kýsa Sýnav Notunu Giriniz: ";
				ögrenciListe[i].KisaSinav2 = kontrol(0,100);

				cout << i + 1 << ". Öðrencinin 1. Ödev Notunu Giriniz: ";
				ögrenciListe[i].Odev1 = kontrol(0, 100);

				cout << i + 1 << ". Öðrencinin 2. Ödev Notunu Giriniz: ";
				ögrenciListe[i].Odev2 = kontrol(0, 100);

				cout << i + 1 << ". Öðrencinin Proje Notunu Giriniz: ";
				ögrenciListe[i].Proje = kontrol(0, 100);

				cout << i + 1 << ". Öðrencinin Vize Notunu Giriniz: ";
				ögrenciListe[i].Vize = kontrol(0, 100);

				cout << i + 1 << ". Öðrencinin Final Notunu Giriniz: ";
				ögrenciListe[i].FinalNotu = kontrol(0, 100);


				DönemiciNot[i] = (ögrenciListe[i].Vize * 50 / 100) + (ögrenciListe[i].KisaSinav1 * 7 / 100) + (ögrenciListe[i].KisaSinav2 * 7 / 100)
					+ (ögrenciListe[i].Odev1 * 10 / 100) + (ögrenciListe[i].Odev2 * 10 / 100) + (ögrenciListe[i].Proje * 16 / 100);

				ögrenciNotu[i] = (DönemiciNot[i] * 55 / 100) + (ögrenciListe[i].FinalNotu * 45 / 100);

				HarfNotu[i] = harfnotu(ögrenciNotu[i]);
				
			}


			int menüSecim2;
			
			do
			{
				do
				{
					menü();
					cout << endl;
					cout << "Görüntülemek Ýstediðiniz Seçeneði Seçiniz" << endl;
					cin >> menüSecim2; cout << endl;
					switch (menüSecim2)
					{
					case 1:
						//öðrenciler fonksiyon ile 20'þer 20'þer listeleniyor
						for (int i = 0; i < 100; i++)
						{
							listele(ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i], ögrenci[i].gun, ögrenci[i].ay, ögrenci[i].yil);
						}
						break;

					case 2:
						//en büyük not fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						for (int i = 0; i < 100; i++)
						{
							EnBüyük = enbüyüknot(ögrenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (ögrenciNotu[i] == EnBüyük)
							{
								cout << "ADI-SOYADI: " << ögrenciListe[i].Adi << " " << ögrenciListe[i].Soyadi << endl;
								cout << "NOTU: " << ögrenciNotu[i] << endl << endl;
							}
						}

						break;

					case 3:
						//en düþük not fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						for (int i = 0; i < 100; i++)
						{
							EnKüçük = enküçüknot(ögrenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (ögrenciNotu[i] == EnKüçük)
							{
								cout << "ADI-SOYADI: " << ögrenciListe[i].Adi << " " << ögrenciListe[i].Soyadi << endl;
								cout << "NOTU: " << ögrenciNotu[i] << endl << endl;
							}
						}

						break;

					case 4:
						//ortalama fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						ort = ortalama(ögrenciNotu);

						cout << ort << endl;
						break;

					case 5:
						//standart sapma fonksiyon ile hesaplanýp ekrana yazdýrýlýyor
						StandartSapma = standartSapma(ögrenciNotu);
						cout << StandartSapma << endl;
						break;

					case 6:
						// girilen aralýktaki notlarý gösterme
						int alt, üst;

						cout << "Bakmak Ýstediðiniz Not Aralýðýný Girin: (önce küçük notu giriniz.) ";
						cin >> alt >> üst; cout << endl;

						//deðerler kontrol ediliyor
						while (alt > üst)
						{
							cout << "Önce Küçük Deðer Giriniz!" << endl;
							cin >> alt >> üst; cout << endl;
						}

						//fonksiyon ile iki deðer arasýndaki notu alan öðrenciler listeleniyor
						for (int i = 0; i < 100; i++)
						{
							aralýk(alt, üst, ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 7:
						// girilen deðerin altýndaki notlar fonksiyon yardýmý ile gösteriliyor
						int inceleme;

						cout << "Girdiðiniz Deðerin Altýnda Kalan Notlara Bakmak Ýçin Bir Deðer Girin: ";
						cin >> inceleme; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							altinigöster(ögrenciNotu[i], inceleme, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}
						break;

					case 8:
						//fonksiyon ile girilen deðerin üstündeki notlarý gösterme
						int inceleme2;

						cout << "Girdiðiniz Deðerin Üstünde Kalan Notlara Bakmak Ýçin Bir Deðer Girin: ";
						cin >> inceleme2; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							üstünügöster(ögrenciNotu[i], inceleme2, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 9:

						return 0;
						break;

					default:
						cout << "Lütfen Geçerli Bir Deðer Giriniz!!!" << endl << endl;
						break;
					}

				} while (menüSecim > 8 or menüSecim < 1);

				system("pause");
				system("CLS");

			} while (true);

			break;

		default:
			cout << "Lütfen Geçerli Bir Deðer Girin!" << endl;
			break;
		}
	} while (secim > 2 or secim < 1);
	
	
	return 0;
}



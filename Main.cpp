/****************************************************************************
**					     SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				           PROGRAMLAMAYA GİRİŞ DERSİ
**
**				ÖDEV NUMARASI…...:  1
**				ÖĞRENCİ ADI...............: İbrahim Talha Durna
**				ÖĞRENCİ NUMARASI.: B221210006
**				DERS GRUBU…………: A
****************************************************************************/


#include <iostream>
#include <locale.h>
#include <time.h>
#include <math.h>

using namespace std;


struct Oğrenci
{
	string Adi , Soyadi;
	float KisaSinav1=0, KisaSinav2=0, Odev1=0, Odev2=0, Proje=0, Vize=0, FinalNotu=0;
};

struct Tarih
{
	int gun, ay, yil;
};


//notları harf notuna çeviren fonksiyon
string harfnotu(float sayinotu)
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
int ortalama(float x[100], int n) 
{
	int ortalama;
	int toplam = 0;
	for(int i = 0; i < n; i++)
	{
		toplam = toplam + x[i];
	}
	
	ortalama = toplam / n;
	return ortalama;
}

//girilen notun doğru olup olmadığını kontrol eden fonksiyon
int kontrol(float min, float maks)
{
	float notu;
	cin >> notu;

	do
	{
		if (!(notu >= min and notu <= maks))
		{
			cout << "Geçersiz Değer Girdiniz!" << endl;
			cout << "Lütfen Tekrar Değer Giriniz: ";
			cin >> notu;
			cout << endl;
		}
	} while (!(notu >= min and notu <= maks));

	return notu;
}

//girilen 2 değer arasındaki notları gösteren fonksiyon
void aralık(float alt, float üst, float notdizi, string addizi, string soyaddizi, string harf)
{
	static int i = 0;

	if (notdizi >= alt and notdizi <= üst)
	{
		cout << i + 1 << ". Öğrenci: " << endl;
		cout << "ADI SOYADI: " << addizi << " " << soyaddizi << endl;
		cout << "NOTU: " << notdizi << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//girilen değerin altında kalan notları gösteren fonksiyon
void altinigöster(float notu, float inceleme, string adi, string soyadi, string harf)
{
	static int i = 0;
	if (notu < inceleme)
	{
		cout << i + 1 << ". Öğrenci: " << endl;
		cout << "ADI SOYADI: " << adi << " " << soyadi << endl;
		cout << "NOTU: " << notu << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//girilen değerin üstünde kalan notları gösteren fonksiyon
void üstünügöster(float notu, float inceleme, string adi, string soyadi, string harf)
{
	static int i = 0;
	if (notu > inceleme)
	{
		cout << i + 1 << ". Öğrenci: " << endl;
		cout << "ADI SOYADI: " << adi << " " << soyadi << endl;
		cout << "NOTU: " << notu << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//menü fonksiyonu
void menü()
{
	cout << "1- SINIF LİSTESİNİ GÖRÜNTÜLE" << endl;
	cout << "2- SINIFIN EN YÜKSEK NOTUNU GÖRÜNTÜLE" << endl;
	cout << "3- SINIFIN EN DÜŞÜK NOTUNU GÖRÜNTÜLE" << endl;
	cout << "4- SINIFIN ORTALAMASINI GÖRÜNTÜLE" << endl;
	cout << "5- SINIFIN STANDART SAPMASINI GÖRÜNTÜLE" << endl;
	cout << "6- SEÇİLEN ARALIKTAKİ NOTLARI GÖRÜNTÜLE" << endl;
	cout << "7- SEÇİLEN DEĞERİN ALTINDAKİ NOTLARI GÖRÜNTÜLE" << endl;
	cout << "8- SEÇİLEN DEĞERİN ÜSTÜNDEKİ NOTLARI GÖRÜNTÜLE" << endl;
	cout << "9- ÇIKIÞ" << endl;
}

//20'şer 20'şer öðrenci listeleyen fonksiyon
void listele(float notu, string adi, string soyadi, string harf, int gun, int ay, int yil)
{
	static int sira = 0;
		
	bool döngü = 1;
	static int a = 0;
			
	cout << (sira + 1) << ". Ögrenci: " << endl;
	cout << "ADI-SOYADI: " << adi << " " << soyadi << endl;	
	cout << "NOTU: " << notu << endl;
	cout << "HARF NOTU: " << harf << endl;
	cout << "DOĞUM TARİHİ: " << gun << "/" << ay << "/" << yil << endl << endl;
	sira++;
	a++;
	
	if (a == 20)
	{
		a = 0;
		system("pause");
		system("CLS");
	}
}

int standartSapma(float notu[100], int n)
{
	int ortalama;
	int toplam = 0;
	int toplam2 = 0;
	int standart = 0;

	for (int i = 0; i < n; i++)
	{
		toplam = toplam + notu[i];
	}

	ortalama = toplam / n;

	int a[100];

	for (int i = 0; i < n; i++)
	{
		a[i] = pow((notu[i] - ortalama) , 2);
		toplam2 = toplam2 + a[i];
	}

	standart = sqrt((toplam2 / (n-1)));
	return standart;
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	string ad[30] = { "Ali","Ahmet","Aslı","Ayşe","İbrahim","Melih","Süleyman","Deniz","Mehmet","Merve","Rümeysa","Fatih","Sıla",
		"Çağrı", "Seda", "Uğur", "Selim", "Buse", "Aybüke", "Yusuf", "Kaan", "Gizem", "Hilal", "İrem","Halil","Hüseyin","Recep",
		"Beyza","Berk","Ece"
	};
	string soyad[30] = { "Kaya","Yılmaz","Çelik","Ünal","Kaplan","Çalışkan","Uysal","Terim","Keser","Akgül","Aksu","Kutbay","Önal",
	"Yalçın","Ay","Gültekin","Özdemir","Altınkaynak","Koç","Apaydın","Kadıoğlu","Yöntem","Arslan","Kayalı","Karagöz","Sağlam",
	"Atılgan","Işık","Çavus","Semerci"
	};

	Oğrenci ögrenciListe[100];
	Tarih ögrenci[100];
	float ögrenciNotu[100];
	string HarfNotu[100];
	
	float DönemiciNot[100];
	float EnBüyük;
	float EnKüçük;
	int secim;
	float ort = 0;
	float StandartSapma;

	
	
	

	cout << "Notların Rastgele Girilmesini İstiyorsanız 1'e Basın" << endl;
	cout << "Notları Elle Girmek İstiyorsanız 2'ye Basın" << endl;
	
	
	do
	{
		cin >> secim; cout << endl;

		switch (secim)
		{
		case 1:
			srand(time(NULL));
			//100 öğrenciye rastgele isim ve soyisim ve doğum tarihi
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
			// 100 öğrenciye istenen kriterlere göre rastgele not atadım
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
			//fonksiyon yardımıyla öğrencilerin harf notlarını atadım
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
					cout << "Görüntülemek İstediğiniz Seçeneği Seçiniz" << endl;
					cin >> menüSecim; cout << endl;

					switch (menüSecim)
					{
					case 1:
						//öğrenciler fonksiyon ile 20'şer 20'şer listeleniyor
						for (int i = 0; i < 100; i++)
						{
							listele(ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i], ögrenci[i].gun, ögrenci[i].ay, ögrenci[i].yil);
						}
						break;

					case 2:
						//en büyük not fonksiyon ile hesaplanıp ekrana yazdırılıyor
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
						//en düşük not fonksiyon ile hesaplanıp ekrana yazdırılıyor
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
						//ortalama fonksiyon ile hesaplanıp ekrana yazdırılıyor
						ort = ortalama(ögrenciNotu, 100);
						cout << "Sýnýf Ortalamasý: " << ort << endl;
						break;

					case 5:
						//standart sapma fonksiyon ile hesaplanıp ekrana yazdırılıyor
						StandartSapma = standartSapma(ögrenciNotu, 100);
						cout << "Standart Sapma: " << StandartSapma << endl;
						break;

					case 6:
						// girilen aralıktaki notları gösterme
						int alt, üst;

						cout << "Bakmak İstediðiniz Not Aralığını Girin: (önce küçük notu giriniz.) ";
						cin >> alt >> üst; cout << endl;

						//değerler kontrol ediliyor
						while (alt > üst)
						{
							cout << "Önce Küçük Değer Giriniz!" << endl;
							cin >> alt >> üst; cout << endl;
						}

						//fonksiyon ile iki değer arasındaki notu alan öğrenciler listeleniyor
						for (int i = 0; i < 100; i++)
						{
							aralýk(alt, üst, ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 7:
						// girilen değerin altındaki notlar fonksiyon yardımı ile gösteriliyor
						int inceleme;

						cout << "Girdiğiniz Değerin Altında Kalan Notlara Bakmak İçin Bir Değer Girin: ";
						inceleme = kontrol(0, 100);

						for (int i = 0; i < 100; i++)
						{
							altinigöster(ögrenciNotu[i], inceleme, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}
						break;

					case 8:
						//fonksiyon ile girilen deðerin üstündeki notlarý gösterme
						int inceleme2;

						cout << "Girdiğiniz Değerin Üstünde Kalan Notlara Bakmak İçin Bir Deðer Girin: ";
						inceleme2 = kontrol(0, 100);

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
						cout << "Lütfen Geçerli Bir Değer Giriniz!!!" << endl << endl;
						break;

					}
				} while (menüSecim > 9 or menüSecim < 1);

				cout << endl;

				system("pause");
				system("CLS");

			} while (true);

			break;
		case 2:
			
			int ögrenciSayisi;

			cout << "Kaç Adet Öğrenci Bilgisi Girmek İstersiniz? (En fazla 100 öðrenci)" << endl;
			ögrenciSayisi = kontrol(1, 100);

			//kullanıcıdan girdileri isteyen ve gerekli hesaplamaları yapan döngü
			for (int i = 0; i < ögrenciSayisi; i++)
			{
				cout << i+1 << ". Öğrencinin Adını Giriniz: ";
				cin >> ögrenciListe[i].Adi;

				cout << i+1 << ". Öğrencinin Soyadını Giriniz: ";
				cin >> ögrenciListe[i].Soyadi;

				cout << i + 1 << ". Öğrencinin Doğum Tarihini Giriniz: " << endl;
				cout << "GÜN: ";
				ögrenci[i].gun = kontrol(1, 31);
				cout << "AY: ";
				ögrenci[i].ay = kontrol(1, 12);
				cout << "YIL: ";
				ögrenci[i].yil = kontrol(1980, 2004);

				cout << i + 1 << ". Öğrencinin 1. Kısa Sınav Notunu Giriniz: ";
				ögrenciListe[i].KisaSinav1 = kontrol(0,100);

				cout << i + 1 << ". Öğrencinin 2. Kısa Sınav Notunu Giriniz: ";
				ögrenciListe[i].KisaSinav2 = kontrol(0,100);

				cout << i + 1 << ". Öğrencinin 1. Ödev Notunu Giriniz: ";
				ögrenciListe[i].Odev1 = kontrol(0, 100);

				cout << i + 1 << ". Öğrencinin 2. Ödev Notunu Giriniz: ";
				ögrenciListe[i].Odev2 = kontrol(0, 100);

				cout << i + 1 << ". Öğrencinin Proje Notunu Giriniz: ";
				ögrenciListe[i].Proje = kontrol(0, 100);

				cout << i + 1 << ". Öğrencinin Vize Notunu Giriniz: ";
				ögrenciListe[i].Vize = kontrol(0, 100);

				cout << i + 1 << ". Öğrencinin Final Notunu Giriniz: ";
				ögrenciListe[i].FinalNotu = kontrol(0, 100);

				cout << endl;

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
					cout << endl;
					menü();
					cout << endl;
					cout << "Görüntülemek İstediğiniz Seçeneği Seçiniz" << endl;
					cin >> menüSecim2; cout << endl;
					switch (menüSecim2)
					{
					case 1:
						//öðrenciler fonksiyon ile 20'şer 20'şer listeleniyor
						for (int i = 0; i < ögrenciSayisi; i++)
						{
							listele(ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i], ögrenci[i].gun, ögrenci[i].ay, ögrenci[i].yil);
						}
						break;

					case 2:
						//en büyük not fonksiyon ile hesaplanıp ekrana yazdırılıyor
						for (int i = 0; i < ögrenciSayisi; i++)
						{
							EnBüyük = enbüyüknot(ögrenciNotu[i]);
						}

						for (int i = 0; i < ögrenciSayisi; i++)
						{
							if (ögrenciNotu[i] == EnBüyük)
							{
								cout << "ADI-SOYADI: " << ögrenciListe[i].Adi << " " << ögrenciListe[i].Soyadi << endl;
								cout << "NOTU: " << ögrenciNotu[i] << endl << endl;
							}
						}

						break;

					case 3:
						//en düşük not fonksiyon ile hesaplanıp ekrana yazdırılıyor
						for (int i = 0; i < ögrenciSayisi; i++)
						{
							EnKüçük = enküçüknot(ögrenciNotu[i]);
						}

						for (int i = 0; i < ögrenciSayisi; i++)
						{
							if (ögrenciNotu[i] == EnKüçük)
							{
								cout << "ADI-SOYADI: " << ögrenciListe[i].Adi << " " << ögrenciListe[i].Soyadi << endl;
								cout << "NOTU: " << ögrenciNotu[i] << endl << endl;
							}
						}

						break;

					case 4:
						//ortalama fonksiyon ile hesaplanıp ekrana yazdırılıyor
						ort = ortalama(ögrenciNotu, ögrenciSayisi);
						cout << "Sınıf Ortalaması: " << ort << endl;
						break;

					case 5:
						//standart sapma fonksiyon ile hesaplanıp ekrana yazdırılıyor
						StandartSapma = standartSapma(ögrenciNotu, ögrenciSayisi);
						cout << "Standart Sapma: " << StandartSapma << endl;
						break;

					case 6:
						// girilen aralıktaki notları gösterme
						int alt, üst;

						cout << "Bakmak İstediğiniz Not Aralığını Girin: (önce küçük notu giriniz.) ";
						cin >> alt >> üst; cout << endl;

						//değerler kontrol ediliyor
						while (alt > üst)
						{
							cout << "Önce Küçük Değer Giriniz!" << endl;
							cin >> alt >> üst; cout << endl;
						}

						//fonksiyon ile iki deðer arasındaki notu alan öðrenciler listeleniyor
						for (int i = 0; i < ögrenciSayisi; i++)
						{
							aralık(alt, üst, ögrenciNotu[i], ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 7:
						// girilen değerin altındaki notlar fonksiyon yardımı ile gösteriliyor
						int inceleme;

						cout << "Girdiğiniz Değerin Altında Kalan Notlara Bakmak İçin Bir Değer Girin: ";
						inceleme = kontrol(0, 100);

						for (int i = 0; i < ögrenciSayisi; i++)
						{
							altinigöster(ögrenciNotu[i], inceleme, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}
						break;

					case 8:
						//fonksiyon ile girilen değerin üstündeki notları gösterme
						int inceleme2;

						cout << "Girdiğiniz Değerin Üstünde Kalan Notlara Bakmak İçin Bir Değer Girin: ";
						inceleme2 = kontrol(0, 100);
							
						for (int i = 0; i < ögrenciSayisi; i++)
						{
							üstünügöster(ögrenciNotu[i], inceleme2, ögrenciListe[i].Adi, ögrenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 9:

						return 0;
						break;

					default:
						cout << "Lütfen Geçerli Bir Değer Giriniz!!!" << endl << endl;
						break;
					}

				} while (menüSecim2 > 9 or menüSecim2 < 1);

				cout << endl;

				system("pause");
				system("CLS");

			} while (true);

			break;

		default:
			cout << "Lütfen Geçerli Bir Değer Girin!" << endl;
			break;
		}
	} while (secim > 2 or secim < 1);
	
	
	return 0;
}



/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...:  1
**				��RENC� ADI...............: �brahim Talha Durna
**				��RENC� NUMARASI.: B221210006
**				DERS GRUBU����: A
****************************************************************************/


#include <iostream>
#include <locale.h>
#include <time.h>
#include <math.h>

using namespace std;


struct O�renci
{
	string Adi , Soyadi;
	float No=0, KisaSinav1=0, KisaSinav2=0, Odev1=0, Odev2=0, Proje=0, Vize=0, FinalNotu=0;
};

struct Tarih
{
	int gun, ay, yil;
};


//notlar� harf notuna �eviren fonksiyon
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

//en b�y�k notu bulan fonksiyon
int enb�y�knot(int x)
{
	static int eb = 0;
	if (x >= eb)
	{
		eb = x;
	}
	
	return eb;
}

//en k���k notu bulan fonksiyon
int enk���knot(int x)
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

//girilen notun do�ru olup olmad���n� kontrol eden fonksiyon
int kontrol(float min, float maks)
{
	float notu;
	cin >> notu;

	do
	{
		if (!(notu >= min and notu <= maks))
		{
			cout << "Ge�ersiz Not Girdiniz!" << endl;
			cout << "L�tfen Tekrar Not Giriniz: ";
			cin >> notu;
		}
	} while (!(notu >= min and notu <= maks));

	return notu;
}

//girilen 2 de�er aras�ndaki notlar� g�steren fonksiyon
void aral�k(int alt, int �st, int notdizi, string addizi, string soyaddizi, string harf)
{
	static int i = 0;

	if (notdizi >= alt and notdizi <= �st)
	{
		cout << i + 1 << ". ��renci: " << endl;
		cout << "ADI SOYADI: " << addizi << " " << soyaddizi << endl;
		cout << "NOTU: " << notdizi << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//girilen de�erin alt�nda kalan notlar� g�steren fonksiyon
void altinig�ster(int notu, int inceleme, string adi, string soyadi, string harf)
{
	static int i = 0;
	if (notu < inceleme)
	{
		cout << i + 1 << ". ��renci: " << endl;
		cout << "ADI SOYADI: " << adi << " " << soyadi << endl;
		cout << "NOTU: " << notu << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//girilen de�erin �st�nde kalan notlar� g�steren fonksiyon
void �st�n�g�ster(int notu, int inceleme, string adi, string soyadi, string harf)
{
	static int i = 0;
	if (notu > inceleme)
	{
		cout << i + 1 << ". ��renci: " << endl;
		cout << "ADI SOYADI: " << adi << " " << soyadi << endl;
		cout << "NOTU: " << notu << endl;
		cout << "HARF NOTU: " << harf << endl << endl;
	}
	i++;
}

//men� fonksiyonu
void men�()
{
	cout << "1- SINIF L�STES�N� G�R�NT�LE" << endl;
	cout << "2- SINIFIN EN Y�KSEK NOTUNU G�R�NT�LE" << endl;
	cout << "3- SINIFIN EN D���K NOTUNU G�R�NT�LE" << endl;
	cout << "4- SINIFIN ORTALAMASINI G�R�NT�LE" << endl;
	cout << "5- SINIFIN STANDART SAPMASINI G�R�NT�LE" << endl;
	cout << "6- SE��LEN ARALIKTAK� NOTLARI G�R�NT�LE" << endl;
	cout << "7- SE��LEN DE�ER�N ALTINDAK� NOTLARI G�R�NT�LE" << endl;
	cout << "8- SE��LEN DE�ER�N �ST�NDEK� NOTLARI G�R�NT�LE" << endl;
	cout << "9- �IKI�" << endl;
}

//20'�er 20'�er ��renci listeleyen fonksiyon
void listele(int notu, string adi, string soyadi, string harf, int gun, int ay, int yil)
{
	static int sira = 0;
		
	bool d�ng� = 1;
	static int a = 0;
			
	cout << (sira + 1) << ". ��renci: " << endl;
	cout << "ADI-SOYADI: " << adi << " " << soyadi << endl;	
	cout << "NOTU: " << notu << endl;
	cout << "HARF NOTU: " << harf << endl;
	cout << "DO�UM TAR�H�: " << gun << "/" << ay << "/" << yil << endl << endl;
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

	string ad[30] = { "Ali","Ahmet","Asl�","Ay�e","�brahim","Melih","S�leyman","Deniz","Mehmet","Merve","R�meysa","Fatih","S�la",
		"�a�r�", "Seda", "U�ur", "Selim", "Buse", "Ayb�ke", "Yusuf", "Kaan", "Gizem", "Hilal", "�rem","Halil","H�seyin","Recep",
		"Beyza","Berk","Ece"
	};
	string soyad[30] = { "Kaya","Y�lmaz","�elik","�nal","Kaplan","�al��kan","Uysal","Terim","Keser","Akg�l","Aksu","Kutbay","�nal",
	"Yal��n","Ay","G�ltekin","�zdemir","Alt�nkaynak","Ko�","Apayd�n","Kad�o�lu","Y�ntem","Arslan","Kayal�","Karag�z","Sa�lam",
	"At�lgan","I��k","�avu�","Semerci"
	};

	O�renci �grenciListe[100];
	Tarih �grenci[100];
	int �grenciNotu[100];
	string HarfNotu[100];
	string OkulNo[100];
	int D�nemiciNot[100];
	int EnB�y�k;
	int EnK���k;
	int secim;
	string tekrarG�r�nt�leme;
	string tekrarG�r�nt�leme2;
	int ort = 0;
	int StandartSapma;

	

	cout << "Notlar�n Rastgele Girilmesini �stiyorsan�z 1'e Bas�n" << endl;
	cout << "Notlar� Elle Girmek �stiyorsan�z 2'ye Bas�n" << endl;
	
	
	do
	{
		cin >> secim; cout << endl;

		switch (secim)
		{
		case 1:
			srand(time(NULL));
			//100 ��renciye rastgele isim ve soyisim ve do�um tarihi
			int Rastgeleisim, Rastgelesoyisim;

			for (int i = 0; i < 100; i++)
			{
				�grenci[i].gun = 1 + rand() % 31;
				�grenci[i].ay = 1 + rand() % 12;
				�grenci[i].yil = 2000 + rand() % 5;
				Rastgeleisim = rand() % 30;
				Rastgelesoyisim = rand() % 30;
				�grenciListe[i].Adi = ad[Rastgeleisim];
				�grenciListe[i].Soyadi = soyad[Rastgelesoyisim];
			}
			// 100 ��renciye istenen kriterlere g�re rastgele not atad�m
			for (int i = 0; i < 10; i++)
			{
				�grenciNotu[i] = rand() % 40;
			}
			for (int i = 10; i < 60; i++)
			{
				�grenciNotu[i] = 40 + rand() % 30;
			}
			for (int i = 60; i < 75; i++)
			{
				�grenciNotu[i] = 70 + rand() % 10;
			}
			for (int i = 75; i < 100; i++)
			{
				�grenciNotu[i] = 80 + rand() % 21;
			}
			//fonksiyon yard�m�yla ��rencilerin harf notlar�n� atad�m
			for (int i = 0; i < 100; i++)
			{
				HarfNotu[i] = harfnotu(�grenciNotu[i]);
			}

			int men�Secim;
			
			do
			{
				do
				{
					men�();
					cout << endl;
					cout << "G�r�nt�lemek �stedi�iniz Se�ene�i Se�iniz" << endl;
					cin >> men�Secim; cout << endl;

					switch (men�Secim)
					{
					case 1:
						//��renciler fonksiyon ile 20'�er 20'�er listeleniyor
						for (int i = 0; i < 100; i++)
						{
							listele(�grenciNotu[i], �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i], �grenci[i].gun, �grenci[i].ay, �grenci[i].yil);
						}
						break;

					case 2:
						//en b�y�k not fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						for (int i = 0; i < 100; i++)
						{
							EnB�y�k = enb�y�knot(�grenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (�grenciNotu[i] == EnB�y�k)
							{
								cout << "ADI-SOYADI: " << �grenciListe[i].Adi << " " << �grenciListe[i].Soyadi << endl;
								cout << "NOTU: " << �grenciNotu[i] << endl << endl;
							}
						}
						
						break;

					case 3:
						//en d���k not fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						for (int i = 0; i < 100; i++)
						{
							EnK���k = enk���knot(�grenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (�grenciNotu[i] == EnK���k)
							{
								cout << "ADI-SOYADI: " << �grenciListe[i].Adi << " " << �grenciListe[i].Soyadi << endl;
								cout << "NOTU: " << �grenciNotu[i] << endl << endl;
							}
						}

						break;

					case 4:
						//ortalama fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						ort = ortalama(�grenciNotu);
						
						cout << ort << endl;
						break;

					case 5:
						//standart sapma fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						StandartSapma = standartSapma(�grenciNotu);
						cout << StandartSapma << endl;
						break;

					case 6:
						// girilen aral�ktaki notlar� g�sterme
						int alt, �st;

						cout << "Bakmak �stedi�iniz Not Aral���n� Girin: (�nce k���k notu giriniz.) ";
						cin >> alt >> �st; cout << endl;

						//de�erler kontrol ediliyor
						while (alt > �st)
						{
							cout << "�nce K���k De�er Giriniz!" << endl;
							cin >> alt >> �st; cout << endl;
						}

						//fonksiyon ile iki de�er aras�ndaki notu alan ��renciler listeleniyor
						for (int i = 0; i < 100; i++)
						{
							aral�k(alt, �st, �grenciNotu[i], �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 7:
						// girilen de�erin alt�ndaki notlar fonksiyon yard�m� ile g�steriliyor
						int inceleme;

						cout << "Girdi�iniz De�erin Alt�nda Kalan Notlara Bakmak ��in Bir De�er Girin: ";
						cin >> inceleme; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							altinig�ster(�grenciNotu[i], inceleme, �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i]);
						}
						break;

					case 8:
						//fonksiyon ile girilen de�erin �st�ndeki notlar� g�sterme
						int inceleme2;

						cout << "Girdi�iniz De�erin �st�nde Kalan Notlara Bakmak ��in Bir De�er Girin: ";
						cin >> inceleme2; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							�st�n�g�ster(�grenciNotu[i], inceleme2, �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 9:

						return 0;
						break;

					default:
						cout << "L�tfen Ge�erli Bir De�er Giriniz!!!" << endl << endl;
						break;

					}
				} while (men�Secim > 9 or men�Secim < 1);

				system("pause");
				system("CLS");

			} while (true);

			break;
		case 2:
			//kullan�c�dan girdileri isteyen ve gerekli hesaplamalar� yapan d�ng�
			for (int i = 0; i < 100; i++)
			{
				cout << i+1 << ". ��rencinin Ad�n� Giriniz: ";
				cin >> �grenciListe[i].Adi;

				cout << i+1 << ". ��rencinin Soyad�n� Giriniz: ";
				cin >> �grenciListe[i].Soyadi;

				cout << i + 1 << ". ��rencinin Do�um Tarihini GG/AA/YYYY Cinsinden Giriniz: ";
				cin >> �grenci[i].gun >> �grenci[i].ay >> �grenci[i].yil;

				cout << i + 1 << ". ��rencinin Okul Numaras�n� Giriniz: ";
				cin >> �grenciListe[i].No;

				cout << i + 1 << ". ��rencinin 1. K�sa S�nav Notunu Giriniz: ";
				�grenciListe[i].KisaSinav1 = kontrol(0,100);

				cout << i + 1 << ". ��rencinin 2. K�sa S�nav Notunu Giriniz: ";
				�grenciListe[i].KisaSinav2 = kontrol(0,100);

				cout << i + 1 << ". ��rencinin 1. �dev Notunu Giriniz: ";
				�grenciListe[i].Odev1 = kontrol(0, 100);

				cout << i + 1 << ". ��rencinin 2. �dev Notunu Giriniz: ";
				�grenciListe[i].Odev2 = kontrol(0, 100);

				cout << i + 1 << ". ��rencinin Proje Notunu Giriniz: ";
				�grenciListe[i].Proje = kontrol(0, 100);

				cout << i + 1 << ". ��rencinin Vize Notunu Giriniz: ";
				�grenciListe[i].Vize = kontrol(0, 100);

				cout << i + 1 << ". ��rencinin Final Notunu Giriniz: ";
				�grenciListe[i].FinalNotu = kontrol(0, 100);


				D�nemiciNot[i] = (�grenciListe[i].Vize * 50 / 100) + (�grenciListe[i].KisaSinav1 * 7 / 100) + (�grenciListe[i].KisaSinav2 * 7 / 100)
					+ (�grenciListe[i].Odev1 * 10 / 100) + (�grenciListe[i].Odev2 * 10 / 100) + (�grenciListe[i].Proje * 16 / 100);

				�grenciNotu[i] = (D�nemiciNot[i] * 55 / 100) + (�grenciListe[i].FinalNotu * 45 / 100);

				HarfNotu[i] = harfnotu(�grenciNotu[i]);
				
			}


			int men�Secim2;
			
			do
			{
				do
				{
					men�();
					cout << endl;
					cout << "G�r�nt�lemek �stedi�iniz Se�ene�i Se�iniz" << endl;
					cin >> men�Secim2; cout << endl;
					switch (men�Secim2)
					{
					case 1:
						//��renciler fonksiyon ile 20'�er 20'�er listeleniyor
						for (int i = 0; i < 100; i++)
						{
							listele(�grenciNotu[i], �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i], �grenci[i].gun, �grenci[i].ay, �grenci[i].yil);
						}
						break;

					case 2:
						//en b�y�k not fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						for (int i = 0; i < 100; i++)
						{
							EnB�y�k = enb�y�knot(�grenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (�grenciNotu[i] == EnB�y�k)
							{
								cout << "ADI-SOYADI: " << �grenciListe[i].Adi << " " << �grenciListe[i].Soyadi << endl;
								cout << "NOTU: " << �grenciNotu[i] << endl << endl;
							}
						}

						break;

					case 3:
						//en d���k not fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						for (int i = 0; i < 100; i++)
						{
							EnK���k = enk���knot(�grenciNotu[i]);
						}

						for (int i = 0; i < 100; i++)
						{
							if (�grenciNotu[i] == EnK���k)
							{
								cout << "ADI-SOYADI: " << �grenciListe[i].Adi << " " << �grenciListe[i].Soyadi << endl;
								cout << "NOTU: " << �grenciNotu[i] << endl << endl;
							}
						}

						break;

					case 4:
						//ortalama fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						ort = ortalama(�grenciNotu);

						cout << ort << endl;
						break;

					case 5:
						//standart sapma fonksiyon ile hesaplan�p ekrana yazd�r�l�yor
						StandartSapma = standartSapma(�grenciNotu);
						cout << StandartSapma << endl;
						break;

					case 6:
						// girilen aral�ktaki notlar� g�sterme
						int alt, �st;

						cout << "Bakmak �stedi�iniz Not Aral���n� Girin: (�nce k���k notu giriniz.) ";
						cin >> alt >> �st; cout << endl;

						//de�erler kontrol ediliyor
						while (alt > �st)
						{
							cout << "�nce K���k De�er Giriniz!" << endl;
							cin >> alt >> �st; cout << endl;
						}

						//fonksiyon ile iki de�er aras�ndaki notu alan ��renciler listeleniyor
						for (int i = 0; i < 100; i++)
						{
							aral�k(alt, �st, �grenciNotu[i], �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 7:
						// girilen de�erin alt�ndaki notlar fonksiyon yard�m� ile g�steriliyor
						int inceleme;

						cout << "Girdi�iniz De�erin Alt�nda Kalan Notlara Bakmak ��in Bir De�er Girin: ";
						cin >> inceleme; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							altinig�ster(�grenciNotu[i], inceleme, �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i]);
						}
						break;

					case 8:
						//fonksiyon ile girilen de�erin �st�ndeki notlar� g�sterme
						int inceleme2;

						cout << "Girdi�iniz De�erin �st�nde Kalan Notlara Bakmak ��in Bir De�er Girin: ";
						cin >> inceleme2; cout << endl;

						for (int i = 0; i < 100; i++)
						{
							�st�n�g�ster(�grenciNotu[i], inceleme2, �grenciListe[i].Adi, �grenciListe[i].Soyadi, HarfNotu[i]);
						}

						cout << endl;
						break;

					case 9:

						return 0;
						break;

					default:
						cout << "L�tfen Ge�erli Bir De�er Giriniz!!!" << endl << endl;
						break;
					}

				} while (men�Secim > 8 or men�Secim < 1);

				system("pause");
				system("CLS");

			} while (true);

			break;

		default:
			cout << "L�tfen Ge�erli Bir De�er Girin!" << endl;
			break;
		}
	} while (secim > 2 or secim < 1);
	
	
	return 0;
}



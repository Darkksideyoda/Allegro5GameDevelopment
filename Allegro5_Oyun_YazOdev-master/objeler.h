//Obje atamalar�n� yap�yoruz.
enum KIMLIKLER { KARAKTER, KURSUN, DUSMAN };
//Bizim karakterimizin yap�lar�.

struct Karakter {
	int Kimlik;
	int x;
	int y;
	int can;
	int hiz;
	int boundx;
	int boundy;
	int skor;

	int maxKare;
	int anlik_Kare;
	int KareSayac;
	int KareGecikme;
	int EkranGenislik;
	int EkranBoy;
	int AnimasyonSutun;
	int Animasyon_yonu;

	int Animasyon_sira;

	ALLEGRO_BITMAP *image;
};
//Kursun Yap�lar�
struct Kursun {
	int Kimlik;
	int x;
	int y;
	int can;
	int hiz;
	int boundx;
	int boundy;
	int skor;

	int maxKare;
	int anlik_Kare;
	int KareSayac;
	int KareGecikme;
	int EkranGenislik;
	int EkranBoy;
	int AnimasyonSutun;
	int Animasyon_yonu;

	ALLEGRO_BITMAP *image;

};
//Dusman Yap�lar�
struct Dusman_2 {
	int Kimlik;
	int x;
	int y;
	int can;
	int hiz;
	int boundx;
	int boundy;


	int maxKare;
	int anlik_Kare;
	int KareSayac;
	int KareGecikme;
	int EkranGenislik;
	int EkranBoy;
	int AnimasyonSutun;
	int Animasyon_yonu;

	ALLEGRO_BITMAP *image;
};
//Patlama Yap�lar�
struct Patlama {
	int x;
	int y;
	bool can;

	int maxKare;
	int anlik_Kare;
	int KareSayac;
	int KareGecikme;
	int EkranGenislik;
	int EkranBoy;
	int AnimasyonSutun;
	int Animasyon_yonu;
	ALLEGRO_BITMAP *image;
};
//Arka Plan Yap�lar�
struct Background
{
	float x;
	float y;
	float velX;//X Ekseninde D�n�� H�z�
	float velY;//Y Ekseninde D�n�� H�z�
	int dirX;//X ekseninin Y�n�
	int dirY;//Y Ekseninin Y�n�

	int width;
	int height;

	ALLEGRO_BITMAP *image;

};

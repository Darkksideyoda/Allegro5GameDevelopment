//Obje atamalarýný yapýyoruz.
enum KIMLIKLER { KARAKTER, KURSUN, DUSMAN };
//Bizim karakterimizin yapýlarý.

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
//Kursun Yapýlarý
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
//Dusman Yapýlarý
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
//Patlama Yapýlarý
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
//Arka Plan Yapýlarý
struct Background
{
	float x;
	float y;
	float velX;//X Ekseninde Dönüþ Hýzý
	float velY;//Y Ekseninde Dönüþ Hýzý
	int dirX;//X ekseninin Yönü
	int dirY;//Y Ekseninin Yönü

	int width;
	int height;

	ALLEGRO_BITMAP *image;

};

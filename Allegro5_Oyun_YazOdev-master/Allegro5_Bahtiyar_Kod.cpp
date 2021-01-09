/*
//////////			 /\        |		|     ||||||||||||   *     \      /     /\         |/////////
/		 /          /  \       |        |		   |	     |		\	 /     /  \		   |		/
/        /		   /    \	   |		|		   |         |		 \  /     /    \       |		/
/////////		  /      \     |        |          |		 |		  \/     /      \      |		/
/        ////	 /        \    ||||||||||          |         |		  ||    /        \     |////////
/           /  	//////\\\\\\   |        |          |         |		  ||   //////\\\\\\    |		\
/          /   /            \  |        |          |         |        ||  /            \   |		 \
/         /   /              \ |        |          |         |        || /              \  |          \
//////////   /                \|        |          |         |        ||/                \ |           \


*/

//e�er vs 2017 kullan�l�yorsa ve hata al�n�yorsa dahil ediniz ^^#include"pch.h"^^. Bu konsol bazl� uygulamalarda compile h�z�n� artt�rmak i�in kullan�l�yor , Derleyici �ncelikli �stiyor.
#include <stdio.h>//standart "C" K�t�phanesi.
#include<math.h>//Standart math.h K�t�phanesi.
#include<allegro5/allegro.h>//Standart allegro k�t�phanesi.
#include<allegro5/allegro_primitives.h>//bu k�t�phane basit geometrik �ekkiller kullanabilmemizi sa�l�yor.
#include<allegro5/allegro_color.h>//cisimlere ve objelere renk kazand�rmak i�in kullan�lan k�t�phane.
#include<allegro5/allegro_image.h>//ortamdan import edilecek imaj dosyalar�n� �a��rmak ve kullanmak i�in.
#include <allegro5/allegro_font.h>//font i�in gerekli k�t�phane.
#include <allegro5/allegro_ttf.h>//true type font k�t�phanesi.
#include<locale.h>//t�rk�e karakter i�in kulland���m�z locale k�t�phanesi.
#include<allegro5/allegro_acodec.h>//ses dosyalar�n� ��z�mleyen k�t�phane
#include"objeler.h"//objelerimiz i�in header dosyam�z� dahil ediyoruz.
#include<allegro5/allegro_audio.h>//ses dosyalar� i�in k�t�phane.


////////////////////////////////////////////////////////////////////////
/*																	   /
#include<math.h>                                                       /BURADAK� Gibi Kutucuk i�inde'ki KODLAR
#include <cmath>                                                       / OYUNUN KOMPAKT HAL�NDEK� C# GUI'Den Dosya Okuma
#include <cstdlib>                                                     /i�in. Bu Kodlar� Yorum Haline almam�n Nedeni
#include <iostream>                                                    /Oyunun Saf Kodlar�na Odaklanman�z i�in.
#include <iomanip>                                                     /Bu Kodlar�n �al���r Haldeki Durumu Oyunun Kompakt Halidir.
#include <string>                                                      /Oyunu �u anda Hi�bir S�k�nt� Olmadan Debug modda �al��t�r�p
#include <fstream>                                                     /Oynayabilirsiniz.Ayn� �ekilde C# Kodlar�n�da Payla�aca��m...
#include <cstdlib>                                                    //
*/                                                                  ////
////////////////////////////////////////////////////////////////////////


int WIDTH;//Kulllan�c� Ekran�n�n En(x)boyutu
int HEIGHT;//Kullan�c� Ekran�n�n boy(y) boyutu
ALLEGRO_SAMPLE* patlama = NULL;
const int NUM_BULLETS = 50;//kur�un say�s�
const int NUM_COMETS = 10;//d��man say�s�
enum TUSLAR { UP, DOWN, LEFT, RIGHT, SPACE };//klavye tu�lar�n�n atamas�n�(numaraland�rmas�n�) yapt�k.
bool keys[5] = { false, false, false, false, false };//klavye tu�lar�n�n s�ras�yla do�ruluk de�erini atad�k.
const int NUM_EXPLOSIONS = 5;
int ana_menu();
void KarakterTanimla(Karakter& ship , ALLEGRO_BITMAP* image);//gemimizi oyuna dahil etti�imiz fonksiyon
void KarakterCiz(Karakter& ship);// gemiyi �izdi�imiz fonksiyon
void KursunTanimla(Kursun bullet[], int size, ALLEGRO_BITMAP* image);//kur�unlar� dahil etme 
void KursunCiz(Kursun bullet[], int size);//kur�unlar� �izme
void KursunAtesleme(Kursun bullet[], int size, Karakter& ship);//kur�unlar� ate�leme
void KursunYenileme(Kursun bullet[], int size);//kur�unlar bittikten sonra yeniden doldurmak i�in yaz�lan fonksiyon
void KursunCarpisma(Kursun bullet[], int bSize, Dusman_2 comets[], int cSize, Karakter& ship, Patlama explosions[], int eSize);//cisimlerle �arp��mada olacaklar� yazd���m�z fonskyion

void DusmanTanimla(Dusman_2 comets[], int size, ALLEGRO_BITMAP* image);//d��manlar� dahil etme
void DusmanCiz(Dusman_2 comets[], int size);//d��manlar� �izme
void DusmanBaslat(Dusman_2 comets[], int size);//D��manlar� Random �ekilde Ba�latt���m�z Fonksiyon.
void DusmanYenileme(Dusman_2 comets[], int size, Karakter& ship);//d��manlar� s�rekli spawn(yineleme)etme fonksiyonu.
void InitArkaplan(Background& back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP* image);
void YenileArkaplan(Background& back);
void CizArkaplan(Background& back);
void PatlamaTanimla(Patlama explosions[], int size, ALLEGRO_BITMAP* image);
void PatlamaCiz(Patlama explosions[], int size);
void PatlamaBasla(Patlama explosions[], int size, int x, int y);
void PatlamaYenile(Patlama explosions[], int size);

/*/////////////////////////
int Cozunurluk();		  /��z�n�rl�k fonksiyonu C# ile olu�turdu�umuz Cozunurluk.txt dosyas�n� Okumam�z� Sa�l�yor
int batac();			  /Baslat.bat Ad�ndaki batch dosyas�na a�arak EkranAyar.exe adl� c# program�n� �al��t�r�yor
using namespace std;	  / c++ :)
*//////////////////////////


int main(int argc, char** argv)//main fonksiyonumuz
{


	setlocale(LC_ALL, "Turkish");

	printf("Lutfen Ekran Boyutlar�n�z� giriniz ==> �r. 1920x1080 width=1920,height=1080");
	printf("\nWidth: ");
	scanf_s("%d", &WIDTH);
	printf("\nHeight: ");
	scanf_s("%d", &HEIGHT);


	/*/////////////
	batac();	  / Oyunun Kompakt Halindeki Kullan�lan Fonksiyonlar
	Cozunurluk(); /
	*//////////////            




	ana_menu();//ana menu fonksiyonu

	bool done = false;//bu de�i�ken sayesinde olay�m�z� ne zaman sonland�r�ca��m�z� mant�ksal olarak belirtmi� olaca��z.

	bool redraw = true;//ekranda a��lan cisim objelerin yeniden �izilebilmesi i�in.
	const int FPS = 60;
	//objelerin de�i�kenleri.
	Karakter ship;
	Kursun bullets[NUM_BULLETS];
	Dusman_2 comets[NUM_COMETS];
	Background BG;
	Patlama explosions[NUM_EXPLOSIONS];

	ALLEGRO_SAMPLE* ses = NULL;
	ALLEGRO_SAMPLE* sample = NULL;

	ALLEGRO_SAMPLE_INSTANCE* songInstance = NULL;
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);
	al_reserve_samples(2);
	al_init_font_addon();
	al_init_ttf_addon();



	if (!al_install_audio()) {
		fprintf(stderr, "Ses Dosyas� dahil edilemedi !\n");
		return -1;
	}
	sample = al_load_sample("kursun.wav");
	ses = al_load_sample("bensound-epic.wav");
	patlama = al_load_sample("patlama2.wav");
	if (!sample) {
		printf("Ses Dosyasi Yuklenemedi!\n");
		return -1;
	}

	if (!al_install_audio()) {
		fprintf(stderr, "Ses Cozumleme yuklenemedi!\n");
		return -1;
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "cozumleme basarilamadi!\n");
		return -1;
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_BITMAP* arkaplan = NULL;

	ALLEGRO_BITMAP* bulletImage = NULL;
	ALLEGRO_BITMAP* shipImage;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;//Bir Event(olay)Yaratmak,Olu�turmak i�in Kullan�yoruz.

	ALLEGRO_DISPLAY* ekran = NULL;//Pencere Olu�turuyoruz.
	ALLEGRO_DISPLAY_MODE   ekran_verisi;/*
										  Burada Olu�turulan Pencereyi Y�kseklik ve Geni�lik ayarlar�n�
										  elle girmek yerine oyun hangi bilgisayarda a��l�rsa a��ls�n otomatik
										  olarak tam ekran yapmas�n� sa�l�yoruz.
										*/

	ALLEGRO_BITMAP* cometImage;
	ALLEGRO_BITMAP* expImage;
	if (!al_init()) {
		fprintf(stderr, "Allegro Baslatilamadi!\n");
		return -1;
	}/*//allegronun ba�lamas�na ili�kin problemle kar��la��l�rsa Gelecek Kod Blo�u*/

	al_init_image_addon();//imaj adonunu ekliyoruz
	al_init_primitives_addon();//primitivies adonunu ekliyoruz.

	al_get_display_mode(al_get_num_display_modes() - 1, &ekran_verisi);

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);//tam ekran yapacak fonksiyonumuz
	ekran = al_create_display(ekran_verisi.width, ekran_verisi.height);//Burada al_create_display fonk. ile pencere olu�turuyoruz.
	arkaplan = al_load_bitmap("arkacik.jpg");
	InitArkaplan(BG, 0, 0, 1, 0, WIDTH, HEIGHT, -1, 1, arkaplan);
	font = al_load_ttf_font("Audiowide-Regular.ttf", 20, 0);

	if (!ekran) {
		fprintf(stderr, "Ekran Olusturulamadi!\n");
		return -1;
	}/*
	 Pencere Olu�mazssa Kar��la��lacak Kod Blo�u.
	 */

	al_init_primitives_addon();
	bulletImage = al_load_bitmap("kursun.png");
	cometImage = al_load_bitmap("dusman32.png");
	KursunTanimla(bullets, NUM_BULLETS, bulletImage);
	DusmanTanimla(comets, NUM_COMETS, cometImage);
	al_install_keyboard();//klavye komutlar�n� y�kl�yoruz.
	event_queue = al_create_event_queue();//event olu�turuyoruz.
	timer = al_create_timer(1.0 / FPS);
	shipImage = al_load_bitmap("crosshairs64.png");
	al_convert_mask_to_alpha(shipImage, al_map_rgb(255, 255, 255));



	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(ekran));
	/*al_register_event_source(event_queue, al_get_display_event_source(ekran));
		bu kodu e�er ekran boyutlar�n� elle girdiysek �rne�in(1024,768).. �eklinde Esc tu�u yerine uygulama bar�ndaki �arp� butonunu
		aktif veya deaktif durumua getiriyoruz.Ben Esc Tu�unu Kullanmay� tercih ettim.
	*/
	expImage = al_load_bitmap("patlama.png");
	songInstance = al_create_sample_instance(ses);
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	PatlamaTanimla(explosions, NUM_EXPLOSIONS, expImage);
	srand(time(NULL));
	KarakterTanimla(ship, shipImage);
	al_play_sample_instance(songInstance);
	al_start_timer(timer);


	while (!done)//while ile i� bitinceye kadar d�ng�ye sokuyoruz.
	{

		ALLEGRO_EVENT ev;//olay de�i�kenimizi olu�turuyoruz. 
		al_wait_for_event(event_queue, &ev);//burda yapt���m�z �ey allegroya ben sana bir �eyler yapt�rcam ama bir tu�a basmam� bekle gibi bir komut.


		if (ev.type == ALLEGRO_EVENT_TIMER)
		{

			if (keys[UP])
			{
				ship.y -= ship.hiz;
				if (ship.y < 0)
					ship.y = 0;
			}
			if (keys[DOWN])
			{
				ship.y += ship.hiz;
				if (ship.y > ekran_verisi.height)
					ship.y = ekran_verisi.height;
			}
			if (keys[LEFT])
			{
				ship.x -= ship.hiz;
				if (ship.x < 0)
					ship.x = 0;

			}
			if (keys[RIGHT])
			{
				ship.x += ship.hiz;
				if (ship.x > ekran_verisi.width)
					ship.x = ekran_verisi.width;
			}

			if (keys[SPACE])
			{

				al_play_sample(sample, 1.0, 1.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}






			YenileArkaplan(BG);
			PatlamaYenile(explosions, NUM_EXPLOSIONS);
			KursunYenileme(bullets, NUM_BULLETS);
			DusmanBaslat(comets, NUM_COMETS);
			DusmanYenileme(comets, NUM_COMETS, ship);
			KursunCarpisma(bullets, NUM_BULLETS, comets, NUM_COMETS, ship, explosions, NUM_EXPLOSIONS);
			redraw = true;

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)//klavyedeki tu� kodlar�n� kullanmak i�in switch case yap�s�n� kullan�yoruz.
			{
			case ALLEGRO_KEY_UP://yukar� y�n tu�u
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN://a��a��
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT://sol y�n tu�u
				keys[LEFT] = true;

				break;
			case ALLEGRO_KEY_RIGHT://sa� y�n tu�u
				keys[RIGHT] = true;

				break;
			case ALLEGRO_KEY_SPACE://Bo�luk
				keys[SPACE] = true;
				KursunAtesleme(bullets, NUM_BULLETS, ship);//Space'e Bas�ld���nda Ates Etme.

				break;

			}
		}
		/*
		�stteki kod blo�undan farkl� olarak buradaki ama� bool de�erinin false yaparak tu�lara bas�lmad���n� belirtiyoruz.
		*/
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;

				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;

				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;

			case ALLEGRO_KEY_ESCAPE://Esc Bas�ld���nda oyunu kapamam�za yar�yor.
				done = true;//anla��ld��� �zerede zaten tek true de�eri Esc'de.
				break;

			}

		}




		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
			CizArkaplan(BG);
			al_draw_textf(font, al_map_rgb(255, 255, 0), 5, 5, 0, "SKOR:%i", ship.skor);//Sol �st K��edeki Skor Tablosu.
			KarakterCiz(ship);
			KursunCiz(bullets, NUM_BULLETS);
			DusmanCiz(comets, NUM_COMETS);
			PatlamaCiz(explosions, NUM_EXPLOSIONS);
			al_flip_display();



		}

	}
	/*
	Burada T�m G�r�nt�,Ses Vb. Elementleri Destroy(yok ederek) ile Bitiriyoruz.
	*/
	al_destroy_bitmap(expImage);
	al_destroy_bitmap(arkaplan);
	al_destroy_bitmap(bulletImage);
	al_destroy_bitmap(cometImage);
	al_destroy_bitmap(shipImage);
	al_destroy_display(ekran);
	al_destroy_sample(sample);
	al_destroy_sample(ses);
	//////
	return 0;
}
int ana_menu()//oyunun ana giri� men�s� i�in olu�turulan fonksiyon.
{


	ALLEGRO_EVENT_QUEUE* event_queu = NULL;
	bool done = false;

	if (!al_init()) {
		fprintf(stderr, "Allegro Baslatilamadi\n");
		return -1;
	}

	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	ALLEGRO_DISPLAY* display = al_create_display(1024, 768);

	if (!display) {
		fprintf(stderr, "Ekran Olusturulamadi.\n");
		return -1;
	}

	ALLEGRO_FONT* font = al_load_ttf_font("Audiowide-Regular.ttf", 20, 0);//burada font'un -size(BOYUT)- de�i�imini kontrol ediyor ve import ediyoruz.
	//yaz� bi�imleri internetten �cretsiz olarak bulunabilir ve program kodlar�n�n bulundu�u dosya dizinine atarak kullanabilirsiniz.
	if (!font) {
		fprintf(stderr, "Yaz� Fontu = > 'Audiowide-Regular.ttf'.\n");//yaz� fontuyla ilgili hata ��kt�s�n�n kodu.
		return -1;
	}


	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 1024 / 2, (768 / 4), ALLEGRO_ALIGN_CENTRE, "OYUNU BASLATMAK ICIN SPACE BASINIZ");
	al_draw_text(font, al_map_rgb(255, 255, 255), 1024 / 2, (768 / 20), ALLEGRO_ALIGN_CENTRE, "@BAHTIYAR");
	//al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "AYARLAR");
	//al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "CIKIS");

	al_install_keyboard();//klavye kontrollerini y�kl�yoruz.
	event_queu = al_create_event_queue();

	al_register_event_source(event_queu, al_get_keyboard_event_source());
	al_flip_display();
	while (!done)
	{
		ALLEGRO_EVENT ol;
		al_wait_for_event(event_queu, &ol);
		if (ol.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (ol.keyboard.keycode == ALLEGRO_KEY_SPACE)//burda ekran� atlayabilmemiz i�in enter yada sapce tu�unu bas�yoruz.
				done = true;

		}
		if (ol.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			al_destroy_display(display);

		}


	}


	al_rest(1.0);

	al_destroy_display(display);


	return 0;
}

void KarakterTanimla(Karakter& ship, ALLEGRO_BITMAP* image)
{


	ship.x = WIDTH / 2;//Karakterin yani hedefin x ekseninde hangi noktada ba�layaca��n� belirliyoruz ekran� ortalamas� i�in /2 dedik
	ship.y = HEIGHT / 2;//x ekseni i�in olan i�lemi y ekseni i�inde yapt�k.
	ship.Kimlik = KARAKTER;//burda kimlik belirttik 
	ship.can = 3;
	ship.hiz = 7;//Karakterin h�z�
	ship.boundx = 6;
	ship.boundy = 7;
	ship.skor = 0;//skor tablosu ba�lang�� de�eri.

	ship.maxKare = 3;
	ship.anlik_Kare = 0;
	ship.KareSayac = 0;
	ship.KareGecikme = 50;
	ship.EkranGenislik = 64;
	ship.EkranBoy = 64;
	ship.AnimasyonSutun = 20;
	ship.Animasyon_yonu = 1;

	ship.Animasyon_sira = 1;

	if (image != NULL)
		ship.image = image;
}
void KarakterCiz(Karakter& ship)
{
	/*
	 Karakterin �izildi�i fonksiyon.
	*/
	int fx = (ship.anlik_Kare % ship.AnimasyonSutun) * ship.EkranGenislik;
	int fy = ship.Animasyon_yonu * ship.EkranBoy;

	al_draw_bitmap_region(ship.image, fx, fy, ship.EkranGenislik,
		ship.EkranBoy, ship.x - ship.EkranGenislik / 2, ship.y - ship.EkranBoy / 2, 0);




}
void KursunTanimla(Kursun bullet[], int size, ALLEGRO_BITMAP* image = NULL)
{
	for (int i = 0; i < size; i++)
	{
		bullet[i].Kimlik = KURSUN;//kur�un oldu�unu tan�tt�k
		bullet[i].hiz = 10;//kur�unlar�n h�z�n� belirledik.

		bullet[i].can = false;
		bullet[i].maxKare = 1;
		bullet[i].anlik_Kare = 0;
		bullet[i].KareSayac = 0;
		bullet[i].KareGecikme = 2;
		bullet[i].EkranGenislik = 48;
		bullet[i].EkranBoy = 30;
		bullet[i].AnimasyonSutun = 5;

		if (rand() % 2)
			bullet[i].Animasyon_yonu = 1;
		else
			bullet[i].Animasyon_yonu = -1;

		if (image != NULL)
			bullet[i].image = image;

	}
}
void KursunCiz(Kursun bullet[], int size)
{


	for (int i = 0; i < size; i++)
	{
		if (bullet[i].can)
		{

			/*
			kur�unun �izimi
			*/
			int fx = (bullet[i].anlik_Kare % bullet[i].AnimasyonSutun) * bullet[i].EkranGenislik;
			int fy = (bullet[i].anlik_Kare / bullet[i].AnimasyonSutun) * bullet[i].EkranBoy;

			al_draw_bitmap_region(bullet[i].image, fx, fy, bullet[i].EkranGenislik,
				bullet[i].EkranBoy, bullet[i].x - bullet[i].EkranGenislik / 2, bullet[i].y - bullet[i].EkranBoy / 2, 0);

		}




	}
}
void KursunAtesleme(Kursun bullet[], int size, Karakter& ship)
{
	/*
		bu fonksyinda kur�unun ��k�� noktas�n� belirledik.
		kur�unun ��k��  noktas� Karakterin(hedefin) anl�k kordinatlar�.
	*/
	for (int i = 0; i < size; i++)
	{
		if (!bullet[i].can)
		{
			bullet[i].x = ship.x;
			bullet[i].y = ship.y;
			bullet[i].can = true;
			break;
		}
	}
}
void KursunYenileme(Kursun bullet[], int size)
{

	/*
		kur�unlar�n yeniden doldurulmas� ve hangi eksende ilerleyece�ini yazd�k.
	*/
	for (int i = 0; i < size; i++)
	{
		if (bullet[i].can)
		{
			bullet[i].y -= bullet[i].hiz;
			if (-bullet[i].y > HEIGHT)
				bullet[i].can = false;
		}
	}
}
void DusmanTanimla(Dusman_2 comets[], int size, ALLEGRO_BITMAP* image = NULL)
{
	for (int i = 0; i < size; i++)
	{
		comets[i].Kimlik = DUSMAN;
		comets[i].can = false;
		comets[i].hiz = 5;
		comets[i].boundx = 35;
		comets[i].boundy = 35;

		comets[i].maxKare = 143;
		comets[i].anlik_Kare = 0;
		comets[i].KareSayac = 0;
		comets[i].KareGecikme = 2;
		comets[i].EkranGenislik = 86;
		comets[i].EkranBoy = 165;
		comets[i].AnimasyonSutun = 1;

		if (rand() % 2)
			comets[i].Animasyon_yonu = 1;
		else
			comets[i].Animasyon_yonu = -1;

		if (image != NULL)
			comets[i].image = image;
	}
}
void DusmanCiz(Dusman_2 comets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (comets[i].can)
		{

			/*


				T�m �izimler Ortak Bir Algoritmayla Yaz�lm�� Durumda E�er Basit�e A��klamak Gerekirse Durum ��yledir.
			�izimini Ele Ald���m�z Objelerin yani belriledi�imiz Dusman,karakter,kursun,patlamaya ait bir Animasyon Hareketli Sayfas� Mevcut(Animation Sprite Sheet).
			Bu Sayfa png format�nda oldu�u i�in ayr� ayr� her bir durumu sayfadan k�rparak dahil etmedik.O anda ki frame(kare) say�s�n�n Sayfada Bulunan Animasyonun
			sutun say�s�yla modunu ald�k b�ylelikle elimizde kalan ile sahip oldumuz monit�r�n ebatlar�na �arparak matematiksel olarak anl�k pozisyona uyarlad�k.
			Sonras�nda ise Bu Pozisyonu Etkile�im Hassasiyetini ve hatlar�n� belirlemek ad�na kabaca �izdik. Durumu Bu �ekilde �zetleyebiliriz.


			*/


			int fx = (comets[i].anlik_Kare % comets[i].AnimasyonSutun) * comets[i].EkranGenislik;
			int fy = (comets[i].anlik_Kare / comets[i].AnimasyonSutun) * comets[i].EkranBoy;

			al_draw_bitmap_region(comets[i].image, fx, fy, comets[i].EkranGenislik,
				comets[i].EkranBoy, comets[i].x - comets[i].EkranGenislik / 2, comets[i].y - comets[i].EkranBoy / 2, 0);





			/*al_draw_filled_rectangle(comets[i].x - comets[i].boundx, comets[i].y - comets[i].boundy, comets[i].x + comets[i].boundx,
				comets[i].y + comets[i].boundy, al_map_rgba(255, 0, 255, 100));*/
		}
	}
}
void DusmanBaslat(Dusman_2 comets[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (!comets[i].can)
		{


			if (rand() % 1 == 0)//rand ile random yani rastgele d��manlar� Baslat�yoruz
			{

				comets[i].can = true;
				comets[i].y = HEIGHT;
				comets[i].x = 30 + rand() % (WIDTH - 100);
				break;
			}
		}
	}


}
void DusmanYenileme(Dusman_2 comets[], int size, Karakter& ship)
{


	for (int i = 0; i < size; i++)
	{
		if (comets[i].can)
		{

			comets[i].y -= comets[i].hiz;//d��manlar�n geli� y�n�
			if (comets[i].y < 0)
			{
				comets[i].can = false;
			}
		}
	}
}
void KursunCarpisma(Kursun bullet[], int bSize, Dusman_2 comets[], int cSize, Karakter& ship, Patlama explosions[], int eSize)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].can)
		{
			for (int j = 0; j < cSize; j++)
			{
				if (comets[j].can)
				{
					/*
					Bu Kod Blo�unu A��klayacak Olursak Kur�un D��mana Hangi A��dan De�erse De�sin Vuruldu�unda hem Kur�unun Hemde D��man�n yok Olmas�n�
					ayn� zamanda Patlama Animasyonunu devreye sokarak Skorada ekleme yap�yoruz.

					*/


					if (bullet[i].x > (comets[j].x - comets[j].boundx) &&
						bullet[i].x < (comets[j].x + comets[j].boundx) &&
						bullet[i].y >(comets[j].y - comets[j].boundy) &&
						bullet[i].y < (comets[j].y + comets[j].boundy))
					{
						bullet[i].can = false;
						comets[j].can = false;
						ship.skor++;
						PatlamaBasla(explosions, eSize, bullet[i].x, bullet[i].y);
						al_play_sample(patlama, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);


					}
				}
			}
		}
	}
}
void InitArkaplan(Background& back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP* image)
{


	back.x = x;
	back.y = y;
	back.velX = velx;
	back.velY = vely;
	back.width = width;
	back.height = height;
	back.dirX = dirX;
	back.dirY = dirY;
	back.image = image;







}
void YenileArkaplan(Background& back)
{
	/* (+X) Ekseninde Belli Bir H�zda Resmimizi Hareketlendiriyoruz.   */

	back.x += back.velX * back.dirX;
	if (back.x + back.width <= 0)
	{
		back.x = 0;
	}
}
void CizArkaplan(Background& back)
{
	al_draw_bitmap(back.image, back.x, back.y, 0);
	if (back.x + back.width < WIDTH)
	{
		al_draw_bitmap(back.image, back.x + back.width, back.y, 0);
	}
}

void PatlamaTanimla(Patlama explosions[], int size, ALLEGRO_BITMAP* image = NULL)
{
	for (int i = 0; i < size; i++)
	{
		explosions[i].can = false;

		explosions[i].maxKare = 34;
		explosions[i].anlik_Kare = 0;
		explosions[i].KareSayac = 0;
		explosions[i].KareGecikme = 1;
		explosions[i].EkranGenislik = 100;
		explosions[i].EkranBoy = 100;
		explosions[i].AnimasyonSutun = 6;
		explosions[i].Animasyon_yonu = 1;

		if (image != NULL)
			explosions[i].image = image;
	}
}

void PatlamaCiz(Patlama explosions[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (explosions[i].can)
		{
			int fx = (explosions[i].anlik_Kare % explosions[i].AnimasyonSutun) * explosions[i].EkranGenislik;
			int fy = (explosions[i].anlik_Kare / explosions[i].AnimasyonSutun) * explosions[i].EkranBoy;

			al_draw_bitmap_region(explosions[i].image, fx, fy, explosions[i].EkranGenislik,
				explosions[i].EkranBoy, explosions[i].x - explosions[i].EkranGenislik / 2, explosions[i].y - explosions[i].EkranBoy / 2, 0);


		}
	}
}
void PatlamaBasla(Patlama explosions[], int size, int x, int y)
{
	for (int i = 0; i < size; i++)
	{
		if (!explosions[i].can)
		{
			explosions[i].can = true;
			explosions[i].x = x;
			explosions[i].y = y;
			break;
		}
	}
}
void PatlamaYenile(Patlama explosions[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (explosions[i].can)
		{
			if (++explosions[i].KareSayac >= explosions[i].KareGecikme)
			{
				explosions[i].anlik_Kare += explosions[i].Animasyon_yonu;
				if (explosions[i].anlik_Kare >= explosions[i].maxKare)
				{
					explosions[i].anlik_Kare = 0;
					explosions[i].can = false;
				}

				explosions[i].KareSayac = 0;
			}
		}
	}
}
/*
int Cozunurluk()
{
	
	//Standart Dosyadan Okuma ��lemi Yap�yoruz (I/O)
	
	std::fstream myfile("Cozunurluk.txt", std::ios_base::in);

	float a = 0;

	myfile >> a;

	while (!myfile.fail())
	{

		myfile >> a;
	}



	float sum(0);
	int x(0);
	int y(0);
	int sumcount(0);
	double average(0);
	int even(0);
	int odd(0);

	ifstream fin;

	string file_name = "Cozunurluk.txt";





	fin.open(file_name.c_str(), ios::in);

	if (!fin.is_open())
	{

		printf("Lutfen Ekran Boyutlar�n�z� giriniz ==> �r. 1920x1080 width=1920,height=1080");
		printf("\nWidth: ");
		scanf_s("%d", &WIDTH);
		printf("\nHeight: ");
		scanf_s("%d", &HEIGHT);


	}

	fin >> x;
	fin >> y;
	while (!fin.fail())
	{
		WIDTH = x;
	  cout << "Okunan Deger: " << x << endl;
	  cout << "Okunan Deger: " << y << endl;
		sum = sum + x;
		sumcount++;
		if (x % 2 == 0)
			even++;
		else
			odd++;

		fin >> x;
		HEIGHT = x;
	}

	fin.close();


	return 0;

}
int batac()
{
	//Oyunun Bulundu�u Dizindeki batch dosyas�.

	system("Baslat.bat");
	printf("Ba�latmak ��in 'O' Bas�n�z ");
	getchar();
	return 0;
}
*/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;//Dosya Giriş Çıkış İşlemleri İçin.
using System.Text;
using System.Diagnostics;

/*
 orjinal Form yerine Metro FrameWork Kullanmamın Sebebi Daha modern Bir Kullanıcı Arayüzü Oluşturmaktı.
     */
namespace EkranAyar
{
    
    public partial class Form1 : MetroFramework.Forms.MetroForm
    {
        string ata;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void MetroTextBox1_Click(object sender, EventArgs e)
        {
            
        }

        private void MetroButton1_Click(object sender, EventArgs e)
        {
            if (label2.Visible)//eğer label 2 görünür durumdaysa
                label2.Visible = false;//gösterme 

            else
                label2.Visible = true;//butona basıldığı taktirde görünür yap.


            //ata = ata.Replace(@"\\", @"\");
            StreamWriter File = new StreamWriter(ata+"\\Cozunurluk.txt");//açılan dosyanın dizini+dosya adı
            File.Write(metroTextBox1.Text);//yazılacak verinin alındığı textbox1
            File.Write("\n"+metroTextBox2.Text);//yazılacak verinin alındığı textbox2
            File.Close();//dosyayı kapat.


           //System.IO.File.WriteAllText("d:\a.txt", metroTextBox1.Text);
           
        }

        private void MetroButton2_Click(object sender, EventArgs e)
        {
            // bu kısım Dizin aramamızı Sağlayan Kod Bloğu Bilgisayarın her hangi bir lokasyonunu seçebiliriz.
            FolderBrowserDialog fBrowser = new FolderBrowserDialog();
            fBrowser.ShowDialog();
            string secilenDizin = fBrowser.SelectedPath;//seçilen lokasyonu string'e atıyoruz.
            metroTextBox3.Text = secilenDizin;//string'e atanmış olan lokasyonu textboxta gösteriyoruz
            ata = secilenDizin;//seçilen lokasyonu ortak tanımladığımız string'e atıyoruz
            if (label1.Visible)//label görünmez yap.
                label1.Visible = false;

           
        }

        private void MetroTextBox3_Click(object sender, EventArgs e)
        {

        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void MetroButton3_Click(object sender, EventArgs e)
        {
            this.Close();//form kapatmamızı sağlayan komut.

        }

        private void Label2_Click(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {



            button1.TabStop = false;
            button1.FlatStyle = FlatStyle.Flat;
            button1.FlatAppearance.BorderSize = 0;
            button1.FlatAppearance.BorderColor = Color.FromArgb(0, 255, 255, 255); //transparent
            //butonun kenarlarındaki çerçeveyi transparan bir hal almasını sağlayan kod.
            //aslında tüm bunlar Vs Blend'den daha detaylı yapılabilirdi...



            string makine;//string yapısındaki değişkenimiz
            makine = "OyunBilgisi.html";//değişkenin değeri.
            System.Diagnostics.Process.Start(makine);//programın bulunduğu dizindeki girilen string değerinde bir dosya varsa başlatmamızı sağlıyor.
            



        }
    }
    }


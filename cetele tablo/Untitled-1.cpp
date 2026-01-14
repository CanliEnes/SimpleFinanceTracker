#include <iostream>
#include <vector> 
#include <fstream> 

using namespace std;

struct Tarih {
    int gun;
    int ay;
    int yil;
};

void verileriyukle(Tarih t[],int &kayitsayisi){
    ifstream infile("tarihler.txt");
    if (!infile.is_open()) {
        cerr << "Dosya acilamadi!" << endl;
        kayitsayisi = 0;
        return;
    }
    while(kayitsayisi < 100 && infile >> t[kayitsayisi].gun >> t[kayitsayisi].ay >> t[kayitsayisi].yil){
    kayitsayisi++;
    }

    infile.close();
    cout << kayitsayisi << " adet kayit basariyla yüklendi." << endl;
}

void verilerikaydet(const Tarih t[], int kayitsayisi){
    ofstream outfile("tarihler.txt");
    if(!outfile.is_open()) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }
    for (int i = 0; i < kayitsayisi; i++) {
        outfile << t[i].gun << " " << t[i].ay << " " << t[i].yil << endl;
    }
    outfile.close();
    cout << kayitsayisi << " adet kayit basariyla 'tarihler.txt' dosyasina kaydedildi." << endl;

}

void tarihlerlistesi(const Tarih t[], int kayitsayisi){
    cout << "KAYITLI TARIHLER LISTESI:" << endl;
    if(kayitsayisi == 0) {
        cout << "Kayit bulunamadi." << endl;
        return;
    }
    for (int i = 0; i < kayitsayisi; i++) {
        cout << i + 1 << ". " << t[i].gun << "/" << t[i].ay << "/" << t[i].yil << endl;
    }}

void tarihsil(Tarih t[], int &kayitsayisi){
    if(kayitsayisi == 0) {
        cout << "Silinecek kayit bulunamadi." << endl;
        return;
    }
    tarihlerlistesi(t, kayitsayisi);
    int silinecekindex;
    cout << "Silmek istediginiz kaydin numarasini giriniz (1-" << kayitsayisi << "): ";
    cin >> silinecekindex;
    if(silinecekindex < 1 || silinecekindex > kayitsayisi) {
        cout << "Gecersiz numara." << endl;
        return;
    }
    int silinecek = silinecekindex - 1;
    
    for (int i = silinecek; i < kayitsayisi - 1 ; i++) {
        t[i] = t[i + 1];
    }
    kayitsayisi--;

    cout << "Kayit basariyla silindi." << endl;
}

void tarihekle(Tarih t[], int &kayitsayisi){
    if(kayitsayisi >= 100000) {
        cout << "Kayit limiti doldu. Yeni kayit eklenemiyor." << endl;
        
    }
    Tarih yeniTarih;
    cout << "Yeni tarih bilgilerini giriniz." << endl;
    cout << "Gun: ";
    cin >> yeniTarih.gun;
    cout << "Ay: ";
    cin >> yeniTarih.ay;
    cout << "Yil: ";
    cin >> yeniTarih.yil;

    t[kayitsayisi] = yeniTarih;
    kayitsayisi++;

    cout << "Yeni tarih basariyla eklendi." << endl;
}

void alacakverecek(int &kayitsayisi){
    int alacak,verecek;
    alacak=0;
    for(int i=0;i<kayitsayisi;i++){
        alacak+=1000;

    }
    cout << "Toplam Verecek: " << endl;
    cin >> verecek;
    alacak-=verecek;
    cout << "Toplam Alacak: " << alacak << endl;
}

int main() {

    Tarih tarihler[100];
    int kayitsayisi = 0;

    verileriyukle(tarihler, kayitsayisi);
    int secim;

    while(true){

    cout << "\n--- GUNLUK TAKIP MENUSU ---" << endl;
    cout << "1. Tarih Ekle" << endl;
    cout << "2. Tarih Sil" << endl;
    cout << "3. Tarihleri Listele" << endl;
    cout << "4. Alacak Verecek"<< endl;
    cout << "5. Cikis ve Kaydet" << endl;
    cout << "Seciminizi giriniz (1-5): ";
    cin >> secim;
        
    switch (secim) {
        case 1:
            tarihekle(tarihler, kayitsayisi);
            break;
        case 2:
            tarihsil(tarihler, kayitsayisi);
            break;
        case 3:
            tarihlerlistesi(tarihler, kayitsayisi);
            break;
        case 4:
            alacakverecek(kayitsayisi);
        break;

        case 5:
            verilerikaydet(tarihler, kayitsayisi);
            cout << "Cikis yapiliyor..." << endl;
            return 0;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyiniz." << endl;


            /*

            2.000
            5.000
            2.000
            2yarım gün(-1000)
            10.000

            en son alınan 20.000(10.01.2026)
            */
            
            
            
    }}
    
    return 0;
}

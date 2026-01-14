# 📅 GunlukTakip - C++ Tarih ve Alacak Takip Sistemi

Bu proje, basit bir C++ konsol uygulaması olup kullanıcının belirli tarihleri kaydetmesine, silmesine, listelemesine ve bu kayıtlara bağlı olarak basit bir alacak-verecek hesabı yapmasına olanak tanır. Veriler `tarihler.txt` dosyasında kalıcı olarak saklanır.

## 🚀 Özellikler
* **Veri Saklama:** Program açıldığında eski kayıtları yükler, kapatıldığında (5. seçenek ile) verileri otomatik olarak `tarihler.txt` dosyasına yazar.
* **Kayıt Yönetimi:** Çalışma zamanında yeni tarihler eklenebilir veya mevcut kayıtlar silinebilir.
* **Alacak-Verecek Hesabı:** Kayıtlı gün sayısı üzerinden (her gün için 1000 birim baz alınarak) borç/alacak hesaplaması yapar.
* **Hata Kontrolü:** Dosya bulunamadığında veya geçersiz menü seçimi yapıldığında kullanıcıyı uyarır.

## 🛠️ Teknik Detaylar
* **Dil:** C++
* **Veri Yapısı:** `struct` kullanılarak tarih bilgileri (`gun`, `ay`, `yil`) gruplandırılmıştır.
* **Dosya Yönetimi:** `fstream` kütüphanesi ile metin dosyası okuma ve yazma işlemleri gerçekleştirilir.
* **Algoritma:** Silme işleminde dizi elemanları kaydırılarak (shifting) veri bütünlüğü korunur.



## 📋 Nasıl Çalıştırılır?

1.  Bilgisayarınızda bir C++ derleyicisinin (GCC, Clang, MSVC vb.) kurulu olduğundan emin olun.
2.  Dosyayı indirin ve bir terminal açın.
3.  Aşağıdaki komutla derleyin:
    ```bash
    g++ main.cpp -o GunlukTakip
    ```
4.  Uygulamayı çalıştırın:
    ```bash
    ./GunlukTakip
    ```

## 📖 Kullanım Senaryosu
Program ilk açıldığında `tarihler.txt` dosyasını kontrol eder. Eğer dosya varsa eski kayıtları yükler. Menü üzerinden:
* `1` ile yeni bir tarih ekleyebilir,
* `2` ile listedeki hatalı bir kaydı silebilir,
* `4` ile toplam bakiyenizi (Gün sayısı * 1000 - Alınan Ödeme) kontrol edebilirsiniz.
* `5` tuşuna basarak çıktığınızda verileriniz kaydedilir.

* ## 👥 Geliştiriciler
*   Enes Canlı

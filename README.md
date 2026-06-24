# 🧩 Sokoban Puzzle

## 1. Giriş

Bu proje, **C++ programlama dili** ve **Raylib** kütüphanesi kullanılarak geliştirilen 2D bir puzzle oyunudur. Oyuncu, karakteri kontrol ederek sandıkları belirli hedeflere yerleştirmeye çalışır. Seviyelerdeki **engeller**, **buz mekaniği** ve **kapan sistemleri** ile oyun karmaşıklaşır.

Proje, **nesne yönelimli programlama (OOP)** prensiplerine uygun olarak modüler bir yapıda tasarlanmıştır.

---

### 2. Kontroller
- **Hareket:**  
  -  Karakter `W`, `A`, `S`, `D` tuşları veya `ok tuşları` ile kontrol edilir.
- **Geri Alma (Undo):**  
  - `G` tuşuyla hamleler geri alınır.
- **Seviye Yenileme:**  
  - `T` tuşuyla seviye yenilenir .

---



[![Oyunun videosu](readme/playerFace.png)](https://youtu.be/DmZPjBDGy5Q)

## 3. Projenin Temel İçeriği

- **Başlangıç Ekranı:** Oyunun başlangıç menüsü ve geçişi
![Başlangıç Ekranı GIF](readme/baslatmaekrani.gif)
- **Karakter Kontrolü:** WASD ve ok tuşları ile hareket ve sandık itme
![Kutu Itme Mekaniği GIF](readme/kutuitme.gif)
- **Sandık-Hedef Eşleştirme:** Renkli sandıkları doğru hedeflere taşıma
![Sandık Hedef Eşleştirme GIF](readme/farklirenkler.gif)
- **Buz Mekaniği:** Buz üzerinde kayma 
![Buz Mekaniği GIF](readme/buz.gif)
- **Kapan & Anahtar Sistemi:** Anahtarların basılmasıyla açılan kapılar
![Kapan Mekaniği GIF](readme/kapan.gif)
- **Seviye Sistemi:** Birden fazla seviye ve ilerleme
![Seviyeler GIF](readme/seviyeler.gif)
- **Geri Alma (Undo):** Karakter ve sandıkları geri alabilme özelliği
![Geri Alma GIF](readme/gerialma.gif)
## 3. Sistem Tasarımı ve Sınıf Yapısı

Proje, nesne yönelimli prensiplere göre modüler şekilde tasarlanmıştır. Sınıflar üç ana grupta toplanmıştır:

### a. Temel Sınıflar

- **GameObject:** Tüm oyun nesnelerinin türediği soyut sınıf. `Guncelle()` ve `Ciz()` metodlarını içerir.
- **Karakter:** Oyuncunun kontrol ettiği karakter. Hareket, animasyon ve buzda kayma mekanikleri bu sınıfta yönetilir.
- **Sandık:** Renk, konum ve hedef kontrolü özellikleri bulunur. Hedeflere taşınması gereken nesnelerdir.
- **Hedef:** Sandıkların yerleştirilmesi gereken hücrelerdir.
- **Kapan:** Anahtarlar basıldığında açılan kapılardır.

### b. Yönetici Sınıflar

- **ObjeYonetici:** Oyun nesnelerinin (karakter, sandık, hedef) yönetiminden sorumlu.
- **DurumYonetici:** Geri alma özelliği için oyun durumunu kaydeder ve yükler.
- **DokuYonetici:** Görsellerin yüklenmesi ve çizilmesinden sorumludur.
- **KesisimKontrolcu:** Çarpışma ve etkileşim kontrollerinden sorumludur.
- **SeviyeSistemi:** Seviye yükleme, seviyeler arası geçiş ve tamamlanma şartının sorgulamasından sorumludur.

### c. Diğer Bileşenler

- **BaslangicEkrani:** Başlangıç menüsü ve buton yönetimi.
- **GirdiKontrolcu:** Klavye girdilerinin işlenmesi.

---

## 4. Oyun Mekanikleri ve Algoritmalar

### a. Hareket ve Kesişimler

- Karakter ve sandıklar, `KesisimKontrolcu` yardımıyla duvar, sandık ve kapı kesişimlerini kontrol eder.
- Buz üzerinde, nesneler sonraki engelsiz noktaya kadar kayar.

### b. Geri Alma (Undo)

- `DurumYonetici`, her hamle sonrası karakter ve sandık konumlarını kaydeder.
- `GeriAl()` metodu ile önceki durumlara dönülebilir.

### c. Seviye Yükleme

- Sandık, hedef, kapan, karakter konumları ve özellikleri ve harita matrisi her seviyede, seviyeler vektöründen okunur.

---

## 5. Kurulum ve Derleme

### Gereksinimler

- [Raylib 4.5.0](https://github.com/raysan5/raylib/releases/tag/4.5.0)
- C++14 destekli derleyici
  - **Windows:** w64devkit (Raylib Windows kurulumunda dahili gelir)
  - **Linux:** g++
  - **macOS:** clang++

### Windows

1. Raylib 4.5.0'ı indirip kurun (`C:/raylib` dizinine).
2. Projeyi Raylib dizini içine yerleştirin:
   ```
   C:/raylib/
   ├── src/
   ├── sokoban_puzzle/   ← projeyi buraya koyun
   └── ...
   ```
3. Proje dizininde terminali açın ve derleyin:
   ```bash
   mingw32-make
   ```
4. Oluşan `game.exe` dosyasını çalıştırın.

### Linux

```bash
sudo apt install libraylib-dev   # veya raylib'i kaynaktan derleyin
make
./game
```

### macOS

```bash
brew install raylib
make
./game
```

---

## 6. Kullanıcı Arayüzü

- **Başlangıç Menüsü:** "Başla" butonu ile oyuncuyu karşılar.
- **Oyun İçi Arayüz:** Seviye numarası ve kontrol butonları (önceki seviye, seviye yenileme, sonraki seviyeye).
- **Seviye Tamamlama Ekranı:** "Sonraki Seviye", "Tekrarla" ve "Önceki Seviye" seçeneklerini içerir.

---


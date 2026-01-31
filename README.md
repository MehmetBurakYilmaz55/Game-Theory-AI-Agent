# 🧠 Game Theory & Perfect Play AI Agent


Bu proje, tarafsız oyunlar (impartial games) için geliştirdiğim, oyunun herhangi bir anında kazanmayı matematiksel olarak garantileyen (Perfect Play) bir yapay zeka ajanıdır. C++ ile geliştirilen bu algoritma, **Dinamik Programlama** ve **Oyun Ağacı Analizi** yöntemlerini kullanır.

## 🚀 Motivasyon ve Hikaye (Origin Story)
Bu projenin temelleri, lise yıllarımda izlediğim **"A Beautiful Mind" (Akıl Oyunları)** filmi ve **John Nash**'in çalışmalarına duyduğum hayranlıkla atıldı. O dönemde **Prof. Dr. Ali Nesin**'in Oyunlar Kuramı üzerine matematiksel modellemelerini incelemiştim.

Üniversite eğitimim sırasında aldığım C programlama ve algoritma dersleriyle birlikte, yıllar önce teorik olarak öğrendiğim bu matematiksel modelleri gerçek bir yazılıma dönüştürmeye karar verdim.

## 🛠️ Geliştirme Süreci (Development Lifecycle)
Projeyi 48 saatlik yoğun bir "Sprint" ile hayata geçirdim. Mühendislik yaklaşımını korumak adına süreci ikiye böldüm:

* **Gün 1: Matematiksel Modelleme:** Kod yazmaya başlamadan önce, Ali Nesin'in ders notlarını revize ederek oyunun kazanma/kaybetme durumlarını kağıt üzerinde modelledim. Algoritmanın "karar ağacını" (decision tree) teorik olarak oluşturdum.
* **Gün 2: Uygulama (Implementation):** Oluşturduğum matematiksel modeli C++ diline, bellek yönetimi (memory management) kurallarına dikkat ederek aktardım.

## 🧪 Test ve Doğrulama
Algoritma, geliştirme sonrası "insan oyunculara" karşı kapsamlı testlere tabi tutulmuştur.
* **Sonuç:** Yapılan onlarca denemede, algoritma matematiksel olarak kazanmanın mümkün olduğu her senaryoda **%100 galibiyet oranı** yakalamıştır.
* İnsan rakipler (arkadaşlarım), algoritmanın hatasız (bug-free) oyun stili karşısında kazanmanın imkansız olduğunu doğrulamıştır.

## ⚙️ Teknik Detaylar
Bu projede aşağıdaki bilgisayar bilimleri konseptleri kullanılmıştır:
* **Dynamic Programming:** Alt problemlerin çözümlerini (`analizler` dizisi) saklayarak hesaplama verimliliği sağlandı.
* **State Space Search:** Olası tüm hamlelerin sonuç uzayı tarandı.
* **Memory Management:** `calloc` ve pointer aritmetiği ile dinamik bellek tahsisi yapıldı.
* **Game Theory:** Zermelo teoremi ve Nash dengesi prensipleri uygulandı.

## 💻 Kurulum ve Kullanım
Kodu derlemek ve yapay zekaya meydan okumak için:

```bash
g++ ImpartialGameSolver.cpp -o GameSolver
./GameSolver


---

# 🧴 HandSanitizer Otomatic – IoT Hand Sanitizer Otomatis

**Sanitizer Otomatic** adalah alat **dispenser hand sanitizer otomatis berbasis sensor inframerah dan servo motor**. Alat ini dikembangkan sebagai solusi untuk menjaga kebersihan tangan tanpa sentuhan, mengurangi risiko penyebaran kuman dan virus, serta memberikan kemudahan bagi pengguna di area publik.

> 📘 **Catatan:** Proyek ini merupakan *proyek Ujian Akhir Semester (UAS)* dari mata kuliah **Internet of Things (IoT)**. Tujuannya adalah untuk menerapkan konsep sensor, aktuator, mikrokontroler, dan otomasi berbasis IoT dalam kehidupan nyata.

---

## 👥 Pengerjaan Kelompok

Proyek ini dikerjakan secara berkelompok oleh mahasiswa dengan rincian sebagai berikut:

**Kelompok: Otomatic HandSanitizer**

| Nama                          | NRP         |
| ----------------------------- | ----------- |
| Muhammad Rafli Nurfathan      | 221-111-009 |
| Dea Rismi Oktoris             | 221-221-001 |
| Elisabeth Patricia Jelly Ma’u | 221-221-003 |

---

## 🎯 Fitur Utama

* ✅ Deteksi otomatis keberadaan tangan menggunakan sensor IR
* ✅ Gerakan servo motor untuk menyemprotkan hand sanitizer
* ✅ Kembali otomatis ke posisi awal setelah menyemprot
* ✅ Monitoring status sensor melalui Serial Monitor
* ✅ Mudah dirakit dan cocok untuk skala kecil maupun besar

---

## 🔧 Komponen yang Digunakan

| Komponen                  | Fungsi                                  |
| ------------------------- | --------------------------------------- |
| Arduino Uno/Nano          | Mikrokontroler utama                    |
| Sensor IR (Inframerah)    | Mendeteksi tangan di depan alat         |
| Servo Motor x2            | Menekan botol sanitizer secara otomatis |
| Breadboard & Kabel Jumper | Menyusun rangkaian elektronik           |
| Botol Sanitizer           | Wadah cairan pembersih tangan           |
| Power Supply              | Catu daya melalui USB atau baterai      |

---

## ⚙️ Cara Kerja

1. Sensor inframerah terus memantau keberadaan tangan.
2. Ketika tangan terdeteksi (sinyal LOW), sistem mengaktifkan dua servo motor.
3. Servo menekan botol hand sanitizer secara bersamaan.
4. Setelah 1 detik, servo kembali ke posisi semula.
5. Sistem menunggu sebelum memulai siklus deteksi kembali.

---

## 📂 Cuplikan Kode

```cpp
#include <Servo.h>

const int irPin = 9;
Servo servo1;
Servo servo2;
const int servoPin1 = 5;
const int servoPin2 = 6;

bool isObjectDetected() {
  return digitalRead(irPin) == LOW;
}

void setup() {
  pinMode(irPin, INPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  Serial.begin(9600);
}

void loop() {
  bool objectDetected = isObjectDetected();
  Serial.print("Objek Terdeteksi: ");
  Serial.println(objectDetected ? "Ya" : "Tidak");

  if (objectDetected) {
    servo1.write(90);
    servo2.write(90);
    delay(1000);
    servo1.write(0);
    servo2.write(0);
    delay(1000);
  }

  delay(500);
}
```

---

## 🔌 Skema Rangkaian IoT dan Tampilan Proyek

Berikut adalah hasil proyek:
![IOT](https://github.com/user-attachments/assets/451e331d-f33c-4d7f-8032-bb99cb3660a9)

### 🖼️ Gambar Skema

![skema](https://github.com/user-attachments/assets/4a1e3a7e-38dd-4bdd-b0f9-a5b61aeec4b0)

*Catatan: Gambar hanya ilustrasi. Penempatan pin dapat disesuaikan.*

---

## 🛠 Teknologi & Bahasa

| Teknologi   | Keterangan                    |
| ----------- | ----------------------------- |
| Arduino C++ | Bahasa untuk mikrokontroler   |
| Arduino IDE | Lingkungan pengembangan utama |
| IR Sensor   | Deteksi keberadaan tangan     |
| Servo Motor | Menggerakkan botol sanitizer  |

---

## 🚀 Rencana Pengembangan

* 🌐 Integrasi ESP8266/ESP32 untuk fitur pemantauan jarak jauh
* 📱 Dashboard pemantauan jumlah penggunaan sanitizer harian
* 🔋 Power bank atau solar panel untuk penggunaan luar ruangan
* 🔔 Sistem notifikasi isi ulang sanitizer

---

## 📧 Kontak Pengembang

* 👤 Nama: **Muhammad Rafli Nurfathan**
* 📧 Email: **[nurfathanrafli85@gmail.com](mailto:nurfathanrafli85@gmail.com)**
* 🔗 LinkedIn: [linkedin.com/in/mhmmdraflin](https://www.linkedin.com/in/mhmmdraflin)

---

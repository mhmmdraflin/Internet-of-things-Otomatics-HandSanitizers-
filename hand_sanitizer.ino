#include <Servo.h>

// Deklarasi untuk sensor inframerah
const int irPin = 9; // Pin untuk sensor inframerah

// Deklarasi untuk motor servo
Servo servo1;
Servo servo2;
const int servoPin1 = 5;
const int servoPin2 = 6;

// Fungsi untuk mendeteksi objek dengan sensor inframerah
bool isObjectDetected() {
  return digitalRead(irPin) == LOW; // Asumsikan LOW berarti objek terdeteksi
}

void setup() {
  // Inisialisasi pin sensor dan servo
  pinMode(irPin, INPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // Mulai komunikasi serial untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Periksa apakah objek terdeteksi oleh sensor inframerah
  bool objectDetected = isObjectDetected();
  Serial.print("Objek Terdeteksi: ");
  Serial.println(objectDetected ? "Ya" : "Tidak");
  
  // Jika tangan terdeteksi
  if (objectDetected) {
    // Gerakkan servo untuk mengeluarkan hand sanitizer
    servo1.write(90); // Sesuaikan dengan kebutuhan
    servo2.write(90); // Sesuaikan dengan kebutuhan
    delay(1000);      // Tunda untuk memberikan waktu servo bergerak
    // Kembalikan servo ke posisi awal
    servo1.write(0);
    servo2.write(0);
    delay(1000);      // Tunda sebelum pengukuran berikutnya
  }
  
  // Tunda sebelum pengukuran berikutnya
  delay(500);
}

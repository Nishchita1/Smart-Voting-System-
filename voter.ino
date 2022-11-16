#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_Fingerprint.h> 

SoftwareSerial mySerial(2, 3);
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int Buzzer = 7;
int fingerprintID=0;

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer,LOW);
  delay(50);

  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  
}
void ff()
{
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }
  delay(5000);
  
}
void buzz()
{
  digitalWrite(Buzzer,HIGH);
  Serial.println("ALERT");
  delay(1000);
  digitalWrite(Buzzer,LOW);
  delay(1000);
}
void RFID()
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "53 65 E9 16") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println("Nishchita Kumari");
    delay(1000);
    ff();
    delay(3000);
    startFingerprintSensor();
  }
 else if (content.substring(1) == "CA 72 81 B0") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println("Supriya P M");
    delay(1000);
    ff();
    delay(3000);
    startFingerprintSensor();
  }
   else if (content.substring(1) == "7A B7 B8 B0") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println("Ashwini H K");
    delay(1000);
    ff();
    delay(3000);
    startFingerprintSensor();
  }
  else if (content.substring(1) == "DA BD B4 AF") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println("Vanishree K T");
    delay(1000);
    ff();
    delay(3000);
    startFingerprintSensor();
  }
 else
 {
    Serial.println(" Access denied");
    buzz();
    delay(1000);
  }
}
int getFingerprintID() 
 {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
void startFingerprintSensor()
{
  fingerprintID = getFingerprintID(); //We scan the fingerprint here
  delay(50);
  if(fingerprintID == 11) //We have found a valid fingerprint with the id 1
  {
    Serial.println("First person");
    delay(1000);
    Serial.println("Open Facial Recognition");
  }   
  else if(fingerprintID == 10)
    {//We have found a valid fingerprint with the id 2  {
    Serial.println("Second person");
    delay(1000);
    Serial.println("Open Facial Recognition");
    }
    else if(fingerprintID == 1)
    {//We have found a valid fingerprint with the id 2  {
    Serial.println("AUTHORIZER PERSON");
    delay(1000);
    Serial.println("Open Facial Recognition");
    }
     else if(fingerprintID == 2)
    {//We have found a valid fingerprint with the id 2  {
    Serial.println("AUTHORIZER PERSON");
    delay(1000);
    Serial.println("Open Facial Recognition");
    }
     else if(fingerprintID == 12)
    {//We have found a valid fingerprint with the id 2  {
    Serial.println("AUTHORIZER PERSON");
    delay(1000);
    Serial.println("Open Facial Recognition");
    }
     else if(fingerprintID == 3)
    {//We have found a valid fingerprint with the id 2  {
    Serial.println("AUTHORIZER PERSON");
    delay(1000);
    Serial.println("Open Facial Recognition");
    }
     else if(fingerprintID == 9)
    {//We have found a valid fingerprint with the id 2  {
    Serial.println("AUTHORIZER PERSON");
    delay(1000);
    Serial.println("Open Facial Recognition");
    }
    else 
    {
      Serial.println("UNAUTHORIZER PERSON");
      delay(500);
      buzz();
    }
}
void loop() 
{
 RFID();
 delay(500);
}

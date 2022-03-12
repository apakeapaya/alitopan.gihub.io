#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

int Buzzer = 8;

//Bluetooth Var
SoftwareSerial Blue(5, 6);
long int data;
long int password1 = 92;// Unlock
long int password2 = 79; // Locked
char state = 0;
 
//Solenoid Var
int hall_sensor = 7;
int state1, lockread,motion;
const int LockPin = 2;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// Button
const int BUTTON_PIN = 4; // Arduino pin connected to button's pin

void setup() 
{
  Blue.begin(9600);     //initiate Bluetooth
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus

  //Input and Output
  pinMode(LockPin, OUTPUT);
  pinMode(hall_sensor, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(Buzzer, OUTPUT);
  // Initiate MFRC522
  mfrc522.PCD_Init();   
  //Serial.println("Approximate card to the reader...");
  // Serial.println();
  digitalWrite(LockPin, HIGH);
  digitalWrite(Buzzer, HIGH);

}

void loop() 
{
readsensor();
sensor();


  //Button................................................................

  int buttonState = digitalRead(BUTTON_PIN); // read new state

  if (buttonState == HIGH) {
    Serial.println("The button is being pressed");
    digitalWrite(LockPin, LOW); // turn on
    delay(3000);
    sensor();
  }

  // Blutooth Aplication.....................................................
   if(Blue.available()>0){
     data = Blue.parseInt();
     
     //Serial.print(data);
    
    if (data == password1)
    {
    digitalWrite(LockPin,LOW);
    Serial.println("Unlock Door ");
    digitalWrite(Buzzer, HIGH);
    delay(3000);
    digitalWrite(Buzzer, LOW);

   sensor();   
   }
     
    if( data == password2)
    {
     digitalWrite(LockPin,HIGH);
     Serial.println("Lock Door");
    }delay(500);
  }
 

  //Solenoid.........................................................................
  // Look for new cards
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

  //Serial.println();
  //Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) =="04 30 7B CA 18 52 80") //change here the UID of the card/cards that you want to give access
  {   
    digitalWrite(LockPin, LOW);
    Serial.print("Door Unlocked");
    digitalWrite(Buzzer, LOW);
    delay(3000);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LockPin, HIGH);

    sensor();
    }
 if (content.substring(1) =="D1 91 32 21") //change here the UID of the card/cards that you want to give access
  {   
    digitalWrite(LockPin, LOW);
    Serial.print("Door Unlocked");
    digitalWrite(Buzzer, LOW);
    delay(3000);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LockPin, HIGH);

    sensor();
    }
    if (content.substring(1) =="4C D6 3B 4A") //change here the UID of the card/cards that you want to give access
  {   
    digitalWrite(LockPin, LOW);
    Serial.print("Door Unlocked");
    digitalWrite(Buzzer, LOW);
    delay(3000);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LockPin, HIGH);
 
    sensor();
    }
 if (content.substring(1) =="04 14 6A 42 D7 28 80") //change here the UID of the card/cards that you want to give access
  {   
    digitalWrite(LockPin, LOW);
    Serial.print("Door Unlocked");
    digitalWrite(Buzzer, LOW);
    delay(3000);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LockPin, HIGH);

    sensor();
    }
  if (content.substring(1) =="04 14 6B 42 D7 28 80") //change here the UID of the card/cards that you want to give access
  {   
    digitalWrite(LockPin, LOW);
    Serial.print("Door Unlocked");
    digitalWrite(Buzzer, LOW);
    delay(3000);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LockPin, HIGH);

    sensor();
    }
  else
  {
   Serial.println("You are not Authorised"); 
   digitalWrite(LockPin, HIGH);
   delay(2000);

  }

}


//Function Hall Sensor
void readsensor()
{
 lockread = digitalRead(LockPin);
 state1 = digitalRead(hall_sensor);

 //delay(2000); 
 //Serial.print(lockread);
 //Serial.print(state1);
 
}

void sensor()
{
 readsensor();
 if (lockread == LOW){  
     readsensor();
     if(state1 == HIGH){
      digitalWrite(LockPin, HIGH);
      Serial.print("Door Closed!!");
      digitalWrite(Buzzer, LOW);
      delay(2000);
      digitalWrite(Buzzer, HIGH);
     }

   }
 }

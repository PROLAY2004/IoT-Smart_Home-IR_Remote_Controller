const int irPin = 4;
const int Relay1 = 0;
const int Relay2 = 1;
const int Relay3 = 2;
const int Relay4 = 3;

boolean Relay1State = false;
boolean Relay2State = false;
boolean Relay3State = false;
boolean Relay4State = false;

void setup() {
  
  //Serial.begin(115200);
  pinMode(irPin, INPUT);
  
pinMode(Relay1, OUTPUT);
pinMode(Relay2, OUTPUT);
pinMode(Relay3, OUTPUT);
pinMode(Relay4, OUTPUT);
}

void loop() {
  int key = getIrKey();

  
  if(key ==  1269 ){
    Relay1State = !Relay1State;
    if(Relay1State == true)
      digitalWrite(Relay1, HIGH);
    else
      digitalWrite(Relay1, LOW);
  }

  
  if(key == 1524 ){
    Relay2State = !Relay2State;
    if(Relay2State == true)
      digitalWrite(Relay2, HIGH);
    else
      digitalWrite(Relay2, LOW);
  }
 
  if(key == 1779 ){
   
    Relay3State = !Relay3State;
    if(Relay3State == true)
      digitalWrite(Relay3, HIGH);
    else
      digitalWrite(Relay3, LOW);
  }

   if(key == 2034 ){
    
    Relay4State = !Relay4State;
    if(Relay4State == true)
      digitalWrite(Relay4, HIGH);
    else
      digitalWrite(Relay4, LOW);
  }

}

int getIrKey(){
  int len = pulseIn(irPin,LOW);
  int key, temp;
  key = 0;
  //Serial.print("len=");
  //Serial.println(len);
  if(len > 5000) {
    for(int i=1;i<=32;i++){
      temp = pulseIn(irPin,HIGH);
      if(temp > 1000)
        key = key + (1<<(i-17));
    }
  }
  if(key < 0 )
    key = -key;
  
  //if(key)
    //Serial.println(key);

    delay(250);
  return key;
}

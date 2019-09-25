#define RELAY_Pr 2 //relay Proektor pin
#define RELAY_Led 3 //relay Chiroq pin
bool prYongan;
bool ledYongan;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RELAY_Pr, OUTPUT);
  pinMode(RELAY_Led, OUTPUT);
  
  digitalWrite(RELAY_Pr, HIGH);
  digitalWrite(RELAY_Led, HIGH);
  prYongan = false;
  ledYongan = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      char c = Serial.read();
      if(c == 'C')
      {
        if(ledYongan == false){
          ledYongan = true;
          digitalWrite(RELAY_Led, LOW);
        }else{
          ledYongan = false;
          digitalWrite(RELAY_Led, HIGH);
        }
      }
      if(c == 'P')
      {
        if(prYongan == false){
          prYongan = true;
          digitalWrite(RELAY_Pr, LOW);
        }else{
          prYongan = false;
          digitalWrite(RELAY_Pr, HIGH);
        }
      }
    }
}

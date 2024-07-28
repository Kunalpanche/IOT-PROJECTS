int Green = 5;
int Blue = 9;
int Red = 6;

void setup() {
  Serial.begin(9600);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Red, OUTPUT);


}


char c;
String voice;

void loop() {
  if (Serial.available() > 0)
  {
    voice = "";
    voice = Serial.readString();
    Serial.print(voice + '\n');
  }

  if (voice == "green")
  {
    digitalWrite(Green, HIGH);
  } else if (voice == "green off")
  {
    digitalWrite(Green, LOW);
  }

  if (voice == "blue")
  {
    digitalWrite(Blue, HIGH);
  } else if (voice == "blue off")
  {
    digitalWrite(Blue, LOW);
  }


  if (voice == "red")
  {
    digitalWrite(Red, HIGH);
  } else if (voice == "red off")
  {
    digitalWrite(Red, LOW);
  }

}

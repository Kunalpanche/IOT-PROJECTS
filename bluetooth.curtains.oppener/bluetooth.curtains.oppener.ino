int val;

int nb;

void setup() {

// put your setup code here, to run once:

Serial.begin(9600);

pinMode(3,OUTPUT);

pinMode(5,OUTPUT);

pinMode(6,OUTPUT);

pinMode(7,INPUT);

}

// put your main code here, to run repeatedly:

void loop()

{

if(Serial.available()>0)

{

int data= Serial.read();

Stop();

if(data=='R')

{

digitalWrite(3,HIGH);

digitalWrite(5,LOW);

digitalWrite(7,HIGH);

digitalWrite(6,LOW);

}

else if(data=='L')

{

digitalWrite(3,LOW);

digitalWrite(5,HIGH);

digitalWrite(7,LOW);

digitalWrite(6,HIGH);

}else if(data=='F'){

digitalWrite(3,LOW);

digitalWrite(5,HIGH);

digitalWrite(7,HIGH);

digitalWrite(6,LOW);

}else if(data=='B'){

digitalWrite(3,HIGH);

digitalWrite(5,LOW);

digitalWrite(7,LOW);

digitalWrite(6,HIGH);

}

}

}

void Stop()

{

digitalWrite(3,LOW);

digitalWrite(5,LOW);

digitalWrite(7,LOW);

digitalWrite(6,LOW);

}
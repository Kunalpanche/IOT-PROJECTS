
#include <MaxMatrix.h>

#include <SoftwareSerial.h>// import the serial library


SoftwareSerial BT(0, 1);  // RX, TX


int DIN = 11;   // DIN pin of MAX7219 module

int CLK = 13;   // CLK pin of MAX7219 module

int CS = 10;    // CS pin of MAX7219 module

int maxInUse = 1;


boolean red = true;

boolean toggle = true;



MaxMatrix m(DIN, CS, CLK, maxInUse);


void setup()

{

  BT.begin(9600); //start the Bluetooth communication at 9600 baudrate

  Serial.begin(9600);

  // BT.println("Bluetooth working");


  m.init(); // MAX7219 initialization

  m.setIntensity(8); // initial led matrix intensity, 0-15

  m.clear(); // Clears the display



}


int incoming;

int Y = 0;

int X = 0;


void loop()

{

  if (BT.available())

  {

    incoming = BT.read();

    Serial.println(incoming);


    if (incoming==0)

      m.clear(); // Clears the display

      

    else if (incoming == 100)//Check if we should on or off the LED

    {

      if (red == true)

      red= false;

      else if (red == false)

      red= true;


        Serial.print("RED:");  Serial.println(red);

    }

    

    else if (incoming<=64)

    { //Calculate where to ON ro OFF the LED

      toggle=true;

    Y = incoming / 8;

    X = incoming - (Y * 8);


    if (incoming%8 == 0)

      {X = 8; Y -= 1;}



    Serial.println(X - 1);

    Serial.println(Y);

    if(red==true)

    m.setDot((X - 1), (Y), true); //LED ON

    else if (red == false)

    m.setDot((X - 1), (Y), false); //LED OFF

    

    }

  }


}

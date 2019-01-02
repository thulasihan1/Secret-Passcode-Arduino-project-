
#include <Servo.h>
// create an instance of the servo library
Servo myServo;

const int switchPin = 2;    // pin the switch is attached to
const int yellowLed = 3;    // pin the yellow LED is attached to
const int greenLed = 4;    // pin the green LED is attached to
const int redLed = 5;   // pin the red LED is attached to
const int blueLed= 7;
int pins[2]={10,11};
int i;


// variable for the switch value
int switchVal;
int t;
int w;
int h;
int j;
int c=0;
int v=0;
int r=0;
int m=0;
int k=0;

int reset=12;

 



// variable to indicate if locked or not
boolean locked = false;


void setup(){
pinMode(yellowLed,OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(redLed,OUTPUT);
pinMode(7,OUTPUT);


  
  // attach the servo to pin 9
  myServo.attach(9);

  // make the LED pins outputs


  // set the switch pin as an input
  pinMode(switchPin, INPUT);

  // start serial communication for debugging
  Serial.begin(9600);

  // turn the green LED on
  digitalWrite(greenLed, HIGH);

  // move the servo to the unlocked position
  myServo.write(0);

  // print status to the serial monitor
  Serial.println("the box is unlocked!");

for(i=0;i<2;i++)
{
pinMode(pins[i],INPUT);
i++;
  
}

  
}

void loop(){


  // if the box is unlocked
  if(locked == false){
    
 // read the value of the switch pin
    switchVal = digitalRead(switchPin);
      
  
    
   
    

    // if the button is pressed, lock the box
    if(switchVal == HIGH){
      // set the locked variable to "true"
      locked = true;

      // change the status LEDs
      digitalWrite(greenLed,LOW);
      digitalWrite(redLed,HIGH);

      // move the servo to the locked position
      myServo.write(90);

      // print out status
      Serial.println("the box is locked!");

      // wait for the servo to move into position
      delay (1000);
    }
  }



 if(locked==true)
  {
    t=digitalRead(pins[0]);
   w=digitalRead(pins[1]);
     h=digitalRead(reset);

      if(t!=c)
      {
      

      if(t==HIGH )
      {
         digitalWrite(yellowLed,HIGH);
      delay(50);
      digitalWrite(yellowLed,LOW);
      r++;
       Serial.println(r);
      if(m==0)
      {
        m=1;
      }
          }

        }

 if(w!=v)
      {
          if(w==HIGH)
          {
            
           digitalWrite(yellowLed,HIGH);
      delay(50);
      digitalWrite(yellowLed,LOW);
      r++;
      Serial.println(r);
      if(m==1)
      {
        m=2;
      }
            }
      }
  
  }

    if(k!=h){
       if(h=HIGH)
      {
        r=0;
        m=0;
        Serial.println("RESET");
        digitalWrite(blueLed,HIGH);
        delay(200);
         digitalWrite(blueLed,LOW);
         delay(200);
      }
          }

 



      if(m==2&& r==2)
    {
       m=0;
       r=0;
      
        locked = false;

      // change the status LEDs
      digitalWrite(greenLed,HIGH);
      digitalWrite(redLed,LOW);

      // move the servo to the locked position
      myServo.write(0);

      // print out status
      Serial.println("the box is unlocked!");

      // wait for the servo to move into position
      delay (1000);
      }
      else
      if(r>2)
      {
        r=0;
        m=0;
        Serial.println("Try Again");
        for(j=0;j<3;j++)
        {
        digitalWrite(redLed,HIGH);
        delay(500);
        digitalWrite(redLed,LOW);
        delay(500);
        }
        digitalWrite(redLed,HIGH);
      }
        else 
        if(r==2 && m==1)
        {
        r=0;
        m=0;
        Serial.println("Try Again");
        for(j=0;j<3;j++)
        {
        digitalWrite(redLed,HIGH);
        delay(500);
        digitalWrite(redLed,LOW);
        delay(500); 
          
        }
        digitalWrite(redLed,HIGH);
      }



          



  
}
 
  
   
    

 
    
      
    
    
  



  







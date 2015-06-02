#include <EEPROM.h>
#include <UF_uArm_Metal.h>

UF_uArm uarm;           // initialize the uArm library 
int dlrstretch = 120;
int maxdeals = 5;
int x = 0;


void setup() 
{
  Serial.begin(9600);
  
  uarm.init();          // initialize the uArm position
 
  uarm.setServoSpeed(SERVO_R, 75);  // 0=full speed, 1-255 slower to faster
  uarm.setServoSpeed(SERVO_L, 75);  // 0=full speed, 1-255 slower to faster
  uarm.setServoSpeed(SERVO_ROT, 75); // 0=full speed, 1-255 slower to faster
  delay(500);


  Serial.println("Servo speed setting complete");
  
  deckstartpointer();
  delay(5000);
  
  Serial.println("Start Init");
  uarm.init();
  delay(2000);
  Serial.println("Start Init Complete");
}

void loop()
{
    for (x; x < maxdeals; x++) 
    {
        Serial.write('x = ' + x);
        Serial.println();
        
        dealcard();
    } 
} 


void deckstartpointer()
{
  Serial.println("Deck Start Pointer Init");
 
  uarm.setPosition(dlrstretch, 0, 0, 0);    // stretch out
 
  Serial.println("Deck Start Point Complete");
}

void dealcard()
{
  Serial.println("Deal Card Init");

  uarm.setPosition(dlrstretch, 0, 0, 0);    // stretch out
  delay(3500);
  uarm.setPosition(dlrstretch, -45, 0, 0);  // down
  delay(1000);  
  uarm.gripperCatch();               // catch
  delay(1500);
  uarm.setPosition(dlrstretch, 0, 0, 0);    // up
  delay(1000);
  uarm.setPosition(dlrstretch, 0, 70, 0);   // rotate
  delay(4000);
  uarm.gripperRelease();             // release
 
  Serial.println("Deal Card Complete");
}


void motion()
{
  uarm.setPosition(60, 0, 0, 0);    // stretch out
  delay(400);
  uarm.setPosition(60, -45, 0, 0);  // down
  uarm.gripperCatch();               // catch
  delay(400);
  uarm.setPosition(60, 0, 0, 0);    // up
  delay(400);
  uarm.setPosition(60, 0, 25, 0);   // rotate
  delay(400);
  uarm.setPosition(60, -45, 25, 0); // down
  delay(400);
  uarm.gripperRelease();             // release
  delay(100);
  uarm.setPosition(60, 0, 25, 0);   // up
  delay(400);
  uarm.setPosition(0, 0, 25, 0);     
  delay(400);
  uarm.gripperDirectDetach();        // direct detach 
  delay(500);
}

void motionReturn()
{
  uarm.setPosition(60, 0, 25, 0);    // stretch out
  delay(400);
  uarm.setPosition(60, -45, 25, 0);  // down
  uarm.gripperCatch();                // catch
  delay(400);
  uarm.setPosition(60, 0, 25, 0);    // up
  delay(400);
  uarm.setPosition(60, 0, 0, 0);     // rotate
  delay(400);
  uarm.setPosition(60, -45, 0, 0);   // down
  delay(400);
  uarm.gripperRelease();              // release
  delay(100);
  uarm.setPosition(60, 0, 0, 0);     // up
  delay(400);
  uarm.setPosition(0, 0, 0, 0);       // original position
  delay(400);
  uarm.gripperDirectDetach();         // direct detach 
  delay(500);
}

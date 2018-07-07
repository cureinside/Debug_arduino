#include <Debug.h>

Debug deb(13); //attach LED for debugging at pin 13

void setup() 
{}

int i=0;
void loop() {
   i+=1;
   if (i%2==0) 
    deb.setActive(); else
      deb.setUnactive();
   /*
    * will print message and blinks LED for every even loop,
    */

   deb.prints ("this is loop - %d",i); //prints
   deb.LED(); //blink LED attached at pin 13
   delay(1000);
}

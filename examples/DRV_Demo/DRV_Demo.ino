#include <DC_Motor.h>
#include "DRV.h"

/** Example DRV:
 * 
 * (C) by dmholtz
 * April 2020
 * 
 * Creates a motor instances and lets the motor turn for two seconds.
 * 
 *  - Import both the DC_Motor library and the header file for the corresponding driver. 
 *  - Always create DC_Motor pointers and allocate memory on the heap
 *  - Manipulate the motor using the arrow operator
 *  - delete the object after usage
 * 
 **/

void setup() {
  
  // Activates M1 on Mirco Arduino
  DC_Motor* my_mot = new DRV(10, 8, MISO);
  my_mot->ccw();
  delay(2000);
  my_mot->stop();

  delete my_mot;

}

void loop() {
  // put your main code here, to run repeatedly:

}

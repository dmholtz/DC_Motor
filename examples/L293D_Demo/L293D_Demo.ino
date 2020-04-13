#include <DC_Motor.h>
#include "L239D.h"

/** Example L293D:
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
  
  DC_Motor* my_mot = new L293D(10, 31, 33};
  my_mot->ccw();
  delay(2000);
  my_mot->stop();

  delete my_motor;

}

void loop() {
  // put your main code here, to run repeatedly:

}

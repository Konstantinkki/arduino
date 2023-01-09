#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

#define SinDivisions (200)

static int microMzh = 16;
static int freq = 50;
static long int period;
static unsigned int lookUp[SinDivisions];
static char theTCCRIA = 0b10000010;

void setup() {
  // put your setup code here, to run once:
  double temp;
  period = microMzh*le6/freq/SinDivisions;

  for(int i = 0; i< SinDivisions/2; i++){
    temp = sin(i*2*M_PI/SinDivisions)*period;
    lookUp[i] = (int)(temp + 0.5);
  }

  TCCRIA = theTCCRIA;
  TCCRIB = 0b00011001;

}

void loop() {
  // put your main code here, to run repeatedly:

}

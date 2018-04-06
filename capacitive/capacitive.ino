#define SAMPLES 500

byte buf[SAMPLES*9];
byte counts[9*8] = { 255 };

unsigned int i;
byte k;
byte delta;

void setup() {

  //Serial.begin(1000000);
  Serial.begin(115200);

  cli();
  
  // 3,2,5
  DDRE = DDRE | B00010000;
  // 9-6,16,17
  DDRH = B00000000;
  // 14,15
  DDRJ = B00000000;
  // 22-29
  DDRA = B00000000;
  // 30-37
  DDRC = B00000000;
  // 38,18-21
  DDRD = B10000000; // i2c pins don't work because they have hardware pullups
  // 4,39,40,41
  DDRG = B00000000;
  // 42-49
  DDRL = B00000000;
  // 13-10,50-53
  DDRB = B00000000;

}

void loop() {
  
  // 2
  PORTE = B00000000;

  // read inputs
buf[0*9+0] = PINE; buf[0*9+1] = PINH; buf[0*9+2] = PINJ; buf[0*9+3] = PINA; buf[0*9+4] = PINC; buf[0*9+5] = PIND; buf[0*9+6] = PING; buf[0*9+7] = PINL; buf[0*9+8] = PINB;
buf[1*9+0] = PINE; buf[1*9+1] = PINH; buf[1*9+2] = PINJ; buf[1*9+3] = PINA; buf[1*9+4] = PINC; buf[1*9+5] = PIND; buf[1*9+6] = PING; buf[1*9+7] = PINL; buf[1*9+8] = PINB;
buf[2*9+0] = PINE; buf[2*9+1] = PINH; buf[2*9+2] = PINJ; buf[2*9+3] = PINA; buf[2*9+4] = PINC; buf[2*9+5] = PIND; buf[2*9+6] = PING; buf[2*9+7] = PINL; buf[2*9+8] = PINB;
buf[3*9+0] = PINE; buf[3*9+1] = PINH; buf[3*9+2] = PINJ; buf[3*9+3] = PINA; buf[3*9+4] = PINC; buf[3*9+5] = PIND; buf[3*9+6] = PING; buf[3*9+7] = PINL; buf[3*9+8] = PINB;
buf[4*9+0] = PINE; buf[4*9+1] = PINH; buf[4*9+2] = PINJ; buf[4*9+3] = PINA; buf[4*9+4] = PINC; buf[4*9+5] = PIND; buf[4*9+6] = PING; buf[4*9+7] = PINL; buf[4*9+8] = PINB;
buf[5*9+0] = PINE; buf[5*9+1] = PINH; buf[5*9+2] = PINJ; buf[5*9+3] = PINA; buf[5*9+4] = PINC; buf[5*9+5] = PIND; buf[5*9+6] = PING; buf[5*9+7] = PINL; buf[5*9+8] = PINB;
buf[6*9+0] = PINE; buf[6*9+1] = PINH; buf[6*9+2] = PINJ; buf[6*9+3] = PINA; buf[6*9+4] = PINC; buf[6*9+5] = PIND; buf[6*9+6] = PING; buf[6*9+7] = PINL; buf[6*9+8] = PINB;
buf[7*9+0] = PINE; buf[7*9+1] = PINH; buf[7*9+2] = PINJ; buf[7*9+3] = PINA; buf[7*9+4] = PINC; buf[7*9+5] = PIND; buf[7*9+6] = PING; buf[7*9+7] = PINL; buf[7*9+8] = PINB;
buf[8*9+0] = PINE; buf[8*9+1] = PINH; buf[8*9+2] = PINJ; buf[8*9+3] = PINA; buf[8*9+4] = PINC; buf[8*9+5] = PIND; buf[8*9+6] = PING; buf[8*9+7] = PINL; buf[8*9+8] = PINB;
buf[9*9+0] = PINE; buf[9*9+1] = PINH; buf[9*9+2] = PINJ; buf[9*9+3] = PINA; buf[9*9+4] = PINC; buf[9*9+5] = PIND; buf[9*9+6] = PING; buf[9*9+7] = PINL; buf[9*9+8] = PINB;
buf[10*9+0] = PINE; buf[10*9+1] = PINH; buf[10*9+2] = PINJ; buf[10*9+3] = PINA; buf[10*9+4] = PINC; buf[10*9+5] = PIND; buf[10*9+6] = PING; buf[10*9+7] = PINL; buf[10*9+8] = PINB;
buf[11*9+0] = PINE; buf[11*9+1] = PINH; buf[11*9+2] = PINJ; buf[11*9+3] = PINA; buf[11*9+4] = PINC; buf[11*9+5] = PIND; buf[11*9+6] = PING; buf[11*9+7] = PINL; buf[11*9+8] = PINB;
buf[12*9+0] = PINE; buf[12*9+1] = PINH; buf[12*9+2] = PINJ; buf[12*9+3] = PINA; buf[12*9+4] = PINC; buf[12*9+5] = PIND; buf[12*9+6] = PING; buf[12*9+7] = PINL; buf[12*9+8] = PINB;
buf[13*9+0] = PINE; buf[13*9+1] = PINH; buf[13*9+2] = PINJ; buf[13*9+3] = PINA; buf[13*9+4] = PINC; buf[13*9+5] = PIND; buf[13*9+6] = PING; buf[13*9+7] = PINL; buf[13*9+8] = PINB;
buf[14*9+0] = PINE; buf[14*9+1] = PINH; buf[14*9+2] = PINJ; buf[14*9+3] = PINA; buf[14*9+4] = PINC; buf[14*9+5] = PIND; buf[14*9+6] = PING; buf[14*9+7] = PINL; buf[14*9+8] = PINB;
buf[15*9+0] = PINE; buf[15*9+1] = PINH; buf[15*9+2] = PINJ; buf[15*9+3] = PINA; buf[15*9+4] = PINC; buf[15*9+5] = PIND; buf[15*9+6] = PING; buf[15*9+7] = PINL; buf[15*9+8] = PINB;
buf[16*9+0] = PINE; buf[16*9+1] = PINH; buf[16*9+2] = PINJ; buf[16*9+3] = PINA; buf[16*9+4] = PINC; buf[16*9+5] = PIND; buf[16*9+6] = PING; buf[16*9+7] = PINL; buf[16*9+8] = PINB;
buf[17*9+0] = PINE; buf[17*9+1] = PINH; buf[17*9+2] = PINJ; buf[17*9+3] = PINA; buf[17*9+4] = PINC; buf[17*9+5] = PIND; buf[17*9+6] = PING; buf[17*9+7] = PINL; buf[17*9+8] = PINB;
buf[18*9+0] = PINE; buf[18*9+1] = PINH; buf[18*9+2] = PINJ; buf[18*9+3] = PINA; buf[18*9+4] = PINC; buf[18*9+5] = PIND; buf[18*9+6] = PING; buf[18*9+7] = PINL; buf[18*9+8] = PINB;
buf[19*9+0] = PINE; buf[19*9+1] = PINH; buf[19*9+2] = PINJ; buf[19*9+3] = PINA; buf[19*9+4] = PINC; buf[19*9+5] = PIND; buf[19*9+6] = PING; buf[19*9+7] = PINL; buf[19*9+8] = PINB;
buf[20*9+0] = PINE; buf[20*9+1] = PINH; buf[20*9+2] = PINJ; buf[20*9+3] = PINA; buf[20*9+4] = PINC; buf[20*9+5] = PIND; buf[20*9+6] = PING; buf[20*9+7] = PINL; buf[20*9+8] = PINB;
buf[21*9+0] = PINE; buf[21*9+1] = PINH; buf[21*9+2] = PINJ; buf[21*9+3] = PINA; buf[21*9+4] = PINC; buf[21*9+5] = PIND; buf[21*9+6] = PING; buf[21*9+7] = PINL; buf[21*9+8] = PINB;
buf[22*9+0] = PINE; buf[22*9+1] = PINH; buf[22*9+2] = PINJ; buf[22*9+3] = PINA; buf[22*9+4] = PINC; buf[22*9+5] = PIND; buf[22*9+6] = PING; buf[22*9+7] = PINL; buf[22*9+8] = PINB;
buf[23*9+0] = PINE; buf[23*9+1] = PINH; buf[23*9+2] = PINJ; buf[23*9+3] = PINA; buf[23*9+4] = PINC; buf[23*9+5] = PIND; buf[23*9+6] = PING; buf[23*9+7] = PINL; buf[23*9+8] = PINB;
buf[24*9+0] = PINE; buf[24*9+1] = PINH; buf[24*9+2] = PINJ; buf[24*9+3] = PINA; buf[24*9+4] = PINC; buf[24*9+5] = PIND; buf[24*9+6] = PING; buf[24*9+7] = PINL; buf[24*9+8] = PINB;
buf[25*9+0] = PINE; buf[25*9+1] = PINH; buf[25*9+2] = PINJ; buf[25*9+3] = PINA; buf[25*9+4] = PINC; buf[25*9+5] = PIND; buf[25*9+6] = PING; buf[25*9+7] = PINL; buf[25*9+8] = PINB;
buf[26*9+0] = PINE; buf[26*9+1] = PINH; buf[26*9+2] = PINJ; buf[26*9+3] = PINA; buf[26*9+4] = PINC; buf[26*9+5] = PIND; buf[26*9+6] = PING; buf[26*9+7] = PINL; buf[26*9+8] = PINB;
buf[27*9+0] = PINE; buf[27*9+1] = PINH; buf[27*9+2] = PINJ; buf[27*9+3] = PINA; buf[27*9+4] = PINC; buf[27*9+5] = PIND; buf[27*9+6] = PING; buf[27*9+7] = PINL; buf[27*9+8] = PINB;
buf[28*9+0] = PINE; buf[28*9+1] = PINH; buf[28*9+2] = PINJ; buf[28*9+3] = PINA; buf[28*9+4] = PINC; buf[28*9+5] = PIND; buf[28*9+6] = PING; buf[28*9+7] = PINL; buf[28*9+8] = PINB;
buf[29*9+0] = PINE; buf[29*9+1] = PINH; buf[29*9+2] = PINJ; buf[29*9+3] = PINA; buf[29*9+4] = PINC; buf[29*9+5] = PIND; buf[29*9+6] = PING; buf[29*9+7] = PINL; buf[29*9+8] = PINB;
buf[30*9+0] = PINE; buf[30*9+1] = PINH; buf[30*9+2] = PINJ; buf[30*9+3] = PINA; buf[30*9+4] = PINC; buf[30*9+5] = PIND; buf[30*9+6] = PING; buf[30*9+7] = PINL; buf[30*9+8] = PINB;
buf[31*9+0] = PINE; buf[31*9+1] = PINH; buf[31*9+2] = PINJ; buf[31*9+3] = PINA; buf[31*9+4] = PINC; buf[31*9+5] = PIND; buf[31*9+6] = PING; buf[31*9+7] = PINL; buf[31*9+8] = PINB;
buf[32*9+0] = PINE; buf[32*9+1] = PINH; buf[32*9+2] = PINJ; buf[32*9+3] = PINA; buf[32*9+4] = PINC; buf[32*9+5] = PIND; buf[32*9+6] = PING; buf[32*9+7] = PINL; buf[32*9+8] = PINB;
buf[33*9+0] = PINE; buf[33*9+1] = PINH; buf[33*9+2] = PINJ; buf[33*9+3] = PINA; buf[33*9+4] = PINC; buf[33*9+5] = PIND; buf[33*9+6] = PING; buf[33*9+7] = PINL; buf[33*9+8] = PINB;
buf[34*9+0] = PINE; buf[34*9+1] = PINH; buf[34*9+2] = PINJ; buf[34*9+3] = PINA; buf[34*9+4] = PINC; buf[34*9+5] = PIND; buf[34*9+6] = PING; buf[34*9+7] = PINL; buf[34*9+8] = PINB;
buf[35*9+0] = PINE; buf[35*9+1] = PINH; buf[35*9+2] = PINJ; buf[35*9+3] = PINA; buf[35*9+4] = PINC; buf[35*9+5] = PIND; buf[35*9+6] = PING; buf[35*9+7] = PINL; buf[35*9+8] = PINB;
buf[36*9+0] = PINE; buf[36*9+1] = PINH; buf[36*9+2] = PINJ; buf[36*9+3] = PINA; buf[36*9+4] = PINC; buf[36*9+5] = PIND; buf[36*9+6] = PING; buf[36*9+7] = PINL; buf[36*9+8] = PINB;
buf[37*9+0] = PINE; buf[37*9+1] = PINH; buf[37*9+2] = PINJ; buf[37*9+3] = PINA; buf[37*9+4] = PINC; buf[37*9+5] = PIND; buf[37*9+6] = PING; buf[37*9+7] = PINL; buf[37*9+8] = PINB;
buf[38*9+0] = PINE; buf[38*9+1] = PINH; buf[38*9+2] = PINJ; buf[38*9+3] = PINA; buf[38*9+4] = PINC; buf[38*9+5] = PIND; buf[38*9+6] = PING; buf[38*9+7] = PINL; buf[38*9+8] = PINB;
buf[39*9+0] = PINE; buf[39*9+1] = PINH; buf[39*9+2] = PINJ; buf[39*9+3] = PINA; buf[39*9+4] = PINC; buf[39*9+5] = PIND; buf[39*9+6] = PING; buf[39*9+7] = PINL; buf[39*9+8] = PINB;
buf[40*9+0] = PINE; buf[40*9+1] = PINH; buf[40*9+2] = PINJ; buf[40*9+3] = PINA; buf[40*9+4] = PINC; buf[40*9+5] = PIND; buf[40*9+6] = PING; buf[40*9+7] = PINL; buf[40*9+8] = PINB;
buf[41*9+0] = PINE; buf[41*9+1] = PINH; buf[41*9+2] = PINJ; buf[41*9+3] = PINA; buf[41*9+4] = PINC; buf[41*9+5] = PIND; buf[41*9+6] = PING; buf[41*9+7] = PINL; buf[41*9+8] = PINB;
buf[42*9+0] = PINE; buf[42*9+1] = PINH; buf[42*9+2] = PINJ; buf[42*9+3] = PINA; buf[42*9+4] = PINC; buf[42*9+5] = PIND; buf[42*9+6] = PING; buf[42*9+7] = PINL; buf[42*9+8] = PINB;
buf[43*9+0] = PINE; buf[43*9+1] = PINH; buf[43*9+2] = PINJ; buf[43*9+3] = PINA; buf[43*9+4] = PINC; buf[43*9+5] = PIND; buf[43*9+6] = PING; buf[43*9+7] = PINL; buf[43*9+8] = PINB;
buf[44*9+0] = PINE; buf[44*9+1] = PINH; buf[44*9+2] = PINJ; buf[44*9+3] = PINA; buf[44*9+4] = PINC; buf[44*9+5] = PIND; buf[44*9+6] = PING; buf[44*9+7] = PINL; buf[44*9+8] = PINB;
buf[45*9+0] = PINE; buf[45*9+1] = PINH; buf[45*9+2] = PINJ; buf[45*9+3] = PINA; buf[45*9+4] = PINC; buf[45*9+5] = PIND; buf[45*9+6] = PING; buf[45*9+7] = PINL; buf[45*9+8] = PINB;
buf[46*9+0] = PINE; buf[46*9+1] = PINH; buf[46*9+2] = PINJ; buf[46*9+3] = PINA; buf[46*9+4] = PINC; buf[46*9+5] = PIND; buf[46*9+6] = PING; buf[46*9+7] = PINL; buf[46*9+8] = PINB;
buf[47*9+0] = PINE; buf[47*9+1] = PINH; buf[47*9+2] = PINJ; buf[47*9+3] = PINA; buf[47*9+4] = PINC; buf[47*9+5] = PIND; buf[47*9+6] = PING; buf[47*9+7] = PINL; buf[47*9+8] = PINB;
buf[48*9+0] = PINE; buf[48*9+1] = PINH; buf[48*9+2] = PINJ; buf[48*9+3] = PINA; buf[48*9+4] = PINC; buf[48*9+5] = PIND; buf[48*9+6] = PING; buf[48*9+7] = PINL; buf[48*9+8] = PINB;
buf[49*9+0] = PINE; buf[49*9+1] = PINH; buf[49*9+2] = PINJ; buf[49*9+3] = PINA; buf[49*9+4] = PINC; buf[49*9+5] = PIND; buf[49*9+6] = PING; buf[49*9+7] = PINL; buf[49*9+8] = PINB;
buf[50*9+0] = PINE; buf[50*9+1] = PINH; buf[50*9+2] = PINJ; buf[50*9+3] = PINA; buf[50*9+4] = PINC; buf[50*9+5] = PIND; buf[50*9+6] = PING; buf[50*9+7] = PINL; buf[50*9+8] = PINB;
buf[51*9+0] = PINE; buf[51*9+1] = PINH; buf[51*9+2] = PINJ; buf[51*9+3] = PINA; buf[51*9+4] = PINC; buf[51*9+5] = PIND; buf[51*9+6] = PING; buf[51*9+7] = PINL; buf[51*9+8] = PINB;
buf[52*9+0] = PINE; buf[52*9+1] = PINH; buf[52*9+2] = PINJ; buf[52*9+3] = PINA; buf[52*9+4] = PINC; buf[52*9+5] = PIND; buf[52*9+6] = PING; buf[52*9+7] = PINL; buf[52*9+8] = PINB;
buf[53*9+0] = PINE; buf[53*9+1] = PINH; buf[53*9+2] = PINJ; buf[53*9+3] = PINA; buf[53*9+4] = PINC; buf[53*9+5] = PIND; buf[53*9+6] = PING; buf[53*9+7] = PINL; buf[53*9+8] = PINB;
buf[54*9+0] = PINE; buf[54*9+1] = PINH; buf[54*9+2] = PINJ; buf[54*9+3] = PINA; buf[54*9+4] = PINC; buf[54*9+5] = PIND; buf[54*9+6] = PING; buf[54*9+7] = PINL; buf[54*9+8] = PINB;
buf[55*9+0] = PINE; buf[55*9+1] = PINH; buf[55*9+2] = PINJ; buf[55*9+3] = PINA; buf[55*9+4] = PINC; buf[55*9+5] = PIND; buf[55*9+6] = PING; buf[55*9+7] = PINL; buf[55*9+8] = PINB;
buf[56*9+0] = PINE; buf[56*9+1] = PINH; buf[56*9+2] = PINJ; buf[56*9+3] = PINA; buf[56*9+4] = PINC; buf[56*9+5] = PIND; buf[56*9+6] = PING; buf[56*9+7] = PINL; buf[56*9+8] = PINB;
buf[57*9+0] = PINE; buf[57*9+1] = PINH; buf[57*9+2] = PINJ; buf[57*9+3] = PINA; buf[57*9+4] = PINC; buf[57*9+5] = PIND; buf[57*9+6] = PING; buf[57*9+7] = PINL; buf[57*9+8] = PINB;
buf[58*9+0] = PINE; buf[58*9+1] = PINH; buf[58*9+2] = PINJ; buf[58*9+3] = PINA; buf[58*9+4] = PINC; buf[58*9+5] = PIND; buf[58*9+6] = PING; buf[58*9+7] = PINL; buf[58*9+8] = PINB;
buf[59*9+0] = PINE; buf[59*9+1] = PINH; buf[59*9+2] = PINJ; buf[59*9+3] = PINA; buf[59*9+4] = PINC; buf[59*9+5] = PIND; buf[59*9+6] = PING; buf[59*9+7] = PINL; buf[59*9+8] = PINB;
buf[60*9+0] = PINE; buf[60*9+1] = PINH; buf[60*9+2] = PINJ; buf[60*9+3] = PINA; buf[60*9+4] = PINC; buf[60*9+5] = PIND; buf[60*9+6] = PING; buf[60*9+7] = PINL; buf[60*9+8] = PINB;
buf[61*9+0] = PINE; buf[61*9+1] = PINH; buf[61*9+2] = PINJ; buf[61*9+3] = PINA; buf[61*9+4] = PINC; buf[61*9+5] = PIND; buf[61*9+6] = PING; buf[61*9+7] = PINL; buf[61*9+8] = PINB;
buf[62*9+0] = PINE; buf[62*9+1] = PINH; buf[62*9+2] = PINJ; buf[62*9+3] = PINA; buf[62*9+4] = PINC; buf[62*9+5] = PIND; buf[62*9+6] = PING; buf[62*9+7] = PINL; buf[62*9+8] = PINB;
buf[63*9+0] = PINE; buf[63*9+1] = PINH; buf[63*9+2] = PINJ; buf[63*9+3] = PINA; buf[63*9+4] = PINC; buf[63*9+5] = PIND; buf[63*9+6] = PING; buf[63*9+7] = PINL; buf[63*9+8] = PINB;
buf[64*9+0] = PINE; buf[64*9+1] = PINH; buf[64*9+2] = PINJ; buf[64*9+3] = PINA; buf[64*9+4] = PINC; buf[64*9+5] = PIND; buf[64*9+6] = PING; buf[64*9+7] = PINL; buf[64*9+8] = PINB;
buf[65*9+0] = PINE; buf[65*9+1] = PINH; buf[65*9+2] = PINJ; buf[65*9+3] = PINA; buf[65*9+4] = PINC; buf[65*9+5] = PIND; buf[65*9+6] = PING; buf[65*9+7] = PINL; buf[65*9+8] = PINB;
buf[66*9+0] = PINE; buf[66*9+1] = PINH; buf[66*9+2] = PINJ; buf[66*9+3] = PINA; buf[66*9+4] = PINC; buf[66*9+5] = PIND; buf[66*9+6] = PING; buf[66*9+7] = PINL; buf[66*9+8] = PINB;
buf[67*9+0] = PINE; buf[67*9+1] = PINH; buf[67*9+2] = PINJ; buf[67*9+3] = PINA; buf[67*9+4] = PINC; buf[67*9+5] = PIND; buf[67*9+6] = PING; buf[67*9+7] = PINL; buf[67*9+8] = PINB;
buf[68*9+0] = PINE; buf[68*9+1] = PINH; buf[68*9+2] = PINJ; buf[68*9+3] = PINA; buf[68*9+4] = PINC; buf[68*9+5] = PIND; buf[68*9+6] = PING; buf[68*9+7] = PINL; buf[68*9+8] = PINB;
buf[69*9+0] = PINE; buf[69*9+1] = PINH; buf[69*9+2] = PINJ; buf[69*9+3] = PINA; buf[69*9+4] = PINC; buf[69*9+5] = PIND; buf[69*9+6] = PING; buf[69*9+7] = PINL; buf[69*9+8] = PINB;
buf[70*9+0] = PINE; buf[70*9+1] = PINH; buf[70*9+2] = PINJ; buf[70*9+3] = PINA; buf[70*9+4] = PINC; buf[70*9+5] = PIND; buf[70*9+6] = PING; buf[70*9+7] = PINL; buf[70*9+8] = PINB;
buf[71*9+0] = PINE; buf[71*9+1] = PINH; buf[71*9+2] = PINJ; buf[71*9+3] = PINA; buf[71*9+4] = PINC; buf[71*9+5] = PIND; buf[71*9+6] = PING; buf[71*9+7] = PINL; buf[71*9+8] = PINB;
buf[72*9+0] = PINE; buf[72*9+1] = PINH; buf[72*9+2] = PINJ; buf[72*9+3] = PINA; buf[72*9+4] = PINC; buf[72*9+5] = PIND; buf[72*9+6] = PING; buf[72*9+7] = PINL; buf[72*9+8] = PINB;
buf[73*9+0] = PINE; buf[73*9+1] = PINH; buf[73*9+2] = PINJ; buf[73*9+3] = PINA; buf[73*9+4] = PINC; buf[73*9+5] = PIND; buf[73*9+6] = PING; buf[73*9+7] = PINL; buf[73*9+8] = PINB;
buf[74*9+0] = PINE; buf[74*9+1] = PINH; buf[74*9+2] = PINJ; buf[74*9+3] = PINA; buf[74*9+4] = PINC; buf[74*9+5] = PIND; buf[74*9+6] = PING; buf[74*9+7] = PINL; buf[74*9+8] = PINB;
buf[75*9+0] = PINE; buf[75*9+1] = PINH; buf[75*9+2] = PINJ; buf[75*9+3] = PINA; buf[75*9+4] = PINC; buf[75*9+5] = PIND; buf[75*9+6] = PING; buf[75*9+7] = PINL; buf[75*9+8] = PINB;
buf[76*9+0] = PINE; buf[76*9+1] = PINH; buf[76*9+2] = PINJ; buf[76*9+3] = PINA; buf[76*9+4] = PINC; buf[76*9+5] = PIND; buf[76*9+6] = PING; buf[76*9+7] = PINL; buf[76*9+8] = PINB;
buf[77*9+0] = PINE; buf[77*9+1] = PINH; buf[77*9+2] = PINJ; buf[77*9+3] = PINA; buf[77*9+4] = PINC; buf[77*9+5] = PIND; buf[77*9+6] = PING; buf[77*9+7] = PINL; buf[77*9+8] = PINB;
buf[78*9+0] = PINE; buf[78*9+1] = PINH; buf[78*9+2] = PINJ; buf[78*9+3] = PINA; buf[78*9+4] = PINC; buf[78*9+5] = PIND; buf[78*9+6] = PING; buf[78*9+7] = PINL; buf[78*9+8] = PINB;
buf[79*9+0] = PINE; buf[79*9+1] = PINH; buf[79*9+2] = PINJ; buf[79*9+3] = PINA; buf[79*9+4] = PINC; buf[79*9+5] = PIND; buf[79*9+6] = PING; buf[79*9+7] = PINL; buf[79*9+8] = PINB;
buf[80*9+0] = PINE; buf[80*9+1] = PINH; buf[80*9+2] = PINJ; buf[80*9+3] = PINA; buf[80*9+4] = PINC; buf[80*9+5] = PIND; buf[80*9+6] = PING; buf[80*9+7] = PINL; buf[80*9+8] = PINB;
buf[81*9+0] = PINE; buf[81*9+1] = PINH; buf[81*9+2] = PINJ; buf[81*9+3] = PINA; buf[81*9+4] = PINC; buf[81*9+5] = PIND; buf[81*9+6] = PING; buf[81*9+7] = PINL; buf[81*9+8] = PINB;
buf[82*9+0] = PINE; buf[82*9+1] = PINH; buf[82*9+2] = PINJ; buf[82*9+3] = PINA; buf[82*9+4] = PINC; buf[82*9+5] = PIND; buf[82*9+6] = PING; buf[82*9+7] = PINL; buf[82*9+8] = PINB;
buf[83*9+0] = PINE; buf[83*9+1] = PINH; buf[83*9+2] = PINJ; buf[83*9+3] = PINA; buf[83*9+4] = PINC; buf[83*9+5] = PIND; buf[83*9+6] = PING; buf[83*9+7] = PINL; buf[83*9+8] = PINB;
buf[84*9+0] = PINE; buf[84*9+1] = PINH; buf[84*9+2] = PINJ; buf[84*9+3] = PINA; buf[84*9+4] = PINC; buf[84*9+5] = PIND; buf[84*9+6] = PING; buf[84*9+7] = PINL; buf[84*9+8] = PINB;
buf[85*9+0] = PINE; buf[85*9+1] = PINH; buf[85*9+2] = PINJ; buf[85*9+3] = PINA; buf[85*9+4] = PINC; buf[85*9+5] = PIND; buf[85*9+6] = PING; buf[85*9+7] = PINL; buf[85*9+8] = PINB;
buf[86*9+0] = PINE; buf[86*9+1] = PINH; buf[86*9+2] = PINJ; buf[86*9+3] = PINA; buf[86*9+4] = PINC; buf[86*9+5] = PIND; buf[86*9+6] = PING; buf[86*9+7] = PINL; buf[86*9+8] = PINB;
buf[87*9+0] = PINE; buf[87*9+1] = PINH; buf[87*9+2] = PINJ; buf[87*9+3] = PINA; buf[87*9+4] = PINC; buf[87*9+5] = PIND; buf[87*9+6] = PING; buf[87*9+7] = PINL; buf[87*9+8] = PINB;
buf[88*9+0] = PINE; buf[88*9+1] = PINH; buf[88*9+2] = PINJ; buf[88*9+3] = PINA; buf[88*9+4] = PINC; buf[88*9+5] = PIND; buf[88*9+6] = PING; buf[88*9+7] = PINL; buf[88*9+8] = PINB;
buf[89*9+0] = PINE; buf[89*9+1] = PINH; buf[89*9+2] = PINJ; buf[89*9+3] = PINA; buf[89*9+4] = PINC; buf[89*9+5] = PIND; buf[89*9+6] = PING; buf[89*9+7] = PINL; buf[89*9+8] = PINB;
buf[90*9+0] = PINE; buf[90*9+1] = PINH; buf[90*9+2] = PINJ; buf[90*9+3] = PINA; buf[90*9+4] = PINC; buf[90*9+5] = PIND; buf[90*9+6] = PING; buf[90*9+7] = PINL; buf[90*9+8] = PINB;
buf[91*9+0] = PINE; buf[91*9+1] = PINH; buf[91*9+2] = PINJ; buf[91*9+3] = PINA; buf[91*9+4] = PINC; buf[91*9+5] = PIND; buf[91*9+6] = PING; buf[91*9+7] = PINL; buf[91*9+8] = PINB;
buf[92*9+0] = PINE; buf[92*9+1] = PINH; buf[92*9+2] = PINJ; buf[92*9+3] = PINA; buf[92*9+4] = PINC; buf[92*9+5] = PIND; buf[92*9+6] = PING; buf[92*9+7] = PINL; buf[92*9+8] = PINB;
buf[93*9+0] = PINE; buf[93*9+1] = PINH; buf[93*9+2] = PINJ; buf[93*9+3] = PINA; buf[93*9+4] = PINC; buf[93*9+5] = PIND; buf[93*9+6] = PING; buf[93*9+7] = PINL; buf[93*9+8] = PINB;
buf[94*9+0] = PINE; buf[94*9+1] = PINH; buf[94*9+2] = PINJ; buf[94*9+3] = PINA; buf[94*9+4] = PINC; buf[94*9+5] = PIND; buf[94*9+6] = PING; buf[94*9+7] = PINL; buf[94*9+8] = PINB;
buf[95*9+0] = PINE; buf[95*9+1] = PINH; buf[95*9+2] = PINJ; buf[95*9+3] = PINA; buf[95*9+4] = PINC; buf[95*9+5] = PIND; buf[95*9+6] = PING; buf[95*9+7] = PINL; buf[95*9+8] = PINB;
buf[96*9+0] = PINE; buf[96*9+1] = PINH; buf[96*9+2] = PINJ; buf[96*9+3] = PINA; buf[96*9+4] = PINC; buf[96*9+5] = PIND; buf[96*9+6] = PING; buf[96*9+7] = PINL; buf[96*9+8] = PINB;
buf[97*9+0] = PINE; buf[97*9+1] = PINH; buf[97*9+2] = PINJ; buf[97*9+3] = PINA; buf[97*9+4] = PINC; buf[97*9+5] = PIND; buf[97*9+6] = PING; buf[97*9+7] = PINL; buf[97*9+8] = PINB;
buf[98*9+0] = PINE; buf[98*9+1] = PINH; buf[98*9+2] = PINJ; buf[98*9+3] = PINA; buf[98*9+4] = PINC; buf[98*9+5] = PIND; buf[98*9+6] = PING; buf[98*9+7] = PINL; buf[98*9+8] = PINB;
buf[99*9+0] = PINE; buf[99*9+1] = PINH; buf[99*9+2] = PINJ; buf[99*9+3] = PINA; buf[99*9+4] = PINC; buf[99*9+5] = PIND; buf[99*9+6] = PING; buf[99*9+7] = PINL; buf[99*9+8] = PINB;
buf[100*9+0] = PINE; buf[100*9+1] = PINH; buf[100*9+2] = PINJ; buf[100*9+3] = PINA; buf[100*9+4] = PINC; buf[100*9+5] = PIND; buf[100*9+6] = PING; buf[100*9+7] = PINL; buf[100*9+8] = PINB;
buf[101*9+0] = PINE; buf[101*9+1] = PINH; buf[101*9+2] = PINJ; buf[101*9+3] = PINA; buf[101*9+4] = PINC; buf[101*9+5] = PIND; buf[101*9+6] = PING; buf[101*9+7] = PINL; buf[101*9+8] = PINB;
buf[102*9+0] = PINE; buf[102*9+1] = PINH; buf[102*9+2] = PINJ; buf[102*9+3] = PINA; buf[102*9+4] = PINC; buf[102*9+5] = PIND; buf[102*9+6] = PING; buf[102*9+7] = PINL; buf[102*9+8] = PINB;
buf[103*9+0] = PINE; buf[103*9+1] = PINH; buf[103*9+2] = PINJ; buf[103*9+3] = PINA; buf[103*9+4] = PINC; buf[103*9+5] = PIND; buf[103*9+6] = PING; buf[103*9+7] = PINL; buf[103*9+8] = PINB;
buf[104*9+0] = PINE; buf[104*9+1] = PINH; buf[104*9+2] = PINJ; buf[104*9+3] = PINA; buf[104*9+4] = PINC; buf[104*9+5] = PIND; buf[104*9+6] = PING; buf[104*9+7] = PINL; buf[104*9+8] = PINB;
buf[105*9+0] = PINE; buf[105*9+1] = PINH; buf[105*9+2] = PINJ; buf[105*9+3] = PINA; buf[105*9+4] = PINC; buf[105*9+5] = PIND; buf[105*9+6] = PING; buf[105*9+7] = PINL; buf[105*9+8] = PINB;
buf[106*9+0] = PINE; buf[106*9+1] = PINH; buf[106*9+2] = PINJ; buf[106*9+3] = PINA; buf[106*9+4] = PINC; buf[106*9+5] = PIND; buf[106*9+6] = PING; buf[106*9+7] = PINL; buf[106*9+8] = PINB;
buf[107*9+0] = PINE; buf[107*9+1] = PINH; buf[107*9+2] = PINJ; buf[107*9+3] = PINA; buf[107*9+4] = PINC; buf[107*9+5] = PIND; buf[107*9+6] = PING; buf[107*9+7] = PINL; buf[107*9+8] = PINB;
buf[108*9+0] = PINE; buf[108*9+1] = PINH; buf[108*9+2] = PINJ; buf[108*9+3] = PINA; buf[108*9+4] = PINC; buf[108*9+5] = PIND; buf[108*9+6] = PING; buf[108*9+7] = PINL; buf[108*9+8] = PINB;
buf[109*9+0] = PINE; buf[109*9+1] = PINH; buf[109*9+2] = PINJ; buf[109*9+3] = PINA; buf[109*9+4] = PINC; buf[109*9+5] = PIND; buf[109*9+6] = PING; buf[109*9+7] = PINL; buf[109*9+8] = PINB;
buf[110*9+0] = PINE; buf[110*9+1] = PINH; buf[110*9+2] = PINJ; buf[110*9+3] = PINA; buf[110*9+4] = PINC; buf[110*9+5] = PIND; buf[110*9+6] = PING; buf[110*9+7] = PINL; buf[110*9+8] = PINB;
buf[111*9+0] = PINE; buf[111*9+1] = PINH; buf[111*9+2] = PINJ; buf[111*9+3] = PINA; buf[111*9+4] = PINC; buf[111*9+5] = PIND; buf[111*9+6] = PING; buf[111*9+7] = PINL; buf[111*9+8] = PINB;
buf[112*9+0] = PINE; buf[112*9+1] = PINH; buf[112*9+2] = PINJ; buf[112*9+3] = PINA; buf[112*9+4] = PINC; buf[112*9+5] = PIND; buf[112*9+6] = PING; buf[112*9+7] = PINL; buf[112*9+8] = PINB;
buf[113*9+0] = PINE; buf[113*9+1] = PINH; buf[113*9+2] = PINJ; buf[113*9+3] = PINA; buf[113*9+4] = PINC; buf[113*9+5] = PIND; buf[113*9+6] = PING; buf[113*9+7] = PINL; buf[113*9+8] = PINB;
buf[114*9+0] = PINE; buf[114*9+1] = PINH; buf[114*9+2] = PINJ; buf[114*9+3] = PINA; buf[114*9+4] = PINC; buf[114*9+5] = PIND; buf[114*9+6] = PING; buf[114*9+7] = PINL; buf[114*9+8] = PINB;
buf[115*9+0] = PINE; buf[115*9+1] = PINH; buf[115*9+2] = PINJ; buf[115*9+3] = PINA; buf[115*9+4] = PINC; buf[115*9+5] = PIND; buf[115*9+6] = PING; buf[115*9+7] = PINL; buf[115*9+8] = PINB;
buf[116*9+0] = PINE; buf[116*9+1] = PINH; buf[116*9+2] = PINJ; buf[116*9+3] = PINA; buf[116*9+4] = PINC; buf[116*9+5] = PIND; buf[116*9+6] = PING; buf[116*9+7] = PINL; buf[116*9+8] = PINB;
buf[117*9+0] = PINE; buf[117*9+1] = PINH; buf[117*9+2] = PINJ; buf[117*9+3] = PINA; buf[117*9+4] = PINC; buf[117*9+5] = PIND; buf[117*9+6] = PING; buf[117*9+7] = PINL; buf[117*9+8] = PINB;
buf[118*9+0] = PINE; buf[118*9+1] = PINH; buf[118*9+2] = PINJ; buf[118*9+3] = PINA; buf[118*9+4] = PINC; buf[118*9+5] = PIND; buf[118*9+6] = PING; buf[118*9+7] = PINL; buf[118*9+8] = PINB;
buf[119*9+0] = PINE; buf[119*9+1] = PINH; buf[119*9+2] = PINJ; buf[119*9+3] = PINA; buf[119*9+4] = PINC; buf[119*9+5] = PIND; buf[119*9+6] = PING; buf[119*9+7] = PINL; buf[119*9+8] = PINB;
buf[120*9+0] = PINE; buf[120*9+1] = PINH; buf[120*9+2] = PINJ; buf[120*9+3] = PINA; buf[120*9+4] = PINC; buf[120*9+5] = PIND; buf[120*9+6] = PING; buf[120*9+7] = PINL; buf[120*9+8] = PINB;
buf[121*9+0] = PINE; buf[121*9+1] = PINH; buf[121*9+2] = PINJ; buf[121*9+3] = PINA; buf[121*9+4] = PINC; buf[121*9+5] = PIND; buf[121*9+6] = PING; buf[121*9+7] = PINL; buf[121*9+8] = PINB;
buf[122*9+0] = PINE; buf[122*9+1] = PINH; buf[122*9+2] = PINJ; buf[122*9+3] = PINA; buf[122*9+4] = PINC; buf[122*9+5] = PIND; buf[122*9+6] = PING; buf[122*9+7] = PINL; buf[122*9+8] = PINB;
buf[123*9+0] = PINE; buf[123*9+1] = PINH; buf[123*9+2] = PINJ; buf[123*9+3] = PINA; buf[123*9+4] = PINC; buf[123*9+5] = PIND; buf[123*9+6] = PING; buf[123*9+7] = PINL; buf[123*9+8] = PINB;
buf[124*9+0] = PINE; buf[124*9+1] = PINH; buf[124*9+2] = PINJ; buf[124*9+3] = PINA; buf[124*9+4] = PINC; buf[124*9+5] = PIND; buf[124*9+6] = PING; buf[124*9+7] = PINL; buf[124*9+8] = PINB;
buf[125*9+0] = PINE; buf[125*9+1] = PINH; buf[125*9+2] = PINJ; buf[125*9+3] = PINA; buf[125*9+4] = PINC; buf[125*9+5] = PIND; buf[125*9+6] = PING; buf[125*9+7] = PINL; buf[125*9+8] = PINB;
buf[126*9+0] = PINE; buf[126*9+1] = PINH; buf[126*9+2] = PINJ; buf[126*9+3] = PINA; buf[126*9+4] = PINC; buf[126*9+5] = PIND; buf[126*9+6] = PING; buf[126*9+7] = PINL; buf[126*9+8] = PINB;
buf[127*9+0] = PINE; buf[127*9+1] = PINH; buf[127*9+2] = PINJ; buf[127*9+3] = PINA; buf[127*9+4] = PINC; buf[127*9+5] = PIND; buf[127*9+6] = PING; buf[127*9+7] = PINL; buf[127*9+8] = PINB;
buf[128*9+0] = PINE; buf[128*9+1] = PINH; buf[128*9+2] = PINJ; buf[128*9+3] = PINA; buf[128*9+4] = PINC; buf[128*9+5] = PIND; buf[128*9+6] = PING; buf[128*9+7] = PINL; buf[128*9+8] = PINB;
buf[129*9+0] = PINE; buf[129*9+1] = PINH; buf[129*9+2] = PINJ; buf[129*9+3] = PINA; buf[129*9+4] = PINC; buf[129*9+5] = PIND; buf[129*9+6] = PING; buf[129*9+7] = PINL; buf[129*9+8] = PINB;
buf[130*9+0] = PINE; buf[130*9+1] = PINH; buf[130*9+2] = PINJ; buf[130*9+3] = PINA; buf[130*9+4] = PINC; buf[130*9+5] = PIND; buf[130*9+6] = PING; buf[130*9+7] = PINL; buf[130*9+8] = PINB;
buf[131*9+0] = PINE; buf[131*9+1] = PINH; buf[131*9+2] = PINJ; buf[131*9+3] = PINA; buf[131*9+4] = PINC; buf[131*9+5] = PIND; buf[131*9+6] = PING; buf[131*9+7] = PINL; buf[131*9+8] = PINB;
buf[132*9+0] = PINE; buf[132*9+1] = PINH; buf[132*9+2] = PINJ; buf[132*9+3] = PINA; buf[132*9+4] = PINC; buf[132*9+5] = PIND; buf[132*9+6] = PING; buf[132*9+7] = PINL; buf[132*9+8] = PINB;
buf[133*9+0] = PINE; buf[133*9+1] = PINH; buf[133*9+2] = PINJ; buf[133*9+3] = PINA; buf[133*9+4] = PINC; buf[133*9+5] = PIND; buf[133*9+6] = PING; buf[133*9+7] = PINL; buf[133*9+8] = PINB;
buf[134*9+0] = PINE; buf[134*9+1] = PINH; buf[134*9+2] = PINJ; buf[134*9+3] = PINA; buf[134*9+4] = PINC; buf[134*9+5] = PIND; buf[134*9+6] = PING; buf[134*9+7] = PINL; buf[134*9+8] = PINB;
buf[135*9+0] = PINE; buf[135*9+1] = PINH; buf[135*9+2] = PINJ; buf[135*9+3] = PINA; buf[135*9+4] = PINC; buf[135*9+5] = PIND; buf[135*9+6] = PING; buf[135*9+7] = PINL; buf[135*9+8] = PINB;
buf[136*9+0] = PINE; buf[136*9+1] = PINH; buf[136*9+2] = PINJ; buf[136*9+3] = PINA; buf[136*9+4] = PINC; buf[136*9+5] = PIND; buf[136*9+6] = PING; buf[136*9+7] = PINL; buf[136*9+8] = PINB;
buf[137*9+0] = PINE; buf[137*9+1] = PINH; buf[137*9+2] = PINJ; buf[137*9+3] = PINA; buf[137*9+4] = PINC; buf[137*9+5] = PIND; buf[137*9+6] = PING; buf[137*9+7] = PINL; buf[137*9+8] = PINB;
buf[138*9+0] = PINE; buf[138*9+1] = PINH; buf[138*9+2] = PINJ; buf[138*9+3] = PINA; buf[138*9+4] = PINC; buf[138*9+5] = PIND; buf[138*9+6] = PING; buf[138*9+7] = PINL; buf[138*9+8] = PINB;
buf[139*9+0] = PINE; buf[139*9+1] = PINH; buf[139*9+2] = PINJ; buf[139*9+3] = PINA; buf[139*9+4] = PINC; buf[139*9+5] = PIND; buf[139*9+6] = PING; buf[139*9+7] = PINL; buf[139*9+8] = PINB;
buf[140*9+0] = PINE; buf[140*9+1] = PINH; buf[140*9+2] = PINJ; buf[140*9+3] = PINA; buf[140*9+4] = PINC; buf[140*9+5] = PIND; buf[140*9+6] = PING; buf[140*9+7] = PINL; buf[140*9+8] = PINB;
buf[141*9+0] = PINE; buf[141*9+1] = PINH; buf[141*9+2] = PINJ; buf[141*9+3] = PINA; buf[141*9+4] = PINC; buf[141*9+5] = PIND; buf[141*9+6] = PING; buf[141*9+7] = PINL; buf[141*9+8] = PINB;
buf[142*9+0] = PINE; buf[142*9+1] = PINH; buf[142*9+2] = PINJ; buf[142*9+3] = PINA; buf[142*9+4] = PINC; buf[142*9+5] = PIND; buf[142*9+6] = PING; buf[142*9+7] = PINL; buf[142*9+8] = PINB;
buf[143*9+0] = PINE; buf[143*9+1] = PINH; buf[143*9+2] = PINJ; buf[143*9+3] = PINA; buf[143*9+4] = PINC; buf[143*9+5] = PIND; buf[143*9+6] = PING; buf[143*9+7] = PINL; buf[143*9+8] = PINB;
buf[144*9+0] = PINE; buf[144*9+1] = PINH; buf[144*9+2] = PINJ; buf[144*9+3] = PINA; buf[144*9+4] = PINC; buf[144*9+5] = PIND; buf[144*9+6] = PING; buf[144*9+7] = PINL; buf[144*9+8] = PINB;
buf[145*9+0] = PINE; buf[145*9+1] = PINH; buf[145*9+2] = PINJ; buf[145*9+3] = PINA; buf[145*9+4] = PINC; buf[145*9+5] = PIND; buf[145*9+6] = PING; buf[145*9+7] = PINL; buf[145*9+8] = PINB;
buf[146*9+0] = PINE; buf[146*9+1] = PINH; buf[146*9+2] = PINJ; buf[146*9+3] = PINA; buf[146*9+4] = PINC; buf[146*9+5] = PIND; buf[146*9+6] = PING; buf[146*9+7] = PINL; buf[146*9+8] = PINB;
buf[147*9+0] = PINE; buf[147*9+1] = PINH; buf[147*9+2] = PINJ; buf[147*9+3] = PINA; buf[147*9+4] = PINC; buf[147*9+5] = PIND; buf[147*9+6] = PING; buf[147*9+7] = PINL; buf[147*9+8] = PINB;
buf[148*9+0] = PINE; buf[148*9+1] = PINH; buf[148*9+2] = PINJ; buf[148*9+3] = PINA; buf[148*9+4] = PINC; buf[148*9+5] = PIND; buf[148*9+6] = PING; buf[148*9+7] = PINL; buf[148*9+8] = PINB;
buf[149*9+0] = PINE; buf[149*9+1] = PINH; buf[149*9+2] = PINJ; buf[149*9+3] = PINA; buf[149*9+4] = PINC; buf[149*9+5] = PIND; buf[149*9+6] = PING; buf[149*9+7] = PINL; buf[149*9+8] = PINB;
buf[150*9+0] = PINE; buf[150*9+1] = PINH; buf[150*9+2] = PINJ; buf[150*9+3] = PINA; buf[150*9+4] = PINC; buf[150*9+5] = PIND; buf[150*9+6] = PING; buf[150*9+7] = PINL; buf[150*9+8] = PINB;
buf[151*9+0] = PINE; buf[151*9+1] = PINH; buf[151*9+2] = PINJ; buf[151*9+3] = PINA; buf[151*9+4] = PINC; buf[151*9+5] = PIND; buf[151*9+6] = PING; buf[151*9+7] = PINL; buf[151*9+8] = PINB;
buf[152*9+0] = PINE; buf[152*9+1] = PINH; buf[152*9+2] = PINJ; buf[152*9+3] = PINA; buf[152*9+4] = PINC; buf[152*9+5] = PIND; buf[152*9+6] = PING; buf[152*9+7] = PINL; buf[152*9+8] = PINB;
buf[153*9+0] = PINE; buf[153*9+1] = PINH; buf[153*9+2] = PINJ; buf[153*9+3] = PINA; buf[153*9+4] = PINC; buf[153*9+5] = PIND; buf[153*9+6] = PING; buf[153*9+7] = PINL; buf[153*9+8] = PINB;
buf[154*9+0] = PINE; buf[154*9+1] = PINH; buf[154*9+2] = PINJ; buf[154*9+3] = PINA; buf[154*9+4] = PINC; buf[154*9+5] = PIND; buf[154*9+6] = PING; buf[154*9+7] = PINL; buf[154*9+8] = PINB;
buf[155*9+0] = PINE; buf[155*9+1] = PINH; buf[155*9+2] = PINJ; buf[155*9+3] = PINA; buf[155*9+4] = PINC; buf[155*9+5] = PIND; buf[155*9+6] = PING; buf[155*9+7] = PINL; buf[155*9+8] = PINB;
buf[156*9+0] = PINE; buf[156*9+1] = PINH; buf[156*9+2] = PINJ; buf[156*9+3] = PINA; buf[156*9+4] = PINC; buf[156*9+5] = PIND; buf[156*9+6] = PING; buf[156*9+7] = PINL; buf[156*9+8] = PINB;
buf[157*9+0] = PINE; buf[157*9+1] = PINH; buf[157*9+2] = PINJ; buf[157*9+3] = PINA; buf[157*9+4] = PINC; buf[157*9+5] = PIND; buf[157*9+6] = PING; buf[157*9+7] = PINL; buf[157*9+8] = PINB;
buf[158*9+0] = PINE; buf[158*9+1] = PINH; buf[158*9+2] = PINJ; buf[158*9+3] = PINA; buf[158*9+4] = PINC; buf[158*9+5] = PIND; buf[158*9+6] = PING; buf[158*9+7] = PINL; buf[158*9+8] = PINB;
buf[159*9+0] = PINE; buf[159*9+1] = PINH; buf[159*9+2] = PINJ; buf[159*9+3] = PINA; buf[159*9+4] = PINC; buf[159*9+5] = PIND; buf[159*9+6] = PING; buf[159*9+7] = PINL; buf[159*9+8] = PINB;
buf[160*9+0] = PINE; buf[160*9+1] = PINH; buf[160*9+2] = PINJ; buf[160*9+3] = PINA; buf[160*9+4] = PINC; buf[160*9+5] = PIND; buf[160*9+6] = PING; buf[160*9+7] = PINL; buf[160*9+8] = PINB;
buf[161*9+0] = PINE; buf[161*9+1] = PINH; buf[161*9+2] = PINJ; buf[161*9+3] = PINA; buf[161*9+4] = PINC; buf[161*9+5] = PIND; buf[161*9+6] = PING; buf[161*9+7] = PINL; buf[161*9+8] = PINB;
buf[162*9+0] = PINE; buf[162*9+1] = PINH; buf[162*9+2] = PINJ; buf[162*9+3] = PINA; buf[162*9+4] = PINC; buf[162*9+5] = PIND; buf[162*9+6] = PING; buf[162*9+7] = PINL; buf[162*9+8] = PINB;
buf[163*9+0] = PINE; buf[163*9+1] = PINH; buf[163*9+2] = PINJ; buf[163*9+3] = PINA; buf[163*9+4] = PINC; buf[163*9+5] = PIND; buf[163*9+6] = PING; buf[163*9+7] = PINL; buf[163*9+8] = PINB;
buf[164*9+0] = PINE; buf[164*9+1] = PINH; buf[164*9+2] = PINJ; buf[164*9+3] = PINA; buf[164*9+4] = PINC; buf[164*9+5] = PIND; buf[164*9+6] = PING; buf[164*9+7] = PINL; buf[164*9+8] = PINB;
buf[165*9+0] = PINE; buf[165*9+1] = PINH; buf[165*9+2] = PINJ; buf[165*9+3] = PINA; buf[165*9+4] = PINC; buf[165*9+5] = PIND; buf[165*9+6] = PING; buf[165*9+7] = PINL; buf[165*9+8] = PINB;
buf[166*9+0] = PINE; buf[166*9+1] = PINH; buf[166*9+2] = PINJ; buf[166*9+3] = PINA; buf[166*9+4] = PINC; buf[166*9+5] = PIND; buf[166*9+6] = PING; buf[166*9+7] = PINL; buf[166*9+8] = PINB;
buf[167*9+0] = PINE; buf[167*9+1] = PINH; buf[167*9+2] = PINJ; buf[167*9+3] = PINA; buf[167*9+4] = PINC; buf[167*9+5] = PIND; buf[167*9+6] = PING; buf[167*9+7] = PINL; buf[167*9+8] = PINB;
buf[168*9+0] = PINE; buf[168*9+1] = PINH; buf[168*9+2] = PINJ; buf[168*9+3] = PINA; buf[168*9+4] = PINC; buf[168*9+5] = PIND; buf[168*9+6] = PING; buf[168*9+7] = PINL; buf[168*9+8] = PINB;
buf[169*9+0] = PINE; buf[169*9+1] = PINH; buf[169*9+2] = PINJ; buf[169*9+3] = PINA; buf[169*9+4] = PINC; buf[169*9+5] = PIND; buf[169*9+6] = PING; buf[169*9+7] = PINL; buf[169*9+8] = PINB;
buf[170*9+0] = PINE; buf[170*9+1] = PINH; buf[170*9+2] = PINJ; buf[170*9+3] = PINA; buf[170*9+4] = PINC; buf[170*9+5] = PIND; buf[170*9+6] = PING; buf[170*9+7] = PINL; buf[170*9+8] = PINB;
buf[171*9+0] = PINE; buf[171*9+1] = PINH; buf[171*9+2] = PINJ; buf[171*9+3] = PINA; buf[171*9+4] = PINC; buf[171*9+5] = PIND; buf[171*9+6] = PING; buf[171*9+7] = PINL; buf[171*9+8] = PINB;
buf[172*9+0] = PINE; buf[172*9+1] = PINH; buf[172*9+2] = PINJ; buf[172*9+3] = PINA; buf[172*9+4] = PINC; buf[172*9+5] = PIND; buf[172*9+6] = PING; buf[172*9+7] = PINL; buf[172*9+8] = PINB;
buf[173*9+0] = PINE; buf[173*9+1] = PINH; buf[173*9+2] = PINJ; buf[173*9+3] = PINA; buf[173*9+4] = PINC; buf[173*9+5] = PIND; buf[173*9+6] = PING; buf[173*9+7] = PINL; buf[173*9+8] = PINB;
buf[174*9+0] = PINE; buf[174*9+1] = PINH; buf[174*9+2] = PINJ; buf[174*9+3] = PINA; buf[174*9+4] = PINC; buf[174*9+5] = PIND; buf[174*9+6] = PING; buf[174*9+7] = PINL; buf[174*9+8] = PINB;
buf[175*9+0] = PINE; buf[175*9+1] = PINH; buf[175*9+2] = PINJ; buf[175*9+3] = PINA; buf[175*9+4] = PINC; buf[175*9+5] = PIND; buf[175*9+6] = PING; buf[175*9+7] = PINL; buf[175*9+8] = PINB;
buf[176*9+0] = PINE; buf[176*9+1] = PINH; buf[176*9+2] = PINJ; buf[176*9+3] = PINA; buf[176*9+4] = PINC; buf[176*9+5] = PIND; buf[176*9+6] = PING; buf[176*9+7] = PINL; buf[176*9+8] = PINB;
buf[177*9+0] = PINE; buf[177*9+1] = PINH; buf[177*9+2] = PINJ; buf[177*9+3] = PINA; buf[177*9+4] = PINC; buf[177*9+5] = PIND; buf[177*9+6] = PING; buf[177*9+7] = PINL; buf[177*9+8] = PINB;
buf[178*9+0] = PINE; buf[178*9+1] = PINH; buf[178*9+2] = PINJ; buf[178*9+3] = PINA; buf[178*9+4] = PINC; buf[178*9+5] = PIND; buf[178*9+6] = PING; buf[178*9+7] = PINL; buf[178*9+8] = PINB;
buf[179*9+0] = PINE; buf[179*9+1] = PINH; buf[179*9+2] = PINJ; buf[179*9+3] = PINA; buf[179*9+4] = PINC; buf[179*9+5] = PIND; buf[179*9+6] = PING; buf[179*9+7] = PINL; buf[179*9+8] = PINB;
buf[180*9+0] = PINE; buf[180*9+1] = PINH; buf[180*9+2] = PINJ; buf[180*9+3] = PINA; buf[180*9+4] = PINC; buf[180*9+5] = PIND; buf[180*9+6] = PING; buf[180*9+7] = PINL; buf[180*9+8] = PINB;
buf[181*9+0] = PINE; buf[181*9+1] = PINH; buf[181*9+2] = PINJ; buf[181*9+3] = PINA; buf[181*9+4] = PINC; buf[181*9+5] = PIND; buf[181*9+6] = PING; buf[181*9+7] = PINL; buf[181*9+8] = PINB;
buf[182*9+0] = PINE; buf[182*9+1] = PINH; buf[182*9+2] = PINJ; buf[182*9+3] = PINA; buf[182*9+4] = PINC; buf[182*9+5] = PIND; buf[182*9+6] = PING; buf[182*9+7] = PINL; buf[182*9+8] = PINB;
buf[183*9+0] = PINE; buf[183*9+1] = PINH; buf[183*9+2] = PINJ; buf[183*9+3] = PINA; buf[183*9+4] = PINC; buf[183*9+5] = PIND; buf[183*9+6] = PING; buf[183*9+7] = PINL; buf[183*9+8] = PINB;
buf[184*9+0] = PINE; buf[184*9+1] = PINH; buf[184*9+2] = PINJ; buf[184*9+3] = PINA; buf[184*9+4] = PINC; buf[184*9+5] = PIND; buf[184*9+6] = PING; buf[184*9+7] = PINL; buf[184*9+8] = PINB;
buf[185*9+0] = PINE; buf[185*9+1] = PINH; buf[185*9+2] = PINJ; buf[185*9+3] = PINA; buf[185*9+4] = PINC; buf[185*9+5] = PIND; buf[185*9+6] = PING; buf[185*9+7] = PINL; buf[185*9+8] = PINB;
buf[186*9+0] = PINE; buf[186*9+1] = PINH; buf[186*9+2] = PINJ; buf[186*9+3] = PINA; buf[186*9+4] = PINC; buf[186*9+5] = PIND; buf[186*9+6] = PING; buf[186*9+7] = PINL; buf[186*9+8] = PINB;
buf[187*9+0] = PINE; buf[187*9+1] = PINH; buf[187*9+2] = PINJ; buf[187*9+3] = PINA; buf[187*9+4] = PINC; buf[187*9+5] = PIND; buf[187*9+6] = PING; buf[187*9+7] = PINL; buf[187*9+8] = PINB;
buf[188*9+0] = PINE; buf[188*9+1] = PINH; buf[188*9+2] = PINJ; buf[188*9+3] = PINA; buf[188*9+4] = PINC; buf[188*9+5] = PIND; buf[188*9+6] = PING; buf[188*9+7] = PINL; buf[188*9+8] = PINB;
buf[189*9+0] = PINE; buf[189*9+1] = PINH; buf[189*9+2] = PINJ; buf[189*9+3] = PINA; buf[189*9+4] = PINC; buf[189*9+5] = PIND; buf[189*9+6] = PING; buf[189*9+7] = PINL; buf[189*9+8] = PINB;
buf[190*9+0] = PINE; buf[190*9+1] = PINH; buf[190*9+2] = PINJ; buf[190*9+3] = PINA; buf[190*9+4] = PINC; buf[190*9+5] = PIND; buf[190*9+6] = PING; buf[190*9+7] = PINL; buf[190*9+8] = PINB;
buf[191*9+0] = PINE; buf[191*9+1] = PINH; buf[191*9+2] = PINJ; buf[191*9+3] = PINA; buf[191*9+4] = PINC; buf[191*9+5] = PIND; buf[191*9+6] = PING; buf[191*9+7] = PINL; buf[191*9+8] = PINB;
buf[192*9+0] = PINE; buf[192*9+1] = PINH; buf[192*9+2] = PINJ; buf[192*9+3] = PINA; buf[192*9+4] = PINC; buf[192*9+5] = PIND; buf[192*9+6] = PING; buf[192*9+7] = PINL; buf[192*9+8] = PINB;
buf[193*9+0] = PINE; buf[193*9+1] = PINH; buf[193*9+2] = PINJ; buf[193*9+3] = PINA; buf[193*9+4] = PINC; buf[193*9+5] = PIND; buf[193*9+6] = PING; buf[193*9+7] = PINL; buf[193*9+8] = PINB;
buf[194*9+0] = PINE; buf[194*9+1] = PINH; buf[194*9+2] = PINJ; buf[194*9+3] = PINA; buf[194*9+4] = PINC; buf[194*9+5] = PIND; buf[194*9+6] = PING; buf[194*9+7] = PINL; buf[194*9+8] = PINB;
buf[195*9+0] = PINE; buf[195*9+1] = PINH; buf[195*9+2] = PINJ; buf[195*9+3] = PINA; buf[195*9+4] = PINC; buf[195*9+5] = PIND; buf[195*9+6] = PING; buf[195*9+7] = PINL; buf[195*9+8] = PINB;
buf[196*9+0] = PINE; buf[196*9+1] = PINH; buf[196*9+2] = PINJ; buf[196*9+3] = PINA; buf[196*9+4] = PINC; buf[196*9+5] = PIND; buf[196*9+6] = PING; buf[196*9+7] = PINL; buf[196*9+8] = PINB;
buf[197*9+0] = PINE; buf[197*9+1] = PINH; buf[197*9+2] = PINJ; buf[197*9+3] = PINA; buf[197*9+4] = PINC; buf[197*9+5] = PIND; buf[197*9+6] = PING; buf[197*9+7] = PINL; buf[197*9+8] = PINB;
buf[198*9+0] = PINE; buf[198*9+1] = PINH; buf[198*9+2] = PINJ; buf[198*9+3] = PINA; buf[198*9+4] = PINC; buf[198*9+5] = PIND; buf[198*9+6] = PING; buf[198*9+7] = PINL; buf[198*9+8] = PINB;
buf[199*9+0] = PINE; buf[199*9+1] = PINH; buf[199*9+2] = PINJ; buf[199*9+3] = PINA; buf[199*9+4] = PINC; buf[199*9+5] = PIND; buf[199*9+6] = PING; buf[199*9+7] = PINL; buf[199*9+8] = PINB;
buf[200*9+0] = PINE; buf[200*9+1] = PINH; buf[200*9+2] = PINJ; buf[200*9+3] = PINA; buf[200*9+4] = PINC; buf[200*9+5] = PIND; buf[200*9+6] = PING; buf[200*9+7] = PINL; buf[200*9+8] = PINB;
buf[201*9+0] = PINE; buf[201*9+1] = PINH; buf[201*9+2] = PINJ; buf[201*9+3] = PINA; buf[201*9+4] = PINC; buf[201*9+5] = PIND; buf[201*9+6] = PING; buf[201*9+7] = PINL; buf[201*9+8] = PINB;
buf[202*9+0] = PINE; buf[202*9+1] = PINH; buf[202*9+2] = PINJ; buf[202*9+3] = PINA; buf[202*9+4] = PINC; buf[202*9+5] = PIND; buf[202*9+6] = PING; buf[202*9+7] = PINL; buf[202*9+8] = PINB;
buf[203*9+0] = PINE; buf[203*9+1] = PINH; buf[203*9+2] = PINJ; buf[203*9+3] = PINA; buf[203*9+4] = PINC; buf[203*9+5] = PIND; buf[203*9+6] = PING; buf[203*9+7] = PINL; buf[203*9+8] = PINB;
buf[204*9+0] = PINE; buf[204*9+1] = PINH; buf[204*9+2] = PINJ; buf[204*9+3] = PINA; buf[204*9+4] = PINC; buf[204*9+5] = PIND; buf[204*9+6] = PING; buf[204*9+7] = PINL; buf[204*9+8] = PINB;
buf[205*9+0] = PINE; buf[205*9+1] = PINH; buf[205*9+2] = PINJ; buf[205*9+3] = PINA; buf[205*9+4] = PINC; buf[205*9+5] = PIND; buf[205*9+6] = PING; buf[205*9+7] = PINL; buf[205*9+8] = PINB;
buf[206*9+0] = PINE; buf[206*9+1] = PINH; buf[206*9+2] = PINJ; buf[206*9+3] = PINA; buf[206*9+4] = PINC; buf[206*9+5] = PIND; buf[206*9+6] = PING; buf[206*9+7] = PINL; buf[206*9+8] = PINB;
buf[207*9+0] = PINE; buf[207*9+1] = PINH; buf[207*9+2] = PINJ; buf[207*9+3] = PINA; buf[207*9+4] = PINC; buf[207*9+5] = PIND; buf[207*9+6] = PING; buf[207*9+7] = PINL; buf[207*9+8] = PINB;
buf[208*9+0] = PINE; buf[208*9+1] = PINH; buf[208*9+2] = PINJ; buf[208*9+3] = PINA; buf[208*9+4] = PINC; buf[208*9+5] = PIND; buf[208*9+6] = PING; buf[208*9+7] = PINL; buf[208*9+8] = PINB;
buf[209*9+0] = PINE; buf[209*9+1] = PINH; buf[209*9+2] = PINJ; buf[209*9+3] = PINA; buf[209*9+4] = PINC; buf[209*9+5] = PIND; buf[209*9+6] = PING; buf[209*9+7] = PINL; buf[209*9+8] = PINB;
buf[210*9+0] = PINE; buf[210*9+1] = PINH; buf[210*9+2] = PINJ; buf[210*9+3] = PINA; buf[210*9+4] = PINC; buf[210*9+5] = PIND; buf[210*9+6] = PING; buf[210*9+7] = PINL; buf[210*9+8] = PINB;
buf[211*9+0] = PINE; buf[211*9+1] = PINH; buf[211*9+2] = PINJ; buf[211*9+3] = PINA; buf[211*9+4] = PINC; buf[211*9+5] = PIND; buf[211*9+6] = PING; buf[211*9+7] = PINL; buf[211*9+8] = PINB;
buf[212*9+0] = PINE; buf[212*9+1] = PINH; buf[212*9+2] = PINJ; buf[212*9+3] = PINA; buf[212*9+4] = PINC; buf[212*9+5] = PIND; buf[212*9+6] = PING; buf[212*9+7] = PINL; buf[212*9+8] = PINB;
buf[213*9+0] = PINE; buf[213*9+1] = PINH; buf[213*9+2] = PINJ; buf[213*9+3] = PINA; buf[213*9+4] = PINC; buf[213*9+5] = PIND; buf[213*9+6] = PING; buf[213*9+7] = PINL; buf[213*9+8] = PINB;
buf[214*9+0] = PINE; buf[214*9+1] = PINH; buf[214*9+2] = PINJ; buf[214*9+3] = PINA; buf[214*9+4] = PINC; buf[214*9+5] = PIND; buf[214*9+6] = PING; buf[214*9+7] = PINL; buf[214*9+8] = PINB;
buf[215*9+0] = PINE; buf[215*9+1] = PINH; buf[215*9+2] = PINJ; buf[215*9+3] = PINA; buf[215*9+4] = PINC; buf[215*9+5] = PIND; buf[215*9+6] = PING; buf[215*9+7] = PINL; buf[215*9+8] = PINB;
buf[216*9+0] = PINE; buf[216*9+1] = PINH; buf[216*9+2] = PINJ; buf[216*9+3] = PINA; buf[216*9+4] = PINC; buf[216*9+5] = PIND; buf[216*9+6] = PING; buf[216*9+7] = PINL; buf[216*9+8] = PINB;
buf[217*9+0] = PINE; buf[217*9+1] = PINH; buf[217*9+2] = PINJ; buf[217*9+3] = PINA; buf[217*9+4] = PINC; buf[217*9+5] = PIND; buf[217*9+6] = PING; buf[217*9+7] = PINL; buf[217*9+8] = PINB;
buf[218*9+0] = PINE; buf[218*9+1] = PINH; buf[218*9+2] = PINJ; buf[218*9+3] = PINA; buf[218*9+4] = PINC; buf[218*9+5] = PIND; buf[218*9+6] = PING; buf[218*9+7] = PINL; buf[218*9+8] = PINB;
buf[219*9+0] = PINE; buf[219*9+1] = PINH; buf[219*9+2] = PINJ; buf[219*9+3] = PINA; buf[219*9+4] = PINC; buf[219*9+5] = PIND; buf[219*9+6] = PING; buf[219*9+7] = PINL; buf[219*9+8] = PINB;
buf[220*9+0] = PINE; buf[220*9+1] = PINH; buf[220*9+2] = PINJ; buf[220*9+3] = PINA; buf[220*9+4] = PINC; buf[220*9+5] = PIND; buf[220*9+6] = PING; buf[220*9+7] = PINL; buf[220*9+8] = PINB;
buf[221*9+0] = PINE; buf[221*9+1] = PINH; buf[221*9+2] = PINJ; buf[221*9+3] = PINA; buf[221*9+4] = PINC; buf[221*9+5] = PIND; buf[221*9+6] = PING; buf[221*9+7] = PINL; buf[221*9+8] = PINB;
buf[222*9+0] = PINE; buf[222*9+1] = PINH; buf[222*9+2] = PINJ; buf[222*9+3] = PINA; buf[222*9+4] = PINC; buf[222*9+5] = PIND; buf[222*9+6] = PING; buf[222*9+7] = PINL; buf[222*9+8] = PINB;
buf[223*9+0] = PINE; buf[223*9+1] = PINH; buf[223*9+2] = PINJ; buf[223*9+3] = PINA; buf[223*9+4] = PINC; buf[223*9+5] = PIND; buf[223*9+6] = PING; buf[223*9+7] = PINL; buf[223*9+8] = PINB;
buf[224*9+0] = PINE; buf[224*9+1] = PINH; buf[224*9+2] = PINJ; buf[224*9+3] = PINA; buf[224*9+4] = PINC; buf[224*9+5] = PIND; buf[224*9+6] = PING; buf[224*9+7] = PINL; buf[224*9+8] = PINB;
buf[225*9+0] = PINE; buf[225*9+1] = PINH; buf[225*9+2] = PINJ; buf[225*9+3] = PINA; buf[225*9+4] = PINC; buf[225*9+5] = PIND; buf[225*9+6] = PING; buf[225*9+7] = PINL; buf[225*9+8] = PINB;
buf[226*9+0] = PINE; buf[226*9+1] = PINH; buf[226*9+2] = PINJ; buf[226*9+3] = PINA; buf[226*9+4] = PINC; buf[226*9+5] = PIND; buf[226*9+6] = PING; buf[226*9+7] = PINL; buf[226*9+8] = PINB;
buf[227*9+0] = PINE; buf[227*9+1] = PINH; buf[227*9+2] = PINJ; buf[227*9+3] = PINA; buf[227*9+4] = PINC; buf[227*9+5] = PIND; buf[227*9+6] = PING; buf[227*9+7] = PINL; buf[227*9+8] = PINB;
buf[228*9+0] = PINE; buf[228*9+1] = PINH; buf[228*9+2] = PINJ; buf[228*9+3] = PINA; buf[228*9+4] = PINC; buf[228*9+5] = PIND; buf[228*9+6] = PING; buf[228*9+7] = PINL; buf[228*9+8] = PINB;
buf[229*9+0] = PINE; buf[229*9+1] = PINH; buf[229*9+2] = PINJ; buf[229*9+3] = PINA; buf[229*9+4] = PINC; buf[229*9+5] = PIND; buf[229*9+6] = PING; buf[229*9+7] = PINL; buf[229*9+8] = PINB;
buf[230*9+0] = PINE; buf[230*9+1] = PINH; buf[230*9+2] = PINJ; buf[230*9+3] = PINA; buf[230*9+4] = PINC; buf[230*9+5] = PIND; buf[230*9+6] = PING; buf[230*9+7] = PINL; buf[230*9+8] = PINB;
buf[231*9+0] = PINE; buf[231*9+1] = PINH; buf[231*9+2] = PINJ; buf[231*9+3] = PINA; buf[231*9+4] = PINC; buf[231*9+5] = PIND; buf[231*9+6] = PING; buf[231*9+7] = PINL; buf[231*9+8] = PINB;
buf[232*9+0] = PINE; buf[232*9+1] = PINH; buf[232*9+2] = PINJ; buf[232*9+3] = PINA; buf[232*9+4] = PINC; buf[232*9+5] = PIND; buf[232*9+6] = PING; buf[232*9+7] = PINL; buf[232*9+8] = PINB;
buf[233*9+0] = PINE; buf[233*9+1] = PINH; buf[233*9+2] = PINJ; buf[233*9+3] = PINA; buf[233*9+4] = PINC; buf[233*9+5] = PIND; buf[233*9+6] = PING; buf[233*9+7] = PINL; buf[233*9+8] = PINB;
buf[234*9+0] = PINE; buf[234*9+1] = PINH; buf[234*9+2] = PINJ; buf[234*9+3] = PINA; buf[234*9+4] = PINC; buf[234*9+5] = PIND; buf[234*9+6] = PING; buf[234*9+7] = PINL; buf[234*9+8] = PINB;
buf[235*9+0] = PINE; buf[235*9+1] = PINH; buf[235*9+2] = PINJ; buf[235*9+3] = PINA; buf[235*9+4] = PINC; buf[235*9+5] = PIND; buf[235*9+6] = PING; buf[235*9+7] = PINL; buf[235*9+8] = PINB;
buf[236*9+0] = PINE; buf[236*9+1] = PINH; buf[236*9+2] = PINJ; buf[236*9+3] = PINA; buf[236*9+4] = PINC; buf[236*9+5] = PIND; buf[236*9+6] = PING; buf[236*9+7] = PINL; buf[236*9+8] = PINB;
buf[237*9+0] = PINE; buf[237*9+1] = PINH; buf[237*9+2] = PINJ; buf[237*9+3] = PINA; buf[237*9+4] = PINC; buf[237*9+5] = PIND; buf[237*9+6] = PING; buf[237*9+7] = PINL; buf[237*9+8] = PINB;
buf[238*9+0] = PINE; buf[238*9+1] = PINH; buf[238*9+2] = PINJ; buf[238*9+3] = PINA; buf[238*9+4] = PINC; buf[238*9+5] = PIND; buf[238*9+6] = PING; buf[238*9+7] = PINL; buf[238*9+8] = PINB;
buf[239*9+0] = PINE; buf[239*9+1] = PINH; buf[239*9+2] = PINJ; buf[239*9+3] = PINA; buf[239*9+4] = PINC; buf[239*9+5] = PIND; buf[239*9+6] = PING; buf[239*9+7] = PINL; buf[239*9+8] = PINB;
buf[240*9+0] = PINE; buf[240*9+1] = PINH; buf[240*9+2] = PINJ; buf[240*9+3] = PINA; buf[240*9+4] = PINC; buf[240*9+5] = PIND; buf[240*9+6] = PING; buf[240*9+7] = PINL; buf[240*9+8] = PINB;
buf[241*9+0] = PINE; buf[241*9+1] = PINH; buf[241*9+2] = PINJ; buf[241*9+3] = PINA; buf[241*9+4] = PINC; buf[241*9+5] = PIND; buf[241*9+6] = PING; buf[241*9+7] = PINL; buf[241*9+8] = PINB;
buf[242*9+0] = PINE; buf[242*9+1] = PINH; buf[242*9+2] = PINJ; buf[242*9+3] = PINA; buf[242*9+4] = PINC; buf[242*9+5] = PIND; buf[242*9+6] = PING; buf[242*9+7] = PINL; buf[242*9+8] = PINB;
buf[243*9+0] = PINE; buf[243*9+1] = PINH; buf[243*9+2] = PINJ; buf[243*9+3] = PINA; buf[243*9+4] = PINC; buf[243*9+5] = PIND; buf[243*9+6] = PING; buf[243*9+7] = PINL; buf[243*9+8] = PINB;
buf[244*9+0] = PINE; buf[244*9+1] = PINH; buf[244*9+2] = PINJ; buf[244*9+3] = PINA; buf[244*9+4] = PINC; buf[244*9+5] = PIND; buf[244*9+6] = PING; buf[244*9+7] = PINL; buf[244*9+8] = PINB;
buf[245*9+0] = PINE; buf[245*9+1] = PINH; buf[245*9+2] = PINJ; buf[245*9+3] = PINA; buf[245*9+4] = PINC; buf[245*9+5] = PIND; buf[245*9+6] = PING; buf[245*9+7] = PINL; buf[245*9+8] = PINB;
buf[246*9+0] = PINE; buf[246*9+1] = PINH; buf[246*9+2] = PINJ; buf[246*9+3] = PINA; buf[246*9+4] = PINC; buf[246*9+5] = PIND; buf[246*9+6] = PING; buf[246*9+7] = PINL; buf[246*9+8] = PINB;
buf[247*9+0] = PINE; buf[247*9+1] = PINH; buf[247*9+2] = PINJ; buf[247*9+3] = PINA; buf[247*9+4] = PINC; buf[247*9+5] = PIND; buf[247*9+6] = PING; buf[247*9+7] = PINL; buf[247*9+8] = PINB;
buf[248*9+0] = PINE; buf[248*9+1] = PINH; buf[248*9+2] = PINJ; buf[248*9+3] = PINA; buf[248*9+4] = PINC; buf[248*9+5] = PIND; buf[248*9+6] = PING; buf[248*9+7] = PINL; buf[248*9+8] = PINB;
buf[249*9+0] = PINE; buf[249*9+1] = PINH; buf[249*9+2] = PINJ; buf[249*9+3] = PINA; buf[249*9+4] = PINC; buf[249*9+5] = PIND; buf[249*9+6] = PING; buf[249*9+7] = PINL; buf[249*9+8] = PINB;
buf[250*9+0] = PINE; buf[250*9+1] = PINH; buf[250*9+2] = PINJ; buf[250*9+3] = PINA; buf[250*9+4] = PINC; buf[250*9+5] = PIND; buf[250*9+6] = PING; buf[250*9+7] = PINL; buf[250*9+8] = PINB;
buf[251*9+0] = PINE; buf[251*9+1] = PINH; buf[251*9+2] = PINJ; buf[251*9+3] = PINA; buf[251*9+4] = PINC; buf[251*9+5] = PIND; buf[251*9+6] = PING; buf[251*9+7] = PINL; buf[251*9+8] = PINB;
buf[252*9+0] = PINE; buf[252*9+1] = PINH; buf[252*9+2] = PINJ; buf[252*9+3] = PINA; buf[252*9+4] = PINC; buf[252*9+5] = PIND; buf[252*9+6] = PING; buf[252*9+7] = PINL; buf[252*9+8] = PINB;
buf[253*9+0] = PINE; buf[253*9+1] = PINH; buf[253*9+2] = PINJ; buf[253*9+3] = PINA; buf[253*9+4] = PINC; buf[253*9+5] = PIND; buf[253*9+6] = PING; buf[253*9+7] = PINL; buf[253*9+8] = PINB;
buf[254*9+0] = PINE; buf[254*9+1] = PINH; buf[254*9+2] = PINJ; buf[254*9+3] = PINA; buf[254*9+4] = PINC; buf[254*9+5] = PIND; buf[254*9+6] = PING; buf[254*9+7] = PINL; buf[254*9+8] = PINB;
buf[255*9+0] = PINE; buf[255*9+1] = PINH; buf[255*9+2] = PINJ; buf[255*9+3] = PINA; buf[255*9+4] = PINC; buf[255*9+5] = PIND; buf[255*9+6] = PING; buf[255*9+7] = PINL; buf[255*9+8] = PINB;
buf[256*9+0] = PINE; buf[256*9+1] = PINH; buf[256*9+2] = PINJ; buf[256*9+3] = PINA; buf[256*9+4] = PINC; buf[256*9+5] = PIND; buf[256*9+6] = PING; buf[256*9+7] = PINL; buf[256*9+8] = PINB;
buf[257*9+0] = PINE; buf[257*9+1] = PINH; buf[257*9+2] = PINJ; buf[257*9+3] = PINA; buf[257*9+4] = PINC; buf[257*9+5] = PIND; buf[257*9+6] = PING; buf[257*9+7] = PINL; buf[257*9+8] = PINB;
buf[258*9+0] = PINE; buf[258*9+1] = PINH; buf[258*9+2] = PINJ; buf[258*9+3] = PINA; buf[258*9+4] = PINC; buf[258*9+5] = PIND; buf[258*9+6] = PING; buf[258*9+7] = PINL; buf[258*9+8] = PINB;
buf[259*9+0] = PINE; buf[259*9+1] = PINH; buf[259*9+2] = PINJ; buf[259*9+3] = PINA; buf[259*9+4] = PINC; buf[259*9+5] = PIND; buf[259*9+6] = PING; buf[259*9+7] = PINL; buf[259*9+8] = PINB;
buf[260*9+0] = PINE; buf[260*9+1] = PINH; buf[260*9+2] = PINJ; buf[260*9+3] = PINA; buf[260*9+4] = PINC; buf[260*9+5] = PIND; buf[260*9+6] = PING; buf[260*9+7] = PINL; buf[260*9+8] = PINB;
buf[261*9+0] = PINE; buf[261*9+1] = PINH; buf[261*9+2] = PINJ; buf[261*9+3] = PINA; buf[261*9+4] = PINC; buf[261*9+5] = PIND; buf[261*9+6] = PING; buf[261*9+7] = PINL; buf[261*9+8] = PINB;
buf[262*9+0] = PINE; buf[262*9+1] = PINH; buf[262*9+2] = PINJ; buf[262*9+3] = PINA; buf[262*9+4] = PINC; buf[262*9+5] = PIND; buf[262*9+6] = PING; buf[262*9+7] = PINL; buf[262*9+8] = PINB;
buf[263*9+0] = PINE; buf[263*9+1] = PINH; buf[263*9+2] = PINJ; buf[263*9+3] = PINA; buf[263*9+4] = PINC; buf[263*9+5] = PIND; buf[263*9+6] = PING; buf[263*9+7] = PINL; buf[263*9+8] = PINB;
buf[264*9+0] = PINE; buf[264*9+1] = PINH; buf[264*9+2] = PINJ; buf[264*9+3] = PINA; buf[264*9+4] = PINC; buf[264*9+5] = PIND; buf[264*9+6] = PING; buf[264*9+7] = PINL; buf[264*9+8] = PINB;
buf[265*9+0] = PINE; buf[265*9+1] = PINH; buf[265*9+2] = PINJ; buf[265*9+3] = PINA; buf[265*9+4] = PINC; buf[265*9+5] = PIND; buf[265*9+6] = PING; buf[265*9+7] = PINL; buf[265*9+8] = PINB;
buf[266*9+0] = PINE; buf[266*9+1] = PINH; buf[266*9+2] = PINJ; buf[266*9+3] = PINA; buf[266*9+4] = PINC; buf[266*9+5] = PIND; buf[266*9+6] = PING; buf[266*9+7] = PINL; buf[266*9+8] = PINB;
buf[267*9+0] = PINE; buf[267*9+1] = PINH; buf[267*9+2] = PINJ; buf[267*9+3] = PINA; buf[267*9+4] = PINC; buf[267*9+5] = PIND; buf[267*9+6] = PING; buf[267*9+7] = PINL; buf[267*9+8] = PINB;
buf[268*9+0] = PINE; buf[268*9+1] = PINH; buf[268*9+2] = PINJ; buf[268*9+3] = PINA; buf[268*9+4] = PINC; buf[268*9+5] = PIND; buf[268*9+6] = PING; buf[268*9+7] = PINL; buf[268*9+8] = PINB;
buf[269*9+0] = PINE; buf[269*9+1] = PINH; buf[269*9+2] = PINJ; buf[269*9+3] = PINA; buf[269*9+4] = PINC; buf[269*9+5] = PIND; buf[269*9+6] = PING; buf[269*9+7] = PINL; buf[269*9+8] = PINB;
buf[270*9+0] = PINE; buf[270*9+1] = PINH; buf[270*9+2] = PINJ; buf[270*9+3] = PINA; buf[270*9+4] = PINC; buf[270*9+5] = PIND; buf[270*9+6] = PING; buf[270*9+7] = PINL; buf[270*9+8] = PINB;
buf[271*9+0] = PINE; buf[271*9+1] = PINH; buf[271*9+2] = PINJ; buf[271*9+3] = PINA; buf[271*9+4] = PINC; buf[271*9+5] = PIND; buf[271*9+6] = PING; buf[271*9+7] = PINL; buf[271*9+8] = PINB;
buf[272*9+0] = PINE; buf[272*9+1] = PINH; buf[272*9+2] = PINJ; buf[272*9+3] = PINA; buf[272*9+4] = PINC; buf[272*9+5] = PIND; buf[272*9+6] = PING; buf[272*9+7] = PINL; buf[272*9+8] = PINB;
buf[273*9+0] = PINE; buf[273*9+1] = PINH; buf[273*9+2] = PINJ; buf[273*9+3] = PINA; buf[273*9+4] = PINC; buf[273*9+5] = PIND; buf[273*9+6] = PING; buf[273*9+7] = PINL; buf[273*9+8] = PINB;
buf[274*9+0] = PINE; buf[274*9+1] = PINH; buf[274*9+2] = PINJ; buf[274*9+3] = PINA; buf[274*9+4] = PINC; buf[274*9+5] = PIND; buf[274*9+6] = PING; buf[274*9+7] = PINL; buf[274*9+8] = PINB;
buf[275*9+0] = PINE; buf[275*9+1] = PINH; buf[275*9+2] = PINJ; buf[275*9+3] = PINA; buf[275*9+4] = PINC; buf[275*9+5] = PIND; buf[275*9+6] = PING; buf[275*9+7] = PINL; buf[275*9+8] = PINB;
buf[276*9+0] = PINE; buf[276*9+1] = PINH; buf[276*9+2] = PINJ; buf[276*9+3] = PINA; buf[276*9+4] = PINC; buf[276*9+5] = PIND; buf[276*9+6] = PING; buf[276*9+7] = PINL; buf[276*9+8] = PINB;
buf[277*9+0] = PINE; buf[277*9+1] = PINH; buf[277*9+2] = PINJ; buf[277*9+3] = PINA; buf[277*9+4] = PINC; buf[277*9+5] = PIND; buf[277*9+6] = PING; buf[277*9+7] = PINL; buf[277*9+8] = PINB;
buf[278*9+0] = PINE; buf[278*9+1] = PINH; buf[278*9+2] = PINJ; buf[278*9+3] = PINA; buf[278*9+4] = PINC; buf[278*9+5] = PIND; buf[278*9+6] = PING; buf[278*9+7] = PINL; buf[278*9+8] = PINB;
buf[279*9+0] = PINE; buf[279*9+1] = PINH; buf[279*9+2] = PINJ; buf[279*9+3] = PINA; buf[279*9+4] = PINC; buf[279*9+5] = PIND; buf[279*9+6] = PING; buf[279*9+7] = PINL; buf[279*9+8] = PINB;
buf[280*9+0] = PINE; buf[280*9+1] = PINH; buf[280*9+2] = PINJ; buf[280*9+3] = PINA; buf[280*9+4] = PINC; buf[280*9+5] = PIND; buf[280*9+6] = PING; buf[280*9+7] = PINL; buf[280*9+8] = PINB;
buf[281*9+0] = PINE; buf[281*9+1] = PINH; buf[281*9+2] = PINJ; buf[281*9+3] = PINA; buf[281*9+4] = PINC; buf[281*9+5] = PIND; buf[281*9+6] = PING; buf[281*9+7] = PINL; buf[281*9+8] = PINB;
buf[282*9+0] = PINE; buf[282*9+1] = PINH; buf[282*9+2] = PINJ; buf[282*9+3] = PINA; buf[282*9+4] = PINC; buf[282*9+5] = PIND; buf[282*9+6] = PING; buf[282*9+7] = PINL; buf[282*9+8] = PINB;
buf[283*9+0] = PINE; buf[283*9+1] = PINH; buf[283*9+2] = PINJ; buf[283*9+3] = PINA; buf[283*9+4] = PINC; buf[283*9+5] = PIND; buf[283*9+6] = PING; buf[283*9+7] = PINL; buf[283*9+8] = PINB;
buf[284*9+0] = PINE; buf[284*9+1] = PINH; buf[284*9+2] = PINJ; buf[284*9+3] = PINA; buf[284*9+4] = PINC; buf[284*9+5] = PIND; buf[284*9+6] = PING; buf[284*9+7] = PINL; buf[284*9+8] = PINB;
buf[285*9+0] = PINE; buf[285*9+1] = PINH; buf[285*9+2] = PINJ; buf[285*9+3] = PINA; buf[285*9+4] = PINC; buf[285*9+5] = PIND; buf[285*9+6] = PING; buf[285*9+7] = PINL; buf[285*9+8] = PINB;
buf[286*9+0] = PINE; buf[286*9+1] = PINH; buf[286*9+2] = PINJ; buf[286*9+3] = PINA; buf[286*9+4] = PINC; buf[286*9+5] = PIND; buf[286*9+6] = PING; buf[286*9+7] = PINL; buf[286*9+8] = PINB;
buf[287*9+0] = PINE; buf[287*9+1] = PINH; buf[287*9+2] = PINJ; buf[287*9+3] = PINA; buf[287*9+4] = PINC; buf[287*9+5] = PIND; buf[287*9+6] = PING; buf[287*9+7] = PINL; buf[287*9+8] = PINB;
buf[288*9+0] = PINE; buf[288*9+1] = PINH; buf[288*9+2] = PINJ; buf[288*9+3] = PINA; buf[288*9+4] = PINC; buf[288*9+5] = PIND; buf[288*9+6] = PING; buf[288*9+7] = PINL; buf[288*9+8] = PINB;
buf[289*9+0] = PINE; buf[289*9+1] = PINH; buf[289*9+2] = PINJ; buf[289*9+3] = PINA; buf[289*9+4] = PINC; buf[289*9+5] = PIND; buf[289*9+6] = PING; buf[289*9+7] = PINL; buf[289*9+8] = PINB;
buf[290*9+0] = PINE; buf[290*9+1] = PINH; buf[290*9+2] = PINJ; buf[290*9+3] = PINA; buf[290*9+4] = PINC; buf[290*9+5] = PIND; buf[290*9+6] = PING; buf[290*9+7] = PINL; buf[290*9+8] = PINB;
buf[291*9+0] = PINE; buf[291*9+1] = PINH; buf[291*9+2] = PINJ; buf[291*9+3] = PINA; buf[291*9+4] = PINC; buf[291*9+5] = PIND; buf[291*9+6] = PING; buf[291*9+7] = PINL; buf[291*9+8] = PINB;
buf[292*9+0] = PINE; buf[292*9+1] = PINH; buf[292*9+2] = PINJ; buf[292*9+3] = PINA; buf[292*9+4] = PINC; buf[292*9+5] = PIND; buf[292*9+6] = PING; buf[292*9+7] = PINL; buf[292*9+8] = PINB;
buf[293*9+0] = PINE; buf[293*9+1] = PINH; buf[293*9+2] = PINJ; buf[293*9+3] = PINA; buf[293*9+4] = PINC; buf[293*9+5] = PIND; buf[293*9+6] = PING; buf[293*9+7] = PINL; buf[293*9+8] = PINB;
buf[294*9+0] = PINE; buf[294*9+1] = PINH; buf[294*9+2] = PINJ; buf[294*9+3] = PINA; buf[294*9+4] = PINC; buf[294*9+5] = PIND; buf[294*9+6] = PING; buf[294*9+7] = PINL; buf[294*9+8] = PINB;
buf[295*9+0] = PINE; buf[295*9+1] = PINH; buf[295*9+2] = PINJ; buf[295*9+3] = PINA; buf[295*9+4] = PINC; buf[295*9+5] = PIND; buf[295*9+6] = PING; buf[295*9+7] = PINL; buf[295*9+8] = PINB;
buf[296*9+0] = PINE; buf[296*9+1] = PINH; buf[296*9+2] = PINJ; buf[296*9+3] = PINA; buf[296*9+4] = PINC; buf[296*9+5] = PIND; buf[296*9+6] = PING; buf[296*9+7] = PINL; buf[296*9+8] = PINB;
buf[297*9+0] = PINE; buf[297*9+1] = PINH; buf[297*9+2] = PINJ; buf[297*9+3] = PINA; buf[297*9+4] = PINC; buf[297*9+5] = PIND; buf[297*9+6] = PING; buf[297*9+7] = PINL; buf[297*9+8] = PINB;
buf[298*9+0] = PINE; buf[298*9+1] = PINH; buf[298*9+2] = PINJ; buf[298*9+3] = PINA; buf[298*9+4] = PINC; buf[298*9+5] = PIND; buf[298*9+6] = PING; buf[298*9+7] = PINL; buf[298*9+8] = PINB;
buf[299*9+0] = PINE; buf[299*9+1] = PINH; buf[299*9+2] = PINJ; buf[299*9+3] = PINA; buf[299*9+4] = PINC; buf[299*9+5] = PIND; buf[299*9+6] = PING; buf[299*9+7] = PINL; buf[299*9+8] = PINB;
buf[300*9+0] = PINE; buf[300*9+1] = PINH; buf[300*9+2] = PINJ; buf[300*9+3] = PINA; buf[300*9+4] = PINC; buf[300*9+5] = PIND; buf[300*9+6] = PING; buf[300*9+7] = PINL; buf[300*9+8] = PINB;
buf[301*9+0] = PINE; buf[301*9+1] = PINH; buf[301*9+2] = PINJ; buf[301*9+3] = PINA; buf[301*9+4] = PINC; buf[301*9+5] = PIND; buf[301*9+6] = PING; buf[301*9+7] = PINL; buf[301*9+8] = PINB;
buf[302*9+0] = PINE; buf[302*9+1] = PINH; buf[302*9+2] = PINJ; buf[302*9+3] = PINA; buf[302*9+4] = PINC; buf[302*9+5] = PIND; buf[302*9+6] = PING; buf[302*9+7] = PINL; buf[302*9+8] = PINB;
buf[303*9+0] = PINE; buf[303*9+1] = PINH; buf[303*9+2] = PINJ; buf[303*9+3] = PINA; buf[303*9+4] = PINC; buf[303*9+5] = PIND; buf[303*9+6] = PING; buf[303*9+7] = PINL; buf[303*9+8] = PINB;
buf[304*9+0] = PINE; buf[304*9+1] = PINH; buf[304*9+2] = PINJ; buf[304*9+3] = PINA; buf[304*9+4] = PINC; buf[304*9+5] = PIND; buf[304*9+6] = PING; buf[304*9+7] = PINL; buf[304*9+8] = PINB;
buf[305*9+0] = PINE; buf[305*9+1] = PINH; buf[305*9+2] = PINJ; buf[305*9+3] = PINA; buf[305*9+4] = PINC; buf[305*9+5] = PIND; buf[305*9+6] = PING; buf[305*9+7] = PINL; buf[305*9+8] = PINB;
buf[306*9+0] = PINE; buf[306*9+1] = PINH; buf[306*9+2] = PINJ; buf[306*9+3] = PINA; buf[306*9+4] = PINC; buf[306*9+5] = PIND; buf[306*9+6] = PING; buf[306*9+7] = PINL; buf[306*9+8] = PINB;
buf[307*9+0] = PINE; buf[307*9+1] = PINH; buf[307*9+2] = PINJ; buf[307*9+3] = PINA; buf[307*9+4] = PINC; buf[307*9+5] = PIND; buf[307*9+6] = PING; buf[307*9+7] = PINL; buf[307*9+8] = PINB;
buf[308*9+0] = PINE; buf[308*9+1] = PINH; buf[308*9+2] = PINJ; buf[308*9+3] = PINA; buf[308*9+4] = PINC; buf[308*9+5] = PIND; buf[308*9+6] = PING; buf[308*9+7] = PINL; buf[308*9+8] = PINB;
buf[309*9+0] = PINE; buf[309*9+1] = PINH; buf[309*9+2] = PINJ; buf[309*9+3] = PINA; buf[309*9+4] = PINC; buf[309*9+5] = PIND; buf[309*9+6] = PING; buf[309*9+7] = PINL; buf[309*9+8] = PINB;
buf[310*9+0] = PINE; buf[310*9+1] = PINH; buf[310*9+2] = PINJ; buf[310*9+3] = PINA; buf[310*9+4] = PINC; buf[310*9+5] = PIND; buf[310*9+6] = PING; buf[310*9+7] = PINL; buf[310*9+8] = PINB;
buf[311*9+0] = PINE; buf[311*9+1] = PINH; buf[311*9+2] = PINJ; buf[311*9+3] = PINA; buf[311*9+4] = PINC; buf[311*9+5] = PIND; buf[311*9+6] = PING; buf[311*9+7] = PINL; buf[311*9+8] = PINB;
buf[312*9+0] = PINE; buf[312*9+1] = PINH; buf[312*9+2] = PINJ; buf[312*9+3] = PINA; buf[312*9+4] = PINC; buf[312*9+5] = PIND; buf[312*9+6] = PING; buf[312*9+7] = PINL; buf[312*9+8] = PINB;
buf[313*9+0] = PINE; buf[313*9+1] = PINH; buf[313*9+2] = PINJ; buf[313*9+3] = PINA; buf[313*9+4] = PINC; buf[313*9+5] = PIND; buf[313*9+6] = PING; buf[313*9+7] = PINL; buf[313*9+8] = PINB;
buf[314*9+0] = PINE; buf[314*9+1] = PINH; buf[314*9+2] = PINJ; buf[314*9+3] = PINA; buf[314*9+4] = PINC; buf[314*9+5] = PIND; buf[314*9+6] = PING; buf[314*9+7] = PINL; buf[314*9+8] = PINB;
buf[315*9+0] = PINE; buf[315*9+1] = PINH; buf[315*9+2] = PINJ; buf[315*9+3] = PINA; buf[315*9+4] = PINC; buf[315*9+5] = PIND; buf[315*9+6] = PING; buf[315*9+7] = PINL; buf[315*9+8] = PINB;
buf[316*9+0] = PINE; buf[316*9+1] = PINH; buf[316*9+2] = PINJ; buf[316*9+3] = PINA; buf[316*9+4] = PINC; buf[316*9+5] = PIND; buf[316*9+6] = PING; buf[316*9+7] = PINL; buf[316*9+8] = PINB;
buf[317*9+0] = PINE; buf[317*9+1] = PINH; buf[317*9+2] = PINJ; buf[317*9+3] = PINA; buf[317*9+4] = PINC; buf[317*9+5] = PIND; buf[317*9+6] = PING; buf[317*9+7] = PINL; buf[317*9+8] = PINB;
buf[318*9+0] = PINE; buf[318*9+1] = PINH; buf[318*9+2] = PINJ; buf[318*9+3] = PINA; buf[318*9+4] = PINC; buf[318*9+5] = PIND; buf[318*9+6] = PING; buf[318*9+7] = PINL; buf[318*9+8] = PINB;
buf[319*9+0] = PINE; buf[319*9+1] = PINH; buf[319*9+2] = PINJ; buf[319*9+3] = PINA; buf[319*9+4] = PINC; buf[319*9+5] = PIND; buf[319*9+6] = PING; buf[319*9+7] = PINL; buf[319*9+8] = PINB;
buf[320*9+0] = PINE; buf[320*9+1] = PINH; buf[320*9+2] = PINJ; buf[320*9+3] = PINA; buf[320*9+4] = PINC; buf[320*9+5] = PIND; buf[320*9+6] = PING; buf[320*9+7] = PINL; buf[320*9+8] = PINB;
buf[321*9+0] = PINE; buf[321*9+1] = PINH; buf[321*9+2] = PINJ; buf[321*9+3] = PINA; buf[321*9+4] = PINC; buf[321*9+5] = PIND; buf[321*9+6] = PING; buf[321*9+7] = PINL; buf[321*9+8] = PINB;
buf[322*9+0] = PINE; buf[322*9+1] = PINH; buf[322*9+2] = PINJ; buf[322*9+3] = PINA; buf[322*9+4] = PINC; buf[322*9+5] = PIND; buf[322*9+6] = PING; buf[322*9+7] = PINL; buf[322*9+8] = PINB;
buf[323*9+0] = PINE; buf[323*9+1] = PINH; buf[323*9+2] = PINJ; buf[323*9+3] = PINA; buf[323*9+4] = PINC; buf[323*9+5] = PIND; buf[323*9+6] = PING; buf[323*9+7] = PINL; buf[323*9+8] = PINB;
buf[324*9+0] = PINE; buf[324*9+1] = PINH; buf[324*9+2] = PINJ; buf[324*9+3] = PINA; buf[324*9+4] = PINC; buf[324*9+5] = PIND; buf[324*9+6] = PING; buf[324*9+7] = PINL; buf[324*9+8] = PINB;
buf[325*9+0] = PINE; buf[325*9+1] = PINH; buf[325*9+2] = PINJ; buf[325*9+3] = PINA; buf[325*9+4] = PINC; buf[325*9+5] = PIND; buf[325*9+6] = PING; buf[325*9+7] = PINL; buf[325*9+8] = PINB;
buf[326*9+0] = PINE; buf[326*9+1] = PINH; buf[326*9+2] = PINJ; buf[326*9+3] = PINA; buf[326*9+4] = PINC; buf[326*9+5] = PIND; buf[326*9+6] = PING; buf[326*9+7] = PINL; buf[326*9+8] = PINB;
buf[327*9+0] = PINE; buf[327*9+1] = PINH; buf[327*9+2] = PINJ; buf[327*9+3] = PINA; buf[327*9+4] = PINC; buf[327*9+5] = PIND; buf[327*9+6] = PING; buf[327*9+7] = PINL; buf[327*9+8] = PINB;
buf[328*9+0] = PINE; buf[328*9+1] = PINH; buf[328*9+2] = PINJ; buf[328*9+3] = PINA; buf[328*9+4] = PINC; buf[328*9+5] = PIND; buf[328*9+6] = PING; buf[328*9+7] = PINL; buf[328*9+8] = PINB;
buf[329*9+0] = PINE; buf[329*9+1] = PINH; buf[329*9+2] = PINJ; buf[329*9+3] = PINA; buf[329*9+4] = PINC; buf[329*9+5] = PIND; buf[329*9+6] = PING; buf[329*9+7] = PINL; buf[329*9+8] = PINB;
buf[330*9+0] = PINE; buf[330*9+1] = PINH; buf[330*9+2] = PINJ; buf[330*9+3] = PINA; buf[330*9+4] = PINC; buf[330*9+5] = PIND; buf[330*9+6] = PING; buf[330*9+7] = PINL; buf[330*9+8] = PINB;
buf[331*9+0] = PINE; buf[331*9+1] = PINH; buf[331*9+2] = PINJ; buf[331*9+3] = PINA; buf[331*9+4] = PINC; buf[331*9+5] = PIND; buf[331*9+6] = PING; buf[331*9+7] = PINL; buf[331*9+8] = PINB;
buf[332*9+0] = PINE; buf[332*9+1] = PINH; buf[332*9+2] = PINJ; buf[332*9+3] = PINA; buf[332*9+4] = PINC; buf[332*9+5] = PIND; buf[332*9+6] = PING; buf[332*9+7] = PINL; buf[332*9+8] = PINB;
buf[333*9+0] = PINE; buf[333*9+1] = PINH; buf[333*9+2] = PINJ; buf[333*9+3] = PINA; buf[333*9+4] = PINC; buf[333*9+5] = PIND; buf[333*9+6] = PING; buf[333*9+7] = PINL; buf[333*9+8] = PINB;
buf[334*9+0] = PINE; buf[334*9+1] = PINH; buf[334*9+2] = PINJ; buf[334*9+3] = PINA; buf[334*9+4] = PINC; buf[334*9+5] = PIND; buf[334*9+6] = PING; buf[334*9+7] = PINL; buf[334*9+8] = PINB;
buf[335*9+0] = PINE; buf[335*9+1] = PINH; buf[335*9+2] = PINJ; buf[335*9+3] = PINA; buf[335*9+4] = PINC; buf[335*9+5] = PIND; buf[335*9+6] = PING; buf[335*9+7] = PINL; buf[335*9+8] = PINB;
buf[336*9+0] = PINE; buf[336*9+1] = PINH; buf[336*9+2] = PINJ; buf[336*9+3] = PINA; buf[336*9+4] = PINC; buf[336*9+5] = PIND; buf[336*9+6] = PING; buf[336*9+7] = PINL; buf[336*9+8] = PINB;
buf[337*9+0] = PINE; buf[337*9+1] = PINH; buf[337*9+2] = PINJ; buf[337*9+3] = PINA; buf[337*9+4] = PINC; buf[337*9+5] = PIND; buf[337*9+6] = PING; buf[337*9+7] = PINL; buf[337*9+8] = PINB;
buf[338*9+0] = PINE; buf[338*9+1] = PINH; buf[338*9+2] = PINJ; buf[338*9+3] = PINA; buf[338*9+4] = PINC; buf[338*9+5] = PIND; buf[338*9+6] = PING; buf[338*9+7] = PINL; buf[338*9+8] = PINB;
buf[339*9+0] = PINE; buf[339*9+1] = PINH; buf[339*9+2] = PINJ; buf[339*9+3] = PINA; buf[339*9+4] = PINC; buf[339*9+5] = PIND; buf[339*9+6] = PING; buf[339*9+7] = PINL; buf[339*9+8] = PINB;
buf[340*9+0] = PINE; buf[340*9+1] = PINH; buf[340*9+2] = PINJ; buf[340*9+3] = PINA; buf[340*9+4] = PINC; buf[340*9+5] = PIND; buf[340*9+6] = PING; buf[340*9+7] = PINL; buf[340*9+8] = PINB;
buf[341*9+0] = PINE; buf[341*9+1] = PINH; buf[341*9+2] = PINJ; buf[341*9+3] = PINA; buf[341*9+4] = PINC; buf[341*9+5] = PIND; buf[341*9+6] = PING; buf[341*9+7] = PINL; buf[341*9+8] = PINB;
buf[342*9+0] = PINE; buf[342*9+1] = PINH; buf[342*9+2] = PINJ; buf[342*9+3] = PINA; buf[342*9+4] = PINC; buf[342*9+5] = PIND; buf[342*9+6] = PING; buf[342*9+7] = PINL; buf[342*9+8] = PINB;
buf[343*9+0] = PINE; buf[343*9+1] = PINH; buf[343*9+2] = PINJ; buf[343*9+3] = PINA; buf[343*9+4] = PINC; buf[343*9+5] = PIND; buf[343*9+6] = PING; buf[343*9+7] = PINL; buf[343*9+8] = PINB;
buf[344*9+0] = PINE; buf[344*9+1] = PINH; buf[344*9+2] = PINJ; buf[344*9+3] = PINA; buf[344*9+4] = PINC; buf[344*9+5] = PIND; buf[344*9+6] = PING; buf[344*9+7] = PINL; buf[344*9+8] = PINB;
buf[345*9+0] = PINE; buf[345*9+1] = PINH; buf[345*9+2] = PINJ; buf[345*9+3] = PINA; buf[345*9+4] = PINC; buf[345*9+5] = PIND; buf[345*9+6] = PING; buf[345*9+7] = PINL; buf[345*9+8] = PINB;
buf[346*9+0] = PINE; buf[346*9+1] = PINH; buf[346*9+2] = PINJ; buf[346*9+3] = PINA; buf[346*9+4] = PINC; buf[346*9+5] = PIND; buf[346*9+6] = PING; buf[346*9+7] = PINL; buf[346*9+8] = PINB;
buf[347*9+0] = PINE; buf[347*9+1] = PINH; buf[347*9+2] = PINJ; buf[347*9+3] = PINA; buf[347*9+4] = PINC; buf[347*9+5] = PIND; buf[347*9+6] = PING; buf[347*9+7] = PINL; buf[347*9+8] = PINB;
buf[348*9+0] = PINE; buf[348*9+1] = PINH; buf[348*9+2] = PINJ; buf[348*9+3] = PINA; buf[348*9+4] = PINC; buf[348*9+5] = PIND; buf[348*9+6] = PING; buf[348*9+7] = PINL; buf[348*9+8] = PINB;
buf[349*9+0] = PINE; buf[349*9+1] = PINH; buf[349*9+2] = PINJ; buf[349*9+3] = PINA; buf[349*9+4] = PINC; buf[349*9+5] = PIND; buf[349*9+6] = PING; buf[349*9+7] = PINL; buf[349*9+8] = PINB;
buf[350*9+0] = PINE; buf[350*9+1] = PINH; buf[350*9+2] = PINJ; buf[350*9+3] = PINA; buf[350*9+4] = PINC; buf[350*9+5] = PIND; buf[350*9+6] = PING; buf[350*9+7] = PINL; buf[350*9+8] = PINB;
buf[351*9+0] = PINE; buf[351*9+1] = PINH; buf[351*9+2] = PINJ; buf[351*9+3] = PINA; buf[351*9+4] = PINC; buf[351*9+5] = PIND; buf[351*9+6] = PING; buf[351*9+7] = PINL; buf[351*9+8] = PINB;
buf[352*9+0] = PINE; buf[352*9+1] = PINH; buf[352*9+2] = PINJ; buf[352*9+3] = PINA; buf[352*9+4] = PINC; buf[352*9+5] = PIND; buf[352*9+6] = PING; buf[352*9+7] = PINL; buf[352*9+8] = PINB;
buf[353*9+0] = PINE; buf[353*9+1] = PINH; buf[353*9+2] = PINJ; buf[353*9+3] = PINA; buf[353*9+4] = PINC; buf[353*9+5] = PIND; buf[353*9+6] = PING; buf[353*9+7] = PINL; buf[353*9+8] = PINB;
buf[354*9+0] = PINE; buf[354*9+1] = PINH; buf[354*9+2] = PINJ; buf[354*9+3] = PINA; buf[354*9+4] = PINC; buf[354*9+5] = PIND; buf[354*9+6] = PING; buf[354*9+7] = PINL; buf[354*9+8] = PINB;
buf[355*9+0] = PINE; buf[355*9+1] = PINH; buf[355*9+2] = PINJ; buf[355*9+3] = PINA; buf[355*9+4] = PINC; buf[355*9+5] = PIND; buf[355*9+6] = PING; buf[355*9+7] = PINL; buf[355*9+8] = PINB;
buf[356*9+0] = PINE; buf[356*9+1] = PINH; buf[356*9+2] = PINJ; buf[356*9+3] = PINA; buf[356*9+4] = PINC; buf[356*9+5] = PIND; buf[356*9+6] = PING; buf[356*9+7] = PINL; buf[356*9+8] = PINB;
buf[357*9+0] = PINE; buf[357*9+1] = PINH; buf[357*9+2] = PINJ; buf[357*9+3] = PINA; buf[357*9+4] = PINC; buf[357*9+5] = PIND; buf[357*9+6] = PING; buf[357*9+7] = PINL; buf[357*9+8] = PINB;
buf[358*9+0] = PINE; buf[358*9+1] = PINH; buf[358*9+2] = PINJ; buf[358*9+3] = PINA; buf[358*9+4] = PINC; buf[358*9+5] = PIND; buf[358*9+6] = PING; buf[358*9+7] = PINL; buf[358*9+8] = PINB;
buf[359*9+0] = PINE; buf[359*9+1] = PINH; buf[359*9+2] = PINJ; buf[359*9+3] = PINA; buf[359*9+4] = PINC; buf[359*9+5] = PIND; buf[359*9+6] = PING; buf[359*9+7] = PINL; buf[359*9+8] = PINB;
buf[360*9+0] = PINE; buf[360*9+1] = PINH; buf[360*9+2] = PINJ; buf[360*9+3] = PINA; buf[360*9+4] = PINC; buf[360*9+5] = PIND; buf[360*9+6] = PING; buf[360*9+7] = PINL; buf[360*9+8] = PINB;
buf[361*9+0] = PINE; buf[361*9+1] = PINH; buf[361*9+2] = PINJ; buf[361*9+3] = PINA; buf[361*9+4] = PINC; buf[361*9+5] = PIND; buf[361*9+6] = PING; buf[361*9+7] = PINL; buf[361*9+8] = PINB;
buf[362*9+0] = PINE; buf[362*9+1] = PINH; buf[362*9+2] = PINJ; buf[362*9+3] = PINA; buf[362*9+4] = PINC; buf[362*9+5] = PIND; buf[362*9+6] = PING; buf[362*9+7] = PINL; buf[362*9+8] = PINB;
buf[363*9+0] = PINE; buf[363*9+1] = PINH; buf[363*9+2] = PINJ; buf[363*9+3] = PINA; buf[363*9+4] = PINC; buf[363*9+5] = PIND; buf[363*9+6] = PING; buf[363*9+7] = PINL; buf[363*9+8] = PINB;
buf[364*9+0] = PINE; buf[364*9+1] = PINH; buf[364*9+2] = PINJ; buf[364*9+3] = PINA; buf[364*9+4] = PINC; buf[364*9+5] = PIND; buf[364*9+6] = PING; buf[364*9+7] = PINL; buf[364*9+8] = PINB;
buf[365*9+0] = PINE; buf[365*9+1] = PINH; buf[365*9+2] = PINJ; buf[365*9+3] = PINA; buf[365*9+4] = PINC; buf[365*9+5] = PIND; buf[365*9+6] = PING; buf[365*9+7] = PINL; buf[365*9+8] = PINB;
buf[366*9+0] = PINE; buf[366*9+1] = PINH; buf[366*9+2] = PINJ; buf[366*9+3] = PINA; buf[366*9+4] = PINC; buf[366*9+5] = PIND; buf[366*9+6] = PING; buf[366*9+7] = PINL; buf[366*9+8] = PINB;
buf[367*9+0] = PINE; buf[367*9+1] = PINH; buf[367*9+2] = PINJ; buf[367*9+3] = PINA; buf[367*9+4] = PINC; buf[367*9+5] = PIND; buf[367*9+6] = PING; buf[367*9+7] = PINL; buf[367*9+8] = PINB;
buf[368*9+0] = PINE; buf[368*9+1] = PINH; buf[368*9+2] = PINJ; buf[368*9+3] = PINA; buf[368*9+4] = PINC; buf[368*9+5] = PIND; buf[368*9+6] = PING; buf[368*9+7] = PINL; buf[368*9+8] = PINB;
buf[369*9+0] = PINE; buf[369*9+1] = PINH; buf[369*9+2] = PINJ; buf[369*9+3] = PINA; buf[369*9+4] = PINC; buf[369*9+5] = PIND; buf[369*9+6] = PING; buf[369*9+7] = PINL; buf[369*9+8] = PINB;
buf[370*9+0] = PINE; buf[370*9+1] = PINH; buf[370*9+2] = PINJ; buf[370*9+3] = PINA; buf[370*9+4] = PINC; buf[370*9+5] = PIND; buf[370*9+6] = PING; buf[370*9+7] = PINL; buf[370*9+8] = PINB;
buf[371*9+0] = PINE; buf[371*9+1] = PINH; buf[371*9+2] = PINJ; buf[371*9+3] = PINA; buf[371*9+4] = PINC; buf[371*9+5] = PIND; buf[371*9+6] = PING; buf[371*9+7] = PINL; buf[371*9+8] = PINB;
buf[372*9+0] = PINE; buf[372*9+1] = PINH; buf[372*9+2] = PINJ; buf[372*9+3] = PINA; buf[372*9+4] = PINC; buf[372*9+5] = PIND; buf[372*9+6] = PING; buf[372*9+7] = PINL; buf[372*9+8] = PINB;
buf[373*9+0] = PINE; buf[373*9+1] = PINH; buf[373*9+2] = PINJ; buf[373*9+3] = PINA; buf[373*9+4] = PINC; buf[373*9+5] = PIND; buf[373*9+6] = PING; buf[373*9+7] = PINL; buf[373*9+8] = PINB;
buf[374*9+0] = PINE; buf[374*9+1] = PINH; buf[374*9+2] = PINJ; buf[374*9+3] = PINA; buf[374*9+4] = PINC; buf[374*9+5] = PIND; buf[374*9+6] = PING; buf[374*9+7] = PINL; buf[374*9+8] = PINB;
buf[375*9+0] = PINE; buf[375*9+1] = PINH; buf[375*9+2] = PINJ; buf[375*9+3] = PINA; buf[375*9+4] = PINC; buf[375*9+5] = PIND; buf[375*9+6] = PING; buf[375*9+7] = PINL; buf[375*9+8] = PINB;
buf[376*9+0] = PINE; buf[376*9+1] = PINH; buf[376*9+2] = PINJ; buf[376*9+3] = PINA; buf[376*9+4] = PINC; buf[376*9+5] = PIND; buf[376*9+6] = PING; buf[376*9+7] = PINL; buf[376*9+8] = PINB;
buf[377*9+0] = PINE; buf[377*9+1] = PINH; buf[377*9+2] = PINJ; buf[377*9+3] = PINA; buf[377*9+4] = PINC; buf[377*9+5] = PIND; buf[377*9+6] = PING; buf[377*9+7] = PINL; buf[377*9+8] = PINB;
buf[378*9+0] = PINE; buf[378*9+1] = PINH; buf[378*9+2] = PINJ; buf[378*9+3] = PINA; buf[378*9+4] = PINC; buf[378*9+5] = PIND; buf[378*9+6] = PING; buf[378*9+7] = PINL; buf[378*9+8] = PINB;
buf[379*9+0] = PINE; buf[379*9+1] = PINH; buf[379*9+2] = PINJ; buf[379*9+3] = PINA; buf[379*9+4] = PINC; buf[379*9+5] = PIND; buf[379*9+6] = PING; buf[379*9+7] = PINL; buf[379*9+8] = PINB;
buf[380*9+0] = PINE; buf[380*9+1] = PINH; buf[380*9+2] = PINJ; buf[380*9+3] = PINA; buf[380*9+4] = PINC; buf[380*9+5] = PIND; buf[380*9+6] = PING; buf[380*9+7] = PINL; buf[380*9+8] = PINB;
buf[381*9+0] = PINE; buf[381*9+1] = PINH; buf[381*9+2] = PINJ; buf[381*9+3] = PINA; buf[381*9+4] = PINC; buf[381*9+5] = PIND; buf[381*9+6] = PING; buf[381*9+7] = PINL; buf[381*9+8] = PINB;
buf[382*9+0] = PINE; buf[382*9+1] = PINH; buf[382*9+2] = PINJ; buf[382*9+3] = PINA; buf[382*9+4] = PINC; buf[382*9+5] = PIND; buf[382*9+6] = PING; buf[382*9+7] = PINL; buf[382*9+8] = PINB;
buf[383*9+0] = PINE; buf[383*9+1] = PINH; buf[383*9+2] = PINJ; buf[383*9+3] = PINA; buf[383*9+4] = PINC; buf[383*9+5] = PIND; buf[383*9+6] = PING; buf[383*9+7] = PINL; buf[383*9+8] = PINB;
buf[384*9+0] = PINE; buf[384*9+1] = PINH; buf[384*9+2] = PINJ; buf[384*9+3] = PINA; buf[384*9+4] = PINC; buf[384*9+5] = PIND; buf[384*9+6] = PING; buf[384*9+7] = PINL; buf[384*9+8] = PINB;
buf[385*9+0] = PINE; buf[385*9+1] = PINH; buf[385*9+2] = PINJ; buf[385*9+3] = PINA; buf[385*9+4] = PINC; buf[385*9+5] = PIND; buf[385*9+6] = PING; buf[385*9+7] = PINL; buf[385*9+8] = PINB;
buf[386*9+0] = PINE; buf[386*9+1] = PINH; buf[386*9+2] = PINJ; buf[386*9+3] = PINA; buf[386*9+4] = PINC; buf[386*9+5] = PIND; buf[386*9+6] = PING; buf[386*9+7] = PINL; buf[386*9+8] = PINB;
buf[387*9+0] = PINE; buf[387*9+1] = PINH; buf[387*9+2] = PINJ; buf[387*9+3] = PINA; buf[387*9+4] = PINC; buf[387*9+5] = PIND; buf[387*9+6] = PING; buf[387*9+7] = PINL; buf[387*9+8] = PINB;
buf[388*9+0] = PINE; buf[388*9+1] = PINH; buf[388*9+2] = PINJ; buf[388*9+3] = PINA; buf[388*9+4] = PINC; buf[388*9+5] = PIND; buf[388*9+6] = PING; buf[388*9+7] = PINL; buf[388*9+8] = PINB;
buf[389*9+0] = PINE; buf[389*9+1] = PINH; buf[389*9+2] = PINJ; buf[389*9+3] = PINA; buf[389*9+4] = PINC; buf[389*9+5] = PIND; buf[389*9+6] = PING; buf[389*9+7] = PINL; buf[389*9+8] = PINB;
buf[390*9+0] = PINE; buf[390*9+1] = PINH; buf[390*9+2] = PINJ; buf[390*9+3] = PINA; buf[390*9+4] = PINC; buf[390*9+5] = PIND; buf[390*9+6] = PING; buf[390*9+7] = PINL; buf[390*9+8] = PINB;
buf[391*9+0] = PINE; buf[391*9+1] = PINH; buf[391*9+2] = PINJ; buf[391*9+3] = PINA; buf[391*9+4] = PINC; buf[391*9+5] = PIND; buf[391*9+6] = PING; buf[391*9+7] = PINL; buf[391*9+8] = PINB;
buf[392*9+0] = PINE; buf[392*9+1] = PINH; buf[392*9+2] = PINJ; buf[392*9+3] = PINA; buf[392*9+4] = PINC; buf[392*9+5] = PIND; buf[392*9+6] = PING; buf[392*9+7] = PINL; buf[392*9+8] = PINB;
buf[393*9+0] = PINE; buf[393*9+1] = PINH; buf[393*9+2] = PINJ; buf[393*9+3] = PINA; buf[393*9+4] = PINC; buf[393*9+5] = PIND; buf[393*9+6] = PING; buf[393*9+7] = PINL; buf[393*9+8] = PINB;
buf[394*9+0] = PINE; buf[394*9+1] = PINH; buf[394*9+2] = PINJ; buf[394*9+3] = PINA; buf[394*9+4] = PINC; buf[394*9+5] = PIND; buf[394*9+6] = PING; buf[394*9+7] = PINL; buf[394*9+8] = PINB;
buf[395*9+0] = PINE; buf[395*9+1] = PINH; buf[395*9+2] = PINJ; buf[395*9+3] = PINA; buf[395*9+4] = PINC; buf[395*9+5] = PIND; buf[395*9+6] = PING; buf[395*9+7] = PINL; buf[395*9+8] = PINB;
buf[396*9+0] = PINE; buf[396*9+1] = PINH; buf[396*9+2] = PINJ; buf[396*9+3] = PINA; buf[396*9+4] = PINC; buf[396*9+5] = PIND; buf[396*9+6] = PING; buf[396*9+7] = PINL; buf[396*9+8] = PINB;
buf[397*9+0] = PINE; buf[397*9+1] = PINH; buf[397*9+2] = PINJ; buf[397*9+3] = PINA; buf[397*9+4] = PINC; buf[397*9+5] = PIND; buf[397*9+6] = PING; buf[397*9+7] = PINL; buf[397*9+8] = PINB;
buf[398*9+0] = PINE; buf[398*9+1] = PINH; buf[398*9+2] = PINJ; buf[398*9+3] = PINA; buf[398*9+4] = PINC; buf[398*9+5] = PIND; buf[398*9+6] = PING; buf[398*9+7] = PINL; buf[398*9+8] = PINB;
buf[399*9+0] = PINE; buf[399*9+1] = PINH; buf[399*9+2] = PINJ; buf[399*9+3] = PINA; buf[399*9+4] = PINC; buf[399*9+5] = PIND; buf[399*9+6] = PING; buf[399*9+7] = PINL; buf[399*9+8] = PINB;
buf[400*9+0] = PINE; buf[400*9+1] = PINH; buf[400*9+2] = PINJ; buf[400*9+3] = PINA; buf[400*9+4] = PINC; buf[400*9+5] = PIND; buf[400*9+6] = PING; buf[400*9+7] = PINL; buf[400*9+8] = PINB;
buf[401*9+0] = PINE; buf[401*9+1] = PINH; buf[401*9+2] = PINJ; buf[401*9+3] = PINA; buf[401*9+4] = PINC; buf[401*9+5] = PIND; buf[401*9+6] = PING; buf[401*9+7] = PINL; buf[401*9+8] = PINB;
buf[402*9+0] = PINE; buf[402*9+1] = PINH; buf[402*9+2] = PINJ; buf[402*9+3] = PINA; buf[402*9+4] = PINC; buf[402*9+5] = PIND; buf[402*9+6] = PING; buf[402*9+7] = PINL; buf[402*9+8] = PINB;
buf[403*9+0] = PINE; buf[403*9+1] = PINH; buf[403*9+2] = PINJ; buf[403*9+3] = PINA; buf[403*9+4] = PINC; buf[403*9+5] = PIND; buf[403*9+6] = PING; buf[403*9+7] = PINL; buf[403*9+8] = PINB;
buf[404*9+0] = PINE; buf[404*9+1] = PINH; buf[404*9+2] = PINJ; buf[404*9+3] = PINA; buf[404*9+4] = PINC; buf[404*9+5] = PIND; buf[404*9+6] = PING; buf[404*9+7] = PINL; buf[404*9+8] = PINB;
buf[405*9+0] = PINE; buf[405*9+1] = PINH; buf[405*9+2] = PINJ; buf[405*9+3] = PINA; buf[405*9+4] = PINC; buf[405*9+5] = PIND; buf[405*9+6] = PING; buf[405*9+7] = PINL; buf[405*9+8] = PINB;
buf[406*9+0] = PINE; buf[406*9+1] = PINH; buf[406*9+2] = PINJ; buf[406*9+3] = PINA; buf[406*9+4] = PINC; buf[406*9+5] = PIND; buf[406*9+6] = PING; buf[406*9+7] = PINL; buf[406*9+8] = PINB;
buf[407*9+0] = PINE; buf[407*9+1] = PINH; buf[407*9+2] = PINJ; buf[407*9+3] = PINA; buf[407*9+4] = PINC; buf[407*9+5] = PIND; buf[407*9+6] = PING; buf[407*9+7] = PINL; buf[407*9+8] = PINB;
buf[408*9+0] = PINE; buf[408*9+1] = PINH; buf[408*9+2] = PINJ; buf[408*9+3] = PINA; buf[408*9+4] = PINC; buf[408*9+5] = PIND; buf[408*9+6] = PING; buf[408*9+7] = PINL; buf[408*9+8] = PINB;
buf[409*9+0] = PINE; buf[409*9+1] = PINH; buf[409*9+2] = PINJ; buf[409*9+3] = PINA; buf[409*9+4] = PINC; buf[409*9+5] = PIND; buf[409*9+6] = PING; buf[409*9+7] = PINL; buf[409*9+8] = PINB;
buf[410*9+0] = PINE; buf[410*9+1] = PINH; buf[410*9+2] = PINJ; buf[410*9+3] = PINA; buf[410*9+4] = PINC; buf[410*9+5] = PIND; buf[410*9+6] = PING; buf[410*9+7] = PINL; buf[410*9+8] = PINB;
buf[411*9+0] = PINE; buf[411*9+1] = PINH; buf[411*9+2] = PINJ; buf[411*9+3] = PINA; buf[411*9+4] = PINC; buf[411*9+5] = PIND; buf[411*9+6] = PING; buf[411*9+7] = PINL; buf[411*9+8] = PINB;
buf[412*9+0] = PINE; buf[412*9+1] = PINH; buf[412*9+2] = PINJ; buf[412*9+3] = PINA; buf[412*9+4] = PINC; buf[412*9+5] = PIND; buf[412*9+6] = PING; buf[412*9+7] = PINL; buf[412*9+8] = PINB;
buf[413*9+0] = PINE; buf[413*9+1] = PINH; buf[413*9+2] = PINJ; buf[413*9+3] = PINA; buf[413*9+4] = PINC; buf[413*9+5] = PIND; buf[413*9+6] = PING; buf[413*9+7] = PINL; buf[413*9+8] = PINB;
buf[414*9+0] = PINE; buf[414*9+1] = PINH; buf[414*9+2] = PINJ; buf[414*9+3] = PINA; buf[414*9+4] = PINC; buf[414*9+5] = PIND; buf[414*9+6] = PING; buf[414*9+7] = PINL; buf[414*9+8] = PINB;
buf[415*9+0] = PINE; buf[415*9+1] = PINH; buf[415*9+2] = PINJ; buf[415*9+3] = PINA; buf[415*9+4] = PINC; buf[415*9+5] = PIND; buf[415*9+6] = PING; buf[415*9+7] = PINL; buf[415*9+8] = PINB;
buf[416*9+0] = PINE; buf[416*9+1] = PINH; buf[416*9+2] = PINJ; buf[416*9+3] = PINA; buf[416*9+4] = PINC; buf[416*9+5] = PIND; buf[416*9+6] = PING; buf[416*9+7] = PINL; buf[416*9+8] = PINB;
buf[417*9+0] = PINE; buf[417*9+1] = PINH; buf[417*9+2] = PINJ; buf[417*9+3] = PINA; buf[417*9+4] = PINC; buf[417*9+5] = PIND; buf[417*9+6] = PING; buf[417*9+7] = PINL; buf[417*9+8] = PINB;
buf[418*9+0] = PINE; buf[418*9+1] = PINH; buf[418*9+2] = PINJ; buf[418*9+3] = PINA; buf[418*9+4] = PINC; buf[418*9+5] = PIND; buf[418*9+6] = PING; buf[418*9+7] = PINL; buf[418*9+8] = PINB;
buf[419*9+0] = PINE; buf[419*9+1] = PINH; buf[419*9+2] = PINJ; buf[419*9+3] = PINA; buf[419*9+4] = PINC; buf[419*9+5] = PIND; buf[419*9+6] = PING; buf[419*9+7] = PINL; buf[419*9+8] = PINB;
buf[420*9+0] = PINE; buf[420*9+1] = PINH; buf[420*9+2] = PINJ; buf[420*9+3] = PINA; buf[420*9+4] = PINC; buf[420*9+5] = PIND; buf[420*9+6] = PING; buf[420*9+7] = PINL; buf[420*9+8] = PINB;
buf[421*9+0] = PINE; buf[421*9+1] = PINH; buf[421*9+2] = PINJ; buf[421*9+3] = PINA; buf[421*9+4] = PINC; buf[421*9+5] = PIND; buf[421*9+6] = PING; buf[421*9+7] = PINL; buf[421*9+8] = PINB;
buf[422*9+0] = PINE; buf[422*9+1] = PINH; buf[422*9+2] = PINJ; buf[422*9+3] = PINA; buf[422*9+4] = PINC; buf[422*9+5] = PIND; buf[422*9+6] = PING; buf[422*9+7] = PINL; buf[422*9+8] = PINB;
buf[423*9+0] = PINE; buf[423*9+1] = PINH; buf[423*9+2] = PINJ; buf[423*9+3] = PINA; buf[423*9+4] = PINC; buf[423*9+5] = PIND; buf[423*9+6] = PING; buf[423*9+7] = PINL; buf[423*9+8] = PINB;
buf[424*9+0] = PINE; buf[424*9+1] = PINH; buf[424*9+2] = PINJ; buf[424*9+3] = PINA; buf[424*9+4] = PINC; buf[424*9+5] = PIND; buf[424*9+6] = PING; buf[424*9+7] = PINL; buf[424*9+8] = PINB;
buf[425*9+0] = PINE; buf[425*9+1] = PINH; buf[425*9+2] = PINJ; buf[425*9+3] = PINA; buf[425*9+4] = PINC; buf[425*9+5] = PIND; buf[425*9+6] = PING; buf[425*9+7] = PINL; buf[425*9+8] = PINB;
buf[426*9+0] = PINE; buf[426*9+1] = PINH; buf[426*9+2] = PINJ; buf[426*9+3] = PINA; buf[426*9+4] = PINC; buf[426*9+5] = PIND; buf[426*9+6] = PING; buf[426*9+7] = PINL; buf[426*9+8] = PINB;
buf[427*9+0] = PINE; buf[427*9+1] = PINH; buf[427*9+2] = PINJ; buf[427*9+3] = PINA; buf[427*9+4] = PINC; buf[427*9+5] = PIND; buf[427*9+6] = PING; buf[427*9+7] = PINL; buf[427*9+8] = PINB;
buf[428*9+0] = PINE; buf[428*9+1] = PINH; buf[428*9+2] = PINJ; buf[428*9+3] = PINA; buf[428*9+4] = PINC; buf[428*9+5] = PIND; buf[428*9+6] = PING; buf[428*9+7] = PINL; buf[428*9+8] = PINB;
buf[429*9+0] = PINE; buf[429*9+1] = PINH; buf[429*9+2] = PINJ; buf[429*9+3] = PINA; buf[429*9+4] = PINC; buf[429*9+5] = PIND; buf[429*9+6] = PING; buf[429*9+7] = PINL; buf[429*9+8] = PINB;
buf[430*9+0] = PINE; buf[430*9+1] = PINH; buf[430*9+2] = PINJ; buf[430*9+3] = PINA; buf[430*9+4] = PINC; buf[430*9+5] = PIND; buf[430*9+6] = PING; buf[430*9+7] = PINL; buf[430*9+8] = PINB;
buf[431*9+0] = PINE; buf[431*9+1] = PINH; buf[431*9+2] = PINJ; buf[431*9+3] = PINA; buf[431*9+4] = PINC; buf[431*9+5] = PIND; buf[431*9+6] = PING; buf[431*9+7] = PINL; buf[431*9+8] = PINB;
buf[432*9+0] = PINE; buf[432*9+1] = PINH; buf[432*9+2] = PINJ; buf[432*9+3] = PINA; buf[432*9+4] = PINC; buf[432*9+5] = PIND; buf[432*9+6] = PING; buf[432*9+7] = PINL; buf[432*9+8] = PINB;
buf[433*9+0] = PINE; buf[433*9+1] = PINH; buf[433*9+2] = PINJ; buf[433*9+3] = PINA; buf[433*9+4] = PINC; buf[433*9+5] = PIND; buf[433*9+6] = PING; buf[433*9+7] = PINL; buf[433*9+8] = PINB;
buf[434*9+0] = PINE; buf[434*9+1] = PINH; buf[434*9+2] = PINJ; buf[434*9+3] = PINA; buf[434*9+4] = PINC; buf[434*9+5] = PIND; buf[434*9+6] = PING; buf[434*9+7] = PINL; buf[434*9+8] = PINB;
buf[435*9+0] = PINE; buf[435*9+1] = PINH; buf[435*9+2] = PINJ; buf[435*9+3] = PINA; buf[435*9+4] = PINC; buf[435*9+5] = PIND; buf[435*9+6] = PING; buf[435*9+7] = PINL; buf[435*9+8] = PINB;
buf[436*9+0] = PINE; buf[436*9+1] = PINH; buf[436*9+2] = PINJ; buf[436*9+3] = PINA; buf[436*9+4] = PINC; buf[436*9+5] = PIND; buf[436*9+6] = PING; buf[436*9+7] = PINL; buf[436*9+8] = PINB;
buf[437*9+0] = PINE; buf[437*9+1] = PINH; buf[437*9+2] = PINJ; buf[437*9+3] = PINA; buf[437*9+4] = PINC; buf[437*9+5] = PIND; buf[437*9+6] = PING; buf[437*9+7] = PINL; buf[437*9+8] = PINB;
buf[438*9+0] = PINE; buf[438*9+1] = PINH; buf[438*9+2] = PINJ; buf[438*9+3] = PINA; buf[438*9+4] = PINC; buf[438*9+5] = PIND; buf[438*9+6] = PING; buf[438*9+7] = PINL; buf[438*9+8] = PINB;
buf[439*9+0] = PINE; buf[439*9+1] = PINH; buf[439*9+2] = PINJ; buf[439*9+3] = PINA; buf[439*9+4] = PINC; buf[439*9+5] = PIND; buf[439*9+6] = PING; buf[439*9+7] = PINL; buf[439*9+8] = PINB;
buf[440*9+0] = PINE; buf[440*9+1] = PINH; buf[440*9+2] = PINJ; buf[440*9+3] = PINA; buf[440*9+4] = PINC; buf[440*9+5] = PIND; buf[440*9+6] = PING; buf[440*9+7] = PINL; buf[440*9+8] = PINB;
buf[441*9+0] = PINE; buf[441*9+1] = PINH; buf[441*9+2] = PINJ; buf[441*9+3] = PINA; buf[441*9+4] = PINC; buf[441*9+5] = PIND; buf[441*9+6] = PING; buf[441*9+7] = PINL; buf[441*9+8] = PINB;
buf[442*9+0] = PINE; buf[442*9+1] = PINH; buf[442*9+2] = PINJ; buf[442*9+3] = PINA; buf[442*9+4] = PINC; buf[442*9+5] = PIND; buf[442*9+6] = PING; buf[442*9+7] = PINL; buf[442*9+8] = PINB;
buf[443*9+0] = PINE; buf[443*9+1] = PINH; buf[443*9+2] = PINJ; buf[443*9+3] = PINA; buf[443*9+4] = PINC; buf[443*9+5] = PIND; buf[443*9+6] = PING; buf[443*9+7] = PINL; buf[443*9+8] = PINB;
buf[444*9+0] = PINE; buf[444*9+1] = PINH; buf[444*9+2] = PINJ; buf[444*9+3] = PINA; buf[444*9+4] = PINC; buf[444*9+5] = PIND; buf[444*9+6] = PING; buf[444*9+7] = PINL; buf[444*9+8] = PINB;
buf[445*9+0] = PINE; buf[445*9+1] = PINH; buf[445*9+2] = PINJ; buf[445*9+3] = PINA; buf[445*9+4] = PINC; buf[445*9+5] = PIND; buf[445*9+6] = PING; buf[445*9+7] = PINL; buf[445*9+8] = PINB;
buf[446*9+0] = PINE; buf[446*9+1] = PINH; buf[446*9+2] = PINJ; buf[446*9+3] = PINA; buf[446*9+4] = PINC; buf[446*9+5] = PIND; buf[446*9+6] = PING; buf[446*9+7] = PINL; buf[446*9+8] = PINB;
buf[447*9+0] = PINE; buf[447*9+1] = PINH; buf[447*9+2] = PINJ; buf[447*9+3] = PINA; buf[447*9+4] = PINC; buf[447*9+5] = PIND; buf[447*9+6] = PING; buf[447*9+7] = PINL; buf[447*9+8] = PINB;
buf[448*9+0] = PINE; buf[448*9+1] = PINH; buf[448*9+2] = PINJ; buf[448*9+3] = PINA; buf[448*9+4] = PINC; buf[448*9+5] = PIND; buf[448*9+6] = PING; buf[448*9+7] = PINL; buf[448*9+8] = PINB;
buf[449*9+0] = PINE; buf[449*9+1] = PINH; buf[449*9+2] = PINJ; buf[449*9+3] = PINA; buf[449*9+4] = PINC; buf[449*9+5] = PIND; buf[449*9+6] = PING; buf[449*9+7] = PINL; buf[449*9+8] = PINB;
buf[450*9+0] = PINE; buf[450*9+1] = PINH; buf[450*9+2] = PINJ; buf[450*9+3] = PINA; buf[450*9+4] = PINC; buf[450*9+5] = PIND; buf[450*9+6] = PING; buf[450*9+7] = PINL; buf[450*9+8] = PINB;
buf[451*9+0] = PINE; buf[451*9+1] = PINH; buf[451*9+2] = PINJ; buf[451*9+3] = PINA; buf[451*9+4] = PINC; buf[451*9+5] = PIND; buf[451*9+6] = PING; buf[451*9+7] = PINL; buf[451*9+8] = PINB;
buf[452*9+0] = PINE; buf[452*9+1] = PINH; buf[452*9+2] = PINJ; buf[452*9+3] = PINA; buf[452*9+4] = PINC; buf[452*9+5] = PIND; buf[452*9+6] = PING; buf[452*9+7] = PINL; buf[452*9+8] = PINB;
buf[453*9+0] = PINE; buf[453*9+1] = PINH; buf[453*9+2] = PINJ; buf[453*9+3] = PINA; buf[453*9+4] = PINC; buf[453*9+5] = PIND; buf[453*9+6] = PING; buf[453*9+7] = PINL; buf[453*9+8] = PINB;
buf[454*9+0] = PINE; buf[454*9+1] = PINH; buf[454*9+2] = PINJ; buf[454*9+3] = PINA; buf[454*9+4] = PINC; buf[454*9+5] = PIND; buf[454*9+6] = PING; buf[454*9+7] = PINL; buf[454*9+8] = PINB;
buf[455*9+0] = PINE; buf[455*9+1] = PINH; buf[455*9+2] = PINJ; buf[455*9+3] = PINA; buf[455*9+4] = PINC; buf[455*9+5] = PIND; buf[455*9+6] = PING; buf[455*9+7] = PINL; buf[455*9+8] = PINB;
buf[456*9+0] = PINE; buf[456*9+1] = PINH; buf[456*9+2] = PINJ; buf[456*9+3] = PINA; buf[456*9+4] = PINC; buf[456*9+5] = PIND; buf[456*9+6] = PING; buf[456*9+7] = PINL; buf[456*9+8] = PINB;
buf[457*9+0] = PINE; buf[457*9+1] = PINH; buf[457*9+2] = PINJ; buf[457*9+3] = PINA; buf[457*9+4] = PINC; buf[457*9+5] = PIND; buf[457*9+6] = PING; buf[457*9+7] = PINL; buf[457*9+8] = PINB;
buf[458*9+0] = PINE; buf[458*9+1] = PINH; buf[458*9+2] = PINJ; buf[458*9+3] = PINA; buf[458*9+4] = PINC; buf[458*9+5] = PIND; buf[458*9+6] = PING; buf[458*9+7] = PINL; buf[458*9+8] = PINB;
buf[459*9+0] = PINE; buf[459*9+1] = PINH; buf[459*9+2] = PINJ; buf[459*9+3] = PINA; buf[459*9+4] = PINC; buf[459*9+5] = PIND; buf[459*9+6] = PING; buf[459*9+7] = PINL; buf[459*9+8] = PINB;
buf[460*9+0] = PINE; buf[460*9+1] = PINH; buf[460*9+2] = PINJ; buf[460*9+3] = PINA; buf[460*9+4] = PINC; buf[460*9+5] = PIND; buf[460*9+6] = PING; buf[460*9+7] = PINL; buf[460*9+8] = PINB;
buf[461*9+0] = PINE; buf[461*9+1] = PINH; buf[461*9+2] = PINJ; buf[461*9+3] = PINA; buf[461*9+4] = PINC; buf[461*9+5] = PIND; buf[461*9+6] = PING; buf[461*9+7] = PINL; buf[461*9+8] = PINB;
buf[462*9+0] = PINE; buf[462*9+1] = PINH; buf[462*9+2] = PINJ; buf[462*9+3] = PINA; buf[462*9+4] = PINC; buf[462*9+5] = PIND; buf[462*9+6] = PING; buf[462*9+7] = PINL; buf[462*9+8] = PINB;
buf[463*9+0] = PINE; buf[463*9+1] = PINH; buf[463*9+2] = PINJ; buf[463*9+3] = PINA; buf[463*9+4] = PINC; buf[463*9+5] = PIND; buf[463*9+6] = PING; buf[463*9+7] = PINL; buf[463*9+8] = PINB;
buf[464*9+0] = PINE; buf[464*9+1] = PINH; buf[464*9+2] = PINJ; buf[464*9+3] = PINA; buf[464*9+4] = PINC; buf[464*9+5] = PIND; buf[464*9+6] = PING; buf[464*9+7] = PINL; buf[464*9+8] = PINB;
buf[465*9+0] = PINE; buf[465*9+1] = PINH; buf[465*9+2] = PINJ; buf[465*9+3] = PINA; buf[465*9+4] = PINC; buf[465*9+5] = PIND; buf[465*9+6] = PING; buf[465*9+7] = PINL; buf[465*9+8] = PINB;
buf[466*9+0] = PINE; buf[466*9+1] = PINH; buf[466*9+2] = PINJ; buf[466*9+3] = PINA; buf[466*9+4] = PINC; buf[466*9+5] = PIND; buf[466*9+6] = PING; buf[466*9+7] = PINL; buf[466*9+8] = PINB;
buf[467*9+0] = PINE; buf[467*9+1] = PINH; buf[467*9+2] = PINJ; buf[467*9+3] = PINA; buf[467*9+4] = PINC; buf[467*9+5] = PIND; buf[467*9+6] = PING; buf[467*9+7] = PINL; buf[467*9+8] = PINB;
buf[468*9+0] = PINE; buf[468*9+1] = PINH; buf[468*9+2] = PINJ; buf[468*9+3] = PINA; buf[468*9+4] = PINC; buf[468*9+5] = PIND; buf[468*9+6] = PING; buf[468*9+7] = PINL; buf[468*9+8] = PINB;
buf[469*9+0] = PINE; buf[469*9+1] = PINH; buf[469*9+2] = PINJ; buf[469*9+3] = PINA; buf[469*9+4] = PINC; buf[469*9+5] = PIND; buf[469*9+6] = PING; buf[469*9+7] = PINL; buf[469*9+8] = PINB;
buf[470*9+0] = PINE; buf[470*9+1] = PINH; buf[470*9+2] = PINJ; buf[470*9+3] = PINA; buf[470*9+4] = PINC; buf[470*9+5] = PIND; buf[470*9+6] = PING; buf[470*9+7] = PINL; buf[470*9+8] = PINB;
buf[471*9+0] = PINE; buf[471*9+1] = PINH; buf[471*9+2] = PINJ; buf[471*9+3] = PINA; buf[471*9+4] = PINC; buf[471*9+5] = PIND; buf[471*9+6] = PING; buf[471*9+7] = PINL; buf[471*9+8] = PINB;
buf[472*9+0] = PINE; buf[472*9+1] = PINH; buf[472*9+2] = PINJ; buf[472*9+3] = PINA; buf[472*9+4] = PINC; buf[472*9+5] = PIND; buf[472*9+6] = PING; buf[472*9+7] = PINL; buf[472*9+8] = PINB;
buf[473*9+0] = PINE; buf[473*9+1] = PINH; buf[473*9+2] = PINJ; buf[473*9+3] = PINA; buf[473*9+4] = PINC; buf[473*9+5] = PIND; buf[473*9+6] = PING; buf[473*9+7] = PINL; buf[473*9+8] = PINB;
buf[474*9+0] = PINE; buf[474*9+1] = PINH; buf[474*9+2] = PINJ; buf[474*9+3] = PINA; buf[474*9+4] = PINC; buf[474*9+5] = PIND; buf[474*9+6] = PING; buf[474*9+7] = PINL; buf[474*9+8] = PINB;
buf[475*9+0] = PINE; buf[475*9+1] = PINH; buf[475*9+2] = PINJ; buf[475*9+3] = PINA; buf[475*9+4] = PINC; buf[475*9+5] = PIND; buf[475*9+6] = PING; buf[475*9+7] = PINL; buf[475*9+8] = PINB;
buf[476*9+0] = PINE; buf[476*9+1] = PINH; buf[476*9+2] = PINJ; buf[476*9+3] = PINA; buf[476*9+4] = PINC; buf[476*9+5] = PIND; buf[476*9+6] = PING; buf[476*9+7] = PINL; buf[476*9+8] = PINB;
buf[477*9+0] = PINE; buf[477*9+1] = PINH; buf[477*9+2] = PINJ; buf[477*9+3] = PINA; buf[477*9+4] = PINC; buf[477*9+5] = PIND; buf[477*9+6] = PING; buf[477*9+7] = PINL; buf[477*9+8] = PINB;
buf[478*9+0] = PINE; buf[478*9+1] = PINH; buf[478*9+2] = PINJ; buf[478*9+3] = PINA; buf[478*9+4] = PINC; buf[478*9+5] = PIND; buf[478*9+6] = PING; buf[478*9+7] = PINL; buf[478*9+8] = PINB;
buf[479*9+0] = PINE; buf[479*9+1] = PINH; buf[479*9+2] = PINJ; buf[479*9+3] = PINA; buf[479*9+4] = PINC; buf[479*9+5] = PIND; buf[479*9+6] = PING; buf[479*9+7] = PINL; buf[479*9+8] = PINB;
buf[480*9+0] = PINE; buf[480*9+1] = PINH; buf[480*9+2] = PINJ; buf[480*9+3] = PINA; buf[480*9+4] = PINC; buf[480*9+5] = PIND; buf[480*9+6] = PING; buf[480*9+7] = PINL; buf[480*9+8] = PINB;
buf[481*9+0] = PINE; buf[481*9+1] = PINH; buf[481*9+2] = PINJ; buf[481*9+3] = PINA; buf[481*9+4] = PINC; buf[481*9+5] = PIND; buf[481*9+6] = PING; buf[481*9+7] = PINL; buf[481*9+8] = PINB;
buf[482*9+0] = PINE; buf[482*9+1] = PINH; buf[482*9+2] = PINJ; buf[482*9+3] = PINA; buf[482*9+4] = PINC; buf[482*9+5] = PIND; buf[482*9+6] = PING; buf[482*9+7] = PINL; buf[482*9+8] = PINB;
buf[483*9+0] = PINE; buf[483*9+1] = PINH; buf[483*9+2] = PINJ; buf[483*9+3] = PINA; buf[483*9+4] = PINC; buf[483*9+5] = PIND; buf[483*9+6] = PING; buf[483*9+7] = PINL; buf[483*9+8] = PINB;
buf[484*9+0] = PINE; buf[484*9+1] = PINH; buf[484*9+2] = PINJ; buf[484*9+3] = PINA; buf[484*9+4] = PINC; buf[484*9+5] = PIND; buf[484*9+6] = PING; buf[484*9+7] = PINL; buf[484*9+8] = PINB;
buf[485*9+0] = PINE; buf[485*9+1] = PINH; buf[485*9+2] = PINJ; buf[485*9+3] = PINA; buf[485*9+4] = PINC; buf[485*9+5] = PIND; buf[485*9+6] = PING; buf[485*9+7] = PINL; buf[485*9+8] = PINB;
buf[486*9+0] = PINE; buf[486*9+1] = PINH; buf[486*9+2] = PINJ; buf[486*9+3] = PINA; buf[486*9+4] = PINC; buf[486*9+5] = PIND; buf[486*9+6] = PING; buf[486*9+7] = PINL; buf[486*9+8] = PINB;
buf[487*9+0] = PINE; buf[487*9+1] = PINH; buf[487*9+2] = PINJ; buf[487*9+3] = PINA; buf[487*9+4] = PINC; buf[487*9+5] = PIND; buf[487*9+6] = PING; buf[487*9+7] = PINL; buf[487*9+8] = PINB;
buf[488*9+0] = PINE; buf[488*9+1] = PINH; buf[488*9+2] = PINJ; buf[488*9+3] = PINA; buf[488*9+4] = PINC; buf[488*9+5] = PIND; buf[488*9+6] = PING; buf[488*9+7] = PINL; buf[488*9+8] = PINB;
buf[489*9+0] = PINE; buf[489*9+1] = PINH; buf[489*9+2] = PINJ; buf[489*9+3] = PINA; buf[489*9+4] = PINC; buf[489*9+5] = PIND; buf[489*9+6] = PING; buf[489*9+7] = PINL; buf[489*9+8] = PINB;
buf[490*9+0] = PINE; buf[490*9+1] = PINH; buf[490*9+2] = PINJ; buf[490*9+3] = PINA; buf[490*9+4] = PINC; buf[490*9+5] = PIND; buf[490*9+6] = PING; buf[490*9+7] = PINL; buf[490*9+8] = PINB;
buf[491*9+0] = PINE; buf[491*9+1] = PINH; buf[491*9+2] = PINJ; buf[491*9+3] = PINA; buf[491*9+4] = PINC; buf[491*9+5] = PIND; buf[491*9+6] = PING; buf[491*9+7] = PINL; buf[491*9+8] = PINB;
buf[492*9+0] = PINE; buf[492*9+1] = PINH; buf[492*9+2] = PINJ; buf[492*9+3] = PINA; buf[492*9+4] = PINC; buf[492*9+5] = PIND; buf[492*9+6] = PING; buf[492*9+7] = PINL; buf[492*9+8] = PINB;
buf[493*9+0] = PINE; buf[493*9+1] = PINH; buf[493*9+2] = PINJ; buf[493*9+3] = PINA; buf[493*9+4] = PINC; buf[493*9+5] = PIND; buf[493*9+6] = PING; buf[493*9+7] = PINL; buf[493*9+8] = PINB;
buf[494*9+0] = PINE; buf[494*9+1] = PINH; buf[494*9+2] = PINJ; buf[494*9+3] = PINA; buf[494*9+4] = PINC; buf[494*9+5] = PIND; buf[494*9+6] = PING; buf[494*9+7] = PINL; buf[494*9+8] = PINB;
buf[495*9+0] = PINE; buf[495*9+1] = PINH; buf[495*9+2] = PINJ; buf[495*9+3] = PINA; buf[495*9+4] = PINC; buf[495*9+5] = PIND; buf[495*9+6] = PING; buf[495*9+7] = PINL; buf[495*9+8] = PINB;
buf[496*9+0] = PINE; buf[496*9+1] = PINH; buf[496*9+2] = PINJ; buf[496*9+3] = PINA; buf[496*9+4] = PINC; buf[496*9+5] = PIND; buf[496*9+6] = PING; buf[496*9+7] = PINL; buf[496*9+8] = PINB;
buf[497*9+0] = PINE; buf[497*9+1] = PINH; buf[497*9+2] = PINJ; buf[497*9+3] = PINA; buf[497*9+4] = PINC; buf[497*9+5] = PIND; buf[497*9+6] = PING; buf[497*9+7] = PINL; buf[497*9+8] = PINB;
buf[498*9+0] = PINE; buf[498*9+1] = PINH; buf[498*9+2] = PINJ; buf[498*9+3] = PINA; buf[498*9+4] = PINC; buf[498*9+5] = PIND; buf[498*9+6] = PING; buf[498*9+7] = PINL; buf[498*9+8] = PINB;
buf[499*9+0] = PINE; buf[499*9+1] = PINH; buf[499*9+2] = PINJ; buf[499*9+3] = PINA; buf[499*9+4] = PINC; buf[499*9+5] = PIND; buf[499*9+6] = PING; buf[499*9+7] = PINL; buf[499*9+8] = PINB;

  // 2
  PORTE = B00010000;
  
  // count the highs before low
  for (i = 0; i < 9*8; i++) {
    counts[i] = 0;
  }
  for (i = 1; i < SAMPLES; i++) {
    for (k = 0; k < 9; k++) {
      
    delta = buf[i*9+k] ^ buf[(i-1)*9+k];
    if (delta & 1<<0) {
      counts[k*8+0] = i;
    }
    if (delta & 1<<1) {
      counts[k*8+1] = i;
    }
    if (delta & 1<<2) {
      counts[k*8+2] = i;
    }
    if (delta & 1<<3) {
      counts[k*8+3] = i;
    }
    if (delta & 1<<4) {
      counts[k*8+4] = i;
    }
    if (delta & 1<<5) {
      counts[k*8+5] = i;
    }
    if (delta & 1<<6) {
      counts[k*8+6] = i;
    }
    if (delta & 1<<7) {
      counts[k*8+7] = i;
    }
    
    }
  }
  
  // Write serial while waiting for capacitor to charge
  Serial.write(0xFF);
  Serial.write(counts, 9*8);

}

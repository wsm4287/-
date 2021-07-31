#ifndef SFP_H
#define SFP_H

#define BTBP "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define BTB(byte) (byte & 0x8000 ? '1' : '0'), (byte & 0x4000 ? '1' : '0'), \
(byte & 0x2000 ? '1' : '0'), (byte & 0x1000 ? '1' : '0'), \
(byte & 0x0800 ? '1' : '0'), (byte & 0x0400 ? '1' : '0'), \
(byte & 0x0200 ? '1' : '0'), (byte & 0x0100 ? '1' : '0'), \
(byte & 0x0080 ? '1' : '0'), (byte & 0x0040 ? '1' : '0'), \
(byte & 0x0020 ? '1' : '0'), (byte & 0x0010 ? '1' : '0'), \
(byte & 0x0008 ? '1' : '0'), (byte & 0x0004 ? '1' : '0'), \
(byte & 0x0002 ? '1' : '0'), (byte & 0x0001 ? '1' : '0')

typedef unsigned short sfp;

sfp int2sfp(int input);
int sfp2int(sfp input);
sfp float2sfp(float input);
float sfp2float(sfp input);

sfp sfp_add(sfp a, sfp b);
sfp sfp_mul(sfp a, sfp b);

#endif

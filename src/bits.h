/*
 * bits.h
 *
 *  Created on: 25 de jun. de 2025
 *      Author: Fernando
 */

#ifndef BITS_H_
#define BITS_H_

#define bitSet(arg, bit) ((arg) |=  (1 << (bit)))
#define bitClr(arg, bit) ((arg) &= ~(1 << (bit)))
#define bitTgl(arg, bit) ((arg) ^=  (1 << (bit)))
#define bitTst(arg, bit) ((arg) &   (1 << (bit)))

#endif /* BITS_H_ */

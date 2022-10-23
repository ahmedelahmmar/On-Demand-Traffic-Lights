#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

#define SET_BIT(BIT, REG) 		(REG |= (1 << BIT))
#define CLEAR_BIT(BIT, REG) 	(REG &= ~(1 << BIT))
#define TOGGLE_BIT(BIT, REG) 	(REG ^= (1 << BIT))
#define CHECK_BIT(BIT, REG) 	((REG >> BIT) & 1)

#endif // BIT_MATH_H_INCLUDED

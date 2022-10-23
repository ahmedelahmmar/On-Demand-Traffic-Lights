#include "../Utilities/StandardFunctions.h"

f32 MAP(f32 InputValue, f32 fromMin, f32 fromMax, f32 toMin, f32 toMax)
{
	 return ((((InputValue - fromMin)*(toMax - toMin))/(fromMax - fromMin)) + toMin);
}

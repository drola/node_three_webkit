#ifndef MATH_H
#define MATH_H
namespace math {
inline double clamp(double val, double min, double max);

inline double clamp(double value, double min, double max) {
	if(value < min) {
		return min;
	} else if(value > max) {
		return max;
	}
	
	return value;
}
}
#endif
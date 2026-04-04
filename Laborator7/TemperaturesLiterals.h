#pragma once

float operator"" _Kelvin(unsigned long long kelvin)
{
	return static_cast<float>(kelvin - 273.15);
}
float operator"" _Fahrenheit(unsigned long long fahrenheit)
{
	return static_cast<float>((fahrenheit - 32) * 5.0 / 9.0);
}
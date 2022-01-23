/**
 * @file utils.h
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief utility function declarations 
 * @version 0.1
 * @date 2022-01-22
 */

#ifndef UTIL_H_DEF
#define UTIL_H_DEF

#include <cstdint>

float map (float input, float inputStart, float inputEnd, float outputStart, float outputEnd);
int random(int a, int b);
uint32_t gradient(float ratio);

#endif
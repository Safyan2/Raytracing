#ifndef COLOUR_H
#define COLOUR_H

// program for writing RGB represented by vec3 vectors to an output stream such as ostream 

#include "vec3.h"

#include <iostream>

//type alias for vec3
using colour = vec3;



// sending data to output stream
void write_colour(std::ostream& output_stream, colour pixel_colour)
{
    output_stream << static_cast<int>(255.999 * pixel_colour.x()) << ' '
                  << static_cast<int>(255.999 * pixel_colour.y()) << ' '
                  << static_cast<int>(255.999 * pixel_colour.z()) << '\n';
}

#endif
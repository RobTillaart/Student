
[![Arduino CI](https://github.com/RobTillaart/Student/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/Student/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/Student/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/Student/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/Student/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/Student.svg)](https://github.com/RobTillaart/Student/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/Student/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/Student.svg?maxAge=3600)](https://github.com/RobTillaart/Student/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/Student.svg)](https://registry.platformio.org/libraries/robtillaart/Student)


# Student

Arduino library for Student or T-distribution math.


## Description

**Experimental**

Student is an experimental Arduino library to estimate the mean (average) of a population
based upon a (very) small sample (selection).
Goal is to calculate the interval for which there is a certain confidence e.g. 95%, 
that the population mean lies between the estimated mean from the sample +- some intervalDelta.

The 0.1.x version of the library uses a lookup table for sample size is 2..20, and for the 
discrete confidence levels 80%, 90%, 95%, 98% and 99%.
This look up table is defined in the file **StudentTable.h** and generated from a spreadsheet.
Note: values in the LUT are single sided.

The library allows to calculate the interval after every addition until the internal buffer
of 20 samples is full. (At least 2 samples needed)


### History

The T-distribution is developed by W.A. Gosset in 1908 while working for Guinness Beer.
His goal was to guard a constant quality of the beer. For this he needed a method to determine
the quality of the raw materials like grains, malt and hops to 

### Accuracy / precision

The version 0.1.x lookup table has 20 x 5 values with 3 decimals, coded as an uint16_t (for RAM)
This allows about 3-4 digits precision in the found interval.

The 0.1.x version does not interpolate the confidence level yet, and only support 5 distinct levels.
This interpolation (between 80-99) is planned to be implemented in the future.

If you need only one confidence interval you could strip the lookup table to one column.


### Character

|  parameter  |  name  |  ALT-code  |  char |
|:-----------:|:------:|:----------:|:-----:|
|  mean       |  mu    |  ALT-230   |   µ   |
|  stddev     | sigma  |  ALT-229   |   σ   |
|  CDF        |  phi   |  ALT-232   |   Φ   |  ALT-237 for lower case
|  plus minus |        |  ALT-0177  |   ±   |

- https://altcodesguru.com/greek-alt-codes.html


### Related

- https://en.wikipedia.org/wiki/Normal_distribution
- https://en.wikipedia.org/wiki/Student_distribution
- https://sphweb.bumc.bu.edu/otlt/mph-modules/bs/bs704_probability/bs704_probability9.html
- https://github.com/RobTillaart/Gauss
- https://github.com/RobTillaart/Multimap
- https://github.com/RobTillaart/Statistic  (more stat links there).
- https://github.com/RobTillaart/Student


## Interface

```cpp
#include Student.h
```


### Constructor + meta

- **Student()** constructor. 0.1.x has a fixed max sample size = 20.
- **uint8_t getSize()** returns 20.
- **uint8_t getCount()** returns the number of samples added.
Returns value between 0 .. getSize().
- **void reset()** resets internal counter to zero.

### Add

- **bool add(float value)** adds one sample.
Returns false if internal buffer is full (count >= size).
- **bool add(float \*array, uint8_t size)** adds an array of samples.
Returns false if the internal buffer would "overflow".

### Math

- **float mean()** returns estimated mean based upon samples added.
- **float variance()** idem
- **float deviation()** idem
- **float estimatedDeviation()** returns estimated deviation of the 
estimated mean (based upon the samples).

### Interval

Confidence should be 80, 90, 95, 98 or 99. 
The confidence level is not interpolated and incorrect values are replaced by 95%.


- **float intervalDelta(int confidence)** returns the delta to be added
oor subtracted to the mean to determine the confidence interval.
- **float meanLower(int confidence)** returns mean - intervalDelta.
- **float meanUpper(int confidence)** returns mean + intervalDelta.


## Future

#### Must

- documentation
- improve upon function names.
- test test test

#### Should

- optimize code, e.g. cache values for performance.
- optimize lookup table, PROGMEM for footprint?
- dynamic allocation for sizes > 20
  - or derived classes, student30, student40, student50, student100?
- add interpolation to **intervalDelta()** so confidence level (0.2.x)
  could be any integer value from 80-99 (maybe even float?)

#### Could

- add examples
- add unit tests

#### Won't (unless requested)


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2024-07-22
// PURPOSE: unit tests for the Student library
//          https://github.com/RobTillaart/Student
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "Student.h"


unittest_setup()
{
    fprintf(stderr, "STUDENT_LIB_VERSION: %s\n", (char *) STUDENT_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  Student S;

  assertEqual(10, S.getSize());
  assertEqual(00, S.getCount());
}


unittest(test_add)
{
  Student S;

  S.add(100);

  assertEqual(10, S.getSize());
  assertEqual(01, S.getCount());
  
}


unittest_main()


//  -- END OF FILE --


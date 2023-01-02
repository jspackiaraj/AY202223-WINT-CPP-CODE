# WORKING WITH NUMERIC PRECISION #
## Numeric Precision - Revision of the background ##
Numeric precision, and the number of significant digits are important to calculations. 

Precision and significant numbers are used to represent the dependability and accuracy of measurements or calculations.  When presenting numerical data, it is critical to utilise a suitable number of significant figures or decimal places to represent the data's precision level, preventing overstating the data's accuracy and allowing others to realise the measurements' limitations or calculations' limitations.

For example, measuring an object's length as 12.34 cm with three significant figures or two decimal places indicates that the measurement is accurate to within 0.01 cm and informs others that the actual value of the measurement is most likely between 12.33 cm and 12.35 cm.  If, on the other hand, you describe the measurement as 12.345 cm with four decimal places, it suggests a degree of precision that the measurement must support and may need to be more accurate.

Assume you are performing a calculation that requires multiple steps.  In that situation, utilise numbers with several decimal places to avoid rounding errors, which can add up and cause significant variances in the final result.

Using suitable significant figures or decimal places is critical in many professions, including science, engineering, and finance, where exact measurements and calculations are required for decision-making and problem-solving.

Many scientific, technological, statistical, and mathematical fields require accurately articulating numbers.  For example, if you are measuring a substance's mass, you may need to express the value to several decimal places to distinguish it from comparable substances.

Significant numbers and precision are strongly related to the concept of significant figures, which refers to the digits in a number that is known with some degree of certainty.  In general, the higher the number's significant figures, the more precise it is.  For example, a measurement of "5.00 metres" is more precise than a measurement of "5 metres" because the former has two significant figures and the latter only one.

It's worth mentioning that, depending on the context, numerous conventions and rules exist for expressing significant numbers and precision.  For example, in scientific notation, numbers are frequently written with only one significant figure to the right of the decimal point.  In contrast, two or more significant figures are more commonly used in engineering.  In India, the __IS 2: Rules for Rounding off Numerical Values__ may be referred to for understanding the correct way to apply the rules for rounding to a particular number of significant digits.

## Rounding off and expressing significant numbers ##

Internally, in the memory areas of C++, the numbers are stored with very high precision.  Sometimes, depending on the implementation by the compiler, 1 might be stored as 0.999999... and the programmer needs to be aware of how the computer is actually going to handle the data.  In C++, using the __<iomanip>__ header, much of the same can be implemented for display of the output.  However, a custom function for rounding would be required to be written by the programmer, as per the requirements of the calculations being performed.
  
The following problem illustrates the same.  Refer to the accompanying C++ file, __02_IllustratingRounding.cpp__.

## Problem to illustrate the same ##

Define a C++ class Point with public member variable __x1__, __Y1__, __x2__, and  __y2__, private member variable __distance__, allof data types double.

Create public methods __setDistance()__ and,__GetDistance()__, and private methods __distanceBetweenTwoPoints()__, and __jspRnd()__.  

### Description of Classes ###
#### setDistance() ####
This class is used to set the private member variable and contains a call to the private method __distanceBetweenTwoPoints()__, passing the public member variables __x1__, __Y1__, __x2__, and  __y2__.  This class calculates the distance between the two points, which it receives as arguments, using standard trigonometric formulae.
#### GetDistance() ####
This class is used to get the value stored in the private member variable __distance__ and exposes the same outside the class.  The final result of the computation is rounded using __jspRnd()__ to the required number of digits.
#### jspRnd() ####
This class rounds off the number to the required number of significant digits.

The function __main()__ should initiate an instance of the class Point, set the coordinates of the points and set the distance variable.   Demonstrate how you can fix the output to a certain number of decimal places, and modify the precision of __std::cout__ using the __<iomanip>__ header file.
  
```
<cmath> has the definition of the mathematical functions used.  
  Look up any good reference on how to call these functions, 
  the methods used, and how the different methods are overloaded.

<iomanip> has the definition of the methods that the std::cout can display numbers.  
  Look up any good reference on how to call these functions, 
  the methods used, the lifetime of modifiers, 
  and how the different methods are overloaded.
  
```

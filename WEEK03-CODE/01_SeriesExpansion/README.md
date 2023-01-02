# SERIES EXPANSION #
The power series expansion of sine is an infinite series that allows you to approximate the value of the sine function to any desired degree of precision. The basic form of the series is:

sin(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - ...

![Link](/AY202223-WINT-CPP-CODE/WEEK03-CODE/01_SeriesExpansion/PowerSeriesExpansionOfSine.png)

In this series, the terms x^n/n! represents the nth-order Taylor polynomial for the sine function. The series can be truncated at any point, with the remaining terms representing the error in the approximation. The more terms you include in the series, the more precise the approximation will be.

In general, the number of iterations needed to achieve a certain level of precision depends on the value of x and the desired precision. For example, if you want to approximate sin(x) to within an error of 10^-6 for a small value of x, you should only include a few terms of the series. However, if you want to achieve the same level of precision for a larger value of x, you will need to include more terms.

The power series expansion of the sine is just one way to approximate the value of the sine function. Other methods may be more efficient in certain situations, such as using lookup tables or more specialized approximation techniques.

## Outline of Solution ##
Here is an outline of the steps you can follow to program the expansion of the sine function using the power series, with the number of iterations required for a required degree of precision:

1. Define a method that takes as input the angle for which you want to compute the sine and the desired precision.
2. Initialize a variable to store the current value of the sine expansion, and set it to 0.
3. Implement a loop that will continue until the required precision is reached. Within the loop: 
4. a. Compute the next term in the power series expansion of sine. b. Add the computed term to the current value of the expansion. c. Compare the current value of the expansion to the previous value, and if the difference is smaller than the required precision, exit the loop.
Return the final value of the sine expansion as the result of the function.

## Pseudocode for determining the value of sine using an expansion series ##
Here is a write-up of the steps for programming an expansion of the sine function using the power series, along with the number of iterations required for a certain degree of precision:
Begin by writing a function that takes in a value for __x__ (in radians) and the desired precision level. (In our program, we have the option to enter the value as an angle in degree. Simply use the appropriate method.
Initialize a variable __sum__ to 0, which will be used to store the result of the expansion.
Initialize a variable __prev__ to some large value (e.g. 10^9), which will be used to store the result of the previous iteration. (In our case, there is a means to set the number of decimal places. It has been set to 3)
Initialize a variable __i__ to 1, which will be used as the exponent in the power series expansion.
Write a loop that will continue until the difference between sum and prev is less than the desired precision level.
Inside the loop, calculate the term in the power series expansion using the current value of __i__, and add it to the sum.
Set the value of __prev__ to the current value of __sum__.
Increment __i__ by 1.
Return the value of __sum__ as the result of the function.
To compare the result of the expansion to the previous value, you can use an if statement to check whether the difference between sum and prev is less than the desired precision level. You can exit the loop and return the result if it is. If not, then you can continue iterating until the difference between the two values is small enough.
It's worth noting that the number of iterations required for a certain degree of precision will depend on the value of x and the desired precision level. In general, larger values of x and higher precision levels will require more iterations to achieve the desired level of accuracy.

# SERIES EXPANSION #
The power series expansion of sine is an infinite series that allows you to approximate the value of the sine function to any desired degree of precision. The basic form of the series is:

![Link](Assets/Images/PowerSeriesExpansionOfSine.png)

The series can be truncated at any point, with the remaining terms representing the error in the approximation. The more terms you include in the series, the more precise the approximation will be.

In general, the number of iterations needed to achieve a certain level of precision depends on the value of x and the desired precision. For example, if you want to approximate sin(x) to within an error of 10^-6 for a small value of x, you should only include a few terms of the series. However, if you want to achieve the same level of precision for a larger value of x, you will need to include more terms.

The power series expansion of the sine is just one way to approximate the value of the sine function. Other methods may be more efficient in certain situations, such as using lookup tables or more specialized approximation techniques.

## Outline of Solution ##
Here is an outline of the steps you can follow to program the expansion of the sine function using the power series, with the number of iterations required for a required degree of precision:

1. Define a method that takes as input the angle for which you want to compute the sine and the desired precision.
2. Initialize a variable to store the current value of the sine expansion, and set it to 0.
3. Implement a loop that will continue until the required precision is reached. Within the loop: 
    a. Compute the next term in the power series expansion of sine. 
    b. Add the computed term to the current value of the expansion. 
    c. Compare the current value of the expansion to the previous value, and if the difference is smaller than the required precision, exit the loop.
4. Return the final value of the sine expansion as the result of the function.

## Pseudocode for determining the value of sine using an expansion series ##
Here is a write-up of the steps for programming an expansion of the sine function using the power series, along with the number of iterations required for a certain degree of precision:
1. Begin by writing a function that takes in a value for **x** (in radians) and the desired precision level. (In our program, we have the option to enter the value as an angle in degree. Simply use the appropriate method.
2. Initialize a variable **sum** to 0, which will be used to store the result of the expansion.
3. Initialize a variable **prev** to some large value (e.g. 10^9), which will be used to store the result of the previous iteration. (In our case, there is a means to set the number of decimal places. It has been set to 3)
4. Initialize a variable **i** to 1, which will be used as the exponent in the power series expansion.
5. Write a loop that will continue until the difference between sum and prev is less than the desired precision level.
6. Inside the loop, calculate the term in the power series expansion using the current value of **i**, and add it to the sum.
7. Set the value of **prev** to the current value of **sum**.
8. Increment **i** by 1.
9. Return the value of **sum** as the result of the function.
10. To compare the result of the expansion to the previous value, you can use an if statement to check whether the difference between sum and prev is less than the desired precision level. You can exit the loop and return the result if it is. If not, then you can continue iterating until the difference between the two values is small enough.

> **Note**
> It's worth noting that the number of iterations required for a certain degree of precision will depend on the value of x and the desired precision level. In general, larger values of x and higher precision levels will require more iterations to achieve the desired level of accuracy.

## Output in a Console ##

![Link](Assets/Images/Output.png)

## Discussion of Output ##
In the code, we have introduced a string stream object which essentially treats the string as a stream, and we have the luxury of using it like we are using one of the many stream objects as **std::cin** or **std::cout**. With intermediate member variables to capture values of the iteration, we are able to form a neat little table with the member variable **strOutputTxt** and  **strOutputTxt2**.   Because we are handling the same as string stream, we are able to use the methods exposed in **\<iomanip\>** to modify the output.  Note how the iteration progresses in the first run.  In the second and thrid run, note how the display changes when string values of  **strOutputTxt** and  **strOutputTxt2**.
    
The header **\<iomanip\>** is powerful, and we will be creating text files and ensuring that the number of decimal places, precision in display and internal rounding to a level desirable for the program will be written out.

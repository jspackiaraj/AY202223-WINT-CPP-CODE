>**Warning**
> This description is work in progress.
# Question #
Write a program which has a function to read the numeric information from a file using C++, and reports the size of the file and the average of the elements present in the file.  This function reads the file sent to it as a parameter.  Have error handling mechanism with multiple try .. catch blocks to handle exceptions thrown by the program as givn below:
1. check if the file to be read is available in the specified path, otherwise give an error message out.
2. check if the file has illegal data (non - numeric) and flag the same.
3. check if the file is a non-empty file, and if it is empty flag the same.
## About the proposed solution ##
A proposed solution has been attached.  This solution, aims to demonstrate  This program is very similar to the previous exercise, with the exception that we will use multiple `catch` blocks to handle the different errors that we predict that the program will thrown. As before, a simple function reads the location mentioned and returns the content of the file if the file exists in the specified location.  In addition, the size of the file is also captured by the program.  Please note that the file will be read from the directory where the executable will be created.

> **Note**
> Go through the previous exercises where additional information on file handling, escaping paths is available.  This exercise builds on the [previous exercise](../01_ErrorHandlingWithIf_FileReading/).

## Outline of Solution ##
Here is an outline of the steps you can follow to read a file and have a basic error handling:

The most common error occurs when the file is not available for a computer process because it is either locked by the operating system for another process, or it is not available in the location where the program is looking for it.  In the previous case, the `if` statement was alone used for the error check.  
1. The file which is to be opened is received as a parameter and the file is checked if it can be opened.  An error of type **runtime_error** is thrown with a custom message.
2. Read the file line by line and convert the string to a double using the **stod()** function.  Here there is a chance that the string cannot be converted to a double, hence enclose the statement in a `try` block.  When the string cannot be converted, it will throw an error of data type **invalid_argument**.  Throw this error onward for the `main()` function to handle.
3. If the file does not contain any data, pass meaningful information to the end user.  This is also an error that will be handled by `main()`.  It is wished to demonstrate that the `catch` blocks need to be having a waterfall model where the most specific error datatype is handled before cascading down to the more generic types.  Unlike the previous two throw of an error, here the error is of datatype **int** and the error block in main which will have catch an error thrown of data type **int** will handle the same.
> **Note**
> Refer to the note on the __c_str()__, and line termination character in the [previous exercise](../01_ErrorHandlingWithIf_FileReading/).

## Introducing the try .. catch block and the throw statement ##
Here, the `try block` has code that has a potential to have an errror.  The `throw` statement within the try block, is used to communicate that an error is present to a `catch` block.   On encountering an error, the __throw__ statement sends an error message specified by the programmer, which will be handled by the `catch` block.  This priciple can be used to build more involved error handlers, by having multiple __*catch*__ blocks.  The __*throw*__ statement interrupts the normal flow of the program and should be used in __*exceptional*__ situations only, in combination with a __*try .. catch*__ block.

## Output in a Console ##
The following output is one in which the file is not available is not available in the directory where the executable is run from.

![Link](Assets/Images/Output.png)

The contents of the file __input1.txt__ is read and the screen shot of the same is shown below.

>![Link](Assets/Images/Output_1.png)

## Discussion of Output ##
As in the previous case,

1. Open the directory and change the file name.  See what happens.  
2. Change the file name in the CPP file and compile it to read another file.
3. Uncomment the lines _34_ and _35_ and type the name of the file to be opened.
4. You can also try to change the location of the file which is to be read from.  This will be a good exercise to understand escaping paths. 
5. Open files other than the text files and try to see the contents.
6. Look for some of the standard error messages encountered for diffferent conditions.
> **Note**
> 1. Error message in this case was what we specified.  Look for the standard errors which a programming language has to offer.
> 2. Try and understand the reason of a __return 0;__ or a __return

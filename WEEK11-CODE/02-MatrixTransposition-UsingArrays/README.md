# Question #
Write a C++ program that reads a file which contains the data required to populate a matrix.  The first two rows of the data files have the data of the number of rows and columns, respectively.  The remaining rows have the data arranged so that the matrix can be populated in a row-wise fashion.  Your program should get the file names to be read from the user and then populate a dynamic array.   This matrix shall be transposed and stored in another dynamic array.,
The dynamic array shall be printed one element per line so that the output is printed on the console similar to the input file format, ie, first, the number of rows in the output matrix and then the number of columns in the output matrix, followed the elements of rows, one per line in a row-wise fashion.
## About the proposed solution ##
A proposed solution has been attached.  The program uses dynamic memory allocation and initialises a block of code that will be contiguous.  The information from the file is read and the matrix is populated in the memory locations allocated.   As matrix which is a transpose will have the values in the rows and columns  of the original matrix interchanged, a for loop will be used to fill up the transposed matrix.
In this solution, since the size is known before hand, the rows and columns are comfortably populated by using the main loop that reads the file.  The pre-increment operator is used in the check, which elimnates the need to increment the value before making the logical decision if the columns in a specific row of data is read and populated in an array.  Once a row of data is read, the counter that tracks the row gets incremented and the process repeats till all the rows are accounted for.  
The files read by this program __matA.txt, is stored in the ![Assets](Assets) folder.
> **Note**
>  The file should be present in the directory as where the executable is compiled and run from.  Any file can be used, however, the path should be included, if the files to be read are not in the same path as where the executable is located in.
## Outline of Solution ##
Here is an outline of the steps you can follow to find the transpose of the matrix:
1. Start by getting the file names where the matrices are stored.  In this case, the path is hardcoded, but you can uncomment _line 35_ to be able to enter custom file names to be read by the program.
2. A few switches have been added to the program as boolean values.  These switches determine the behaviour of different parts of the program.
3. The __main()__ method reads the data file and populate the matrix A.  The first two rows of these files contains information of the number of rows and columns that are present in the matrices whose data is stored by the file.
4. Based on the number of rows and columns, space for the matricx is dynamically assigned.
5. The logic of the program is such that as the file is read, the matrices are populated by using a series of __if .. else__ logic.
6. Once, both the matrices are read, they are added and the output is stored in a third matrix, which is also dynamically created.
7. The values of the sum is output.
> **Note**
>  Using the switches is an elegant way to debug the program.  Play around changing the switches to _true_ and _false_.
## A word of caution in using the program ##
There is a chance that your compiler does not recogonise the line ending.  In the file attached, the line ending is __LF__, and in windows, if you need a __CR LF__ line ending, please open the same in a text editor like notepad++ and modify the line ending to suit your platform.
## Output in a Console ##
The output keeping the Boolean Switches of __debug mode__ and __not showing decorators__ to false and true respectively, the output is as given below. 
![Link](Assets/Images/Output.png)

## Discussion of Output ##
The output demonstrates a few ways that the array can be printed out.
## Suggested Further Activities ##
1. As always, play around with the different boolean switches and observe how the output gets changed.
2. In this solution, there is no check to ensure that only double values are stored, nor check if there are adequate rows of data to populate the arrays fully.  This can be taken as a second-level exercise.

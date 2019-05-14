# listmax

In this challenge, you will start with an array initialized to zeros with indexes starting at 1.  You will then be given a series of operations to perform on segments of the list.  Each operation will consist of a starting and ending index within the array, and a number to add to each element within that range.

For example, start with an array of 5 elements: [0, 0, 0, 0, 0].  The variables a and b represent the starting and ending indexes inclusive.  Another variable k is the addend.  The first element is at index 1.

   a    b    k             list
                  [  0,  0,  0,  0,  0]
   1    2   10    [ 10, 10,  0,  0,  0]
   2    4    5    [ 10, 15,  5,  5,  0]
   3    5   12    [ 10, 15, 17, 17, 12]


The maximum value in the resultant array is 17. That is the value to be determined.

Function description

Complete the listMax function in the editor below. The function must return a long integer denoting the largest value of the array after all operations have been performed.

listMax has the following parameters:

   n: An integer, denoting the size of the array.
   operations: A 2D integer array, denoting the operations.


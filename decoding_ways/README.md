the problem:

    Given a string of digits, return the numebr of ways to decode the digits to characters.    

ex:

    intput = "226"  
    output = 3
    explanation: can be decoded as "BZ (2,26), "VF" (22,6), or "BBF" (2,2,6)

solution:

    use two variables val1 and val2 to track the number of ways to decode digits up to and including  
    the (i-1)th digit and the (i-2)th digits respectively. If the current digit (ith digit) is  
    between 1 and 9, it can be considered individually so the number of ways to decode is the same as the number of ways to decode the string up to and including (i-1)th digit. if combining the (i-1)th  digit with the ith digit creates a two digit number that is in [10,26] then the number of ways to decode is the same as the number of ways to decode up to and including the (i-2)th digit so we increment current number of ways by val1 and/or val2.  
    should end up with total number of ways to decode the whole string.
    
complexity:

    This solution uses a dynamic programming approah as we keep track of the number of ways to decode  the string up to an including both (i-1)th digits and (i-2)th digits. The number ways to decode  
    the string up to and including the ith digit is calculated using the numbers using the previous  
    counts.  
    Allows for linear time complexity. 

    time: O(n)  
    space: O(1)  
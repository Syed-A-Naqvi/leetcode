the problem:

    Given an input array denoting the height of individual walls, choose two  
    such that area of water between them is maximized. 

ex:

    array = {1,8,6,2,5,4,8,3,7}  
    if we choose walls 8 and 7 then the maximum height of the container can  
    can be 7 and the width is index(7) - index(8) = 7 so total area = 49. 

solution:

    Point to the first and last elements of the array. Calculate area between  
    the bars and store it as max_area. Start traversing the list using the  
    the pointer to the lower of the two bars (if they are equal height choose  one randomly). If we encounter a bar of greater height than the original,  
    calculate new area. Repeat until pointers meet. 

complexity:

    time: O(n)  
    space: O(1)  
package stacks.largest_rectangle;

import java.util.Stack;

public class Main {

    public static void main(String[] args) {

        Solution mySol = new Solution();

        int largestRectangle = mySol.largestRectangleArea(new int[] {7,1,7,2,2,4});

        System.out.println(largestRectangle);
    }
}

class Solution {

    class Bar {
        
        int height;
        int idx;

        public Bar(int h, int i){
            this.height = h;
            this.idx = i;
        }
        
    }

    public int largestRectangleArea(int[] heights) {
        
        Stack<Bar> bars = new Stack<>();
        bars.add(new Bar(heights[0], 0));

        int currBest = 0;
        for (int i = 1; i < heights.length; i++) {
            if (bars.peek().height > heights[i]){
                if (bars.peek().)
            }
        }

    }

}
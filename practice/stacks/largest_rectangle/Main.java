package stacks.largest_rectangle;

import java.util.Stack;

public class Main {

    public static void main(String[] args) {

        Solution mySol = new Solution();

        int largestRectangle = mySol.largestRectangleArea(new int[] {0,1,0,1});

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

        @Override
        public String toString() {
            return String.format("{h:%d, idx:%d}", this.height, this.idx);
        }
        
    }

    public int largestRectangleArea(int[] heights) {
        
        Stack<Bar> bars = new Stack<>();

        int currBest = 0;
        int idx = 0;
        int i = 0;

        while (i < heights.length) {

            if (bars.empty() || bars.peek().height < heights[i]) {
                bars.add(new Bar(heights[i], idx));
                i++;
                idx = i;
                System.out.println("inserted bar:" + bars.peek().toString());
                System.out.println("idx:" + idx + ", i:" + i);
                System.out.println("currBest = " + currBest);
                System.out.println("stack:" + bars);
                System.out.println();
            }
            else if (bars.peek().height == heights[i]) {
                i++;
                idx = i;
                System.out.println(String.format("heights[%d]", i) + "=" + heights[i] + " == " + "bars.peek()="+ bars.peek().toString());
                System.out.println("idx:" + idx + ", i:" + i);
                System.out.println("currBest = " + currBest);
                System.out.println("stack:" + bars);
                System.out.println();
            }
            else {
                Bar bar = bars.pop();
                idx = bar.idx;
                int currArea = ((i - bar.idx) * bar.height);

                if ( currArea > currBest ) {
                    currBest = currArea;
                }

                System.out.println("popped bar:" + bar.toString());
                System.out.println("idx:" + idx + ", i:" + i);
                System.out.println("currBest = " + currBest);
                System.out.println("stack:" + bars);
                System.out.println();
            }

        }


        while (!bars.empty()) {

            // System.out.println("currBest:" + currBest);

            Bar bar = bars.pop();
            int currArea = ((i - bar.idx) * bar.height);

            if ( currArea > currBest ) {
                currBest = currArea;
            }

        }

        return currBest;

    }

}
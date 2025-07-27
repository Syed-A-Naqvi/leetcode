class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {

        let maxHeights = [0,0];
        let pointers = [0, height.length-1];
        let totalTrapped = 0;

        while(pointers[0] < pointers[1]) {

            let p;
            height[pointers[0]] < height[pointers[1]] ? p = 0 : p = 1;

            let water = maxHeights[p] - height[pointers[p]]

            if(water > 0) {
                totalTrapped += water;
            }

            if (maxHeights[p] < height[pointers[p]]) {
                maxHeights[p] = height[pointers[p]];
            }

            (p == 0) ? pointers[p]++ : pointers[p]--;

        }

        return totalTrapped;

    }
}

const solution = new Solution();
const height = [0,2,0,3,1,0,1,3,2,1];
const result = solution.trap(height);

console.log(`Total trappable water = ${result}`)
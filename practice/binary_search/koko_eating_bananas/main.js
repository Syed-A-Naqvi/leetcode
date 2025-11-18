class Solution {

    /**
     * @param {number[]} piles
     * @param {number} h
     * @return {number} 
     */
    minEatingSpeed(piles, h){
        // finding max pile
        let r = 0;
        for (let i = 0; i < piles.length; i++) {
            if (piles[i] > r) { r = piles[i];}
        }

        // bianry search on range of possible k values 
        let min_k = r;
        let l = 0;
        while(l <= r){
            
            let k = Math.floor( (l+r) / 2)
            let curr_h = 0;

            for (let i = 0; i < piles.length; i++) {
                curr_h += Math.ceil(piles[i]/k);
            }

            if (curr_h <= h) {
                r = k-1;
                min_k = k;
            }
            else {
                l = k+1;
            }

        }

        return min_k;
    }
}

let piles = [25,10,23,4], h = 4;
let mySol = new Solution();

console.log(`minimum eating rate is ${mySol.minEatingSpeed(piles, h)}`);

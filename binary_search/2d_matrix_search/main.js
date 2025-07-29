class Solution {
    /**
     * @param {number} cols
     * @param {number} i
     * @return {{j: number, k: number}}
     */
    #getMatrixIdxs(cols, i) {
        let j = Math.floor( i / cols);
        let k = i - j*cols;
        return {j, k}
    }

    /**
     * @param {number[][]} matrix
     * @param {number} target
     * @return {boolean}
     */
    searchMatrix(matrix, target) {
        
        // // getting matrix dimensions
        let rows = matrix.length;
        let cols = matrix[0].length;

        // // initializing algorithm pointers
        let l = 0;
        let r = (rows*cols) - 1

        while (l <= r) {

            let m = Math.floor((r+l)/2);

            let j = this.#getMatrixIdxs(cols, m).j;
            let k = this.#getMatrixIdxs(cols, m).k;

            if(matrix[j][k] === target) {
                return true;
            }
            if(matrix[j][k] < target) {
                l = m+1;
            }
            if(matrix[j][k] > target) {
                r = m-1;
            }

        }
        
        return false;

    }
    
}

let mysol = new Solution();

let matrix = [
    [1,2,4,8],
    [10,11,12,13],
    [14,20,30,40]
];

let target = 100;

console.log(mysol.searchMatrix(matrix, target));
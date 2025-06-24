package two_pointers.valid_palindrome;

import java.util.HashSet;

public class Main {

    public static void main(String[] args) {
        
        Solution mysol = new Solution();

        System.out.println(mysol.isPalindrome("Was it a car or a cat I saw?"));

    }
}

class Solution {
    public boolean isPalindrome(String s) {
        
        HashSet<Integer> chars = new HashSet<>();
        HashSet<Integer> nums = new HashSet<>();

        for (int i = 'A'; i < 'Z'+1; i++) {
            chars.add(i);
        }
        for (int i = 'a'; i < 'z'+1; i++) {
            chars.add(i);
        }
        for (int i = '0'; i < '9'+1; i++) {
            nums.add(i);
        }


        int i = 0, j = s.length()-1;
        while (i < j) {
            
            while ( !(chars.contains((int)s.charAt(j)) || nums.contains((int)s.charAt(j))) ) {
                j--;
            }
            while ( !(chars.contains((int)s.charAt(i)) || nums.contains((int)s.charAt(i))) ) {
                i++;
            }

            if (j < 0 || i > s.length()-1) {
                return false;
            }

            int a = s.charAt(i), b = s.charAt(j);

            if (nums.contains(a) && nums.contains(b) && (a != b)) {
                System.out.println((char)a + " and " + (char)b + " not same num.");
                return false;
            }
            else if (chars.contains(a) && chars.contains(b) && ((a - b) % 32 != 0) ) {
                System.out.println((char)a + " and " + (char)b + " not same char.");
                return false;
            }
            else if ( (chars.contains(a) && nums.contains(b)) || (chars.contains(b) && nums.contains(a)) ) {
                System.out.println((char)a + " and " + (char)b + " not both char or num.");
                return false;
            }

            i++;
            j--;

        }

        return true;

    }
}

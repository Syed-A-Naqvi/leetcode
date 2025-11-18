package two_pointers.valid_palindrome;

public class Main {

    public static void main(String[] args) {
        
        Solution mysol = new Solution();

        System.out.println(mysol.isPalindrome(".,"));
    }
}

class Solution {
    public boolean isPalindrome(String s) {

        // converting all letters to lowercase for simpler comparison conditions
        s = s.toLowerCase();

        // two pointers
        int i = 0, j = s.length()-1;

        while (i < s.length() && j > -1 && i < j) {
            if ( !((s.charAt(i) >= 'a' && s.charAt(i) <= 'z') || (s.charAt(i) >= '0' && s.charAt(i) <= '9'))) {
                System.out.println(s.charAt(i) + " is not alphanumeric, incrementing i.");
                i++;
                continue;
            }
            if ( !((s.charAt(j) >= 'a' && s.charAt(j) <= 'z') || (s.charAt(j) >= '0' && s.charAt(j) <= '9'))) {
                System.out.println(s.charAt(j) + " is not alphanumeric, decrementing j.");
                j--;
                continue;
            }

            if (s.charAt(i) != s.charAt(j)) {
                System.out.println(s.charAt(i) + " not equal to " + s.charAt(j));
                return false;
            }
            
            System.out.println(s.charAt(i) + " equals  " + s.charAt(j));
            
            j--;
            i++;

        }

        return true;

    }
}

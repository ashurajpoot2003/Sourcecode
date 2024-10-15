import java.util.*;

public class Solution {
    
    // Main function that will return a list of valid strings after removing invalid parentheses
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new ArrayList<>();
        // Call helper function to recursively remove invalid parentheses
        remove(s, ans, 0, 0, new char[]{'(', ')'});
        return ans;
    }

    // Helper function that uses recursion and backtracking to remove invalid parentheses
    public void remove(String s, List<String> ans, int last_i, int last_j, char[] par) {
        // `stack` is used to keep track of parentheses balance
        for (int stack = 0, i = last_i; i < s.length(); ++i) {
            if (s.charAt(i) == par[0]) stack++;  // Increase stack for opening parenthesis '('
            if (s.charAt(i) == par[1]) stack--;  // Decrease stack for closing parenthesis ')'
            
            // If `stack` becomes negative, it means there are too many closing parentheses
            if (stack >= 0) continue;
            
            // Try removing a closing parenthesis ')' and recursively check if it's valid
            for (int j = last_j; j <= i; ++j) {
                if (s.charAt(j) == par[1] && (j == last_j || s.charAt(j - 1) != par[1])) {
                    // Remove the invalid parenthesis at position j and recurse
                    remove(s.substring(0, j) + s.substring(j + 1), ans, i, j, par);
                }
            }
            return;
        }

        // Reverse the string to check from right to left
        String reversed = new StringBuilder(s).reverse().toString();
        
        // If par[0] is '(', that means we were checking from left to right.
        // Now we reverse and check from right to left with swapped parentheses.
        if (par[0] == '(') {
            remove(reversed, ans, 0, 0, new char[]{')', '('});
        } 
        // If we've already checked both directions, add the valid string to the result list.
        else {
            ans.add(reversed);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner scanner = new Scanner(System.in);
        
        // Input string containing parentheses and letters from the user
        System.out.println("Enter the string with parentheses and letters: ");
        String s = scanner.nextLine();

        // Call the function and store the result
        List<String> result = solution.removeInvalidParentheses(s);

        // Output the list of valid strings
        System.out.println("Valid strings after removing invalid parentheses: ");
        for (String str : result) {
            System.out.println(str);
        }
    }
}

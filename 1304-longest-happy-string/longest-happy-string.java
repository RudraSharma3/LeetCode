import java.util.PriorityQueue;

class Solution {
    class Pair {
        int count; // Remaining count of a character
        char ch;   // The character itself
        
        Pair(int count, char ch) {
            this.count = count;
            this.ch = ch;
        }
    }

    public String longestDiverseString(int a, int b, int c) {
        // Max-heap based on count of characters remaining
        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> y.count - x.count);
        
        // Add pairs of count and character for 'a', 'b', and 'c'
        if (a > 0) pq.add(new Pair(a, 'a'));
        if (b > 0) pq.add(new Pair(b, 'b'));
        if (c > 0) pq.add(new Pair(c, 'c'));
        
        StringBuilder result = new StringBuilder();
        
        while (!pq.isEmpty()) {
            // Get the character with the most remaining occurrences
            Pair first = pq.poll();
            
            // Check if we can safely add this character to the result
            int len = result.length();
            if (len >= 2 && result.charAt(len - 1) == first.ch && result.charAt(len - 2) == first.ch) {
                // If adding this character will result in a "aaa", "bbb", or "ccc", we need to pick another character
                if (pq.isEmpty()) break; // If no other character is available, break

                Pair second = pq.poll(); // Pick the next best character
                result.append(second.ch);
                second.count--;

                if (second.count > 0) pq.add(second); // Re-add if there's still more of this character

                pq.add(first); // Re-add the original character back
            } else {
                // Safe to add the character
                result.append(first.ch);
                first.count--;
                
                if (first.count > 0) pq.add(first); // Re-add if there's still more of this character
            }
        }
        
        return result.toString();
    }
}

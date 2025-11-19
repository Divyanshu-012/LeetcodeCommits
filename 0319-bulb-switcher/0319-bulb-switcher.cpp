class Solution {
public:
    int bulbSwitch(int n) {
        int i = 1;           // Start checking from the first bulb
        int answer = 0;      // Counter for bulbs that remain on
        while (i * i <= n) { // While i^2 is within range
            answer++;        // Each perfect square bulb stays on
            i++;             // Move to next integer
        }
        return answer;       // Return total count of perfect squares
    }
};
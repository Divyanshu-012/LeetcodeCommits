class Solution {
    public boolean anagram(String[] words, int idx) {
        int[] alpha = new int[26];

        for (int i = 0; i < words[idx].length(); i++) {
            alpha[words[idx].charAt(i) - 'a']++;
        }

        if (words[idx - 1].length() != words[idx].length()) return false;

        for (int i = 0; i < words[idx - 1].length(); i++) {
            alpha[words[idx - 1].charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (alpha[i] != 0) return false;
        }

        return true;
    }

    public List<String> removeAnagrams(String[] words) {
        List<String> list = new ArrayList<>(Arrays.asList(words));
        int n = list.size();

        for (int i = n - 1; i > 0; i--) {
            if (anagram(words, i)) {  
                list.remove(i);
            }
        }
        return list;
    }
}

class Solution {
    public boolean isAnagram(String s, String t) {
        int[] sCount = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int[] tCount = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i < s.length(); i++) {
            sCount[s.charAt(i) - 'a']++;
        }

        for (int j = 0; j < t.length(); j++) {
            tCount[t.charAt(j) - 'a']++;
        }

        for (int k = 0; k < 26; k++) {
            if (sCount[k] - tCount[k] != 0) {
                return false;
            }
        }

        return true;
    }
}

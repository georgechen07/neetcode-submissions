class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        List<String> characters = new ArrayList<>();
        for (int i = 0; i < strs.length; i++) {
            int[] list = new int[26];
            for (int j = 0; j < strs[i].length(); j++) {
                list[strs[i].charAt(j) - 'a']++;
            }
            characters.add(Arrays.toString(list));

        }

        HashMap<String, Integer> anaFound = new HashMap<>();
        int b = 0;
        for (int a = 0; a < strs.length; a++) {
            if (anaFound.get(characters.get(a)) != null) {
                (res.get(anaFound.get(characters.get(a)))).add(strs[a]);
            } else {
                List<String> substrings = new ArrayList<>();
                substrings.add(strs[a]);
                anaFound.put(characters.get(a), b);
                b++;
                res.add(substrings);
            }
        }

        return res;
    }
}
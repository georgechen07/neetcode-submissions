class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        if (n == 0) {
            return res;
        }

        int offset = 0;
        res.push_back(1);
        for (int i = 2; i <= n; ++i) {
            if (ceil(log(i) / log(2)) == floor(log(i) / log(2))) {
                res.push_back(1);
                ++offset;
                cout << "triggered " << i << " " << log(i) / log(2) << " " << offset << '\n';
            } else {
                res.push_back(res[res.size() - pow(2, offset)] + 1);
            }
        }

        // log(6) / log(2) == 2.14134
        // ceil(2....) == 3
        // desired res = 4

        // < 2 = -1
        // < 4 = -2
        // < 8 = -4
        // < 2x = -x
        // 2^a < i < 2^b
        // i results in - b / 2
        
        // 3 = 2^1
        // 5 = 2^2
        // 7 = 2^3
        // 9 = 2^4
        // 11 = 2^5

        return res;
    }
};


/*
0   0
1   1
2   10
3   11
4   100
5   101
6   110        wasd     prev
7   111
8   1000
9   1001
10  1010        wasd        prev
11  1011
12  1100        wasd        prev - 1
13  1101
14  1110        wasd    prev
15  1111
16  10000
17  10001
18  10010        wasd   prev
19  10011
20  10100        wasd   prev - 1
21  10101
22  10110        wasd   prev
23  10111
24  11000        wasd   prev - 2
25  11001
26  11010        wasd   prev
27  11011
28  11100        wasd   prev - 1
29  11101
30  11110        wasd   prev
31  11111
32  100000

*/
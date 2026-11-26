class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;

        n -= 10;
        int last = 9;
        bool alice = false;

        while(n >= last) {
            n -= last;
            last--;
            alice = !alice;
        }

        return !alice;
    }
};
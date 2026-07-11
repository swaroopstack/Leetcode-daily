class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(26,0);
        for(int i=0;i<magazine.size();i++){
            mag[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            mag[ransomNote[i]-'a']--;
            if(mag[ransomNote[i]-'a']<0){
                return false;
            }
        }
        return true;
    }
};
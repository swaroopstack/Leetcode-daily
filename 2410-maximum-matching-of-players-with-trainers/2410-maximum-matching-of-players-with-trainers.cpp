class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int gend=players.size()-1;
        int send=trainers.size()-1;
        while(send>=0 && gend>=0){
            if(players[gend]<=trainers[send]){
                ans++;
                gend--;
                send--;
            }
            else{
                gend--;
            }
        }

        return ans;
    }
};
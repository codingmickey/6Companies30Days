class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> track;
        int b = 0, c = 0;
        for(auto x:secret) {
            track[x]++;
        }
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                b++;
                track[guess[i]]--;
            }
        }
        for(int i = 0; i < secret.length(); i++) {
            if(track.find(guess[i]) != track.end() && secret[i] != guess[i]) {
                if(track[guess[i]] > 0) {
                    c++;
                }
                track[guess[i]]--;
            }
        }
        return to_string(b) + "A" + to_string(c) + "B";
    }
};

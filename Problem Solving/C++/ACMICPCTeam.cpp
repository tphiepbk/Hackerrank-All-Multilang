#include <iostream>
#include <vector>
#include <map>

using namespace std;

int skillOfTeam(string player1, string player2) {
    int count = 0;
    for (int i = 0 ; i < player1.length() ; i++) {
        int skill1 = (int)player1[i] - 48;
        int skill2 = (int)player2[i] - 48;
        if ((skill1 | skill2) == 1) count++;
    }
    return count;
}

vector<int> acmTeam(vector<string> topic) {
    vector<int> res;
    map<int, vector<vector<int>>> m;
    for (int i = 0 ; i < topic.size() - 1 ; i++) {
        string player1 = topic[i];
        for (int j = i + 1; j < topic.size() ; j++) {
            string player2 = topic[j];
            int skills = skillOfTeam(player1, player2);
            vector<int> p(2);
            p[0] = i;
            p[1] = j;
            m[skills].push_back(p);
        }
    }  
    auto it2 = m.rbegin();
    res.push_back(it2->first);
    res.push_back(it2->second.size());
    return res;

}

int main() {
    vector<string> topic = {"10101",
                            "11100", 
                            "11010", 
                            "00101"};

    vector<int> res = acmTeam(topic);
    cout << res[0] << " " << res[1];
}
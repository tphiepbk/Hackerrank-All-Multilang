#include <bits/stdc++.h>

using namespace std;

int nonDivisibleSubset(int k, vector<int> s)
{

    vector<vector<int>> container;
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if ((s[i] + s[j]) % k != 0)
            {
                vector<int> line(2);
                line[0] = s[i];
                line[1] = s[j];
                container.push_back(line);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < container.size(); i++)
    {
        vector<int> line = container[i];
        for (int j = 0; j < s.size(); j++)
        {
            int check = 0;
            int temp = s[j];
            for (int k = 0; k < line.size(); k++)
            {
                int temp2 = line[k];
                if (s[j] == line[k])
                    break;
                if ((s[j] + line[k]) % 3 != 0)
                    check++;
            }
            if (check != 0)
                line.push_back(s[j]);
        }
        if (line.size() >= max)
            max = line.size();
    }

    return max;

    /*
    vector<int> res;
    res.push_back(s[0]);
    int lastIndex = 1;
    for (int i = 1 ; i < s.size() ; i++) {
        int check = 0;
        for (int j = 0 ; j < res.size() ; j++) {
            if ((res[j] + s[i]) % k == 0) check++;
        }
        if (check == 0) res.push_back(s[i]);
    }
    return res.size();
    */
}

int main()
{
    vector<int> arr = {19, 10, 12, 24, 25, 22};
    cout << nonDivisibleSubset(4, arr);
}

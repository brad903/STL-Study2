#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class BatchSystem{
    public:
        vector<int> schedule(vector<int> duration, vector<string> user){
            vector<int> result;

            map<string, int> WorkTime_all;
            
            // map에 넣음으로써 같은 이름 여러번 나올 때 한 사람단위로 묶어 합을 구할 수 있음
            for(int i=0; i<duration.size(); i++){
                WorkTime_all[user[i]] += duration[i];
            }

            // 정렬하기 위해 pair 이용한 vector 사용하여 합을 우선적으로 비교하고 같으면 이름 사전순으로 정렬   
            vector<pair<int, string>> sorted_people(WorkTime_all.size());
            int i=0;
           for(auto p : WorkTime_all){
               sorted_people[i].first = p.second;
                sorted_people[i].second = p.first;
                i++;
           }
           sort(sorted_people.begin(), sorted_people.end());

            // 정렬된 순서를 토대로 매개변수 user에서 작업 순서 차례대로 받아서 vector에 집어넣음   
            for(int i=0; i<sorted_people.size(); i++){
                for(int j=0; j<user.size(); j++){
                    if(sorted_people[i].second == user[j]){
                        result.push_back(j);
                   }
                }
            }

        return result;
    }
};

int main(){
    // vector<int> duration = {400, 100, 100, 100};
    // vector<string> user = {"DannyMesser", "Stella Bonasera", "Stella Bonasera", "MacTaylor"};

    // vector<int> duration = {200, 200, 200};
    // vector<string> user = {"Gil", "Sarah", "Warrick"};

    vector<int> duration = {100, 200, 50};
    vector<string> user = {"Horatio Caine", "horatio caine", "YEAAAAAH"};

    BatchSystem BS;
    vector<int> ans = BS.schedule(duration, user);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
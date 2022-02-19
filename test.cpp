#include<bits/stdc++.h>

using namespace std;

struct Client{
    string name;
    int payment, timeNeeded, lastTime;
    double paymentPerHour;

    Client(string name, int lastTime, int timeNeeded, int payment){
        this -> name = name;
        this -> lastTime = lastTime;
        this -> timeNeeded = timeNeeded;
        this -> payment = payment;
        paymentPerHour = (double)payment/(double)timeNeeded;
    }

};

typedef struct Client client;


vector<client> maximumPayment(vector<client> &clients){
    sort(clients.begin(), clients.end(), [](client a, client b){
            return a.paymentPerHour > b.paymentPerHour;
    });
    vector<bool> timeAvailability(10, 0);
    vector<client> clientsPicked;
    for(auto c: clients){
        int timeLeft = 0;
        for(int i = c.lastTime; i >= 0; i--){
            if(!timeAvailability[i]) timeLeft++;
        }
        int requiredTime = c.timeNeeded;
        if(timeLeft > c.timeNeeded){
            for(int i = c.lastTime; requiredTime; i--){
                if(!timeAvailability[i]){
                    timeAvailability[i] = true;
                    requiredTime--;
                }
            }
            clientsPicked.push_back(c);
        }
    }
    return clientsPicked;

}

int main(){
    //freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<client> clients;

    for(int i = 0; i < n; i++){
        string name; cin >> name;
        int lastTime; cin >> lastTime;
        int timeNeeded; cin >> timeNeeded;
        int payment; cin >> payment;
        clients.push_back(client(name, lastTime, timeNeeded, payment));
    }

    vector<client> clientsPicked = maximumPayment(clients);
    int payment = 0;
    for(int i = 0; i < clientsPicked.size(); i++){
        cout << clientsPicked[i].name;
        if(i < clientsPicked.size()-1) cout << ", ";
        else cout << endl;
        payment += clientsPicked[i].payment;
    }
    cout << payment << endl;
}
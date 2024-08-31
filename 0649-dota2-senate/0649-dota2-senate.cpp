class Solution {
public:
    string predictPartyVictory(string senate) {
    queue<int> radiant, dire;
    int n = senate.size();

    // Initialize queues with indices of senators
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }

    // Simulate the rounds
    while (!radiant.empty() && !dire.empty()) {
        int r_index = radiant.front();
        int d_index = dire.front();
        radiant.pop();
        dire.pop();

        // The senator with the smaller index gets to ban the other senator
        if (r_index < d_index) {
            radiant.push(r_index + n);  // Radiant bans Dire and goes to the end of the queue
        } else {
            dire.push(d_index + n);  // Dire bans Radiant and goes to the end of the queue
        }
    }

    // Determine the winner
    return radiant.empty() ? "Dire" : "Radiant";
    }
};
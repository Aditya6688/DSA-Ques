class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        if (!geneBank.count(endGene)) return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        while (!q.empty()) {
            auto [currGene, steps] = q.front();
            q.pop();

            if (currGene == endGene) return steps;

            for (int i = 0; i < 8; ++i) {
                string mutated = currGene;
                for (char ch : {'A', 'C', 'G', 'T'}) {
                    if (mutated[i] == ch) continue;
                    mutated[i] = ch;
                    if (geneBank.count(mutated) && !visited.count(mutated)) {
                        visited.insert(mutated);
                        q.push({mutated, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
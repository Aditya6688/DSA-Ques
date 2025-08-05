class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string token;
        stringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") {
                // skip empty parts and current directory
                continue;
            } else if (token == "..") {
                if (!stk.empty()) stk.pop_back(); // go up one directory if possible
            } else {
                // normal directory name (includes "..." or "...." etc.)
                stk.push_back(token);
            }
        }

        if (stk.empty()) return "/";

        string res;
        for (const auto &dir : stk) {
            res += "/" + dir;
        }
        return res;
    }
};
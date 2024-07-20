class Solution {
public:
    static bool compare(string &a,string &b){
        //find the content from both the strings.
        string substr1 = string(a.begin() + a.find(' '), a.end());
        string substr2 = string(b.begin() + b.find(' '), b.end());
		//if both are equal, sort with identifiers,else with content.
        return (substr1 == substr2) ? a < b : substr1 < substr2;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int count = 0;
        int index = logs.size()-1;
		//First calculate the number of letter logs and partition the vector.
		//The reason for why we are starting from reverse is because we don't care about relative ordering of letter logs,
		//however we want digit logs in relative order and also they must be at the rear.
        for(int i = logs.size() - 1 ; i >= 0 ; i--)
        {
            int pos = logs[i].find(' ');
			//if it is digit then swap and decrease the index.
            if(isdigit(logs[i][pos+1]))
                swap(logs[index--],logs[i]);
			//increase count.
            else
                count++;
        }
		//we sort only the letter logs which are at the front.
        sort(logs.begin(),logs.begin()+count,compare);
        return logs;
        
    }
};
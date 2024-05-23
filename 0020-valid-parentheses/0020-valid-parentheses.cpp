class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> brackets = {{'[',-3},{'{',-2},{'(',-1},{')',1},{'}',2},{']',3},};
        stack<char> st;
        for(auto br : s){
            if(brackets[br] < 0){
                st.push(br);
            }
            else{
                if(st.empty()){
                    return false;
                    break;
                }
                else{
                    char top = st.top();
                    st.pop();
                    if(brackets[top] + brackets[br] != 0){
                        return false;
                        break;
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
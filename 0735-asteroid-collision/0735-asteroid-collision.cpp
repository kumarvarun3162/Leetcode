class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int x : asteroids) {

            while (!st.empty() && st.back() > 0 && x < 0) {

                if (st.back() < -x) {
                    st.pop_back();
                    continue;
                }

                if (st.back() == -x) {
                    st.pop_back();
                }

                x = 0;
                break;
            }

            if (x != 0)
                st.push_back(x);
        }

        return st;
    }
};
#include <iostream>
#include <stack>
int main()
{
    int N,result=0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::stack<char> st;
        std::string str;
        std::cin >> str;
        for (int i = 0; i != str.length(); i++)
        {
            if (st.empty())
                st.push(str[i]);
            else
            {
                if (str[i] == st.top())
                    st.pop();
                else
                    st.push(str[i]);
            }
        }
        if (st.empty()) result++;
    }
    std::cout << result;
}

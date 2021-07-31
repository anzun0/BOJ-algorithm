#include <iostream>
#include <deque>
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    std::deque<int> deq;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        if (str == "push_front")
        {
            int X;
            std::cin >> X;
            deq.push_front(X);
        }
        else if (str == "push_back")
        {
            int X;
            std::cin >> X;
            deq.push_back(X);
        }
        else if (str == "pop_front")
        {
            if (deq.empty()) std::cout << "-1\n";
            else
            {
                std::cout << deq.front()<<'\n';
                deq.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (deq.empty()) std::cout << "-1\n";
            else
            {
                std::cout << deq.back()<<'\n';
                deq.pop_back();
            }
        }
        else if (str == "size") std::cout << deq.size()<<'\n';
        else if (str == "empty")
        {
            if (deq.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (str == "front")
        {
            if (deq.empty()) std::cout << "-1\n";
            else std::cout << deq.front()<<'\n';
        }
        else if (str == "back")
        {
            if (deq.empty()) std::cout << "-1\n";
            else std::cout << deq.back()<<'\n';
        }
    }
}

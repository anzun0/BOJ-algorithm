#include <iostream>
#include <utility>
int arr[1000000];
int tmp[1000000];
void merge(int st, int ed)
{
    int mid = (st + ed) / 2;
    int idx = st;
    int idx1 = st;
    int idx2 = mid;

    while (idx1 < mid && idx2 < ed)
    {
        if (arr[idx1] < arr[idx2])
            tmp[idx++] = arr[idx1++];
        else
            tmp[idx++] = arr[idx2++];
    }
    while (idx1 < mid)
        tmp[idx++] = arr[idx1++];
    while (idx2 < ed)
        tmp[idx++] = arr[idx2++];
    for (int i = st; i < ed; i++) arr[i] = tmp[i];
}
void merge_sort(int st, int ed)
{
    if (ed - st == 1) return;
    if (ed - st == 2)
    {
        if (arr[st] > arr[st+1])
            std::swap(arr[st], arr[st+1]);
        return;
    }
    int mid = (st + ed) / 2;
    merge_sort(st, mid);
    merge_sort(mid, ed);
    merge(st, ed);
}

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    merge_sort(0, N);

    for (int i = 0; i < N; i++)
        std::cout << arr[i] << '\n';
}

class Solution {
public:
    int search(vector<int>& a, int key) {
        int n = a.size();

        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (a[mid] == key)
            {
                return mid;
            }

            if (a[s] <= a[mid])
            {
                if (a[s] <= key && a[mid] > key)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (key <= a[e] && key > a[mid])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }

        return -1;
    }
};
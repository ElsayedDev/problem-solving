class Solution
{
public:
    int sumOfEncryptedInt(vector<int> &nums)
    {

        // if nums[i] is more than 10 convert it to make digits ex: 1235 -> 5555
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 10)
            {
                nums[i] = convertNumberToMaxSameDigits(nums[i]);
            }
        }

        // print nums
        for (auto element : nums)
            cout << element << " ";
        cout << endl;

        // int sum = 0;
        // for (auto element : nums)
        //     sum += element;
        // return sum;
    }

    int convertNumberToMaxSameDigits(int n)
    {
        int number = mxDigits(n), res = 0, fact = 1;

        while (n / 10 > 0)
        {
            res = res + number * fact;
            fact = fact * 10;
            n = n / 10;
        }
        return res + number * fact;
    }

    int mxDigits(int n)
    {
        int largest = 0;

        while (n)
        {
            int r = n % 10;

            // Find the largest digit
            largest = max(r, largest);

            n = n / 10;
        }
        return largest;
    }
};
// 1 / 10
/*
    if (root!=NULL ) return 0;

        if (target == root->val) return 1;

        if (root->left ==NULL && root->right ==NULL) return 0;


        return  dfs(root->left,target-root->val) + dfs(root->right,target-root->val);
 */

int main()
{
    Solution sol = Solution();
    vector<int> nums = {10,21,36};
    sol.sumOfEncryptedInt(nums);

    return 0;
}

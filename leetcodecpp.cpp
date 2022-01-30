// leetcodecpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
//13.rome convert to integer
int romeconvert(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'V') {
            sum += 4;
            i++;
            
        }

        else if (s[i] == 'I' && s[i + 1] == 'X') {
            sum += 9;
            i++;
            
        }

        else if (s[i] == 'X' && s[i + 1] == 'L') {
            sum += 40;
            i++;
            
        }

        else if (s[i] == 'X' && s[i + 1] == 'C') {
            sum += 90;
            i++;
            
        }
        else if (s[i] == 'C' && s[i + 1] == 'M') {
            sum += 900;
            i++;
            
        }
        else if (s[i] == 'C' && s[i + 1] == 'D') {
            sum += 400;
            i++;
            
        }

        

        else if (s[i] == 'I') {
            sum += 1;
        }
        else if (s[i] == 'V') {
            sum += 5;
        }
        else if (s[i] == 'X') {
            sum += 10;
        }
        else if (s[i] == 'L') {
            sum += 50;
        }
        else if (s[i] == 'C') {
            sum += 100;
        }
        else if (s[i] == 'D') {
            sum += 500;
        }
        else if (s[i] == 'M') {
            sum += 1000;
        }
    }
    return sum;
}
//14.integer convert to rome
string inttorome(int num){
    string ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    string tens[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
    string hrns[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
    string ths[] = { "","M","MM","MMM" };
    
    return  ths[num / 1000]+ hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

string longestCommonPrefix(vector<string>& strs) {
    int length = strs.size();
    string ans = strs[0];
    for (int i = 1; i < length; i++) {
        int j;
        for (j = 0; j < strs[i].size(); j++) {
            if (ans[j] != strs[i][j]) {
                break;
            }


        }
        ans = ans.substr(0, j);
    }
    return ans;


   
}

//20.isValid to check if the string is a valid parentheses like "(){[]}"
bool isValid(string s) {
    stack<char> st;
    for (char i : s) {
        if (i == '(' || i == '[' || i == '{') {
            st.push(i);
        }
        else {
            if (st.empty() || (st.top() == '(' && i != ')') || (st.top() == '{' && i != '}') || (st.top() == '[' && i != ']')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();


}

//11.to check the maxinum volum of the height list
int maxArea(vector<int>& height) {
    int ans = 0, i = 0, j = height.size() - 1, cur = 0;
    while (i < j) {
        if (height[i] <= height[j]) {
            cur = height[i] * (j - i);
            i++;
        }
        else {
            cur = height[j] * (j - i);
            j--;
        }
        if (ans < cur) {
            ans = cur;
        }
        
    }
    return ans;
}

//110.check the height of a tree
int treeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + (max(treeHeight(root->left), treeHeight(root->right)));
}
//110.to check if the tree is a balanced tree 
bool isBalancedTree(TreeNode* root) {
    if (root == NULL) {
        return true;

    }
    return (abs(treeHeight(root->left) - treeHeight(root->right))) <= 1 && isBalancedTree(root->left)&& isBalancedTree(root->right);
}

//1.two sum question
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
            }

        }
    }
    return result;
}
// 1893 is covered Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
//Output: true
bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    for (int i = left; i <= right; ++i) {
        bool flag = false;
        for (const auto& range : ranges) {
            if (i >= range[0] and i <= range[1]) {
                flag = true;
                break;
            }
        }
        if (flag == false) return false;
    }
    return true;
}

//21. merge two sorted lists
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }

}
//26. remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    vector<int> thenum;
    thenum.push_back(nums[1]);
    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i] != nums[i + 1]) {
            
            thenum.push_back(nums[i+1]);
            
        }
    }
    for (int j = thenum.size()-1; j >= 0 ; j--) {
        nums.insert(nums.begin(),thenum[j]);
    }
    nums.resize(thenum.size());
    
    return thenum.size();

}
//121. Best time to buy and sell stock
int maxProfit(vector<int>& prices) {
    int profit = 0, min = INT_MAX;
    for (int i = 0; i < prices.size(); i++) {
        if (min > prices[i]) {
            min = prices[i];
        }
        if (min < prices[i]) {
            profit = max(profit, (prices[i] - min));
        }
    }
    return profit;

}


//swap sort
int swapsort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            swap(nums[i], nums[i + 1]);
                for (int j = i + 1; j >= 1; j--) {
                    if (nums[j] < nums[j - 1]) {
                        swap(nums[j], nums[j - 1]);
                    }
                }
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;

}
bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            swap(nums[i], nums[i + 1]);
            for (int j = i + 1; j >= 1; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }
    }
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    return false;

}
//given a list, return max of sum of the subarray
int maxSubArray(vector<int>& nums) {
    int max = INT_MIN, cursum = 0;
    for (int i = 0; i < nums.size(); i++) {
        cursum += nums[i];
        if (cursum > max) {
            max = cursum;
        }
        if (cursum < 0) {
            cursum = 0;
        }
    }
    return max;
}

// given a list return the list production of all other element
vector<int> productExceptSelf(vector<int>& nums) {
    int max =1 , zero = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            max *= nums[i];
        }
        else {
            zero++;
        }
    }
    cout << max << endl;

    if (zero == 0) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = max / nums[i];
        }
    }
    if (zero == 1) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = max;
            }
            else {
                nums[i] = 0;
            }

        }
    }
    if (zero >= 2) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = 0;
        }

    }

    return nums;
}


//152 maximum product subarray, given a list, return the maximum production number
int maxProduct(vector<int>& nums) {
    int curmin = nums[0];
    int curmax = nums[0];
    int maxP = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(curmax, curmin);
        }
        curmax = max(nums[i], curmax * nums[i]);
        curmin = min(nums[i], curmin * nums[i]);
        maxP = max(maxP, curmax);

    }

    return maxP;

}
//153 find minimum in rotated sorted array
int findMin(vector<int>& nums) {
    int prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (prev > nums[i]) {
            return nums[i];
        }
        else {
            prev = nums[i];
        }

    }
    return nums[0];

}
int search(vector<int>& nums, int target) {
    int prev = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i]) {
            return i;
            cout << i << endl;

        }


    }
    return -1;
}

    //226. invert binary tree
    TreeNode* invertTree(TreeNode * root) {
        if (!root) {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;

    }

    // 70. climbing stairs i=1,o=1  i=2,o=2   i=3,o=3    i=4 o=5;
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int pre = 2, pre2 = 1;
        int cur = 0;
        for (int i = 3; i <= n; i++) {
            cur = pre + pre2;
            pre2 = pre;
            pre = cur;

        }
        return cur;
    }

    //322. dynamic programming Coin Change given a list of coin types [1,3,5]... and amount = 10, 
    //return the min coins that combine to that amount
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
            for (int c : coins)
                if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
        return dp[amount] > amount ? -1 : dp[amount];

    }

    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }

        int count = 0;
        int index = -1;

        for (int i = 0; i < haystack.length(); i++) {
            if (needle[0] == haystack[i]) {
                index = i;
                break;
            }

        }

        if (index == -1) {
            return index;
        }
        for (int i = index + 1; i < needle.length() + index; i++) {
            
            if (haystack[i] != needle[i]) {
                return -1;
                
            }
        }
        
        return index;



    }

    //112. path sum, given a root of binary tree and target integer, return boolean value if one path can sum
    //to the target
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }

    //136 single number, Given a non-empty array of integers nums, every element appears twice except for one. 
    //Find that single one.
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int size = nums.size();
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[size - 1] != nums[size - 2]) {
            return nums[size - 1];
        }
        for (i; i < nums.size() - 2; i++) {
            if (nums[i] != nums[i + 1] && nums[i + 1] != nums[i + 2]) {
                break;
            }
        }
        return nums[i + 1];

    }

    //94 B tree inorer traversal 
    void helper(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL)
        {
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;

    }
    //// two sum in a sorted array
    //vector<int> twoSum(vector<int>& numbers, int target) {
    //    int i = 0;
    //    int j = numbers.size() - 1;
    //    while (i < j) {
    //        int sum = numbers[i] + numbers[j];
    //        if (sum == target) {
    //            return { i + 1,j + 1 };
    //        }
    //        if (sum > target) {
    //            j--;
    //        }
    //        else {
    //            i++;
    //        }
    //    }
    //    return {};

    //}

    //169. Majority element 
    int majorityElement1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    int majorityElement2(vector<int>& nums) {
        // Initialize count variable to count the occurrence and ele variable to keep track of element which is being counted
        int count = 0;
        int ele = 0;


        for (int i = 0; i < nums.size(); i++) {
            // if count is 0 then assign the current element to ele variable
            if (count == 0) {
                ele = nums[i];
            }
            // if nums[i] equals to ele then increase the count or else decrease
            if (ele == nums[i]) {
                count += 1;
            }
            else {
                count -= 1;
            }
        }

        return ele;
    }

    //203 remove linked list elements
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;

    }
int cProducts(set<int>& a, set<int>& b, tuple<int,int>& c) {
    try {
        int x = get<0>(c);
        int y = get<1>(c);
        int index = x * b.size() + y;
        return index;

    }
    catch (int x) {
        return -1;
    }
   

    }
//234. Palindrome Linked List Given the head of a singly linked list, return true if it is a palindrome.
class Solution234 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, * curr = head, * temp = NULL;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* findMind(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

        }
        return slow;
    }
    bool compare(ListNode* h1, ListNode* h2) {
        while (h1 != NULL && h2 != NULL) {
            if (h1->val != h2->val) {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* mid = findMind(head);
        ListNode* reversedL = reverseList(mid);
        return compare(head, reversedL);



    }
};
double getHitProbability(int R, int C, vector<vector<int>> G) {
    // Write your code here
    double value;
    double count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; i++) {
            if (G[i][j] == 1) {
                count += 1;
            }
        }
    }
    value = count / R * C;
    return value;
}

//566 reshape the Matrix 
vector<vector<int>> matrixReshape(vector<vector<int>> mat, int r, int c) {
    int length = 0;
    for (auto& m1 : mat) {
        for (auto& m2 : m1) {
            length++;
        }
    }
    if (r * c > length) {
        return mat;
    }
    vector<vector<int>> ans;
    vector<int> temp;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (temp.size() == c) {
                ans.push_back(temp);
                cout << "checl" << endl;
                temp.resize(0);
            }
            else if (temp.size() < c) {
                temp.push_back(mat[i][j]);
            }
        }

    }
    
    return ans;
}
int main()
{
    std::cout << "Hello World!\n";
    string s = "MCMXCIV";
    cout << romeconvert(s) << endl;
    vector<string> vec;
    vec.push_back("www");
    vec.push_back("wwwww");
    cout << longestCommonPrefix(vec) << endl;
    string ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    cout << inttorome(90) << endl;
    
    vector<int> vec1 = { 1, 1, 2, 2, 3, 4, 5, 5,5,6 };
    vector<int> vec2 = { 1,2,3,1 };
    //cout << removeDuplicates(vec1) << endl;
    //swapsort(vec2);
    vector <int> list1 = { 1,2,3,4 };
    vector<int> list2 = { 4,5,6,7,0,1,2 };
    productExceptSelf(list1);
    cout << search(list2, 0) << endl;
    //cout<< strStr("hello", "ll")<<endl;
    vector<int> ans;
    ans = vector<int>(5, 2);
    cout << ans[4] << endl;
    set<int> s1 = { 1,2,3 };
    set<int> s2 = { 2,3 };
    tuple<int, int> c = { 1, 1 };
    cout << cProducts(s1, s2, c) << endl;
    cout << getHitProbability(2, 3, { {1,1,0},{0,0,1} }) << endl;
    vector<vector<int>> a = matrixReshape({ {1,2},{3,4} }, 1, 4);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
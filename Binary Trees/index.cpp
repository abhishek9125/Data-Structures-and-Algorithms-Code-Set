#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Pair
{
public:
    int height;
    int diameter;
};

class HBPair
{
public:
    bool isBalanced;
    int height;
};

node *buildTree(node *root)
{

    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

    return;
}

void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);

    return;
}

void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";

    return;
}

void buildTreeIterative(node *&root)
{
    queue<node *> q;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void countOfLeafNodes(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        count++;
    }

    countOfLeafNodes(root->left, count);
    countOfLeafNodes(root->right, count);
    return;
}

int heightOfTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return 1 + max(left, right);
}

int diameterOfTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = diameterOfTree(root->left);
    int option2 = diameterOfTree(root->right);
    int option3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    return max(option1, max(option2, option3));
}

Pair diameterOfTreeOptimised(node *root)
{

    Pair p;
    if (root == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair left = diameterOfTreeOptimised(root->left);
    Pair right = diameterOfTreeOptimised(root->right);

    p.height = 1 + max(left.height, right.height);
    p.diameter = max(left.height + right.height + 1, max(left.diameter, right.diameter));

    return p;
}

bool isTreeHeightBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isTreeHeightBalanced(root->left);
    bool right = isTreeHeightBalanced(root->right);

    if ((abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1) && left && right)
    {
        return true;
    }

    return false;
}

HBPair isTreeHeightBalancedOptimised(node *root)
{
    HBPair p;

    if (root == NULL)
    {
        p.isBalanced = true;
        p.height = 0;
        return p;
    }

    HBPair left = isTreeHeightBalancedOptimised(root->left);
    HBPair right = isTreeHeightBalancedOptimised(root->right);

    p.height = 1 + max(left.height, right.height);

    if (left.isBalanced && right.isBalanced && (abs(left.height - right.height) <= 1))
    {
        p.isBalanced = true;
    }
    else
    {
        p.isBalanced = false;
    }

    return p;
}

bool areTreesIdentical(node *root1, node *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }

    bool left = areTreesIdentical(root1->left, root2->left);
    bool right = areTreesIdentical(root1->right, root2->right);

    if (left && right && root1->data == root2->data)
    {
        return true;
    }

    return false;
}

pair<bool, int> isSumTreeFast(node *root)
{

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    pair<bool, int> ans;

    if (left.first && right.first && (root->data == left.second + right.second))
    {
        ans.first = true;
        ans.second = root->data + left.second + right.second;
    }
    else
    {
        ans.first = false;
        ans.second = 0;
    }

    return ans;
}

vector<int> zigZagLevelOrderTraversal(node *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    bool rightToLeft = false;
    vector<int> temp;

    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {

            if (rightToLeft)
            {
                reverse(temp.begin(), temp.end());
            }

            for (auto i : temp)
            {
                result.push_back(i);
            }

            rightToLeft = !rightToLeft;

            temp.clear();

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            temp.push_back(frontNode->data);
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }

    return result;
}

void traverseLeft(node *root, vector<int> &result)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    result.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, result);
    }
    else
    {
        traverseLeft(root->right, result);
    }
    return;
}

void traverseLeafNodes(node *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        result.push_back(root->data);
        return;
    }

    traverseLeafNodes(root->left, result);
    traverseLeafNodes(root->right, result);
}

void traverseRight(node *root, vector<int> &result)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, result);
    }
    else
    {
        traverseRight(root->left, result);
    }
    result.push_back(root->data);

    return;
}

vector<int> boundary(node *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    result.push_back(root->data);

    traverseLeft(root->left, result);
    traverseLeafNodes(root->left, result);
    traverseLeafNodes(root->right, result);
    traverseRight(root->right, result);

    return result;
}

vector<int> verticalOrder(node *root)
{

    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                result.push_back(k);
            }
        }
    }

    return result;
}

vector<int> topView(node *root)
{

    vector<int> result;

    if (!root)
    {
        return result;
    }

    map<int, int> nodes;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int distance = temp.second;

        if (nodes.find(distance) == nodes.end())
        {
            nodes[distance] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, distance - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, distance + 1));
        }
    }

    for (auto i : nodes)
    {
        result.push_back(i.second);
    }

    return result;
}

vector<int> bottomView(node *root)
{

    vector<int> result;

    if (!root)
    {
        return result;
    }

    map<int, int> nodes;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int distance = temp.second;

        nodes[distance] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, distance - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, distance + 1));
        }
    }

    for (auto i : nodes)
    {
        result.push_back(i.second);
    }

    return result;
}

vector<int> leftView(node *root)
{

    vector<int> result;

    if (!root)
    {
        return result;
    }

    map<int, int> nodes;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {

        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int level = temp.second;

        if (nodes.find(level) == nodes.end())
        {
            nodes[level] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, level + 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, level + 1));
        }
    }

    for (auto i : nodes)
    {
        result.push_back(i.second);
    }

    return result;
}

vector<int> righView(node *root)
{

    vector<int> result;

    if (!root)
    {
        return result;
    }

    map<int, int> nodes;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {

        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int level = temp.second;

        nodes[level] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, level + 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, level + 1));
        }
    }

    for (auto i : nodes)
    {
        result.push_back(i.second);
    }

    return result;
}

void sumOfLongRootToLeafPathHelper(node *root, int sum, int &maxSum, int len, int &maxLen)
{

    if (root == NULL)
    {

        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sumOfLongRootToLeafPathHelper(root->left, sum + root->data, maxSum, len + 1, maxLen);
    sumOfLongRootToLeafPathHelper(root->right, sum + root->data, maxSum, len + 1, maxLen);

    return;
}

int sumOfLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    sumOfLongRootToLeafPathHelper(root, sum, maxSum, len, maxLen);

    return maxSum;
}

node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *leftAns = lca(root->left, n1, n2);
    node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    node *root = NULL;
    node *root2 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1
    buildTreeIterative(root2);
    cout << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);
    cout << "Preorder Traversal : ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal : ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal : ";
    postOrderTraversal(root);
    cout << endl;
    int count = 0;
    countOfLeafNodes(root, count);
    Pair getDiameter = diameterOfTreeOptimised(root);
    HBPair getBalancedTree = isTreeHeightBalancedOptimised(root);
    pair<bool, int> checkSumTree = isSumTreeFast(root);
    bool isTreeBalanced = getBalancedTree.isBalanced;
    cout << "Count of Leaf Nodes : " << count << endl;
    cout << "Height of Tree : " << heightOfTree(root) << endl;
    // cout << "Sum of All Tree Nodes : " << nodeSumOfTree(root) << endl;
    cout << "Diameter of Binary Tree : " << diameterOfTree(root) << endl;
    cout << "Diameter of Binary Tree Optimised Approach : " << getDiameter.diameter << endl;
    isTreeHeightBalanced(root) ? cout << "Tree is Balanced" << endl : cout << "Tree Is Not Balanced" << endl;
    isTreeBalanced ? cout << "Tree is Balanced by Optimisation" << endl : cout << "Tree Is Not Balanced by Optimisation" << endl;
    areTreesIdentical(root, root2) ? cout << "Trees Are Identical" << endl : cout << "Trees Are Different" << endl;
    checkSumTree.first ? cout << "Tree is Sum Balanced" << endl : cout << "Tree Is Not Sum Balanced" << endl;
    vector<int> zigZagTraversal = zigZagLevelOrderTraversal(root);
    cout << "Zig Zag Level Order Traversal : ";
    for (auto i : zigZagTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> boundaryTraversal = boundary(root);
    cout << "Boundary Traversal : ";
    for (auto i : boundaryTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> verticalTraversal = verticalOrder(root);
    cout << "Vertical Traversal : ";
    for (auto i : verticalTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> topViewTraversal = topView(root);
    cout << "Top View Traversal : ";
    for (auto i : topViewTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> bottomViewTraversal = bottomView(root);
    cout << "Bottom View Traversal : ";
    for (auto i : bottomViewTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> leftViewTraversal = leftView(root);
    cout << "Left View Traversal : ";
    for (auto i : leftViewTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> rightViewTraversal = rightView(root);
    cout << "Right View Traversal : ";
    for (auto i : rightViewTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Root To Leaf Longest Path Node Sum : " << sumOfLongRootToLeafPath(root) << endl;
    // cout << "Maximum Sum of Non Adjacent Nodes : " << getMaxSumForNonAdjacentNodes(root) << endl;
    // pathsHavingTargetSum
    // lowestCommonAncestor
    // buildTreeFromInorderAndPreorder
    // buildTreeFromInorderAndPostorder
    // minTimeToBurnTree
    // flattenBinaryTreeToLinkedList
    return 0;
}

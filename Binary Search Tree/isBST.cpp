//Solution to https://www.hackerrank.com/challenges/is-binary-search-tree

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/


struct BSTChkWithMinMax
{
    bool isBST;
    int min;
    int max;
    BSTChkWithMinMax()
    {
        isBST = true;
        min = 0 - 2147483647 - 1;
        max = 2147483647;
    }
};    

bool checkBST(Node* root) 
{
    bool isBST = checkBST_WithRoot(root).isBST;
    return isBST;
}


BSTChkWithMinMax checkBST_WithRoot(Node* root)
{
    BSTChkWithMinMax retVal;
    if(root!=nullptr)
    {
        if(root->left==nullptr && root->right==nullptr)
        {
            retVal.min = root->data;
            retVal.max = root->data;
            retVal.isBST = true;
        }
        else
        {
            if(root->left!=nullptr)
            {
                auto BSTChkForLeft = checkBST_WithRoot(root->left);
                if( BSTChkForLeft.isBST 
                   && root->data>BSTChkForLeft.max)
                {
                    retVal.isBST = true;
                    retVal.min = BSTChkForLeft.min;
                }
                else
                {
                    retVal = BSTChkWithMinMax();
                    retVal.isBST = false;
                    return retVal;
                }
            }
            
            
            if(root->right!=nullptr)
            {
                auto BSTChkForRight = checkBST_WithRoot(root->right);
                if( BSTChkForRight.isBST 
                   && root->data<BSTChkForRight.min)
                {
                    retVal.isBST = true;
                    retVal.max = BSTChkForRight.max;
                }
                else
                {
                    retVal = BSTChkWithMinMax();
                    retVal.isBST = false;
                    return retVal;
                }
            }

        }
    }
    return retVal;
}

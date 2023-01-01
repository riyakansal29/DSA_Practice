#include <iostream>

using namespace std;

struct node{
  int val;
  node *left;
  node *right;
};

class tree{
  public:
  node *root;
  tree(int value){
    root = new node;
    root->val = value;
    root->left = NULL;
    root->right = NULL;
  }
  node * insertnode(node *root, int value);
  void inordertraversal(node *root);
};

node * tree::insertnode(node *root, int value){
  if(root == NULL){
    root = new node;
    root->val = value;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  else if(root->left==NULL)
    root->left = insertnode(root->left, value);
  else if(root->right == NULL)
    root->right = insertnode(root->right, value);
  else{
    root->left = insertnode(root->left, value);
  }
  return root;
}

void tree::inordertraversal(node * root){
  if(root == NULL) return;
  inordertraversal(root->left);
  cout<<root->val<< " ";
   inordertraversal(root->right);
}

int main(){
  tree a(4);
  
  a.root = a.insertnode(a. root, 5);
  a.root = a.insertnode(a. root, 6);
  a.root = a.insertnode(a. root, 7);
   a.root = a.insertnode(a. root, 8);
    a.root = a.insertnode(a. root, 9);
     a.root = a.insertnode(a. root, 10);
  a.inordertraversal(a.root);
  
}
    /*
                1
               / \
              2   3
             / \   \
            4   5   6
    */



//depth of node
// int finddepth(node *root, int value, int depth){
//   if(root->val == value) return depth;
//   if(root == NULL) return -1;
//   int left = finddepth(root->left, value, depth+1);
//   if(ans != -1) return depth;
//   else{
//       int right = finddepth(root->right, value, depth+1);
//       return right;
//   }

// }




//height of tree/ depth of tree
//  int maxDepth(Node* root) {
//         if(root == NULL) return -1; 
//         int left = maxDepth(root->left);
//         int right = maxDepth(root->right);
//         return 1+max(left, right);
//     }





//height of node
// int heightnode(node *root, int val){
//   node *temp = searchnode(root,val);
//   int height = findheight(temp);
//   return height;
// }




//level order traversal recursive approach 
// void levelorder(node *root, int level, void<int>ans){
//   if(level == 1) ans.push_back(root->val);
//   if(root == NULL) return;
//   levelorder(root->left, level-1, ans);
//   levelorder(root->right, level-1, ans);
// }

// void findlevel(node *root){
//   int height =0;
//   height = findheight(root, height);
//   void<int>ans;
//   for(int i=height;i>=1;i--){
//     levelorder(root, i, ans);
//   }
// }



//left/right view, level = 0
// void<int> view(node *root, void<int> ans, int level){
//   if(root == NULL) return ans;
//   if(ans.size()<level)
//   ans.push_back(root->data);
//   ans = view(root->left, ans, level+1);
//   ans = view(root->right, ans, level+1);
// }

//another approach view
// vector<int> leftView(Node *root)
// {
//     vector<int> ans;
//     if(root == NULL)
//         return ans;
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         int size = q.size();
//         int index = 0;
//         for(int i=1;i<=size;i++){
//             Node *temp = q.front();
//             q.pop();
//             if(index == 0){
//                 ans.push_back(temp->data); 
//                 index = 1;
//             }
//             if(temp->left!=NULL)
//                 q.push(temp->left);
//             if(temp->right!=NULL)
//                 q.push(temp->right);
//         }
//     }
//     return ans;
// }

//bottom/top view
// vector <int> bottomView(Node *root) {
//         vector<int> ans;
//         if(root == NULL)
//             return ans;
//         queue<map<Node*,int>> q;
//         map<int, int> mymap;
        
//         q.push({{root,0}});
//         while(!q.empty()){
//             map<Node*, int> element = q.front();
//             map<Node*,int>::iterator it = element.begin();  
//             q.pop();
//             Node *temp = it->first;
//             int level = it->second;
//             if(temp->left!=NULL)
//                 q.push({{temp->left,level-1}});
//             if(temp->right!=NULL)
//                 q.push({{temp->right, level+1}});
//             mymap[level] = temp->data;
//         }
//         map<int, int>::iterator it1;
//         for(it1=mymap.begin();it1!=mymap.end();){
//             ans.push_back(it1->second);
//             it1++;
//         }
//         return ans;
//     }

//tree path
// bool path(Node *root, int x, vector<int>&ans){
//    ans.push_back(root->data);
//   if(root->data == x)
//     return true;
//   if(root==NULL)
//     return false;
//   if(path(root->left,x,ans)==true||path(root->right,x,ans)==true){
//     return true;
//   }
//   else{
//     ans.pop_back();
//     return false;
//   }
// }



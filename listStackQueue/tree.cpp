#include <iostream>
#include <memory>
using namespace std;

template <typename T> class BinaryTree {
   public:
      BinaryTree() : root(nullptr) {}
      ~BinaryTree() {}
      bool isEmpty() const;

      int countNodes() {
         return countNodes(root);
      }

      int inorder2() {
         return inorder2(root);
      }

      int countLevel(int level) {
         return countLevel(root, level);
      }

   private:
      struct Node {
         T item;
         shared_ptr<Node> left;
         shared_ptr<Node> right;
         Node(const T& newItem) : 
            item(newItem), left(nullptr), right(nullptr) {}
         ~Node();
      };
      shared_ptr<Node> root;

      int countNodes(shared_ptr<Node> &node) {
         if (node)
            return 1 + countNodes(node->left) + countNodes(node->right);
         return 0;
      }

      template <typename T> int inorder2(shared_ptr<Node> &node) {
         if (node) {
            int count = inorder2(node->left);
            count++;
            cout << node->item << "\n";
            count += inorder2(node->right);
            return count;
         }
         return 0;
      }

      int countLevel(shared_ptr<Node> &node, int level) {
         if (node && level >= 1) {
            if (level == 1) return 1;
            else 
               return countLevel(node->left, level - 1) +
                  countLevel(node->right, level - 1);
         }
         return 0;
      }
};
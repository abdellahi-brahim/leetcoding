/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var findTilt = function(root) {
    if(root == null) return 0;
    
    let nodeTilt = 0;
    
    if(root.left != null){
        nodeTilt += findTilt(root.left);
        root.val += root.left.val;
    }
    
    if(root.right != null){
        nodeTilt += findTilt(root.right);
        root.val += root.right.val;
    }
    
    return nodeTilt + Math.abs((root.left?.val || 0) - (root.right?.val || 0));;
};

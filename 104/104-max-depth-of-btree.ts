class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
  }
}

function maxDepth(root: TreeNode | null): number {
  return solve(root)
};

function solve(node: TreeNode | null) {
  if (!node) {
    return 0
  }

  const left = maxDepth(node.left)
  const right = maxDepth(node.right)

  return Math.max(left, right) + 1
}

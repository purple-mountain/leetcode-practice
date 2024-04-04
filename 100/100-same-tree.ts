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

function isSameTree(p: TreeNode | null | undefined, q: TreeNode | null | undefined): boolean {
  if (!q && !p) {
    return true
  }

  if (p?.val !== q?.val) {
    return false
  }

  return isSameTree(p?.left, q?.left) && isSameTree(p?.right, q?.right)
}

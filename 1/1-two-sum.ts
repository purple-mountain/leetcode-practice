function twoSum(nums: number[], target: number): number[] | undefined {
  const map = new Map<number, number>()
  for (let i = 0; i < nums.length; i++) {
    const foo = target - nums[i]
    if (map.has(foo)) {
      // @ts-ignore
      return [map.get(foo), i]
    }
    map.set(nums[i], i)
  }
};

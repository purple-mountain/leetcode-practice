function isAnagramWithSorting(s: string, t: string): boolean {
  return s.split('').sort().join('') === t.split('').sort().join('')
};

function isAnagramWithHashMap(s: string, t: string): boolean {
  if (s.length !== t.length) {
    return false;
  }

  const sMap = new Map<string, number>()
  const tMap = new Map<string, number>()

  for (let i = 0; i < s.length; i++) {
    sMap[s[i]] = sMap[s[i]] ? ++sMap[s[i]] : 1
    tMap[t[i]] = tMap[t[i]] ? ++tMap[t[i]] : 1
  }

  for (const key in sMap) {
    if (sMap[key] !== tMap[key]) {
      return false
    }
  }

  return true;
};

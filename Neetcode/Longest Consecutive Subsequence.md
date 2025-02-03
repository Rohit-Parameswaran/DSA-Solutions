# 🚨 Note to Self

**Key Insight:**
Super clever hashmap solution! Tracks consecutive sequences in O(n) without sorting. 
Very elegant algorithmic approach that makes for an interesting interview solution.

# Understanding the Code: Longest Consecutive Sequence

## Intuition
**Hash Map to Store Sequence Lengths**

- The key of `mp` is the number itself.
- The value of `mp[num]` stores the length of the consecutive sequence that `num` belongs to.

## Merging Intervals

- If `num` is already in `mp`, skip it to avoid duplicate processing.
- Otherwise, compute the sequence length:

```cpp
mp[num] = mp[num - 1] + mp[num + 1] + 1
```

- Update the boundaries of the merged sequence:
  - `mp[num - mp[num - 1]] = mp[num]` → Update the start of the sequence
  - `mp[num + mp[num + 1]] = mp[num]` → Update the end of the sequence

## Step-by-Step Execution

### Example
Input:
```cpp
nums = {100, 4, 200, 1, 3, 2}
```

### Processing Steps

1. Insert 100:
   - `mp[100] = 1`
   - Update start and end → `mp[100] = 1`
   - `res = 1`

2. Insert 4:
   - `mp[4] = 1`
   - `mp[4] = 1`
   - `res = 1`

3. Insert 200:
   - `mp[200] = 1`
   - `mp[200] = 1`
   - `res = 1`

4. Insert 1:
   - `mp[1] = 1`
   - `mp[1] = 1`
   - `res = 1`

5. Insert 3:
   - `mp[3] = mp[2] + mp[4] + 1 = 1 + 1 + 1 = 3`
   - `mp[1] = 3, mp[4] = 3`
   - `res = 3`

6. Insert 2:
   - `mp[2] = mp[1] + mp[3] + 1 = 3 + 3 + 1 = 4`
   - `mp[1] = 4, mp[4] = 4`
   - `res = 4`

### Final `mp` State
```ini
mp = {1 → 4, 2 → 4, 3 → 4, 4 → 4, 100 → 1, 200 → 1}
```

### Output
```cpp
4  // The longest sequence is [1,2,3,4]
```

## Complexity Analysis

- Each number is processed once: O(n)
- Hash map operations are O(1) on average
- Overall complexity: O(n)

## Edge Cases

- Empty Input: `nums = {}` → Output: 0
- All Unique Elements, No Consecutive: `nums = {10, 20, 30}` → Output: 1
- Already Consecutive Elements: `nums = {1, 2, 3, 4, 5}` → Output: 5
- Large Inputs with Random Numbers

## Alternative Approach: Sorting

- Sort the array: O(n log n)
- Traverse to find longest sequence: O(n)
- Total Complexity: O(n log n)
- **Drawback**: Sorting takes extra time

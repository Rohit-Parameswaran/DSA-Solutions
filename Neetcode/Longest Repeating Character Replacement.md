> NOTE: Apparently the use of getMajorityFreq is redundant and the algorithm will work without updating max_freq to reflect accurate values. I asked ChatGPT why and this is the explanation it gave. Have to come back to this

**Your Concern**
* In your implementation, you **recalculate** `max_freq` every time you move `l` (left pointer).
* The concern is: **what if** `max_freq` was affected by removing `s[l]`?
  * If `s[l]` was the most frequent character and we decrement its count, the majority frequency might change.
  * If we don't update `max_freq`, we might be **working with a stale value**.

**Key Insight: `max_freq` Only Needs to Be Non-Decreasing**
* `max_freq` **only ever increases** and is **never explicitly decreased**.
* Even if `s[l]` was the most frequent character, removing one occurrence **doesn't necessarily reduce the maximum frequency**.
* The condition for shrinking the window is: \text{(window size)} - \text{max_freq} > k
  * If `max_freq` is outdated, it means the condition might **hold for a slightly longer window** than necessary.
  * This is **fine** because the next time a more frequent character appears, `max_freq` will be updated.

**Why the Editorial Approach Works**
* Instead of recalculating `max_freq` inside the shrinking loop, we **rely on the fact that **`max_freq` is always the highest frequency seen so far.
* If we remove a character that was the previous majority, we don't immediately recalculate because **this doesn't affect our ability to find a valid window**.
* Instead, we just move `l` when needed, and `max_freq` naturally updates when `r` expands.
* This means we might keep an outdated `max_freq` for a few iterations, but it **never causes a false positive**, only a minor delay in shrinking.

**Example Where `max_freq` Stays Outdated But Doesn't Matter**
Consider `s = "AABABBA"`, `k = 1`:

Consider `s = "AABABBA"`, `k = 1`:

| l | r | Window (s[l:r]) | fc Map | max_freq | Condition (r-l+1 - max_freq > k) | Action |
|---|---|----------------|--------|----------|----------------------------------|--------|
| 0 | 0 | "A" | {A:1} | 1 | 0 > 1 (false) | Expand |
| 0 | 1 | "AA" | {A:2} | 2 | 0 > 1 (false) | Expand |
| 0 | 2 | "AAB" | {A:2, B:1} | 2 | 1 > 1 (false) | Expand |
| 0 | 3 | "AABA" | {A:3, B:1} | 3 | 1 > 1 (false) | Expand |
| 0 | 4 | "AABAB" | {A:3, B:2} | 3 | 2 > 1 (true) | Shrink l=1 |
| 1 | 4 | "ABAB" | {A:2, B:2} | 3 (stale!) | 2 > 1 (true) | Shrink l=2 |
| 2 | 4 | "BAB" | {A:1, B:2} | 3 (stale!) | 1 > 1 (false) | Expand |

Even though `max_freq` remains `3`, it **doesn't cause incorrect results** because as soon as a new max appears, it updates.

**Why Your Approach Works But Is Less Efficient**
* Your approach ensures that `max_freq` is **always exact** by recalculating it inside the shrinking loop.
* This guarantees correctness, but it costs an **extra O(26) = O(1) operation per shrink**.
* Since the editorial approach **never decreases **`max_freq`, it avoids unnecessary recalculations while still maintaining correctness.

**Final Takeaway**
The key observation is that keeping an outdated `max_freq` temporarily doesn't break correctness, because the condition still holds and `max_freq` will naturally update when needed.

The editorial approach **avoids unnecessary work** and achieves an optimal O(N) solution. 🚀

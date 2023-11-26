# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/article-views-i/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT DISTINCT author_id AS id FROM Views
WHERE author_id = viewer_id
order by author_id;
```

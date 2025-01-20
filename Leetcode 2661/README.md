<h1 ><a href = "https://leetcode.com/problems/first-completely-painted-row-or-column/description/">2661. First Completely Painted Row or Column </a></h1>
<div><div class="elfjS" data-track-load="description_content"><p>You are given a <strong>0-indexed</strong> integer array <code>arr</code>, and an <code>m x n</code> integer <strong>matrix</strong> <code>mat</code>. <code>arr</code> and <code>mat</code> both contain <strong>all</strong> the integers in the range <code>[1, m * n]</code>.</p>

<p>Go through each index <code>i</code> in <code>arr</code> starting from index <code>0</code> and paint the cell in <code>mat</code> containing the integer <code>arr[i]</code>.</p>

<p>Return <em>the smallest index</em> <code>i</code> <em>at which either a row or a column will be completely painted in</em> <code>mat</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="image explanation for example 1"><img alt="image explanation for example 1" src="https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg" style="width: 321px; height: 81px;">
<pre><strong>Input:</strong> arr = [1,3,4,2], mat = [[1,4],[2,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="image explanation for example 2" src="https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg" style="width: 601px; height: 121px;">
<pre><strong>Input:</strong> arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The second column becomes fully painted at arr[3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n = mat[i].length</code></li>
	<li><code>arr.length == m * n</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], mat[r][c] &lt;= m * n</code></li>
	<li>All the integers of <code>arr</code> are <strong>unique</strong>.</li>
	<li>All the integers of <code>mat</code> are <strong>unique</strong>.</li>
</ul>
</div></div>


Solution C++
```CPP
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int mn = arr.size();
        vector<int>newArr(mn);
        for(int i = 0; i < mn; i++) newArr[arr[i]-1] = i;
        int m = mat.size();
        int n = mat[0].size();
        vector<int>row(m , 0);
        vector<int>col(n , 0);

        for(int  i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                int index = newArr[mat[i][j] -1];
                row[i] = max(index , row[i]);
                col[j] = max(index , col[j]);
            }
        }
        int result = INT_MAX;

        for(int i = 0; i < m ; i++){
            result = min(result , row[i]);
        }
        for(int i = 0; i < n ; i++){
            result = min(result , col[i]);
        }
        return result;
        
    }
};
```

Solution JavaScript
```JavaScript
/**
 * @param {number[]} arr
 * @param {number[][]} mat
 * @return {number}
 */
var firstCompleteIndex = function(arr, mat) {
    let mn = arr.length
    let newArr = new Array(mn).fill(0)
    for(let i = 0; i < mn ; i++) newArr[arr[i] - 1] = i;
    let m = mat.length
    let n = mat[0].length
    let row = new Array(m).fill(0);
    let col = new Array(n).fill(0);

    for(let i = 0; i < m ; i++){
        for(let j = 0; j < n ; j++){
            let index = newArr[mat[i][j]-1];
            row[i] = Math.max(row[i] , index);
            col[j] = Math.max(col[j] , index);
        }
    }

    let result = Math.min(...col ,...row)
    return result;
    
};
```

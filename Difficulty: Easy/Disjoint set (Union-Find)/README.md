<h2><a href="https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1">Disjoint set (Union-Find)</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>par[]</strong>&nbsp;that stores all number from <strong>1</strong> to <strong>n</strong> (both inclusive and sorted) and <strong>k</strong> queries.</span></p>
<p><span style="font-size: 18px;">The task is to do the following operations on array elements :</span></p>
<p><span style="font-size: 18px;">1.&nbsp;<strong>UNION</strong> x z : Perform union of <strong>x</strong> and <strong>z</strong> i.e. parent of <strong>z</strong> will become the parent of <strong>x</strong>.<br>2.&nbsp;<strong>FIND</strong> x: Find the ultimate parent of <strong>x</strong> and print it.</span></p>
<p><span style="font-size: 18px;"><strong>Note</strong>: Initially all are the parent of themselves.T</span><span style="color: #001d35; font-family: 'Google Sans', Roboto, 'Helvetica Neue', Arial, sans-serif; font-size: 18px; background-color: #ffffff;">he ultimate parent is the topmost node such that par[node]=node.</span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 5, k = 4, queries[] = {{find 4}, {find 1}, {unionSet 3 1}, {find 3}}
<strong>Output: </strong>4 1 1
<strong>Explanation:</strong>
1. The parent of 4 is 4. Hence the output is 4.
2. The parent of 1 is 1. Hence the output is 1.
3. After performing unionSet 3 1, parent of 3 becomes 1, since, parent of 1 is currently 1 itself.
4. The parent of 3 is now 1. Hence, the output is 1.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n,k &lt;= 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>union-find</code>&nbsp;<code>Algorithms</code>&nbsp;
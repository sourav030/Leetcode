<h2><a href="https://www.geeksforgeeks.org/problems/is-sudoku-valid4820/1">Is Sudoku Valid</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an&nbsp;incomplete Sudoku&nbsp;configuration in terms of a 9x9 &nbsp;2-D square matrix(<strong>mat[][]</strong>)&nbsp;the task to check if the current configuration is valid or not where a 0 represents an empty block.<br><strong>Note:</strong> Current valid configuration does not ensure validity of the final solved sudoku.&nbsp;<br></span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat[][] = [
[3, 0, 6, 5, 0, 8, 4, 0, 0]
[5, 2, 0, 0, 0, 0, 0, 0, 0]
[0, 8, 7, 0, 0, 0, 0, 3, 1]
[0, 0, 3, 0, 1, 0, 0, 8, 0]
[9, 0, 0, 8, 6, 3, 0, 0, 5]
[0, 5, 0, 0, 9, 0, 6, 0, 0]
[1, 3, 0, 0, 0, 0, 2, 5, 0]
[0, 0, 0, 0, 0, 0, 0, 7, 4]
[0, 0, 5, 2, 0, 6, 3, 0, 0]
]
<strong>Output:</strong> true
<strong>Explaination:</strong> It is possible to have aproper sudoku.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat[][] = [
[3, 0, 3, 5, 0, 8, 4, 0, 0]
[5, 2, 0, 0, 0, 0, 0, 0, 0]
[0, 8, 7, 0, 0, 0, 0, 3, 1]
[0, 0, 3, 0, 1, 0, 0, 8, 0]
[9, 0, 0, 8, 6, 3, 0, 0, 5]
[0, 5, 0, 0, 9, 0, 6, 0, 0]
[1, 3, 0, 0, 0, 0, 2, 5, 0]
[0, 0, 0, 0, 0, 0, 0, 7, 4]
[0, 0, 5, 2, 0, 6, 3, 0, 0]
]
<strong>Output:</strong> false
<strong>Explaination:</strong> It is not possible to have aproper sudoku.<br></span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat[][] = [
[2, 0, 2, 5, 0, 8, 4, 0, 0]
[5, 2, 0, 0, 0, 0, 0, 0, 0]
[0, 8, 7, 0, 0, 0, 0, 3, 1]
[0, 0, 3, 0, 1, 0, 0, 8, 0]
[9, 0, 0, 8, 6, 3, 0, 0, 5]
[0, 5, 0, 0, 9, 0, 6, 0, 0]
[1, 3, 0, 0, 0, 0, 2, 5, 0]
[0, 0, 0, 0, 0, 0, 0, 7, 4]
[0, 0, 5, 2, 0, 6, 3, 0, 0]
]
<strong>Output:</strong> false
<strong>Explaination:</strong> It is not possible to have aproper sudoku.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>0 ≤ mat[i][j] ≤ 9</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;
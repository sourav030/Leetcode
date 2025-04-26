<h2><a href="https://www.geeksforgeeks.org/problems/median-of-bst/1">Median of BST</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a Binary Search Tree, find the Median of its Node values.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root = [6, 3, 8, 1, 4, 7, 9]
&nbsp; &nbsp; &nbsp; &nbsp;6
&nbsp; &nbsp; &nbsp;/&nbsp; &nbsp;\
&nbsp; &nbsp;3&nbsp; &nbsp; &nbsp; 8&nbsp; &nbsp;
&nbsp;/&nbsp; \&nbsp; &nbsp; /&nbsp; \
1&nbsp; &nbsp; 4&nbsp; 7&nbsp;   9<strong>
Output: </strong>6
<strong>Explanation: </strong>Inorder of Given BST will be: 1, 3, 4, 6, 7, 8, 9. So, here median will 6.
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root = [6, 3, 8, 1, 4, 7, N]
&nbsp; &nbsp; &nbsp; &nbsp;6
&nbsp; &nbsp; &nbsp;/&nbsp; &nbsp;\
&nbsp; &nbsp;3&nbsp; &nbsp; &nbsp; 8&nbsp; &nbsp;
&nbsp;/&nbsp; &nbsp;\&nbsp; &nbsp; /&nbsp; &nbsp;
1&nbsp; &nbsp; 4&nbsp;  7&nbsp; &nbsp;<strong>
Output: </strong>5<strong>
Explanation:</strong>Inorder of Given BST will be: 1, 3, 4, 6, 7, 8. So, here median will (4 + 6)/2 = 10/2 = 5.<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root = [18, 16, 20, 7]<strong>
Output: </strong>17</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1&lt;=n&lt;=10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Traversal</code>&nbsp;<code>Binary Search Tree</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;
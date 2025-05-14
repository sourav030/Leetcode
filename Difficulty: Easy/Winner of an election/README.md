<h2><a href="https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621--162858/1?page=1&category=Strings&sortBy=latest">Winner of an election</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a lowercase string array <strong>arr</strong>[]. Each element in the array represents a vote cast for a candidate. Return the name of the candidate who received the maximum number of votes and the count of votes he received. In case of a tie between two or more candidates, return the <strong>lexicographically</strong> smallest name.<br></span></p>
<p><span style="font-size: 18px;">Note: Return an array of strings, the winning candidate name as the first element and the vote count as the second element (typecast the count to string).</span></p>
<p><span style="font-size: 18px;"><strong>Examples :<br></strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = ["john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"]
<strong>Output: </strong>["john", "4"]<strong>
Explanation: "</strong>john" has 4 votes casted for him, but so does "johnny". "john" is lexicographically smaller, so we print "john" and the votes he received.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3
arr[] = ["andy", "blake", "clark"]
<strong>Output: </strong>[<strong>"</strong>Andy", "1"]<strong>
Explanation: </strong>All the candidates get 1 votes each. We print "andy" as it is lexicographically smaller.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= arr.size() &lt;= 10<sup>5<br></sup></span><span style="font-size: 18px;">1 &lt;= arr[i].size() &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Adobe</code>&nbsp;<code>Atlassian</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;
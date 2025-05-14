<h2><a href="https://www.geeksforgeeks.org/problems/case-insensitive-search/1?page=1&category=Strings&sortBy=latest">Case Insensitive Search</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given two strings, one is a text string&nbsp;<strong>txt</strong>&nbsp;and the other is a pattern string&nbsp;<strong>pat</strong>. The task is to print the indexes of&nbsp;<strong>all the occurrences</strong> of the pattern string in the text string, ignoring the letter case (uppercase and lowercase characters are considered same)</span><span style="font-size: 14pt;">. Use</span><strong style="font-size: 14pt;">&nbsp;0-based</strong><span style="font-size: 14pt;">&nbsp;indexing while returning the indices.&nbsp;</span></p>
<p><span style="font-size: 14pt;">Note:<strong>&nbsp;</strong>Return an empty list in case of no occurrences of pattern.<br></span></p>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18.6667px;"><strong>Input: </strong>txt = "aBcAb", pat = "aB"<strong>
Output: </strong>[0, 3]<strong>
Explanation: </strong>The string "ab" can match with any of the following strings: "ab", "Ab", "aB" and "AB". So, pat occurs twice in txt, first occurrence starts from index 0 and second from index 3.</span></pre>
<pre><span style="font-size: 18.6667px;"><strong>Input: </strong>txt = "aAAa", pat = "Aa"<strong>
Output: </strong>[0, 1, 2]<strong>
Explanation: </strong>The string "Aa" can match with any of the following strings: "aa", "aA", "Aa" and "AA". So, pat occurs thrice in txt, first occurrence starts from index 0, second from index 2 and third from index 3.</span></pre>
<pre><span style="font-size: 18.6667px;"><strong>Input: </strong>txt = "abba", pat = "aC"<strong>
Output:</strong> []<strong>
Explanation:</strong> There is no occurrence of "aC" in "abba".</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ txt.size() ≤ 10<sup>5</sup><br>1 ≤ pat.size() &lt; txt.size()<br>Both the strings consist of uppercase or lowercase English alphabets.</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Pattern Searching</code>&nbsp;
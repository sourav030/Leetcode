<h2><a href="https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix">Infix to Postfix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given an infix expression in the form of string <strong>s</strong>. Convert this infix expression to a postfix expression.</span></p>
<ul>
<li><span style="font-size: 14pt;"><strong>Infix expression:</strong> The expression of the form a <strong>op</strong> b. When an operator is in between every pair of operands.</span></li>
<li><span style="font-size: 14pt;"><strong>Postfix expression:</strong> The expression of the form a b <strong>op</strong>. When an operator is followed for every pair of operands.</span></li>
</ul>
<p><span style="font-size: 14pt;">Note:&nbsp;The order of precedence is: ^&nbsp;greater than&nbsp;*&nbsp;equals to&nbsp;/&nbsp;greater than&nbsp;+&nbsp;equals to&nbsp;-. Ignore the right associativity of&nbsp;<strong>^</strong>.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: s = "a+b*(c^d-e)^(f+g*h)-i"
<strong>Output</strong>: abcd^e-fgh*+^*+i-
<strong>Explanation</strong>: After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: s = "A*(B+C)/D"
<strong>Output</strong>: ABC+*D/
<strong>Explanation</strong>: After converting the infix expression into postfix expression, the resultant expression will be ABC+*D/<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: s = "(a+b)*(c+d)"
<strong>Output</strong>: ab+cd+*</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ s.length ≤ 30</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>VMWare</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;
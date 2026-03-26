<h2><a href="https://www.geeksforgeeks.org/problems/fun-with-expresions2523/1">Expression Evaluation</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">You are given an array of strings <strong>arr[]</strong>, that represents a valid <strong>infix expression</strong>. The task is to evaluate this expression.</span><br><span style="font-size: 14pt;">An infix expression is of the form "operand1 operator operand2" (e.g., "a + b"), where the operator is written between the two operands.</span></p>
<p><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Note: </strong><span style="font-size: 14pt;">Infix expressions follow precedence: ^ (highest, right-to-left), then * and /, and finally + and - (left-to-right).</span><br><span style="font-size: 14pt;">The division operation between two integers always computes the </span><strong style="font-size: 14pt;">floor value,</strong><span style="font-size: 14pt;">&nbsp;</span><span style="font-size: 18.6667px;">i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.</span><br><span style="font-size: 14pt;">It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.</span></span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = ["100", "+", "200", "/", "2", "*", "5", "+", "7"]
<strong>Output: </strong>607<br><strong>Explanation:</strong> The expression can be directly read as: (100 + 200 / 2 * 5 + 7). Now, evaluate step by step:
200 / 2 = 100
100 * 5 = 500
500 + 100 = 600
600 + 7 = 607
Final Answer: 607
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = ["2", "^", "3", "^", "2"]
<strong>Output: </strong>512<br><strong>Explanation: </strong>^ is right-associative → 2 ^ (3 ^ 2) = 2 ^ 9 = 512.
Final Answer: 512</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>3 ≤ arr.size() ≤ 10<sup>5</sup></span><br><span style="font-size: 14pt;">arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [1, 10<sup>4</sup>]</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Stack</code>&nbsp;
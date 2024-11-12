#include <bits/stdc++.h> 
using namespace std;
/**
 * Inserts the given element x into the given sorted stack st
 *
 * @param[in,out] st  The sorted stack in which x is to be inserted
 * @param[in] x  The element to be inserted into the stack
 */
stocvoid sortedInsert(stack<int>&st,int x){
	if(st.empty() || x>=st.top()){
		st.push(x);
	}else{
		int t = st.top();st.pop();
		sortedInsert(st, x);
		st.push(t);
	}
}
/**
 * Recursively sorts the given stack in ascending order
 *
 * @param[in,out] st  The stack to be sorted
 */
void sort(stack<int>&st){
	if(st.empty())return ;
	int x = st.top();
	st.pop();
	sort(st);
	sortedInsert(st,x);
}
/**
 * Sorts the given stack in ascending order
 *
 * @param[in,out] stack  The stack to be sorted
 */
void sortStack(stack<int> &stack)
{
	// Write your code here
	sort(stack);
}
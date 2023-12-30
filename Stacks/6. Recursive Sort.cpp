#include <bits/stdc++.h>

void sortRec(stack<int> &s, int element) {

	if(s.size() == 0 || element >= s.top()) {
		s.push(element);
		return;
	}

	int top = s.top();
	s.pop();
	sortRec(s, element);
	s.push(top);
	return;
}

void sortStack(stack<int> &s)
{
	// Write your code here
	if(s.empty()) {
		return;
	}

	int top = s.top();
	s.pop();
	sortStack(s);
	sortRec(s, top);
	return;
}
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> q;

	q.push(-1);
	q.push(-2);
	q.push(3);
	q.push(-3);
	q.push(1);
	
	while(!q.empty()){
		printf("%d\n", q.top());
		q.pop();
	}
	
	return 0;




}

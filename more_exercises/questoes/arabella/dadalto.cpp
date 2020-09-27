/****************************************************************************
 * Arthur Pratti Dadalto
 * OBI 2016
 * Programação dinâmica (O(M*log(N)))
 ***************************************************************************/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[112345], tab[112345], nexta[112345];

int pd(int a, int i)
{
	if(i >= graph[a].size())	return 1;
	if(tab[a][i])	return tab[a][i];
	return tab[a][i] = max(pd(graph[a][i], nexta[a][i]) + 1, pd(a, i+1));
}

int
main(void)
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		tab[a].push_back(0);
		graph[b].push_back(a);
		tab[b].push_back(0);
	}
	for(int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < graph[i].size(); j++)
			nexta[i].push_back(upper_bound(graph[graph[i][j]].begin(), graph[graph[i][j]].end(), i) - graph[graph[i][j]].begin());

	printf("%d", pd(1, 0));
	for(int i = 2; i <= n; i++)
		printf(" %d", pd(i, 0));
	printf("\n");
}

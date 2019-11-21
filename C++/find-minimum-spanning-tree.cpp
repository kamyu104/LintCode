/*
 * This algorithm is called Kruskall's Algorithm which is used to find the 
 * minimum spanning tree (MST) within a graph. MST is basically a tree within
 * a graph with the least weightage in its edges.
 *
 * Time Complexity  : O(M log N) or O(M log M) [variables are as coded]
 * Space Complexity : O(M)
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000000

int N,M,totalCost;
int rank[MAX],parent[MAX];

struct edge {int x,y,c;};
edge A[MAX];

// To find the parent of the node x using Union Disjoint Set Data Structure (UDS).
int f_find(int x)
{
  if(parent[x] != x)
    parent[x] = f_find(parent[x]);
  return parent[x];
}

// To unify and edge with the rest of the tree (coded based on UDS).
void f_union(int x,int y)
{
  if(rank[x] > rank[y])swap(x,y);
  
  if(rank[x] == rank[y])
    rank[y] ++;
  
  parent[x] = y;
}

// A function to help with the sorting algorithm.
bool func(edge a, edge b)
{
  return a.c < b.c;
}

// Kruskal's algorithm to find the MST within a graph.
void kruskall()
{
  sort(A, A+M, func);

  // Initializing all the varibales.
  for(int i=0;i<N;i++)
    rank[i] = 0, parent[i] = i;

  for(int i=0;i<M;i++)
    {
      int x = f_find (A[i].x);
      int y = f_find (A[i].y);
      
      if(x!=y)
	{
	  f_union(x,y);
	  totalCost += A[i].c;
	}
    }

  cout << totalCost << '\n';
}


// Receiving the input from STDIN
void get_input()
{
  cout << "Enter the number of nodes : "; cin >> N;
  cout << "Enter the number of edges : "; cin >> M;
  cout << "Enter the edges in the format of 'Node1 Node2 Cost'\n";
  for(int i=0;i<M;i++)
    cin >> A[i].x >> A[i].y >> A[i].c;
}

int main()
{
  get_input();
  kruskall();
  return 0;
}

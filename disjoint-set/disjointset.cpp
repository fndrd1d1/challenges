#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
	int size;

    struct DisjointSetElement
    {
        int parent;
        int rank;
        int groupsize;

        DisjointSetElement(int parent = -1, int rank = 0, int groupsize = 0)
        : parent(parent), rank(rank)
        {}
    };

	vector<DisjointSetElement> sets;
public:
	DisjointSet(int size): size(size), sets(size)
    {
		for (int i = 0; i < size; i++)
        {
           sets[i].parent = i;
           sets[i].groupsize = 1;
        }
	}

	int find(int element)
    {
		// find parent and compress path
        if(element != sets[element].parent)
        {
            sets[element].parent = find(sets[element].parent);
        }
        return sets[element].parent;
    }

    int getSize(int element)
    {
        return sets[find(element)].groupsize;
    }

	void merge(int destination, int source) {
		int realDestination = find(destination);
		int realSource = find(source);
		if (realDestination != realSource) {
			// merge two components
			// use union by rank heuristic
            if(sets[realDestination].rank > sets[realSource].rank)
            {
                sets[realSource].parent = realDestination;
                sets[realDestination].groupsize += sets[realSource].groupsize;
            }
            else
            {
                sets[realDestination].parent = realSource;
                sets[realSource].groupsize += sets[realDestination].groupsize;
                if (sets[realDestination].rank == sets[realSource].rank)
                {
                    sets[realSource].rank++;
                }
            }

		}
	}
};

int main() {
    int N,Q = 0;
    char q;

    int val1, val2;
    cin >> N >> Q;

    DisjointSet dset(N+1);

    for(int i = 0; i < Q; ++i)
    {
        cin >> q;
        if (q == 'Q')
        {
            cin >> val1;
            cout << dset.getSize(val1) << endl;
        }
        else
        {
            cin >> val1;
            cin >> val2;
            dset.merge(val1, val2);
        }
    }
    return 0;
}


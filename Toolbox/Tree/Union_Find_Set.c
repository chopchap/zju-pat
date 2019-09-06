/**
 * IMPLIMENTATION OF UNION-FIND-SET
 */
#define MAXN 1000
typedef int ElementType;	/* Non-negative integer to present normal element */
typedef int SetName;		/* Use index of root as the name of Set */
typedef ElementType SetType[MAXN];

/* Root1 and Root2 are root of different set by assumption */
void Union(SetType S, SetName Root1, SetName Root2)
{
	/* To promise merge the smaller one into the larger one */
	if (S[Root2] < S[Root1]) {		/* Set2 is larger */
		S[Root2] += S[Root1];		/* Merge into Set2 */
		S[Root1] = Root2;
	} else {						/* Set1 is larger */
		S[Root1] += S[Root2];		/* Merge */
		S[Root2] = Root1;
	}
}

/* Set all elements in the set as -1 */
SetName Find(SetType S, ElementType X)
{
	if (S[X] < 0) return X; 		/* Find the root of Set */
	else return S[X] = Find(S, S[X]); 	/* Path compression */
}


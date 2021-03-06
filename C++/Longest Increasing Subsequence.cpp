int A[MAX_N], L[MAX_N], L_id[MAX_N], prev_id[MAX_N]; //negate values in array A for longest decreasing subsequence
stack<int> stk;

int LIS() {
	int lis = 0, lisEnd = 0;
	for (int i = 0; i < N; ++i) {
		int pos = lower_bound(L, L + lis, A[i]) - L; //change to upper_bound to go from increasing to non-decreasing
		L[pos] = A[i];
		L_id[pos] = i;
		prev_id[i] = (pos ? L_id[pos - 1] : -1);
		if (pos + 1 > lis) {
			lis = pos + 1;
			lisEnd = i;
		}
	}
	return lis;
}

void reconstructLIS(int end) {
	int i;
	for (i = end; prev_id[i] >= 0; i = prev_id[i]) stk.push(A[i]);
	stk.push(A[i]);
}

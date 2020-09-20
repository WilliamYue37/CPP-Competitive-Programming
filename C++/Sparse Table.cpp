int sparse[MAX_N][MAX_LOG];

void init() {
	for (int i = 0; i < N; ++i) sparse[i][0] = arr[i];
	for (int j = 1; (1 << j) <= N; ++j) {
		for (int i = 0; (i + (1 << j) - 1) < N; ++i) {
			sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) { //inclusive range
	int j = (int)log2(r - l + 1);
	return min(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}
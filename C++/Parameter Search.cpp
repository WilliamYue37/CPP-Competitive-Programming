ll lo = 0, hi = INF, ans = -1;
pl memo_left, memo_right;
while (lo <= hi) {
	ll x = (lo + hi) / 2;
	pl prev = {-arr[1], 0};
	dp[0].ff = INF;
	for (int i = 1; i <= N; ++i) {
		dp[i] = min(pl{dp[i - 1].ff - arr[i - 1] + arr[i], dp[i - 1].ss}, pl{prev.ff + arr[i] + x, prev.ss + 1});
		prev = min(prev, pl{dp[i].ff - arr[i + 1], dp[i].ss});
	}
	ll val = dp[N].ff - x * dp[N].ss;
	if (dp[N].ss == K) {
		ans = val;
		break;
	}
	else if (dp[N].ss < K) {
		memo_left = {dp[N].second, val};
		hi = x - 1;
	}
	else {
		memo_right = {dp[N].second, val};
		lo = x + 1;
	}
}
// colinear points
if (ans == -1) {
	ans = (memo_right.ss * (memo_left.ff - K) + memo_left.ss * (K - memo_right.ff)) / (memo_left.ff - memo_right.ff);
}

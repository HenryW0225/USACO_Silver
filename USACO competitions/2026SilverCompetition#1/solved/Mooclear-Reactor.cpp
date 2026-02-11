#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

struct Link {
    int nxt;
    long long weight;
    Link(int n = 0, long long w = 0) : nxt(n), weight(w) {}
};

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        vector<long long> lowerBound(N), upperBound(N);
        for (int i = 0; i < N; i++) {
            cin >> lowerBound[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> upperBound[i];
        }

        int a, b;
        long long c;
        vector<vector<Link>> adj(N);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            adj[a-1].push_back(Link(b-1, c));
            adj[b-1].push_back(Link(a-1, c));
        }
        vector<bool> visited(N, false);
        vector<int> parity(N, 0);
        vector<long long> delta(N, 0);

        int totalAnswer = 0;
        bool isImpossible = false;
        for (int i = 0; i < N && !isImpossible; i++) {
            if (visited[i]) {
                continue;
            }

            queue<int> bfsQueue;
            vector<int> component;

            visited[i] = true;
            parity[i] = 1;
            delta[i] = 0;
            bfsQueue.push(i);
            bool hasFixedValue = false;
            long long fixedValue = 0;

            while (!bfsQueue.empty() && !isImpossible) {
                int current = bfsQueue.front();
                bfsQueue.pop();

                component.push_back(current);

                for (const Link& edge : adj[current]) {
                    if (!visited[edge.nxt]) {
                        visited[edge.nxt] = true;
                        parity[edge.nxt] = -parity[current];
                        delta[edge.nxt] = edge.weight - delta[current];
                        bfsQueue.push(edge.nxt);
                    } 
                    else {
                        if (parity[edge.nxt] == -parity[current]) {
                            if (delta[edge.nxt] != edge.weight - delta[current]) {
                                isImpossible = true;
                                break;
                            }
                        } 
                        else {
                            long long candidate =
                                (edge.weight - delta[current] - delta[edge.nxt]) *
                                (long long)parity[edge.nxt];
                            if (candidate % 2 != 0) {
                                isImpossible = true;
                                break;
                            }
                            candidate /= 2;
                            if (!hasFixedValue) {
                                hasFixedValue = true;
                                fixedValue = candidate;
                            } else if (fixedValue != candidate) {
                                isImpossible = true;
                                break;
                            }
                        }
                    }
                }
            }
            if(isImpossible) {
                continue;
            }
            if (hasFixedValue) {
                for (int vtx : component) {
                    long long actual =
                        (long long)parity[vtx] * fixedValue + delta[vtx];
                    if (lowerBound[vtx] <= actual && actual <= upperBound[vtx]) {
                        totalAnswer++;
                    }
                }
            } else {
                vector<Link> sweepEvents;
                sweepEvents.reserve(component.size() * 2);
                for (int vtx : component) {
                    if (parity[vtx] == 1) {
                        sweepEvents.emplace_back(1,  lowerBound[vtx] - delta[vtx]);
                        sweepEvents.emplace_back(-1, upperBound[vtx] - delta[vtx] + 1);
                    } else {
                        sweepEvents.emplace_back(1,  delta[vtx] - upperBound[vtx]);
                        sweepEvents.emplace_back(-1, delta[vtx] - lowerBound[vtx] + 1);
                    }
                }
                


                sort(sweepEvents.begin(), sweepEvents.end(),
                    [](const Link& a, const Link& b) {
                        return a.weight < b.weight;
                    });
                int bestOverlap = 0;
                int activeCount = 0;
                int idx = 0;
                while (idx < (int)sweepEvents.size()) {
                    long long curPos = sweepEvents[idx].weight;
                    while (idx < (int)sweepEvents.size() &&
                        sweepEvents[idx].weight == curPos) {
                        activeCount += sweepEvents[idx].nxt;
                        idx++;
                    }
                    bestOverlap = max(bestOverlap, activeCount);
                }
                totalAnswer += bestOverlap;
            }
        }
        if (isImpossible) {
            cout << -1 << endl;
        } 
        else {
            cout << totalAnswer << endl;
        }
    }
}
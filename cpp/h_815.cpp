class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                stopToBuses[routes[i][j]].push_back(i);
            }
        }
        queue<int> buses;
        unordered_set<int> visitedStops, visitedBuses;
        for (int bus : stopToBuses[source]) {
            buses.push(bus);
            visitedBuses.insert(bus);
        }
        int stops = 1;
        while (!buses.empty()) {
            int size = buses.size();
            for (int i = 0; i < size; i++) {
                int currBus = buses.front();
                buses.pop();
                for (int stop : routes[currBus]) {
                    if (stop == target) return stops;
                    if (visitedStops.count(stop)) continue;

                    visitedStops.insert(stop);
                    for (int nextBus : stopToBuses[stop]) {
                        if (!visitedBuses.count(nextBus)) {
                            buses.push(nextBus);
                            visitedBuses.insert(nextBus);
                        }
                    }
                }
            }
            stops++;
        }

        return -1;
    }
};

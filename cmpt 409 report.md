Problem name | level | interesting | Writing | Topics | Equivalent versions
--- | --- | --- | --- | --- | --- 
Anagram Groups | 1 | average |  average | Dict, String | For every input string, make a copy and sort it by alphebt order. Then attach the string to list in a dict like {string : list}. Output by group list length.
Asteroids | 3 | good | good | Bipartite Matching | Make vertex for each row X and column Y. If there is a asteroid in [x,y] then connect two vertices. Compute the maximum bipartite matching.
Binary codes | 1 | average | good | sort | Construct n strings by shift the original left n - 1 times. Sort by alphabetical order, find the first one.
Cube stacking | 2 | average | good | union | Move X Y -> union[x].bottom.next = union[y].top Count X -> union[x].height
Dining | 3 | good | average | Network flow | Make two nodes for each cow and connect them, cow-food and cow-drink. Add a super souce for every food, and a super sink for every drink. If connect food and node cow-food if cow like this types, similar for drink. Find the maxium flow on this graph.


Problem name | level | interesting | Writing | Topics | Equivalent versions
--- | --- | --- | --- | --- | --- 
Drainage Ditches | 2 | avg | avg | network flow | build graph, run max flow
Farm Tour | 2 | avg | good | network flow | add super source to start point with capicity 2, and super sink to destination with capicity 2. run max flow 
Fishnet | 2 | good | good | computational geometry | iteraltively check all sub-areas, find the largest one.
Frogger | 1 | bad | avg | shortest path | read in stone' position, compute shortest path.
Going Home | 2 | Interesting | good | network flow | Min-cost Max-flow where cost is the travel distance from human to house.

Problem name | level | interesting | Writing | Topics | Equivalent versions
--- | --- | --- | --- | --- | --- 
Inversion | 2 | avg | avg | permutation and combination | {a1, a2 .. ,ak .. ,am} when {a1 .. ak} are determinined, it can have (m-k)! possibilities. Then use the way we compute binary numbers, to find answer.
A Knight's Journey | 1 | bad | avg | DFS | keep a state then DFS, to see whether it is possible to traverse all positions.
Line of Sight | 1 | avg | avg | geometry | Firstly remove all intervals that don't overlap with house. Then, merge intervals. Compute the gap.
Low Cost Air Travel | 2 | avg | good | shortest path | price is the distance between two cities. After building graph, compute shortest path.
Milking Grid | 3 | interesting | good | KMP | Take each column as a string, find its cyclic substring, record length L1. Take each row as a string, find cyclic substring of length L2. L1 * L2 is the area we want.

Problem name | level | interesting | Writing | Topics | Equivalent versions
--- | --- | --- | --- | --- | --- 
Most Distant Point from the Sea | 3 | Interesting | good | computational geometry | This problem is equvilant to ask the largest incircle of convex polygon.
Navigation Nightmare | 2 | bad | avg | union | when add a path of two cities, do union merge. As for query, if they are not in same union, cout -1. Otherwise cout the sum of their offest to root.
Out of Hay | 2 | avg | avg | minimum spanning tree | Distances between vertice are given clearly. Run Kruskal.
Paratroopers | 3 | Interesting | good | networf flow | Since the cost is product of every ri and ci. Firstly change it into lg(s) = lg(s1) + lg(s2) + ... + lg(sn). Construct graph with a super source and sink. Add edge from s to cr[i] and ri to cr[i] (capicity lg(ri)), and edge from cc[i] to sink and cc[i] to ci(capacity lg(ci)). And for every enemy [x,y], add edge from row x to colum y with infinite capacity. 
Popular Cows | 2 | avg | good | topological sort | for each pair A B, add edge A -> B. Run topologic sort.

Problem name | level | interesting | Writing | Topics | Equivalent versions
--- | --- | --- | --- | --- | --- 
Questions | 1 | bad | bad | Josephus problem ｜ It is a modified Josephus permutation. Since data set is not large, simply following the description can solve it.
Redundant Paths | 3 | avg | avg | connected component | Find all joints that connected by at least two routes. Shrink them to single node. Leaf is the node with degree 1. And result is (leaf + 1) / 2.
Space Ant | 3 | avg | avg | convex hull | every time go to the point with has smallest angle.
Stockbroker Grapevine | 2 | interesting | good | global shortest path | build graph, run floyd, to find the man with shortest paths to rest people.
Subway | 2 | avg | good | shortest path | use infomation to build graph, run dijkstra.
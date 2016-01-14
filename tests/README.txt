I "made-up" this format for easy parsing; you may want to change
to fit your application; example of .network format:

8 <-- num of nodes
0 100 300 <-- node id, (x,y) location in um; location is not used currently for anything;
1 100 100
2 200 300
3 200 100
4 300 300
5 300 100
6 400 300
7 400 100
12 <-- num of edges
0 0 2 10.0 2.00 <-- id, src, des, capacity, delay (as cost)
1 2 4 10.0 2.00 
2 3 2 10.0 6.00 
3 1 3 10.0 2.00 
4 3 5 10.0 2.00
5 2 3 10.0 6.00 
6 4 2 10.0 2.00
7 5 3 10.0 2.00
8 5 4 10.0 6.00 
9 4 5 10.0 6.00 
10 4 6 10.0 2.00
11 5 7 10.0 2.00
2 <-- num of demands (commodities)
0 0 7 0.577004 <-- id src des amount
1 1 6 1.777268

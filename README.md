
#  Island Counter Visualization (C++ / Graphics.h)

This project visualizes and calculates the **area of islands** in a 2D grid using **Depth-First Search (DFS)**. Each island is a group of connected pixels (cells) with the same ID, and the goal is to determine the **number of pixels in each island** and identify the island with the **maximum area**.

##  Features

- Graphical visualization using `graphics.h`
- Recursive DFS algorithm for connected component detection (including diagonals)
- User input for:
  - Number of islands
  - Grid size (width & height)
  - Cell values indicating island membership
- Output includes:
  - Area of each island
  - ID of island with the largest area


 Concepts Used

- Depth-First Search (DFS) for region exploration
- 8-directional connectivity (includes diagonals)
- Basic graphics rendering (`putpixel`, `rectangle`)
- Handling user input for dynamic grid construction

##  Sample Input

```
Number of islands: 2  
Length & Height: 5 5  
Grid values:  
0 1 1 0 0  
0 1 0 0 2  
0 0 0 2 2  
0 0 0 0 0  
0 0 0 0 0  
```

##  Output

```
Island 1: 3 pixels  
Island 2: 4 pixels  
Maximum area: 4  
Island with maximum area: 2
```
raphical programming.

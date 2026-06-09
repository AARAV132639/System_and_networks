# Polygon Filling

## Journey so far

- Line generation ---> Circle generation ----> Ellipse Generation ----> Polygon filling

- Until now we were deciding: Which pixels belong to the boundary?

- Now we are deciding: Which pixel belong to the inside?

## Three Algorithms:

o Flood Fill 
o Boundary Fill
o Scan line Fill

## Flood Fill

- Like the Paint bucket tool

- The algorithm spreads outward until it encounters a different colour.

### Idea:

o If current pixel color equals old color: fill it

o Recursively visit : left, right, up and down

### Algorithm

Flood fill (x,y)

    if current pixel != target color
        return
    
    color pixel

    Flood fill(x+1,y)
    Flood fill(x-1,y)
    Flood fill(x,y+1)
    Flood fill(x,y-1)

## Boundary Fill

- Instead of checking for a fill colour it stops when it reaches a boundary color.

### Idea;

- Stop wehn boundary color is encountered

## Scan Line Fill

- Proffesional approach

- For every horizontal line: y = constant

- Find intersection with polygon edges

- Fill between pairs of intersection.

- This is much faster and forms the basis of rasterization pipelines.

### Core idea:

o Take one horizontal row
o Find where it enters polygon
o Find where it leaves polygon
o Fill between them

- Move to next row
- Repeat

### Hidden mathematics

o Computation geometry: For every edge we solve: Where does this edge intersect the horizontal scan line? This is line intersection problem
o Sorting: For each row
                        - Find the intersections
                        - Sort them
                        - Fill between the pairs
                        ** Sorting is the step that makes this algorithm works

o Odd-even rule:
                - Outside
                - Cross edge
                - Inside
                - Cross edge
                - Outside
    
    This is actually parity argument from discrete mathematics

Hence scan line works row by row. Much faster and without recursion.

### Rasterization:

Scan line algorithm is foundation of:

o OpenGl rasterization
o DirectX rasterization
o GPU rendering
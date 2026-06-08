# Circle generation Algorithms


## Theory

- Circle equations: x2 + y2 = r2

- Unlike a line, we cannot simply increment x and compute y effeiciently

- Instead, we use a decision parameter to determine which pixel is closer to the actual circle

## Key Observation: 8- way symmetry

- If a circle contains (x,y) it also contains:
                                                (x,y)   (-x,y)  (x,-y)  (-x,-y)
                                                (y,x)   (-y,x)  (y,-x)  (-y,-x)

- So we only compute one octant and mirror the points. **This reduces work my a factor of 8**

## Important poins

1. Mid points Cirlce Algorithm

- Decision parameter: p0 = 1-r.

i. Start from x=0 y=r
ii. Move until x<= y
iii. At each step:  
                    o if p < 0:
                                - Choose east pixel (x+1,y)
                                - Update: p = p + 2x +3
                    
                    o else :
                            - Choose South - east pixel: (x+1, y-1)
                            - Update : p = 2(x-y) +5

2. Bresenham algorithm

- d= 3 - 2r

3. Both:
        o Use integer arithmetic
        o Use 8- way symmetry
        o Avoid trigonometric functions
        o Run in O(r)
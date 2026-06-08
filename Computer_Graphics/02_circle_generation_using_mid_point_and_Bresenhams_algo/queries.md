## On what basis do we choose the update function?

- The update function comes from the the geometry equation of the shape and from reusing previous calculations

- The actual equation of circle is: x2 + y2 - r2 =0

- Define: F(x,y): x2 + y2 -r2

- Now suppose you are at pixel (x,y)
                                    - You have two candidate pixels: E = (x+1,y) SE = (x+1,y-1)
                                    - Which is closer to true circle?

                                    - Instead of computing distances every time, we evaluate F at a midpoint between candidates

                                    - The decision parameter is basically----> decision = F(midpoint)

                                    - If positive: One pixel is closer
                                    - If negative: the other pixel is closer

- Clever part: After moving from one pixel to the next, we don't compute x2 + y2 - r2 from scratch.

- We derive: newDecision = oldDecision + correction

- The correction becomes the update function

- So the updat equation is not magic but:
                                        o Decision function
                                        o Algebraic simplification
                                        o Incremental update

---

## What hidden subjects are being used?

1. Co ordinate geometry [ Everything begins here]

2. Analytical geometry 
                    - Is this point above the line?
                    - Inside the circle?
                    - Outside the circle?

3. Numerical Methods. We are approximating continous curve with discrete pixels

4. Discrete Mathematics
                        - Screen is not continous
                        - It is integer lattic points
                        - Graphics algorithms are fundamentally discrete math

5. Algorithm desing: Instead of recomputing everything we reuse previous computation

6. Optimization: The original formulas involve multiplication, division, floating points. Bresenham transforms them into addition, subtraction and comparision

7. Computer Architecture
                        - Why does Bresenham exists?
                        - Because historically Integer arithmetic << floating point arithmetic in cost
                        - So graphics algorithms were designed around CPU limitations

---

## Deeper lessen

- Most computer graphics algorithms are not really about graphics

They are about:

o Continous Mathematics
o Decision Function
o Discrete approximation
o Incremental Computation
o Finally followed by efficient hardware execution

- Line generation and circle generation are the first examples

---

## Why we take east and sout east points only?

- This is the key insight. We take only East and South East because we are drawing only one octant of the circle. Starting form x=0 and y=r

- Thus in 1st octant: As we move from top of the circle x will always increase and y will either stay the same or decreases by 1

- Since we are moving clockwise in first octant:
                                                o North is not possible as we are moving downward
                                                o West (x-1,y) is not possible as we dont go back
                                                o South (x,y-1) is not possible because that would skip horizontal progress
                                                o Hence only (x+1,y) and (x+1,y-1) remain

- We need to find only octant because all 8 points are symmetric

- hence the decision parameter evaluates a midpoints between East and SE and asks is the circle above this midpoint or below it?

o if above ---> Choose E
o if below----> choose SE

Thus the entire midpoint/Bresenham circle algorithm is really a repeated binary choice .

That is why the algorithm is so efficient. Instead of searching among many pixels, geometry guarantees that only two candidates are ever relevatn in the octant being drawn.

---
---
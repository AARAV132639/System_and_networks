# Important Notes and key insights


## One line essence of first experiment:

- How do we convert continous geometry into discrete pixel with minimal computation

1. Why is it called slope method?

- Because every pixel is generated using the slope m= del_y/del_x

---


2. What is the main drawback?

- uses floationg- points calculations and rounding

---


3. Why was DDA developed?

- To generalize line generation and improve handling of different slopes

---


4. Why DDA is better than slope method?

- It works for: 
            1. Positive slopes  2. Negative slopes 
            3. Steep slopes     4. Horizontal lines
            5. Vertical lines
        without specail classes

---

5. Main disadvantage of DDA?

- Uses floating point of arithmetic and rounding.

---


6. Why was Bresenham developed?

- To avoid floating points arithmetic entirely and improve speed

- Bresenham uses only integer operations making it faster and more effecient

---

## Bresenham Algorithm

1. DDA uses floating-points calculations: x+= xince     y+=yince

2. Bresenham avoids floating-points arithmetic entirely

3. It uses decision parameter to determine which pixel is closer to the ideal line

4. It uses **decision parameters** to determine which pixel is closer to ideal line

### For a line with: 0<= slope <= 1

- Initial decision parameter: p0= 2dy- dx

- if p < 0: choose east pixel(x+1,y)

- else choose north east pixel (x+1, y+1)

- Only integer addition and subtraction are used

*Hence, Bresenham's algorithm is the most effecieint*

- Why is it preferred in graphics hardware?

~ Because integer operations are computationally cheaper than floating point operations.

### Generalized version of Bresenham Algorithm

- A line can have all types of slopes thus the algorithm must work in all 8 octants

#### **Mathematical Idea**:
                        A line can be written as: F(x,y)= dy.x - dx.y +c where dy= y2-y1 and dx= x2-x1

- Instead of computing exact real-valued line, Bresenham asks: Which neighbouring pixel is closer to the true line?

- This is essentially a sign test on the line equation

- The entire algorithm is really: Analytical geometry+ Integer Arithmetic

### Key mathematical insigh:

- The generalized algorithm no longer cares about slope. 
- Instead it compares: |dx| and |dy|.
                                    - if |dx|>|dy| the line is x-dominant. Advance x every step
                                    - else the line is y dominant. Advance y every step

- Hence, effecitively using |m|= |dy/dx| without actually performing division. 

- Clever part: It avoids floating- point slope calculations completely.

### Subjects hidden inside Bresenham

- The generalized algorithm combines:

1. Co-ordinate Geometry: 
                        o Line equations
                        o Distance from line

2. Discrete Mathematics:
                        o Integer Lattic points
                        o Pixel grids

3. Numerical Methods: o Approximation of continous objects

4. Optimization: o Replacing division and multiplication with additions

---
---
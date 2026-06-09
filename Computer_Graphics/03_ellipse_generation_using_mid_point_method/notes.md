# Ellipse generation failure

- Straight lines instead of smooth curves along major axis. **Look up this file and output**


## Core mathematical insight

1. Line ----> one rgeion
2. Circle ----> one octant
3. Ellipse ----> two regions
because the slope is not uniform. 

4. The midpoint ellipse algorithm combines:
                                            o Co ordinate Geometry
                                            o Conic sections(ellipse equation)
                                            o Differential intuition (slope change)
                                            o Incremental computation
                                            o Symmetry

5. This is the first encounter with **conic rasterization** the same family of ideas used to draw circles, ellipses, parabolas, and hyperbolas efficiently.

## Why two regions?

- For circle we always chose between: E and SE

- For an ellipse slope changes differently. So we split the first quadrant into:

o Region 1: |slope|<1. Move primarily in x. Candidates: E & SE

o Region 2: |slope|>1. Move primarily in y. Candidates: S & SE
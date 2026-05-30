## Big Picture

- LZW= Lempel-Ziv-Welch-Compression

- It is a loseless data compression algorithm

- Loseless means:
                1. Original data
                2. Compressed
                3. Compressed data
                4. Decompress
                5. Original data recovered exactly

---
---

## Fundamental Questions

1. What exactly is LZW algorithm doing?
    
- It is a simple loseless compression which works by building a dictionary of repeated patterns and replacing long strings with short codes.

- LZW is called an adaptive dictionary compression algorithm. The dictionary is not fixed, rather it learns repeated patterns as it reads the data

- *Limitation of this particular implementation*: for(int j=0;j < dictsize;j++)
    
    - This is actually a linear search. 
    - Real LZW implementations use hash tables or trie structures so look up becomes faster.

---

2. How does it work? What is it mechanism?

- Sample Input: ABABABA

                        1. Step 1: Initial Dictionary--->
                                                        - The first 256 dictionary are ASCII. 
                                                        - Thus, dict[65]= "A", dict[66]="B"...
                        
                        2. Step 2: Start Compression--->
                                                        i. Iteration 1:
                                                                        - Current="A"
                                                                        - Next char= "B"
                                                                        - Build next= "AB"
                                                                        - Search dictionary, Is AB present? Ans is NO
                                                                        - Therefore, output code of current. "A"---> 65
                                                                        - Add new pattern "AB" ---> 256
                                                                        - Dictionary becomes dict[256] = "AB"
                                                                        - Set current ="B"
                                                        
                                                        ii. Iteration 2: 
                                                                        - Current ="B"
                                                                        - Next char ="A"
                                                                        - Build next = "BA"
                                                                        - Search dictionary, IS BA present? Ans is NO
                                                                        - Output: "B"---> 66
                                                                        - Printed: 65 66
                                                                        - Add "BA"---> 257
                                                                        - Dictionary becomes dict[256]="AB". dict[257]= "BA"
                                                                        - Set Current = "A"
                                                        
                                                        iii. Iteration 3:
                                                                        - Current= "A"
                                                                        - Next char ="B"
                                                                        - Build = "AB"
                                                                        - "AB" present in dictionary
                                                                        - No output
                                                                        - Set current = "AB"
                                                        
                                                        iv. Iteration 4:
                                                                        - Current= "AB"
                                                                        - Next char ="A"
                                                                        - Build ="ABA"
                                                                        - "ABA" not present
                                                                        - Output current: 256
                                                                        - Add dict[258]= "ABA"
                                                                        - Set current= "A"
                                                        
                                                        v. Iteration 5:
                                                                        - Current ="A"
                                                                        - Next char ="B"
                                                                        - Build: "AB"
                                                                        - "AB" present. No output
                                                                        - set current = "AB"
                                                        
                                                        vi. Iteration 6: 
                                                                        - Current = "AB"
                                                                        - Next char= "A"
                                                                        - Build= "ABA"
                                                                        - Present in dictionary.
                                                                        - Current = "ABA"
                                                                        - Loop ends
                        
                        3. Step 3 : Output the code
                            - Final output---> 65 66 256 258

- Big Idea:
            1. Normal storage: A B A B A B A [7 characters]
            2, LZW stores: 65 66 256 258 [4 codes]
            3. The decoder can rebuild the same dictionary in the same order  so it know, 256 = AB, 258= ABA and reconstructs the original string

---

3. What is the core logic of this compression?

- if(found!=-1) strcpy(current, next);
- *If the longer pattern already exists, keep extending*

- if pattern is not found:
                        
                        else
                        {
                            output(current);
                            add(next);
                            current= new_character;
                        }
                
                1. Emit the largest known pattern
                2. Learn a new longer pattern
                3. Continue compression

---

## Applications and limitations

1. Where is LZW used?

- LZW became famous because it was simple and worked well on repetitive data

- GIF images, Early Unix compress utility, Fax/Document transmission etc

---

2. What are the limitations?

- Dictionary Keeps Growing.
    - Suppose a case where there is no repetition. In that case LZW keeps adding entries and rarely using them.

- Memory consumpiton. Hence real implemenations usually cap dictionary size or periodically reset dictionary

- Not optimal. LZW discovers repeated patterns. But it doesn't know probabilities
    - E.g. A appears 70% B appears 30%. LZW treats both equally

- Random data defeats it. For cases like ZIP, JPEG, MP4, encrypted files LZW makes things larger.
- Why? Because there are no useful repetitions to exploit.

---

3. How LZW is different from Huffman coding?

- They are basically brothers solving different problems

- Huffman questions---> *Which symbol occurs most often?*

    - E.g: AAAAAAAABBC
    - Frequency: A=8, B=2, C=1
    - Huffman creates: A=0. B=10, C=1. Why?---Look up Huffman coding

    - Frequent symbols get shorter codes

- LZW questions ----> *Which pattern repeat?*

    - E.g.: ABABABAB
    - LZW discovers: AB, ABA, ABAB... and assign codes

- Which is better?----> Depends on the condition. 
    - If data is repetitive LZW wins while on frequency skewed data Huffman wins.

---

4. Why do modern compressors combine them?

- Each solves a different problems.

- Classic pipeline: Data---> LZ77/LZW---> Huffman----> Compressed file

- LZW finds repeated patterns, Huffman then compresses the resulting symbols according to frequency. Best of both worlds.

---

5. What' next?

- Implement LZW using Trie
- LZW decompressor [Famous KwKwK case]
- Bit packing
- Implement Huffman coding
- Implement DEFLATE [algorithm behind ZIP PNG gzip]

---

## Fun diving

---
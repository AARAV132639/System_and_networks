## Big Picture

    ~ Sender: 4 bit-data
            - parity generation
            - 7-bit encoded message

    ~ Noise introduces error

    ~ Receiver: recalucate parity
                - locate bad bit
                - correct it

---
---

## Fundamental Questions

1. What is the essence of Hamming code?

- Hamming (7,4) adds 3 intelligently placed parity bits to 4 data bits so that the receiver can not only detect but also locate and correct any single-bit transmission error using the syndrome value(p4 p2 p1)

- In simpler words, it's the idea of adding redundancy so that a reciever can find and fix a single corrupted bit without asking for retransmission.

---

2. Can you tell the problem that is being solve?

- Suppose 1011 has been sent through a noisy channel

- During transmission 1011---> 1001 || One bit gets flipped

- Without any extra information, the reciver has no way to know which bit changed.

- *Hamming code solves this by adding carefully chosen parity bits*

---

3. What is core idea?

- Instead of sending only D1 D2 D3 D4 data bits ----> Send: P1 P2 D1 P4 D2 D3 D4 which gives 7 bits total

- For e.g.: 1011 becomes 0110011, Where P1 P2 and P4 are parity bits. *These parity bits act like checkpoints*

        ~ But why positions 1,2,4? Because they are powers of 2. 
                                - These positions are reserved for parity
                                - Remaining 3,5,6,7 store actual data.

---

4. What does calculateParity() do?

- a^b^c|| Since a^a=0 || a^b^a=b

- Because of this, XOR naturally tells whether the number of 1s is odd or even

- Hence parity calculation becomes extremely simple.

---

5. How parity is actually helping?

- Let the case be:
                  i. Data sent: 1011
                  ii. Hamming code: 011011
                  iii. let 5th position get corrupted: 0110111
                
                        - Reciever doesn't know which bit changed. So it checks the parity group

- Checking by parity groups:
                                i. P1 Checks 1 3 5 7----> Values recieved: 0111---> No. of 1s: 3(odd) 
                                - But we expected even parity. Thus, P1 group failed

                                ii. P2 checks 2 3 6 7 ----> Values: 1111 [even]
                                iii. P4 checks 4 5 6 7----> Values: 0111[odd]. Thus P4 groud failed

- Result: P4 P2 P1 ----> 101 ---> Converting into decimal = 5. This is exactly the corrupted position.

- Hence parity is acting like a set of security cameras with each parity watching a certain positions.

---

6. How error is corrected?

- After knowing the error position there can be only two possibilities. Either 0 became 1 or 1 became 0

- Thus, we simply flip it. received[x] = ! received[x]

---
---

## Theoritical questions

1. Where is this hamming code used?

- Wherever single-bit error are common and fast corrections is needed

- Cases:
        i. Computer Memory [ECC RAM]: Cosmic rays, electrical noise, voltage fluctuations can randomly flip a memory bit.
                                        - Servers       - Data Centres          - Aerospace systems
        
        ii. Satellite and Space communication

        iii. Digital Communication: Modems, embedded sytems, sensor networks

        iv. Acadmics: For its the fundamental error correcting algorithm

---

2. What are it's limitations?

- Can only correct 1 bit error. Syndrome becomes misleading when 2 bits error occur

- Over head: For 4 bits data it's sending 3 bits parity. 75% overhead. Thus, ineffecient for large systems

- Not suitable for burst errors

---

3. What are it's improvement?

- Exteneded Hamming Code (SECDED): Single Error Correction Double Error Detection. Used in ECC RAM

- Reed Solomon Codes: A scratched CD may lose hundreds of bits. Reed-solomon can ofthen recover the data

- BCH codes: Generalization of Hamming codes. Widely used in flash memory

- Convolution codes: Good for continous streams of data

- LDPC codes: Low-density parity check mode: Provides error correction close to theoritical limits. Used in 5G, high speed networking

- Turbo codes: used in cellular networks and space missions.

---
---

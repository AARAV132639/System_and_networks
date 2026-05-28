## Primary questions

1. What is parity?
2. How does Hamming Code actually works?
3. Why are we using parity?

4. How is the error detection working?

## Big Picture

    ~ Sender: 4 bit-data
            - parity generation
            - 7-bit encoded message

    ~ Noise introduces error

    ~ Receiver: recalucate parity
                - locate bad bit
                - correct it
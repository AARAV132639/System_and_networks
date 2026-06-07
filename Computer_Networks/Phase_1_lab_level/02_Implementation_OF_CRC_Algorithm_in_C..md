## Primary Questions:

1. What is CRC algorithm?
    
    - *CRC = Cyclic Redundancy Check*

    - *Purpose*:
                1. When data travels through a medium:
                                                        - electrical noise
                                                        - interference
                                                        - attenuation
                                                        - signal distortion
                                                    
                                                    These may flip bits
                            
                            E.g. Original: 10110011|| Transmitted: 10111011
                            Here one bit has changed now
                            But Reciver needs a way to detect this
                            CRC does exactly that.
        
    - *Core idea*:
                    1. CRC treats binary data like a polynomial and performs division
                    2. But not normal division. Rather it uses---> **Modulo-2 division
                    3. This means *no carry*, *no borrow*, and *subtraction* Hence, XOR
                    4. Sender computes a small check value called CRC remainder
                    5. This remainder is attached to data.
                    6. Reciever recomputes it.
                    7. If results mismatch---> corruption detected


2. What is the use of this algorithm?

    - **Main use**: Detect transmission errors
    - **Used in**: 
                    1. Ethernet frames
                    2. Wifi packets
                    3. Storage devices
                    4. USB communication
                    5. Satellite communication
                    6. Bluetooth
                    7. Network protocols
    
    - E.g. The browser requests a webpage.
            - The data travels: Server--->routers---> ISP---> WiFi router----> Laptop
            - Many hops are happening at hardware level where noise can alter bits
            - Hence CRC catches corruption
            - Retransmitting corrupted data is better than accepting wrong data


3. What is strcpy()? - string copy

4. What exactly are we doing here and why?

    1.  Step1: Input original data
    2. Step 2: Input generator polynomial
        ~ this is CRC rulebook
        ~ Sender and receiver must use same generator
    
    3. Append zeros
        ~ Because remainder will occupy these positions
        ~ this is like reserving checksum space
    
    4. Divide by XOR ----> this generates CRC remainder
    5. Attach remainder---> transmit this
        - Why? Because this makes transmitted code mathematically divisible by generator
    
    6. Reciever checks by divinding by same generator

    Therefore, overall: We are creating a mathematical fingerprint for data integrity

5. How does XOR operation helps?

    1. Normal subtraction needs borrow(7-5=2). Modulo-2 simplifies it which is kind of Equivalent to subtraction without borrow
    2. Hardware loves XOR: 1. simple gates 2. fast computation 3. cheap implementation

6. The Big picture:
                    Sender:
                    Data
                    ---> checksum generation
                    ---> transmission

                    Reciever:
                    recieved data
                    ----> checksum verification
                    ----> accept/reject


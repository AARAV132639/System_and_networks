## Primary Questions

1. What is data link layer?

    - Data link layer is the 2nd layer of OSI model.
    - It's main purpose is to make raw transmission reliable between directly connected devices
    - For more theory: 

2. What exactly are we doing here?

    - This experiment is about framing.

    For e.g.:
            1. Suppose the use wants to send: HELLO
            2. However the physical layer dealing with raw bits doesn't understand HELLO it would only see 010100111....
            3. But reciever needs to know : 
                                            - Where the frame starts
                                            - Where the frame ends
                                
                                **Hence, we use Framing**

3. What is Framing?

    - Dividing a continous stream of bits into identifable blocks
    - A frame is the unit of data at the Data Link Layer

4. Why Framing is needed?

    - Because the reciever must know: 
                                        1. Start of message
                                        2. End of Message
                                        3. Error detection boundaries
                                        4. Synchronization

5. What are the types of Framing?
    
    - Fixed size framing
    - Character Count
    - Character stuffing(byte stuffing)
    - Bit stuffing
    - Physical layer coding violations

    ### Fixed Size Framing-
                            1. Every frame has same fixed size
                            2. E.g. Data= ASBCDEFGHIJ -----> Split= ABCDE FGHJ
                            3. *Problem*: Wasteful if message sizes vary
                            4. Used where fixed packet sizes are acceptable
    
    ### Character Count Method-
                                1. Frame header stores data length
                                2. E.g. 5HELLO. ----> Meaning: Next 5 characters belong to this frame
                                3. Reciever reads: Count=5 thus read next 5 chars
                                4. *Problem*: If count gets corrupted---> Receiver losses sync badly
    
    ### Character Stuffing(Byte Stuffing)-
                                            1. Special Characters mark boundaries
                                            2. E.g. Delimiter: F || Frame = F HELLO F
                                            3. But what if actual data contains F? For example: HELLOFWORLD. The reciver might get confused
                                            4. Solution: Escape special characters using Escape char: E.
                                                                    - Stuff: HELLOEFWORLD
                                                                    - Transmitted: FHELLOEFWORLDF
                                                        
                                                        Now the reciver rule: 
                                                                            * F= frame boundary
                                                                            * EF= actual F data
                                            
                                            ** This is character Stuffing**

    ### Bit Stuffing- 
                        1. Used in bit-oriented protocols
                        2. Special flag: 01111110 ---> Marks frame boundary
                        3. E.g 01111110 DATA 01111110
                        4. *Problem*: If same pattern appears inside actual data, The reciever mistakes data for boundary
                        5. Solution: After consecutive 1s, insert a 0
                                                                        - E.g.: Original---> 111111
                                                                        - Stuffed----> 11111+0 (After first five 1s)
                                                                        - Remaining 1---> 1111101
                                                                        - Reciver---> After five 1s, if next bit is 0---> Remove it.
                                                                          therefore, recoverd: 111111
                                                
                                                **This is bit stuffing**
    
    ### Physical Layer Coding Violations:
                                        1. Some signl patterns are illegal in normal transmission
                                        2. Use those illegal patterns as frame boundaries
                                        3. Effecient but hardware dependent

6. What are the applications of Framing?

    - Ethernet--->
                    Frames: 1. destination MAC 2. source MAC 3. payload 4. Checksum
    
    - HDLC---> Uses bit stuffing 
    - PPP(Point-to-Point control) ---> Dial up/ router links. Uses framing+stuffing
    - USB communication 
    - Serial Communication : UART style framed transfers
    - Embedded sytems: Communication between microcontroller and sensor communication

---

## Line by Line function explanation

1. What does this code simulates?

    - Sender NIC----> Framing/Stuffing----> Transmission---->Destuffing---->Receiver NIC

---

## Other Notes:

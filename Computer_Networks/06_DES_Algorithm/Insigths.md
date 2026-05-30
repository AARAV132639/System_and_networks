## Phase 1

1. Why "clear && gcc main.c permutations.c -o main && ./main" worked?

- clear: wipes the terminal screen completely
- &&: AND ONLY THEN operator
- gcc main.c permutations.c -o main: Re-compiles both files into a brand-new executable
- ./main: executes the freshly created main file

!! Secret culptrit---> Terminal buffering
- **printf** doesn't always send text straight to the screen immediately rather it stores it in a temporary memory warehouse called *buffer*
- The buffer dumps its next to the screen when it hits a newline character \n
- During ./main previously the program may have finished so quickly that the VS code terminal closed the stream before the buffer could flus
- Chaining the commands changes how the shell process manages the standard output stream, forcing your terminal to display the text instantly.
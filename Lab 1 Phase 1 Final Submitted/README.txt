Lab 1 Phase 1 Read me by Kevin Cozart

This program properly parses through the phase one example input located here. https://canvas.sonoma.edu/courses/17624/assignments/80722
It outputs exactly what the Solution states it should on the same page as the example input WITH ONE EXCEPTION.  Bug fix in example output still present, my code and output no longer have this issue.
All required features of this Phase 1 requirements are functioning to the best of my knowledge. 

-Kevin 

UPDATE 08/31/2019:
Tokenizer changes:
Extracted method for parsing input stream to be utilized for both Open and Close tag name generation
Updated If Else statement for proper tracking of Open and Close tag logic so that it can differentiate between open and closed tags properly setting the tags for Token
Fixed bug with improper character location for Stand along tag logic
Token changes:
Modified print logic to function for isClosTag flag to print properly


PATCHED:
The input text does not have a > on row 2 character position 167, however I was able to replicate this due to a parsing error in the code.
This however held true when parsing the last /> statement of the example input. 

The solution shows the end few lines as follows:
[ 5, 420] >
[ 6, 423] <br
[ 6, 427] />

However my output shows the same with one extra line similar to the issue on the sample output discussed above. [2,167] when dealing with />
[ 5, 420] >
[ 6, 423] <br
[ 6, 427] />
[ 6, 428] >

I am submitting this now with this minor bug, so that if murphy's law strikes, I have something in the books for grading purposes, but I will be talking with Dr. Kooshesh about the discrepancy on Tuesday.
That is unless I solve the issue before then.

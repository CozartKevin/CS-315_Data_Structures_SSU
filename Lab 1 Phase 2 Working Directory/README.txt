Lab 1 Phase 2 Read me by Kevin Cozart

Program is functional, Map properly tracks tags, and outputs errors as secondary input file requires. 
Its not pretty, I will clean out most of my error tracking cout statements and print messages once I track down my last few bugs.  This is a just in case I die over the weekend you will know I turned in my project. 

-Kevin 



Small bugs:
some of the tag numbers are by 1 +/- in places.  Still trying to track down the bug. 

The output of this section is backwards.
[13, 525] </tr closes while the following tags remain open.
     [13, 471] <p
     [13, 483] <em

Should be:
[13, 524] </tr closes while the following tags remain open.
	[13, 483] <em
	[13, 471] <p

Will fix once I track down my number issues.
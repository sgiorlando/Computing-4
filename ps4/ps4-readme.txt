/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Scott Giorlando and Zachary Palmer


Hours to complete assignment (optional): 3-4 hours



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
We used the Needleman-Wunsch method with an MxN matrix to find the alignment.

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: X: atattat Y: tattat

Expected output: X: atattat Y: -tattat

What happened: It displayed the right string.



/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/
Scott's Laptop: 16GB
Zach's Laptop: 8GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 2
largest N = 22360      

take the b (2) root of 8,000,000,000 bytes = 89442.72
divide by a = 22360.679775

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************

--------------------------------------------------------------------------------
Command:            ./ED
Massif arguments:   (none)
ms_print arguments: massif.out.3667
--------------------------------------------------------------------------------


    GB
1.491^                                                                       :
     |#::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::@
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
     |#                                                                      @
   0 +----------------------------------------------------------------------->Gi
     0                                                                   46.92

Number of snapshots: 96
 Detailed snapshots: [26 (peak), 31, 41, 50, 60, 70, 80, 90]

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1      2,552,797           72,712           72,704             8            0
  2      2,670,755           76,816           76,800            16            0
  3      2,872,360           78,760           78,721            39            0
  4      3,062,995           80,680           80,641            39            0
  5      3,443,248           88,384           88,322            62            0
  6      3,444,100           84,520           84,481            39            0
  7      4,204,662           99,904           99,842            62            0
  8      4,206,294           92,200           92,161            39            0
  9      5,727,325          122,944          122,882            62            0
 10      5,730,517          107,560          107,521            39            0
 11      6,653,272          107,600          107,552            48            0
 12      6,841,913          109,504          109,442            62            0
 13      7,032,548          111,424          111,362            62            0
 14      7,412,801          119,128          119,043            85            0
 15      7,413,653          115,264          115,202            62            0
 16      8,174,215          130,648          130,563            85            0
 17      8,175,847          122,944          122,882            62            0
 18      9,696,878          153,688          153,603            85            0
 19      9,700,070          138,304          138,242            62            0
 20     10,620,508          158,328          158,243            85            0
 21     10,834,056      279,742,208      279,672,218        69,990            0
 22     11,072,056      619,844,208      619,689,218       154,990            0
 23     11,248,456      871,919,808      871,701,818       217,990            0
 24     11,450,056    1,160,006,208    1,159,716,218       289,990            0
 25     11,587,256    1,356,065,008    1,355,726,018       338,990            0
 26     11,758,670    1,600,938,448    1,600,538,258       400,190            0


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		118	0.30894(with valgrind)	24.07 MB
ecoli5000.txt		160	1.18415(with valgrind)	95.75 MB
ecoli7000.txt		194	2.24136(with valgrind)	187.5 MB
ecoli10000.txt		223	4.54806(with valgrind)	382.2 MB
ecoli20000.txt		3135	24.9072(with valgrind)	1.491 GB
ecoli28284.txt		8394	53.6283(with valgrind)	2.982 GB

Fill out the data here first, then go to the assignment web page for
instructions on sharing your data on iSENSE.



/**********************************************************************
 *  Enter your data onto iSENSE per the directions on the course web
 *  site. Then, paste a URL to your data set here.
 *
 *  YOU WILL ONLY RECEIVE CREDIT FOR YOUR iSENSE WORK IF YOU PROVIDE
 *  THE URL HERE.
 *
 *  e.g.: http://isenseproject.org/projects/871/data_sets/7893
 ************************************************************************/



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4
b = 2
largest N = ?

generally everytime N doubles the time quadruples

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/

Just Zach and Scott

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
We had some slight leaks in our program, there was no destructor and once that was put in it was fixed with no leaks.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
In the table above that has the time and memory, the time listed was when the program was run with valgrind and massif, we tried it without valgrind and massif and the time was very similar to the table below it.

# Assignment 4: CP386 (Mohammad Safi, Brady Loenhart)
CP386 Assignment 4 repository

------------------------------------------------------------------
Motivation:
------------------------------------------------------------------

Was aprt of a required course assignment and allowed something about 
Opreating Systems.

 ----------------------------------------------------------------
 [Completed tasks outlined in CP386: Assignment 4 - Winter 2022]
 ----------------------------------------------------------------
 Author 1: Mohammad Safi
 Student ID: 190501610
 E-mail: safi1610@mylaurier.ca

 Author 2: Brady Loenhart
 Student ID: 190905340
 E-mail: loen5340@mylaurier.ca
 
 ---------------------------------------------------------------
 Due: Apr.2nd, 2022
 Prepared for both: Professor Sukhjit Sehra, sshera@wlu.ca
 & TA Ishmeet Singh, sing0078@mylaurier.ca
 ----------------------------------------------------------------
 [Funcitons]
 ----------------------------------------------------------------
 Mohammad Safi:
 Q1:
int readFile(char *fName);
void readSeq(char *fName, int max[rowNum][colNum]);
int resourceRequest(int args[]);
int resourceRelease(int args[]);

Q2:
void releaseMem(char pid[5]);
void bestFit(char pid[5], int requestedSpace)
void requestMem(char pid[3], int requestedSpace, char algo[2]) {


Brady Loenhart:
Q1:
bool safetyCheck(int *avail, int *alloc, int *need);
void state(int *avail, int *max, int *alloc, int *need);
int sumArr(int arr[], int i);
void getColNum(char *fName);
void runCMD();

-------------------------------------------------------------------
Description:
-------------------------------------------------------------------
190501610_190905340_a04_q1.c
---------------------------
This is a multi-threaded program. It is the implementation of the Banker's algorithm
where customers release resources and also request them from the bank. The resources
are kept track of by the banker. The safetyCheck algorithm will grant a request if it
is satisfied. Any request that leaves it in an unsafe state will be denied by the banker.

190501610_190905340_a04_q2.c
---------------------------
This program has contiguous memory allocation using an implementation of ther Best-Fit
algorithm. This program manages a region of contiguous memory. It handles 3 important
requests. It reports allocated and free memory. It both requests and releases a contiguous
memory block.

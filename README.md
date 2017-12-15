# CBCS sticky snail

#### This project is compatible only with Windows
This program takes the advantage of SAME "session id" being used in the SASTRA CBCS login portal.
It will extract the NAME, BRANCH, SECTION chosen from the web pages.

## This repository contains 2 folders 
- CBCS-list2
- CBCS
****
### CBCS-list2
This folder contains the code to download the Data in single threaded mode upto the next 1000 stu-ids.

### CBCS
This folder contains the code to simply run multiple instances of the CBCS-list2, more like multi threading. Using p_thread didn't improve the results.

## Usage
### Single-Threaded
Run CBCS-list2.exe with the beginning "stuid" as the parameter.
Example: CBCS-list2.exe 60000 (For stuid 60000-61000)

### Multi-Threaded
Make changes in CBCS.cpp for the desired range. Make sure that CBCS.exe and CBCS-list2.exe are in the same folder. Just open CBCS.exe.
Example: CBCS.exe
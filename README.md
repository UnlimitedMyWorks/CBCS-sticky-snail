# CBCS sticky snail

#### This project is compatible only with Windows
This program takes the advantage of SAME "session id" being used in the SASTRA CBCS login portal.
It will extract the NAME, BRANCH, SECTION chosen from the web pages.

## This repository contains 2 folders 
- CBCS-list2
- CBCS
****
### CBCS-list2
This folder contains the code to download the Data in single threaded mode. 

### CBCS
This folder contains the code to simply run multiple instances of the CBCS-list2, more like multi threading. Using p_thread didn't improve the results.


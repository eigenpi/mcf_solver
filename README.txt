Author: Cristinel Ababei
August.2009, Fargo ND; version v1.0 (initial)
January.2016, Milwaukee, WI; version v2.0
cristinel.ababei@marquette.edu


Synopsis
========
This is an efficient C++ implementation of a polynomial time approximation 
algorithm to solve multicommodity flow problems [1]. The implementation 
follows basically [1] but with the "binary search" in the second part
(while solving the so called "min-cost max concurrent flow" problem)
improved as described in [2].
This implementation is meant to provide a clean and simple interface (for 
easy integration in bigger projects) for specifying the network (or graph) 
and the supplies and demands (or commodities).


Credits
=======
This code is an incomplete porting to C++ with "extraction", restructuring,
and clean-up of the MCF code written by Yuanfang Hu, Hongyu Chen, and Yi Zhu
(while at UCSD as students of Chung-Kuan Cheng). Their code is discussed 
in [2] and can be downloaded from here:
http://www-cse.ucsd.edu/users/kuan/supercomputer/supercomputer_package.tar


Installation
============
The latest version of the tool can be downloaded from:
www.dejazzer.com/software.html
To compile it just type:
> make


How to use the tool
===================
Usage:  mcf_solver network_file [Options...]
Options:
        [-problem_type MCF|MCMCF]. Default is MCMCF.
        where: MCF - max multicommodity flow, MCMCF - min-cost max concurrent flow
        [-epsilon float]. Default is 0.1.

Examples:
> mcf_solver tests/toy1.network -problem_type MCF
> mcf_solver tests/toy1.network
> mcf_solver tests/toy2.network -problem_type MCF
> mcf_solver tests/toy2.network
> mcf_solver tests/toy2.network -problem_type MCF -epsilon 0.01


Papers
======
To better understand the code I suggest you to read the following
(some of the comments refer to some of the equations or things
from some of these papers):
[1] G. Karakostas, "Faster approximation schemes for fractional 
    multicommodity flow problems," ACM Trans. on Algorithms, 
    vol. 4, no. 3, March 2008.
    Can be downloaded from: http://www.cas.mcmaster.ca/~gk
[2] Yuanfang Hu, Yi Zhu, Hongyu Chen, Ronald L. Graham, and 
    Chung-Kuan Cheng, "Communication latency aware low power NoC 
    synthesis," DAC, pp. 574-579, 2006.
[3]	Lisa Fleischer, "Approximating fractional multicommodity 
    flow independent of the number of commodities," FOCS, 1999.
[4] Naveen Garg and Jochen Könemann, "Faster and simpler algorithms 
    for multicommodity Flow and other fractional packing problems,"
    39th Annual Symposium on Foundations of Computer Science, 1998.
[5] C. Ababei, "Efficient congestion-oriented custom Network-on-Chip 
    topology  synthesis," IEEE Int. Conference on Reconfigurable 
    Computing and FPGAs (ReConFig 2010), Cancun, Mexico, Dec. 2010.
    (the portion about MCF only)


Things I need yet to do
=======================
1. Clean-up more all classes: have all class-variables as "_variable"
and not just "variable"; encapsulate everything: make all class-variables 
private and provide access functions; get rid of dubious constants such as
"400" inside shortest_path() routine;
2. Get rid of all malloc's; for that use vectors for all arrays
3. Implement MCF::build_network_from_host_application() - this should be 
very easy for anyone


Things you might want to do
===========================
1. If you dig into it and find any bug, please let me know
2. If you use this code in a research project and want to 
include a reference to it, then please use:
[] Cristinel Ababei, C++ implementation of a polynomial time 
   approximation algorithm, 2009, [Online], Available: 
   www.dejazzer.com/software.html
3. If you'll ever hit it big (to be read: make a lot of money :-) ),
and this code helped you in any way, then please consider 
donating some to support my research (I need it :-) )


Copyright
=========
Copyright 2009-present by Cristinel Ababei, cristinel.ababei@marquette.edu
This Copyright notice applies to all files, called hereafter 
"The Software".
Permission to use, copy, and modify this software and its 
documentation is hereby granted only under the following 
terms and conditions.  Both the above copyright notice and 
this permission notice must appear in all copies of the 
software, derivative works or modified versions, and any 
portions thereof, and both notices must appear in supporting 
documentation.  Permission is granted only for non-commercial 
use.  For commercial use, please contact the author.
This software may be distributed (but not offered for sale 
or transferred for compensation) to third parties, provided 
such third parties agree to abide by the terms and conditions
of this notice.
The Software is provided "as is", and the authors, 
Marquette University, as well as any and
all previous authors (of portions or modified portions of
the software) disclaim all warranties with regard to this 
software, including all implied warranties of merchantability
and fitness.  In no event shall the authors or NDSU or any and
all previous authors be liable for any special, direct, 
indirect, or consequential damages or any damages whatsoever
resulting from loss of use, data or profits, whether in an
action of contract, negligence or other tortious action,
arising out of or in connection with the use or performance
of this software.

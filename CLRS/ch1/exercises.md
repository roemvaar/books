# Chapter 1 - Exercises

1.1-1 Sorting in real-world: 

* Sorting books by name/author in a public library
*  Sorting people for immigration when they arrive from an international flight
* Sorting your tasks priorities from work

Sorting that requires finding the shortest distance between two points:

1) If you sell things online, and you need to deliver more than one of them,
you would like to efficient your time and gas, therefore you would have to
list all the adddresses you need to visit, and then sort them, using the shortest
path to go from one place to another/

1.1-2 Other than speed, other measures to consider in real-world:

* Gas prices
* Distance
* Time
* Road speed limits

1.1-3 Data structure - strenghts and limitations

Hash-Table: one of my favorite data structures. They map keys to values.

Pros:

* Constant time (amortyzed) for multiple operations - insertion, searching, deletion
* It helps with to record seen elements in another data structure, and you can make an
algorithm that can take you two passes, in one pass.

Cons:

* Take a lot of memory
* Complex - not included as part of the C standard library (that's a bummer for embedded software
engineers)
* Collisions - Hard to develop a good hash function

1.1-4 Shortest-path and traveling-salesperson problems [1]:

Similarities:

* They both use distance as one of the measures to take in account

Differences:

* The traveling-salesperson needs to go to ALL the points in the graph and then
come back to where it started, while for the shortest-path, we only need to determine
an efficient route to go from A to B
* TSP is an NP-Complete problem and shortest-path is known polynomial-time

1.1-5 Real-world problem in which only the best solution will do. Then come up with one in
which "approximately" the best solution is good enough:

* Best Solution: Banking (transacations), safety systems (brake activation on autonomous vehicles) 
* Approximation: CPU tasks scheduling, music recommendation (Spotify), friend suggestions (Facebook)


1.1-6 Real-world problem where all the input is available before you need to solve the problem and
problem where not all the input is available before you start solving the problem

* Available: Music player (downloaded songs), data analysis of logs (already stored in memory/disk)
* Not available: CAN messages (extended), live streaming (video or voice), data analysis of streaming data
from a data acquisition system


References:

[1] https://stackoverflow.com/questions/7763432/what-is-the-difference-between-travelling-salesman-and-finding-shortest-path
